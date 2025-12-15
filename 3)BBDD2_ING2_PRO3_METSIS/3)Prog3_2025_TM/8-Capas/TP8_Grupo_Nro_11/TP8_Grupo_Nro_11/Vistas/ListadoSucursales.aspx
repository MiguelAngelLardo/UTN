<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="ListadoSucursales.aspx.cs" Inherits="Vistas.ListadoSucursales" %>

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
            height: 22px;
        }
        .auto-style8 {
            width: 196px;
        }
        .auto-style9 {
            width: 100%;
            height: 35px;
            margin-bottom: 0px;
        }
        .auto-style10 {
            width: 333px;
        }
        .auto-style11 {
            width: 59px;
        }
        .auto-style12 {
            width: 45px;
        }
        .auto-style13 {
            width: 37px;
        }
        .auto-style14 {
            width: 214px;
        }
        .auto-style15 {
            height: 22px;
            width: 144px;
        }
        .auto-style17 {
            height: 22px;
            width: 122px;
        }
        .auto-style18 {
            height: 22px;
            width: 152px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <table class="auto-style1">
            <tr>
                <td class="auto-style15"></td>
                <td class="auto-style17">
                        <asp:HyperLink ID="hlAgregarSucursal" runat="server" NavigateUrl="~/AgregarSucursal.aspx">Agregar Sucursal</asp:HyperLink>
                    </td>
                <td class="auto-style18">
                        <asp:HyperLink ID="hlListadoSucursales" runat="server" NavigateUrl="~/ListadoSucursales.aspx">Listado de Sucursales</asp:HyperLink>
                    </td>
                <td class="auto-style2">
                        <asp:HyperLink ID="hlEliminarSucursal" runat="server" NavigateUrl="~/EliminarSucursal.aspx">Eliminar Sucursal</asp:HyperLink>
                    </td>
            </tr>
        </table>
        <p><strong>
            <asp:Label ID="Label1" runat="server" Font-Size="X-Large"></asp:Label>
            </strong>
        </p>
        <table class="auto-style9">
            <tr>
                <td class="auto-style8">Búsqueda ingrese Id sucursal:</td>
                <td class="auto-style10">
                    <asp:TextBox ID="tbBuscarIdSucursal" runat="server" Width="258px"></asp:TextBox>
                </td>
                <td class="auto-style12">&nbsp;</td>
                <td class="auto-style11">
                    <asp:Button ID="btnFiltrar" runat="server" Text="Filtrar" OnClick="btnFiltrar_Click" />
                </td>
                <td class="auto-style13">&nbsp;</td>
                <td class="auto-style14">
                    <asp:Button ID="btnMostrarTodos" runat="server" Text="Mostrar Todos" Width="143px" OnClick="btnMostrarTodos_Click" />
                </td>
                <td>&nbsp;</td>
            </tr>
        </table>
    <p>
        <asp:GridView ID="gvTabla" runat="server">
        </asp:GridView>
        </p>
        <p>
            <asp:Label ID="labelError" runat="server" ForeColor="#D70000"></asp:Label>
        </p>
    </form>
    <p>
        &nbsp;</p>
    <p>
        &nbsp;</p>
    <p>
        &nbsp;</p>
</body>
</html>
