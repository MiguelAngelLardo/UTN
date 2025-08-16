<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Ej3.aspx.cs" Inherits="Tp4.Ej3" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
  <style type="text/css">
    .auto-style1 {
      width: 100%;
    }
    .auto-style3 {
      width: 118px;
    }
    .auto-style4 {
      width: 121px;
    }
    .auto-style5 {
      width: 123px;
    }
  </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
          <table class="auto-style1">
            <tr>
              <td class="auto-style3">Seleccionar Tema:</td>
              <td>
                <asp:DropDownList ID="ddlTemas" runat="server">
                </asp:DropDownList>
              </td>
            </tr>
          </table>
          <table class="auto-style1">
            <tr>
              <td class="auto-style4">&nbsp;</td>
              <td>&nbsp;</td>
            </tr>
          </table>
          <table class="auto-style1">
            <tr>
              <td class="auto-style5">
                <asp:LinkButton ID="lbVerLibros" runat="server" OnClick="lbVerLibros_Click">Ver libros</asp:LinkButton>
              </td>
              <td>&nbsp;</td>
            </tr>
          </table>
        </div>
    </form>
</body>
</html>
