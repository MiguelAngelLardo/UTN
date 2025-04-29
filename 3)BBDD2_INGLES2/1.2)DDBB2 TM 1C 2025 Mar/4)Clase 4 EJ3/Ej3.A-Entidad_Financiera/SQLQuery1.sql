USE EJ03A2025
--1. Realizar una consulta que informe Sucursales
Select CodSuc_SU, Direccion_SU FROM SUCURSALES
GO

--2.Realizar una consulta que informe los datos de un cliente específico con su respectiva sucursal
Select DISTINCT CodSuc_CU_CUxCL, DNI_CL_CUxCL, Nombre_CL 
FROM CUENTASxCLIENTES Inner Join Clientes
ON CUENTASxCLIENTES.DNI_CL_CUxCL = CLIENTES.DNI_CL
WHERE CLIENTES.DNI_CL = 11222333
GO

select * from CUENTASxCLIENTES
select * from CLIENTES

--3.Realizar una consulta que informe los datos de un cliente específico con sus respectivas cuentas
Select CodCuenta_CU_CUxCL, CodSuc_CU_CUxCL, DNI_CL_CUxCL, Nombre_CL 
FROM CUENTASxCLIENTES Inner Join Clientes
ON CUENTASxCLIENTES.DNI_CL_CUxCL = CLIENTES.DNI_CL
WHERE CLIENTES.DNI_CL = 11222333
GO

--4. Realizar una consulta que informe la mayor transacción y los datos del cliente
SELECT Monto_TR as MAX_MONTO 
FROM TRANSACCIONES Inner Join CLIENTES 
ON CLIENTES.DNI_CL = TRANSACCIONES.DNI_CUxCL_TR
where Monto_TR = (select MAX (Monto_TR) from TRANSACCIONES)

select * from clientes 
select * from transacciones
GO

--5.Realizar una consulta que informe los datos de un cliente específico con sus respectivas cuentas, sucursales y saldos.
Select dni_cl, Nombre_CL, Apellido_CL, CodCuenta_CU, CodSuc_SU_CU, Saldo_CU 
from clientes inner join CUENTASxCLIENTES
on CLIENTES.DNI_CL = CUENTASxCLIENTES.DNI_CL_CUxCL
inner join CUENTAS
on CUENTAS.CodSuc_SU_CU = CUENTASxCLIENTES.CodSuc_CU_CUxCL AND CUENTAS.CodCuenta_CU = CUENTASxCLIENTES.CodCuenta_CU_CUxCL
WHERE CLIENTES.DNI_CL = 11222333

select * from clientes
select * from CUENTASxCLIENTES
select * from CUENTAS
GO

/*Agregar en la tabla clientes del Ejercicio 03 los siguientes datos:
Clientes en los campos Nombre y Apellido Mario Silva, Alberto Castro, 
Mercedes López, María Landa, Alfredo Gómez*/

--6.Informe Nombre y apellido de todos los clientes cuyo nombre comience con la primera letra 
--distinta de ‘A’ y la segunda letra sea una ‘e’ seguida por cualquier cadena.
select Nombre_CL, Apellido_CL from CLIENTES
WHERE Nombre_CL LIKE '[^A]e%'
select * from CLIENTES 
GO

--7.Informe Nombre y apellido de todos los clientes cuyo apellido no comience con ‘S’ o ‘L
select Nombre_CL, Apellido_CL 
from CLIENTES
WHERE Apellido_CL NOT LIKE 'S%' 
    AND Apellido_CL NOT LIKE 'L%'

select Nombre_CL, Apellido_CL 
from CLIENTES
WHERE Apellido_CL LIKE '[^SL]%' 

select * from CLIENTES 