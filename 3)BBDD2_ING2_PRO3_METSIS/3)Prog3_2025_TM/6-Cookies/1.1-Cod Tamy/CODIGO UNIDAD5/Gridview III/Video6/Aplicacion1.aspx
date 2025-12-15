<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion1.aspx.cs" Inherits="Aplicaciones.Aplicacion1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <p>
            <strong>El siguiente ejemplo utiliza la base de datos Libreria </strong>
        <p>
            <br />
            <asp:GridView ID="grdLibros" runat="server" AutoGenerateColumns="False" AutoGenerateEditButton="True" CellPadding="4" ForeColor="#333333" GridLines="None" OnRowCancelingEdit="grdLibros_RowCancelingEdit" OnRowEditing="grdLibros_RowEditing" OnRowUpdating="grdLibros_RowUpdating" PageSize="3" OnRowDataBound="grdLibros_RowDataBound" >
                <AlternatingRowStyle BackColor="White" />
                <Columns>
                    <asp:TemplateField HeaderText="ID LIBRO">
                        <EditItemTemplate>
                            <asp:Label ID="lbl_eit_IdLibro" runat="server" Text='<%# Bind("IdLibro") %>'></asp:Label>
                        </EditItemTemplate>
                        <ItemTemplate>
                            <asp:Label ID="lbl_it_IdLibro" runat="server" Text='<%# Bind("IdLibro") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="TITULO">
                        <EditItemTemplate>
                            <asp:TextBox ID="txt_eit_Titulo" runat="server" Text='<%# Bind("Titulo") %>'></asp:TextBox>
                        </EditItemTemplate>
                        <ItemTemplate>
                            <asp:Label ID="lbl_it_Titulo" runat="server" Text='<%# Bind("Titulo") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="PRECIO">
                        <EditItemTemplate>
                            <asp:TextBox ID="txt_eit_Precio" runat="server" Text='<%# Bind("Precio") %>'></asp:TextBox>
                        </EditItemTemplate>
                        <ItemTemplate>
                            <asp:Label ID="lbl_it_Precio" runat="server" Text='<%# Bind("Precio") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="AUTOR">
                        <EditItemTemplate>
                            <asp:TextBox ID="txt_eit_Autor" runat="server" Text='<%# Bind("Autor") %>'></asp:TextBox>
                        </EditItemTemplate>
                        <ItemTemplate>
                            <asp:Label ID="lbl_it_Autor" runat="server" Text='<%# Bind("Autor") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>


                    <asp:TemplateField HeaderText="TEMAS">
                        <EditItemTemplate>
                            <asp:DropDownList ID="ddl_eit_Temas" runat="server">
                            </asp:DropDownList>
                        </EditItemTemplate>
                        <ItemTemplate>
                            <asp:Label ID="lbl_it_Temas" runat="server" Text='<%# Bind("Tema") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>


                </Columns>
                <FooterStyle BackColor="#990000" Font-Bold="True" ForeColor="White" />
                <HeaderStyle BackColor="#990000" Font-Bold="True" ForeColor="White" />
                <PagerStyle BackColor="#FFCC66" ForeColor="#333333" HorizontalAlign="Center" />
                <RowStyle BackColor="#FFFBD6" ForeColor="#333333" />
                <SelectedRowStyle BackColor="#FFCC66" Font-Bold="True" ForeColor="Navy" />
                <SortedAscendingCellStyle BackColor="#FDF5AC" />
                <SortedAscendingHeaderStyle BackColor="#4D0000" />
                <SortedDescendingCellStyle BackColor="#FCF6C0" />
                <SortedDescendingHeaderStyle BackColor="#820000" />
            </asp:GridView>
        </p>
        <div>
            <br />
        </div>
    </form>
    <p>
        &nbsp;</p>
</body>
</html>
