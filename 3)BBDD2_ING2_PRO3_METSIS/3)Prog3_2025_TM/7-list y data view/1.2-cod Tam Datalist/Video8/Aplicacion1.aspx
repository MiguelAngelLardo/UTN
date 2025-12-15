<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion1.aspx.cs" Inherits="Video8.Aplicacion1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <strong>Los siguientes ejemplos utilizan la base de datos Empresa </strong>
            <br />
            <br />
            <asp:DataList ID="dlPersonas" runat="server" DataKeyField="Dni" DataSourceID="SqlDataSource1">
                <ItemTemplate>
                    Nombre:
                    <asp:Label ID="NombreLabel" runat="server" Text='<%# Eval("Nombre") %>' />
                    <br />
                    Dni:
                    <asp:Label ID="DniLabel" runat="server" Text='<%# Eval("Dni") %>' />
                    <br />
                    Apellido:
                    <asp:Label ID="ApellidoLabel" runat="server" Text='<%# Eval("Apellido") %>' />
                    <br />
                    Edad:
                    <asp:Label ID="EdadLabel" runat="server" Text='<%# Eval("Edad") %>' />
                    <br />
                    Sexo:
                    <asp:Label ID="SexoLabel" runat="server" Text='<%# Eval("Sexo") %>' />
                    <br />
<br />
                </ItemTemplate>
            </asp:DataList>
            <br />
            <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:EmpresaConnectionString %>" SelectCommand="SELECT [Nombre], [Dni], [Apellido], [Edad], [Sexo] FROM [Personas]"></asp:SqlDataSource>
        </div>
    </form>
</body>
</html>
