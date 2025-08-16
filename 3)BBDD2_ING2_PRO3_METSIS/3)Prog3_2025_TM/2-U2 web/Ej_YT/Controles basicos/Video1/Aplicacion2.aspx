<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion2.aspx.cs" Inherits="MiPrimerSitioWeb.Aplicacion2" %>

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
            height: 31px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            &nbsp;&nbsp; Introduce un numero:&nbsp;
            <asp:TextBox ID="txtNumero" runat="server"></asp:TextBox>
&nbsp;
            <asp:Button ID="btnMultiplicar" runat="server" Text="Ver tabla de multiplicar" OnClick="btnMultiplicar_Click" />
            <br />
            <br />
&nbsp;&nbsp;&nbsp;
            <asp:Label ID="lblTabla" runat="server"></asp:Label>
            <br />
            <br />
            <br />
&nbsp;&nbsp;&nbsp;
         
        </div>
    </form>
</body>
</html>
