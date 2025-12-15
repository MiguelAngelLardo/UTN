<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="ejemplo4a.aspx.cs" Inherits="SessionCookiesApplicacion.ejemplo4a" %>

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
            width: 45px;
        }
        .auto-style3 {
            width: 137px;
        }
        .auto-style4 {
            width: 45px;
            height: 23px;
        }
        .auto-style5 {
            width: 137px;
            height: 23px;
        }
        .auto-style6 {
            height: 23px;
        }
        .auto-style7 {
            margin-bottom: 0px;
        }
        .auto-style8 {
            width: 21px;
        }
        .auto-style9 {
            height: 23px;
            width: 21px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
        </div>
        <table class="auto-style1">
            <tr>
                <td class="auto-style2">&nbsp;</td>
                <td class="auto-style3">Ingrese nombre</td>
                <td class="auto-style8">&nbsp;</td>
                <td>
                    <asp:TextBox ID="txtNombre" runat="server"></asp:TextBox>
                </td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style4"></td>
                <td class="auto-style5"></td>
                <td class="auto-style9"></td>
                <td class="auto-style6"></td>
                <td class="auto-style6"></td>
            </tr>
            <tr>
                <td class="auto-style2">&nbsp;</td>
                <td class="auto-style3">Ingrese contaseña</td>
                <td class="auto-style8">&nbsp;</td>
                <td>
                    <asp:TextBox ID="txtContrasenia" runat="server"></asp:TextBox>
                </td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style2">&nbsp;</td>
                <td class="auto-style3">&nbsp;</td>
                <td class="auto-style8">&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style2">&nbsp;</td>
                <td class="auto-style3">&nbsp;</td>
                <td class="auto-style8">&nbsp;</td>
                <td>
                    <asp:Button ID="btnIniciarSession" runat="server" CssClass="auto-style7" OnClick="btnIniciarSession_Click" Text="Iniciar sesion" />
                </td>
                <td>&nbsp;</td>
            </tr>
        </table>
    </form>
</body>
</html>
