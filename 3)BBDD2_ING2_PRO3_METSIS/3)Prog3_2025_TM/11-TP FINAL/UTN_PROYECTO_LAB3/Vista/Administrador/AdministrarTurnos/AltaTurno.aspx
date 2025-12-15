<%@ Page Title="Alta de Turno" Language="C#" MasterPageFile="~/Principal.Master"  AutoEventWireup="true" CodeBehind="AltaTurno.aspx.cs" Inherits="Vista.Administrador.AdministrarTurnos.AltaTurno" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">

</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">   
  
<h2 class="titulo-pagina">Asignación / Alta de Turno</h2>
<div class="contenedor-columnas">

  <div class="columna"><%-- col izquierda --%>
   <asp:Label ID="lblEspecialidad" runat="server" Text="Especialidad:"></asp:Label> <%-- Especialidad CON AUTO POST BACK TRUE para ddlmedico--%>
   <asp:DropDownList ID="ddlEspecialidad" runat="server" CssClass="ddl-form" AutoPostBack="true" OnSelectedIndexChanged="ddlEspecialidad_SelectedIndexChanged"/>  
   <asp:RequiredFieldValidator ID="rfvEspecialidad" runat="server" ControlToValidate="ddlEspecialidad" InitialValue="0" ErrorMessage="Seleccione una especialidad" Display="Static" CssClass="error-validacion" />
    
   <asp:Label ID="lblMedico" runat="server" Text="Médico:"></asp:Label> <%-- Médico de esa especialidad CON AUTO POST BACK TRUE para ver ddlHorariosDisponible y lblDiasMedico--%>
   <asp:DropDownList ID="ddlMedico" runat="server" CssClass="ddl-form" AutoPostBack="True" OnSelectedIndexChanged="ddlMedico_SelectedIndexChanged"/>
   <asp:RequiredFieldValidator ID="rfvMedico" runat="server" ControlToValidate="ddlMedico" InitialValue="0" ErrorMessage="Seleccione un médico" Display="Static" CssClass="error-validacion"/>

    <asp:Label ID="lblPaciente" runat="server" Text="Paciente:"></asp:Label><%-- Paciente --%>
    <asp:DropDownList ID="ddlPaciente" runat="server" CssClass="ddl-form"/>   
    <asp:RequiredFieldValidator ID="rfvPaciente" runat="server" ControlToValidate="ddlPaciente" InitialValue="0" ErrorMessage="Seleccione un paciente"  Display="Static"  CssClass="error-validacion" />      
  </div>

  <div class="columna"><%-- col derecha --%>
   

    <%-- Usamos un TextBox con el tipo Date para que el navegador muestre un calendario CON AUTO POST BACK para el ddl horario --%>
    <asp:Label ID="lblCalendario" runat="server" Text="Fecha del Turno:"></asp:Label>
    <asp:TextBox ID="txtDateCalendario" runat="server" CssClass="input-txtbox-form" TextMode="Date" AutoPostBack="true" OnTextChanged="txtDateCalendario_TextChanged"  />
    <asp:RequiredFieldValidator ID="rfvFecha" runat="server" ControlToValidate="txtDateCalendario" ErrorMessage="Ingrese la fecha" Display="Static" CssClass="error-validacion" />
    
    <%-- Este DDL se cargará con horas libres (8:00, 9:00, etc.) --%>
    <asp:Label ID="lblHorarioDisponible" runat="server" Text="">Horario base: </asp:Label>
    <asp:DropDownList ID="ddlHorarioDisponible" runat="server" CssClass="ddl-form" />
    <asp:RequiredFieldValidator ID="rfvHorario" runat="server" ControlToValidate="ddlHorarioDisponible" InitialValue="0" ErrorMessage="Seleccione hora" Display="Static" CssClass="error-validacion" />
  </div>




  <div class="P_diasAtencion">
    <asp:Label ID="lblTituloDiasMedico" runat="server" Text="Dias que atiende el Doctor:" CssClass="P_diasAtencion__titulo" ></asp:Label>
    <asp:Label ID="lblDiasMedico" runat="server" Text="" CssClass="info-dias"></asp:Label> 
  </div>


  
  <%-- <div class="cblPadre">
      <div class="cblPadre__lbl"> 
          <asp:Label ID="lblDias" runat="server" Text="Días de Atención:"></asp:Label>
      </div>
    
      <div class ="cblPadre__checks">

      <asp:CheckBoxList ID="cblDias" runat="server" RepeatDirection="Horizontal"/>
      </div>
    
      <div class="cblPadre__validator">
        <asp:CustomValidator ID="cvDias" runat="server" ErrorMessage="Seleccione al menos un día" CssClass="error-validacion" Display="Static" ClientValidationFunction="validarCheckBox"/>
      </div> 
    </div>--%>

<div class="fila-mensajes"><%-- Un médico no puede tener dos turnos el mismo día, en el mismo horari, un paciente no puede tener dos turnos al mismo hs --%>
    <asp:Label ID="lblMensajeExito" runat="server" CssClass="mensaje-exito" Visible="false"></asp:Label>
    <asp:Label ID="lblMensajeError" runat="server" CssClass="mensaje-error" Visible="false"></asp:Label>
</div>

<div class="fila-boton-guardar"> 
   <asp:Button ID="btnGuardarTurno" CssClass="btnAgregar" runat="server" Text="Guardar" OnClick="btnGuardarTurno_Click" />
   <asp:HyperLink ID="hlVolver" runat="server" NavigateUrl="ListadoTurnos.aspx" CssClass="btnVolver" Visible="false">Volver al Listado</asp:HyperLink>
</div>

</div><%-- contenedor-columnas --%>


  <script type="text/javascript">

</script>
    
</asp:Content>
