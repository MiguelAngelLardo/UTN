<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="AgregarSucursal.aspx.cs" Inherits="Tp5.AgregarSucursal" %>

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
    .auto-style3 {
      width: 145px;
    }
    .auto-style4 {
      height: 22px;
      width: 145px;
    }
    .auto-style5 {
      width: 384px;
    }
    .auto-style6 {
      height: 22px;
      width: 384px;
    }
  </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
          <table class="auto-style1">
            <tr>
              <td class="auto-style3">
                <asp:HyperLink ID="hlAgregarSucu" runat="server" BorderStyle="None" ForeColor="Blue" style="text-decoration: underline">Agregar Sucursal</asp:HyperLink>
              </td>
              <td class="auto-style5">
                <asp:HyperLink ID="hlListarSucu" runat="server" BorderStyle="None" ForeColor="Blue" style="text-decoration: underline">Listar Sucursales</asp:HyperLink>
              </td>
              <td>
                <asp:HyperLink ID="hlEliminarSucu" runat="server" BorderStyle="None" ForeColor="Blue" style="text-decoration: underline">Eliminar Sucursales</asp:HyperLink>
              </td>
            </tr>
            <tr>
              <td class="auto-style3" style="font-size: large"><strong style="font-size: x-large">
                <br />
                GRUPO N<br />
                </strong></td>
              <td class="auto-style5">&nbsp;</td>
              <td>&nbsp;</td>
            </tr>
            <tr>
              <td class="auto-style4" style="font-size: large"><strong>Agregar Sucursal<br />
                </strong></td>
              <td class="auto-style6"></td>
              <td class="auto-style2"></td>
            </tr>
            <tr>
              <td class="auto-style3">Nombre Sucursal:</td>
              <td class="auto-style5">
                <asp:TextBox ID="txtNombreSuc" runat="server" Width="218px"></asp:TextBox>
&nbsp;<asp:RequiredFieldValidator ID="rfvNombre" runat="server" ControlToValidate="txtNombreSuc" ForeColor="#FF3300">Agregar un nombre</asp:RequiredFieldValidator>
              </td>
              <td>&nbsp;</td>
            </tr>
            <tr>
              <td class="auto-style3">Descripción:</td>
              <td class="auto-style5">
                <asp:TextBox ID="txtDescripcion" runat="server" Height="31px" Width="218px"></asp:TextBox>
                <asp:RequiredFieldValidator ID="rfvDescripcion" runat="server" ControlToValidate="txtDescripcion" ForeColor="#FF3300">Agregar Descripcion</asp:RequiredFieldValidator>
              </td>
              <td>&nbsp;</td>
            </tr>
            <tr>
              <td class="auto-style3">Provincia:</td>
              <td class="auto-style5">
                <asp:DropDownList ID="ddlProvincia" runat="server" Height="22px" Width="224px">
                </asp:DropDownList>
              </td>
              <td>&nbsp;</td>
            </tr>
            <tr>
              <td class="auto-style3">Dirección:</td>
              <td class="auto-style5">
                <asp:TextBox ID="txtDireccion" runat="server" Width="218px"></asp:TextBox>
                <asp:RequiredFieldValidator ID="rfvDireccion" runat="server" ControlToValidate="txtDireccion" ForeColor="#FF3300">Agregar Direccion</asp:RequiredFieldValidator>
              </td>
              <td>&nbsp;</td>
            </tr>
            <tr>
              <td class="auto-style3">&nbsp;</td>
              <td class="auto-style5">
                <br />
                <asp:Button ID="btnAceptar" runat="server" Text="Aceptar" />
              </td>
              <td>&nbsp;</td>
            </tr>
          </table>
        </div>
    </form>
</body>
</html>
