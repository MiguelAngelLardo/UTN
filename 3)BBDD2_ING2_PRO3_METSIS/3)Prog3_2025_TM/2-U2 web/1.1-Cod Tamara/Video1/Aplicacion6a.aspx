<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion6a.aspx.cs" Inherits="MiPrimerSitioWeb.Aplicacion6a" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <p>
&nbsp;&nbsp; Pasar informacion entre formularios opcion 2</p>
        <p>
            &nbsp;</p>
        <p>
            Ingrese su&nbsp; nombre: <asp:TextBox ID="txtNombre" runat="server"></asp:TextBox>
            <br />
            <br />
            Ingrese su apellido:
            <asp:TextBox ID="txtApellido" runat="server"></asp:TextBox>
            <br />
            <br />
            <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Button ID="btnAceptar" runat="server" OnClick="btnAceptar_Click" Text="Aceptar" />
        </p>
        <div>
        </div>
    </form>
</body>
</html>
