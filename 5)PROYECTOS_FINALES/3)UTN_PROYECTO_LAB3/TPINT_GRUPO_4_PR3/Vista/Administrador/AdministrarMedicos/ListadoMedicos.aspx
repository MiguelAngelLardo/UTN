<%@ Page Title="Listado de Médicos" Language="C#" MasterPageFile="~/Principal.Master" AutoEventWireup="true" CodeBehind="ListadoMedicos.aspx.cs" Inherits="Vista.Administrador.AdministrarMedicos.ListadoMedicos" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server"></asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

<div style="display: flex; justify-content: space-between; align-items: center; margin-bottom: 20px;">
    <h2>Listado de Médicos</h2>
    <asp:Button ID="btnAgregarMedico" CssClass="btnAgregar" runat="server" OnClick="btnAgregarMedico_Click" Text="Agregar médico" />
</div>

<div class="contenedor-busqueda">
    <asp:TextBox ID="txtBuscarPorNombre" CssClass="input-txtbox-busqueda" runat="server" placeholder="Nombre y apellido"></asp:TextBox>
    <asp:TextBox ID="txtBuscarPorLegajo" CssClass="input-txtbox-busqueda" runat="server"  placeholder="N° de legajo"></asp:TextBox>
    <asp:Button ID="btnBuscar" runat="server" Text="Buscar" CssClass="btnBuscar" OnClientClick="return resetDdlCbl();" OnClick="btnBuscar_Click" />
</div>

<div class="contenedor-filtros">
    <asp:DropDownList ID="ddlEspecialidades" runat="server" CssClass="ddl"></asp:DropDownList>
    <asp:CheckBoxList ID="checkDias" runat="server" RepeatDirection="Horizontal" CssClass="checkbox-dias"></asp:CheckBoxList>
    <asp:Button ID="btnAplicarFiltros" runat="server" Text="Aplicar Filtros" CssClass="btnBuscar"  OnClick="btnAplicarFiltros_Click"  />
</div>

 <br />
 <asp:GridView ID="gvMedicos" runat="server" AutoGenerateColumns="False" CssClass="tabla-medicos"  OnRowCommand="gvMedicos_RowCommand" OnRowDataBound="gvMedicos_RowDataBound" OnPageIndexChanging="gvMedicos_PageIndexChanging"  AllowPaging="True"   PageSize="10"   >
  <Columns>
    <asp:BoundField DataField="Legajo" HeaderText="Legajo" />  <asp:BoundField DataField="Nombre" HeaderText="Nombre" />
    <asp:BoundField DataField="Apellido" HeaderText="Apellido" />  <asp:BoundField DataField="Especialidad" HeaderText="Especialidad" />
    <asp:BoundField DataField="Dias" HeaderText="Días de Atención" />  <asp:BoundField DataField="Horas" HeaderText="Horario de Atención" />
    
    <asp:TemplateField HeaderText="Acciones" ItemStyle-CssClass="columna-Btn-Grid"> <%--es la unica manera que css aplique estilos a esta col--%>
      <ItemTemplate>
          <asp:Button ID="btnVer" runat="server" Text="Ver detalle" CommandName="Ver" CommandArgument='<%# Eval("Legajo") %>' CssClass="btnAccion btnVer" />
          <asp:Button ID="btnEditar" runat="server" Text="Editar" CommandName="Editar" CommandArgument='<%# Eval("Legajo") %>' CssClass="btnAccion btnEditar" />
          <asp:Button ID="btnEliminar" runat="server" Text="Eliminar" CommandName="Eliminar" CommandArgument='<%# Eval("Legajo") %>' CssClass="btnAccion btnEliminar" OnClientClick="return confirm('¿Está seguro que desea eliminar este médico?');"/>
      </ItemTemplate>
    </asp:TemplateField>
    <asp:TemplateField HeaderText="Usuario">
    <ItemTemplate>
        <div class="usuario-col">

            <div class="usuario-acciones">
                <asp:Button ID="btnCrearUsuario" runat="server"
                    CommandArgument='<%# Eval("Legajo") %>'
                    CssClass="btnAccion btnCrear" />

                <asp:Button ID="btnEliminarUsuario" runat="server"
                    Text="Eliminar"
                    CommandName="EliminarUsuario"
                    CommandArgument='<%# Eval("Legajo") %>'
                    CssClass="btnAccion btnEliminar"
                    OnClientClick="return confirm('¿Está seguro que desea eliminar este usuario?');" />
            </div>
            <div class="usuario-estado" runat="server" id="divEstado">
    <label class="switch">
        <asp:CheckBox 
            ID="chkHabilitar"
            runat="server"
            AutoPostBack="true"
            OnCheckedChanged="chkHabilitar_CheckedChanged"
        />
        <span class="slider"></span>
    </label>

    <asp:Label 
        ID="lblEstado"
        runat="server"
        CssClass="texto-switch"
    />
</div>
 
            <asp:HiddenField 
                ID="hfLegajo" 
                runat="server" 
                Value='<%# Eval("Legajo") %>' 
            />
        </div>
    </ItemTemplate>
</asp:TemplateField>
  </Columns>
</asp:GridView>

<script type="text/javascript">
  function resetDdlCbl() {
  var ddlEspecialidad = document.getElementById('<%= ddlEspecialidades.ClientID %>')
  if (ddlEspecialidad) ddlEspecialidad.value = "0"; // Lo pone en "-- Seleccione --"
    
  var objCbl = document.getElementById('<%= checkDias.ClientID %>');
  if (objCbl) {
    var vCuadradosCheck = objCbl.getElementsByTagName('input');// Buscamos todos los <input> dentro del controllos check y no check
    for (var i = 0; i < vCuadradosCheck.length; i++) {
      if (vCuadradosCheck[i].type === 'checkbox') {
        vCuadradosCheck[i].checked = false; // Destilda la casilla
      }
    }
  }
        
  return true; //el true es para que siga con el Postback y continue al servidor
}
 
</script>

</asp:Content>

