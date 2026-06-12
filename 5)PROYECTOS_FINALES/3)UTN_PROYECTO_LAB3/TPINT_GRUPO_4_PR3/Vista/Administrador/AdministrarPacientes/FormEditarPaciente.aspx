<%@ Page Title="" Language="C#" MasterPageFile="~/Principal.Master" AutoEventWireup="true" CodeBehind="FormEditarPaciente.aspx.cs" Inherits="Vista.Administrador.AdministrarPacientes.FormEditarPaciente" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
   
  <h2 class="titulo-pagina">Editar Paciente</h2>
  <div class="contenedor-columnas">
    <div class="columna">
      <asp:Label ID="lblDNI" runat="server" Text="DNI:"></asp:Label> <%-- dni --%>
      <asp:TextBox ID="txtDNI" runat="server" CssClass="input-txtbox-form" ReadOnly="True"></asp:TextBox>
      <asp:CustomValidator ID="cvDni" runat="server" ControlToValidate="txtDNI" ErrorMessage="-" ClientValidationFunction="validarDni" Display="Static" CssClass="error-validacion"  ValidateEmptyText="true"/> 

      <asp:Label ID="lblNombre" runat="server" Text="Nombre:"></asp:Label> <%-- nombre --%>
      <asp:TextBox ID="txtNombre" runat="server" CssClass="input-txtbox-form"></asp:TextBox>
      <asp:CustomValidator ID="cvNombre" runat="server" ControlToValidate="txtNombre" ErrorMessage="-" ClientValidationFunction="validarNomApeNac" Display="Static" CssClass="error-validacion" ValidateEmptyText="true"/>

      <asp:Label ID="lblPronvica" runat="server" Text="Provincia:"></asp:Label> <%-- provincia --%>
      <asp:DropDownList ID="ddlProvincias" runat="server" CssClass="ddl-form" AutoPostBack="True" OnSelectedIndexChanged="ddlProvincias_SelectedIndexChanged"/> 
      <asp:RequiredFieldValidator ID="rfvProvincia" runat="server" ControlToValidate="ddlProvincias" InitialValue="0" ErrorMessage="Seleccione provincia" Display="Static" CssClass="error-validacion"  />

       <asp:Label ID="lblDireccion" runat="server" Text="Dirección:"></asp:Label>                    <%-- Dirección --%>
       <asp:TextBox ID="txtDireccion" runat="server" CssClass="input-txtbox-form"></asp:TextBox>
       <asp:RequiredFieldValidator ID="rfvDireccion" runat="server" ControlToValidate="txtDireccion" ErrorMessage="Ingrese Dirección" Display="Static" CssClass="error-validacion"/>
      
        <asp:Label ID="lblSexo" runat="server" Text="Sexo:"></asp:Label> <%-- sexo --%>
        <asp:DropDownList ID="ddlSexo" runat="server" CssClass="ddl-form">
          <asp:ListItem Text="-- Seleccione una opción --" Value="0"></asp:ListItem> <asp:ListItem Text="Femenino" Value="F"></asp:ListItem> <asp:ListItem Text="Masculino" Value="M"></asp:ListItem>
        </asp:DropDownList>
        <asp:RequiredFieldValidator ID="rfvSexo" runat="server" ControlToValidate="ddlSexo" InitialValue="0" ErrorMessage="Seleccione sexo" Display="Static" CssClass="error-validacion"/>
   
        <asp:Label ID="lblFechaNacimiento" runat="server" Text="Fecha de Nacimiento:"></asp:Label> <%-- fecha de nacimiento --%>
        <asp:TextBox ID="txtFechaNacimiento" runat="server" CssClass="input-txtbox-form" TextMode="Date"></asp:TextBox>
        <asp:CustomValidator ID="cvEdadMinima" runat="server" ControlToValidate="txtFechaNacimiento" ErrorMessage="-" ClientValidationFunction="validarEdad" Display="Static" CssClass="error-validacion" ValidateEmptyText="true"/>
    </div>

    <div class="columna">        
      <asp:Label ID="lblNacionalidad" runat="server" Text="Nacionalidad:"></asp:Label> <%-- Nacionalidad --%>
      <asp:TextBox ID="txtNacionalidad" runat="server" CssClass="input-txtbox-form"></asp:TextBox>
      <asp:CustomValidator ID="cvNacionalidad" runat="server" ControlToValidate="txtNacionalidad" ErrorMessage="-" ClientValidationFunction="validarNomApeNac" Display="Static" CssClass="error-validacion" ValidateEmptyText="true"/>

      <asp:Label ID="lblApellido" runat="server" Text="Apellido:"></asp:Label> <%-- Apellido --%>
      <asp:TextBox ID="txtApellido" runat="server" CssClass="input-txtbox-form"></asp:TextBox>
      <asp:CustomValidator ID="cvApellido" runat="server" ControlToValidate="txtApellido" ErrorMessage="-" ClientValidationFunction="validarNomApeNac" Display="Static" CssClass="error-validacion" ValidateEmptyText="true"/>

      <asp:Label ID="lblLocalidad" runat="server" Text="Localidad:"></asp:Label> <%-- Localidad --%>
      <asp:DropDownList ID="ddlLocalidades" runat="server" CssClass="ddl-form"/>  
      <asp:RequiredFieldValidator ID="rfvLocalidad" runat="server" ControlToValidate="ddlLocalidades" InitialValue="0" ErrorMessage="Seleccione localidad" Display="Static"  CssClass="error-validacion" />

      
      <asp:Label ID="lblTelefono" runat="server" Text="Teléfono:"></asp:Label> <%-- Teléfono --%>
      <asp:TextBox ID="txtTelefono" runat="server" CssClass="input-txtbox-form"></asp:TextBox>
      <asp:CustomValidator ID="cvTel" runat="server" ControlToValidate="txtTelefono" ErrorMessage="-" lientValidationFunction="validarTelefono"  Display="Static" CssClass="error-validacion" ValidateEmptyText="true"/> 
     
          
      <asp:Label ID="lblCorreoElectronico" runat="server" Text="Correo Electrónico:"></asp:Label>   <%-- Correo --%>
      <asp:TextBox ID="txtCorreoElectronico" runat="server" CssClass="input-txtbox-form"></asp:TextBox>
      <asp:CustomValidator ID="cvMail" runat="server" ControlToValidate="txtCorreoElectronico" ErrorMessage="-" ClientValidationFunction="validarCorreo" Display="Static" CssClass="error-validacion" ValidateEmptyText="true"/>

      <asp:Label ID="Label1" runat="server" Text="Diagnostico:"></asp:Label>  <%-- Diagnostico --%>
      <asp:TextBox ID="txtDiagnostico" runat="server" CssClass="input-txtbox-form"></asp:TextBox>
      <asp:RequiredFieldValidator ID="rfvDiagnostico" runat="server" ControlToValidate="txtDiagnostico" ErrorMessage="Ingrese Diagnostico" Display="Static" CssClass="error-validacion" />
    </div>

    <div class="fila-mensajes">
     <asp:Label ID="lblMensajeExito" runat="server" CssClass="mensaje-exito" Visible="false"></asp:Label>
     <asp:Label ID="lblMensajeError" runat="server" CssClass="mensaje-error" Visible="false"></asp:Label>
    </div>

    <div class="fila-boton-Editar">
      <asp:Button ID="btnGuardarCambios" CssClass="btnAgregar" runat="server" Text="Guardar Cambios" OnClick="btnGuardarCambios_Click" />
      <asp:HyperLink ID="hlVolver" runat="server" NavigateUrl="ListadoPacientes.aspx" CssClass="btnVolver" Visible="false">Volver al Listado</asp:HyperLink>
    </div>

  </div> <%--class="contenedor-columnas">--%>

   
</asp:Content>