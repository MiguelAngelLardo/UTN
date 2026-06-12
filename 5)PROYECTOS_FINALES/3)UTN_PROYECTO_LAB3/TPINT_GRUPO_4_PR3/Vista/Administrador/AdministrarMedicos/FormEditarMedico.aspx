<%@ Page Title="Agregar Medico" Language="C#" MasterPageFile="~/Principal.Master" AutoEventWireup="true" CodeBehind="FormEditarMedico.aspx.cs" Inherits="Vista.Administrador.AdministrarMedicos.FormEditarMedico" %>


<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server"></asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">      
  <h2 class="titulo-pagina">Editar Médico</h2>
   <script type="text/javascript">
   var cblDiasClientId = '<%= cblDias.ClientID %>';
   </script>
  <div class="contenedor-columnas">
    <div class="columna"><%-- Columna Izquierda--%>
      <asp:Label ID="lblLegajo" runat="server" Text="N° Legajo:"></asp:Label><%-- Legajo --%>
      <asp:TextBox ID="txtLegajo" runat="server" CssClass="input-txtbox-form" ReadOnly="true"></asp:TextBox>
      <asp:CustomValidator ID="cvLegajo" runat="server" ControlToValidate="txtLegajo" ErrorMessage="-"  ClientValidationFunction="validarLegajo"  Display="Static" CssClass="error-validacion" ValidateEmptyText="true"/> <%--sin el ValidateEmpty el custom o el regex validador no toma el "" o null--%>
      
      <asp:Label ID="lblNombre" runat="server" Text="Nombre:"></asp:Label> <%-- Nombre --%>
      <asp:TextBox ID="txtNombre" runat="server" CssClass="input-txtbox-form"></asp:TextBox>
      <asp:CustomValidator ID="cvNombre" runat="server" ControlToValidate="txtNombre" ErrorMessage="-" ClientValidationFunction="validarNomApeNac" Display="Static" CssClass="error-validacion" ValidateEmptyText="true"/>

      <asp:Label ID="lblSexo" runat="server" Text="Sexo:"></asp:Label> <%-- Sexo --%>
      <asp:DropDownList ID="ddlSexo" runat="server" CssClass="ddl-form">
        <asp:ListItem Text="-- Seleccione una opción --" Value="0"></asp:ListItem> <asp:ListItem Text="Femenino" Value="F"></asp:ListItem> <asp:ListItem Text="Masculino" Value="M"></asp:ListItem>
      </asp:DropDownList>
      <asp:RequiredFieldValidator ID="rfvSexo" runat="server" ControlToValidate="ddlSexo" InitialValue="0" ErrorMessage="Seleccione sexo" Display="Static" CssClass="error-validacion"/>     

      <%-- Provincia -> AutoPostBack es para que envie los cambios realizados (seleccion de provincia) de lo contrario queda ddlLocalidad en gris de por vida || OnSelectedIndex es para que cargue las Localidades cuando se elige Provincia--%>
      <asp:Label ID="lblPronvica" runat="server" Text="Provincia:"></asp:Label>
      <asp:DropDownList ID="ddlProvincias" runat="server" AutoPostBack="true" OnSelectedIndexChanged="ddlProvincias_SelectedIndexChanged" CssClass="ddl-form"/>
      <asp:RequiredFieldValidator ID="rfvProvincia" runat="server" ControlToValidate="ddlProvincias" InitialValue="0" ErrorMessage="Seleccione provincia" Display="Static" CssClass="error-validacion"/>

      <%-- Correo electrónico --%>
      <asp:Label ID="lblCorreoElectronico" runat="server" Text="Correo Electrónico:"></asp:Label>
      <asp:TextBox ID="txtCorreoElectronico" runat="server" CssClass="input-txtbox-form"></asp:TextBox> 
      <asp:CustomValidator ID="cvMail" runat="server" ControlToValidate="txtCorreoElectronico" ErrorMessage="-"  ClientValidationFunction="validarCorreo" Display="Static" CssClass="error-validacion" ValidateEmptyText="true"/> 


      <asp:Label ID="lblEspecialidad" runat="server" Text="Especialidad:"></asp:Label>      <%-- Especialidad --%>     
      <asp:DropDownList ID="ddlEspecialidad" runat="server" CssClass="ddl-form"/>
      <asp:RequiredFieldValidator ID="rfvEspecialidad" runat="server" ControlToValidate="ddlEspecialidad" InitialValue="0" ErrorMessage="Seleccione especialidad" Display="Static" CssClass="error-validacion"/>
    
      <%-- Fecha de nacimiento --%>
      <asp:Label ID="lblFechaNacimiento" runat="server" Text="Fecha de Nacimiento:"></asp:Label>
      <asp:TextBox ID="txtFechaNacimiento" runat="server" CssClass="input-txtbox-form" TextMode="Date"></asp:TextBox>
     <asp:CustomValidator ID="cvEdadMinima" runat="server" ControlToValidate="txtFechaNacimiento" ErrorMessage="-" ClientValidationFunction="validarEdad" Display="Static"  CssClass="error-validacion" ValidateEmptyText="true"/>
    </div>

    <div class="columna"><%-- Columna dertecha --%>
      
    <asp:Label ID="lblDNI" runat="server" Text="DNI:"></asp:Label><%-- DNI --%>
    <asp:TextBox ID="txtDNI" runat="server" CssClass="input-txtbox-form" ReadOnly="true"></asp:TextBox>
    <asp:CustomValidator ID="cvDni" runat="server" ControlToValidate="txtDNI" ErrorMessage="-" Display="Static" CssClass="error-validacion"/> <%--sin el ValidateEmpty el custom o el regex validador no toma el "" o null--%>


    <asp:Label ID="lblApellido" runat="server" Text="Apellido:"></asp:Label>      <%-- Apellido --%>
    <asp:TextBox ID="txtApellido" runat="server" CssClass="input-txtbox-form"></asp:TextBox>
    <asp:CustomValidator ID="cvApellido" runat="server" ControlToValidate="txtApellido" ErrorMessage="-"  ClientValidationFunction="validarNomApeNac" Display="Static" CssClass="error-validacion" ValidateEmptyText="true"/>

    <asp:Label ID="lblNacionalidad" runat="server" Text="Nacionalidad:"></asp:Label>      <%-- Nacionalidad --%>
    <asp:TextBox ID="txtNacionalidad" runat="server" CssClass="input-txtbox-form"></asp:TextBox>
    <asp:CustomValidator ID="cvNacionalidad" runat="server" ControlToValidate="txtNacionalidad" ErrorMessage="-" ClientValidationFunction="validarNomApeNac" Display="Static" CssClass="error-validacion" ValidateEmptyText="true"/>


    <asp:Label ID="lblLocalidad" runat="server" Text="Localidad:"></asp:Label>  <%-- Localidad --%>
    <asp:DropDownList ID="ddlLocalidades" runat="server" CssClass="ddl-form"/>
    <asp:RequiredFieldValidator ID="rfvLocalidad" runat="server" ControlToValidate="ddlLocalidades" InitialValue="0" ErrorMessage="Seleccione localidad" Display="Static" CssClass="error-validacion"/>

    <asp:Label ID="lblDireccion" runat="server" Text="Dirección:"></asp:Label>      <%-- Dirección --%>
    <asp:TextBox ID="txtDireccion" runat="server" CssClass="input-txtbox-form"></asp:TextBox>
    <asp:RequiredFieldValidator ID="rfvDireccion" runat="server" ControlToValidate="txtDireccion" ErrorMessage="Ingrese Dirección" Display="Static" CssClass="error-validacion" />

    <asp:Label ID="lblTelefono" runat="server" Text="Teléfono:"></asp:Label>      <%-- Teléfono --%>
    <asp:TextBox ID="txtTelefono" runat="server" CssClass="input-txtbox-form"></asp:TextBox>
    <asp:CustomValidator ID="cvTel" runat="server" ControlToValidate="txtTelefono" ErrorMessage="-"  ClientValidationFunction="validarTelefono" Display="Static" CssClass="error-validacion" ValidateEmptyText="true"/> 

            
      <asp:Label ID="lblTurnoHorario" runat="server" Text="Turno:"></asp:Label>      <%-- Horarios --%>
      <asp:DropDownList ID="ddlTurnoHorario" runat="server" CssClass="ddl-form">
          <asp:ListItem Text="-- Turno --" Value="0"/> <asp:ListItem Text="Mañana (08:00-12:00)" Value="08:00-12:00"/> <asp:ListItem Text="Tarde (12:00-16:00)" Value="12:00-16:00"/> <asp:ListItem Text="Noche (16:00-20:00)" Value="16:00-20:00"/>
      </asp:DropDownList>
      <asp:RequiredFieldValidator ID="rfvHorarios" runat="server" ControlToValidate="ddlTurnoHorario" InitialValue="0" ErrorMessage="Seleccione un rango horario" Display="Static" CssClass="error-validacion"/>     
     </div> 
    <div class="cblPadre">
        <%-- 1. BLOQUE IZQUIERDO (Etiqueta + Validador) --%>
      <div class="cblPadre__lbl"> 
          <asp:Label ID="lblDias" runat="server" Text="Días de Atención:"></asp:Label>
      </div>
    
      <%-- 2. BLOQUE CENTRAL (CheckboxList - la tabla) --%>
      <div class ="cblPadre__checks">
        <asp:CheckBoxList ID="cblDias" runat="server" RepeatDirection="Horizontal"/>
      </div>
    
      <%-- 3. BLOQUE DERECHO (El Espaciador Invisible) --%>
      <div class="cblPadre__validator">
        <asp:CustomValidator ID="cvDias" runat="server"  ErrorMessage="Seleccione al menos un día"   CssClass="error-validacion" Display="Static"    ClientValidationFunction="validarCheckBox"/>
      </div> 
    </div>

    <%-- MSJ DNI DUPLICADO --%>
    <div class="fila-mensajes">
        <asp:Label ID="lblMensajeExito" runat="server" CssClass="mensaje-exito" Visible="false"></asp:Label>
        <asp:Label ID="lblMensajeError" runat="server" CssClass="mensaje-error" Visible="false"></asp:Label>
    </div>

    <div class="fila-boton-Editar"> 
       <asp:Button ID="btnEditarMedico" CssClass="btnAgregar" runat="server" Text="Guardar Cambios" OnClick="btnEditarMedico_Click"/>
       <asp:HyperLink ID="hlVolver" runat="server" NavigateUrl="ListadoMedicos.aspx" CssClass="btnVolver" Visible="false">Volver al Listado</asp:HyperLink>
    </div>

 </div>   <%--class="contenedor-columnas">--%>

</asp:Content>
