<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Ej1.aspx.cs" Inherits="Tp4.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
  <style type="text/css">
    .auto-style1 {
      width: 48%;
    }
    .auto-style2 {
      width: 151px;
    }
  </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
          <table class="auto-style1">
            <tr>
              <td class="auto-style2" style="text-decoration: underline">DESTINO INICIO</td>
              <td>&nbsp;</td>
            </tr>
            <tr>
              <td class="auto-style2">
                <br />
                PROVINCIA:</td>
              <td>
                <asp:DropDownList ID="ddlProvInicio" runat="server" Width="155px" OnSelectedIndexChanged="ddlProvInicio_SelectedIndexChanged">
                  <asp:ListItem>--Seleccionar--</asp:ListItem>
                </asp:DropDownList>
              </td>
            </tr>
            <tr>
              <td class="auto-style2">lOCALIDAD</td>
              <td>
                <asp:DropDownList ID="ddlLocInicio" runat="server" Width="125px" OnSelectedIndexChanged="ddlLocInicio_SelectedIndexChanged">
                  <asp:ListItem>--Seleccionar--</asp:ListItem>
                </asp:DropDownList>
              </td>
            </tr>
            <tr>
              <td class="auto-style2" style="text-decoration: underline">
                <br />
                DESTINO FINAL</td>
              <td>
                <asp:Label ID="lblPrueba" runat="server"></asp:Label>
              </td>
            </tr>
            <tr>
              <td class="auto-style2">
                <br />
                PROVINCIA:</td>
              <td>
                <asp:DropDownList ID="ddlProvFinal" runat="server" Height="18px" Width="155px" OnSelectedIndexChanged="ddlProvFinal_SelectedIndexChanged">
                  <asp:ListItem>--Seleccionar--</asp:ListItem>
                </asp:DropDownList>
              </td>
            </tr>
            <tr>
              <td class="auto-style2">LOCALIDAD:</td>
              <td>
                <asp:DropDownList ID="ddlLocFinal" runat="server" Height="16px" Width="125px">
                  <asp:ListItem>--Seleccionar--</asp:ListItem>
                </asp:DropDownList>
              </td>
            </tr>
          </table>
        </div>
    </form>
    <p>
      &nbsp;</p>
</body>
</html>
