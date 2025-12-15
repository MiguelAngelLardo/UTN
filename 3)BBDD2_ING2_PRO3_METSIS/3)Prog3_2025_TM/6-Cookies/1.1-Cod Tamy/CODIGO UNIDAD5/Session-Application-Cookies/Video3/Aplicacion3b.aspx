<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion3b.aspx.cs" Inherits="Aplicaciones.Aplicacion3b" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <p>
            <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/Aplicacion3a.aspx">Ir a aplicacion3a</asp:HyperLink>
        </p>
        <p>
            <br />
            Listado de personas agregadas:</p>
        <p>
            <asp:GridView ID="grdPersonas" runat="server">
            </asp:GridView>
        </p>
        <p>
            &nbsp;</p>
        <p>
            <asp:Button ID="btnEliminar" runat="server" OnClick="btnEliminar_Click" Text="Eliminar el listado de personas" />
        </p>
        <p>
            &nbsp;</p>
        <div>
        </div>
    </form>
</body>
</html>
