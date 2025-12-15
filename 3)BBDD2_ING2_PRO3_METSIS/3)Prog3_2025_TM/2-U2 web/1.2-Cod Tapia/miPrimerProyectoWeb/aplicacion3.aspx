<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="aplicacion3.aspx.cs" Inherits="miPrimerProyectoWeb.aplicacion3" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Label ID="Label1" runat="server" Text="Elija un color: "></asp:Label>
            <asp:DropDownList ID="ddlColores" runat="server">
            </asp:DropDownList>
            <asp:Button ID="btnElegir" runat="server" OnClick="btnElegir_Click" Text="Elegir color" />
            <br />
            <br />
            <asp:Label ID="Label2" runat="server" Text="Usted seleccionó: "></asp:Label>
            <asp:Label ID="txtColorSeleccionado" runat="server"></asp:Label>
        </div>
    </form>
</body>
</html>
