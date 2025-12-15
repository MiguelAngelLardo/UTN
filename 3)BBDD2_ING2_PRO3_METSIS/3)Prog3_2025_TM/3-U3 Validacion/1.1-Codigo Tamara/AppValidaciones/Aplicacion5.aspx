<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion5.aspx.cs" Inherits="Video9.Aplicacion5" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">

        .style1
        {
            width: 100%;
        }
        .auto-style2 {
            font-size: x-large;
        }
        .auto-style4 {
            width: 151px;
        }
        .auto-style5 {
            width: 128px;
        }
        .auto-style6 {
            width: 128px;
            height: 54px;
        }
        .auto-style7 {
            width: 151px;
            height: 54px;
        }
        .auto-style8 {
            height: 54px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <table class="style1">
        <tr>
            <td>
                <strong><span class="auto-style2">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; CustomValidator </span></strong>
                <br />
                <br />
                <table class="style1">
                    <tr>
                        <td class="auto-style6">Comentarios:</td>
                        <td class="auto-style7">
                            <asp:TextBox ID="txtComentarios" runat="server" Height="44px" Width="218px" TextMode="MultiLine"></asp:TextBox>
                        </td>
                        <td class="auto-style8">
                            &nbsp;<asp:CustomValidator ID="cvComentarios" runat="server" ControlToValidate="txtComentarios" OnServerValidate="cvComentarios_ServerValidate">Solo se permiten 25 caracteres</asp:CustomValidator>
                            <br />
                        </td>
                    </tr>
                    <tr>
                        <td class="auto-style5">&nbsp;</td>
                        <td class="auto-style4">
                            <asp:Button ID="btnEnviar" runat="server" Text="Enviar" OnClick="btnEnviar_Click" />
                        </td>
                        <td>
                            <asp:Label ID="lblMensaje" runat="server"></asp:Label>
                        </td>
                    </tr>
                </table>
            </td>
        </tr>
        </table>
        </form>
</body>
</html>
