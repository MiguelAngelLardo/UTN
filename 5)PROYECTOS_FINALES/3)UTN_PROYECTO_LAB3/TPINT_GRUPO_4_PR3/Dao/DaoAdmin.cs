using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data.SqlClient;
namespace Dao
{

  public class DaoAdmin
  {

    private AccesoDatos _accesoDatos = new AccesoDatos();


    public bool ExisteAdminYPass(string user, string pass)
    {

      string consulta = "SELECT 1 FROM Administradores WHERE Usuario_A = @User AND Contrasena_A = @Pass AND UsuarioHabilitado_A = 1"; //SQL devuelve una fila que contiene 1

      List<SqlParameter> parametros = new List<SqlParameter>();
      parametros.Add(new SqlParameter("@User", user)); //le paso Key Value
      parametros.Add(new SqlParameter("@Pass", pass));

      return _accesoDatos.Existe(consulta, parametros);
    }
  }
}
