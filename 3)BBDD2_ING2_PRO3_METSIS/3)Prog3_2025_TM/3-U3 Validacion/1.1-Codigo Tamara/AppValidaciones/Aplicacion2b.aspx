<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion2b.aspx.cs" Inherits="Video9.Aplicacion2b" %>

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
            width: 193px;
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
        </style>
</head>
<body>
    <form id="form1" runat="server">
    <table class="style1">
        <tr>
            <td colspan="3">
                <strong><span class="auto-style2">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; CompareValidator </span></strong>
                <br />
                <br />
                CompareValidator, compara los dos controles para saber si en ambos el usuario ingreso lo mismo<br />
                <br />
            </td>
        </tr>
        <tr>
            <td class="style3">
                Contraseña:</td>
            <td class="style4">
                <asp:TextBox ID="txtContraseña1" runat="server"></asp:TextBox>
            </td>
            <td class="style5">
                <br />
            </td>
        </tr>
        <tr>
            <td class="style3">
                Repita contraseña:</td>
            <td class="style4">
                <asp:TextBox ID="txtContraseña2" runat="server"></asp:TextBox>
            </td>
            <td class="style5">
                <asp:CompareValidator ID="cvContrasenia" runat="server" ControlToCompare="txtContraseña1" ControlToValidate="txtContraseña2">Contraseña incorrecta</asp:CompareValidator>
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
    </form>
</body>
</html>
