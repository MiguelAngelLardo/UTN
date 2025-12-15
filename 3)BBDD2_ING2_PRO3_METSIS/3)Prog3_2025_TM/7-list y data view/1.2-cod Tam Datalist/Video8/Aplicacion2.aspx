<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion2.aspx.cs" Inherits="Video8.Aplicacion2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <br />
            <asp:DataList ID="dlPersonas" runat="server" DataKeyField="Dni" DataSourceID="SqlDataSource1">
                <ItemTemplate>
                    <asp:Button ID="btnPersonas" runat="server" CommandArgument='<%# Eval("Nombre")+" "+Eval("Apellido")+" "+Eval("Dni") %>' CommandName="comandoBoton" OnCommand="btnPersonas_Command" Text='<%# Eval("Nombre")+" "+Eval("Apellido") %>' Width="250px" />
                    <br />
                </ItemTemplate>
            </asp:DataList>
            <br />
            <asp:Label ID="lblMensaje" runat="server"></asp:Label>
            <br />
            <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:EmpresaConnectionString %>" SelectCommand="SELECT [Dni], [Nombre], [Apellido], [Edad], [Sexo], [ImagenURL], [Direccion], [Telefono] FROM [Personas]"></asp:SqlDataSource>
        </div>
    </form>
</body>
</html>
