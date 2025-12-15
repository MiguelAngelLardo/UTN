using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Entidades;
using Dao;
using System.Data;


namespace Negocio
{
    public class NegocioCategoria
    {
        public DataTable getTabla()
        {
            DaoCategoria dao = new DaoCategoria();
            return dao.getTablaCategorias();
        }

        public Categoria get(int id)
        {
            DaoCategoria dao = new DaoCategoria();
            Categoria cat = new Categoria();
            cat.setIdCategoria(id);
            return dao.getCategoria(cat);
        }

        public bool eliminarCategoria(int id)
        {
            //Validar id existente 
            DaoCategoria dao = new DaoCategoria();
            Categoria cat = new Categoria();
            cat.setIdCategoria(id);
            int op = dao.eliminarCategoria(cat);
            if (op == 1)
                return true;
            else
                return false;
        }

        public bool agregarCategoria(String nombre)
        {
            int cantFilas = 0;

            Categoria cat = new Categoria();
            cat.setNombreCategoria(nombre);

            DaoCategoria dao = new DaoCategoria();
            if(dao.existeCategoría(cat)==false)
            {
                cantFilas = dao.agregarCategoria(cat);
            }

            if (cantFilas == 1)
                return true;
            else
                return false;
        }

    }

  
}
