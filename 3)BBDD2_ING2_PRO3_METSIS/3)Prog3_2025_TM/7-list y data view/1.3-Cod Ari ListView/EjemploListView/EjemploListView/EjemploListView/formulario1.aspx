<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="formulario1.aspx.cs" Inherits="EjemploListView.formulario1" %>

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
            <asp:Button ID="btnOrdenar" runat="server" OnClick="btnOrdenar_Click" Text="Ordenar por nombre" />
            <br />
            <br />
            <asp:ListView ID="ListViewEmpresa" runat="server" DataKeyNames="Dni" GroupItemCount="3">
<%--                <AlternatingItemTemplate>
                    <td runat="server" style="background-color: #FFFFFF;color: #284775;">Dni:
                        <asp:Label ID="DniLabel" runat="server" Text='<%# Eval("Dni") %>' />
                        <br />Nombre:
                        <asp:Label ID="NombreLabel" runat="server" Text='<%# Eval("Nombre") %>' />
                        <br />Apellido:
                        <asp:Label ID="ApellidoLabel" runat="server" Text='<%# Eval("Apellido") %>' />
                        <br />Edad:
                        <asp:Label ID="EdadLabel" runat="server" Text='<%# Eval("Edad") %>' />
                        <br />Sexo:
                        <asp:Label ID="SexoLabel" runat="server" Text='<%# Eval("Sexo") %>' />
                        <br />ImagenURL:
                        <asp:Label ID="ImagenURLLabel" runat="server" Text='<%# Eval("ImagenURL") %>' />
                        <br /></td>
                </AlternatingItemTemplate>--%>
                <EditItemTemplate>
                    <td runat="server" style="background-color: #999999;">Dni:
                        <asp:Label ID="DniLabel1" runat="server" Text='<%# Eval("Dni") %>' />
                        <br />Nombre:
                        <asp:TextBox ID="NombreTextBox" runat="server" Text='<%# Bind("Nombre") %>' />
                        <br />Apellido:
                        <asp:TextBox ID="ApellidoTextBox" runat="server" Text='<%# Bind("Apellido") %>' />
                        <br />Edad:
                        <asp:TextBox ID="EdadTextBox" runat="server" Text='<%# Bind("Edad") %>' />
                        <br />Sexo:
                        <asp:TextBox ID="SexoTextBox" runat="server" Text='<%# Bind("Sexo") %>' />
                        <br />ImagenURL:
                        <asp:TextBox ID="ImagenURLTextBox" runat="server" Text='<%# Bind("ImagenURL") %>' />
                        <br />
                        <asp:Button ID="UpdateButton" runat="server" CommandName="Update" Text="Actualizar" />
                        <br />
                        <asp:Button ID="CancelButton" runat="server" CommandName="Cancel" Text="Cancelar" />
                        <br /></td>
                </EditItemTemplate>
                <EmptyDataTemplate>
                    <table runat="server" style="background-color: #FFFFFF;border-collapse: collapse;border-color: #999999;border-style:none;border-width:1px;">
                        <tr>
                            <td>No se han devuelto datos.</td>
                        </tr>
                    </table>
                </EmptyDataTemplate>
                <EmptyItemTemplate>
<td runat="server" />
                </EmptyItemTemplate>
                <GroupTemplate>
                    <tr id="itemPlaceholderContainer" runat="server">
                        <td id="itemPlaceholder" runat="server"></td>
                    </tr>
                </GroupTemplate>
                <InsertItemTemplate>
                    <td runat="server" style="">Dni:
                        <asp:TextBox ID="DniTextBox" runat="server" Text='<%# Bind("Dni") %>' />
                        <br />Nombre:
                        <asp:TextBox ID="NombreTextBox" runat="server" Text='<%# Bind("Nombre") %>' />
                        <br />Apellido:
                        <asp:TextBox ID="ApellidoTextBox" runat="server" Text='<%# Bind("Apellido") %>' />
                        <br />Edad:
                        <asp:TextBox ID="EdadTextBox" runat="server" Text='<%# Bind("Edad") %>' />
                        <br />Sexo:
                        <asp:TextBox ID="SexoTextBox" runat="server" Text='<%# Bind("Sexo") %>' />
                        <br />ImagenURL:
                        <asp:TextBox ID="ImagenURLTextBox" runat="server" Text='<%# Bind("ImagenURL") %>' />
                        <br />
                        <asp:Button ID="InsertButton" runat="server" CommandName="Insert" Text="Insertar" />
                        <br />
                        <asp:Button ID="CancelButton" runat="server" CommandName="Cancel" Text="Borrar" />
                        <br /></td>
                </InsertItemTemplate>
                <ItemTemplate>
                    <td runat="server" style="background-color: #E0FFFF;color: #333333;">Dni:
                        <asp:Label ID="DniLabel" runat="server" Text='<%# Eval("Dni") %>' />
                        <br />Nombre:
                        <asp:Label ID="NombreLabel" runat="server" Text='<%# Eval("Nombre") %>' />
                        <br />Apellido:
                        <asp:Label ID="ApellidoLabel" runat="server" Text='<%# Eval("Apellido") %>' />
                        <br />Edad:
                        <asp:Label ID="EdadLabel" runat="server" Text='<%# Eval("Edad") %>' />
                        <br />Sexo:
                        <asp:Label ID="SexoLabel" runat="server" Text='<%# Eval("Sexo") %>' />
                        <br />Imagen :
                        <asp:ImageButton ID="ImageButton1" runat="server" ImageUrl='<%# Eval("ImagenURL") %>' />
                        <br />
                        <br />
                        <asp:Button ID="btnSeleccionar" runat="server" CommandArgument='<%# Eval("Nombre") + " - " + Eval("Apellido") %>' CommandName="eventoSeleccionar" OnCommand="btnSeleccionar_Command" Text="Seleccionar" />
                        <br />
                        <br />
                        <asp:CheckBox ID="CheckBoxEmpresa" runat="server" />
                        <br />
                        <br />
                    </td>
                </ItemTemplate>
                <LayoutTemplate>
                    <table runat="server">
                        <tr runat="server">
                            <td runat="server">
                                <table id="groupPlaceholderContainer" runat="server" border="1" style="background-color: #FFFFFF;border-collapse: collapse;border-color: #999999;border-style:none;border-width:1px;font-family: Verdana, Arial, Helvetica, sans-serif;">
                                    <tr id="groupPlaceholder" runat="server">
                                    </tr>
                                </table>
                            </td>
                        </tr>
                        <tr runat="server">
                            <td runat="server" style="text-align: center;background-color: #5D7B9D;font-family: Verdana, Arial, Helvetica, sans-serif;color: #FFFFFF">
                                <asp:DataPager ID="DataPager1" runat="server" PageSize="4">
                                    <Fields>
                                        <asp:NextPreviousPagerField ButtonType="Button" ShowFirstPageButton="True" ShowLastPageButton="True" />
                                    </Fields>
                                </asp:DataPager>
                            </td>
                        </tr>
                    </table>
                </LayoutTemplate>
                <SelectedItemTemplate>
                    <td runat="server" style="background-color: #E2DED6;font-weight: bold;color: #333333;">Dni:
                        <asp:Label ID="DniLabel" runat="server" Text='<%# Eval("Dni") %>' />
                        <br />Nombre:
                        <asp:Label ID="NombreLabel" runat="server" Text='<%# Eval("Nombre") %>' />
                        <br />Apellido:
                        <asp:Label ID="ApellidoLabel" runat="server" Text='<%# Eval("Apellido") %>' />
                        <br />Edad:
                        <asp:Label ID="EdadLabel" runat="server" Text='<%# Eval("Edad") %>' />
                        <br />Sexo:
                        <asp:Label ID="SexoLabel" runat="server" Text='<%# Eval("Sexo") %>' />
                        <br />ImagenURL:
                        <asp:Label ID="ImagenURLLabel" runat="server" Text='<%# Eval("ImagenURL") %>' />
                        <br /></td>
                </SelectedItemTemplate>
            </asp:ListView>
            <br />
            <asp:SqlDataSource ID="SqlDataSourceEmpresa" runat="server" ConnectionString="<%$ ConnectionStrings:EmpresaConnectionString %>" SelectCommand="SELECT [Dni], [Nombre], [Apellido], [Edad], [Sexo], [ImagenURL] FROM [Personas]"></asp:SqlDataSource>
            <br />
            <asp:Button ID="btnMostrarSeleccionado" runat="server" OnClick="btnMostrarSeleccionado_Click" Text="Mostrar Seleccionado" />
            <br />
            <br />
            <asp:Label ID="lblMensaje" runat="server"></asp:Label>
            <br />
            <br />
        </div>
    </form>
</body>
</html>
