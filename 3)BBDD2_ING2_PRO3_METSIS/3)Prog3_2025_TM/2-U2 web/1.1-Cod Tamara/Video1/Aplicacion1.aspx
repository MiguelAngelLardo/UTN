<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion1.aspx.cs" Inherits="MiPrimerSitioWeb.Aplicacion1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            &nbsp;&nbsp; Ingrese su nombre:
            <asp:TextBox ID="txtNombre" runat="server"></asp:TextBox>
&nbsp;
            <asp:Button ID="btnAceptar" runat="server" OnClick="btnAceptar_Click" Text="Aceptar" />
            <br />
            <br />
&nbsp;&nbsp;
            <asp:Label ID="lblMensaje" runat="server"></asp:Label>
        </div>
    </form>
</body>
</html>
