
USE master
GO

CREATE DATABASE [2doTrabajoIntegrador2025]
ON
(NAME=T_I_2_DAT,
FILENAME='C:\BASES\TRABAJO_INTEGRADOR_2.mdf')
GO

USE [2doTrabajoIntegrador2025]
GO

CREATE TABLE PROVINCIAS
(
    codProvincia_Pcia CHAR(4) NOT NULL,
    descripcion_Pcia VARCHAR(100) NOT NULL,
    CONSTRAINT PK_PROVINCIAS PRIMARY KEY (codProvincia_Pcia)
)
GO

CREATE TABLE CIUDADES
(
    codProvincia_Ciud CHAR(4) NOT NULL,
	codPostal_Ciud CHAR(4) NOT NULL,
    descripcion_Ciud VARCHAR(100) NOT NULL,
    CONSTRAINT PK_CIUDADES PRIMARY KEY (codProvincia_Ciud,codPostal_Ciud),
    CONSTRAINT FK_CIUDADES_PROVINCIAS FOREIGN KEY (codProvincia_Ciud) REFERENCES PROVINCIAS(codProvincia_Pcia)
)
GO

CREATE TABLE GENEROS
(
    cod_Gen CHAR(4) NOT NULL,
    descripcion_Gen VARCHAR(100) NOT NULL,
    CONSTRAINT PK_GENEROS PRIMARY KEY (cod_Gen)
)
GO

CREATE TABLE CLIENTES
(
    dni_Cl CHAR(20) NOT NULL,
    nombre_Cl VARCHAR(100) NOT NULL,
    apellido_Cl VARCHAR(100) NOT NULL,
    direccion_Cl VARCHAR(100) NOT NULL,
    codProvincia_Cl CHAR(4) NOT NULL,
	codPostal_Cl CHAR(4) NOT NULL,
    fechaNacimiento_Cl DATE NOT NULL,
    codGen_Cl CHAR(4) NOT NULL,
    mail_Cl VARCHAR(60),
    CONSTRAINT PK_CLIENTES PRIMARY KEY (dni_Cl),
    CONSTRAINT FK_CLIENTES_CIUDADES FOREIGN KEY (codProvincia_Cl,codPostal_Cl) REFERENCES CIUDADES(codProvincia_Ciud,codPostal_Ciud),
    CONSTRAINT FK_CLIENTES_GENEROS FOREIGN KEY (codGen_Cl) REFERENCES GENEROS(cod_Gen)
)
GO

CREATE TABLE VENDEDORES
(
    legajo_Vd CHAR(4) NOT NULL,
    nombre_Vd VARCHAR(100) NOT NULL,
    apellido_Vd VARCHAR(100) NOT NULL,
    direccion_Vd VARCHAR(100) NOT NULL,
    codProvincia_Vd CHAR(4) NOT NULL,
	codPostal_Vd CHAR(4) NOT NULL,
    fechaNacimiento_Vd DATE NOT NULL,
    codGen_Vd CHAR(4) NOT NULL,
    fechaIngreso_Vd DATE NOT NULL,
    CONSTRAINT PK_VENDEDORES PRIMARY KEY (legajo_Vd),
    CONSTRAINT FK_VENDEDORES_BARRIOS FOREIGN KEY (codProvincia_Vd,codPostal_Vd) REFERENCES CIUDADES(codProvincia_Ciud,codPostal_Ciud),
    CONSTRAINT FK_VENDEDORES_GENEROS FOREIGN KEY (codGen_Vd) REFERENCES GENEROS(cod_Gen)
)
GO

CREATE TABLE TELEFONOSxCLIENTES
(
    dniCliente_TxC CHAR(20) NOT NULL,
    telefono_TxC VARCHAR(20) NOT NULL,
    CONSTRAINT PK_TELEFONOSxCLIENTES PRIMARY KEY (dniCliente_TxC,telefono_TxC),
    CONSTRAINT FK_TELEFONOSxCLIENTES_CLIENTES FOREIGN KEY (dniCliente_TxC) REFERENCES CLIENTES(dni_Cl)
)
GO

CREATE TABLE PROVEEDORES
(
    cod_Prov CHAR(7) NOT NULL,
    cuit_Prov CHAR(11) NOT NULL,
    razonSocial_Prov VARCHAR(100) NOT NULL,
    direccion_Prov VARCHAR(100) NOT NULL,
    codProvincia_Prov CHAR(4) NOT NULL,
	codPostal_Prov CHAR(4) NOT NULL,
    web_Prov VARCHAR(100) NOT NULL,
    telefono_Prov VARCHAR(20) NOT NULL,
    mail_Prov VARCHAR(60) NOT NULL,
    CONSTRAINT PK_PROVEEDORES PRIMARY KEY (cod_Prov),
    CONSTRAINT FK_PROVEEDORES_CIUDADES FOREIGN KEY (codProvincia_Prov,codPostal_Prov) REFERENCES CIUDADES(codProvincia_Ciud,codPostal_Ciud),
    CONSTRAINT UK_PROVEEDORES UNIQUE (cuit_Prov)
)
GO

CREATE TABLE ARTICULOS
(
    cod_Art CHAR(7) NOT NULL,
    descripcion_Art VARCHAR(100) NOT NULL,
    stock_Art INT DEFAULT 0 CHECK(stock_Art >= 0),
    precioUnitario_Art DECIMAL(8,2) DEFAULT 0 CHECK(precioUnitario_Art >= 0),
    codProv_Art CHAR(7) NOT NULL,
    CONSTRAINT PK_ARTICULOS PRIMARY KEY (cod_Art),
    CONSTRAINT FK_ARTICULOS_PROVEEDORES FOREIGN KEY (codProv_Art) REFERENCES PROVEEDORES(cod_Prov)
)
GO

CREATE TABLE VENTAS
(
    id_Venta INT NOT NULL IDENTITY(1,1),
    codVendedor_Venta CHAR(4) NOT NULL,
    Fecha_Venta DATE NOT NULL,
    Hora_Venta TIME NOT NULL,
    dniCliente_Venta CHAR(20) NOT NULL,
    total_Venta DECIMAL(8,2) DEFAULT 0 CHECK(total_Venta >= 0),
    CONSTRAINT PK_VENTAS PRIMARY KEY (id_Venta),
    CONSTRAINT FK_VENTAS_VENDEDORES FOREIGN KEY (codVendedor_Venta) REFERENCES VENDEDORES(legajo_Vd),
    CONSTRAINT FK_VENTAS_CLIENTES FOREIGN KEY (dnicliente_Venta) REFERENCES CLIENTES(dni_Cl) 
)

CREATE TABLE DETALLE_VENTAS
(
    idVenta_DV INT NOT NULL,
    codArt_DV CHAR(7) NOT NULL,
    cantidadArt_DV INT DEFAULT 0 CHECK(cantidadArt_DV > 0),
    precioUnitario_DV DECIMAL(8,2) DEFAULT 0 CHECK(precioUnitario_DV >= 0),
    CONSTRAINT PK_DETALLE_VENTAS PRIMARY KEY (idVenta_DV,codArt_DV),
    CONSTRAINT FK_DETALLE_VENTAS_VENTAS FOREIGN KEY (idVenta_DV) REFERENCES VENTAS(id_Venta),
    CONSTRAINT FK_DETALLE_VENTAS_ARTICULOS FOREIGN KEY (codArt_DV) REFERENCES ARTICULOS(cod_Art)
)
GO


INSERT INTO PROVINCIAS(codProvincia_Pcia, descripcion_Pcia)
SELECT 'BSAS','Buenos Aires' UNION
SELECT 'CORD','Cordoba' UNION
SELECT 'STFE','Santa Fe' UNION
SELECT 'RIOJ','La Rioja' UNION
SELECT 'NEUQ','Neuquen' UNION
SELECT 'PAMP','La Pampa' UNION
SELECT 'SALT','Salta' UNION
SELECT 'FORM','Formosa' UNION
SELECT 'JUJU','Jujuy'
GO


INSERT INTO CIUDADES(codProvincia_Ciud,codPostal_Ciud,descripcion_Ciud)
SELECT 'BSAS', '1900','La Plata' UNION
SELECT 'BSAS', '1870','Avellaneda' UNION
SELECT 'BSAS', '1878','Quilmes' UNION
SELECT 'BSAS', '1888','Florencio Varela' UNION
SELECT 'BSAS', '1300','Azul' UNION
SELECT 'STFE', '5243','Esperanza' UNION
SELECT 'STFE', '5434','Pujato' UNION
SELECT 'RIOJ', '7300','Pinchas' UNION
SELECT 'CORD', '6155','Alta Gracia'
GO

INSERT INTO GENEROS(cod_Gen,descripcion_Gen)
SELECT 'GNML','Masculino' UNION
SELECT 'GNFM','Femenino'
GO

INSERT INTO CLIENTES(dni_Cl,nombre_Cl,apellido_Cl,direccion_Cl,codProvincia_Cl,codPostal_Cl,fechaNacimiento_Cl,codGen_Cl,mail_Cl)
SELECT '08997441','Agustín','Martínez','Av. Castro 1100','CORD', '6155','1957-08-12','GNML','agustinmartinez@hotmail.com' UNION
SELECT '30447854','Luciana','Rodríguez','Zenzabello 1500','RIOJ', '7300','1987-06-29','GNFM','lucianarodriguez@gmail.com' UNION
SELECT '36774112','Carlos','Gutiérrez','Av. Los Quilmes 2450','BSAS', '1900','2004-11-11','GNML','carlosgutierrez@hotmail.com' UNION
SELECT '26251697','Fernanda','Ramírez','Los Maizales 400','BSAS', '1900','1963-05-27','GNFM','fernandaramirez@outlook.com' UNION
SELECT '10997554','Carolina','García','De las Artes 110','BSAS', '1878','1990-12-12','GNFM','carolinagarcia@gmail.com' UNION
SELECT '36552344','Lucas','Paretto','Sargento Cabral 457','BSAS', '1888','1991-07-20','GNML','lucasparetto@hotmail.com' UNION
SELECT '24117895','Gabriela','Lusteau','Av. Malvinas Argentinas 110','BSAS', '1900','1963-10-05','GNFM','gabrielalusteau@gmail.com' UNION
SELECT '37112687','Pedro','Montalván','Av. 25 de Mayo 2892','STFE', '5243','2002-06-29','GNML','pedromontalvan@gmail.com' UNION
SELECT '37544981','Ludmila','Fernández','Av. San Martín 450','STFE', '5243','2002-11-15','GNFM','ludmilafernandez@hotmail.com' UNION
SELECT '09125570','Marcos','Peralta','Bustamante 200','BSAS', '1300','1957-09-22','GNML','marcosperalta@yahoo.com.ar' UNION
SELECT '38441654','Pía','Valmonte','Av. Calchaquí 700','BSAS', '1878','1992-03-17','GNFM','piavalmonte@gmail.com' UNION
SELECT '38564123','Lucia','González','caseros 1541','BSAS', '1900','1990-10-22','GNFM','luciagonzalez@outlook.com' UNION
SELECT '33025813','Mauro','Peralta','Av. San Martín 2510','BSAS', '1300','1987-08-15','GNML','mauroperalta@gmail.com' UNION
SELECT '38441674','Fernando','Carabajal','Alvarado 478','CORD', '6155','1991-09-12','GNML','fernandocarbajal@gmail.com' UNION
SELECT '39111247','Luciano','Martínez','Los Ombúes 112','RIOJ', '7300','1992-11-21','GNML','lucianomartinez@outlook.com' 
GO

INSERT INTO TELEFONOSxCLIENTES(dniCliente_TxC,telefono_TxC)
SELECT '08997441','(011)11223344' UNION
SELECT '30447854','4222-8877' UNION
SELECT '08997441','(011)99887766' UNION
SELECT '08997441','4974-6391' UNION
SELECT '30447854','(011)20103088' UNION
SELECT '36774112','4557-8852' UNION
SELECT '26251697','4232-0011' UNION
SELECT '26251697','4522-1019' UNION
SELECT '10997554','(011)52524799' UNION
SELECT '36552344','(011)35876120' UNION
SELECT '36552344','(011)25528008' UNION
SELECT '24117895','4652-1132' UNION
SELECT '37112687','(011)41146556' UNION
SELECT '37544981','4871-0221' UNION
SELECT '37112687','(011)23369741' UNION
SELECT '09125570','(011)52446678' UNION
SELECT '38441654','4025-8877' UNION
SELECT '09125570','(011)01203588' UNION
SELECT '09125570','4255-1744' UNION
SELECT '38564123','(011)20113387' UNION
SELECT '38564123','4778-5697' UNION
SELECT '38564123','4230-1254' UNION
SELECT '33025813','4788-9954' UNION
SELECT '38441674','(011)61472255' UNION
SELECT '38441674','(011)36314788' UNION
SELECT '39111247','(011)51525377' UNION
SELECT '39111247','4652-1010' UNION
SELECT '39111247','(011)65987845'
GO

INSERT INTO VENDEDORES(legajo_Vd,nombre_Vd,apellido_Vd,direccion_Vd,codProvincia_Vd,codPostal_Vd,fechaNacimiento_Vd,codGen_Vd,fechaIngreso_Vd)
SELECT 'LG01','Carina','Pedroza','Asamblea 447','BSAS', '1870','2004-04-20','GNFM','2022-07-10' UNION
SELECT 'LG02','Francisco','Peña','Las Palmeras 321','BSAS', '1900','2004-03-14','GNML','2022-02-10' UNION
SELECT 'LG03','Martín','Bustos','Artigas 2590','BSAS', '1888','1959-10-10','GNML','2009-12-10' UNION
SELECT 'LG04','Graciela','Montenegro','Lugones 719','BSAS', '1300','1964-05-11','GNFM','2014-01-08' UNION
SELECT 'LG05','Alejandro','Fernández','Bioy Casares 110','RIOJ', '7300','1959-03-12','GNML','2015-10-10' UNION
SELECT 'LG06','Carla','López','Pontevedra 1563','BSAS', '1878','1964-06-06','GNFM','2006-03-25'
GO

INSERT INTO PROVEEDORES(cod_Prov,cuit_Prov,razonSocial_Prov,direccion_Prov,codProvincia_Prov,codPostal_Prov,web_Prov,telefono_Prov,mail_Prov)
SELECT 'PV-0001','20144578964','Todo Informática S.A','Av. Los Rosales 110','STFE', '5243','www.todoinformatica.com.ar','4122-8779','todoinfomatica@outlook.com' UNION
SELECT 'PV-0002','36874521203','Power PC S.R.L','Av. Las Palmeras 254','STFE', '5434','www.pcpower.com.ar','(011)11204578','powerpc@gmail.com' UNION
SELECT 'PV-0003','78451263910','Solo Componentes S.A','calle 40 1230','RIOJ', '7300','www.solocomponentes.com.ar','(011)20364577','componentespc@hotmail.com' UNION
SELECT 'PV-0004','99554412300','Sideko Hardware','Viamonte 332','CORD', '6155','www.sidekoh.com.ar','4001-2025','sidekohardware@gmail.com' UNION
SELECT 'PV-0005','12256789419','Nogales Electrónica','Av. Los Lirios 8741','BSAS', '1870','www.nogaleselectronica.com.ar','4777-2020','nogaleselectro@gmail.com'
GO

INSERT INTO ARTICULOS(cod_Art,descripcion_Art,stock_Art,precioUnitario_Art,codProv_Art)
SELECT 'AT-0001','Memoria RAM 8GB DDR3 - 1600 MHz - Markvision',200,16000.00,'PV-0001' UNION
SELECT 'AT-0002','Memoria RAM 16GB DDR3 - 1866MHz - Kingston',150,48000.00,'PV-0001' UNION
SELECT 'AT-0003','Memoria RAM Notebook SODIMM 4GB - DDR3 - HyperVision',280,18000.00,'PV-0002' UNION
SELECT 'AT-0004','Fuente Alimentación ATX - 500W',180,18000.00,'PV-0003' UNION
SELECT 'AT-0005','Fuente Alimentación ATX - 600W',145,23000.00,'PV-0001' UNION
SELECT 'AT-0006','HD USB 1TB WD Elements USB 3.0 - Disco Externo',120,75000.00,'PV-0002' UNION
SELECT 'AT-0007','Disco HDD 4TB Seagate IronWolf NAS',100,160000.00,'PV-0002'
GO

INSERT INTO VENTAS(codVendedor_Venta,Fecha_Venta,Hora_Venta,dniCliente_Venta,total_Venta)
SELECT 'LG04','2024-06-01','15:21:17.334','08997441',156000.00 
GO
INSERT INTO VENTAS(codVendedor_Venta,Fecha_Venta,Hora_Venta,dniCliente_Venta,total_Venta)
SELECT 'LG04','2024-06-03','17:21:44.114','08997441',34000.00
GO
INSERT INTO VENTAS(codVendedor_Venta,Fecha_Venta,Hora_Venta,dniCliente_Venta,total_Venta)
SELECT 'LG04','2024-06-03','09:11:32.004','10997554',352000.00
GO
INSERT INTO VENTAS(codVendedor_Venta,Fecha_Venta,Hora_Venta,dniCliente_Venta,total_Venta)
SELECT 'LG05','2024-06-04','13:10:21.110','24117895',64000.00 
GO
INSERT INTO VENTAS(codVendedor_Venta,Fecha_Venta,Hora_Venta,dniCliente_Venta,total_Venta)
SELECT 'LG05','2024-06-04','15:25:10.456','24117895',740000.00 
GO
INSERT INTO VENTAS(codVendedor_Venta,Fecha_Venta,Hora_Venta,dniCliente_Venta,total_Venta)
SELECT 'LG05','2024-06-05','10:36:40.257','30447854',166000.00
GO

INSERT INTO DETALLE_VENTAS(idVenta_DV,codArt_DV,cantidadArt_DV,precioUnitario_DV)
SELECT 1,'AT-0001',3,16000.00 UNION
SELECT 1,'AT-0003',4,18000.00 UNION
SELECT 1,'AT-0004',2,18000.00 UNION
SELECT 2,'AT-0003',1,18000.00 UNION
SELECT 2,'AT-0001',1,16000.00 UNION
SELECT 3,'AT-0007',2,160000.00 UNION
SELECT 3,'AT-0001',2,16000.00 UNION
SELECT 4,'AT-0001',1,16000.00 UNION
SELECT 4,'AT-0002',1,48000.00 UNION
SELECT 5,'AT-0001',4,16000.00 UNION
SELECT 5,'AT-0003',2,18000.00 UNION
SELECT 5,'AT-0007',4,160000.00 UNION
SELECT 6,'AT-0006',2,75000.00 UNION
SELECT 6,'AT-0001',1,16000.00 
GO
