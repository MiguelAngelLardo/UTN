<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion2a.aspx.cs" Inherits="Video9.Aplicacion2a" %>

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
        .auto-style3 {
            width: 183px;
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
                &nbsp;Se compara que lo que ingrese el usuario sea un numero positivo &gt; 0 (compara contra un valor constante )<br />
                <br />
            </td>
        </tr>
        <tr>
            <td class="style3">
                Cantidad de Paquetes:</td>
            <td class="auto-style3">
                <asp:TextBox ID="txtPaquetes" runat="server"></asp:TextBox>
            </td>
            <td class="style5">
                <asp:CompareValidator ID="cvPaquete" runat="server" ControlToValidate="txtPaquetes" Operator="GreaterThan" Type="Integer" ValueToCompare="0">Ingrese una cantidad válida</asp:CompareValidator>
            </td>
        </tr>
        <tr>
            <td class="style3">
                &nbsp;</td>
            <td class="auto-style3">
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
