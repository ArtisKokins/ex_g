using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KDv2_Hierarhija
{
    public class Om2p: Om
    {
        private double r1, r2;
        public double R1
        {
            set { r1 = value; r = r1 * r2 / (r1 + r2); i = u / r; }
            get { return r1; }
        }
        public double R2
        {
            set { r2 = value; r = r1 * r2 / (r1 + r2); i = u / r; }
            get { return r2; }
        }
        public Om2p(double aU, double aR1, double aR2)
        {
            u = aU; r1 = aR1; r2 = aR2; r = r1 * r2 / (r1 + r2); i = u / r;
        }
    }
}
