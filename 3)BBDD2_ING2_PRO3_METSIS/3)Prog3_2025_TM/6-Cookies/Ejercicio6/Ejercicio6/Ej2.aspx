<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Ej2.aspx.cs" Inherits="Ejercicio6.Ej2" %>

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
            width: 157px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <table class="auto-style1">
            <tr>
                <td class="auto-style2" style="font-size: x-large"><strong>Inicio</strong></td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style2">&nbsp;</td>
                <td>
                    <asp:HyperLink ID="hlSelecProd" runat="server" NavigateUrl="~/SeleccionarP.aspx">Seleccionar Productos</asp:HyperLink>
                </td>
            </tr>
            <tr>
                <td class="auto-style2">&nbsp;</td>
                <td>
                    <asp:LinkButton ID="lbEliminarProd" runat="server" OnClick="lbEliminarProd_Click">Eliminar Productos seleccionados</asp:LinkButton>
                </td>
            </tr>
            <tr>
                <td class="auto-style2">&nbsp;</td>
                <td>
                    <asp:HyperLink ID="hlMostrarPRod" runat="server" NavigateUrl="~/MostrarP.aspx">Mostrar Productos</asp:HyperLink>
                </td>
            </tr>
        </table>
        <div>
        </div>
    </form>
</body>
</html>
