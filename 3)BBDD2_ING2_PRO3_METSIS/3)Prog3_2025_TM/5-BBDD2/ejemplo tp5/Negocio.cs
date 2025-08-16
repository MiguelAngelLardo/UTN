using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using System.Data.SqlClient;

namespace TrabajandoConClases
{
    public class Negocio
    {
        AccesoDatos conexion = new AccesoDatos();
        public DataTable ObtenerSucursales()
        {
            string consultaSQL = "SELECT Id_Sucursal AS ID, NombreSucursal AS NOMBRE, DescripcionProvincia AS PROVINCIA, DireccionSucursal AS DIRECCIÓN FROM Sucursal INNER JOIN Provincia ON Id_Provincia=Id_ProvinciaSucursal";
            string nombreTabla = "Sucursales";
            return conexion.ObtenerTablas(consultaSQL, nombreTabla);
        }

        public DataTable ObtenerProvincias()
        {
            string consultaSQL = "SELECT * FROM Provincia";
            string nombreTabla = "Provincias";
            return conexion.ObtenerTablas(consultaSQL, nombreTabla);
        }

        public DataTable ObtenerHorarios()
        {
            string consultaSQL = "SELECT * FROM Horario";
            string nombreTabla = "Horarios";
            return conexion.ObtenerTablas(consultaSQL, nombreTabla);
        }

        public int AgregarSucursal(string nombre, string descripcion, string idProvincia, string direccion)
        {
            string consultaSQL = ""; //CONSTRUIR LA CONSULTA SQL PARA AGREGAR UNA NUEVA SUCURSAL
            return conexion.EjecutarConsulta(consultaSQL);
        }

        public int EliminarSucursal(string idSucursal)
        {
            string consultaSQL = ""; // CONSTRUIR LA CONSULTA SQL PARA ELIMINAR UNA SUCURSAL
            return conexion.EjecutarConsulta(consultaSQL);
        }

        public DataTable BuscarSucursal(string idSucursal)
        {
            string consultaSQL = ""; //CONSTRUIR LA CONSULTA SQL PARA BUSCAR UNA SUCURSAL
            string nombreTabla = "Sucursales";
            return conexion.ObtenerTablas(consultaSQL, nombreTabla);
        }
    }
}