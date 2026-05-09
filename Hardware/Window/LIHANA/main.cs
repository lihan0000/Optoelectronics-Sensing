using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using System.Threading;
using System.Windows.Forms.DataVisualization.Charting;
using System.Drawing.Text;
using System.Timers;
using System.Reflection.Emit;
using MathNet.Numerics;
using Newtonsoft.Json.Linq;

namespace LIHAN
{
    public partial class main : Form
    {
        static ManualResetEvent PauseEventSATA = new ManualResetEvent(false);//创建MannualResetEvent
        static ManualResetEvent PauseEventDATA = new ManualResetEvent(false);//创建MannualResetEvent

        static byte[] CCD_Time = new byte[1];
        static byte[] CCD_Star = new byte[1];
        static byte[] CCD_DATA = new byte[8000];

        static int x = 0;
        static int X = 0;

        static int[] SSS_DATA = new int[3648];//光谱响应系数（TCD130X系列对不同频率光响应不同）
        static int[] VOL_DATA = new int[3648];
        static int[] MEA_DATA = new int[3648];

        static int[] DARK_DATA = new int[3648];
        static int[] SAMP_DATA = new int[3648];
        static int[] COUN_DATA = new int[3648];

        static int[] NUX_DATA = new int[3648];
        static int[] NUY_DATA = new int[3648];

        static double[] NUXO_DATA = new double[3648];
        static double[] NUYO_DATA = new double[3648];

        static int [] SPEC = new int[3648];

        static common common = new common();
        SqlConnection con = common.GetSqlConnection();
        SerialPort Serialcom3 = common.GetSerialPort3();

        public main()
        {
            InitializeComponent();

            Thread SerialSATA = new Thread(SerialPortSATA);//创建线程
            Thread SerialDATA = new Thread(SerialPortDATA);//创建线程

            SerialDATA.Start();//打开线程

            //con.Open();//打开SQL数据库连接
            //Serialcom3.Open();//打开串口COM3连接
            Serialcom3.DataReceived += new SerialDataReceivedEventHandler(CCD_DATA_VOL_DATA);
        }

        private void SerialPortSATA()
        {
            PauseEventSATA.WaitOne();
            PauseEventSATA.Reset();
            SerialPortSATA();
        }

        private void SerialPortDATA()
        {
            PauseEventDATA.WaitOne();

            CCD_Time[0] = byte.Parse(Time.Text);//Time数据作为曝光时间
            Serialcom3.Write(CCD_Time, 0, CCD_Time.Length);
            CCD_Star[0] = 0xFF;
            Serialcom3.Write(CCD_Star, 0, CCD_Star.Length);

            PauseEventDATA.Reset();
            SerialPortDATA();
        }

        private void CCD_DATA_VOL_DATA(object sender, SerialDataReceivedEventArgs e)
        {
            int DATA_num = Serialcom3.BytesToRead;
            byte[] CCD_O = new byte[DATA_num];
            Serialcom3.Read(CCD_O, 0, DATA_num);
            int Y = 0;
            while (Y < DATA_num)
            {
                CCD_DATA[x + Y] = CCD_O[Y];
                Y++;
            }
            x = x + DATA_num;
            if (x >= 8000)
            {
                int i = 32; int k = 0; int m = 0; int n = 0;
                while (m < 3648)
                {
                    MEA_DATA[m] = m + 1;
                    m = m + 1;
                }
                while (k < 3648)
                {
                    VOL_DATA[k] = (int)((CCD_DATA[i] << 8) | CCD_DATA[i + 1]);
                    k = k + 1;
                    i = i + 2;
                }
                while (n < 3648)
                {
                    VOL_DATA[n] = VOL_DATA[n] * SSS_DATA[n];
                    k = k + 1;
                }
                x = 0;

                Serialcom3.DiscardInBuffer();
            }
        }

        private void measure_Click(object sender, EventArgs e)
        {
            PauseEventSATA.Set();
            PauseEventDATA.Set();
            X = X + 1;
        }

        private void View_Click(object sender, EventArgs e)
        {
            string VOLInsertQuery = $"INSERT INTO CCD.dbo.CCD_DATA (Nvalue,Xvalue,Yvalue) VALUES (@NValue,@XValue,@YValue)";
            SqlCommand VOLcommand = new SqlCommand(VOLInsertQuery, con);
            VOLcommand.Parameters.Add("@NValue", SqlDbType.Int);
            VOLcommand.Parameters.Add("@XValue", SqlDbType.Int);
            VOLcommand.Parameters.Add("@YValue", SqlDbType.Int);

            int n = 0;
            while (n < 3648)
            {
                VOLcommand.Parameters["@NValue"].Value = X;
                VOLcommand.Parameters["@XValue"].Value = MEA_DATA[n];
                VOLcommand.Parameters["@YValue"].Value = VOL_DATA[n];
                VOLcommand.ExecuteNonQuery();
                n = n + 1;
            }

            VOLcommand.Dispose();

            string DARKInsertQuery = $"SELECT Yvalue FROM CCD.dbo.CCD_DATA WHERE Nvalue = @X ";
            SqlCommand DARKcommand = new SqlCommand(DARKInsertQuery, con);
            DARKcommand.Parameters.Add("@X", SqlDbType.Int);
            DARKcommand.Parameters["@X"].Value = 0;

            SqlDataAdapter DARKadapter = new SqlDataAdapter(DARKcommand);
            DataTable DARKdataTable = new DataTable();
            DARKadapter.Fill(DARKdataTable);

            int v = 0;
            while (v < 3648)
            {
                DARK_DATA[v] = Convert.ToInt32(DARKdataTable.Rows[v]["Yvalue"]);
                v = v + 1;
            }

            DARKadapter.Dispose();//释放数据库容器
            DARKdataTable.Clear();//清理数据库集合
            DARKcommand.Dispose();//释放数据库查询

            string SSSSInsertQuery = $"SELECT Yvalue FROM CCD.dbo.CCD_DATA WHERE Nvalue = @X ";
            SqlCommand SSSScommand = new SqlCommand(SSSSInsertQuery, con);
            SSSScommand.Parameters.Add("@X", SqlDbType.Int);
            SSSScommand.Parameters["@X"].Value = 3648;

            SqlDataAdapter SSSSadapter = new SqlDataAdapter(SSSScommand);
            DataTable SSSSdataTable = new DataTable();
            SSSSadapter.Fill(SSSSdataTable);

            int l = 0;
            while (l < 3648)
            {
                SSS_DATA[l] = Convert.ToInt32(SSSSdataTable.Rows[l]["Yvalue"]);
                l = l + 1;
            }

            SSSSadapter.Dispose();//释放数据库容器
            SSSSdataTable.Clear();//清理数据库集合
            SSSScommand.Dispose();//释放数据库查询

            string ViewInsertQuery = $"SELECT Xvalue,Yvalue FROM CCD.dbo.CCD_DATA WHERE Nvalue = @X ";
            SqlCommand Viewcommand = new SqlCommand(ViewInsertQuery, con);
            Viewcommand.Parameters.Add("@X", SqlDbType.Int);
            Viewcommand.Parameters["@X"].Value = X;

            SqlDataAdapter Viewadapter = new SqlDataAdapter(Viewcommand);
            DataTable ViewdataTable = new DataTable();
            Viewadapter.Fill(ViewdataTable);

            int z = 0;
            while (z < 3648)
            {
                COUN_DATA[z] = Convert.ToInt32(ViewdataTable.Rows[z]["Xvalue"]);
                SAMP_DATA[z] = DARK_DATA[z] - Convert.ToInt32(ViewdataTable.Rows[z]["Yvalue"]);
                z = z + 1;
            }
            
            Viewadapter.Dispose();//释放数据库容器
            ViewdataTable.Clear();//清理数据库集合
            Viewcommand.Dispose();//释放数据库查询  

            spectrogram.Series[0].Points.DataBindXY(COUN_DATA, SAMP_DATA);

            Multinomial_near();
        }

        private void main_Load(object sender, EventArgs e)
        {

        }

        private void Clear_DATA_Click(object sender, EventArgs e)
        {
            string FMEAInsertQuery = $"DELETE FROM CCD.dbo.CCD_DATA WHERE Nvalue != 0";
            SqlCommand FMEAcommand = new SqlCommand(FMEAInsertQuery, con);
            FMEAcommand.ExecuteNonQuery();

            FMEAcommand.Dispose();
        }

        private void Multinomial_near()
        {
            for (int i = 0; i < 3648; i++)
            {
                NUXO_DATA[i] = (double)COUN_DATA[i];
                NUYO_DATA[i] = (double)SAMP_DATA[i];
            }

            double[] Multinomial_near_coe = Fit.Polynomial(NUXO_DATA, NUYO_DATA,150);

            for (int w = 0; w < 3648; w++)
            {
                SPEC[w] = (int)(1200 - (w * 0.275));
            }

            for (int d = 0; d < 3648; d++)
            {
                double YNUValue = 0;
                for (int h = 0; h < Multinomial_near_coe.Length; h++)
                {
                    YNUValue += Multinomial_near_coe[h] * Math.Pow(d, h);
                }
                spectrogram.Series[0].Points.AddXY(SPEC[d], YNUValue);
            }  
        }
    }
}