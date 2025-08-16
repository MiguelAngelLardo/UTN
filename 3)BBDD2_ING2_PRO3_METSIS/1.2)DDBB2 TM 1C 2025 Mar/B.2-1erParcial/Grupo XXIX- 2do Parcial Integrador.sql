/* GRUPO XXIX
29812 - Lardo, Miguel Angel
30490 - Mucci, Natalia Patricia
30354 - Garcia, María Lourdes
30425 - Lezcano, Sol Dánae
*/


USE "2doTrabajoIntegrador2025"

CREATE TABLE PEDIDOS_DEPOSITO(
    codigoPedido_PD INT IDENTITY(1,1) NOT NULL,
    codigoArticulo_PD char(7) NOT NULL,
    cantidad_PD int DEFAULT 10,
    fechaHora_PD datetime DEFAULT GETDATE(),
    Cumplido_PD bit default 0,
	CONSTRAINT PK_PEDIDOS_DEPOSITOS PRIMARY KEY (codigoPedido_PD),
    CONSTRAINT FK_PEDIDOS_DEPOSITOS_ARTICULOS FOREIGN KEY (codigoArticulo_PD) REFERENCES ARTICULOS(cod_Art),
);
 GO

 CREATE TABLE AUDITORIAS
(
    codigoAuditoria_AU INT IDENTITY(1,1) NOT NULL,
    codigoArticulo_AU char(7) NOT NULL,
    stockAnterior_AU int NOT NULL,
    stockNuevo_AU int NOT NULL,
    fechaHora_AU datetime DEFAULT GETDATE(),
    CONSTRAINT PK_AUDITORIAS PRIMARY KEY (codigoAuditoria_AU),
    CONSTRAINT FK_AUDITORIAS_ARTICULOS FOREIGN KEY (codigoArticulo_AU) REFERENCES ARTICULOS(cod_Art)
);
GO

CREATE TRIGGER tr_ValidarStock
ON DETALLE_VENTAS
AFTER INSERT
AS
BEGIN
    SET NOCOUNT ON;

 
    IF EXISTS (
    SELECT cod_Art
    FROM inserted
    JOIN ARTICULOS ON ARTICULOS.cod_Art = inserted.codArt_DV
    WHERE ARTICULOS.stock_Art >= inserted.cantidadArt_DV
)

    BEGIN
     

        UPDATE ARTICULOS
        SET stock_Art = stock_Art - (SELECT cantidadArt_DV FROM inserted)
        WHERE cod_Art = (SELECT codArt_DV FROM inserted);


        UPDATE VENTAS
        SET total_Venta = total_Venta + (SELECT cantidadArt_DV * precioUnitario_DV FROM inserted)
        WHERE id_Venta = (SELECT idVenta_DV FROM inserted);
    END
    ELSE
    BEGIN
        
		INSERT INTO PEDIDOS_DEPOSITO (codigoArticulo_PD, cantidad_PD, fechaHora_PD, Cumplido_PD)
        SELECT inserted.codArt_DV, inserted.cantidadArt_DV, GETDATE(), 0
        FROM inserted
        INNER JOIN ARTICULOS ON ARTICULOS.cod_Art = inserted.codArt_DV
        WHERE ARTICULOS.stock_Art < inserted.cantidadArt_DV;

     
        ROLLBACK TRANSACTION;
        RAISERROR('No hay stock suficiente. Se generó un pedido a depósito.', 16, 1);
        RETURN;
    END
END;
GO

CREATE TRIGGER ACTUALIZASTOCK 
ON PEDIDOS_DEPOSITO 
AFTER UPDATE 
AS 
BEGIN
    SET NOCOUNT ON;

  
    UPDATE ARTICULOS
    SET stock_Art = stock_Art + I.cantidad_PD
    FROM ARTICULOS A
    INNER JOIN inserted I ON A.cod_Art = I.codigoArticulo_PD
    INNER JOIN deleted D ON I.codigoPedido_PD = D.codigoPedido_PD
    WHERE D.Cumplido_PD = 0 AND I.Cumplido_PD = 1;

 
    INSERT INTO AUDITORIAS (codigoArticulo_AU, stockAnterior_AU, stockNuevo_AU)
    SELECT 
        I.codigoArticulo_PD,
        A.stock_Art - I.cantidad_PD,  
        A.stock_Art                  
    FROM ARTICULOS A
    INNER JOIN inserted I ON A.cod_Art = I.codigoArticulo_PD
    INNER JOIN deleted D ON I.codigoPedido_PD = D.codigoPedido_PD
    WHERE D.Cumplido_PD = 0 AND I.Cumplido_PD = 1;
END;
GO


INSERT INTO DETALLE_VENTAS (codArt_DV, cantidadArt_DV, precioUnitario_DV, idVenta_DV)
VALUES ('AT-0002', 10, 120, 2);


INSERT INTO DETALLE_VENTAS (codArt_DV, cantidadArt_DV, precioUnitario_DV, idVenta_DV)
VALUES ('AT-0003', 7, 90, 3);


UPDATE PEDIDOS_DEPOSITO SET Cumplido_PD = 1
WHERE codigoPedido_PD = 1;
