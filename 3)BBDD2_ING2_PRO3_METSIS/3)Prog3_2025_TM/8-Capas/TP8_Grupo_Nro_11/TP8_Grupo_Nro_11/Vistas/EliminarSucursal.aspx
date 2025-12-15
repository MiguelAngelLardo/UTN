<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="EliminarSucursal.aspx.cs" Inherits="Vistas.EliminarSucursal" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">


        .auto-style1 {
            width: 100%;
        }
        .auto-style7 {
            width: 245px;
        }
        .auto-style3 {
            width: 56px;
        }
        .auto-style4 {
            width: 154px;
        }
        .auto-style8 {
            width: 153px;
        }
        .auto-style9 {
            width: 151px;
            margin-left: 40px;
        }
        .auto-style13 {
            width: 86px;
        }
        .auto-style11 {
            width: 161px;
        }
        </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:LinkButton ID="lbAgregarSucursal" runat="server" OnClick="lbAgregarSucursal_Click">Agregar Sucursal</asp:LinkButton>
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:LinkButton ID="lbListadodeSucursales" runat="server" OnClick="lbListadodeSucursales_Click">Listado de sucursales</asp:LinkButton>
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:LinkButton ID="lbEliminarsucursal" runat="server" OnClick="lbEliminarsucursal_Click">Eliminar sucursal</asp:LinkButton>
            <br />
            <br />
            <strong>
            <asp:Label ID="Label1" runat="server" CssClass="auto-style12" Font-Size="XX-Large"></asp:Label>
            </strong>
            <br />
            &nbsp;<table class="auto-style1">
                <tr>
                    <td class="auto-style7">ingresar ID sucursal:</td>
                    <td class="auto-style3">&nbsp;</td>
                    <td class="auto-style4">
                        <asp:TextBox ID="tbBuscarIdSucursal" runat="server" Width="245px"></asp:TextBox>
                    </td>
                    <td class="auto-style8">&nbsp;</td>
                    <td class="auto-style9">
                        <asp:Button ID="btnEliminar" runat="server" OnClick="btnFiltrar_Click" Text="Eliminar" />
                    </td>
                    <td class="auto-style13">&nbsp;</td>
                    <td class="auto-style11">&nbsp;</td>
                    <td>&nbsp;</td>
                </tr>
            </table>
            <br />
            <br />
            <asp:Label ID="labelError" runat="server" CssClass="auto-style14" style="color: #FF0000"></asp:Label>
            <br />
        </div>
    </form>
</body>
</html>