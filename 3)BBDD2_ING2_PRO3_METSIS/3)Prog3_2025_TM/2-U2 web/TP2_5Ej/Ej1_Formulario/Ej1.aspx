<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Ej1.aspx.cs" Inherits="Ej1_Formulario.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
          Ingrese Nombre del Producto:
          <asp:TextBox ID="txtProductoA" runat="server"></asp:TextBox>
&nbsp;Cantidad:
          <asp:TextBox ID="txtCantidadA" runat="server"></asp:TextBox>
          <br />
          <br />
          Ingrese Nombre del Producto:
          <asp:TextBox ID="txtProductoB" runat="server"></asp:TextBox>
&nbsp;Cantidad:
          <asp:TextBox ID="txtCantidadB" runat="server"></asp:TextBox>
        </div>
        <p>
          &nbsp;</p>
        <asp:Button ID="btnGenerarTabla" runat="server" OnClick="btnGenerarTabla_Click" Text="Generar Tabla" />
        <p>
          <asp:Label ID="lblTabla" runat="server"></asp:Label>
        </p>
    </form>
</body>
</html>
