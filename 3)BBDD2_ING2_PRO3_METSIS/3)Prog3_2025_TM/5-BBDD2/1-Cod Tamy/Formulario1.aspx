<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Formulario1.aspx.cs" Inherits="AccesoDatos2.Formulario1" %>

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
            width: 229px;
        }
        .auto-style3 {
            width: 170px;
        }
        .auto-style4 {
            width: 249px;
        }
        .auto-style5 {
            width: 181px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <br />
            <strong>AGREGAR PRODUCTO</strong><br />
        </div>
        <table class="auto-style1">
            <tr>
                <td class="auto-style2">ID PRODUCTO</td>
                <td class="auto-style3">
                    <asp:TextBox ID="txtIdProducto" runat="server" OnTextChanged="TextBox1_TextChanged"></asp:TextBox>
                </td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style2">NOMBRE PRODUCTO</td>
                <td class="auto-style3">
                    <asp:TextBox ID="txtNombreProdcuto" runat="server"></asp:TextBox>
                </td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style2">SUSPENDIDO</td>
                <td class="auto-style3">
                    <asp:CheckBox ID="chkSuspendido" runat="server" />
                </td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style2">&nbsp;</td>
                <td class="auto-style3">&nbsp;</td>
                <td>
                    <asp:Button ID="btnAgregar" runat="server" OnClick="btnAgregar_Click" Text="Agregar" />
                </td>
            </tr>
            <tr>
                <td class="auto-style2">&nbsp;</td>
                <td class="auto-style3">&nbsp;</td>
                <td>&nbsp;</td>
            </tr>
        </table>
        <p>
            &nbsp;</p>
        <p>
            <strong>ELIMINAR PRODUCTO</strong></p>
        <table class="auto-style1">
            <tr>
                <td class="auto-style4">ID PRODUCTO</td>
                <td class="auto-style5">
                    <asp:TextBox ID="txtIdEliminar" runat="server"></asp:TextBox>
                </td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style4">&nbsp;</td>
                <td class="auto-style5">&nbsp;</td>
                <td>
                    <asp:Button ID="btnEliminar" runat="server" OnClick="btnEliminar_Click" Text="Eliminar" />
                </td>
            </tr>
            <tr>
                <td class="auto-style4">&nbsp;</td>
                <td class="auto-style5">&nbsp;</td>
                <td>&nbsp;</td>
            </tr>
        </table>
    </form>
</body>
</html>
