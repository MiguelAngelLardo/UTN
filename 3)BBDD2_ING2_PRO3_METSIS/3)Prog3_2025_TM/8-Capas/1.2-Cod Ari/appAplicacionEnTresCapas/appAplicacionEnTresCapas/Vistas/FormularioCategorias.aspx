<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="FormularioCategorias.aspx.cs" Inherits="Vistas.FormularioCategorias" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            &nbsp;
            <br />
            Ingrese nombre categoría:
            <asp:TextBox ID="txtNombreCategoria" runat="server"></asp:TextBox>
            &nbsp;
            <asp:Button ID="btnAceptar" runat="server" OnClick="btnAceptar_Click" Text="Aceptar" />
            &nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Label ID="lblMensaje" runat="server"></asp:Label>
        </div>
        <br />
        <br />
        <br />
        <asp:GridView ID="grdCategorias" runat="server">
        </asp:GridView>
        <br />
        <br />
        <br />
        <asp:ListView ID="ListViewCategoria" runat="server" GroupItemCount="3">
            <AlternatingItemTemplate>
                <td runat="server" style="background-color: #FAFAD2;color: #284775;">IdCategoría:
                    <asp:Label ID="IdCategoríaLabel" runat="server" Text='<%# Eval("IdCategoría") %>' />
                    <br />NombreCategoría:
                    <asp:Label ID="NombreCategoríaLabel" runat="server" Text='<%# Eval("NombreCategoría") %>' />
                    <br /></td>
            </AlternatingItemTemplate>
            <EditItemTemplate>
                <td runat="server" style="background-color: #FFCC66;color: #000080;">IdCategoría:
                    <asp:TextBox ID="IdCategoríaTextBox" runat="server" Text='<%# Bind("IdCategoría") %>' />
                    <br />NombreCategoría:
                    <asp:TextBox ID="NombreCategoríaTextBox" runat="server" Text='<%# Bind("NombreCategoría") %>' />
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
                <td runat="server" style="">IdCategoría:
                    <asp:TextBox ID="IdCategoríaTextBox" runat="server" Text='<%# Bind("IdCategoría") %>' />
                    <br />NombreCategoría:
                    <asp:TextBox ID="NombreCategoríaTextBox" runat="server" Text='<%# Bind("NombreCategoría") %>' />
                    <br />
                    <asp:Button ID="InsertButton" runat="server" CommandName="Insert" Text="Insertar" />
                    <br />
                    <asp:Button ID="CancelButton" runat="server" CommandName="Cancel" Text="Borrar" />
                    <br /></td>
            </InsertItemTemplate>
            <ItemTemplate>
                <td runat="server" style="background-color: #FFFBD6;color: #333333;">IdCategoría:
                    <asp:Label ID="IdCategoríaLabel" runat="server" Text='<%# Eval("IdCategoría") %>' />
                    <br />NombreCategoría:
                    <asp:Label ID="NombreCategoríaLabel" runat="server" Text='<%# Eval("NombreCategoría") %>' />
                    <br /></td>
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
                        <td runat="server" style="text-align: center;background-color: #FFCC66;font-family: Verdana, Arial, Helvetica, sans-serif;color: #333333;"></td>
                    </tr>
                </table>
            </LayoutTemplate>
            <SelectedItemTemplate>
                <td runat="server" style="background-color: #FFCC66;font-weight: bold;color: #000080;">IdCategoría:
                    <asp:Label ID="IdCategoríaLabel" runat="server" Text='<%# Eval("IdCategoría") %>' />
                    <br />NombreCategoría:
                    <asp:Label ID="NombreCategoríaLabel" runat="server" Text='<%# Eval("NombreCategoría") %>' />
                    <br /></td>
            </SelectedItemTemplate>
        </asp:ListView>
        <br />
        <br />
        <asp:SqlDataSource ID="SqlDataSourceCategorias" runat="server" ConnectionString="<%$ ConnectionStrings:NeptunoConnectionString %>" SelectCommand="SELECT [IdCategoría], [NombreCategoría] FROM [Categorías]"></asp:SqlDataSource>
        <br />
    </form>
</body>
</html>
