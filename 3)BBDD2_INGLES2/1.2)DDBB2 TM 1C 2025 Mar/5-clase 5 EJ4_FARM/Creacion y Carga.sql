USE EJ04A2025
GO

USE EJ04A2025
GO
--siempre comenzar con el que tiene 1 y luego con muchos por la fk
CREATE TABLE TIPO_MEDICAMENTOS(
	CodTipoMed_TM char (4) not null,-- pk
	Descripcion_TM varchar(50), 
  Constraint PK_TIPO_MEDICAMENTOS Primary Key(CodTipoMed_TM)
)
GO

Create Table LABORATORIOS(
	CodLab_L char(4) not null, 
	Nombre_L varchar(25) not null, 
	Telefono_L varchar(20) NOT NULL,
	Direccion_L varchar(50) NOT NULL,
	Fax_L varchar(20) NULL,
	Contacto_L varchar(50) NULL,
	CONSTRAINT PK_LABORATORIOS Primary Key(CodLab_L)
)
GO

CREATE TABLE MEDICAMENTOS (
	CodMed_M char(4) NOT NULL, --PK
	CodTipoMed_TM_M char(4) NOT NULL,--FK jarabe, comprimido, pomada, etc
	CodLab_L_M char(4) NOT NULL, -- FK
	Nombre_M varchar(50) NOT NULL,
	Stock_M int NOT NULL,
	PtoPedido_M int NULL,--stock minimo
	Precio_M money NULL,--se actualiza
	LibreReceta_M bit NOT NULL default 0,--bool -> libre o receta
	CONSTRAINT PK_MEDICAMENTOS PRIMARY KEY (CodMed_M),
	Constraint FK_MEDICAMENTOS_TIPOMEDICAMENTOS Foreign key (CodTipoMed_TM_M) References TIPO_MEDICAMENTOS (CodTipoMed_TM),
	Constraint FK_MEDICAMENTOS_LABORATORIOS Foreign key (CodLab_L_M) References LABORATORIOS (CodLab_L)
)
GO

CREATE TABLE FACTURAS(
	ID_Fact_F int IDENTITY(1,1) NOT NULL,--crece de a 1 desde el 1
	Cliente_F varchar(20) NOT NULL,
	Total_F decimal(8,2) NULL,--8 totales 123456.78
	Fecha_F smalldatetime NULL,
	constraint PK_FACTURAS Primary Key (ID_Fact_F)
 )
GO

CREATE TABLE DETALLE_FACTURAS(
	ID_Fact_F_DET int NOT NULL,
	CodMed_M_DET char(4) NOT NULL,
	Cantidad_DET int null,
	PU_DET decimal (8,2) NOT NULL, 
	Constraint PK_DETALLE_FACTURAS Primary Key (ID_Fact_F_DET, CodMed_M_DET),
	Constraint FK_DETALLE_FACTURAS_FACTURAS Foreign Key (ID_Fact_F_DET) References FACTURAS (ID_Fact_F), 
	Constraint FK_DETALLE_FACTURAS_MEDICAMENTOS Foreign Key (CodMed_M_DET) References MEDICAMENTOS (CodMed_M)
)
GO

CREATE TABLE FAMILIAS(
	CodFam_F char(4) NOT NULL, 
	NombFam_F varchar(25) NOT NULL, 
	Constraint PK_FAMILIAS Primary Key (CodFam_F)
)
GO

CREATE TABLE MEDICAMENTOSxFAMILIAS(
	CodMed_M_MxF char(4) not null, 
	CodFam_F_MxF char(4) not null,
	Constraint PK_MEDICAMENTOSxFAMILIAS Primary Key(CodMed_M_MxF, CodFam_F_MxF),
	Constraint FK_MEDICAMENTOSxFAMILIAS_MEDICAMENTOS Foreign Key (CodMed_M_MxF) REFERENCES MEDICAMENTOS (CodMed_M),
	Constraint FK_MEDICAMENTOSxFAMILIAS_FAMILIAS Foreign Key (CodFam_F_MxF) REFERENCES FAMILIAS(CodFam_F)
)
GO


INSERT INTO TIPO_MEDICAMENTOS (CodTipoMed_TM, Descripcion_TM)
SELECT 'COMP', 'Comprimido' UNION 
SELECT 'JARA', 'Jarabe' UNION 
SELECT 'POMA', 'Pomada' UNION 
SELECT 'CAPS', 'C�psula' UNION 
SELECT 'GOTA', 'Gotas';

Select * from TIPO_MEDICAMENTOS

-- Insertar laboratorios usando UNION
INSERT INTO LABORATORIOS (CodLab_L, Nombre_L, Telefono_L, Direccion_L, Fax_L, Contacto_L)
SELECT 'LAB1', 'Pfizer Argentina', '011-4871-5000', 'Av. Libertador 4980, CABA', '011-4871-5001', 'Dr. Carlos Mart�nez' UNION
SELECT 'LAB2', 'Bayer Argentina', '011-4340-4900', 'Parque Industrial Pilar, Bs. As.', NULL, 'Lic. Ana G�mez' UNION
SELECT 'LAB3', 'Roemmers', '011-4307-3636', 'Estados Unidos 3602, CABA', '011-4307-3650', 'Dr. Luis Rodr�guez' UNION
SELECT 'LAB4', 'Elea Phoenix', '011-4637-7000', 'Gral. Paz 5445, CABA', NULL, 'Sra. Patricia L�pez' UNION
SELECT 'LAB5', 'Bag� Argentina', '0221-451-2000', 'Camino Gral. Belgrano 430, La Plata', '0221-451-2001', 'Dr. Jorge S�nchez';

-- Verificar los datos insertados
SELECT * FROM LABORATORIOS;

-- Insertar medicamentos usando UNION
INSERT INTO MEDICAMENTOS (CodMed_M, CodTipoMed_TM_M, CodLab_L_M, Nombre_M, Stock_M, PtoPedido_M, Precio_M, LibreReceta_M)
SELECT 'M001', 'COMP', 'LAB1', 'Ibuprofeno 400mg', 150, 50, 120.50, 1 UNION
SELECT 'M002', 'COMP', 'LAB1', 'Paracetamol 500mg', 200, 70, 95.80, 1 UNION
SELECT 'M003', 'JARA', 'LAB2', 'Jarabe para la tos Miel', 80, 30, 350.75, 1 UNION
SELECT 'M004', 'CAPS', 'LAB3', 'Amoxicilina 500mg', 45, 15, 420.30, 0 UNION
SELECT 'M005', 'POMA', 'LAB4', 'Pomada antiinflamatoria', 60, 20, 280.00, 1 UNION
SELECT 'M006', 'GOTA', 'LAB5', 'Gotas oft�lmicas hidratantes', 100, 40, 190.80, 1 UNION
SELECT 'M007', 'COMP', 'LAB2', 'Omeprazol 20mg', 90, 30, 150.00, 0 UNION
SELECT 'M008', 'JARA', 'LAB3', 'Jarabe expectorante', 70, 25, 320.40, 1 UNION
SELECT 'M009', 'CAPS', 'LAB1', 'Cefalexina 500mg', 55, 20, 380.90, 0 UNION
SELECT 'M010', 'POMA', 'LAB5', 'Crema hidratante dermatol�gica', 120, 50, 410.20, 1;

-- Verificar los datos insertados
SELECT * FROM MEDICAMENTOS;

-- Insertar facturas usando UNION con formato correcto para smalldatetime
INSERT INTO FACTURAS (Cliente_F, Total_F, Fecha_F)
SELECT 'Juan P�rez', 850.25, '2023-05-10T10:30:00' UNION
SELECT 'Mar�a G�mez', 1200.50, '2023-05-11T15:45:00' UNION
SELECT 'Carlos L�pez', 560.75, '2023-05-12T09:15:00' UNION
SELECT 'Ana Rodr�guez', 980.00, '2023-05-13T11:20:00' UNION
SELECT 'Pedro S�nchez', 420.30, '2023-05-14T16:00:00' UNION
SELECT 'Luc�a Fern�ndez', 750.80, '2023-05-15T14:10:00' UNION
SELECT 'Roberto Jim�nez', 1320.90, '2023-05-16T17:30:00' UNION
SELECT 'Sof�a Mart�nez', 640.25, '2023-05-17T10:45:00' UNION
SELECT 'Miguel �ngel Ruiz', 890.40, '2023-05-18T12:00:00' UNION
SELECT 'Elena Vargas', 1120.60, '2023-05-19T13:15:00';

-- Verificar los datos insertados
SELECT * FROM FACTURAS;

-- Insertar detalles usando los IDs reales (2-11)
INSERT INTO DETALLE_FACTURAS (ID_Fact_F_DET, CodMed_M_DET, Cantidad_DET, PU_DET)
SELECT 2, 'M001', 2, 120.50 UNION   -- Factura de Ana Rodr�guez
SELECT 2, 'M003', 1, 280.00 UNION
SELECT 3, 'M002', 3, 95.80 UNION    -- Factura de Carlos L�pez
SELECT 4, 'M004', 2, 420.30 UNION   -- Factura de Elena Vargas
SELECT 5, 'M006', 1, 190.80 UNION   -- Factura de Juan P�rez
SELECT 6, 'M001', 3, 120.50 UNION   -- Factura de Luc�a Fern�ndez
SELECT 7, 'M007', 1, 150.00 UNION   -- Factura de Mar�a G�mez
SELECT 8, 'M008', 2, 320.40 UNION   -- Factura de Miguel �ngel Ruiz
SELECT 9, 'M009', 1, 380.90 UNION   -- Factura de Pedro S�nchez
SELECT 10, 'M005', 2, 280.00 UNION  -- Factura de Roberto Jim�nez
SELECT 11, 'M010', 1, 410.20;       -- Factura de Sof�a Mart�nez

-- Verificar los datos insertados
SELECT * FROM DETALLE_FACTURAS;

-- Insertar 5 familias de medicamentos usando UNION
INSERT INTO FAMILIAS (CodFam_F, NombFam_F)
SELECT 'ANAL', 'Analg�sicos' UNION
SELECT 'ANTI', 'Antiinflamatorios' UNION
SELECT 'ANTB', 'Antibi�ticos' UNION
SELECT 'ANTT', 'Antitusivos' UNION
SELECT 'DERM', 'Dermatol�gicos';

-- Verificar los datos insertados
SELECT * FROM FAMILIAS;

-- Insertar relaciones v�lidas (solo con ANAL, ANTI, ANTB, ANTT, DERM)
INSERT INTO MEDICAMENTOSxFAMILIAS (CodMed_M_MxF, CodFam_F_MxF)
SELECT 'M001', 'ANAL' UNION  -- Ibuprofeno es Analg�sico
SELECT 'M001', 'ANTI' UNION  -- Ibuprofeno es Antiinflamatorio
SELECT 'M002', 'ANAL' UNION  -- Paracetamol es Analg�sico
SELECT 'M003', 'ANTT' UNION  -- Jarabe para la tos es Antitusivo
SELECT 'M004', 'ANTB' UNION  -- Amoxicilina es Antibi�tico
SELECT 'M005', 'DERM' UNION  -- Pomada es Dermatol�gica
SELECT 'M005', 'ANTI' UNION  -- Pomada es Antiinflamatoria
SELECT 'M009', 'ANTB' UNION  -- Cefalexina es Antibi�tico
SELECT 'M010', 'DERM';       -- Crema dermatol�gica

-- Verificar los datos insertados
SELECT * FROM MEDICAMENTOSxFAMILIAS;

