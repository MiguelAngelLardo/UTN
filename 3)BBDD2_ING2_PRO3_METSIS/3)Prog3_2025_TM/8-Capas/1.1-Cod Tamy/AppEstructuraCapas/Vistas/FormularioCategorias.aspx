<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="FormularioCategorias.aspx.cs" Inherits="Vistas.FormularioCategorias" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <br />

            Ingrese nombre categoría:
            <asp:TextBox ID="txtNombreCategoria" runat="server"></asp:TextBox>
&nbsp;
            <asp:Button ID="btnAceptar" runat="server" Text="Aceptar" OnClick="btnAceptar_Click" />
        &nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Label ID="lblMensaje" runat="server"></asp:Label>
        </div>
            <br />
        <br />
        <br />
        <asp:GridView ID="grdCategorias" runat="server">
        </asp:GridView>
        <br />
    </form>


</body>
</html>
