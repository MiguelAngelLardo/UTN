USE EJ06A2025
GO

CREATE TABLE PROVEEDORES (
    CodProv_P char(4) NOT NULL,          -- Código del proveedor (PK)
    CUIT_P varchar(15) NOT NULL,         -- CUIT del proveedor (formato: 00-00000000-0)
    RazonSocial_P varchar(100) NOT NULL, -- Nombre legal del proveedor
    Direccion_P varchar(100) NOT NULL,   -- Dirección completa
    Ciudad_P varchar(50) NOT NULL,       -- Ciudad
    Provincia_P varchar(50) NOT NULL,    -- Provincia
    Telefono_P varchar(20) NOT NULL,     -- Teléfono (formato internacional)
    Contacto_P varchar(50) NULL,         -- Persona de contacto
    WEB_P varchar(100) NULL,             -- Sitio web (URL)
    Email_P varchar(100) NULL,           -- Email del proveedor
    CONSTRAINT PK_PROVEEDORES PRIMARY KEY (CodProv_P),
    CONSTRAINT UK_PROVEEDORES_CUIT UNIQUE (CUIT_P)  -- El CUIT debe ser único
)
GO

CREATE TABLE ARTICULOS (
    CodArt_A char(4) NOT NULL,               -- Código del artículo (PK)
    CodProv_P_A char(4) NOT NULL,            -- Código del proveedor (FK)
    Descripcion_A varchar(100) NOT NULL,     -- Descripción del artículo
    Stock_A int NOT NULL DEFAULT 0,          -- Cantidad en stock (inicia en 0)
    PU_A money NOT NULL,                     -- Precio unitario
    CONSTRAINT PK_ARTICULOS PRIMARY KEY (CodArt_A, CodProv_P_A),
    CONSTRAINT FK_ARTICULOS_PROVEEDORES FOREIGN KEY (CodProv_P_A) REFERENCES PROVEEDORES(CodProv_P)
)
GO

CREATE TABLE CLIENTES (
    Dni_C char(8) NOT NULL,               -- Documento de identidad (PK)
    Nombre_C varchar(50) NOT NULL,             -- Nombre del cliente
    Apellido_C varchar(50) NOT NULL,           -- Apellido del cliente
    Direccion_C varchar(100) NOT NULL,         -- Dirección completa
    Telefono_C varchar(20) NOT NULL,           -- Teléfono de contacto
    CONSTRAINT PK_CLIENTES PRIMARY KEY (Dni_C)
)
GO

CREATE TABLE CUENTAS (
    CodCuenta_CU char(4) NOT NULL,               -- Código único de la cuenta (PK)
    Dni_CL_CU char(8) NOT NULL,              -- DNI del cliente (FK)
    LimiteCuenta_CU money NOT NULL,              -- Límite de crédito
    SaldoCuenta_CU money NOT NULL DEFAULT 0,     -- Saldo actual (inicia en 0)
    CONSTRAINT PK_CUENTAS PRIMARY KEY (CodCuenta_CU),
    CONSTRAINT FK_CUENTAS_CLIENTES FOREIGN KEY (Dni_CL_CU) REFERENCES CLIENTES(Dni_C)
)
GO

CREATE TABLE FACTURAS (
    CodFactura_FA int IDENTITY(1,1) NOT NULL,               -- Código único de factura (PK)
    CodCuenta_CU_FA char(4) NOT NULL,             -- Código de cuenta asociada (FK)
    TotalFactura_FA money NOT NULL,                -- Total de la factura
    FechaFactura_FA datetime NOT NULL DEFAULT GETDATE(), -- Fecha de emisión (actual por defecto)
    CONSTRAINT PK_FACTURAS PRIMARY KEY (CodFactura_FA),
    CONSTRAINT FK_FACTURAS_CUENTAS FOREIGN KEY (CodCuenta_CU_FA) REFERENCES CUENTAS(CodCuenta_CU)
)
GO

CREATE TABLE DETALLE_FACTURAS (
    CodFactura_FA_DF int NOT NULL,          -- Código de factura (PK/FK)
    CodArt_A_DF char(4) NOT NULL,               -- Código de artículo (PK/FK)
    CodProv_A_DF char(4) NOT NULL,              -- Código de proveedor (PK/FK)
    Cantidad_DF int NOT NULL,                   -- Cantidad vendida
    PU_DF money NOT NULL,                       -- Precio unitario al momento de la venta
    CONSTRAINT PK_DETALLE_FACTURAS PRIMARY KEY (CodFactura_FA_DF, CodArt_A_DF, CodProv_A_DF),
    CONSTRAINT FK_DF_FACTURAS FOREIGN KEY (CodFactura_FA_DF)REFERENCES FACTURAS(CodFactura_FA),
    CONSTRAINT FK_DF_ARTICULOS FOREIGN KEY (CodArt_A_DF, CodProv_A_DF) REFERENCES ARTICULOS(CodArt_A, CodProv_P_A)
)
GO

INSERT INTO PROVEEDORES (CodProv_P, CUIT_P, RazonSocial_P, Direccion_P, Ciudad_P, Provincia_P, Telefono_P, Contacto_P, WEB_P, Email_P)
SELECT 'P001', '30-12345678-9', 'Farmacéutica Buenos Aires S.A.', 'Av. Rivadavia 1500', 'CABA', 'Buenos Aires', '+541112345678', 'Juan Pérez', 'www.farmaba.com.ar', 'ventas@farmaba.com.ar' UNION 
SELECT 'P002', '30-23456789-1', 'Laboratorios PharmaSur', 'Calle 10 N° 789', 'La Plata', 'Buenos Aires', '+542214567890', 'María Gómez', 'www.pharmasur.com', 'info@pharmasur.com' UNION 
SELECT 'P003', '30-34567891-2', 'Medicamentos del Norte S.R.L.', 'Belgrano 456', 'Salta', 'Salta', '+543874563210', NULL, 'www.medinorte.com.ar', 'contacto@medinorte.com.ar' UNION 
SELECT 'P004', '30-45678912-3', 'Distribuidora Farmacéutica Central', 'San Martín 1234', 'Córdoba', 'Córdoba', '+543514567890', 'Carlos Rodríguez', NULL, 'ventas@difarce.com' UNION 
SELECT 'P005', '30-56789123-4', 'Laboratorios Andinos', 'Mitre 789', 'Mendoza', 'Mendoza', '+542614785236', 'Ana López', 'www.laboratoriosandinos.com', 'administracion@landinos.com' UNION 
SELECT 'P006', '30-67891234-5', 'Genéricos del Litoral', '25 de Mayo 456', 'Rosario', 'Santa Fe', '+543414789520', 'Pedro Martínez', 'www.genericoslitoral.com.ar', NULL UNION 
SELECT 'P007', '30-78912345-6', 'Biofarmacéutica Argentina', 'Corrientes 3210', 'CABA', 'Buenos Aires', '+541145678912', 'Lucía Fernández', 'www.biofarma.com.ar', 'clientes@biofarma.com.ar' UNION 
SELECT 'P008', '30-89123456-7', 'Farmacoop', 'Sarmiento 987', 'Mar del Plata', 'Buenos Aires', '+542234567891', NULL, NULL, 'farmacoop@mdp.com.ar' UNION 
SELECT 'P009', '30-91234567-8', 'Medicamentos Patagónicos', 'Roca 456', 'Neuquén', 'Neuquén', '+542994567812', 'Sofía Giménez', 'www.medipatagonia.com', 'ventas@medipatagonia.com' UNION 
SELECT 'P010', '30-98765432-1', 'Insumos Médicos del Este', 'Urquiza 654', 'Posadas', 'Misiones', '+543764567890', 'Roberto Sánchez', 'www.insumoseste.com', 'info@insumoseste.com'
GO

-- Consulta para verificar los datos
SELECT * FROM PROVEEDORES
GO

INSERT INTO ARTICULOS (CodArt_A, CodProv_P_A, Descripcion_A, Stock_A, PU_A)
SELECT 'A001', 'P001', 'Paracetamol 500mg comprimidos x 20', 150, 120.50 UNION
SELECT 'A002', 'P001', 'Ibuprofeno 400mg comprimidos x 30', 200, 185.75 UNION
SELECT 'A003', 'P002', 'Jarabe para la tos mentolado 120ml', 80, 320.00 UNION
SELECT 'A004', 'P002', 'Omeprazol 20mg cápsulas x 14', 300, 250.40 UNION
SELECT 'A005', 'P003', 'Crema hidratante con vitamina E 50g', 120, 180.90 UNION
SELECT 'A006', 'P004', 'Termómetro digital profesional', 50, 890.00 UNION
SELECT 'A007', 'P005', 'Curitas adhesivas x 100 unidades', 500, 95.30 UNION
SELECT 'A008', 'P006', 'Alcohol en gel 250ml', 400, 150.25 UNION
SELECT 'A009', 'P007', 'Tiras reactivas para diabetes x 50', 75, 1200.00 UNION
SELECT 'A010', 'P008', 'Tensiómetro de brazo digital', 30, 4500.00
GO


-- Consulta para verificar los datos
SELECT * FROM ARTICULOS
GO

INSERT INTO CLIENTES (Dni_C, Nombre_C, Apellido_C, Direccion_C, Telefono_C)
SELECT '30123456', 'María', 'González', 'Av. San Martín 1234', '11-2345-6789' UNION
SELECT '30234567', 'Juan', 'Pérez', 'Calle Rivadavia 567', '11-3456-7890' UNION
SELECT '30345678', 'Carlos', 'López', 'Belgrano 890', '11-4567-8901' UNION
SELECT '30456789', 'Ana', 'Martínez', 'Sarmiento 123', '11-5678-9012' UNION
SELECT '30567890', 'Lucía', 'Rodríguez', 'Mitre 456', '11-6789-0123' UNION
SELECT '30678901', 'Pedro', 'Fernández', 'Alvear 789', '11-7890-1234' UNION
SELECT '30789012', 'Sofía', 'García', 'Urquiza 012', '11-8901-2345' UNION
SELECT '30890123', 'Diego', 'Sánchez', 'Pueyrredón 345', '11-9012-3456' UNION
SELECT '30901234', 'Laura', 'Díaz', 'Alem 678', '11-0123-4567' UNION
SELECT '31012345', 'Jorge', 'Romero', 'Moreno 901', '11-1234-5678'
GO

-- Consulta para verificar los datos
SELECT * FROM CLIENTES ORDER BY Apellido_C, Nombre_C
GO

INSERT INTO CUENTAS (CodCuenta_CU, Dni_CL_CU, LimiteCuenta_CU, SaldoCuenta_CU)
SELECT 'C001', '30123456', 50000.00, 12500.00 UNION
SELECT 'C002', '30234567', 30000.00, -5000.00 UNION
SELECT 'C003', '30345678', 75000.00, 25000.00 UNION
SELECT 'C004', '30456789', 100000.00, 0.00 UNION
SELECT 'C005', '30567890', 25000.00, 18000.00 UNION
SELECT 'C006', '30678901', 60000.00, -12000.00 UNION
SELECT 'C007', '30789012', 40000.00, 40000.00 UNION
SELECT 'C008', '30890123', 80000.00, 30000.00 UNION
SELECT 'C009', '30901234', 35000.00, -8000.00 UNION
SELECT 'C010', '31012345', 90000.00, 45000.00
GO

SELECT * FROM CUENTAS

-- Insertamos facturas (el ID se auto-genera)
INSERT INTO FACTURAS (CodCuenta_CU_FA, TotalFactura_FA, FechaFactura_FA)
SELECT 'C001', 3250.50, 2023-01-15 UNION
SELECT 'C002', 1800.00, 2023-01-16 UNION
SELECT 'C003', 5420.75, 2023-01-17 UNION
SELECT 'C004', 1200.00, 2023-01-18 UNION
SELECT 'C005', 3750.25, GETDATE()  -- Factura con fecha actual
GO

SELECT * FROM FACTURAS

-- Detalles para Factura 1 (3 artículos)
INSERT INTO DETALLE_FACTURAS (CodFactura_FA_DF, CodArt_A_DF, CodProv_A_DF, Cantidad_DF, PU_DF)
SELECT 1, 'A001', 'P001', 2, 120.50 UNION
SELECT 1, 'A003', 'P002', 1, 320.00 UNION
SELECT 1, 'A005', 'P003', 3, 180.90

-- Detalles para Factura 2 (2 artículos)
INSERT INTO DETALLE_FACTURAS (CodFactura_FA_DF, CodArt_A_DF, CodProv_A_DF, Cantidad_DF, PU_DF)
SELECT 2, 'A002', 'P001', 5, 185.75 UNION
SELECT 2, 'A007', 'P005', 8, 95.30

-- Detalles para Factura 3 (4 artículos)
INSERT INTO DETALLE_FACTURAS (CodFactura_FA_DF, CodArt_A_DF, CodProv_A_DF, Cantidad_DF, PU_DF)
SELECT 3, 'A004', 'P002', 4, 250.40 UNION
SELECT 3, 'A006', 'P004', 2, 890.00 UNION
SELECT 3, 'A009', 'P007', 1, 1200.00 UNION
SELECT 3, 'A010', 'P008', 1, 4500.00

-- Detalles para Factura 4 (1 artículo)
INSERT INTO DETALLE_FACTURAS (CodFactura_FA_DF, CodArt_A_DF, CodProv_A_DF, Cantidad_DF, PU_DF)
SELECT 4, 'A001', 'P001', 10, 120.50

-- Detalles para Factura 5 (3 artículos)
INSERT INTO DETALLE_FACTURAS (CodFactura_FA_DF, CodArt_A_DF, CodProv_A_DF, Cantidad_DF, PU_DF)
SELECT 5, 'A003', 'P002', 2, 320.00 UNION
SELECT 5, 'A005', 'P003', 5, 180.90 UNION
SELECT 5, 'A008', 'P006', 15, 150.25
GO

SELECT *  FROM DETALLE_FACTURAS

