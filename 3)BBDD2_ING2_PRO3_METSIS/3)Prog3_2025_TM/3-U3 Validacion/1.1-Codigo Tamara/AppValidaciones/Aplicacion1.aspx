<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion1.aspx.cs" Inherits="Video9.Aplicacion1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .style1
        {
            width: 100%;
        }
        .style2
        {
            width: 339px;
        }
        .auto-style1 {
            font-size: large;
        }
        .auto-style2 {
            font-size: x-large;
        }
        .auto-style3 {
            width: 224px;
        }
        .auto-style4 {
            width: 162px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server" method="post">
    <table class="style1">
        <tr>
            <td colspan="3">
                <strong><span class="auto-style1">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </span><span class="auto-style2">RequiredFieldValidator</span></strong><br />
                <br />
                <br />
            </td>
        </tr>
        <tr>
            <td class="auto-style4">
                Empresa de Envio:</td>
            <td class="auto-style3">
                <asp:DropDownList ID="ddlEmpresa" runat="server" CausesValidation="True">
                    <asp:ListItem>-- Seleccione Empresa --</asp:ListItem>
                    <asp:ListItem>Correo Argentino</asp:ListItem>
                    <asp:ListItem>DHL</asp:ListItem>
                    <asp:ListItem>Federal Express </asp:ListItem>
                </asp:DropDownList>
            </td>
            <td>
                <asp:RequiredFieldValidator ID="rfvEmpresas" runat="server" ControlToValidate="ddlEmpresa" InitialValue="-- Seleccione Empresa --">Elija una empresa de envio</asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td class="auto-style4">
                Tipo de Envio:</td>
            <td class="auto-style3">
                <asp:RadioButtonList ID="rblTipoEnvio" runat="server" CausesValidation="True">
                    <asp:ListItem>En el Dia</asp:ListItem>
                    <asp:ListItem>Dos dias</asp:ListItem>
                    <asp:ListItem>Semana</asp:ListItem>
                    <asp:ListItem>Dos/Tres semanas</asp:ListItem>
                </asp:RadioButtonList>
            </td>
            <td>
                <asp:RequiredFieldValidator ID="rfvTipoEnvio" runat="server" ControlToValidate="rblTipoEnvio">Elija un tipo en envio</asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td class="auto-style4">
                Comentarios:</td>
            <td class="auto-style3">
                <asp:TextBox ID="txtComentarios" runat="server" Height="90px" 
                    TextMode="MultiLine" Width="170px" CausesValidation="True"></asp:TextBox>
            </td>
            <td>
                <asp:RequiredFieldValidator ID="rfvComentarios" runat="server" ControlToValidate="txtComentarios">Ingrese un comentario</asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td class="auto-style4">
                &nbsp;</td>
            <td class="auto-style3">
                <asp:Button ID="btnEnviar" runat="server"   Text="Enviar" OnClick="btnEnviar_Click" />
            </td>
            <td>
                &nbsp;</td>
        </tr>
    </table>
        <p>
            &nbsp;</p>
        <p>
                <asp:Label ID="lblMensaje" runat="server"></asp:Label>
            </p>
    </form>
    </body>
</html>