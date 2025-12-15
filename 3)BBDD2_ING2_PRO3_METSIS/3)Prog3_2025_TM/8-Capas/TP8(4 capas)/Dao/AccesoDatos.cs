using System;
using System.Collections.Generic;
using System.Data.SqlTypes;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data.SqlClient;
using System.Data;
namespace Dao
{
  public class AccesoDatos
  {
    private string _ruta;

    public AccesoDatos(string ruta = "Data Source= localhost; Initial Catalog = Viajes; User ID = sa; Password=Miguel-1234;Encrypt=False")
    {
      _ruta = ruta;
    }

    /*
    private SqlConnection getConexion()
    {
      SqlConnection cn = new SqlConnection(_ruta);
      try
      {
        cn.Open();
        return cn;
      }
      catch (Exception ex)
      {
        return null;
      }
     }*/

    /*
    private SqlDataAdapter getDataAdapter(string consultaSelect, SqlConnection cn)
    {
      SqlDataAdapter adap;
      try
      {
        adap = new SqlDataAdapter(consultaSelect, cn);
        return adap;
      }
      catch (Exception ex)
      {
        return null;
      }
    }*/

    /*
     Interfaz IDisposable 
     Abuelo Component : MarshalByRefObject, IComponent, IDisposable
     Padre abstract DbConnection : Component, IDbConnection, IDisposable
     Hija SqlConnection : DbConnection, ICloneable
     

    
      ///Interfaz/////////////////
      [ComVisible(true)] -> etiqueta para usar sistemasmas antiguos como COM
      [__DynamicallyInvokable] -> Etiqueta interna de Microsoft para indicar que el miembro puede ser invocado dinámicamente.

      public interface IDisposable
      {
       
        [__DynamicallyInvokable]
        void Dispose();
      }
     

     ///Abuelo/////////////////
     Abuelo
     public class Component : MarshalByRefObject, IComponent, IDisposable
     {
    // ... (otras propiedades y eventos) ...

    // --- El Patrón de Limpieza Completo ---

    // 2. El Plan de Emergencia (Finalizador)
    ~Component()
    {
        Dispose(disposing: false);
    }

    // 1. El Plan Principal (Punto de entrada para 'using')
    public void Dispose()
    {
        Dispose(disposing: true);
        GC.SuppressFinalize(this);
    }

    // 3. El Trabajador (Donde ocurre la limpieza real)
    protected virtual void Dispose(bool disposing)
    {
        // Si es una limpieza de emergencia, no hace nada más.
        if (!disposing)
        {
            return;
        }

        // 'lock' es para evitar problemas si dos procesos intentan limpiar al mismo tiempo.
        lock (this)
        {
            // TAREA 1: Desvincularse de su contenedor.
            if (site != null && site.Container != null)
            {
                site.Container.Remove(this);
            }

            // TAREA 2: Avisar a otros que está siendo destruido.
            if (events != null)
            {
                ((EventHandler)events[EventDisposed])?.Invoke(this, EventArgs.Empty);
            }
        }
    }
}
     

    //Padre/////////////////
    public abstract class DbConnection : Component, IDbConnection, IDisposable
    no hace nada con Dispose
    : re-declara la interfaz IDisposable en su firma. Al hacerlo, estandariza y fuerza a que todas las clases de conexión 
    (para SQL Server, Oracle, etc.) sigan obligatoriamente este patrón de limpieza.

    public abstract class DbConnection : Component, IDbConnection, IDisposable // <-- ¡AQUÍ ESTÁ!
    aunque ya hereda de Component (que es IDisposable), los diseñadores de .NET volvieron a escribir IDisposable en la lista de "contratos" que DbConnection firma.
    Tu pregunta es perfecta: si ya lo hereda, ¿por qué escribirlo de nuevo? Parece redundante. La razón es una decisión de diseño para hacer el código más claro y seguro.

    Component (El Abuelo): El abuelo, un ingeniero muy organizado, tenía como regla personal ser siempre muy ordenado (IDisposable).
      Por Claridad: Para que un programador que mire la clase DbConnection sepa inmediatamente que es IDisposable sin tener que ir a investigar al "abuelo" Component. 
      Es una forma de auto-documentación.


    si fuera public abstract class DbConnection : Component, IDbConnection  Igualmente heredaría IDisposable de Component y, por lo tanto, SqlConnection también lo heredaría 
    y todo el sistema con el using seguiría funcionando exactamente igual


    por que lo hacen ? La re-declaración no es una necesidad técnica para que el código compile, es una decisión de diseño para que el código sea más claro, 
    explícito y robusto para los programadores que lo usan.

    //hijo///
    IDisposable de nuevo, ya que lo hereda de su padre. Sin embargo, sobrescribe (override) el método protected Dispose(bool) 
    para añadir su lógica de limpieza específica y más importante: la llamada al método Close() para cerrar la conexión con la base de datos.
    
     SqlConnecion


      protected override void Dispose(bool disposing)
      {
        if (disposing)
        {
          _userConnectionOptions = null; // Libera recursos administrados.
          _poolGroup = null; // Libera recursos administrados.
          Close(); // Cierra la conexión si está abierta.
        }

        DisposeMe(disposing); 
        base.Dispose(disposing); -> para que la clase padre DbConnection también libere sus recursos.
      }

     */

    // Los métodos privados getConexion() y getDataAdapter() ya no son necesarios

    public DataTable getTabla(string consultaSelect) //no uso try catch para que la excepcion la maneje quien llama al metodo
    {
      DataTable dt = new DataTable();

      using (SqlConnection cn = new SqlConnection(_ruta))//el using se encarga de cerrar y disponer la conexion.. OJO NO LA ABRE
      {

        SqlDataAdapter da = new SqlDataAdapter(consultaSelect, cn);// using (SqlDataAdapter da = new SqlDataAdapter(consultaSelect, cn))

        da.Fill(dt);//Dentro del método Fill, el DataAdapter ve que cn está Cerrada, así que la abre, carga los datos en dt y luego la cierra automáticamente.
      } //using debe cerrar la conexion,pero ya viene cerrada del Fill

      return dt;
    }

    /*
   SqlCommand cmd = new SqlCommand();
    cmd.CommandText = "sp_InsertarSucursal"; // Por ejemplo
    cmd.Parameters.AddWithValue("@Nombre", txtNombre.Text);
    cmd.Parameters.AddWithValue("@Descripcion", txtDescripcion.Text);
    AccesoDatos datos = new AccesoDatos();
    int resultado = datos.ejecutarSP(cmd);


     */
    public int ejecutarSP(SqlCommand objSC)
    {
      using (SqlConnection cn = new SqlConnection(_ruta))
      {
        objSC.Connection = cn;
        objSC.CommandType = CommandType.StoredProcedure;

        try
        {
          cn.Open();// diferencia de Fill(), ExecuteNonQuery() SÍ necesita que abramos la conexión manualmente.
          return objSC.ExecuteNonQuery();
        }
        catch (Exception ex)
        {
          return -1;
        }
      } //el using utiliza un Finally interno para cerrar y disponer la conexion
    }


    /*
     
     public Boolean existe(String consulta)
        {
            Boolean estado = false;
            SqlConnection Conexion = ObtenerConexion();
            SqlCommand cmd = new SqlCommand(consulta, Conexion);
            SqlDataReader datos = cmd.ExecuteReader();
            if (datos.Read())
            {
                estado = true;
            }
            return estado;
        }

        public int ObtenerMaximo(String consulta)
        {
            int max = 0;
            SqlConnection Conexion = ObtenerConexion();
            SqlCommand cmd = new SqlCommand(consulta, Conexion);
            SqlDataReader datos = cmd.ExecuteReader();
            if (datos.Read())
            {
                max = Convert.ToInt32(datos[0].ToString());
            }
            return max;
        }
     */


  }
}
