<%@ Page Title="" Language="C#" MasterPageFile="~/Principal.Master" AutoEventWireup="true" CodeBehind="FormEditarTurno.aspx.cs" Inherits="Vista.Administrador.AdministrarTurnos.FormEditarTurno" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>


<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

     
<h2 class="titulo-pagina">Editar Turno</h2>


 <div class="contenedor-columnas">
   <div class="columna">
        <%-- Especialidad --%>
    <asp:Label ID="lblEspecialidad" runat="server" Text="Especialidad:"></asp:Label>
    <asp:DropDownList ID="ddlEspecialidad" runat="server" CssClass="ddl-form" AutoPostBack="true" OnSelectedIndexChanged="ddlEspecialidad_SelectedIndexChanged" />
    <asp:RequiredFieldValidator ID="rfvEspecialidad" runat="server"
        ControlToValidate="ddlEspecialidad"
        InitialValue="0"
        ErrorMessage="Seleccione una especialidad"
        Display="Static"   CssClass="error-validacion"/>
    
       <%-- Médico --%>
 <asp:Label ID="lblMedico" runat="server" Text="Médico:"></asp:Label>
 <asp:DropDownList ID="ddlMedico" runat="server" CssClass="ddl-form"  AutoPostBack="True" OnSelectedIndexChanged="ddlMedico_SelectedIndexChanged" />
 <asp:RequiredFieldValidator ID="rfvMedico" runat="server"
     ControlToValidate="ddlMedico"
     InitialValue="0"
     ErrorMessage="Seleccione un médico"
     Display="Static"  CssClass="error-validacion" />
       
    <%-- Paciente --%>
    <asp:Label ID="lblPaciente" runat="server" Text="Paciente:"></asp:Label>
    <asp:DropDownList ID="ddlPaciente" runat="server" CssClass="ddl-form" />
    <asp:RequiredFieldValidator ID="rfvPaciente" runat="server"
        ControlToValidate="ddlPaciente"
        InitialValue="0"
        ErrorMessage="Seleccione un paciente"
        Display="Static"  CssClass="error-validacion" />
  </div>
    <div class="columna">
    <%-- Día del Turno --%>
    <asp:Label ID="lblDiaTurno" runat="server" Text="Día del Turno:"></asp:Label>
    <asp:TextBox ID="txtDiaTurno" runat="server" CssClass="input-txtbox-form" TextMode="Date" AutoPostBack="true"  OnTextChanged="txtDiaTurno_TextChanged" />
    <asp:RequiredFieldValidator ID="rfvDiaTurno" runat="server"
        ControlToValidate="txtDiaTurno"
        ErrorMessage="Ingrese una fecha"
        Display="Static"  CssClass="error-validacion" />

  <%-- Horario --%>
  <asp:Label ID="lblHorario" runat="server" Text="Horario:"></asp:Label>
  <asp:DropDownList ID="ddlHorario" runat="server" CssClass="ddl-form" />
  <asp:RequiredFieldValidator ID="rfvHorario" runat="server"
      ControlToValidate="ddlHorario"
      InitialValue="0"
      ErrorMessage="Seleccione un horario"
      Display="Static"  CssClass="error-validacion" />
    </div>
 </div>

  <div class="fila-mensajes">
      <asp:Label ID="lblMensajeExito" runat="server" CssClass="mensaje-exito" Visible="false"></asp:Label>
      <asp:Label ID="lblMensajeError" runat="server" CssClass="mensaje-error" Visible="false"></asp:Label>
  </div>
  <%-- Botón de Guardar --%>
  <div style="display: flex; justify-content: center; margin-top: 20px;"> 
      <asp:Button ID="btnGuardarCambios" CssClass="btnAgregar" runat="server" Text="Guardar Cambios" OnClick="btnGuardarCambios_Click" />
      <asp:HyperLink ID="hlVolver" runat="server" NavigateUrl="ListadoTurnos.aspx" CssClass="btnVolver" Visible="false">Volver al Listado</asp:HyperLink>
  
  </div>

</asp:Content>
