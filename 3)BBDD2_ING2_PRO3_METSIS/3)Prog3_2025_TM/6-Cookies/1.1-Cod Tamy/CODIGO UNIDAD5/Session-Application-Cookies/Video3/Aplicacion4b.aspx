<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion4b.aspx.cs" Inherits="Aplicaciones.Aplicacion4b" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Button ID="btnEliminar" runat="server" OnClick="btnEliminar_Click" Text="Eliminar cookies" />
            <br />
            <br />
            <asp:Label ID="lblResultado" runat="server"></asp:Label>
        </div>
    </form>
</body>
</html>
