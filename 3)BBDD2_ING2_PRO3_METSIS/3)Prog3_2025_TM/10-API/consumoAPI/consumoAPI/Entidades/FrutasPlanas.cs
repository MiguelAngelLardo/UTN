using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class FrutasPlanas
    {
        public int id { get; set; }
        public string name { get; set; }
        public string family { get; set; }
        public string genus { get; set; }
        public string order { get; set; }

        // Valores nutricionales directamente
        // como propiedades planas
        public double carbohydrates { get; set; }
        public double protein { get; set; }
        public double fat { get; set; }
        public double calories { get; set; }
        public double sugar { get; set; }
    }
}
