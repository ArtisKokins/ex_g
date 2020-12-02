using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KDv2_Hierarhija
{
    public class Om
    {
        //lauki
        protected double u, r, i;

        //īpašības
        public double U
        {
            set { u = value; i = u / r; }
            get { return u; }
        }
        public double R
        {
            set { r = value; i = u / r; }
            get { return r; }
        }
        public double I
        {
            get { return i; }
        }

        //konstruktori
        public Om()
        {
            u = 0; r = double.PositiveInfinity; i = 0;
        }
        public Om(double aU, double aR)
        {
            u = aU; r = aR; i = u / r;
            //U=aU; R=aR;
        }

        //metodes
        public override string ToString()
        {
            return "U = " + u + " V, R = " + r + " Om, I = " + i + " A";
        }
    }
}
