<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Ej3.aspx.cs" Inherits="Ej1_Formulario.Ej3" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
          <asp:LinkButton ID="lkbRojo" runat="server" OnClick="lkbRojo_Click">Rojo</asp:LinkButton>
          <br />
          <asp:LinkButton ID="lkbAzul" runat="server" OnClick="lkbAzul_Click">Azul</asp:LinkButton>
          <br />
          <asp:LinkButton ID="lkbVerde" runat="server" OnClick="lkbVerde_Click">Verde</asp:LinkButton>
          <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
          <br />
          <asp:Label ID="lblColoreado" runat="server" Text="Texto  Coloreado"></asp:Label>
          <br />
        </div>
    </form>
</body>
</html>
