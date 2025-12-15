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
  public class NegocioTurno
  {
      private DaoTurno _daoTurno = new DaoTurno();


    public DataTable ListarTablaTurno()
    {
        return _daoTurno.getTablaTurnoAdmnistrador();
    }

    public DataTable ListarTablaTurnoMedico(string usuarioMedico)
    {
        return _daoTurno.getTablaTurnoMedico(usuarioMedico);
    }


    public bool AgregarTurno(Turno nuevoTurno)
    {
      return _daoTurno.AgregarTurno(nuevoTurno);
    }


    public bool EditarTurno(Turno turnoEditado)
    {
      return _daoTurno.EditarTurno(turnoEditado);
    }
    public void EliminarTurno(string idTurno)
    {
        _daoTurno.EliminarTurno(idTurno);
    }

    public Turno GetDatosTurno(string idTurno)
    {
      return _daoTurno.GetDatosTurno(idTurno);
    }



    public bool ActualizarAtencion(int idTurno, string observacion, bool asistio)
    {          
      if (!asistio) observacion = "No Asistio";//REGLA DE NEGOCIO =>: Si no asistió, la observación es nula/vacía => por que si escribo algo sin esto y no asistio me lo guarda
      return _daoTurno.ActualizarAtencionTurno(idTurno, observacion, asistio);
    }

   //a la fuerza le tengo que pasar los valores de lo que se completo en el filtrado, pued venir vacio naturalmente
        public DataTable BuscarTurnosAdministrador(
            string nombreApellidoMedico,
            string nombreApellidoPaciente,
            int? idEspecialidad, // tengo que usarlo como "int?" porque si no no tengo otra forma de representar la posbilidad de que venga vacio/nulo,
            bool lunes,           // si es int solo siempre va a pedir un valor, ese int? es una """""abreviacion""""" de Nullable<int>,
            bool martes,          //que admite yun valor entero o un nulo/vacio
            bool miercoles,
            bool jueves,
            bool viernes,
            bool sabado)
        {
            return _daoTurno.BuscarTurnosAdministrador(
                nombreApellidoMedico,
                nombreApellidoPaciente,
                idEspecialidad,
                lunes,
                martes,
                miercoles,
                jueves,
                viernes,
                sabado);
        }

        public InformePresentismo ReportePresentismo(DateTime fechaDesde, DateTime fechasHasta)
        {
            DataTable dt = _daoTurno.ReportePresentismo(fechaDesde, fechasHasta);

            InformePresentismo informe = new InformePresentismo();

            foreach (DataRow fila in dt.Rows)
            {
                int cantidad = Convert.ToInt32(fila["Cantidad"]);

                bool esPresente = Convert.ToBoolean(fila["Atendido_T"]);

                if (esPresente == true)
                {
                    informe.Presentes = cantidad;
                }
                else
                {
                    informe.Ausentes = cantidad;
                }
            }

            informe.Total = informe.Presentes + informe.Ausentes;
            if (informe.Total > 0)
            {
                informe.PorcentajePresentes = (double)informe.Presentes * 100 / informe.Total;
                informe.PorcentajeAusentes = (double)informe.Ausentes * 100 / informe.Total;
            }
            return informe;
        }

        public DataTable ReportePresentismoDetalle(DateTime fechaDesde, DateTime fechaHasta)
        {
            return _daoTurno.ReportePresentismoDetalle(fechaDesde, fechaHasta);
        }

        public InformeRanking ObtenerReporteRanking(DateTime desde, DateTime hasta) { 
            DataTable dt = _daoTurno.ObtenerReporteTurnosPorMedico(desde, hasta);

            InformeRanking informe = new InformeRanking();

            informe.detalleRanking = dt;

            if (dt.Rows.Count > 0)
            {
                int acumuladorTotal = 0;
                foreach (DataRow fila in dt.Rows)
                {
                    acumuladorTotal += Convert.ToInt32(fila["CantidadTurnos"]);
                }
                informe.turnosTotal = acumuladorTotal;

                informe.cantidadMaxima = Convert.ToInt32(dt.Rows[0]["CantidadTurnos"]);

                double promedio = (double)informe.turnosTotal / dt.Rows.Count;

                informe.promedioTurnos = promedio.ToString("0.0");
            }
            else
            {
                informe.turnosTotal = 0;
                informe.cantidadMaxima = 0;
                informe.promedioTurnos = "0";
            }

            return informe;
        }

        public DataTable BuscarTurnoPorPaciente(string nombre, string usuarioMedico)
        {
            return _daoTurno.getTablaTurnoMedicoPorPaciente(nombre, usuarioMedico);
        }
        public DataTable FiltrarTurnos(int asistio, string fecha, string usuarioMedico)
        {
            DateTime? fechaConvertida = null;

            if (!string.IsNullOrEmpty(fecha))
            {
                DateTime f;
                if (DateTime.TryParse(fecha, out f))
                    fechaConvertida = f;
            }

            return _daoTurno.FiltrarTurnos(asistio, fechaConvertida, usuarioMedico);
        }


    }
}
