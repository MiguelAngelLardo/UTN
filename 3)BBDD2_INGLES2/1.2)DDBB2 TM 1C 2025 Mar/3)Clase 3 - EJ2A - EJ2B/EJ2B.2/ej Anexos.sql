Use EJ02B22025

--2.b Informe todas las facturas realizadas a un determinado cliente, indicando el apellido del cliente.
Select * from Ventas
Select * from Clientes
select NumFact_V, Nombre_V
from Ventas Inner Join Clientes 
on Clientes.DNI_C = Ventas.DNI_C_V
WHERE Nombre_C = 'Carlos Pérez'

--2.c Informe todos los productos de un determinado proveedor, indicando la razón social del proveedor
--hay q mostrar la descripcion de la tabla articulo
Select * FROM Articulos
Select * FROM ProveedoresxArticulos
Select * From Proveedores

--Forma 1
Select Nombre_AR FROM (Articulos 
Inner Join ProveedoresxArticulos 
on Articulos.CodArt_AR = ProveedoresxArticulos.CodArt_AR_PxA)

Inner Join Proveedores
on Proveedores.Cuit_PR = ProveedoresxArticulos.Cuit_PR_PxA
WHERE RazonSocial_PR = 'Tecnología Avanzada S.A.'

--Forma 2
Select Nombre_AR From Articulos
Inner Join ProveedoresxArticulos 
Inner Join Proveedores 
on Proveedores.Cuit_PR = ProveedoresxArticulos.Cuit_PR_PxA
on Articulos.CodArt_AR = ProveedoresxArticulos.CodArt_AR_PxA
WHERE RazonSocial_PR = 'Tecnología Avanzada S.A.'
