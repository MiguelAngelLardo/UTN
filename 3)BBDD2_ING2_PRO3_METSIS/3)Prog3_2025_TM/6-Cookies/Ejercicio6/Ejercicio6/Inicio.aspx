<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Inicio.aspx.cs" Inherits="Ejercicio6.Ej1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <table class="auto-style1">
                <tr>
                    <td style="font-size: large"><strong>Grupo Nº</strong></td>
                </tr>
                <tr>
                    <td>
                        <asp:HyperLink ID="hlEj1" runat="server" NavigateUrl="~/Ej1.aspx">Ejercicio 1</asp:HyperLink>
                    </td>
                </tr>
                <tr>
                    <td>
                        <asp:HyperLink ID="hlEj2" runat="server" NavigateUrl="~/Ej2.aspx">Ejercicio 2</asp:HyperLink>
                    </td>
                </tr>
            </table>
        </div>
    </form>
</body>
</html>
