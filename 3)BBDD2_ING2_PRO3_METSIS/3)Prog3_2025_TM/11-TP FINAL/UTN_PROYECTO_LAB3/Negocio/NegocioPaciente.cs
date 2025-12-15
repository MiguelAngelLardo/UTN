using Dao;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using Entidades;
using Datos;


namespace Negocio
{
    public class NegocioPaciente
    {
        private DaoPaciente _daoPaciente = new DaoPaciente();

        public DataTable BuscarPacientes(string nomApe, string dni)
        {
            return _daoPaciente.BuscarPacientes(nomApe, dni);
        }

        public bool AgregarPaciente(Paciente nuevoPaciente)
        {
            if (_daoPaciente.ExisteDni(nuevoPaciente.Dni))
            {
                throw new Exception("El DNI ingresado ya se encuentra registrado.");
            }
            return _daoPaciente.AgregarPaciente(nuevoPaciente);
        }

        public bool EliminarPaciente(string dni)
        {
            if (string.IsNullOrEmpty(dni))
            {
                return false;
            }

            int filasAfectadas = _daoPaciente.EliminarPaciente(dni);
            return filasAfectadas == 1;
        }

        public Entidades.Paciente GetPacientePorDni(string dni, out int idProvincia)
        {
            return _daoPaciente.GetPacientePorDni(dni, out idProvincia);
        }
        public int EditarPaciente(Paciente pacienteEditado)
        {
            return _daoPaciente.editarPaciente(pacienteEditado);
        }
        public DataTable ObtenerPaciente(string dni)
        {
            return _daoPaciente.ObtenerPaciente(dni);
        }


    public DataTable ListarPacientesActivos()//para el agregar turno (migue)
    {
      return _daoPaciente.ListarPacientesActivos();
    }



    }
}