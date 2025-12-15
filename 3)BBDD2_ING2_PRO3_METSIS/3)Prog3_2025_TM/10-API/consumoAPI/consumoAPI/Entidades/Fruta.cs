using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Fruta
    {
        public int id { get; set; }
        public string name { get; set; }
        public string family { get; set; }
        public string genus { get; set; }
        public string order { get; set; }
        public Nutricion nutritions { get; set; }
    }

}
