using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class InformePresentismo
    {
        public int Total { get; set; }
        public int Presentes { get; set; }
        public int Ausentes { get; set; }
        public double PorcentajePresentes { get; set; }
        public double PorcentajeAusentes { get; set; }

        public InformePresentismo() {
            Total = 0;
            Presentes = 0;
            Ausentes = 0;
            PorcentajePresentes = 0;
            PorcentajeAusentes = 0;
        }
    }
}
