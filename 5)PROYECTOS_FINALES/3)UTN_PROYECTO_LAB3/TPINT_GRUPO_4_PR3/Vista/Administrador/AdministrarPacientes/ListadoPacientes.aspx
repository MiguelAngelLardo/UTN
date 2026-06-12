<%@ Page Title="Listado de Pacientes" Language="C#" MasterPageFile="~/Principal.Master"
    AutoEventWireup="true" CodeBehind="ListadoPacientes.aspx.cs" Inherits="Vista.Administrador.AdministrarPacientes.ListadoPacientes" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
    <style>
    </style>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <div style="display: flex; justify-content: space-between; align-items: center; margin-bottom: 20px;">
        <h2>Listado de Pacientes</h2>
        <asp:Button ID="btnAgregarPaciente"  CssClass="btnAgregar" runat="server" OnClick="btnAgregarPaciente_Click" Text="Agregar paciente" />
    </div>

    <div class="contenedor-busqueda">
        <asp:TextBox ID="txtBuscarPorNombre" CssClass="input-txtbox-busqueda" runat="server"
            placeholder="Nombre y apellido"></asp:TextBox>
        <asp:TextBox ID="txtBuscarPorDNI" CssClass="input-txtbox-busqueda" runat="server"
            placeholder="N° de DNI"></asp:TextBox>
        <asp:Button ID="btnBuscar" runat="server" Text="Buscar" CssClass="btnBuscar" OnClick="btnBuscar_Click" />
    </div>
    
    <br />
    
    <asp:GridView ID="gvPacientes" runat="server" 
        AutoGenerateColumns="False" 
        CssClass="tabla-medicos" 
        DataKeyNames="DNI" 
        OnRowCommand="gvPacientes_RowCommand"
       AllowPaging="True"   PageSize="10" OnPageIndexChanging="gvPacientes_PageIndexChanging"
        >
        <Columns>
            <asp:BoundField DataField="DNI" HeaderText="DNI" />
            <asp:BoundField DataField="Nombre" HeaderText="Nombre" />
            <asp:BoundField DataField="Apellido" HeaderText="Apellido" />
            <asp:BoundField DataField="CorreoElectronico" HeaderText="Correo Electrónico" />
            <asp:BoundField DataField="Telefono" HeaderText="Teléfono" />
           
            <asp:TemplateField HeaderText="Acciones">
                <ItemTemplate>
                    <asp:Button ID="btnVer" runat="server" Text="Ver detalle" 
                        CommandName="Ver" CommandArgument='<%# Eval("DNI") %>' CssClass="btnAccion btnVer" />
                    <asp:Button ID="btnEditar" runat="server" Text="Editar" 
                        CommandName="Editar" CommandArgument='<%# Eval("DNI") %>' CssClass="btnAccion btnEditar" />
                    <asp:Button ID="btnEliminar" runat="server" Text="Eliminar" 
                        CommandName="Eliminar" CommandArgument='<%# Eval("DNI") %>' 
                        CssClass="btnAccion btnEliminar"
                        OnClientClick="return confirm('¿Está seguro de eliminar este paciente?');" />
                </ItemTemplate>
            </asp:TemplateField>
        </Columns>
    </asp:GridView>
    
    <br />
</asp:Content>