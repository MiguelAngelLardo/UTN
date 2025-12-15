<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="formulario1.aspx.cs" Inherits="ejemploDataList.formulario1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:DataList ID="DataList_Empresa" runat="server" DataKeyField="Dni" DataSourceID="SqlDataSourceEmpresa">
                <ItemTemplate>
                    <asp:Button ID="btnPersonas" runat="server" CommandArgument='<%# Eval("Nombre") + " " + Eval("Apellido") + " " + Eval("Dni") + " " + Eval("Edad") %>' CommandName="eventoBoton" OnCommand="btnPersonas_Command" Text='<%# Eval("Nombre") +" " + Eval("Apellido") %>' />
                    <br />
                    <br />
                </ItemTemplate>
            </asp:DataList>
            <br />
            <br />
            <asp:Label ID="lblMensaje" runat="server"></asp:Label>
            <br />
            <br />
            <asp:SqlDataSource ID="SqlDataSourceEmpresa" runat="server" ConnectionString="<%$ ConnectionStrings:EmpresaConnectionString %>" SelectCommand="SELECT [Dni], [Nombre], [Apellido], [Edad], [Sexo], [ImagenURL] FROM [Personas]"></asp:SqlDataSource>
        </div>
    </form>
</body>
</html>
