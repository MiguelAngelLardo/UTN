using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
namespace Dao
{
    internal class AccesoDatos
    {

        private string _ruta;

        //const String miRuta = @"Data Source=localhost\SQLEXPRESS;Initial Catalog=Clinica;Integrated Security=True";
        //const string miRuta = "data Source=localhost; Initial Catalog=Clinica; user ID=sa; Password=Miguel-1234; Encrypt=False;";
        //const String miRuta = @"Data Source=DESKTOP-S5DL2KN\SQLEXPRESS;Initial Catalog=Clinica;Integrated Security=True";


        public AccesoDatos(string ruta = miRuta)
        {
            _ruta = ruta;
        }

        public bool Existe(string consulta, List<SqlParameter> parametros)
        {
            bool estado = false;
            using (SqlConnection cn = new SqlConnection(_ruta))
            {
                try
                {
                    cn.Open();

                    SqlCommand cmd = new SqlCommand(consulta, cn);
                    foreach (SqlParameter param in parametros) cmd.Parameters.Add(param);
                    SqlDataReader datos = cmd.ExecuteReader();//Execute Reader abre conexion y lee uan fila a la vez
                    estado = datos.Read(); //Si el usuario existe, datos.Read() se mueve a esa única fila y devuelve true.

                }
                catch (Exception ex)
                {
                    System.Diagnostics.Debug.WriteLine(ex.Message); //imprime mensaje 
                    estado = false;
                }
            }//usa un finally para cerrar la conex con la Herencia de DbConnection usando Protected override void Dispose(bool disposing)
            return estado;
        }
        private SqlConnection ObtenerConexion()
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
        }

        private SqlDataAdapter ObtenerAdaptador(String consultaSql, SqlConnection cn)
        {
            SqlDataAdapter adaptador;
            try
            {
                adaptador = new SqlDataAdapter(consultaSql, cn);
                return adaptador;
            }
            catch (Exception ex)
            {
                return null;
            }
        }

        public DataTable ObtenerTabla(string nombreTabla, string consultaSql, List<SqlParameter> parametros)
        {
            DataTable tabla = new DataTable();

            using (SqlConnection cn = new SqlConnection(_ruta))
            {
                cn.Open();
                SqlCommand cmd = new SqlCommand(consultaSql, cn);

                if (parametros != null)
                {
                    foreach (SqlParameter param in parametros)
                        cmd.Parameters.Add(param);
                }

                SqlDataAdapter adp = new SqlDataAdapter(cmd);
                adp.Fill(tabla);
            }

            return tabla;
        }

        public int EjecutarProcedimientoAlmacenado(SqlCommand Comando, String NombreSP)
        {
            int FilasCambiadas;
            SqlConnection Conexion = ObtenerConexion();
            SqlCommand cmd = new SqlCommand();
            cmd = Comando;
            cmd.Connection = Conexion;
            cmd.CommandType = CommandType.StoredProcedure;
            cmd.CommandText = NombreSP;
            FilasCambiadas = cmd.ExecuteNonQuery();
            Conexion.Close();
            return FilasCambiadas;
        }


        public DataTable ObtenerTabla(String NombreTabla, String consultaSql)
        {
            DataSet ds = new DataSet();
            SqlConnection Conexion = ObtenerConexion();
            SqlDataAdapter adp = ObtenerAdaptador(consultaSql, Conexion);
            adp.Fill(ds, NombreTabla);
            Conexion.Close();
            return ds.Tables[NombreTabla];
        }

        public DataTable ObtenerTabla(string nombreSP, List<SqlParameter> listParam = null)
        {
            DataTable tabla = new DataTable();
            using (SqlConnection cn = new SqlConnection(_ruta))
            {
                try
                {
                    cn.Open();
                    SqlCommand cmd = new SqlCommand(nombreSP, cn);
                    cmd.CommandType = CommandType.StoredProcedure;
                    if (listParam != null) foreach (SqlParameter param in listParam) cmd.Parameters.Add(param);

                    SqlDataReader lector = cmd.ExecuteReader();
                    tabla.Load(lector);
                    lector.Close();
                }
                catch (Exception ex)
                {
                    System.Diagnostics.Debug.WriteLine(ex.Message);
                    tabla = new DataTable();//tabla vacia si da error
                }
            } // El 'using' cierra la conexión
            return tabla;
        }

        public int EjecutarSP(string nombreSP, List<SqlParameter> listParam)
        {

            using (SqlConnection cn = new SqlConnection(_ruta))
            {
                try
                {
                    cn.Open();
                    SqlCommand cmd = new SqlCommand(nombreSP, cn);
                    cmd.CommandType = CommandType.StoredProcedure;
                    if (listParam != null) foreach (SqlParameter param in listParam) cmd.Parameters.Add(param);

                    SqlParameter paramRetorno = new SqlParameter();
                    paramRetorno.Direction = ParameterDirection.ReturnValue;//esto es para que el cmd pueda escribir 1 o 0 => pero me debo asegurar que el SP tenga RETURN 1; 
                    cmd.Parameters.Add(paramRetorno);

                    cmd.ExecuteNonQuery();// ExecuteNonQuery() devuelve -1 por el SET NOCOUNT ON del SP asi que no me sirve. => lo uso por que es necesario para que el motor trabaje
                    return (int)paramRetorno.Value;// Esto valdrá 1 (éxito) o 0 (error) como en el SP
                }
                catch (Exception ex)
                {
                    System.Diagnostics.Debug.WriteLine(ex.Message);
                    return 0; // Devuelve 0 si falla
                }
            } // El 'using' cierra la conexión
        }


    }
}


// Si la lista de parámetros no es nula, los agregamos

/*
------SCRIPT DE CREACIÓN Y CARGA DE BASE DE DATOS CLÍNICA MÉDICA - PROGRAMACIÓN III------

---------------------------------------------------------------
--Ir a Query => Click en SQLCMD MODE
---------------------------------------------------------------

DROP DATABASE "$(NOMBRE_BBDD)" 

:setvar NOMBRE_BBDD "Clinica"  --Declaro variables de script con modo SQLCMD 

USE master;
GO

IF DB_ID('$(NOMBRE_BBDD)') IS NOT NULL
BEGIN
  PRINT 'Poniendo la BBDD $(NOMBRE_BBDD) en modo un solo usuario.';    
  ALTER DATABASE [$(NOMBRE_BBDD)] SET SINGLE_USER WITH ROLLBACK IMMEDIATE; --me permite ejecutar el script sacando a otros usuarios si los hubiera    
  PRINT 'Borrando la BBDD $(NOMBRE_BBDD)...';
	DROP DATABASE [$(NOMBRE_BBDD)];
  PRINT '¡BBDD $(NOMBRE_BBDD) eliminada!';
END
ELSE
BEGIN
  PRINT 'La BBDD $(NOMBRE_BBDD) no existe. No se hizo nada.';
END
GO

PRINT 'Creando la BBDD $(NOMBRE_BBDD)...';
CREATE DATABASE [$(NOMBRE_BBDD)];
GO

USE [$(NOMBRE_BBDD)];
GO

------CREACIÓN DE TABLAS (ESTRUCTURA)---(En orden de dependencia de Claves Foráneas)------

PRINT 'Creando tablas maestras(Referencia)...';
CREATE TABLE Provincias (
  IdProvincia_Pr INT IDENTITY(1,1) NOT NULL,
  Nombre_Pr NVARCHAR(50) NOT NULL,
  Estado_Pr BIT NOT NULL,
  CONSTRAINT PK_Provincias PRIMARY KEY (IdProvincia_Pr)
);

	CREATE TABLE Localidades (
	IdLocalidad_L INT IDENTITY(1,1) NOT NULL,
	Nombre_L NVARCHAR(100) NOT NULL,
	IdProvincia_Pr_L INT NOT NULL,
	Estado_L BIT NOT NULL,
	CONSTRAINT PK_Localidades PRIMARY KEY (IdLocalidad_L),
	CONSTRAINT FK_Localidades_Provincias FOREIGN KEY (IdProvincia_Pr_L)
	REFERENCES Provincias(IdProvincia_Pr)
);

CREATE TABLE Especialidades (
  IdEspecialidad_E INT IDENTITY(1,1) NOT NULL,
  Descripcion_E NVARCHAR(100) NOT NULL,
  Estado_E BIT NOT NULL,
  CONSTRAINT PK_Especialidades PRIMARY KEY (IdEspecialidad_E)
);

CREATE TABLE DiasSemana (
  IdDia_D INT PRIMARY KEY,
  NombreDia_D NVARCHAR(15) NOT NULL
);

PRINT 'Creando tablas de herencia (TPT)...';
CREATE TABLE Personas (
    Dni_P NVARCHAR(8) NOT NULL,
    IdLocalidad_L_P INT,
    Nombre_P NVARCHAR(50) NOT NULL,
    Apellido_P NVARCHAR(50) NOT NULL,
    Sexo_P CHAR(1) NOT NULL,
    Nacionalidad_P NVARCHAR(50),
    FechaNacimiento_P DATE NOT NULL,
    Direccion_P NVARCHAR(100),
    CorreoElectronico_P NVARCHAR(100),
    Telefono_P NVARCHAR(50),
    Estado_P BIT NOT NULL,
    CONSTRAINT PK_Personas PRIMARY KEY (Dni_P),
    CONSTRAINT FK_Personas_Localidades FOREIGN KEY (IdLocalidad_L_P) REFERENCES Localidades(IdLocalidad_L)
);

CREATE TABLE Pacientes (
    Dni_P_Pa NVARCHAR(8) NOT NULL,
    Diagnostico_Pa NVARCHAR(100),
    CONSTRAINT PK_Pacientes PRIMARY KEY (Dni_P_Pa),
    CONSTRAINT FK_Pacientes_Personas FOREIGN KEY (Dni_P_Pa) REFERENCES Personas(Dni_P)
);

CREATE TABLE Medicos (
  Dni_P_M NVARCHAR(8) NOT NULL,
  Legajo_M NVARCHAR(4) NOT NULL,
  IdEspecialidad_E_M INT NOT NULL,    
  HorarioAtencion_M NVARCHAR(20),-- "08:00-12:00", etc.
  Usuario_M NVARCHAR(30), --en la carga lo traigo como null
  Contrasena_M NVARCHAR(50),--en la carga lo traigo como null
  UsuarioHabilitado_M BIT, --en la carga lo traigo como null
  CONSTRAINT PK_Medicos PRIMARY KEY (Dni_P_M),
  CONSTRAINT UQ_Medicos_Legajo UNIQUE (Legajo_M),
  CONSTRAINT FK_Medicos_Personas FOREIGN KEY (Dni_P_M) REFERENCES Personas(Dni_P),
  CONSTRAINT FK_Medicos_Especialidades FOREIGN KEY (IdEspecialidad_E_M) REFERENCES Especialidades(IdEspecialidad_E)
);

CREATE TABLE Administradores (
    Dni_P_A NVARCHAR(8) NOT NULL,
    Usuario_A NVARCHAR(30),
    Contrasena_A NVARCHAR(50),
    UsuarioHabilitado_A BIT,
    CONSTRAINT PK_Administradores PRIMARY KEY (Dni_P_A),
    CONSTRAINT FK_Administradores_Personas FOREIGN KEY (Dni_P_A)
    REFERENCES Personas(Dni_P)
);

PRINT 'Creando tablas auxiliares (Muchos a Muchos)...';

CREATE TABLE MEDICOSxDIAS ( --tabla aux
  Dni_P_M_MxD NVARCHAR(8) NOT NULL, -- FK Medicos
  IdDia_D_MxD INT NOT NULL,         -- FK DiasSemana  
  CONSTRAINT PK_Medico_x_Dia PRIMARY KEY (Dni_P_M_MxD, IdDia_D_MxD),--pk concatenada
  CONSTRAINT FK_MedicoDia_Medico FOREIGN KEY (Dni_P_M_MxD) REFERENCES Medicos(Dni_P_M),
  CONSTRAINT FK_MedicoDia_Dia FOREIGN KEY (IdDia_D_MxD) REFERENCES DiasSemana(IdDia_D)
);

PRINT 'Creando tabla de movimiento(Transacciones)...';
CREATE TABLE Turnos (
    IdTurno_T INT IDENTITY(1,1) NOT NULL,
    Fecha_T DATE NOT NULL,
    Hora_T TIME(0) NOT NULL,
    IdEspecialidad_E_T INT NOT NULL,
    Dni_P_M_T NVARCHAR(8) NOT NULL,
    Dni_P_Pa_T NVARCHAR(8) NOT NULL,
    Observacion_T NVARCHAR(200),
    Atendido_T BIT NULL,
    CONSTRAINT PK_Turnos PRIMARY KEY (IdTurno_T),
    CONSTRAINT FK_Turnos_Especialidades FOREIGN KEY (IdEspecialidad_E_T) REFERENCES Especialidades(IdEspecialidad_E),
    CONSTRAINT FK_Turnos_Medicos FOREIGN KEY (Dni_P_M_T) REFERENCES Medicos(Dni_P_M),
    CONSTRAINT FK_Turnos_Pacientes FOREIGN KEY (Dni_P_Pa_T) REFERENCES Pacientes(Dni_P_Pa)
);
GO

------CARGA DE DATOS (INSERTS)------
PRINT 'Insertando datos maestros...';
INSERT INTO Provincias (Nombre_Pr, Estado_Pr) VALUES
('Buenos Aires', 1), ('Córdoba', 1), ('Santa Fe', 1), ('Mendoza', 1), ('San Luis', 1), ('Neuquén', 1), ('Río Negro', 1),
('Chubut', 1), ('Entre Ríos', 1), ('Formosa', 1), ('Jujuy', 1), ('La Pampa', 1),
('La Rioja', 1), ('Misiones', 1), ('Salta', 1), ('San Juan', 1), ('Santa Cruz', 1),
('Santiago del Estero', 1), ('Tucumán', 1), ('Catamarca', 1), ('Corrientes', 1), ('Chaco', 1);

INSERT INTO Localidades (Nombre_L, IdProvincia_Pr_L, Estado_L) VALUES
('Lanús', 1, 1), ('Banfield', 1, 1), ('Tigre', 1, 1),-- 3 de Buenos Aires
('Villa Carlos Paz', 2, 1), ('Córdoba Capital', 2, 1), ('Río Cuarto', 2, 1),-- 3 de Córdoba
('Rosario', 3, 1), ('Santa Fe Capital', 3, 1), ('Rafaela', 3, 1),-- 3 de Santa Fe
('Godoy Cruz', 4, 1), ('Mendoza Capital', 4, 1),-- 2 de Mendoza
('La Punta', 5, 1),-- 1 de San Luis
('Cutral Có', 6, 1), ('Neuquén Capital', 6, 1),-- 2 de Neuquén
('General Roca', 7, 1),-- 1 de Río Negro
('Trelew', 8, 1), ('Rawson', 8, 1), ('Gualeguaychú', 9, 1),
('Paraná', 9, 1), ('Formosa Capital', 10, 1), ('Palpalá', 11, 1),
('General Pico', 12, 1), ('La Rioja Capital', 13, 1), ('Posadas', 14, 1),
('Oberá', 14, 1), ('Salta Capital', 15, 1), ('Rivadavia', 16, 1),
('Río Gallegos', 17, 1), ('Termas de Río Hondo', 18, 1), ('Tafí Viejo', 19, 1);

INSERT INTO Especialidades (Descripcion_E, Estado_E) VALUES
('Clínica Médica', 1), ('Cardiología', 1), ('Pediatría', 1), ('Dermatología', 1), ('Gastroenterología', 1), 
('Traumatología', 1), ('Neurología', 1), ('Endocrinología', 1), ('Reumatología', 1),
('Oftalmología', 1), ('Otorrinolaringología', 1), ('Urología', 1), ('Oncología', 1), 
('Psiquiatría', 1), ('Infectología', 1),
('Alergología', 1), ('Hematología', 1), ('Nefrología', 1),
('Cirugía General', 1), ('Geriatría', 1), ('Medicina del Deporte', 1),
('Neonatología', 1), ('Fonoaudiología', 1), ('Nutrición', 1),
('Rehabilitación', 1), ('Medicina Interna', 1), ('Diabetología', 1),
('Inmunología', 1), ('Anestesiología', 1), ('Cirugía Pediátrica', 1);

INSERT INTO DiasSemana (IdDia_D, NombreDia_D) VALUES
(1, 'Lunes'), (2, 'Martes'), (3, 'Miércoles'), (4, 'Jueves'), (5, 'Viernes'), (6, 'Sábado');

PRINT 'Insertando Personas, Pacientes, Médicos y Admins...';
-- 5 personas para ADMINISTRADORES (DNI 1xxxx)
INSERT INTO Personas (Dni_P, IdLocalidad_L_P, Nombre_P, Apellido_P, Sexo_P, Nacionalidad_P, FechaNacimiento_P, Direccion_P, CorreoElectronico_P, Telefono_P, Estado_P) VALUES
('10000001', 1, 'Miguel', 'Perez', 'M', 'Argentina', '1990-01-01', 'Av. Siempre Viva 742', 'miguel.perez@clinica.com', '1110001', 1),
('10000002', 2, 'Ana', 'Garcia', 'F', 'Argentina', '1990-01-02', 'Calle Falsa 123', 'ana.garcia@clinica.com', '1110002', 1),
('10000003', 3, 'Luis', 'Fernandez', 'M', 'Argentina', '1990-01-03', 'Rivadavia 5000', 'luis.fernandez@clinica.com', '1110003', 1),
('10000004', 4, 'Elena', 'Diaz', 'F', 'Argentina', '1990-01-04', 'Corrientes 3000', 'elena.diaz@clinica.com', '1110004', 1),
('10000005', 5, 'David', 'Ruiz', 'M', 'Argentina', '1990-01-05', 'Belgrano 1500', 'david.ruiz@clinica.com', '1110005', 1),
('10000006', 1, 'Sofia', 'Mendez', 'F', 'Argentina', '1991-05-01', 'Av. 9 de Julio 100', 'sof.mendez@clinica.com', '1160001', 1),
('10000007', 2, 'Javier', 'Nuñez', 'M', 'Argentina', '1989-02-11', 'Calle 22 130', 'jav.nunez@clinica.com', '1160002', 1),
('10000008', 3, 'Rocio', 'Bustos', 'F', 'Argentina', '1992-07-15', 'Mitre 300', 'rocio.bustos@clinica.com', '1160003', 1),
('10000009', 4, 'Bruno', 'Prieto', 'M', 'Argentina', '1987-10-09', 'Castelli 220', 'bruno.prieto@clinica.com', '1160004', 1),
('10000010', 5, 'Daniela', 'Luna', 'F', 'Argentina', '1985-06-21', 'Yrigoyen 800', 'dan.luna@clinica.com', '1160005', 1),
('10000011', 6, 'Noelia', 'Silva', 'F', 'Argentina', '1993-03-04', 'Sarmiento 350', 'noe.silva@clinica.com', '1160006', 1),
('10000012', 7, 'Lucas', 'Acosta', 'M', 'Argentina', '1986-08-12', 'Dorrego 900', 'luc.acosta@clinica.com', '1160007', 1),
('10000013', 8, 'Patricio', 'Rios', 'M', 'Argentina', '1991-04-27', 'Alberdi 110', 'pat.rios@clinica.com', '1160008', 1),
('10000014', 9, 'Clara', 'Funes', 'F', 'Argentina', '1988-09-19', 'Lavalle 505', 'clara.funes@clinica.com', '1160009', 1),
('10000015', 10, 'Martina', 'Soria', 'F', 'Argentina', '1990-03-09', 'Balcarce 720', 'mart.soria@clinica.com', '1160010', 1),
('10000016', 11, 'Enzo', 'Quiroga', 'M', 'Argentina', '1984-11-12', 'San Juan 450', 'enzo.quiroga@clinica.com', '1160011', 1),
('10000017', 12, 'Paula', 'Marquez', 'F', 'Argentina', '1996-01-29', 'Hipólito 1200', 'paula.marquez@clinica.com', '1160012', 1),
('10000018', 13, 'Federico', 'Rossi', 'M', 'Argentina', '1982-12-02', 'Alsina 620', 'fed.rossi@clinica.com', '1160013', 1),
('10000019', 14, 'Valeria', 'Ortiz', 'F', 'Argentina', '1994-06-18', 'Güemes 215', 'vale.ortiz@clinica.com', '1160014', 1),
('10000020', 15, 'Marcos', 'Germain', 'M', 'Argentina', '1985-05-14', 'Belgrano 890', 'marcos.germain@clinica.com', '1160015', 1);



--5 personas para MEDICOS (DNI 2xxxx)
INSERT INTO Personas (Dni_P, IdLocalidad_L_P, Nombre_P, Apellido_P, Sexo_P, Nacionalidad_P, FechaNacimiento_P, Direccion_P, CorreoElectronico_P, Telefono_P, Estado_P) VALUES
('20000001', 1, 'Laura', 'Gonzalez', 'F', 'Argentina', '1990-04-15', 'Calle 1 123', 'laura@gmail.com', '1111111111', 1),
('20000002', 2, 'Pedro', 'Martinez', 'M', 'Argentina', '1985-03-12', 'Calle 2 456', 'pedro@gmail.com', '2222222222', 1),
('20000003', 3, 'Mariana', 'Sosa', 'F', 'Argentina', '1992-08-22', 'Calle 3 789', 'mariana@gmail.com', '3333333333', 1),
('20000004', 4, 'Jorge', 'Lopez', 'M', 'Argentina', '1980-02-10', 'Calle 4 321', 'jorge@gmail.com', '4444444444', 1),
('20000005', 5, 'Ana', 'Rojas', 'F', 'Argentina', '1997-07-19', 'Calle 5 654', 'ana@gmail.com', '5555555555', 1),
('20000006', 1, 'Hernan','Molina','M','Argentina','1980-04-12','Alsina 300','hmolina@med.com','119001',1),
('20000007', 2, 'Agustina','Benitez','F','Argentina','1991-12-22','Soler 140','abenitez@med.com','119002',1),
('20000008', 3, 'Santiago','Lopez','M','Argentina','1983-06-15','Don Bosco 900','slopez@med.com','119003',1),
('20000009', 4, 'Romina','Castro','F','Argentina','1987-01-17','Peru 600','rcastro@med.com','119004',1),
('20000010', 5, 'Gisel','Ortigoza','F','Argentina','1990-05-11','Constitución 700','gortigoza@med.com','119005',1),
('20000011', 6,'Fernando','Vera','M','Argentina','1982-08-09','Mitre 1001','fvera@med.com','119006',1),
('20000012', 7,'Martina','Quiroz','F','Argentina','1985-02-02','Saavedra 550','mquiroz@med.com','119007',1),
('20000013', 8,'Pablo','Almada','M','Argentina','1989-10-10','Córdoba 100','palmada@med.com','119008',1),
('20000014', 9,'Micaela','Roldan','F','Argentina','1993-03-28','Mendoza 800','mroldan@med.com','119009',1),
('20000015', 10,'Oscar','Ibarra','M','Argentina','1981-09-19','Junín 1120','oibarra@med.com','119010',1),
('20000016', 11,'Julieta','Cano','F','Argentina','1994-07-07','Belgrano 300','jcano@med.com','119011',1),
('20000017', 12,'Rodrigo','Rossi','M','Argentina','1986-11-11','Italia 550','rrossi@med.com','119012',1),
('20000018', 13,'Tamara','Schiavone','F','Argentina','1990-09-01','Laplace 330','tschiavone@med.com','119013',1),
('20000019', 14,'Leonel','Muñoz','M','Argentina','1984-04-16','Rondeau 288','lmunoz@med.com','119014',1),
('20000020', 15,'Sabrina','Paz','F','Argentina','1995-06-11','San Luis 790','spaz@med.com','119015',1);

--5 personas para PACIENTES (DNI 3xxxx)
INSERT INTO Personas (Dni_P, IdLocalidad_L_P, Nombre_P, Apellido_P, Sexo_P, Nacionalidad_P, FechaNacimiento_P, Direccion_P, CorreoElectronico_P, Telefono_P, Estado_P) VALUES
('30000001', 1, 'Carlos', 'Aguirre', 'M', 'Argentina', '1988-01-10', 'Av. Mitre 4500', 'carlos.aguirre@email.com', '1122334455', 1),
('30000002', 2, 'Maria', 'Soto', 'F', 'Uruguaya', '1995-07-20', 'Belgrano 321', 'maria.soto@email.com', '1133445566', 1),
('30000003', 3, 'Lucia', 'Gomez', 'F', 'Argentina', '2001-11-05', 'San Martin 100', 'lucia.gomez@email.com', '1144556677', 1),
('30000004', 4, 'David', 'Ruiz', 'M', 'Argentino', '1975-02-18', 'Sarmiento 750', 'david.ruiz@email.com', '1155667788', 1),
('30000005', 5, 'Elena', 'Torres', 'F', 'Argentina', '1983-09-30', 'Rivadavia 1234', 'elena.torres@email.com', '1166778899', 1),
('30000006', 6, 'Roberto', 'Vega', 'M', 'Argentina', '1992-03-15', 'Moreno 450', 'roberto.vega@email.com', '1177889900', 1),
('30000007', 7, 'Sandra', 'Molina', 'F', 'Argentina', '1986-06-22', 'Urquiza 890', 'sandra.molina@email.com', '1188990011', 1),
('30000008', 8, 'Raul', 'Benitez', 'M', 'Argentina', '1979-09-10', 'Alem 234', 'raul.benitez@email.com', '1199001122', 1),
('30000009', 9, 'Patricia', 'Castro', 'F', 'Argentina', '1990-12-05', 'Tucumán 567', 'patricia.castro@email.com', '1100112233', 1),
('30000010', 10, 'Gustavo', 'Rios', 'M', 'Argentina', '1984-04-18', 'Suipacha 321', 'gustavo.rios@email.com', '1111223344', 1),
('30000011', 11, 'Monica', 'Silva', 'F', 'Argentina', '1993-07-30', 'Corrientes 678', 'monica.silva@email.com', '1122334455', 1),
('30000012', 12, 'Hector', 'Pereyra', 'M', 'Argentina', '1981-11-14', 'Santa Fe 901', 'hector.pereyra@email.com', '1133445566', 1),
('30000013', 13, 'Claudia', 'Rojas', 'F', 'Argentina', '1996-02-28', 'Córdoba 1234', 'claudia.rojas@email.com', '1144556677', 1),
('30000014', 14, 'Alberto', 'Paz', 'M', 'Argentina', '1978-08-07', 'Entre Ríos 456', 'alberto.paz@email.com', '1155667788', 1),
('30000015', 15, 'Gabriela', 'Luna', 'F', 'Argentina', '1991-05-19', 'Jujuy 789', 'gabriela.luna@email.com', '1166778899', 1),
('30000016', 16, 'Fernando', 'Acosta', 'M', 'Argentina', '1985-10-23', 'Salta 1011', 'fernando.acosta@email.com', '1177880011', 1),
('30000017', 17, 'Silvia', 'Quiroga', 'F', 'Argentina', '1989-01-16', 'Mendoza 1213', 'silvia.quiroga@email.com', '1188991122', 1),
('30000018', 18, 'Diego', 'Farias', 'M', 'Argentina', '1982-06-11', 'San Juan 1415', 'diego.farias@email.com', '1199002233', 1),
('30000019', 19, 'Veronica', 'Ortiz', 'F', 'Argentina', '1994-09-25', 'La Rioja 1617', 'veronica.ortiz@email.com', '1100113344', 1),
('30000020', 20, 'Marcelo', 'Romero', 'M', 'Argentina', '1987-12-03', 'Formosa 1819', 'marcelo.romero@email.com', '1111224455', 1);



--5 Administradores (DNI 1xxxx)
INSERT INTO Administradores (Dni_P_A, Usuario_A, Contrasena_A, UsuarioHabilitado_A) VALUES
('10000001', 'admin1', '1', 1), 
('10000002', 'admin2', 'adminpass2', 1), 
('10000003', 'admin3', 'adminpass3', 1), 
('10000004', 'admin4', 'adminpass4', 1), 
('10000005', 'admin5', 'adminpass5', 1),
('10000006','admin6','pass6',1),
('10000007','admin7','pass7',1),
('10000008','admin8','pass8',1),
('10000009','admin9','pass9',1),
('10000010','admin10','pass10',1),
('10000011','admin11','pass11',1),
('10000012','admin12','pass12',1),
('10000013','admin13','pass13',1),
('10000014','admin14','pass14',1),
('10000015','admin15','pass15',1),
('10000016','admin16','pass16',1),
('10000017','admin17','pass17',1),
('10000018','admin18','pass18',1),
('10000019','admin19','pass19',1);

--5 Médicos (DNI 2xxxx)
INSERT INTO Medicos 
(Dni_P_M, Legajo_M, IdEspecialidad_E_M, HorarioAtencion_M, Usuario_M, Contrasena_M, UsuarioHabilitado_M)
VALUES
('20000001', 'L001', 1, '08:00-12:00', 'med001', 'pass001', 1),
('20000002', 'L002', 2, '08:00-12:00', 'med002', 'pass002', 1),
('20000003', 'L003', 3, '12:00-16:00', 'med003', 'pass003', 1),
('20000004', 'L004', 4, '12:00-16:00', 'med004', 'pass004', 1),
('20000005', 'L005', 5, '16:00-20:00', 'med005', 'pass005', 1),
('20000006','L006', 6, '08:00-12:00', 'med006','pass006', 1),
('20000007','L007', 7, '12:00-16:00', 'med007','pass007', 1),
('20000008','L008', 8, '16:00-20:00', 'med008','pass008', 1),
('20000009','L009', 9, '08:00-12:00', 'med009','pass009', 1),
('20000010','L010', 10,'12:00-16:00','med010','pass010', 1),
('20000011','L011', 11,'08:00-12:00','med011','pass011', 1),
('20000012','L012', 12,'16:00-20:00','med012','pass012', 1),
('20000013','L013', 13,'08:00-12:00','med013','pass013', 1),
('20000014','L014', 14,'12:00-16:00','med014','pass014', 1),
('20000015','L015', 15,'16:00-20:00','med015', 'pass015', 1),
('20000016','L016', 1,'08:00-12:00','med016','pass016', 1),
('20000017','L017', 2,'12:00-16:00','med017','pass017', 1),
('20000018','L018', 3,'16:00-20:00','med018','pass018', 1),
('20000019','L019', 4,'08:00-12:00','med019','pass019', 1),
('20000020','L020', 5,'12:00-16:00','med020','pass020', 1);


INSERT INTO Pacientes (Dni_P_Pa, Diagnostico_Pa) VALUES
('30000001', 'Hipertensión leve'), ('30000002', 'Alergia estacional'), ('30000003', 'Dolor lumbar crónico'),
('30000004', 'Cefalea recurrente'), ('30000005', 'Asma leve'),
('30000006','Colesterol elevado'),('30000007','Rinitis alérgica'),('30000008','Lumbalgia aguda'),
('30000009','Hipotiroidismo'),('30000010','Insuficiencia venosa'),('30000011','Contractura cervical'),
('30000012','Artritis leve'),('30000013','Afección respiratoria'),('30000014','Migraña crónica'),
('30000015','Ansiedad leve'),('30000016','Dermatitis'),('30000017','Gastritis recurrente'),
('30000018','Tendinitis'),('30000019','Anemia leve'),('30000020','Dolor articular difuso');

-- Días para 5 Médicos (DNI 2xxxx)
INSERT INTO MEDICOSxDIAS(Dni_P_M_MxD, IdDia_D_MxD) VALUES
('20000001', 1), ('20000001', 3), -- Lunes y Miércoles
('20000002', 2), ('20000002', 4), -- Martes y Jueves
('20000003', 1), ('20000003', 2), ('20000003', 3), -- Lunes, Martes, Miércoles
('20000004', 4), ('20000004', 5), -- Jueves y Viernes
('20000005', 1), ('20000005', 5), -- Lunes y Viernes
('20000006',1),('20000006',4),
('20000007',2),('20000007',5),
('20000008',3),('20000008',6),
('20000009',1),('20000009',5),
('20000010',4),('20000010',6),
('20000011',2),('20000011',3),
('20000012',1),('20000012',6),
('20000013',2),('20000013',4),
('20000014',3),('20000014',5),
('20000015',1),('20000015',2),
('20000016',4),('20000016',5),
('20000017',6),('20000017',3),
('20000018',2),('20000018',4),
('20000019',1),('20000019',6),
('20000020',3),('20000020',5);


PRINT 'Insertando Turnos...';
-- 5 Turnos (usando 5 Médicos y 5 Pacientes)
INSERT INTO Turnos (Fecha_T, Hora_T, IdEspecialidad_E_T, Dni_P_M_T, Dni_P_Pa_T, Observacion_T, Atendido_T) VALUES
('2025-11-01', '09:00', 1, '20000001', '30000001', 'Consulta general', NULL), -- Pendiente
('2025-11-02', '10:00', 2, '20000002', '30000002', 'Electrocardiograma', 1), -- Presente
('2025-11-03', '11:00', 3, '20000003', '30000003', 'Dolor lumbar', NULL), -- Pendiente
('2025-11-04', '12:00', 4, '20000004', '30000004', 'Migraña', 0), -- Ausente
('2025-11-05', '13:00', 5, '20000005', '30000005', 'Gastritis', NULL), -- Pendiente
('2025-10-20','09:00',6,'20000006','30000006','Control traumatología',NULL),
('2025-10-22','10:00',7,'20000007','30000007','Chequeo neurológico',1),
('2025-11-15','11:00',8,'20000008','30000008','Estudio endocrino',0),
('2025-12-01','12:00',9,'20000009','30000009','Dolor articular',1),
('2025-12-10','13:00',10,'20000010','30000010','Evaluación visual',NULL),
('2025-12-14','09:00',11,'20000011','30000011','Evaluación foniátrica',NULL),
('2025-12-16','10:00',12,'20000012','30000012','Control diabetológico',1),
('2025-12-18','11:00',13,'20000013','30000013','Consulta inmunológica',NULL),
('2025-12-20','12:00',14,'20000014','30000014','Seguimiento psiquiátrico',0),
('2025-12-22','13:00',15,'20000015','30000015','Alergias',1),
('2026-01-03','09:00',1,'20000016','30000016','Consulta clínica',NULL),
('2026-01-05','10:00',2,'20000017','30000017','Chequeo cardiológico',1),
('2026-01-07','11:00',3,'20000018','30000018','Dolor lumbar',NULL),
('2026-01-09','12:00',4,'20000019','30000019','Control dermatológico',1),
('2026-01-12','13:00',5,'20000020','30000020','Consulta gastro',0);
PRINT '¡Base de datos creada y cargada exitosamente!';


-- Verificamos los datos
SELECT * FROM Provincias;
SELECT * FROM Localidades;
SELECT * FROM Especialidades;
SELECT * FROM DiasSemana;

SELECT * FROM Personas;
SELECT * FROM Administradores;
SELECT * FROM Medicos;
SELECT * FROM Pacientes;

SELECT * FROM MEDICOSxDIAS;
SELECT * FROM Turnos;
GO

---sp listar prov
USE Clinica
GO

CREATE PROCEDURE [dbo].[sp_ListarProvincias]
AS
BEGIN
	SET NOCOUNT ON; --asi desactivo los msj de error y no se "Stope"
	SELECT
		IdProvincia_Pr AS IdProvincia,
		Nombre_Pr AS NombreProvincia
	FROM
		Provincias
	WHERE
		Estado_Pr = 1 --activas
	ORDER BY
		Nombre_Pr ASC
END 
GO


---sp listar localidades por provincia

USE Clinica
GO

CREATE PROCEDURE [dbo].[sp_ListarLocalidadesPorProvincia]
	@IdProvincia INT
AS
BEGIN
	SET NOCOUNT ON; 
	SELECT
		IdLocalidad_L AS IdLocalidad,
        Nombre_L AS NombreLocalidad
	FROM
		Localidades
	WHERE
		Estado_L = 1 
		AND IdProvincia_Pr_L = @IdProvincia
	ORDER BY
		Nombre_L ASC
END 
GO


---sp listar especialidades
USE Clinica
GO

CREATE PROCEDURE [dbo].[sp_ListarEspecialidades]
AS
BEGIN
	SET NOCOUNT ON; --asi desactivo los msj de error y no se "Stope"
	SELECT
		IdEspecialidad_E AS IdEspecialidad,
		Descripcion_E AS DescripcionEspecialidad
	FROM
		Especialidades
	WHERE
		Estado_E = 1 --activas
	ORDER BY
		Descripcion_E ASC
END 
GO

---sp listar dias de la semana
USE Clinica 
GO
CREATE PROCEDURE [dbo].[sp_ListarDiasSemana]
AS
BEGIN
    SET NOCOUNT ON;
    SELECT
        IdDia_D AS IdDia ,       -- El 'Value' (ej: 1)
        NombreDia_D AS NombreDia -- El 'Text' (ej: "Lunes")
    FROM 
        DiasSemana
    ORDER BY
        IdDia ASC --ordena 1, 2, 3... (Lunes, Martes, Miér)
END
GO

---SP AGREGAR MEDICO MIGUE
USE Clinica
GO
------CREAR EL TIPO DE DATO (para la lista de días) Esto permite a C# enviar una 'Tabla' como parámetro------
------Lo veo en -> Programmability -> types -> (User-Defined Table Types)
PRINT 'Creando el tipo de tabla dbo.TipoTablaDia...';
CREATE TYPE dbo.TipoTablaDia AS TABLE -- mi SP AGREGAR MEDICO necesita si o si el TYPE este.
(
  IdDia INT NOT NULL
);
GO

-----CREAR EL STORED PROCEDURE Agregar Medico-----
PRINT 'Creando el Stored Procedure sp_AgregarMedico...';
USE Clinica
GO

CREATE PROCEDURE [dbo].[sp_AgregarMedico]
  -- Parámetros de Persona
  @Dni_P NVARCHAR(8),
  @IdLocalidad_L_P INT,
  @Nombre_P NVARCHAR(50),
  @Apellido_P NVARCHAR(50),
  @Sexo_P CHAR(1),
  @Nacionalidad_P NVARCHAR(50),
  @FechaNacimiento_P DATE,
  @Direccion_P NVARCHAR(100),
  @CorreoElectronico_P NVARCHAR(100),
  @Telefono_P NVARCHAR(50),
	@Estado_P BIT,
    
  -- Parámetros de Medico -> Usuario_M NVARCHAR(30) + Contrasena_M NVARCHAR(50) + UsuarioHabilitado_M BIT lo carga como NULL
  @Legajo_M NVARCHAR(4),
  @IdEspecialidad_E_M INT,
  @HorarioAtencion_M NVARCHAR(20),

	-- Parámetro de Medico_x_Dia (la "mini-tabla")
  @Dias dbo.TipoTablaDia READONLY --'READONLY' es obligatorio para este tipo de parámetro
AS
BEGIN
  SET NOCOUNT ON;

  BEGIN TRANSACTION;--"la promesa" => "voy a intentar las operaciones, dejalas en borrador... no las guardes aún"    
  BEGIN TRY--INTENTO   
		INSERT INTO Personas (Dni_P, IdLocalidad_L_P, Nombre_P, Apellido_P, Sexo_P, Nacionalidad_P, FechaNacimiento_P, Direccion_P, CorreoElectronico_P, Telefono_P, Estado_P) --1. Insertamos en la tabla 'Padre' (Personas)
		VALUES (@Dni_P, @IdLocalidad_L_P, @Nombre_P, @Apellido_P, @Sexo_P, @Nacionalidad_P, @FechaNacimiento_P, @Direccion_P,	@CorreoElectronico_P, @Telefono_P, @Estado_P);

    INSERT INTO Medicos (Dni_P_M, Legajo_M, IdEspecialidad_E_M, HorarioAtencion_M)--2. Insertamos en la tabla 'Hija' (Medicos)
    VALUES (@Dni_P, @Legajo_M, @IdEspecialidad_E_M, @HorarioAtencion_M);
    
		INSERT INTO MEDICOSxDIAS(Dni_P_M_MxD, IdDia_D_MxD) -- 3. Insertamos en la tabla 'Auxiliar' (Medico_x_Dia) -> Tomamos los datos de la "mini-tabla" (@Dias) que viene del C# List
    SELECT @Dni_P, IdDia FROM @Dias; --@Dias es la "mini-tabla" temporal que trae 1, 3 y 5 => el SELECT recorre las 3 filas y me hace 3 INSERT => DNI 123 y los 3 IdDia diferentes

    COMMIT TRANSACTION;--camino feliz se ejecuta todo    
    RETURN 1; -- (Devolvemos 1 para 'filasAfectadas', aunque fueron más)
   END TRY
   
	 BEGIN CATCH --si algo no se puede agregar entra aca
		ROLLBACK TRANSACTION;--(revertir) se Cancela la promesa ->se Tira el 'borrador' a la basura".    
    RETURN 0;--retorno cero si salio mal
   END CATCH
END
GO

---SP Listar Buscar Todo Medicos
 USE Clinica
GO

CREATE PROCEDURE [dbo].[sp_ListarBuscarTodoMedicos]
    @NombreApellido NVARCHAR(100) = NULL, --inicializo en null y cero para que si no busca por esos parametros traiga solo lo que busca
    @Legajo NVARCHAR(10) = NULL,
    @IdEspecialidad INT = 0,
    @TablaDias dbo.TipoTablaDia READONLY -- <-- Usamos el Tipo Tabla que genere en SP_AGREGARMEDICO
AS
BEGIN
  SET NOCOUNT ON;
	DECLARE @CONST_NUM_DIAS INT = (SELECT COUNT(*) FROM @TablaDias); -- Si la tabla @DTablaDias está vacía, este valor será 0.
  --NumDiasFiltro
	WITH cteMedicoDias AS ( -- 1. CTE (Common Table Expression) para agrupar los días => MedicoDias es mi CTE => es una tabla temporal que tiene DNI del medico y dias concatenados como "Lunes, Miércoles, Viernes"
		SELECT 
			mxd.Dni_P_M_MxD, 
			STRING_AGG(ds.NombreDia_D, ', ') WITHIN GROUP (ORDER BY ds.IdDia_D) AS cteDiasConcatenados
		 FROM 
			 MEDICOSxDIAS mxd 
		 JOIN -- es igual que inner join pero para variar pongo esto
			 DiasSemana ds ON mxd.IdDia_D_MxD = ds.IdDia_D 
			GROUP BY 
			 mxd.Dni_P_M_MxD 
    )
    
    --Consulta principal
  SELECT 
    p.Dni_P,  -- Lo dejamos para usar en 'Detalle' o 'Editar'
    m.Legajo_M AS Legajo, -- Alias para GridView
    p.Nombre_P AS Nombre, -- Alias para GridView
    p.Apellido_P AS Apellido, -- Alias para GridView
    e.Descripcion_E AS Especialidad, -- Alias para GridView
    ISNULL(cteMD.cteDiasConcatenados, 'N/A') AS Dias, --esto no va a pasar por el JS del aspx.cs del fromAgregar... pero por las dudas.... muestra N/A si no hay dias
    m.HorarioAtencion_M AS Horas, -- Alias para GridView

		-- Columnas "invisibles" que usa la lógica de RowDataBound
    m.Usuario_M,  -- Alias para GridView
    m.UsuarioHabilitado_M -- Alias para GridView
    FROM 
      Personas p
    INNER JOIN 
      Medicos m ON p.Dni_P = m.Dni_P_M 
    LEFT JOIN 
      Especialidades e ON m.IdEspecialidad_E_M = e.IdEspecialidad_E --uso LEFT JOIN para que estrictamente traiga TODOS LOS MEDICOS (INNER) pero si no tienen Especialidad asignaada lo muestre pero con null
		LEFT JOIN 
      cteMedicoDias cteMD ON p.Dni_P = cteMD.Dni_P_M_MxD 

    WHERE
			p.Estado_P = 1
    -- Filtros de Búsqueda txtBox
      AND (@Legajo IS NULL OR m.Legajo_M LIKE @Legajo) 
      AND (@NombreApellido IS NULL OR (p.Nombre_P + ' ' + p.Apellido_P) COLLATE Latin1_General_CI_AI LIKE '%' + @NombreApellido + '%' COLLATE Latin1_General_CI_AI)
    
		-- Filtro de DropDown
      AND (@IdEspecialidad = 0 OR m.IdEspecialidad_E_M = @IdEspecialidad)
   
	 -- Filtro de Días con SUBCONSULTA => asegura que el medico trabaje TODOS los dias de la tabla @TablaDias
      AND (
				@CONST_NUM_DIAS = 0 
				OR -- Si @NumDiasFiltro es 0, no se aplica el filtro
			  (	
					SELECT COUNT(DISTINCT mxd.IdDia_D_MxD)
					FROM MEDICOSxDIAS mxd
					-- Unimos la tabla de médicos CON la tabla de filtros
					JOIN @TablaDias tabDias  ON mxd.IdDia_D_MxD = tabDias.IdDia
					WHERE mxd.Dni_P_M_MxD = p.Dni_P
				) 
				= @CONST_NUM_DIAS -- El total de días coincidentes debe ser igual al total de días del filtro
			)
      ORDER BY -- sin esto ordena bien pero por dni y en el listar se ve mal
        m.Legajo_M ASC
END
GO

--prueba de la CTE
USE Clinica
GO

SELECT 
    MEDICOSxDIAS.Dni_P_M_MxD,     
    STRING_AGG(DiasSemana.NombreDia_D, ', ') WITHIN GROUP (ORDER BY DiasSemana.IdDia_D) AS DiasConcatenados --ates del add lo ordeno por IdDia_D asi siempre esta 1, 2, 3, etc
FROM 
    MEDICOSxDIAS
JOIN 
	DiasSemana 
ON MEDICOSxDIAS.IdDia_D_MxD = DiasSemana.IdDia_D 
GROUP BY 
    MEDICOSxDIAS.Dni_P_M_MxD  -- Agrupar todos los días por el DNI del medico

USE Clinica
GO






CREATE PROCEDURE sp_BuscarPacientes
    @NombreApellido NVARCHAR(50) = NULL,
    @Dni NVARCHAR(8) = NULL
AS
BEGIN
    SET NOCOUNT ON;

    SELECT
        -- Alias para BoundFields y C#
        P.Dni_P AS DNI,
        P.Nombre_P AS Nombre,
        P.Apellido_P AS Apellido,
        P.FechaNacimiento_P AS FechaNacimiento,
        P.Telefono_P AS Telefono,
        P.CorreoElectronico_P AS CorreoElectronico,
        P.Direccion_P AS Direccion,
        P.Nacionalidad_P AS Nacionalidad,
        P.Sexo_P AS Sexo,
        P.IdLocalidad_L_P AS IdLocalidad,
        PA.Diagnostico_Pa AS Diagnostico,
        P.Estado_P AS Estado,

        -- Campos de los JOIN (para la mejora de C#)
        PR.IdProvincia_Pr AS IdProvincia,
        L.Nombre_L AS NombreLocalidad,
        PR.Nombre_Pr AS NombreProvincia

    FROM 
        Pacientes PA
    INNER JOIN 
        Personas P ON P.Dni_P = PA.Dni_P_Pa
    INNER JOIN 
        Localidades L ON P.IdLocalidad_L_P = L.IdLocalidad_L
    INNER JOIN 
        Provincias PR ON L.IdProvincia_Pr_L = PR.IdProvincia_Pr
    WHERE 
        P.Estado_P = 1
        AND L.Estado_L = 1
        AND PR.Estado_Pr = 1 -- Asumiendo que Provincias tiene estado
        AND (@Dni IS NULL OR P.Dni_P LIKE '%' + @Dni + '%')
        AND (@NombreApellido IS NULL OR (P.Nombre_P + ' ' + P.Apellido_P) COLLATE Latin1_General_CI_AI LIKE '%' + @NombreApellido + '%' COLLATE Latin1_General_CI_AI)
END
GO




 CREATE PROCEDURE sp_CrearUsuario
    @LEGAJO NVARCHAR(4),
    @NOMBREUSUARIO NVARCHAR(30),
    @CONTRASENIA NVARCHAR(50),
    @HABILITADO BIT
AS
BEGIN
    SET NOCOUNT ON;

    -- Verificar que el médico exista
    IF NOT EXISTS (SELECT 1 FROM Medicos WHERE Legajo_M = @LEGAJO)
    BEGIN
        RAISERROR('No se encontró ningún médico con el legajo especificado.', 16, 1);
        RETURN -1;
    END

    -- Verificar que no tenga usuario asignado
    IF EXISTS (SELECT 1 FROM Medicos WHERE Legajo_M = @LEGAJO AND Usuario_M IS NOT NULL)
    BEGIN
        RAISERROR('El médico ya tiene un usuario asignado.', 16, 1);
        RETURN -2;
    END

    -- Verificar que el usuario no exista en otro médico
    IF EXISTS (SELECT 1 FROM Medicos WHERE Usuario_M = @NOMBREUSUARIO)
    BEGIN
        RAISERROR('El nombre de usuario ya está en uso por otro médico.', 16, 1);
        RETURN -3;
    END

    -- Crear usuario
    UPDATE Medicos
    SET Usuario_M = @NOMBREUSUARIO,
        Contrasena_M = @CONTRASENIA,
        UsuarioHabilitado_M = @HABILITADO
    WHERE Legajo_M = @LEGAJO;

    RETURN @@ROWCOUNT;
END
GO

USE Clinica;
GO

CREATE PROCEDURE sp_ModificarUsuario
    @LEGAJO NVARCHAR(4),
    @NUEVOUSUARIO NVARCHAR(30)
AS
BEGIN
    SET NOCOUNT ON;

    -- Normalizar username
    SET @NUEVOUSUARIO = LTRIM(RTRIM(@NUEVOUSUARIO));

    -- Validar usuario vacío
    IF (@NUEVOUSUARIO = '' OR @NUEVOUSUARIO IS NULL)
    BEGIN
        RAISERROR('El nombre de usuario no puede estar vacío.', 16, 1);
        RETURN -4;
    END

    -- Verificar que el médico exista
    IF NOT EXISTS (SELECT 1 FROM Medicos WHERE Legajo_M = @LEGAJO)
    BEGIN
        RAISERROR('No se encontró ningún médico con el legajo especificado.', 16, 1);
        RETURN -1;
    END

    -- Verificar si tiene usuario asignado
    IF NOT EXISTS (SELECT 1 FROM Medicos WHERE Legajo_M = @LEGAJO AND Usuario_M IS NOT NULL)
    BEGIN
        RAISERROR('El médico no tiene un usuario asignado para modificar.', 16, 1);
        RETURN -2;
    END

    -- Verificar que el nuevo nombre de usuario no exista en ningún otro médico
    IF EXISTS (SELECT 1 
               FROM Medicos 
               WHERE Usuario_M = @NUEVOUSUARIO
                 AND Legajo_M <> @LEGAJO)
    BEGIN
        RAISERROR('El nombre de usuario ya está en uso por otro médico.', 16, 1);
        RETURN -3;
    END

    -- Actualizar usuario
    UPDATE Medicos
    SET Usuario_M = @NUEVOUSUARIO
    WHERE Legajo_M = @LEGAJO;

    RETURN @@ROWCOUNT;
END
GO

USE Clinica;
GO



CREATE PROCEDURE sp_ModificarContrasenia
    @LEGAJO NVARCHAR(4),
    @NUEVACONTRASENIA NVARCHAR(50)
AS
BEGIN
    SET NOCOUNT ON;

    -- Verificar que el médico exista
    IF NOT EXISTS (SELECT 1 FROM Medicos WHERE Legajo_M = @LEGAJO)
    BEGIN
        RAISERROR('No se encontró ningún médico con el legajo especificado.', 16, 1);
        RETURN -1;
    END

    -- Verificar que tenga usuario asignado
    IF NOT EXISTS (SELECT 1 FROM Medicos WHERE Legajo_M = @LEGAJO AND Usuario_M IS NOT NULL)
    BEGIN
        RAISERROR('El médico no tiene un usuario asignado para cambiar contraseña.', 16, 1);
        RETURN -2;
    END

    -- Actualizar contraseña
    UPDATE Medicos
    SET Contrasena_M = @NUEVACONTRASENIA
    WHERE Legajo_M = @LEGAJO;

    RETURN @@ROWCOUNT;
END
GO

CREATE PROCEDURE sp_EliminarMedico
    @Legajo NVARCHAR(10) -- Recibe el Legajo como parámetro
AS
BEGIN
    SET NOCOUNT ON;

    -- Esta es la Baja Lógica:
    -- Pone Estado_P = 0 en la tabla Personas...
    UPDATE Personas
    SET Estado_P = 0
    -- ...buscando al médico por su Legajo en la tabla Medicos
    WHERE Dni_P = (SELECT Dni_P_M FROM Medicos WHERE Legajo_M = @Legajo);
END
GO



CREATE PROCEDURE sp_EliminarPaciente
    @dni NVARCHAR(8)
AS
BEGIN
    SET NOCOUNT ON;
    
    UPDATE Personas
    SET Estado_P = 0
    WHERE Dni_P = @dni;
END
GO


---SP AgregarPaciente
USE Clinica
GO

CREATE PROCEDURE [dbo].[sp_AgregarPaciente]
    -- Parámetros de Persona
    @Dni_P NVARCHAR(8),
    @IdLocalidad_L_P INT,
    @Nombre_P NVARCHAR(50),
    @Apellido_P NVARCHAR(50),
    @Sexo_P CHAR(1),
    @Nacionalidad_P NVARCHAR(50),
    @FechaNacimiento_P DATE,
    @Direccion_P NVARCHAR(100),
    @CorreoElectronico_P NVARCHAR(100),
    @Telefono_P NVARCHAR(50),
    @Estado_P BIT,
    
    -- Parámetros de Paciente
    @Diagnostico_Pa NVARCHAR(100)
AS
BEGIN
    SET NOCOUNT ON;
    BEGIN TRANSACTION; 
    
    BEGIN TRY
        INSERT INTO Personas (
            Dni_P, IdLocalidad_L_P, Nombre_P, Apellido_P, Sexo_P, 
            Nacionalidad_P, FechaNacimiento_P, Direccion_P, 
            CorreoElectronico_P, Telefono_P, Estado_P
        )
        VALUES (
            @Dni_P, @IdLocalidad_L_P, @Nombre_P, @Apellido_P, @Sexo_P,
            @Nacionalidad_P, @FechaNacimiento_P, @Direccion_P, 
            @CorreoElectronico_P, @Telefono_P, @Estado_P
        );
        INSERT INTO Pacientes (
            Dni_P_Pa, Diagnostico_Pa
        )
        VALUES (
            @Dni_P, @Diagnostico_Pa 
        );
        COMMIT TRANSACTION;
        RETURN 1; 
        
    END TRY
    BEGIN CATCH

        ROLLBACK TRANSACTION;
        RETURN 0;
    END CATCH
END
GO

---Obtener Datos Medico x legajo (devuelve una sola fila con los datos del medico)
 
USE Clinica
GO

CREATE PROCEDURE [dbo].[sp_GetMedicoDetallePorLegajo]
    @Legajo NVARCHAR(4)
AS
BEGIN
    SET NOCOUNT ON;
    
    SELECT 
 
        p.Dni_P, p.Nombre_P, p.Apellido_P, p.Sexo_P, p.Nacionalidad_P, 
        p.FechaNacimiento_P, p.Direccion_P, p.CorreoElectronico_P, 
        p.Telefono_P, p.Estado_P,
        
        m.Legajo_M, m.IdEspecialidad_E_M, m.HorarioAtencion_M,
  
        p.IdLocalidad_L_P,
        l.IdProvincia_Pr_L,
        (
            SELECT STRING_AGG(CAST(IdDia_D_MxD AS VARCHAR), ',') 
            FROM MEDICOSxDIAS 
            WHERE Dni_P_M_MxD = p.Dni_P
        ) AS DiaIDs

    FROM 
        Personas p
    INNER JOIN 
        Medicos m ON p.Dni_P = m.Dni_P_M
    INNER JOIN
        Localidades l ON p.IdLocalidad_L_P = l.IdLocalidad_L
    WHERE 
        m.Legajo_M = @Legajo;
END
GO

---sp_ActualizarMedico (Casi igual al agregar pero usa DELETE / INSERT) modificarmedico

USE Clinica
GO

CREATE PROCEDURE [dbo].[sp_ActualizarMedico]
    -- Parámetros de Persona
    @Dni_P NVARCHAR(8), -- Clave para WHERE
    @IdLocalidad_L_P INT,
    @Nombre_P NVARCHAR(50),
    @Apellido_P NVARCHAR(50),
    @Sexo_P CHAR(1),
    @Nacionalidad_P NVARCHAR(50),
    @FechaNacimiento_P DATE,
    @Direccion_P NVARCHAR(100),
    @CorreoElectronico_P NVARCHAR(100),
    @Telefono_P NVARCHAR(50),
    
    -- Parámetros de Medico
    @Legajo_M NVARCHAR(4), -- Clave para WHERE
    @IdEspecialidad_E_M INT,
    @HorarioAtencion_M NVARCHAR(20),

    @Dias dbo.TipoTablaDia READONLY
AS
BEGIN
    SET NOCOUNT ON;
    BEGIN TRANSACTION;
    
    BEGIN TRY

        UPDATE Personas
        SET 
            IdLocalidad_L_P = @IdLocalidad_L_P,
            Nombre_P = @Nombre_P,
            Apellido_P = @Apellido_P,
            Sexo_P = @Sexo_P,
            Nacionalidad_P = @Nacionalidad_P,
            FechaNacimiento_P = @FechaNacimiento_P,
            Direccion_P = @Direccion_P,
            CorreoElectronico_P = @CorreoElectronico_P,
            Telefono_P = @Telefono_P
        WHERE 
            Dni_P = @Dni_P; -- DNI no se edita

        UPDATE Medicos
        SET 
            IdEspecialidad_E_M = @IdEspecialidad_E_M,
            HorarioAtencion_M = @HorarioAtencion_M
        WHERE 
            Legajo_M = @Legajo_M; -- Legajo no se edita

        DELETE FROM MEDICOSxDIAS 
        WHERE Dni_P_M_MxD = @Dni_P;
        
        INSERT INTO MEDICOSxDIAS(Dni_P_M_MxD, IdDia_D_MxD)
        SELECT @Dni_P, IdDia FROM @Dias;
        
        COMMIT TRANSACTION;
        RETURN 1; 
    END TRY
    BEGIN CATCH
        ROLLBACK TRANSACTION;
        RETURN 0; 
    END CATCH
END
GO

USE Clinica
GO

-- Verifica si el SP existe y lo elimina si es necesario
IF OBJECT_ID('[dbo].[sp_EditarPaciente]', 'P') IS NOT NULL
    DROP PROCEDURE [dbo].[sp_EditarPaciente]
GO

CREATE PROCEDURE [dbo].[sp_EditarPaciente]
    -- Parámetros de Persona
    @Dni NVARCHAR(8),
    @IdLocalidad INT,
    @Nombre NVARCHAR(50),
    @Apellido NVARCHAR(50),
    @Sexo CHAR(1),
    @Nacionalidad NVARCHAR(50),
    @FechaNacimiento DATE,
    @Direccion NVARCHAR(100),
    @Correo NVARCHAR(100),
    @Telefono NVARCHAR(50),

    -- Parámetro de Paciente
    @Diagnostico NVARCHAR(255)
AS
BEGIN
    SET NOCOUNT ON;
    DECLARE @TotalAfectadas INT = 0;

    UPDATE Personas
    SET 
        IdLocalidad_L_P = @IdLocalidad,
        Nombre_P = @Nombre,
        Apellido_P = @Apellido,
        Sexo_P = @Sexo,
        Nacionalidad_P = @Nacionalidad,
        FechaNacimiento_P = @FechaNacimiento,
        Direccion_P = @Direccion,
        CorreoElectronico_P = @Correo,
        Telefono_P = @Telefono
    WHERE 
        Dni_P = @Dni; -- CLAVE: Si el DNI no existe aquí, falla el primer UPDATE

    SET @TotalAfectadas = @TotalAfectadas + @@ROWCOUNT;

    UPDATE Pacientes
    SET 
        Diagnostico_Pa = @Diagnostico
    WHERE 
        Dni_P_Pa = @Dni; -- CLAVE: Si el DNI no existe aquí, falla el segundo UPDATE

    -- Sumamos las filas afectadas de Pacientes. 
    -- Si el Diagnostico no cambió, este @@ROWCOUNT será 0.
    SET @TotalAfectadas = @TotalAfectadas + @@ROWCOUNT;

    -- Retornamos un 1 si se encontró el DNI y se actualizó algo, 0 si no se hizo nada.
    -- Dado que tu DAO espera un entero, podemos devolver la suma de filas afectadas.
    RETURN @TotalAfectadas;
END
GO

USE Clinica
GO

CREATE PROCEDURE [dbo].[sp_GetPacienteDetallePorDni]
    @Dni NVARCHAR(8)
AS
BEGIN
    SET NOCOUNT ON;

    SELECT 
        -- Persona
        p.Dni_P, p.Nombre_P, p.Apellido_P, p.Sexo_P, p.Nacionalidad_P, 
        p.FechaNacimiento_P, p.Direccion_P, p.CorreoElectronico_P, 
        p.Telefono_P, p.Estado_P,

        -- Paciente
        pa.Diagnostico_Pa,

        -- Localidad y Provincia (para DropDownList)
        p.IdLocalidad_L_P,
        l.IdProvincia_Pr_L 

    FROM 
        Personas p
    INNER JOIN 
        Pacientes pa ON p.Dni_P = pa.Dni_P_Pa
    INNER JOIN
        Localidades l ON p.IdLocalidad_L_P = l.IdLocalidad_L
    WHERE 
        p.Dni_P = @Dni;
END
GO

 CREATE PROCEDURE sp_EliminarUsuarioMedico
    @LEGAJO NVARCHAR(4)
AS
BEGIN
    SET NOCOUNT ON;

    -- 1) Verificar que el médico exista
    IF NOT EXISTS (SELECT 1 FROM Medicos WHERE Legajo_M = @LEGAJO)
    BEGIN
        RAISERROR('No se encontró ningún médico con el legajo especificado.', 16, 1);
        RETURN -1;
    END

    -- 2) Verificar que el médico tenga usuario asignado
    IF NOT EXISTS (
        SELECT 1 FROM Medicos 
        WHERE Legajo_M = @LEGAJO
          AND Usuario_M IS NOT NULL
    )
    BEGIN
        RAISERROR('El médico no tiene usuario asignado para eliminar.', 16, 1);
        RETURN -2;
    END

    -- 3) Eliminar usuario (volver a NULL los campos)
    UPDATE Medicos
    SET Usuario_M = NULL,
        Contrasena_M = NULL,
        UsuarioHabilitado_M = NULL
    WHERE Legajo_M = @LEGAJO;

    RETURN @@ROWCOUNT; -- devolverá 1 si se actualizó correctamente
END
GO

CREATE PROCEDURE sp_ObtenerUsuarioPorLegajo
    @LEGAJO NVARCHAR(4)
AS
BEGIN
    SET NOCOUNT ON;

    -- Verificar que el médico exista
    IF NOT EXISTS (SELECT 1 FROM Medicos WHERE Legajo_M = @LEGAJO)
    BEGIN
        RAISERROR('No se encontró ningún médico con ese legajo.', 16, 1);
        RETURN -1;
    END

    -- Devolver el usuario
    SELECT Usuario_M
    FROM Medicos
    WHERE Legajo_M = @LEGAJO;

    RETURN 1;
END
GO

USE [Clinica]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[sp_ObtenerDetalleMedico]
    @Legajo NVARCHAR(4)
AS
BEGIN
    SET NOCOUNT ON;
    
    SELECT
        Medicos.Legajo_M AS Legajo,
        Personas.Dni_P AS DNI,
        Personas.Nombre_P AS Nombre,
        Personas.Apellido_P AS Apellido,
        Personas.Sexo_P AS Sexo,
        Personas.Nacionalidad_P AS Nacionalidad,
        Personas.FechaNacimiento_P AS FechaNacimiento,
        Personas.Direccion_P AS Direccion,
        Localidades.Nombre_L AS Localidad,
        Provincias.Nombre_Pr AS Provincia,
        Personas.CorreoElectronico_P AS Correo,
        Personas.Telefono_P AS Telefono,
        Especialidades.Descripcion_E AS Especialidad,
        Medicos.HorarioAtencion_M AS Horario,
        
        (
            SELECT STRING_AGG(ds.NombreDia_D, ', ') 
            WITHIN GROUP (ORDER BY ds.IdDia_D)
            FROM MEDICOSxDIAS mxd
            INNER JOIN DiasSemana ds ON mxd.IdDia_D_MxD = ds.IdDia_D
            WHERE mxd.Dni_P_M_MxD = Personas.Dni_P
        ) AS Dias
        
    FROM Medicos
    INNER JOIN Personas ON Medicos.Dni_P_M = Personas.Dni_P
    INNER JOIN Localidades ON Personas.IdLocalidad_L_P = Localidades.IdLocalidad_L
    INNER JOIN Provincias ON Localidades.IdProvincia_Pr_L = Provincias.IdProvincia_Pr
    INNER JOIN Especialidades ON Medicos.IdEspecialidad_E_M = Especialidades.IdEspecialidad_E
    WHERE Medicos.Legajo_M = @Legajo
END
GO
 
--SP DETALLE PACIENTE

USE Clinica
GO
CREATE PROCEDURE sp_ObtenerDetallePaciente
    @DNI NVARCHAR(8)
AS
BEGIN
    SET NOCOUNT ON;

    SELECT 
        p.Dni_P AS DNI,                
        P.Nombre_P AS Nombre,           
        P.Apellido_P AS Apellido,       
        P.Sexo_P AS Sexo,  
        p.Nacionalidad_P AS Nacionalidad,
        P.FechaNacimiento_P AS FechaNacimiento, 
        P.Direccion_P AS Direccion,     
        P.CorreoElectronico_P AS Correo,
        P.Telefono_P AS Telefono,       
        
        Loc.Nombre_L AS Localidad,        
        Prov.Nombre_Pr AS Provincia       
    FROM 
        Personas p
    INNER JOIN 
        Pacientes Pac ON P.Dni_P = Pac.Dni_P_Pa
    INNER JOIN 
        Localidades Loc ON P.IdLocalidad_L_P = Loc.IdLocalidad_L
    INNER JOIN 
        Provincias Prov ON Loc.IdProvincia_Pr_L = Prov.IdProvincia_Pr
    WHERE 
        P.Dni_P = @DNI
END
GO


CREATE PROCEDURE SP_Turnos_ObtenerTodos
AS
BEGIN
    SELECT 
        T.IdTurno_T AS IdTurno,
        E.Descripcion_E AS Especialidad,
        (PM.Nombre_P + ' ' + PM.Apellido_P) AS Medico,
        CONVERT(VARCHAR(10), T.Fecha_T, 103) AS Dia,  -- ← FORMATO DD/MM/YYYY
        LEFT(T.Hora_T, 5) AS Horario,
        (PP.Nombre_P + ' ' + PP.Apellido_P) AS Paciente
    FROM Turnos T
    INNER JOIN Especialidades E
        ON T.IdEspecialidad_E_T = E.IdEspecialidad_E
    INNER JOIN Personas PM
        ON T.Dni_P_M_T = PM.Dni_P
    INNER JOIN Personas PP
        ON T.Dni_P_Pa_T = PP.Dni_P
    ORDER BY T.IdTurno_T  ASC;
END
GO

---Medicos por especialidad OJO valida por UsusarioHabilitado => MIGUE
 CREATE PROCEDURE [dbo].[sp_ListarMedicosPorEspecialidad]
  @IdEspecialidad INT
AS
BEGIN
  SET NOCOUNT ON;
    
  SELECT 
      m.Legajo_M, -- Este es elDataValueField (el ID único)
      p.Nombre_P + ' ' + p.Apellido_P AS NombreCompleto -- Este es el DataTextField
  FROM 
      Medicos m
  INNER JOIN 
      Personas p ON m.Dni_P_M = p.Dni_P 
  WHERE 
      p.Estado_P = 1 -- Solo activos
      AND m.IdEspecialidad_E_M = @IdEspecialidad -- filtro especialidad
      AND ISNULL(m.UsuarioHabilitado_M, 0) = 1 --Logica de negocio: El medico debe poder loguearse.
			--ISNULL(ColumnaAAnalizar, ValorDeReemplazo) => si el dato es NULL le pone CERO para comaprar con = 1--
  ORDER BY 
      p.Apellido_P ASC
END
GO

---listar pacientes activos MIGUE
 CREATE PROCEDURE [dbo].[sp_ListarPacientesActivos]
AS
BEGIN
    SET NOCOUNT ON;

    SELECT
        P.Dni_P AS DNI, -- Será el DataValueField 
        P.Apellido_P + ', ' + P.Nombre_P AS NombreCompleto -- Será el DataTextField 
    FROM
        Personas P
    INNER JOIN
        Pacientes Pac ON P.Dni_P = Pac.Dni_P_Pa
    WHERE
        P.Estado_P = 1 -- Solo trae personas que estén activas
    ORDER BY
        P.Apellido_P ASC;
END
GO


---horas ocupadas migue 
CREATE PROCEDURE [dbo].[ ]
    @LegajoMedico NVARCHAR(4),
    @Fecha DATE
AS
BEGIN
    SET NOCOUNT ON;
    
    SELECT  
        T.Hora_T 
    FROM    
        Turnos T
    -- Paso clave: Unimos Turnos con Medicos usando el DNI (la clave FK existente)
    INNER JOIN 
        dbo.Medicos M ON T.Dni_P_M_T = M.Dni_P_M 
    WHERE   
        -- Y AHORA SÍ comparamos el Legajo del parámetro contra la columna Legajo_M
        M.Legajo_M = @LegajoMedico 
        AND T.Fecha_T = @Fecha
END
GO


CREATE PROCEDURE [dbo].[sp_ObtenerDiasYHorarioMedico]
    @Legajo NVARCHAR(4)
AS
BEGIN
    SET NOCOUNT ON;

    SELECT
        M.HorarioAtencion_M AS HorarioBase,
        -- Concatena los IDs de los días (1,2,3...) para usar en C#
        STRING_AGG(CONVERT(VARCHAR, mxd.IdDia_D_MxD), ',') AS IdsDiasTrabajo --convert convierte ID 1 en "1",string agg hace "1,"
    FROM
        Medicos M
    LEFT JOIN
        MEDICOSxDIAS mxd ON M.Dni_P_M = mxd.Dni_P_M_MxD
    WHERE
        M.Legajo_M = @Legajo
	GROUP BY 
     M.HorarioAtencion_M -- Incluimos esta columna porque no está en STRING_AGG
END
GO

---sp_ObtenerDniPorLegajo migue
CREATE PROCEDURE [dbo].[sp_ObtenerDniPorLegajo]
    @Legajo_M NVARCHAR(4)
AS
BEGIN
    SET NOCOUNT ON;
    
    SELECT 
        Dni_P_M
    FROM 
        Medicos 
    WHERE 
        Legajo_M = @Legajo_M;
END
GO

---Ella
CREATE PROCEDURE sp_EliminarTurno
    @IdTurno INT
AS
BEGIN
    DELETE FROM Turnos WHERE IdTurno_T = @IdTurno;
END
GO

---lourd
CREATE PROCEDURE sp_ObtenerDatosTurno
(
    @IdTurno INT
)
AS
BEGIN
    SELECT 
        T.IdTurno_T AS IdTurno,
        T.IdEspecialidad_E_T AS IdEspecialidad,
        E.Descripcion_E AS Especialidad,

        -- Médico
        M.Legajo_M AS LegajoMedico,
        PM.Nombre_P AS NombreMedico,
        PM.Apellido_P AS ApellidoMedico,
        T.Dni_P_M_T AS DniMedico,

        -- Paciente
        PP.Nombre_P AS NombrePaciente,
        PP.Apellido_P AS ApellidoPaciente,
        T.Dni_P_Pa_T AS DniPaciente,

        -- Fecha y Hora
        T.Fecha_T AS FechaTurno,
        T.Hora_T AS HoraTurno,

        -- Datos extra
        T.Observacion_T,
        T.Atendido_T
    FROM Turnos T
    INNER JOIN Especialidades E
        ON T.IdEspecialidad_E_T = E.IdEspecialidad_E
    INNER JOIN Medicos M
        ON T.Dni_P_M_T = M.Dni_P_M
    INNER JOIN Personas PM
        ON M.Dni_P_M = PM.Dni_P
    INNER JOIN Personas PP
        ON T.Dni_P_Pa_T = PP.Dni_P
    WHERE T.IdTurno_T = @IdTurno;
END
GO

CREATE PROCEDURE sp_EditarTurno
(
    @idTurno INT,
    @dniMedico NVARCHAR(8),
    @dniPaciente NVARCHAR(8),
    @idEspecialidad INT,

    @fechaTurno DATE,
    @horaTurno TIME(0),

    @observacion NVARCHAR(200) = NULL,
    @atendido BIT = 0
)
AS
BEGIN
    -- IMPORTANTE: No usar SET NOCOUNT ON (igual que en sp_AgregarTurno)

    UPDATE Turnos
    SET 
        Fecha_T = @fechaTurno,
        Hora_T = @horaTurno,
        IdEspecialidad_E_T = @idEspecialidad,
        Dni_P_M_T = @dniMedico,
        Dni_P_Pa_T = @dniPaciente,
        Observacion_T = @observacion,
        Atendido_T = @atendido
    WHERE IdTurno_T = @idTurno;

    -- Si no explota, devolvemos 1
    RETURN 1;
END
GO

---habilitar ususario medico migue
 CREATE PROCEDURE [dbo].[sp_HabilitarUsuarioMedico]
    @Legajo NVARCHAR(4)
AS
BEGIN
    SET NOCOUNT ON;
    
    UPDATE Medicos
    SET UsuarioHabilitado_M = 1
    WHERE Legajo_M = @Legajo;
    RETURN 1; 
END
GO

--ellaSP para filtrar todo lo que hay desde la vista de admin en turno
USE Clinica
GO

-- Eliminar si existe
IF EXISTS (SELECT * FROM sys.objects WHERE type = 'P' AND name = 'SP_BuscarTurnosAdministrador')
    DROP PROCEDURE SP_BuscarTurnosAdministrador
GO






CREATE PROCEDURE SP_BuscarTurnosAdministrador
    @NombreApellidoMedico NVARCHAR(100) = NULL,
    @NombreApellidoPaciente NVARCHAR(100) = NULL,
    @IdEspecialidad INT = NULL,
    @Lunes BIT = 0,
    @Martes BIT = 0,
    @Miercoles BIT = 0,
    @Jueves BIT = 0,
    @Viernes BIT = 0,
    @Sabado BIT = 0
AS
BEGIN
    SET NOCOUNT ON;
    
    -- Arme esta variable aparte, basicamente lo que quiero es ver si eligio un dia para sumarlo a la consulta despuess
    DECLARE @AlgunDiaSeleccionado BIT = 0;
    
    IF (@Lunes = 1 OR @Martes = 1 OR @Miercoles = 1 OR 
        @Jueves = 1 OR @Viernes = 1 OR @Sabado = 1)
    BEGIN
        SET @AlgunDiaSeleccionado = 1;
    END
    
    SELECT 
        T.IdTurno_T AS IdTurno,
        E.Descripcion_E AS Especialidad,
        (PeMed.Nombre_P + ' ' + PeMed.Apellido_P) AS Medico,
        T.Fecha_T AS Dia,
        T.Hora_T AS Horario,
        (PePac.Nombre_P + ' ' + PePac.Apellido_P) AS Paciente
    FROM 
        Turnos T
    INNER JOIN 
        Especialidades E ON T.IdEspecialidad_E_T = E.IdEspecialidad_E
    INNER JOIN 
        Medicos M ON T.Dni_P_M_T = M.Dni_P_M
    INNER JOIN 
        Personas PeMed ON M.Dni_P_M = PeMed.Dni_P
    INNER JOIN 
        Pacientes Pa ON T.Dni_P_Pa_T = Pa.Dni_P_Pa
    INNER JOIN 
        Personas PePac ON Pa.Dni_P_Pa = PePac.Dni_P
    WHERE 
        -- si lo filtro por nombre o ape del medico
        (
            @NombreApellidoMedico IS NULL 
            OR @NombreApellidoMedico = ''
            OR (PeMed.Nombre_P + ' ' + PeMed.Apellido_P) COLLATE Latin1_General_CI_AI LIKE '%' + @NombreApellidoMedico + '%' COLLATE Latin1_General_CI_AI
        )
        -- si filtro por los datos del paciente
        AND (
            @NombreApellidoPaciente IS NULL 
            OR @NombreApellidoPaciente = ''
            OR (PePac.Nombre_P + ' ' + PePac.Apellido_P) COLLATE Latin1_General_CI_AI LIKE '%' + @NombreApellidoPaciente + '%' COLLATE Latin1_General_CI_AI
        )

        -- si filtro por la especialidad 
        AND (
            @IdEspecialidad IS NULL 
            OR E.IdEspecialidad_E = @IdEspecialidad
        )
        -- si filtro por los dias de la semana
        AND (
            @AlgunDiaSeleccionado = 0  
            OR (
                (@Lunes = 1 AND DATEPART(WEEKDAY, T.Fecha_T) = 2) OR
                (@Martes = 1 AND DATEPART(WEEKDAY, T.Fecha_T) = 3) OR
                (@Miercoles = 1 AND DATEPART(WEEKDAY, T.Fecha_T) = 4) OR
                (@Jueves = 1 AND DATEPART(WEEKDAY, T.Fecha_T) = 5) OR
                (@Viernes = 1 AND DATEPART(WEEKDAY, T.Fecha_T) = 6) OR
                (@Sabado = 1 AND DATEPART(WEEKDAY, T.Fecha_T) = 7)
            )
        )
    ORDER BY 
        T.Fecha_T DESC, T.Hora_T;
END
GO


CREATE PROCEDURE [dbo].[sp_ObtenerReporteTurnosPorMedico]
(
    @FechaDesde DATE,
    @FechaHasta DATE
)
AS
BEGIN
    SELECT 
        E.Descripcion_E AS Especialidad,

        COUNT(*) AS CantidadTurnos
    FROM 
        Turnos T
    INNER JOIN 
        Especialidades E ON T.IdEspecialidad_E_T = E.IdEspecialidad_E
    INNER JOIN
        Medicos M ON T.Dni_P_M_T = M.Dni_P_M
    INNER JOIN
        Personas P ON M.Dni_P_M = P.Dni_P
    WHERE
        T.Fecha_T BETWEEN @FechaDesde AND @FechaHasta
    GROUP BY
        E.Descripcion_E
    ORDER BY 
        CantidadTurnos DESC
END



 CREATE PROCEDURE sp_ActualizarAtencionTurno
(
    @IdTurno INT,
    @Observacion NVARCHAR(200),
    @Atendido BIT
)
AS
BEGIN
		SET NOCOUNT ON;-- asi no me dice los row(s) affected y devuelvo el 1 limpio

    UPDATE Turnos
    SET 
        Observacion_T = @Observacion, 
        Atendido_T = @Atendido       
    WHERE 
        IdTurno_T = @IdTurno      
		RETURN 1;--sin esto no anda el ParameterDirection.ReturnValue
END
GO

USE Clinica
GO
CREATE PROCEDURE [dbo].[sp_AgregarTurno]
    --FK
    @dniMedico NVARCHAR(8),
    @dniPaciente NVARCHAR(8),
    @idEspecialidad INT,

		--TIEMPO
    @fechaTurno DATE, -- Fecha del turno (mapeado desde DateTime.Date)
    @horaTurno TIME(0), -- Hora del turno (mapeado desde TimeSpan)

	  --omisión
    @observacion NVARCHAR(200) = NULL, 
    @atendido BIT = NULL
AS
BEGIN
    -- Elimino SET NOCOUNT ON para que no devuelva cero y nos de dolores de cabeza como los que ya me dio
    INSERT INTO Turnos (Fecha_T, Hora_T, IdEspecialidad_E_T, Dni_P_M_T, Dni_P_Pa_T, Observacion_T, Atendido_T)
    VALUES (@fechaTurno, @horaTurno, @idEspecialidad, @dniMedico, @dniPaciente, @observacion, @atendido);
    
    RETURN 1;  -- PASO CLAVE: Si la inserción fue exitosa (no lanzó excepción), devolvemos 1.
END
GO



CREATE PROCEDURE sp_BuscarTurnoDeMedicoPorPaciente
    @UsuarioMedico NVARCHAR(30),
    @NombreApellido NVARCHAR(100) -- nombre de paciente tiene max 50, y apellido max 50, asi que lo dejo en 100
AS
BEGIN
    SET NOCOUNT ON;

    SET @NombreApellido = '%' + @NombreApellido + '%';

    SELECT 
        T.IdTurno_T AS IdTurno,
        T.Fecha_T AS Dia,
        T.Hora_T AS Horario,
        (PePac.Nombre_P + ' ' + PePac.Apellido_P) AS Paciente,
        T.Observacion_T AS Observacion,
        T.Atendido_T AS Atendido
    FROM Turnos T
    INNER JOIN Pacientes Pa 
        ON T.Dni_P_Pa_T = Pa.Dni_P_Pa
    INNER JOIN Personas PePac 
        ON Pa.Dni_P_Pa = PePac.Dni_P
    INNER JOIN Medicos M 
        ON T.Dni_P_M_T = M.Dni_P_M
    WHERE 
        M.Usuario_M = @UsuarioMedico
       AND (
			    (PePac.Nombre_P + ' ' + PePac.Apellido_P) COLLATE Latin1_General_CI_AI LIKE @NombreApellido COLLATE Latin1_General_CI_AI 
        )
    ORDER BY T.Fecha_T, T.Hora_T;
END
GO

CREATE PROCEDURE sp_FiltrarTurnosMedico
    @Asistio INT = -1,          -- -1 = TODOS, 0 = No asistió, 1 = Asistió
    @Fecha DATE = NULL,         -- Puede venir NULL
    @UsuarioMedico NVARCHAR(30)
AS
BEGIN
    SET NOCOUNT ON;

    SELECT 
        T.IdTurno_T AS IdTurno,
        T.Fecha_T AS Dia,
        T.Hora_T AS Horario,
        (PePac.Nombre_P + ' ' + PePac.Apellido_P) AS Paciente,
        T.Observacion_T AS Observacion,
        T.Atendido_T AS Atendido
    FROM Turnos T
    INNER JOIN Pacientes Pa 
        ON T.Dni_P_Pa_T = Pa.Dni_P_Pa
    INNER JOIN Personas PePac 
        ON Pa.Dni_P_Pa = PePac.Dni_P
    INNER JOIN Medicos M 
        ON T.Dni_P_M_T = M.Dni_P_M
    WHERE 
        M.Usuario_M = @UsuarioMedico
        AND (@Asistio = -1 OR T.Atendido_T = @Asistio)
        AND (@Fecha IS NULL OR T.Fecha_T = @Fecha)
    ORDER BY T.Fecha_T, T.Hora_T;
END
GO


CREATE PROCEDURE sp_ObtenerReportePresentismo
(
    @FechaDesde DATE,
    @FechaHasta DATE
)
AS
BEGIN
    SELECT 
        Atendido_T, COUNT(*) AS CANTIDAD
    FROM 
        Turnos
    WHERE 
        Fecha_T BETWEEN @FechaDesde AND @FechaHasta
        AND Atendido_T IS NOT NULL
        -- FILTRO DE HORA:
        AND (
            Fecha_T < CAST(GETDATE() AS DATE)
            OR 
            (
                Fecha_T = CAST(GETDATE() AS DATE) 
                AND Hora_T <= CAST(GETDATE() AS TIME)
            )
        )
    GROUP BY 
        Atendido_T
END
GO


CREATE PROCEDURE sp_ListarDetallePresentismo
    @FechaDesde DATE,
    @FechaHasta DATE
AS
BEGIN
    SELECT 
        T.Fecha_T,
        T.Hora_T,     
        P.Nombre_P, 
        P.Apellido_P, 
        T.Atendido_T
    FROM 
        Turnos T
    INNER JOIN 
        Personas P ON P.Dni_P = T.Dni_P_Pa_T 
    WHERE 
        T.Fecha_T BETWEEN @FechaDesde AND @FechaHasta
        AND T.Atendido_T IS NOT NULL 
        AND (
            T.Fecha_T < CAST(GETDATE() AS DATE)
            OR 
            (
                T.Fecha_T = CAST(GETDATE() AS DATE) 
                AND T.Hora_T <= CAST(GETDATE() AS TIME)
            )
        )
    ORDER BY 
        T.Fecha_T DESC, T.Hora_T ASC
END
GO

// ultima modificacion:
ALTER PROCEDURE [dbo].[sp_HabilitarUsuarioMedico]
     @Legajo NVARCHAR(4),
    @Habilitado BIT
AS
BEGIN
    SET NOCOUNT ON;
    
      SET NOCOUNT ON;

    UPDATE Medicos
    SET UsuarioHabilitado_M = @Habilitado
    WHERE Legajo_M = @Legajo;

    RETURN @@ROWCOUNT;
END
*/


/* Creación de datos de prueba 
--Tablas dependientes
DELETE FROM Turnos;
DELETE FROM MEDICOSxDIAS;

DELETE FROM Medicos;
DELETE FROM Pacientes;
DELETE FROM Administradores;

DELETE FROM Personas;

DELETE FROM Localidades;
DELETE FROM Provincias;

DBCC CHECKIDENT ('Provincias', RESEED, 0);

INSERT INTO Provincias (Nombre_Pr, Estado_Pr)
VALUES
('Buenos Aires',1),
('Catamarca',1),
('Chaco',1),
('Chubut',1),
('Córdoba',1),
('Corrientes',1),
('Entre Ríos',1),
('Formosa',1),
('Jujuy',1),
('La Pampa',1),
('La Rioja',1),
('Mendoza',1),
('Misiones',1),
('Neuquén',1),
('Río Negro',1),
('Salta',1),
('San Juan',1),
('San Luis',1),
('Santa Cruz',1),
('Santa Fe',1),
('Santiago del Estero',1),
('Tierra del Fuego',1);



DBCC CHECKIDENT ('Localidades', RESEED, 0);

INSERT INTO Localidades (Nombre_L, IdProvincia_Pr_L, Estado_L)
VALUES
-- Buenos Aires (1)
('Capital Federal', 1, 1),
('La Plata', 1, 1),

-- Catamarca (2)
('San Fernando del Valle', 2, 1),
('Belén', 2, 1),

-- Chaco (3)
('Resistencia', 3, 1),
('Barranqueras', 3, 1),

-- Chubut (4)
('Rawson', 4, 1),
('Trelew', 4, 1),

-- Córdoba (5)
('Córdoba Capital', 5, 1),
('Villa Carlos Paz', 5, 1),

-- Corrientes (6)
('Corrientes Capital', 6, 1),
('Goya', 6, 1),

-- Entre Ríos (7)
('Paraná', 7, 1),
('Concordia', 7, 1),

-- Formosa (8)
('Formosa Capital', 8, 1),

-- Jujuy (9)
('San Salvador de Jujuy', 9, 1),

-- La Pampa (10)
('Santa Rosa', 10, 1),

-- La Rioja (11)
('La Rioja Capital', 11, 1),

-- Mendoza (12)
('Mendoza Capital', 12, 1),
('San Rafael', 12, 1),

-- Misiones (13)
('Posadas', 13, 1),

-- Neuquén (14)
('Neuquén Capital', 14, 1),

-- Río Negro (15)
('Viedma', 15, 1),

-- Salta (16)
('Salta Capital', 16, 1),

-- San Juan (17)
('San Juan Capital', 17, 1),

-- San Luis (18)
('San Luis Capital', 18, 1),

-- Santa Cruz (19)
('Río Gallegos', 19, 1),

-- Santa Fe (20)
('Santa Fe Capital', 20, 1),
('Rosario', 20, 1),

-- Santiago del Estero (21)
('Santiago del Estero Capital', 21, 1),

-- Tierra del Fuego (22)
('Ushuaia', 22, 1),
('Río Grande', 22, 1);



DECLARE @dni INT = 30000000;
DECLARE @i INT = 1;

-- Listas simuladas
DECLARE @Nombres TABLE (Id INT IDENTITY(1,1), Nombre VARCHAR(50), Sexo CHAR(1));
INSERT INTO @Nombres (Nombre, Sexo) VALUES
('Juan','M'),('Carlos','M'),('Martín','M'),('Lucas','M'),('Pablo','M'),
('María','F'),('Ana','F'),('Laura','F'),('Carolina','F'),('Sofía','F'),
('Lucía','F'),('Valentina','F'),('Camila','F'),('Florencia','F'),('Julieta','F'),
('Diego','M'),('Fernando','M'),('Gonzalo','M'),('Nicolás','M'),('Sebastián','M');

DECLARE @Apellidos TABLE (Id INT IDENTITY(1,1), Apellido VARCHAR(50));
INSERT INTO @Apellidos VALUES
('Gómez'),('Pérez'),('Rodríguez'),('Fernández'),('López'),
('Martínez'),('Sánchez'),('Romero'),('Díaz'),('Álvarez'),
('Torres'),('Ruiz'),('Flores'),('Acosta'),('Benítez');

DECLARE @Direcciones TABLE (Id INT IDENTITY(1,1), Direccion VARCHAR(100));
INSERT INTO @Direcciones VALUES
('Av. Siempre Viva 742'),
('Calle Mitre 123'),
('Av. San Martín 456'),
('Belgrano 890'),
('Rivadavia 1020'),
('Sarmiento 345'),
('Lavalle 678'),
('Corrientes 1500'),
('Av. Córdoba 2300'),
('Independencia 900');

WHILE @dni < 30000110
BEGIN
    DECLARE @idNombre INT = ((@i - 1) % (SELECT COUNT(*) FROM @Nombres)) + 1;
    DECLARE @idApellido INT = ((@i - 1) % (SELECT COUNT(*) FROM @Apellidos)) + 1;
    DECLARE @idDireccion INT = ((@i - 1) % (SELECT COUNT(*) FROM @Direcciones)) + 1;

    DECLARE @nombre VARCHAR(50);
    DECLARE @sexo CHAR(1);
    DECLARE @apellido VARCHAR(50);
    DECLARE @direccion VARCHAR(100);
	DECLARE @nombreMail VARCHAR(50);
	DECLARE @apellidoMail VARCHAR(50);

    SELECT @nombre = Nombre, @sexo = Sexo FROM @Nombres WHERE Id = @idNombre;
    SELECT @apellido = Apellido FROM @Apellidos WHERE Id = @idApellido;
    SELECT @direccion = Direccion FROM @Direcciones WHERE Id = @idDireccion;
	SET @nombreMail = LOWER(@nombre);
SET @apellidoMail = LOWER(@apellido);

SET @nombreMail = REPLACE(@nombreMail, 'á', 'a');
SET @nombreMail = REPLACE(@nombreMail, 'é', 'e');
SET @nombreMail = REPLACE(@nombreMail, 'í', 'i');
SET @nombreMail = REPLACE(@nombreMail, 'ó', 'o');
SET @nombreMail = REPLACE(@nombreMail, 'ú', 'u');

SET @apellidoMail = REPLACE(@apellidoMail, 'á', 'a');
SET @apellidoMail = REPLACE(@apellidoMail, 'é', 'e');
SET @apellidoMail = REPLACE(@apellidoMail, 'í', 'i');
SET @apellidoMail = REPLACE(@apellidoMail, 'ó', 'o');
SET @apellidoMail = REPLACE(@apellidoMail, 'ú', 'u');


    INSERT INTO Personas
    (Dni_P, IdLocalidad_L_P, Nombre_P, Apellido_P, Sexo_P, Nacionalidad_P,
     FechaNacimiento_P, Direccion_P, CorreoElectronico_P, Telefono_P, Estado_P)
    VALUES
    (
        @dni,
        ((@dni % (SELECT COUNT(*) FROM Localidades)) + 1),
        @nombre,
        @apellido,
        @sexo,
        'Argentina',
        -- Edad entre 18 y 80 años
        DATEADD(YEAR, - (18 + (@i % 63)), GETDATE()),
        @direccion,
       CONCAT(@nombreMail, '.', @apellidoMail, '@mail.com'),
        CONCAT('11', RIGHT(@dni, 8)),
        1
    );

    SET @dni += 1;
    SET @i += 1;

END;


INSERT INTO Administradores
(Dni_P_A, Usuario_A, Contrasena_A, UsuarioHabilitado_A)
SELECT
    Dni_P,
    CONCAT('admin', ROW_NUMBER() OVER (ORDER BY Dni_P)) AS Usuario_A,
    '1234',
    1
FROM (
    SELECT TOP 10 Dni_P
    FROM Personas
    ORDER BY Dni_P
) A;



INSERT INTO Medicos
(Dni_P_M, Legajo_M, IdEspecialidad_E_M, HorarioAtencion_M,
 Usuario_M, Contrasena_M, UsuarioHabilitado_M)
SELECT
    Dni_P,
    CONCAT('L', FORMAT(rn, '000')) AS Legajo_M,
    ((rn - 1) % 30) + 1 AS IdEspecialidad_E_M,
    CASE 
        WHEN (rn % 3) = 1 THEN '08:00-12:00'
        WHEN (rn % 3) = 2 THEN '12:00-16:00'
        ELSE '16:00-20:00'
    END AS HorarioAtencion_M,
    CONCAT('med', FORMAT(rn, '000')) AS Usuario_M,
    '1234',
    1
FROM (
    SELECT 
        Dni_P,
        ROW_NUMBER() OVER (ORDER BY Dni_P) AS rn
    FROM Personas
    ORDER BY Dni_P
    OFFSET 10 ROWS FETCH NEXT 40 ROWS ONLY
) M;


INSERT INTO Pacientes
(Dni_P_Pa, Diagnostico_Pa)
SELECT
    Dni_P,
    CASE Dni_P % 10
        WHEN 0 THEN 'Control general'
        WHEN 1 THEN 'Hipertensión arterial'
        WHEN 2 THEN 'Diabetes tipo 2'
        WHEN 3 THEN 'Asma'
        WHEN 4 THEN 'Colesterol elevado'
        WHEN 5 THEN 'Dolor lumbar'
        WHEN 6 THEN 'Gastritis'
        WHEN 7 THEN 'Migraña'
        WHEN 8 THEN 'Alergia respiratoria'
        ELSE 'Chequeo cardiovascular'
    END AS Diagnostico_Pa
FROM (
    SELECT Dni_P
    FROM Personas
    ORDER BY Dni_P
    OFFSET 50 ROWS FETCH NEXT 60 ROWS ONLY
) P;



INSERT INTO MEDICOSxDIAS
(Dni_P_M_MxD, IdDia_D_MxD)
SELECT
    M.Dni_P_M,
    D.IdDia
FROM Medicos M
CROSS JOIN (
    VALUES (1),(2),(3),(4),(5)
) D(IdDia);



DECLARE @FechaInicio DATE = DATEFROMPARTS(YEAR(GETDATE()), 1, 1);
DECLARE @FechaFin DATE = '2026-02-28';

;WITH Fechas AS (
    SELECT @FechaInicio AS Fecha
    UNION ALL
    SELECT DATEADD(DAY, 1, Fecha)
    FROM Fechas
    WHERE Fecha < @FechaFin
),
FechasHabiles AS (
    SELECT Fecha
    FROM Fechas
    WHERE DATEPART(WEEKDAY, Fecha) BETWEEN 2 AND 6 -- Lunes a Viernes
),
Horas AS (
    SELECT CAST('08:00' AS TIME) AS Hora UNION ALL
    SELECT '09:00' UNION ALL
    SELECT '10:00' UNION ALL
    SELECT '11:00' UNION ALL
    SELECT '12:00' UNION ALL
    SELECT '13:00' UNION ALL
    SELECT '14:00' UNION ALL
    SELECT '15:00' UNION ALL
    SELECT '16:00' UNION ALL
    SELECT '17:00' UNION ALL
    SELECT '18:00' UNION ALL
    SELECT '19:00'
),
TurnosBase AS (
    SELECT
        F.Fecha,
        H.Hora,
        M.Dni_P_M,
        M.IdEspecialidad_E_M,
        ROW_NUMBER() OVER (
            PARTITION BY YEAR(F.Fecha), MONTH(F.Fecha)
            ORDER BY NEWID()
        ) AS rnMes
    FROM FechasHabiles F
    JOIN MEDICOSxDIAS MD
        ON MD.IdDia_D_MxD = DATEPART(WEEKDAY, F.Fecha) - 1
    JOIN Medicos M
        ON M.Dni_P_M = MD.Dni_P_M_MxD
    JOIN Horas H
        ON (
            (M.HorarioAtencion_M = '08:00-12:00' AND H.Hora BETWEEN '08:00' AND '11:00')
            OR
            (M.HorarioAtencion_M = '12:00-16:00' AND H.Hora BETWEEN '12:00' AND '15:00')
            OR
            (M.HorarioAtencion_M = '16:00-20:00' AND H.Hora BETWEEN '16:00' AND '19:00')
        )
),
TurnosFiltrados AS (
    -- Máx. 20 turnos por mes
    SELECT *
    FROM TurnosBase
    WHERE rnMes <= 20
),
TurnosNumerados AS (
    -- Numeramos turnos por día
    SELECT *,
           ROW_NUMBER() OVER (
               PARTITION BY Fecha
               ORDER BY NEWID()
           ) AS rnTurnoDia
    FROM TurnosFiltrados
),
PacientesPorDia AS (
    -- Numeramos pacientes por día (para evitar repeticiones)
    SELECT
        F.Fecha,
        P.Dni_P_Pa,
        ROW_NUMBER() OVER (
            PARTITION BY F.Fecha
            ORDER BY NEWID()
        ) AS rnPaciente
    FROM (
        SELECT DISTINCT Fecha FROM TurnosFiltrados
    ) F
    CROSS JOIN Pacientes P
),
TurnosConPaciente AS (
    SELECT
        T.Fecha,
        T.Hora,
        T.Dni_P_M,
        T.IdEspecialidad_E_M,
        P.Dni_P_Pa
    FROM TurnosNumerados T
    JOIN PacientesPorDia P
        ON P.Fecha = T.Fecha
       AND P.rnPaciente = T.rnTurnoDia
),
TurnosFinales AS (
    SELECT
        Fecha,
        Hora,
        IdEspecialidad_E_M,
        Dni_P_M,
        Dni_P_Pa,
        CASE 
            WHEN Fecha < CAST(GETDATE() AS DATE)
                 AND ABS(CHECKSUM(NEWID())) % 10 < 8
                THEN 1
            WHEN Fecha < CAST(GETDATE() AS DATE)
                THEN 0
            ELSE NULL
        END AS Atendido_T
    FROM TurnosConPaciente
)
INSERT INTO Turnos
(
    Fecha_T,
    Hora_T,
    IdEspecialidad_E_T,
    Dni_P_M_T,
    Dni_P_Pa_T,
    Observacion_T,
    Atendido_T
)
SELECT
    CAST(Fecha AS DATE),
    Hora,
    IdEspecialidad_E_M,
    Dni_P_M,
    Dni_P_Pa,
    CASE 
        WHEN Atendido_T = 1 THEN
            CASE ABS(CHECKSUM(NEWID())) % 6
                WHEN 0 THEN 'Paciente evaluado en consulta clínica. Evolución favorable.'
                WHEN 1 THEN 'Consulta médica completa. Se solicitan estudios complementarios.'
                WHEN 2 THEN 'Control periódico realizado. Continúa con el tratamiento indicado.'
                WHEN 3 THEN 'Atención médica sin complicaciones. Signos vitales normales.'
                WHEN 4 THEN 'Paciente atendido. Se prescribe medicación y reposo.'
                ELSE 'Consulta realizada con indicaciones generales y seguimiento.'
            END
	    WHEN Atendido_T = 0 THEN
        'No asistió'

        ELSE NULL
    END,
    Atendido_T
FROM TurnosFinales
OPTION (MAXRECURSION 0);


 
 */