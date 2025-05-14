USE EJ04A2025
GO

--4.1. Realizar una consulta que informe nombre del medicamento, nombre del laboratorio y unidades en stock.
SELECT 
	Nombre_M as NombreMedicamento, 
	Stock_M as CantidadSTockMedicamento,
	Nombre_L as NombreLaboratorio
FROM 
	MEDICAMENTOS 
INNER JOIN 
	LABORATORIOS 
on LABORATORIOS.CodLab_L = MEDICAMENTOS.CodLab_L_M 

select * from LABORATORIOS
select * from MEDICAMENTOS

--4.2.Realizar una consulta que informe nombre, unidades disponibles y precio unitario de los artículos de un determinado laboratorio.
SELECT
	Nombre_M as NombreMedicamento,
	Stock_M as UnidadesDisponibles,
	Precio_M as PrecioUnitario
FROM	
	MEDICAMENTOS
INNER JOIN
	LABORATORIOS 
on LABORATORIOS.CodLab_L = MEDICAMENTOS.CodLab_L_M
WHERE
	LABORATORIOS.Nombre_L = 'Bayer Argentina'

select * from LABORATORIOS
select * from MEDICAMENTOS

--4.3.Realizar una consulta que informe nombre del medicamento, unidades en stock, 
--nombre y teléfono del laboratorio de todos aquellos productos que pasen su punto de pedido.
SELECT 
	Nombre_M as NombreMedicamento,
	Stock_M as StockMedicamento,
	Nombre_L as NombreLaboratorio,
	Telefono_L as TelLaboratorio
FROM 
	MEDICAMENTOS m
INNER JOIN 
	LABORATORIOS l ON l.CodLab_L = m.CodLab_L_M
WHERE 
	m.Stock_M < m.PtoPedido_M
select * from LABORATORIOS
select * from MEDICAMENTOS
	
--4.4. Realizar una consulta que informe la mayor venta por tipo de medicamento (jarabe, comprimido, pomada, etc.).
SELECT 
	tm.Descripcion_TM,
	(df.Cantidad_DET * df.PU_DET) as MayorVenta --si pongo MAX me muesta el mayor
FROM
	FACTURAS f
INNER JOIN 
	DETALLE_FACTURAS df on f.ID_Fact_F = df.ID_Fact_F_DET
INNER JOIN 
	MEDICAMENTOS m on m.CodMed_M = df.CodMed_M_DET
INNER JOIN
	TIPO_MEDICAMENTOS tm on tm.CodTipoMed_TM = m.CodTipoMed_TM_M

SELECT 
	tm.Descripcion_TM,
	MAX(df.Cantidad_DET * df.PU_DET) as MayorVenta --si pongo MAX me muesta el mayor
FROM
	FACTURAS f
INNER JOIN 
	DETALLE_FACTURAS df on f.ID_Fact_F = df.ID_Fact_F_DET
INNER JOIN 
	MEDICAMENTOS m on m.CodMed_M = df.CodMed_M_DET
INNER JOIN
	TIPO_MEDICAMENTOS tm on tm.CodTipoMed_TM = m.CodTipoMed_TM_M
GROUP BY -- es funcion de agregado, va con el MAX
    tm.Descripcion_TM

SELECT 
	tm.Descripcion_TM,
	MAX(df.Cantidad_DET * df.PU_DET) as MayorVenta --si pongo MAX me muesta el mayor
FROM
	FACTURAS f
INNER JOIN 
	DETALLE_FACTURAS df on f.ID_Fact_F = df.ID_Fact_F_DET
INNER JOIN 
	MEDICAMENTOS m on m.CodMed_M = df.CodMed_M_DET
INNER JOIN
	TIPO_MEDICAMENTOS tm on tm.CodTipoMed_TM = m.CodTipoMed_TM_M
GROUP BY -- es funcion de agregado, va con el MAX
		tm.Descripcion_TM
ORDER BY 
    MayorVenta DESC;

