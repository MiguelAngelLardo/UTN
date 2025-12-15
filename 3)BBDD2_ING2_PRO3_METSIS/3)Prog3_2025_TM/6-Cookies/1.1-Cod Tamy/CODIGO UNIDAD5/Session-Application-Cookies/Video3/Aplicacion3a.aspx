<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion3a.aspx.cs" Inherits="Aplicaciones.Aplicacion3a" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
        .auto-style2 {
            width: 264px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <p>
            Ejemplo variables session y datatable:</p>
        <p>
            &nbsp;</p>
        <p>
            &nbsp;</p>
        <p>
            <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/Aplicacion3b.aspx">Ir a aplicacion3b</asp:HyperLink>
            <br />
        </p>
        <table class="auto-style1">
            <tr>
                <td class="auto-style2">Ingrese su nombre:</td>
                <td>
                    <asp:TextBox ID="txtNombre" runat="server"></asp:TextBox>
                </td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style2">Ingrese su apellido:</td>
                <td>
                    <asp:TextBox ID="txtApellido" runat="server"></asp:TextBox>
                </td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style2">&nbsp;</td>
                <td>
                    <asp:Button ID="btnAgregar" runat="server" Height="35px" OnClick="btnAgregar_Click" Text="Agregar" />
                </td>
                <td>&nbsp;</td>
            </tr>
        </table>
        <div>
        </div>
    </form>
</body>
</html>
