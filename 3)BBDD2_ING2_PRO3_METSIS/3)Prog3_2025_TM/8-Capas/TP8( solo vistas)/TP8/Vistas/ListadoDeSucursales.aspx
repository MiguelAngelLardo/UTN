<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="ListadoDeSucursales.aspx.cs" Inherits="Vistas.ListadoDeSucursales" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">

        .auto-style1 {
            width: 61%;
        }
        .auto-style2 {
            width: 218px;
        }
        .auto-style3 {
            width: 178px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <table class="auto-style1">
                <tr>
                    <td class="auto-style2">
                        <asp:HyperLink ID="hlAgregarSucu" runat="server" ForeColor="#0066FF" NavigateUrl="~/AgregarSucursal.aspx" style="text-decoration: underline">Agregar Sucursal</asp:HyperLink>
                    </td>
                    <td class="auto-style3">
                        <asp:HyperLink ID="hlListadoSucu" runat="server" ForeColor="#0066FF" NavigateUrl="~/ListadoDeSucursales.aspx" style="text-decoration: underline">Listado de sucursales</asp:HyperLink>
                    </td>
                    <td>
                        <asp:HyperLink ID="hlEliminarSucu" runat="server" ForeColor="#0066FF" NavigateUrl="~/EliminarSucursal.aspx" style="text-decoration: underline">Eliminar sucursal</asp:HyperLink>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style2"><strong style="font-size: large">
                        <br />
                        Listado de sucursales<br />
                        </strong></td>
                    <td class="auto-style3">&nbsp;</td>
                    <td>&nbsp;</td>
                </tr>
                <tr>
                    <td class="auto-style2">
                        <br />
                        Búsqueda ingrese Id sucursal:<br />
                    </td>
                    <td class="auto-style3">
                        <asp:TextBox ID="txtIngreseIdSucu" runat="server" Width="149px"></asp:TextBox>
                    </td>
                    <td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                        <asp:Button ID="btnFiltrar" runat="server" Text="Filtrar" />
                        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                        <asp:Button ID="btnMostrarTodosFiltrar0" runat="server" Text="Mostrar todos" />
                    </td>
                </tr>
            </table>
        </div>
        <asp:GridView ID="gvListar" runat="server">
        </asp:GridView>
    </form>
</body>
</html>
