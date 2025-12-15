<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion2b.aspx.cs" Inherits="Aplicaciones.Aplicacion2b" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/Aplicacion2a.aspx">Ir a la página Aplicacion2a</asp:HyperLink>
        </div>
        <p>
            &nbsp;</p>
        <p>
            Cantidad de clicks realizados con el botón contar:
            <asp:Label ID="lblMensaje" runat="server"></asp:Label>
        </p>
    </form>
</body>
</html>
