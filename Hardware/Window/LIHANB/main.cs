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
        static int[] SSS_DATA = new int[3648];//光谱响应系数
        static int[] Sample_Value = new int[3648];
        static int[] CCD_XValue = new int[3648];

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
            Serialcom3.Open();//打开串口COM3连接
            Serialcom3.DataReceived += new SerialDataReceivedEventHandler(CCD_DATA_VOL_DATA);

            int m = 0;
            while (m < 3648)
            {
                CCD_XValue[m] = m;
                m = m + 1;
            }
        }

        private void SerialPortSATA()
        {
            PauseEventSATA.WaitOne();
            SerialPortSATA();
        }

        private void SerialPortDATA()
        {
            PauseEventDATA.WaitOne();
            while (true)
            {
                Serialcom3.DiscardInBuffer();
                CCD_Time[0] = byte.Parse(Time.Text);//Time数据作为曝光时间
                Serialcom3.Write(CCD_Time, 0, CCD_Time.Length);
                CCD_Star[0] = 0xFF;
                Serialcom3.Write(CCD_Star, 0, CCD_Star.Length);
                Thread.Sleep(1500);
                View_con();
            } 
        }

        private void View_con()
        {
            this.Invoke((MethodInvoker)delegate
            {
                spectrogram.Series[0].Points.DataBindXY(CCD_XValue, Sample_Value);
            });
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
            x+= DATA_num;
            if (x >= 8000)
            {
                x = 0;
                int i = 32; int k = 0;
        
                while (k < 3648)
                {
                    Sample_Value[k] = (int)((CCD_DATA[i] << 8) | CCD_DATA[i + 1]);
                    k++;
                    i+=2;
                }
            }
        }

        private void measure_Click(object sender, EventArgs e)
        {
            if (PauseEventDATA.WaitOne(0))
            {
                PauseEventDATA.Reset();
            }
            else
            {
                PauseEventDATA.Set();
            }

        }

        private void main_Load(object sender, EventArgs e)
        {
            // TODO: 这行代码将数据加载到表“cCDDataSet.CCD_DATA”中。您可以根据需要移动或移除它。
            //this.cCD_DATATableAdapter.Fill(this.cCDDataSet.CCD_DATA);
        }
        private void Clear_DATA_Click(object sender, EventArgs e)
        {
            
        }
    }
}
