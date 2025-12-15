<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion2a.aspx.cs" Inherits="Aplicaciones.Aplicacion2a" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <p>
        Ejemplo variables application:<br />
    </p>
    <p>
        &nbsp;</p>
    <form id="form1" runat="server">
        <div>
            <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/Aplicacion2b.aspx">Ir a Aplicacion2b</asp:HyperLink>
            <br />
            <br />
            <asp:Button ID="btnContar" runat="server" OnClick="btnContar_Click" Text="Contar" />
            <br />
        </div>
    </form>
</body>
</html>
