<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="SeleccionarSucursales2.aspx.cs" Inherits="TP7_Codigo.SeleccionarSucursales2" %>

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
            width: 159px;
        }
        .auto-style3 {
            width: 214px;
        }
        .auto-style5 {
            width: 264px;
        }
        </style>
</head>
<body>
    <form id="form1" runat="server">
            <table class="auto-style1">
                <tr>
                    <td class="auto-style2">&nbsp;</td>
                    <td class="auto-style3">
                        <asp:HyperLink ID="hlListado" runat="server" NavigateUrl="~/SeleccionarSucursales.aspx">Listado de sucursales</asp:HyperLink>
                    </td>
                    <td>
                        <asp:HyperLink ID="hlMostrar" runat="server" NavigateUrl="~/ListadoSucursalesSeleccionadas.aspx">Mostrar sucursales seleccionadas</asp:HyperLink>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style2">&nbsp;</td>
                    <td class="auto-style3" style="font-size: large"><strong>
                        <br />
                        Listado de sucursales<br />
                        </strong></td>
                    <td>&nbsp;</td>
                </tr>
                <tr>
                    <td class="auto-style2">&nbsp;</td>
                    <td class="auto-style3">Busqueda por sucursales</td>
                    <td>
                        <asp:TextBox ID="txtBusqueda" runat="server"></asp:TextBox>
&nbsp;
                        <asp:Button ID="btnBuscar" runat="server" Text="Buscar"/>
                    </td>
                </tr>
            </table>
        <table class="auto-style1">
            <tr>
                <td class="auto-style5">

                    <%--datalist por interfaz--%>
                    <asp:DataList ID="dlProvincia2" runat="server" DataSourceID="sqsProvincias" OnItemCommand="dlProvincia2_ItemCommand">                         
                        <ItemTemplate>
                            <asp:Button ID="btnProvincias" runat="server" 
                             CommandArgument='<%# Eval("Id_Provincia") %>' 
                             Text='<%# Eval("DescripcionProvincia") %>' 
                             CommandName="filtrarProvincia" Width="200px" />
                        </ItemTemplate> 
                    </asp:DataList>
                    <br />
                    <asp:SqlDataSource ID="sqsProvincias" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:BDSucursalesConnectionString %>" 
                        SelectCommand="SELECT [Id_Provincia], [DescripcionProvincia] FROM [Provincia]" >
                    </asp:SqlDataSource>
                    <br />


                </td>
                <td>
                    <br />
                    <asp:ListView ID="lvSucursales" runat="server" DataKeyNames="Id_Sucursal" DataSourceID="sqsSucursales" GroupItemCount="3">
                       <%-- <AlternatingItemTemplate>
                            <td runat="server" style="background-color: #FFFFFF;color: #284775;">Id_Sucursal:
                                <asp:Label ID="Id_SucursalLabel" runat="server" Text='<%# Eval("Id_Sucursal") %>' />
                                <br />NombreSucursal:
                                <asp:Label ID="NombreSucursalLabel" runat="server" Text='<%# Eval("NombreSucursal") %>' />
                                <br />DescripcionSucursal:
                                <asp:Label ID="DescripcionSucursalLabel" runat="server" Text='<%# Eval("DescripcionSucursal") %>' />
                                <br />URL_Imagen_Sucursal:
                                <asp:Label ID="URL_Imagen_SucursalLabel" runat="server" Text='<%# Eval("URL_Imagen_Sucursal") %>' />
                                <br />Id_ProvinciaSucursal:
                                <asp:Label ID="Id_ProvinciaSucursalLabel" runat="server" Text='<%# Eval("Id_ProvinciaSucursal") %>' />
                                <br /></td>
                        </AlternatingItemTemplate>--%>
                        <EditItemTemplate>
                            <td runat="server" style="background-color: #999999;">Id_Sucursal:
                                <asp:Label ID="Id_SucursalLabel1" runat="server" Text='<%# Eval("Id_Sucursal") %>' />
                                <br />NombreSucursal:
                                <asp:TextBox ID="NombreSucursalTextBox" runat="server" Text='<%# Bind("NombreSucursal") %>' />
                                <br />DescripcionSucursal:
                                <asp:TextBox ID="DescripcionSucursalTextBox" runat="server" Text='<%# Bind("DescripcionSucursal") %>' />
                                <br />URL_Imagen_Sucursal:
                                <asp:TextBox ID="URL_Imagen_SucursalTextBox" runat="server" Text='<%# Bind("URL_Imagen_Sucursal") %>' />
                                <br />Id_ProvinciaSucursal:
                                <asp:TextBox ID="Id_ProvinciaSucursalTextBox" runat="server" Text='<%# Bind("Id_ProvinciaSucursal") %>' />
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
                            <td runat="server" style="">NombreSucursal:
                                <asp:TextBox ID="NombreSucursalTextBox0" runat="server" Text='<%# Bind("NombreSucursal") %>' />
                                <br />DescripcionSucursal:
                                <asp:TextBox ID="DescripcionSucursalTextBox0" runat="server" Text='<%# Bind("DescripcionSucursal") %>' />
                                <br />URL_Imagen_Sucursal:
                                <asp:TextBox ID="URL_Imagen_SucursalTextBox0" runat="server" Text='<%# Bind("URL_Imagen_Sucursal") %>' />
                                <br />Id_ProvinciaSucursal:
                                <asp:TextBox ID="Id_ProvinciaSucursalTextBox0" runat="server" Text='<%# Bind("Id_ProvinciaSucursal") %>' />
                                <br />
                                <asp:Button ID="InsertButton" runat="server" CommandName="Insert" Text="Insertar" />
                                <br />
                                <asp:Button ID="CancelButton0" runat="server" CommandName="Cancel" Text="Borrar" />
                                <br /></td>
                        </InsertItemTemplate>
                        <ItemTemplate>
                            <td runat="server" style="background-color: #E0FFFF;color: #333333;">Id_Sucursal:
                                <asp:Label ID="Id_SucursalLabel" runat="server" Text='<%# Eval("Id_Sucursal") %>' />
                                <br />NombreSucursal:
                                <asp:Label ID="NombreSucursalLabel" runat="server" Text='<%# Eval("NombreSucursal") %>' />
                                <br />DescripcionSucursal:
                                <asp:Label ID="DescripcionSucursalLabel" runat="server" Text='<%# Eval("DescripcionSucursal") %>' />
                                <br />URL_Imagen_Sucursal:
                                <asp:Label ID="URL_Imagen_SucursalLabel" runat="server" Text='<%# Eval("URL_Imagen_Sucursal") %>' />
                                <br />Id_ProvinciaSucursal:
                                <asp:Label ID="Id_ProvinciaSucursalLabel" runat="server" Text='<%# Eval("Id_ProvinciaSucursal") %>' />
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
                                    <td runat="server" style="text-align: center;background-color: #5D7B9D;font-family: Verdana, Arial, Helvetica, sans-serif;color: #FFFFFF">
                                        <asp:DataPager ID="DataPagerlvSucu" runat="server" PageSize="6">
                                            <Fields>
                                                <asp:NextPreviousPagerField ButtonType="Button" ShowFirstPageButton="True" ShowNextPageButton="False" ShowPreviousPageButton="False" />
                                                <asp:NumericPagerField />
                                                <asp:NextPreviousPagerField ButtonType="Button" ShowLastPageButton="True" ShowNextPageButton="False" ShowPreviousPageButton="False" />
                                            </Fields>
                                        </asp:DataPager>
                                    </td>
                                </tr>
                            </table>
                        </LayoutTemplate>
                        <SelectedItemTemplate>
                            <td runat="server" style="background-color: #E2DED6;font-weight: bold;color: #333333;">Id_Sucursal:
                                <asp:Label ID="Id_SucursalLabel2" runat="server" Text='<%# Eval("Id_Sucursal") %>' />
                                <br />NombreSucursal:
                                <asp:Label ID="NombreSucursalLabel0" runat="server" Text='<%# Eval("NombreSucursal") %>' />
                                <br />DescripcionSucursal:
                                <asp:Label ID="DescripcionSucursalLabel0" runat="server" Text='<%# Eval("DescripcionSucursal") %>' />
                                <br />URL_Imagen_Sucursal:
                                <asp:Label ID="URL_Imagen_SucursalLabel0" runat="server" Text='<%# Eval("URL_Imagen_Sucursal") %>' />
                                <br />Id_ProvinciaSucursal:
                                <asp:Label ID="Id_ProvinciaSucursalLabel0" runat="server" Text='<%# Eval("Id_ProvinciaSucursal") %>' />
                                <br /></td>
                        </SelectedItemTemplate>
                    </asp:ListView>
                    <br />
                    <asp:SqlDataSource ID="sqsSucursales" runat="server" ConnectionString="<%$ ConnectionStrings:BDSucursalesConnectionString %>" 
                        SelectCommand="SELECT [Id_Sucursal], [NombreSucursal], [DescripcionSucursal], [URL_Imagen_Sucursal], [Id_ProvinciaSucursal] FROM [Sucursal]" OnSelecting="sqsSucursales_Selecting">
                    </asp:SqlDataSource>

                </td>
            </tr>
        </table>

        <div>
        </div>
    </form>
</body>
</html>
