using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace KDv2_Hierarhija
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Om o1 = new Om();
            Om o2 = new Om(220, 10);
            richTextBox1.Clear();
            richTextBox1.AppendText("\n o1: " + o1.ToString());
            richTextBox1.AppendText("\n o2: " + o2.ToString());
            Om2c o3 = new Om2c(220, 10, 10);
            Om2p o4 = new Om2p(220, 10, 20);
            richTextBox1.AppendText("\n o3: " + o3.ToString());
            richTextBox1.AppendText("\n o4: " + o4.ToString());
        }
        const int N = 10;
        Om[] A = new Om[N];
        private void button2_Click(object sender, EventArgs e)
        {
            Random rnd = new Random();
            const int N = 10;
            A = new Om[N];
            for(int k=0; k<N; k++)
            {
                if(rnd.Next(0, 100)<50)
                {
                    A[k] = new Om2c(rnd.Next(10, 50), rnd.Next(10, 100), rnd.Next(10, 100));
                }
                else
                {
                    A[k] = new Om2p(rnd.Next(10, 50), rnd.Next(10, 100), rnd.Next(10, 100));
                }
            }
            for (int k = 0; k < N; k++)
            {
                richTextBox1.AppendText("\nA[" + k + "] = " + A[k].ToString());
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Array.Sort(A, (a1, a2) => a1.R.CompareTo(a2.R));
            richTextBox1.AppendText("\n---sorted---");
            for(int k = 0; k < N; k++)
            {
                richTextBox1.AppendText("\n A[" + k + "] = " + A[k].ToString());
            }
        }
    }
}
