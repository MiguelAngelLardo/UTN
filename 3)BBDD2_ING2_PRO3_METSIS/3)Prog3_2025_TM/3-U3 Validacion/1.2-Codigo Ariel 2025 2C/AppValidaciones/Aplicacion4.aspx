<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion4.aspx.cs" Inherits="Video9.Aplicacion4" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml"><head runat="server">
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
        .auto-style3 {
            width: 228px;
        }
        .auto-style4 {
            width: 151px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <table class="style1">
        <tr>
            <td>
                <strong><span class="auto-style2">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; RegularExpressionValidator </span></strong>
                <br />
                <br />
                <table class="style1">
                    <tr>
                        <td class="auto-style3">Ingrese números:</td>
                        <td class="auto-style4">
                            <asp:TextBox ID="txtNumeros" runat="server"></asp:TextBox>
                        </td>
                        <td>
                            <asp:RegularExpressionValidator ID="revNumeros" runat="server" ControlToValidate="txtNumeros" ValidationExpression="^[0-9,$]*$">Ingrese solo numeros</asp:RegularExpressionValidator>
                        </td>
                    </tr>
                    <tr>
                        <td class="auto-style3">&nbsp;</td>
                        <td class="auto-style4">
                <asp:Button ID="btnEnviar" runat="server" Text="Enviar" OnClick="btnEnviar_Click"  />
                        </td>
                        <td>&nbsp;</td>
                    </tr>
                </table>
            </td>
        </tr>
        </table>
        <asp:Label ID="lblMensaje" runat="server"></asp:Label>
        </form>
</body>
</html>
