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
    internal class common
    {
        public SqlConnection GetSqlConnection108()//SQL数据库连接
        {
            SqlConnection con;
            string connentionstring = "Data Source = 192.168.1.108; Initial Catalog = CCD; User ID = sa; Password=123456789lihan";
            con = new SqlConnection(connentionstring);
            return con;
        }
        public SqlConnection GetSqlConnection105()//SQL数据库连接
        {
            SqlConnection con;
            string connentionstring = "Data Source = 192.168.1.105; Initial Catalog = CCD; User ID = sa; Password=123456789lihan";
            con = new SqlConnection(connentionstring);
            return con;
        }
        public SqlConnection GetSqlConnection()//SQL数据库连接
        {
            SqlConnection con;
            string connentionstring = "Data Source=LIHANS;Initial Catalog=CCD;Integrated Security=True";
            con = new SqlConnection(connentionstring);
            return con;
        }
        public SerialPort GetSerialPort1()//串口COM1连接
        {
            SerialPort Serialcom1;
            Serialcom1 = new SerialPort();
            Serialcom1.PortName = "COM1";
            Serialcom1.BaudRate = 115200;
            Serialcom1.DataBits = 8;
            Serialcom1.StopBits = StopBits.One;
            Serialcom1.Parity = Parity.None;
            Serialcom1.Handshake = Handshake.None;
            Serialcom1.ReadBufferSize = 8000;
            return Serialcom1;
        }
        public SerialPort GetSerialPort2()//串口COM2连接
        {
            SerialPort Serialcom2;
            Serialcom2 = new SerialPort();
            Serialcom2.PortName = "COM2";
            Serialcom2.BaudRate = 115200;
            Serialcom2.DataBits = 8;
            Serialcom2.StopBits = StopBits.One;
            Serialcom2.Parity = Parity.None;
            Serialcom2.Handshake = Handshake.None;
            Serialcom2.ReadBufferSize = 8000;
            return Serialcom2;
        }
        public SerialPort GetSerialPort3()//串口COM3连接
        {
            SerialPort Serialcom3;
            Serialcom3 = new SerialPort();
            Serialcom3.PortName = "COM3";
            Serialcom3.BaudRate = 115200;
            Serialcom3.DataBits = 8;
            Serialcom3.StopBits = StopBits.One;
            Serialcom3.Parity = Parity.None;
            Serialcom3.Handshake = Handshake.None;
            Serialcom3.ReadBufferSize = 8000;
            return Serialcom3;
        }
        public SerialPort GetSerialPort4()//串口COM4连接
        {
            SerialPort Serialcom4;
            Serialcom4 = new SerialPort();
            Serialcom4.PortName = "COM4";
            Serialcom4.BaudRate = 115200;
            Serialcom4.DataBits = 8;
            Serialcom4.StopBits = StopBits.One;
            Serialcom4.Parity = Parity.None;
            Serialcom4.Handshake = Handshake.None;
            Serialcom4.ReadTimeout = -1;
            Serialcom4.WriteTimeout = -1;
            Serialcom4.ReadBufferSize = 0;
            return Serialcom4;
        }
        public SerialPort GetSerialPort5()//串口COM5连接
        {
            SerialPort Serialcom5;
            Serialcom5 = new SerialPort();
            Serialcom5.PortName = "COM5";
            Serialcom5.BaudRate = 20000;
            Serialcom5.DataBits = 8;
            Serialcom5.StopBits = StopBits.One;
            Serialcom5.Parity = Parity.None;
            Serialcom5.Handshake = Handshake.None;
            Serialcom5.ReadTimeout = -1;
            Serialcom5.WriteTimeout = -1;
            Serialcom5.ReadBufferSize = 0;
            return Serialcom5;
        }
        public SerialPort GetSerialPort6()//串口COM6连接
        {
            SerialPort Serialcom6;
            Serialcom6 = new SerialPort();
            Serialcom6.PortName = "COM6";
            Serialcom6.BaudRate = 20000;
            Serialcom6.DataBits = 8;
            Serialcom6.StopBits = StopBits.One;
            Serialcom6.Parity = Parity.None;
            Serialcom6.Handshake = Handshake.None;
            Serialcom6.ReadTimeout = -1;
            Serialcom6.WriteTimeout = -1;
            Serialcom6.ReadBufferSize = 0;
            return Serialcom6;
        }
        public SerialPort GetSerialPort7()//串口COM7连接
        {
            SerialPort Serialcom7;
            Serialcom7 = new SerialPort();
            Serialcom7.PortName = "COM7";
            Serialcom7.BaudRate = 20000;
            Serialcom7.DataBits = 8;
            Serialcom7.StopBits = StopBits.One;
            Serialcom7.Parity = Parity.None;
            Serialcom7.Handshake = Handshake.None;
            Serialcom7.ReadTimeout = -1;
            Serialcom7.WriteTimeout = -1;
            Serialcom7.ReadBufferSize = 0;
            return Serialcom7;
        }
        public SerialPort GetSerialPort8()//串口COM8连接
        {
            SerialPort Serialcom8;
            Serialcom8 = new SerialPort();
            Serialcom8.PortName = "COM8";
            Serialcom8.BaudRate = 20000;
            Serialcom8.DataBits = 8;
            Serialcom8.StopBits = StopBits.One;
            Serialcom8.Parity = Parity.None;
            Serialcom8.Handshake = Handshake.None;
            Serialcom8.ReadTimeout = -1;
            Serialcom8.WriteTimeout = -1;
            Serialcom8.ReadBufferSize = 0;
            return Serialcom8;
        }
    }
}
