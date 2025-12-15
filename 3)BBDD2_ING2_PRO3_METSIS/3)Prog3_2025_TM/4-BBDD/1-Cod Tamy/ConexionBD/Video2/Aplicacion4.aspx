<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion4.aspx.cs" Inherits="AplicacionesUnidad2.Aplicacion4" %>

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
            width: 207px;
        }
        .auto-style3 {
            width: 207px;
            height: 33px;
        }
        .auto-style4 {
            height: 33px;
        }
        .auto-style5 {
            height: 33px;
            width: 301px;
        }
        .auto-style6 {
            width: 301px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            &nbsp;&nbsp;<br />
            <br />
            <table class="auto-style1">
                <tr>
                    <td class="auto-style3">Id Categoria:</td>
                    <td class="auto-style5">
                        <asp:TextBox ID="txtIdCat" runat="server"></asp:TextBox>
                    </td>
                    <td class="auto-style4">&nbsp;</td>
                </tr>
                <tr>
                    <td class="auto-style2">Nombre Categoría:</td>
                    <td class="auto-style6">
                        <asp:TextBox ID="txtNombreCat" runat="server"></asp:TextBox>
                    </td>
                    <td>&nbsp;</td>
                </tr>
                <tr>
                    <td class="auto-style2">Descripcion</td>
                    <td class="auto-style6">
                        <asp:TextBox ID="txtDescripcion" runat="server"></asp:TextBox>
                    </td>
                    <td>&nbsp;</td>
                </tr>
                <tr>
                    <td class="auto-style2">&nbsp;</td>
                    <td class="auto-style6">
                        <asp:Button ID="btnGuardar" runat="server" OnClick="btnGuardar_Click" Text="Guardar" />
                    </td>
                    <td>
                        <asp:Label ID="lblMensaje" runat="server"></asp:Label>
                    </td>
                </tr>
            </table>
        </div>
    </form>
</body>
</html>
