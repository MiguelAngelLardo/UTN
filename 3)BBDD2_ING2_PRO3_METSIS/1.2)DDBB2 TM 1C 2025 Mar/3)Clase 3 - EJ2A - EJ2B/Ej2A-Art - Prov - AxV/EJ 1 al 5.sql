USE EJ022025
GO

/*2.1 Realizar una consulta que informe razón social,
ciudad y provincia de las empresas ubicadas en Buenos Aires. */
SELECT RAZONSOCIAL_PR, CIUDAD_PR, PROVINCIA_PR FROM PROVEEDORES
WHERE PROVINCIA_PR = 'Buenos Aires'
GO

/*2.2
Realizar una consulta que informe el código de artículo y el nombre, 
ordenados según código de artículo en forma descendente.
*/

SELECT CODART_AR, NOMBRE_AR 
FROM articulos 
ORDER BY CODART_AR DESC
GO

/*2.3. Realizar una consulta que informe las provincias en las que hay proveedores. */
SELECT PROVINCIA_PR FROM PROVEEDORES
SELECT DISTINCT  PROVINCIA_PR FROM PROVEEDORES
GO

/*2.4. Realizar una consulta que informe el nombre de los artículos 
y la cantidad de dinero de estos en stock (cantidad X precio unitario).*/
SELECT * FROM ARTICULOS
SELECT NOMBRE_AR AS Nom, CANTIDAD_AR * PRECIOUNIT_AR AS TOTAL_STOCK FROM ARTICULOS 
GO

/*2.5. Realizar una consulta que informe nombre, 
cantidad y precio unitario de los artículos de un determinado proveedor. 
*/

Select NOMBRE_AR, CANTIDAD_AR, PRECIOUNIT_AR From ARTICULOS
Inner Join ARTICULOSxPROVEEDORES 
on ARTICULOS.CODART_AR = ARTICULOSxPROVEEDORES.CODART_AR_AXP

Select ARTICULOSxPROVEEDORES.CUIT_PR_AXP ,NOMBRE_AR, CANTIDAD_AR, PRECIOUNIT_AR From ARTICULOS
Inner Join ARTICULOSxPROVEEDORES 
on ARTICULOS.CODART_AR = ARTICULOSxPROVEEDORES.CODART_AR_AXP 

Select ARTICULOSxPROVEEDORES.CUIT_PR_AXP ,NOMBRE_AR, CANTIDAD_AR, PRECIOUNIT_AR From ARTICULOS
Inner Join ARTICULOSxPROVEEDORES 
on ARTICULOS.CODART_AR = ARTICULOSxPROVEEDORES.CODART_AR_AXP 
where CUIT_PR_AXP = '33987654321'