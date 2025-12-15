<%@ Page Title="Listado de Turnos" Language="C#" MasterPageFile="~/Principal.Master"
    AutoEventWireup="true" CodeBehind="ListadoTurnos.aspx.cs" Inherits="Vista.Administrador.AdministrarTurnos.ListadoTurnos" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

    <div style="display: flex; justify-content: space-between; align-items: center; margin-bottom: 20px;">
        <h2>Listado de Turnos</h2>
        <asp:Button ID="btnNuevoTurno" CssClass="btnAgregar" runat="server" OnClick="btnNuevoTurno_Click" Text="Nuevo Turno" />
    </div>

    <!-- búsqueda -->
    <div class="contenedor-busqueda">
        <asp:Label ID="lblMedico" runat="server" Text="Buscar por Médico:"></asp:Label>
        <asp:TextBox ID="txtBuscarPorMedico" CssClass="input-txtbox-busqueda" runat="server"
            placeholder="Nombre y apellido del médico"></asp:TextBox>

        <asp:Label ID="lblPaciente" runat="server" Text="Paciente:"></asp:Label>
        <asp:TextBox ID="txtBuscarPorPaciente" CssClass="input-txtbox-busqueda" runat="server"
            placeholder="Nombre y apellido del paciente"></asp:TextBox>

        <asp:Button ID="btnBuscar" runat="server" Text="Buscar" CssClass="btnBuscar" OnClick="btnBuscar_Click" />
    </div>

    <!-- filtros -->
    <div class="contenedor-filtros">
        <asp:Label ID="lblEspecialidad" runat="server" Text="Especialidad:"></asp:Label>
        <asp:DropDownList ID="ddlEspecialidad" runat="server" CssClass="input-txtbox-busqueda">
        </asp:DropDownList>

        <div class="checkbox-dias">
            <asp:Label ID="lblDias" runat="server" Text="Días:"></asp:Label><br />
            <asp:CheckBox ID="chkLunes" runat="server" Text="Lunes" />
            <asp:CheckBox ID="chkMartes" runat="server" Text="Martes" />
            <asp:CheckBox ID="chkMiercoles" runat="server" Text="Miércoles" />
            <asp:CheckBox ID="chkJueves" runat="server" Text="Jueves" />
            <asp:CheckBox ID="chkViernes" runat="server" Text="Viernes" />
            <asp:CheckBox ID="chkSabado" runat="server" Text="Sábado" />
        </div>
          <asp:Button ID="btnAplicarFiltros" runat="server" Text="Aplicar Filtros" CssClass="btnBuscar"  OnClick="btnAplicarFiltros_Click"  />
    </div>

    <br />

    <!-- GridView de turnos -->
    <asp:GridView 
        ID="gvTurnos" 
        runat="server"
        AutoGenerateColumns="False"
        CssClass="tabla-medicos" 
        OnRowCommand="gvTurnos_RowCommand"
         AllowPaging="True"   PageSize="10" OnPageIndexChanging="gvTurnos_PageIndexChanging"
        >
        <Columns>
            <asp:BoundField DataField="IdTurno" HeaderText="Id Turno" />
            <asp:BoundField DataField="Especialidad" HeaderText="Especialidad" />
            <asp:BoundField DataField="Medico" HeaderText="Médico Asignado" />
            <asp:BoundField DataField="Dia" HeaderText="Día" />
            <asp:BoundField DataField="Horario" HeaderText="Horario" />
            <asp:BoundField DataField="Paciente" HeaderText="Paciente" />
            
            <asp:TemplateField HeaderText="Acciones">
                <ItemTemplate>
                    <asp:Button ID="btnEditar" runat="server" Text="Editar"  CommandName="Editar" CommandArgument='<%# Eval("IdTurno") %>' CssClass="btnAccion btnEditar" />
                    <asp:Button ID="btnEliminar" runat="server" Text="Eliminar" 
                      CommandName="Eliminar" CommandArgument='<%# Eval("IdTurno") %>' 
                      CssClass="btnAccion btnEliminar" 
                      OnClientClick="return confirm('¿Estás seguro que deseas eliminar este turno?');"
                      />
                </ItemTemplate>
            </asp:TemplateField>
        </Columns>
    </asp:GridView>

    <br />

</asp:Content>
