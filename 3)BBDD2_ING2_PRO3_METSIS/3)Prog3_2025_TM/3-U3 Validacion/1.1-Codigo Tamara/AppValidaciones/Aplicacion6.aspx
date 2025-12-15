<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion6.aspx.cs" Inherits="Video9.Aplicacion6" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .style1
        {
            width: 100%;
        }
        .style3
        {
            width: 272px;
        }
        .style4
        {
            width: 217px;
        }
        .style5
        {
            width: 340px;
        }
        .auto-style2 {
            font-size: x-large;
        }
        .auto-style3 {
            width: 272px;
            height: 100px;
        }
        .auto-style4 {
            width: 217px;
            height: 100px;
        }
        .auto-style5 {
            width: 340px;
            height: 100px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <table class="style1">
        <tr>
            <td colspan="3">
                <strong><span class="auto-style2">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ValidationSummary
                <br />
                </span></strong>
            </td>
        </tr>
        <tr>
            <td class="style3">
                Empresa de Envio:</td>
            <td class="style4">
                <asp:DropDownList ID="ddlEmpresa" runat="server">
                    <asp:ListItem>-- Seleccione Empresa --</asp:ListItem>
                    <asp:ListItem>Correo Argentino</asp:ListItem>
                    <asp:ListItem>DHL</asp:ListItem>
                    <asp:ListItem>Federal Express </asp:ListItem>
                </asp:DropDownList>
            </td>
            <td class="style5">
                <asp:RequiredFieldValidator ID="rfvEmpresas" runat="server" ControlToValidate="ddlEmpresa" InitialValue="-- Seleccione Empresa --" ErrorMessage="Elija una empresa de envio">*</asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td class="style3">
                Tipo de Envio:</td>
            <td class="style4">
                <asp:RadioButtonList ID="rblTipoEnvio" runat="server">
                    <asp:ListItem>En el Dia</asp:ListItem>
                    <asp:ListItem>Dos dias</asp:ListItem>
                    <asp:ListItem>Semana</asp:ListItem>
                    <asp:ListItem>Dos/Tres semanas</asp:ListItem>
                </asp:RadioButtonList>
            </td>
            <td class="style5">
                <asp:RequiredFieldValidator ID="rfvTipoEnvio" runat="server" ControlToValidate="rblTipoEnvio" ErrorMessage="Elija una empresa de envío">*</asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td class="auto-style3">
                Comentarios:</td>
            <td class="auto-style4">
                <asp:TextBox ID="txtComentarios" runat="server" Height="90px" 
                    TextMode="MultiLine" Width="170px"></asp:TextBox>
            </td>
            <td class="auto-style5">
                <asp:RequiredFieldValidator ID="rfvComentarios" runat="server" ControlToValidate="txtComentarios" ErrorMessage="Ingrese un comentario">*</asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td class="style3">
                Cantidad de Paquetes:</td>
            <td class="style4">
                <asp:TextBox ID="txtPaquetes" runat="server" Height="18px" Width="202px"></asp:TextBox>
            </td>
            <td class="style5">
                 <asp:CompareValidator ID="cvPaquetes" runat="server" Operator="GreaterThan" Type="Integer" ValueToCompare="0" ControlToValidate="txtPaquetes" ErrorMessage="Número de paquetes inválidos">*</asp:CompareValidator>
&nbsp;&nbsp;&nbsp;&nbsp;
                <br />
                <asp:RequiredFieldValidator ID="rfvPaquetes" runat="server" ControlToValidate="txtPaquetes" ErrorMessage="No se ha ingresado un numero de paquetes">*</asp:RequiredFieldValidator>
                <br />
            </td>
        </tr>
        <tr>
            <td class="style3">
                Numero de telefono:</td>
            <td class="style4">
                <asp:TextBox ID="txtTelefono" runat="server" Height="18px" Width="202px"></asp:TextBox>
            </td>
            <td class="style5">
                <asp:RegularExpressionValidator ID="revTelefono" runat="server" ControlToValidate="txtTelefono" ValidationExpression="^\d+$" ErrorMessage="Número de telefono inválido">*</asp:RegularExpressionValidator>
                <br />
                <asp:RequiredFieldValidator ID="rfvTelefono" runat="server" ControlToValidate="txtTelefono" ErrorMessage="No se ha ingresado un número de teléfono">*</asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td class="style3">
                &nbsp;</td>
            <td class="style4">
                <asp:Button ID="btnEnviar" runat="server" Text="Enviar" OnClick="btnEnviar_Click" />
            </td>
            <td class="style5">
                &nbsp;</td>
        </tr>
    </table>
        <p>
                <asp:Label ID="lblMensaje" runat="server"></asp:Label>
            </p>
        <asp:ValidationSummary ID="ValidationSummary" runat="server" ShowMessageBox="True" />
    </form>
</body>
</html>

