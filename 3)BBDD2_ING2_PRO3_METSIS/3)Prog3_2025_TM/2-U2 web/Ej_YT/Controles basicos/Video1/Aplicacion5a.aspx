<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion5a.aspx.cs" Inherits="MiPrimerSitioWeb.Aplicacion5a" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Pasar informacion entre formularios opcion 1&nbsp;&nbsp; 
            <br />
            <br />
            Ingrese su nombre: <asp:TextBox ID="txtNombre" runat="server"></asp:TextBox>
            <br />
            <br />
            Ingrese su apellido:
            <asp:TextBox ID="txtApellido" runat="server"></asp:TextBox>
            <br />
            <br />
            <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Button ID="btnAceptar" runat="server" OnClick="btnAceptar_Click" Text="Aceptar" />
        </div>
    </form>
</body>
</html>
