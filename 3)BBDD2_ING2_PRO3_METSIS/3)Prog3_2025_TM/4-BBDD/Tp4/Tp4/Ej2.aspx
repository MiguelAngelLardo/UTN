<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Ej2.aspx.cs" Inherits="Tp4.Ej2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
  <style type="text/css">
    .auto-style1 {
      width: 59%;
    }
    .auto-style2 {
      width: 85px;
    }
    .auto-style3 {
      width: 105px;
    }
    .auto-style4 {
      width: 343px;
    }
  </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
          <table class="auto-style1">
            <tr>
              <td class="auto-style2">Id Producto: </td>
              <td class="auto-style3">
                <asp:DropDownList ID="ddlProducto" runat="server">
                </asp:DropDownList>
              </td>
              <td class="auto-style4">
                <asp:TextBox ID="txtProducto" runat="server" Width="290px"></asp:TextBox>
              </td>
            </tr>
            <tr>
              <td class="auto-style2">IdCategoria: </td>
              <td class="auto-style3">
                <asp:DropDownList ID="ddlCategoria" runat="server">
                </asp:DropDownList>
              </td>
              <td class="auto-style4">
                <asp:TextBox ID="txtCategoria" runat="server" Width="290px"></asp:TextBox>
              </td>
            </tr>
            <tr>
              <td class="auto-style2">&nbsp;</td>
              <td class="auto-style3">&nbsp;</td>
              <td class="auto-style4">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                <asp:Button ID="btnFiltrar" runat="server" Text="Filtrar" OnClick="btnFiltrar_Click" />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                <asp:Button ID="btnQuitarFiltro" runat="server" Text="Quitar filtro" OnClick="btnQuitarFiltro_Click" />
                <br />
              </td>
            </tr>
          </table>
        </div>
        <br />
        <asp:GridView ID="grdNeptuno" runat="server" Width="642px">
        </asp:GridView>
    </form>
</body>
</html>
