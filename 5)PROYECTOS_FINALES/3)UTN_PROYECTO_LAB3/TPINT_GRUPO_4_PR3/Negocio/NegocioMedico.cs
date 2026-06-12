using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


using System.Data;
using System.Text.RegularExpressions;

using Dao;
using Entidades;

namespace Negocio
{
  public class NegocioMedico
  {
   private DaoMedico _daoMedico = new DaoMedico();

    public bool LoginMedico(string user, string pass)
    {
      return _daoMedico.ExisteMedicoYPass(user, pass);
    }


    public DataTable obtenerTablaGeneral()
    {
       return _daoMedico.getTablaMedicos();
    }


    /*lourd*/
    public bool CrearUsuarioMedico(Medico medico)
    {
    if (_daoMedico.ExisteUsuario(medico.Login.NombreUsuario))
       {
         throw new Exception($"El usuario '{medico.Login.NombreUsuario}' ya existe.");
        }
      int cantFilas = 0;

      cantFilas = _daoMedico.CrearUsuarioMedico(medico);

      if (cantFilas > 0)
        return true;
      else
        return false;
    }

    public DataTable ListarBuscarTodoMedicos(string nombreApellido, string legajo, int idEspecialidad, DataTable dtDias)
    {

      string nomApeSinEspacios = null;
      if (!string.IsNullOrWhiteSpace(nombreApellido))
      {
        string limpieza = nombreApellido.Trim();
        limpieza = Regex.Replace(limpieza, @"\s+", "%");
        nomApeSinEspacios = $"%{limpieza}%";
      }           
      // Ejemplo:
      // "   laura    go" -> (Trim) -> "laura    go"
      // "laura    go" -> (Regex) -> "laura%go"
      // "laura%go" -> (Wrap)con interpolacion -> "%laura%go%"


      string paramLegajo = null;
      if (!string.IsNullOrWhiteSpace(legajo)) paramLegajo = $"%{legajo.Trim()}%"; //interpolacion
      
      return _daoMedico.ListarBuscarTodoMedicos(nomApeSinEspacios, paramLegajo, idEspecialidad, dtDias);
    }

    public DataTable ListarMedicosPorEspecialidad(int idEspecialidad)//lo uso en agregar turno
    {
      return _daoMedico.ListarPorEspecialidad(idEspecialidad);
    }


    public bool AgregarMedico(Medico objMedico)
    {
      if (_daoMedico.ExisteDni(objMedico.Dni)) // VALIDACIÓN DE NEGOCIO => verifico DNI
      {
        throw new Exception($"El DNI '{objMedico.Dni}' ya está registrado.");//ex para que la atrape el .aspx.cs
      }

      if (_daoMedico.ExisteLegajo(objMedico.Legajo))
      {
        throw new Exception($"El Legajo '{objMedico.Legajo}' ya está registrado.");
      }

      return _daoMedico.AgregarMedico(objMedico);
    }


   private static readonly Dictionary<int, string> MapeoDias = new Dictionary<int, string> //ENUM ASUME QUE EN TU BASE DE DATOS LUNES=1, MARTES=2... DOMINGO=7
    {//static es para q se cree una sola vez el mapa al arrancar la ap, readonly es para q no se reemplace la referencia en tiempo de ejecucion
      { 1, "Lunes" },
      { 2, "Martes" },
      { 3, "Miércoles" },
      { 4, "Jueves" },
      { 5, "Viernes" },
      { 6, "Sábado" },
      { 7, "Domingo" }
    };

    public DiasHorariosMedico ObtenerDiasYHorarioMedico(string Legajo)
    {
                                                                  //recibe dataTable del SP HorarioBase IdsDiasTrabajo
      DataTable dt = _daoMedico.ObtenerInfoDiasHorarioMedico(Legajo);                   //08:00-12:00    1,2,3,4,5,6 => '1,3,5' una sola fila me da
      DiasHorariosMedico objInfoDiasHorario = new Entidades.DiasHorariosMedico();

      if (dt != null && dt.Rows.Count > 0)
      {
        DataRow fila = dt.Rows[0];//traigo 1 sola fila del SP
        objInfoDiasHorario.HorarioBase = fila["HorarioBase"].ToString(); // M.HorarioAtencion_M AS HorarioBase,
        objInfoDiasHorario.IdsDiasTrabajo = fila["IdsDiasTrabajo"].ToString();//STRING_AGG(CONVERT(VARCHAR, mxd.IdDia_D_MxD), ',') AS IdsDiasTrabajo

        if (!string.IsNullOrEmpty(objInfoDiasHorario.IdsDiasTrabajo))// Convertir IDs a Nombres para mostrar al usuario
        {
          string[] vDinIds = objInfoDiasHorario.IdsDiasTrabajo.Split(','); //el split siempre devuelve un array por eso no uso list => busca el ASCII 44 ',' para elimianrlo y hacer un nuevo dato del array
          List<string> colNombresDias = new List<string>();

          foreach (string idStr in vDinIds)
          {
            // Usamos Trim() para limpiar posibles espacios
            if (int.TryParse(idStr.Trim(), out int idDia) && MapeoDias.ContainsKey(idDia))//trim limpia "1 " por las dudas del split, si pasa de "1" a 1 lo guarda en idDia 
            {                                                                             //MapeoDias se fija que el 1 exista en su Diccionario
              colNombresDias.Add(MapeoDias[idDia]);// recibe un KEY pero guarda VALUE => recive 1, 3 ,5 y guarda lun, mierc, vier
            }
          }
          objInfoDiasHorario.NombresDiasTrabajo = string.Join(", ", colNombresDias);  // paso de ["Lunes", "Miércoles", "Viernes"] a "Lunes, Miércoles, Viernes"

        }
        else
        {
          objInfoDiasHorario.NombresDiasTrabajo = "Sin días cargados";// Si el SP devuelve NULL o cadena vacía
        }
      }
      return objInfoDiasHorario; // Si no se encuentra el médico, devuelve un objeto DiasHorariosMedico vacío.
    }

    /* //no me sirve la funcion por que string horaStr = filaTemporal["Hora_T"].ToString(); devolvia "08:00:00" con segundos 
    public List<string> ObtenerHorasOcupadas(string Legajo, DateTime Fecha)
    {
      
      DataTable dtOcupados = _daoMedico.ObtenerHorasOcupadas(Legajo, Fecha);
      List<string> horasOcupadas = new List<string>();

      if (dtOcupados != null && dtOcupados.Rows.Count > 0)
      {
        foreach (DataRow filaTemporal in dtOcupados.Rows)
        {
          string horaStr = filaTemporal["Hora_T"].ToString();// La base de datos guarda la hora como time pero aqui la tratamos como string
          if (!string.IsNullOrEmpty(horaStr))// Añadir el string al listado (ej: iteracion 1 "08:00", iteracion 2 "09:00")
          {
            horasOcupadas.Add(horaStr);
          }
        }
      }
      return horasOcupadas;
    }*/

    public List<string> ObtenerHorasOcupadas(string Legajo, DateTime Fecha)
    {
      DataTable dtHorasOcupadas = _daoMedico.ObtenerHorasOcupadas(Legajo, Fecha); // Llama al DAO para obtener un DataTable con la columna Hora_T (ej: "08:00:00")
      List<string> horasOcupadas = new List<string>(); // Lista final que contendrá solo los strings en formato "HH:MM"

      if (dtHorasOcupadas != null && dtHorasOcupadas.Rows.Count > 0)
      {
        foreach (DataRow fila in dtHorasOcupadas.Rows)
        {
          string horaStrConSegundos = fila["Hora_T"].ToString(); // Captura el string que incluye segundos/milisegundos, típicamente "08:00:00" para un TIME(0)

          if (!string.IsNullOrEmpty(horaStrConSegundos))
          {
           
            if (TimeSpan.TryParse(horaStrConSegundos, out TimeSpan horaTimeSpanSinSeg))//si en  horaStrConSegundos hay un string convertilo en TimeSpan => si es true guardalo en  horaTimeSpanSinSeg
            {
              
              // Esto garantiza que la cadena sea IDÉNTICA al formato generado por GenerarSlotsDesdeHorario,
              horasOcupadas.Add(horaTimeSpanSinSeg.ToString(@"hh\:mm"));//uso el metoo de TimeSpan con mini regex
            }//es identico al GenerarSlotsDesdeHorario que declare en en el aspx.cs
          }
        }
      }

      return horasOcupadas;
    }


        public bool CambiarEstadoUsuarioMedico(string legajo, bool habilitado)
        {
            if (string.IsNullOrEmpty(legajo)) return false;

            return _daoMedico.CambiarEstadoUsuarioMedico(legajo, habilitado) > 0;
        }


        public bool CambiarUsuario(Medico medico)
        {
            if (_daoMedico.ExisteUsuario(medico.Login.NombreUsuario))
            {
                throw new Exception($"El usuario '{medico.Login.NombreUsuario}' ya existe.");
            }
            int cantFilas = 0;

            cantFilas = _daoMedico.CambiarUsuarioMedico(medico);

           return cantFilas  == 1;
        }

        public bool CambiarContrasenia(Medico medico)
        {

            int cantFilas = 0;
       
            cantFilas = _daoMedico.CambiarContraseniaMedico(medico);

            return cantFilas == 1;

        }

        public bool EliminarMedico(string legajo)
        {
            if (string.IsNullOrEmpty(legajo))
            {
                return false;
            }
            int filasAfectadas = _daoMedico.EliminarMedico(legajo);
            return filasAfectadas == 1;
        }


        public Medico GetMedicoPorLegajo(string legajo, out int idProvincia) 
        {
            return _daoMedico.GetMedicoPorLegajo(legajo, out idProvincia); 
        }
        public bool ActualizarMedico(Medico objMedico) 
        {
            return _daoMedico.ActualizarMedico(objMedico);
        }
        public bool EliminarUsuario(string legajo)
        {
            int filasAfectadas = 0;
            Medico medico = new Medico();
            medico.Legajo = legajo;
            filasAfectadas = _daoMedico.EliminarUsuarioMedico(medico);
            return filasAfectadas == 1;
        }
        public string ObtenerNombreUsuarioPorLegajo(string legajo)
        {
            Medico medico = new Medico();
            medico.Legajo = legajo;
            return _daoMedico.ObtenerNombreUsuarioPorLegajo(medico);
        }

        public System.Data.DataTable ObtenerDatosMedicoParaDetalle(string legajo)
        {
            DaoMedico dao = new DaoMedico();
            return dao.ObtenerTablaDatosMedico(legajo);
        }

    }
    
}
