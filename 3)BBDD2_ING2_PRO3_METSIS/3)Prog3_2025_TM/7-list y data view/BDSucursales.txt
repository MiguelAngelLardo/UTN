CREATE DATABASE [BDSucursales]
GO
USE [BDSucursales]
GO
CREATE TABLE [dbo].[Sucursal](
	[Id_Sucursal] [int] IDENTITY(1,1)PRIMARY KEY NOT NULL,
	[NombreSucursal] [varchar](100) NOT NULL,
	[DescripcionSucursal] [varchar](100) NOT NULL,
	[Id_HorarioSucursal] [int] NULL,
	[Id_ProvinciaSucursal] [int] NOT NULL,
    [DireccionSucursal] [varchar](100) NULL,
	[URL_Imagen_Sucursal] [varchar](100) NULL,
)
GO
INSERT [dbo].[Sucursal] ( [NombreSucursal], [DescripcionSucursal], [Id_HorarioSucursal], [Id_ProvinciaSucursal], [URL_Imagen_Sucursal],[DireccionSucursal]) VALUES ( N'Ticketek', N'Reserva y venta de entradas para eventos.', 3, 1, N'~/Imagenes/1.jpg',N'Avenida Santa Fe 1234')
INSERT [dbo].[Sucursal] ( [NombreSucursal], [DescripcionSucursal], [Id_HorarioSucursal], [Id_ProvinciaSucursal], [URL_Imagen_Sucursal],[DireccionSucursal]) VALUES ( N'Fravega', N'Venta de articulos electrónicos', 1, 1, N'~/Imagenes/2.jpg',N'Libertador 16280')
INSERT [dbo].[Sucursal] ( [NombreSucursal], [DescripcionSucursal], [Id_HorarioSucursal], [Id_ProvinciaSucursal], [URL_Imagen_Sucursal],[DireccionSucursal]) VALUES ( N'LanTec S.A', N'Productos para el monitoreo, alerta y control domestico y comercial', 1, 1, N'~/Imagenes/3.jpg',N'Callao 986')
INSERT [dbo].[Sucursal] ( [NombreSucursal], [DescripcionSucursal], [Id_HorarioSucursal], [Id_ProvinciaSucursal], [URL_Imagen_Sucursal],[DireccionSucursal]) VALUES ( N'Aramark', N'Expertos en brindar servicios de alimentación y gestión de instalaciones', 2, 3, N'~/Imagenes/4.jpg',N'Cerrito 3567')
INSERT [dbo].[Sucursal] ( [NombreSucursal], [DescripcionSucursal], [Id_HorarioSucursal], [Id_ProvinciaSucursal], [URL_Imagen_Sucursal],[DireccionSucursal]) VALUES ( N'Daytona', N'Reparación y colocación de cubiertas', 2, 1, N'~/Imagenes/5.jpg',N'Constitucion 1899')
INSERT [dbo].[Sucursal] ( [NombreSucursal], [DescripcionSucursal], [Id_HorarioSucursal], [Id_ProvinciaSucursal], [URL_Imagen_Sucursal],[DireccionSucursal]) VALUES ( N'Cafe Fundador', N'Lugar destinado para tomar distintos tipos de café', 1, 3, N'~/Imagenes/6.jpg',N'Hipolito Yrigoyen 2550')
INSERT [dbo].[Sucursal] ( [NombreSucursal], [DescripcionSucursal], [Id_HorarioSucursal], [Id_ProvinciaSucursal], [URL_Imagen_Sucursal],[DireccionSucursal]) VALUES ( N'Reebok', N'Venta de Zapatillas y accesorios reebok', 5, 1, N'~/Imagenes/7.jpg',N'Avenida Santa Fe 2550')
INSERT [dbo].[Sucursal] ( [NombreSucursal], [DescripcionSucursal], [Id_HorarioSucursal], [Id_ProvinciaSucursal], [URL_Imagen_Sucursal],[DireccionSucursal]) VALUES ( N'Puma', N'venta de zapatillas Puma', 6, 4, N'~/Imagenes/8.jpg', N'Peru 776')
INSERT [dbo].[Sucursal] ( [NombreSucursal], [DescripcionSucursal], [Id_HorarioSucursal], [Id_ProvinciaSucursal], [URL_Imagen_Sucursal],[DireccionSucursal]) VALUES ( N'Sony', N'Accesorios y electrodomésticos Sony', 6, 2, N'~/Imagenes/9.jpg',N'Avellaneda 223')
INSERT [dbo].[Sucursal] ( [NombreSucursal], [DescripcionSucursal], [Id_HorarioSucursal], [Id_ProvinciaSucursal], [URL_Imagen_Sucursal],[DireccionSucursal]) VALUES ( N'Starbucks Cofee', N'Starbucks vende café elaborado, bebidas calientes y otras bebidas, además bocadillos.', 1, 3, N'~/Imagenes/10.jpg',N'San Nicolas 1200')
INSERT [dbo].[Sucursal] ( [NombreSucursal], [DescripcionSucursal], [Id_HorarioSucursal], [Id_ProvinciaSucursal], [URL_Imagen_Sucursal],[DireccionSucursal]) VALUES ( N'Adidas', N'Venta de productos Adidas', 1, 4, N'~/Imagenes/11.jpg',N'Corrientes 5677')
INSERT [dbo].[Sucursal] ( [NombreSucursal], [DescripcionSucursal], [Id_HorarioSucursal], [Id_ProvinciaSucursal], [URL_Imagen_Sucursal],[DireccionSucursal]) VALUES ( N'Burguen King', N'Local de comidas rapidas: Burguer King', 6, 1, N'~/Imagenes/12.jpg',N'San Luis 778')
INSERT [dbo].[Sucursal] ( [NombreSucursal], [DescripcionSucursal], [Id_HorarioSucursal], [Id_ProvinciaSucursal], [URL_Imagen_Sucursal],[DireccionSucursal]) VALUES ( N'Mc Donalds', N'Local de comidas rapidas: MC Donalds', 6, 1, N'~/Imagenes/13.jpg',N'Virrey Loreto 611')



GO

CREATE TABLE [dbo].[Provincia](
	[Id_Provincia] [int] IDENTITY(1,1)PRIMARY KEY NOT NULL,
	[DescripcionProvincia] [varchar](50) NOT NULL,
)

GO

INSERT [dbo].[Provincia] ( [DescripcionProvincia]) VALUES ( N'Buenos Aires')
INSERT [dbo].[Provincia] ( [DescripcionProvincia]) VALUES ( N'Entre Rios')
INSERT [dbo].[Provincia] ( [DescripcionProvincia]) VALUES ( N'Santa Fe')
INSERT [dbo].[Provincia] ([DescripcionProvincia]) VALUES ( N'La Pampa')
INSERT [dbo].[Provincia] ([DescripcionProvincia]) VALUES ( N'Cordoba')
INSERT [dbo].[Provincia] ([DescripcionProvincia]) VALUES ( N'Misiones')
INSERT [dbo].[Provincia] ([DescripcionProvincia]) VALUES ( N'Chaco')

GO

CREATE TABLE [dbo].[Horario](
	[Id_Horario] [int] IDENTITY(1,1)PRIMARY KEY NOT NULL,
	[DescripcionHorario] [varchar](50) NOT NULL,
)
GO

INSERT [dbo].[Horario] ([DescripcionHorario]) VALUES ( N'8:00 a  12:00 Hs')
INSERT [dbo].[Horario] ([DescripcionHorario]) VALUES ( N'12:00 a 16:00 Hs')
INSERT [dbo].[Horario] ([DescripcionHorario]) VALUES ( N'16:00 a  20:00 Hs')
INSERT [dbo].[Horario] ([DescripcionHorario]) VALUES ( N'20:00 a  24:00 Hs')
INSERT [dbo].[Horario] ([DescripcionHorario]) VALUES ( N'08:00 a  20:00 Hs')
INSERT [dbo].[Horario] ([DescripcionHorario]) VALUES ( N'10:00 a  22:00 Hs')
