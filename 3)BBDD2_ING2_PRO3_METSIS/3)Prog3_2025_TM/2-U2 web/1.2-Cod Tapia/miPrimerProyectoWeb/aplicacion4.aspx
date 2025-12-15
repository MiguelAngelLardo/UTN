<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="aplicacion4.aspx.cs" Inherits="miPrimerProyectoWeb.aplicacion4" %>

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
            <asp:DropDownList ID="ddlColores" runat="server" AutoPostBack="True" OnSelectedIndexChanged="ddlColores_SelectedIndexChanged">
            </asp:DropDownList>
            <br />
            <br />
            <asp:Label ID="lblColorSeleccionado" runat="server"></asp:Label>
        </div>
    </form>
</body>
</html>
