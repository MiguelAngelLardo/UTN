using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Entidades;
using System.Data;
using System.Data.SqlClient;

namespace Dao
{
    public class DaoCategoria
    {
        AccesoDatos ds = new AccesoDatos();
        public Categoria getCategoria(Categoria cat)
        {
            DataTable tabla = ds.ObtenerTabla("Categoria", "Select * from categorías where IdCategoría=" + cat.getIdCategoria());
            cat.setIdCategoria(Convert.ToInt32(tabla.Rows[0][0].ToString()));
            cat.setNombreCategoria(tabla.Rows[0][1].ToString());
            cat.setDescripcion(tabla.Rows[0][2].ToString());
            return cat;
        }

        public Boolean existeCategoría(Categoria cat)
        {
            String consulta = "Select * from categorías where NombreCategoría='" + cat.getNombreCategoria()+"'";
            return ds.existe(consulta);
        }

        public DataTable getTablaCategorias()
        {
           // List<Categoria> lista = new List<Categoria>();
            DataTable tabla = ds.ObtenerTabla("Categoria", "Select * from categorías");
            return tabla;
        }

        public int eliminarCategoria(Categoria cat)
        {
            SqlCommand comando = new SqlCommand();
            ArmarParametrosCategoriaEliminar(ref comando, cat);
            return ds.EjecutarProcedimientoAlmacenado(comando, "spEliminarCategoria");
        }


        public int agregarCategoria(Categoria cat)
        {
           
            cat.setIdCategoria(ds.ObtenerMaximo("SELECT max(idCategoría) FROM Categorías")+1);
            SqlCommand comando = new SqlCommand();
            ArmarParametrosCategoriaAgregar(ref comando, cat);
            return ds.EjecutarProcedimientoAlmacenado(comando, "spAgregarCategoria");
        }

        private void ArmarParametrosCategoriaEliminar(ref SqlCommand Comando, Categoria cat)
        {
            SqlParameter SqlParametros = new SqlParameter();
            SqlParametros = Comando.Parameters.Add("@IDCATEGORIA", SqlDbType.Int);
            SqlParametros.Value = cat.getIdCategoria();
        }

        private void ArmarParametrosCategoriaAgregar(ref SqlCommand Comando, Categoria cat)
        {
            SqlParameter SqlParametros = new SqlParameter();
            SqlParametros = Comando.Parameters.Add("@IDCATEGORIA", SqlDbType.Int);
            SqlParametros.Value = cat.getIdCategoria();
            SqlParametros = Comando.Parameters.Add("@NOMBRECAT", SqlDbType.VarChar);
            SqlParametros.Value = cat.getNombreCategoria();
        }


        /*
        CREATE PROCEDURE[dbo].[spEliminarCategoria]
        (
               @IDCATEGORIA INT
               )
               AS
        DELETE Categorías WHERE IdCategoría = @IDCATEGORIA
        RETURN
        */

        /*
       CREATE PROCEDURE[dbo].[spAgregarCategoria]
        (
        @IDCATEGORIA INT,
        @NOMBRECAT NVARCHAR(15)
        )
        AS
        INSERT INTO CATEGORÍAS(IdCategoría,NombreCategoría) VALUES(@IDCATEGORIA,@NOMBRECAT)
        RETURN
        */
    }
}
