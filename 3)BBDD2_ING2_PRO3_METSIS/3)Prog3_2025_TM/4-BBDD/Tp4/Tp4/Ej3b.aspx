<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Ej3b.aspx.cs" Inherits="Tp4.Ej3b" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
          <strong>Listado de libros:
          <br />
          </strong>
        </div>
        <asp:GridView ID="gvLibros" runat="server">
        </asp:GridView>
        <br />
        <asp:LinkButton ID="lbConsultarOtroTema" runat="server" OnClick="lbConsultarOtroTema_Click">Consultar otro tema</asp:LinkButton>
&nbsp;&nbsp;
    </form>
</body>
</html>
