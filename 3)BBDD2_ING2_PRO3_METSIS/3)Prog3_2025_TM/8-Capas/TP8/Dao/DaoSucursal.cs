using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data.SqlClient;
using System.Data;

using Entidades;

namespace Dao
{
  public class DaoSucursal
  {

    private AccesoDatos _accesoDatos = new AccesoDatos();

    public DataTable getTablaSucursales()
    {
      string consulta = @"SELECT
                            Sucursal.Id_Sucursal,
                            Sucursal.NombreSucursal as Nombre,
                            Sucursal.DescripcionSucursal as Descripcion,
                            Provincia.DescripcionProvincia as Provincia,
                            Sucursal.DireccionSucursal as Direccion
                        FROM
                            Sucursal
                        INNER JOIN
                            Provincia ON Provincia.Id_Provincia = Sucursal.Id_ProvinciaSucursal";

      return _accesoDatos.daoGetTablaAdap(consulta); // Asumo que tu método en AccesoDatos se llama getTabla
    }


    public DataTable getTablaSucursalesPorIdSuc(string idSuc)
    {
      string consulta = @"SELECT
                            Sucursal.Id_Sucursal,
                            Sucursal.NombreSucursal as Nombre,
                            Sucursal.DescripcionSucursal as Descripcion,
                            Provincia.DescripcionProvincia as Provincia,
                            Sucursal.DireccionSucursal as Direccion
                        FROM
                            Sucursal
                        INNER JOIN
                            Provincia ON Provincia.Id_Provincia = Sucursal.Id_ProvinciaSucursal
                        WHERE 
                            Sucursal.Id_Sucursal = " + idSuc;

      return _accesoDatos.daoGetTablaAdap(consulta);  
    }






    public int agregarSucursal(Sucursal suc)
    {
      // 1. Creamos el comando y le asignamos el NOMBRE del Stored Procedure.
      SqlCommand cmd = new SqlCommand("spAgregarSucursal");

      // 2. Le agregamos los parámetros de forma segura y directa con AddWithValue.
      //    No necesitamos un método 'ArmarParametros' aparte.
      cmd.Parameters.AddWithValue("@NombreSucursal", suc.getNombreSucursal());
      cmd.Parameters.AddWithValue("@Descripcion", suc.getDescripcionSucursal());
      cmd.Parameters.AddWithValue("@Provincia", suc.getIdProvincia());
      cmd.Parameters.AddWithValue("@Direccion", suc.getDireccionSucursal());

      // 3. Llamamos al método de tu clase AccesoDatos y le pasamos el comando ya listo.
      return _accesoDatos.ejecutarSP(cmd);//  objSC.Connection = cn; objSC.CommandType = CommandType.StoredProcedure;
    }


    public bool eliminarSucursal(string eliminarSucursal)
    {
      SqlCommand cmd = new SqlCommand("spEliminarSucursal");
      cmd.Parameters.AddWithValue("@idSucursal", eliminarSucursal);
      int filasAfectadas = _accesoDatos.ejecutarSP(cmd);
      return filasAfectadas == 1;
    }


    /*
    AccesoDatos ds = new AccesoDatos();
    public Sucursal GetSucursal(Sucursal cat)
    {
      DataTable tabla = ds.ObtenerTabla("Sucursal", "Select * from Sucursal where Id_Sucursal=" + cat.getIdSucursal());
      cat.setIdSucursal(Convert.ToInt32(tabla.Rows[0][0].ToString()));
      cat.setNombreSucursal(tabla.Rows[0][1].ToString());
      cat.setDescripcionSucursal(tabla.Rows[0][2].ToString());
      cat.setIdProvinciaSucursal(Convert.ToInt32(tabla.Rows[0][4].ToString()));
      cat.setDireccionSucursal(tabla.Rows[0][5].ToString());
      return cat;
    }

    public Boolean existeCategoría(Sucursal cat)
    {
      String consulta = "Select * from Sucursal where NombreSucursal='" + cat.getNombreSucursal() + "'";
      return ds.existe(consulta);
    }
    public Boolean existeID(Sucursal id)
    {
      String consulta = "Select * from Sucursal where id_Sucursal=" + id.getIdSucursal();
      return ds.existe(consulta);
    }
    public DataTable getTablaPorID(Sucursal id)
    {
      string consulta = @"
            SELECT s.Id_Sucursal, s.NombreSucursal AS 'Nombre', s.DescripcionSucursal AS 'Descripcion',
             p.DescripcionProvincia AS 'Provincia', s.DireccionSucursal AS 'Direccion'
            FROM Sucursal AS s 
            JOIN Provincia AS p ON s.Id_ProvinciaSucursal = p.Id_Provincia
            WHERE s.Id_Sucursal = " + id.getIdSucursal();

      DataTable tabla = ds.ObtenerTabla("Sucursal", consulta);
      return tabla;
    }

    public DataTable getTablaSucursales()
    {
      string consulta = @"
            SELECT s.Id_Sucursal, s.NombreSucursal AS 'Nombre', s.DescripcionSucursal AS 'Descripcion',p.DescripcionProvincia AS 'Provincia',s.DireccionSucursal AS 'Direccion'
            FROM Sucursal AS s JOIN Provincia AS p ON s.Id_ProvinciaSucursal = p.Id_Provincia

            WHERE s.ID_SUCURSAL >= 0";

      // List<Sucursal> lista = new List<Sucursal>();
      DataTable tabla = ds.ObtenerTabla("Sucursal", consulta);
      return tabla;
    }

    public DataTable getTablaSucursalesCompleta()
    {
      // List<Sucursal> lista = new List<Sucursal>();
      DataTable tabla = ds.ObtenerTabla("Sucursal", "Select * from Sucursal");
      return tabla;
    }

    public int eliminarSucursal(Sucursal cat)
    {
      SqlCommand comando = new SqlCommand();
      ArmarParametrosSucursalEliminar(ref comando, cat);
      return ds.EjecutarProcedimientoAlmacenado(comando, "spEliminarSucursal");
    }



    private void ArmarParametrosSucursalEliminar(ref SqlCommand Comando, Sucursal cat)
    {
      SqlParameter SqlParametros = new SqlParameter();
      SqlParametros = Comando.Parameters.Add("@IdSucursal", SqlDbType.Int);
      SqlParametros.Value = cat.getIdSucursal();
    }

    public int agregarSucursal(Sucursal cat)
    {

      cat.setIdSucursal(ds.ObtenerMaximo("SELECT max(Id_Sucursal) FROM Sucursal") + 1);
      SqlCommand comando = new SqlCommand();
      ArmarParametrosSucursalAgregar(ref comando, cat);
      return ds.EjecutarProcedimientoAlmacenado(comando, "spAgregarSucursal");
    }
    private void ArmarParametrosSucursalAgregar(ref SqlCommand Comando, Sucursal cat)
    {
      SqlParameter SqlParametros = new SqlParameter();

      // NombreSucursal
      SqlParametros = Comando.Parameters.Add("@NombreSucursal", SqlDbType.VarChar, 100); /
      SqlParametros.Value = cat.getNombreSucursal();

      // DescripcionSucursal
      SqlParametros = Comando.Parameters.Add("@Descripcion", SqlDbType.VarChar, 100); 
      SqlParametros.Value = cat.getDescripcionSucursal();

      // IdProvinciaSucursal
      SqlParametros = Comando.Parameters.Add("@Provincia", SqlDbType.Int);
      SqlParametros.Value = cat.getIdProvinciaSucursal();

      // DireccionSucursal
      SqlParametros = Comando.Parameters.Add("@Direccion", SqlDbType.VarChar, 100); 
      SqlParametros.Value = cat.getDireccionSucursal();
    }*/

    /*
   USE BDSucursales
GO

CREATE PROCEDURE [dbo].[spEliminarSucursal]
(@idSucursal int)
AS
DELETE Sucursal WHERE Id_Sucursal = @idSucursal
RETURN
GO



    CREATE PROCEDURE[dbo].[spAgregarSucursal]
    (
    @NombreSucursal VARCHAR(100),
@Descripcion VARCHAR(100),
@Provincia int,
@Direccion VARCHAR(100)
    )
    AS
    INSERT INTO Sucursal(NombreSucursal,DescripcionSucursal,Id_ProvinciaSucursal,DireccionSucursal) VALUES(@NombreSucursal,@Descripcion,@Provincia,@Direccion)
    RETURN
    GO
    */







  }
}
