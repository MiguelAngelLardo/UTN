USE EJ06A2025
GO

--1.Realice un procedimiento almacenado que devuelva los artículos mayores de una determinada cantidad en stock.

CREATE PROCEDURE SP_CANTIDADMINIMASTOCK
@cantStockMin int
AS
select CodArt_A, CodProv_P_A, Descripcion_A, Stock_A, CodProv_P, RazonSocial_P 
from ARTICULOS 
inner join PROVEEDORES
on PROVEEDORES.CodProv_P = ARTICULOS.CodProv_P_A
where Stock_A > @cantStockMin 

EXECUTE SP_CANTIDADMINIMASTOCK 80

--2.Informe la razón social del proveedor, el artículo y la inversión hasta el momento en stock (stock * precio unitario) de un artículo determinado. Cree procedimiento almacenado.

CREATE PROCEDURE SP_INVERSIONPORARTICULO
	@descripcionArticulo varchar(100)
AS
Select 
	RazonSocial_P, 
	Descripcion_A, 
	Stock_A, PU_A, 
	(Stock_A*PU_A) as Inversion
from 
	PROVEEDORES 
	Inner join ARTICULOS
	on PROVEEDORES.CodProv_P = ARTICULOS.CodProv_P_A
where 
  Descripcion_A LIKE '%' + @descripcionArticulo + '%'
ORDER BY
 (Stock_A * PU_A) DESC


EXECUTE SP_INVERSIONPORARTICULO 'Tensiómetro de brazo digital'

-----------------------------------------------------------------------------

CREATE PROCEDURE SP_INVERSIONPORARTICULO2
	@codArt char(4),
	@codProv char(4)
AS
select
	RazonSocial_P,
	Descripcion_A,
	(Stock_A * PU_A) AS Inversion
FROM
	PROVEEDORES	inner join ARTICULOS
on
	PROVEEDORES.CodProv_P = ARTICULOS.CodProv_P_A
where
	CodArt_A = @codArt AND CodProv_P_A = @codProv
GO

EXECUTE SP_INVERSIONPORARTICULO2 'A006', 'P004'

--3.Informe nombre y apellido en un solo campo llamado “nombre completo” de los clientes que realizaron una compra de una cantidad mayor a 100 unidades de un artículo. Cree procedimiento almacenado.

CREATE PROCEDURE SP_MAYOR5UNIDADES
AS
SELECT 
	Nombre_C + ' ' + Apellido_C AS [Nombre Completo],
	Cantidad_DF,
	FechaFactura_FA
FROM
	CLIENTES
Inner Join
	CUENTAS on CLIENTES.Dni_C = CUENTAS.Dni_CL_CU
Inner Join
	FACTURAS on CUENTAS.CodCuenta_CU = FACTURAS.CodCuenta_CU_FA 
Inner Join
	DETALLE_FACTURAS on FACTURAS.CodFactura_FA = DETALLE_FACTURAS.CodFactura_FA_DF
where 
	Cantidad_DF > 5

EXECUTE SP_MAYOR5UNIDADES

--4.Crear un procedimiento almacenado con cualquier nombre y cualquier selección de cualquier tabla y elimínelo desde una consulta utilizando la sentencia correspondiente.

CREATE PROCEDURE SP_EJEMPLO_ELIMINACION
AS
 -- Consulta simple de ejemplo
 SELECT TOP 5 
  CodArt_A AS 'Código',
  Descripcion_A AS 'Artículo',
  Stock_A AS 'Stock'
FROM 
	ARTICULOS
ORDER BY 
	Stock_A DESC

GO
DROP PROCEDURE SP_EJEMPLO_ELIMINACION
GO

--5.Crear una tabla llamada “TablaDePrueba” con tres campos nchar de 8 no nulos: Dni, nombre y apellido. El campo Dni será clave

CREATE TABLE TablaPrueba(
	Dni_prueba nchar(8) NOT NULL,
	Nombre_prueba nchar(8) NOT NULL,
	Apellido_Prueba nchar(8) NOT NULL,
	CONSTRAINT PK_TablaPrueba Primary Key (Dni_prueba)
)
GO

--6.Insertar un registro en la tabla anterior con Dni = 12345, nombre = Ariel y apellido = Herrera

INSERT INTO TablaPrueba(Dni_prueba, Nombre_prueba, Apellido_Prueba)
Select '12345', 'Ariel', 'Herrera'

select * from TablaPrueba

--7. Utilizando la misma base de datos, agregue dos tablas para registrar pedidos de artículos que se realicen a los proveedores, donde se almacene la cantidad, la fecha, el estado y otros datos que considere necesarios.  
CREATE TABLE PEDIDOS (
  CodPedido_PED INT IDENTITY(0,1),
  CodProv_P_PED CHAR(4) NOT NULL,  -- Relación 1:M con PROVEEDORES (un pedido es a un solo proveedor)
  FechaPedido_PED DATETIME NOT NULL DEFAULT GETDATE(),
  FechaEntrega_PED DATETIME NULL,
  Estado_PED VARCHAR(20) NOT NULL CHECK (Estado_PED IN ('Pendiente', 'Enviado', 'Recibido', 'Cancelado')),
	CONSTRAINT PK_PEDIDOS Primary Key (CodPedido_PED),
  CONSTRAINT FK_PEDIDOS_PROVEEDORES FOREIGN KEY (CodProv_P_PED) REFERENCES PROVEEDORES(CodProv_P)
)
GO

CREATE TABLE DETALLE_PEDIDOS (
  CodPed_PED_DP INT NOT NULL,          -- FK a PEDIDOS (parte de PK compuesta)
  CodArt_A_DP CHAR(4) NOT NULL,        -- FK a ARTICULOS (parte de PK compuesta)
  CodProv_A_DP CHAR(4) NOT NULL,       -- FK redundante necesaria para la relación con ARTICULOS
  Cantidad_DP INT NOT NULL,
  PU_DP MONEY NOT NULL,                -- Precio unitario al momento del pedido
  Recibido_DP bit not null, 
  CONSTRAINT PK_DETALLE_PEDIDOS PRIMARY KEY (CodPed_PED_DP, CodArt_A_DP, CodProv_A_DP),
  CONSTRAINT FK_DP_PEDIDOS FOREIGN KEY (CodPed_PED_DP) REFERENCES PEDIDOS(CodPedido_PED),
  CONSTRAINT FK_DP_ARTICULOS FOREIGN KEY (CodArt_A_DP, CodProv_A_DP) REFERENCES ARTICULOS(CodArt_A, CodProv_P_A)
)
GO

--8. Cargue las tablas con datos. 

INSERT INTO PEDIDOS (CodProv_P_PED, FechaPedido_PED, FechaEntrega_PED, Estado_PED)
SELECT 'P001', 2023-01-10, NULL, 'Pendiente' UNION
SELECT 'P002', 2023-01-11, 2023-01-15, 'Recibido' UNION
SELECT 'P003', 2023-01-12, NULL, 'Enviado' UNION
SELECT 'P001', 2023-01-13, 2023-01-18, 'Recibido' UNION
SELECT 'P004', 2023-01-14, NULL, 'Pendiente' UNION
SELECT 'P002', 2023-01-15, 2023-01-20, 'Recibido' UNION
SELECT 'P005', 2023-01-16, NULL, 'Cancelado' UNION
SELECT 'P003', 2023-01-17, 2023-01-22, 'Recibido' UNION
SELECT 'P001', 2023-01-18, NULL, 'Enviado' UNION
SELECT 'P004', 2023-01-19, 2023-01-25, 'Recibido'
GO

select * from PEDIDOS

INSERT INTO DETALLE_PEDIDOS (CodPed_PED_DP, CodArt_A_DP, CodProv_A_DP, Cantidad_DP, PU_DP, Recibido_DP)
SELECT 4, 'A001', 'P001', 50, 120.50, 1 UNION ALL
SELECT 4, 'A003', 'P002', 30, 320.00, 0 UNION ALL
SELECT 5, 'A002', 'P001', 25, 185.75, 1 UNION ALL
SELECT 5, 'A007', 'P005', 40, 95.30, 1 UNION ALL
SELECT 6, 'A004', 'P002', 15, 250.40, 0 UNION ALL
SELECT 7, 'A006', 'P004', 10, 890.00, 1 UNION ALL
SELECT 8, 'A009', 'P007', 5, 1200.00, 0 UNION ALL
SELECT 9, 'A010', 'P008', 8, 4500.00, 1 UNION ALL
SELECT 10, 'A005', 'P003', 20, 180.90, 0 UNION ALL
SELECT 11, 'A008', 'P006', 35, 150.25, 1
GO

select * from DETALLE_PEDIDOS

--9. Realice una actualización del stock de un determinado artículo a una cantidad cualquiera desde una consulta.  
select * from ARTICULOS

UPDATE ARTICULOS
SET Stock_A = 10000
where CodArt_A = 'A001'AND CodProv_P_A = 'P001'
GO

Select *from Articulos

--10. Marque un determinado pedido como cumplido
select * from PEDIDOS

UPDATE PEDIDOS
set Estado_PED = 'Recibido',
		FechaEntrega_PED = getdate()
Where CodPedido_PED = 4
go

select * from PEDIDOS

--11. Informe las tres primeras letras de la descripción de un artículo y su cantidad en stock.
--uso funcion left
SELECT
	LEFT(Descripcion_A, 3),
	Descripcion_A,
	Stock_A
FROM
	ARTICULOS

select * from ARTICULOS

--12. Consulte la existencia de la tabla pedidos, si no existiera créela. 
--usa if + schema

IF exists (select * from INFORMATION_SCHEMA.TABLES where TABLE_NAME = 'PEDIDOS')
BEGIN	
	Print 'Ya existe'
	Select 'Ya existe'
END
ELSE
BEGIN
	Print 'Hay que crearla'
	Select 'Hay que crearla' AS columna
END


if exists (select * from INFORMATION_SCHEMA.TABLES where TABLE_NAME = 'PEDIDOS')
BEGIN
	print 'ya existe'
END
ELSE
BEGIN
  PRINT 'Creando tabla PEDIDOS...'
	CREATE TABLE PEDIDOS (
  CodPedido_PED INT IDENTITY(1,1),
  CodProv_P_PED CHAR(4) NOT NULL,  -- Relación 1:M con PROVEEDORES (un pedido es a un solo proveedor)
  FechaPedido_PED DATETIME NOT NULL DEFAULT GETDATE(),
  FechaEntrega_PED DATETIME NULL,
  Estado_PED VARCHAR(20) NOT NULL CHECK (Estado_PED IN ('Pendiente', 'Enviado', 'Recibido', 'Cancelado')),
	CONSTRAINT PK_PEDIDOS Primary Key (CodPedido_PED),
  CONSTRAINT FK_PEDIDOS_PROVEEDORES FOREIGN KEY (CodProv_P_PED) REFERENCES PROVEEDORES(CodProv_P)
  )
  PRINT 'Tabla PEDIDOS creada exitosamente'
END
GO

--13. Cree un procedimiento almacenado que introduzca un registro en la tabla 
--pedidos de cualquier artículo con la fecha del momento de la registración.

CREATE PROCEDURE SP_INSERTARPEDIDO
 @codProv CHAR(4),
 @fechaEntrega DATETIME = NULL,  -- Parámetro opcional
 @estado VARCHAR(20) = 'Pendiente'  -- Valor por defecto
AS
INSERT INTO PEDIDOS(
	CodProv_P_PED,
  FechaPedido_PED,  -- Se registrará automáticamente
  FechaEntrega_PED,
  Estado_PED
)
select
	@codProv, 
  GETDATE(),  -- Fecha y hora actual del sistema
  @fechaEntrega, 
  @estado

select * from PEDIDOS
EXECUTE SP_INSERTARPEDIDO 'P006'
select * from PEDIDOS

select * from PEDIDOS
EXECUTE SP_INSERTARPEDIDO 'P009','31-12-25', 'Enviado' -- 2025-12-31 00:00:00.000
select * from PEDIDOS

EXECUTE SP_INSERTARPEDIDO 'P009','30-8-26 00:20:20', 'Enviado' --2026-08-30 00:20:20.000
select * from PEDIDOS
select * from PEDIDOS

--14. Realice una consulta que informe todos los proveedores con razón social en mayúscula y los contactos en minúsculas. 

SELECT
	UPPER(RazonSocial_P),
	LOWER(Contacto_P)
FROM		
	PROVEEDORES

--15. Crear un trigger en la tabla Detalle de ventas o Detalle de Facturas
--llamado SUMATOTAL que por cada artículo agregado al detalle 
--multiplique el precio unitario por la cantidad y sume el resultado al total en la tabla Facturas o Ventas. 

CREATE TRIGGER TR_SUMATOTAL
on DETALLE_FACTURAS --el triger esta alojado aca
AFTER INSERT

AS --idem SP
BEGIN --va hasta el end
SET NOCOUNT ON; --apago mensajes

UPDATE FACTURAS
SET TotalFactura_FA = TotalFactura_FA + (SELECT Cantidad_DF * PU_DF from inserted)
where CodFactura_FA = (select CodFactura_FA_DF from inserted)
END

select * from FACTURAS
select * from DETALLE_FACTURAS
INSERT INTO DETALLE_FACTURAS (CodFactura_FA_DF, CodArt_A_DF, CodProv_A_DF, Cantidad_DF, PU_DF)
select 2, 'A009', 'P007', 2, 2.50
select * from FACTURAS
select * from DETALLE_FACTURAS


--16. Crear un trigger en la tabla Detalle de ventas o Detalle de Facturas 
--llamado BAJASTOCK que por cada artículo agregado al 
--detalle descuente la cantidad en la tabla correspondiente que lleve el stock. 

CREATE TRIGGER TR_BAJASTOCK
on DETALLE_FACTURAS --el triger esta alojado aca
AFTER INSERT

AS --idem SP
BEGIN --va hasta el end
SET NOCOUNT ON; --apago mensajes

UPDATE ARTICULOS
SET Stock_A = Stock_A - (SELECT Cantidad_DF from inserted)
where 
	CodArt_A = (select CodArt_A_DF from inserted)
	and
	CodProv_P_A = (select CodProv_A_DF from inserted)
END

select * from DETALLE_FACTURAS
Select *from Articulos
insert into DETALLE_FACTURAS (CodFactura_FA_DF, CodArt_A_DF, CodProv_A_DF, Cantidad_DF, PU_DF)
select 4, 'A002', 'P001', 5, 1.50
select * from DETALLE_FACTURAS
Select *from Articulos