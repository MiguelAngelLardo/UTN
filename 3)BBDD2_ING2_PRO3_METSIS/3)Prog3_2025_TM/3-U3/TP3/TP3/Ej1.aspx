<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Ej1.aspx.cs" Inherits="TP3.WebForm1" %>

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
      width: 139px;
    }
    .auto-style3 {
      width: 129px;
    }
    .auto-style4 {
      width: 129px;
      height: 23px;
    }
    .auto-style5 {
      width: 139px;
      height: 23px;
    }
    .auto-style6 {
      height: 23px;
    }
  </style>
</head>
<body>
    <form id="form1" runat="server">
        <table class="auto-style1">
          <tr>
            <td class="auto-style3">&nbsp;</td>
            <td class="auto-style2"><strong>Localidades<br />
              </strong></td>
            <td>&nbsp;</td>
          </tr>
          <tr>
            <td class="auto-style3">Nombre Localidad:</td>
            <td class="auto-style2">
              <asp:TextBox ID="txtLocalidad" runat="server" ValidationGroup="G1" Width="126px"></asp:TextBox>
            </td>
            <td>
              <asp:RequiredFieldValidator ID="rfvLocalidad" runat="server" ControlToValidate="txtLocalidad" ValidationGroup="G1">Ingrese una localidad</asp:RequiredFieldValidator>
            </td>
          </tr>
          <tr>
            <td class="auto-style3">&nbsp;</td>
            <td class="auto-style2">
              <br />
              <asp:Button ID="btnLocalidad" runat="server" OnClick="btnLocalidad_Click" Text="Guardar Localidad" ValidationGroup="G1" Width="114px" />
            </td>
            <td>&nbsp;</td>
          </tr>
          <tr>
            <td class="auto-style3">&nbsp;</td>
            <td class="auto-style2"><strong>
              <br />
              Usuarios<br />
              </strong></td>
            <td>&nbsp;</td>
          </tr>
          <tr>
            <td class="auto-style3" style="font-weight: normal">Nombre usuario</td>
            <td class="auto-style2">
          <asp:TextBox ID="txtNombreUsuario" runat="server" ValidationGroup="G2" style="margin-left: 0px" Width="124px"></asp:TextBox>
            </td>
            <td><asp:RequiredFieldValidator ID="rfvNombre" runat="server" ControlToValidate="txtNombreUsuario" ValidationGroup="G2">Debe ingresar un nombre</asp:RequiredFieldValidator>
            </td>
          </tr>
          <tr>
            <td class="auto-style4">Contraseña:</td>
            <td class="auto-style5">
          <asp:TextBox ID="txtContrasenia" runat="server" ValidationGroup="G2" style="margin-left: 0px" Width="124px" TextMode="Password"></asp:TextBox>
            </td>
            <td class="auto-style6">
              <asp:RequiredFieldValidator ID="rfvContrasenia" runat="server" ControlToValidate="txtContrasenia" ValidationGroup="G2">Debe Ingresar una contraseña</asp:RequiredFieldValidator>
            </td>
          </tr>
          <tr>
            <td class="auto-style3">Repetir Contraseña:</td>
            <td class="auto-style2">
          <asp:TextBox ID="txtRepetirContrasenia" runat="server" ValidationGroup="G2" style="margin-left: 0px" Width="124px" TextMode="Password"></asp:TextBox>
            </td>
            <td style="font-weight: 700">
          <asp:CompareValidator ID="cvContrasenia2" runat="server" ControlToCompare="txtContrasenia" ControlToValidate="txtRepetirContrasenia" ValidationGroup="G2" Font-Bold="False">Contraseña incorrecta</asp:CompareValidator>
            </td>
          </tr>
          <tr>
            <td class="auto-style3">Correo electronico:&nbsp;</td>
            <td class="auto-style2"> <asp:TextBox ID="txtCorreo" runat="server" style="margin-bottom: 0px; margin-left: 0px;" ValidationGroup="G2" Width="124px"></asp:TextBox>
            </td>
            <td><asp:RegularExpressionValidator ID="rgMail" runat="server" ControlToValidate="txtCorreo" ValidationExpression="\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*" ValidationGroup="G2">Debe tener el formato mail</asp:RegularExpressionValidator>
              <br />
              <asp:RequiredFieldValidator ID="rfvMail" runat="server" ControlToValidate="txtCorreo" ValidationGroup="G2">Ingrese un Mail</asp:RequiredFieldValidator>
            </td>
          </tr>
          <tr>
            <td class="auto-style3">CP:</td>
            <td class="auto-style2">
          <asp:TextBox ID="txtCodigoPostal" runat="server" ValidationGroup="G2" style="margin-left: 0px" Width="124px"></asp:TextBox>
            </td>
            <td>
          <asp:CustomValidator ID="cvCodigoPostal" runat="server" ControlToValidate="txtCodigoPostal" OnServerValidate="cvCodigoPostal_ServerValidate" ValidationGroup="G2">Solo 4 digitos</asp:CustomValidator>
              <br />
              <asp:RequiredFieldValidator ID="rfvCodigoPostal" runat="server" ControlToValidate="txtCodigoPostal" ValidationGroup="G2">Ingrese un CP</asp:RequiredFieldValidator>
            </td>
          </tr>
          <tr>
            <td class="auto-style3">Localidades:</td>
            <td class="auto-style2">
          <asp:DropDownList ID="ddlLocalidades" runat="server" ValidationGroup="G2" Height="18px" style="margin-left: 0px" Width="130px">
            <asp:ListItem>-- Seleccione Localidad --</asp:ListItem>
          </asp:DropDownList>
            </td>
            <td>
              <asp:RequiredFieldValidator ID="rfvLocalidades" runat="server" ControlToValidate="ddlLocalidades" InitialValue="-- Seleccione Localidad --" ValidationGroup="G2">Seleccione una localidad</asp:RequiredFieldValidator>
            </td>
          </tr>
          <tr>
            <td class="auto-style4"></td>
            <td class="auto-style5"></td>
            <td class="auto-style6"></td>
          </tr>
          <tr>
            <td class="auto-style3">&nbsp;</td>
            <td class="auto-style2">
          <asp:Button ID="btnGuardarUsuario" runat="server" Text="Guardar Usuario" ValidateRequestMode="Enabled" ValidationGroup="G2" OnClick="btnGuardarUsuario_Click" Width="114px" />
            </td>
            <td>
          <asp:Label ID="lblBienvenido" runat="server" Font-Bold="True"></asp:Label>
            </td>
          </tr>
          <tr>
          <td class="auto-style3">
            <asp:Button ID="btnInicio" runat="server" Text="Ir a inicio.aspx" Width="100px" OnClick="btnInicio_Click" />
            </td>
          <td class="auto-style2">
            &nbsp;</td>
          <td>
            &nbsp;</td>
          </tr>
        </table>
    </form>
    <p>
      &nbsp;</p>
    <p>
      &nbsp;</p>
    <p>
      &nbsp;</p>
</body>
</html>
