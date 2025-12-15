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
        .auto-style2 {
            width: 185px;
        }
        .auto-style3 {
            width: 352px;
        }
    </style>
</head>
<body>
    <form id="form2" runat="server">
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
                    <td class="auto-style2" style="font-size: large">
                        <br />
                        <strong>Eliminar Sucursal</strong><br />
                    </td>
                    <td class="auto-style3">&nbsp;</td>
                    <td>&nbsp;</td>
                </tr>
                <tr>
                    <td class="auto-style2">Ingresar ID sucursal</td>
                    <td class="auto-style3">
                        <asp:TextBox ID="txtIdSucursal" runat="server" Width="175px"></asp:TextBox>
                        <asp:CompareValidator ID="compareValidetNumero" runat="server" ControlToValidate="txtIdSucursal" ErrorMessage="El valor debe ser un número" Operator="DataTypeCheck" Type="Integer"></asp:CompareValidator>
                    </td>
                    <td>
                        <asp:Button ID="btnEliminar" runat="server" OnClick="btnEliminar_Click" Text="Eliminar" />
                    </td>
                </tr>
                <tr>
                    <td class="auto-style2">
                        <asp:Label ID="lblEliminar" runat="server"></asp:Label>
                    </td>
                    <td class="auto-style3">&nbsp;</td>
                    <td>&nbsp;</td>
                </tr>
            </table>
        </div>
    </form>
  
</body>
</html>
