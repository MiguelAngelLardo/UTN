<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Ej4a_Ppal.aspx.cs" Inherits="Tp2Ej1_Formulario.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
          Usuario:&nbsp;
          <asp:TextBox ID="txtUsuario" runat="server"></asp:TextBox>
          <br />
          Clave:&nbsp;&nbsp;&nbsp;&nbsp;
          <asp:TextBox ID="txtClave" runat="server" TextMode="Password"></asp:TextBox>
          <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
          <asp:Button ID="btnValidar" runat="server" OnClick="btnValidar_Click" Text="Button" />
          <br />
        </div>
    </form>
</body>
</html>
