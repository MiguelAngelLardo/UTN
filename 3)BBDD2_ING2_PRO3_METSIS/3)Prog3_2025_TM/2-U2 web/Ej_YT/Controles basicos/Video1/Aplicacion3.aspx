<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion3.aspx.cs" Inherits="MiPrimerSitioWeb.Aplicacion3" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            &nbsp;&nbsp;&nbsp;&nbsp; Seleccione un color:&nbsp;
            <asp:DropDownList ID="ddlColores" runat="server">
            </asp:DropDownList>
            <br />
            <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Button ID="btnAceptar" runat="server" OnClick="btnAceptar_Click" Text="Aceptar" />
            <br />
            <br />
&nbsp;&nbsp;&nbsp;&nbsp; Usted selecciono:&nbsp;
            <asp:Label ID="lblMensaje" runat="server"></asp:Label>
        </div>
    </form>
</body>
</html>
