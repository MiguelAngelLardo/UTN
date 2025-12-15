using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Categoria
    {
        private int IdCategoria;
        private String NombreCategoria;
        private String Descripcion;

        public Categoria()
        { }
        public int getIdCategoria()
        {
            return IdCategoria;
        }
        public void setIdCategoria(int idCategoria)
        {
            IdCategoria = idCategoria;
        }
        public String getNombreCategoria()
        {
            return NombreCategoria;
        }
        public void setNombreCategoria(String nombreCategoria)
        {
            NombreCategoria = nombreCategoria;
        }
        public String getDescripcion()
        {
            return Descripcion;
        }
        public void setDescripcion(String descripcion)
        {
            Descripcion = descripcion;
        }
    }
}
