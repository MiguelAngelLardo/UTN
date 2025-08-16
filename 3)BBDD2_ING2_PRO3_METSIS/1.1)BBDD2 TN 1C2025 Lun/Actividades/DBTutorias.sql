CREATE DATABASE DBTutorias
COLLATE Latin1_General_CI_AI;

GO

USE DBTutorias;
GO

-- ==============================================
-- TABLAS
-- ==============================================

CREATE TABLE Estudiantes (
    IDEstudiante INT PRIMARY KEY IDENTITY(1,1),
    Legajo VARCHAR(10) NOT NULL,
    Nombre VARCHAR(100) NOT NULL,
    Apellido VARCHAR(100) NOT NULL,
    Email VARCHAR(150) NOT NULL,
    FechaAlta DATE NOT NULL DEFAULT GETDATE(),
    SaldoCredito SMALLINT NOT NULL DEFAULT 10,
    Activo BIT  NOT NULL DEFAULT 1
);

CREATE TABLE Materias (
    IDMateria INT PRIMARY KEY IDENTITY(1,1),
    Nombre VARCHAR(100) NOT NULL,
    Nivel TINYINT NOT NULL,
    Carrera VARCHAR(150) NOT NULL,
	CodigoMateria VARCHAR(4) NOT NULL
);

CREATE TABLE EstudiantesMaterias (
    IDEstudiante INT NOT NULL,
    IDMateria INT NOT NULL,
    Rol VARCHAR(10) NOT NULL,
    FechaAlta DATE NOT NULL DEFAULT GETDATE(),
    PRIMARY KEY (IDEstudiante, IDMateria, rol),
    FOREIGN KEY (IDEstudiante) REFERENCES Estudiantes(IDEstudiante),
    FOREIGN KEY (IDMateria) REFERENCES Materias(IDMateria)
);

CREATE TABLE Tutorias (
    IDTutoria INT PRIMARY KEY IDENTITY(1,1),
    IDEstudianteTutor INT NOT NULL,
    IDEstudianteAlumno INT NOT NULL,
    IDMateria INT NOT NULL,
    Fecha DATE NOT NULL,
    Duracion TINYINT NOT NULL,
	ConfirmaTutor BIT NOT NULL DEFAULT 0,
	ConfirmaAlumno BIT NOT NULL DEFAULT 0,
    Estado VARCHAR(20) NOT NULL DEFAULT 'PENDIENTE',
    FOREIGN KEY (IDEstudianteTutor) REFERENCES Estudiantes(IDEstudiante),
    FOREIGN KEY (IDEstudianteAlumno) REFERENCES Estudiantes(IDEstudiante),
    FOREIGN KEY (IDMateria) REFERENCES Materias(IDMateria)
);

CREATE TABLE HistorialCreditos (
    IDCredito INT PRIMARY KEY IDENTITY(1,1),
    IDEstudiante INT NOT NULL,
    Fecha DATE NOT NULL DEFAULT GETDATE(),
    Tipo VARCHAR(10) NOT NULL,
    Cantidad TINYINT NOT NULL,
    Descripcion VARCHAR(255) NOT NULL,
    FOREIGN KEY (IDEstudiante) REFERENCES Estudiantes(IDEstudiante)
);
