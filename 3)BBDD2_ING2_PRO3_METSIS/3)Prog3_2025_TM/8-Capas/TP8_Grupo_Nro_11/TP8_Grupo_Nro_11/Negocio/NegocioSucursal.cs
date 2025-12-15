using Dao;
using Entidades;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Negocio
{
    public class NegocioSucursal
    {
        public bool AgregarSucursal(Sucursal sucursal)
        {
            DaoSucursal daoSucursal = new DaoSucursal();
            int FilasAfectadas = daoSucursal.agregarSucursal(sucursal);

            if (FilasAfectadas == 1) return true;
            else return false;
        }
        public DataTable TablaCompleta()
        {
            DaoSucursal dao = new DaoSucursal();
            return dao.getTablaSucursales();
        }

        public bool eliminarSucursal(int id)
        {
            //Validar id existente 
            DaoSucursal dao = new DaoSucursal();
            Sucursal cat = new Sucursal();
            cat.setIdSucursal(id);
            int op = dao.eliminarSucursal(cat);
            if (op == 1)
                return true;
            else
                return false;
        }

        public DataTable TablaPorId(Sucursal sucursal)
        {   
            DaoSucursal dao = new DaoSucursal();
            if (dao.existeID(sucursal))
            {
                return dao.getTablaPorID(sucursal);

            }
            return new DataTable();
        }
       
    }

   



}
