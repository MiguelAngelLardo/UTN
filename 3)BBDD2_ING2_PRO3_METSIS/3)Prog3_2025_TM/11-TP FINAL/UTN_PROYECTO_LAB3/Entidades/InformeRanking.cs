using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class InformeRanking
    {
        public int turnosTotal { get; set; }
        public int cantidadMaxima { get; set; }
        public DataTable detalleRanking { get; set; }
        public string promedioTurnos { get; set; }


        public InformeRanking()
        {

            turnosTotal = 0;
            cantidadMaxima = 0;
            detalleRanking = new DataTable();
            promedioTurnos = "0";
        }
    }
}