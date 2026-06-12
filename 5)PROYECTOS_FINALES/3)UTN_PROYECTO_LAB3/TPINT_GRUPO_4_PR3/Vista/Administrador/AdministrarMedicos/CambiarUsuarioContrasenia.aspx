
<%@ Page Language="C#" MasterPageFile="~/Principal.Master"
         AutoEventWireup="true"
         CodeBehind="CambiarUsuarioContrasenia.aspx.cs"
         Inherits="Vista.Administrador.AdministrarMedicos.CambiarUsuarioContrasenia" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

 <h2 class="titulo-pagina">Administrar Usuario</h2>

  <div class="contenedor-unacolumna">
      <div class="columna-centrada">
            <%-- Legajo: este campo ya viene completado de la pantalla anterior --%>
             <asp:Label ID="lblLegajoMedicoCambio" runat="server" Text="N° Legajo:"></asp:Label>
            <asp:TextBox ID="txtLegajoMedicoCambio" runat="server" CssClass="input-txtbox-form"></asp:TextBox>
          </div>
         </div>

   <div class="contenedor-filtros">
        <asp:RadioButtonList ID="radioOpcionCambio" runat="server" RepeatDirection="Horizontal" CssClass="radio-opciones" AutoPostBack="true" OnSelectedIndexChanged="radioOpcionCambio_SelectedIndexChanged">
            <asp:ListItem Selected="True">Usuario</asp:ListItem>  <asp:ListItem>Contraseña</asp:ListItem>
        </asp:RadioButtonList>
    </div>

    <%-- Cambio de Usuario --%>
    <div id="divCambioUsuario" runat="server" visible="true">
      <div class="contenedor-unacolumna">
          <div class="columna-centrada">
            <asp:Label ID="lblUsuarioCambio" runat="server" Text="Usuario:"></asp:Label>
            <asp:TextBox ID="txtUsuarioCambio" runat="server" CssClass="input-txtbox-form"></asp:TextBox>
             <asp:CustomValidator ID="cvUsuario" runat="server" ControlToValidate="txtUsuarioCambio" ErrorMessage="-"  ClientValidationFunction="validarUsuario" Display="Static" CssClass="error-validacion" ValidateEmptyText="true" ValidationGroup="GrupoGuardar" />
           </div>
      </div>
    </div>

    <%-- Cambio de Contraseña --%>
    <div id="divCambioContraseña" runat="server" visible="false">
           <div class="contenedor-unacolumna">
        <div class="columna-centrada">
            <asp:Label ID="lblContraseñaCambio" runat="server" Text="Contraseña:"></asp:Label>
               <div class="pass-container">
              <asp:TextBox ID="txtContraseñaCambio" runat="server" TextMode="Password" CssClass="input-txtbox-form"></asp:TextBox>
                <i id="togglePass3" class="bx bx-show"></i>
                </div>
           <asp:CustomValidator ID="cvPassword" runat="server" ControlToValidate="txtContraseñaCambio" ErrorMessage="-"  ClientValidationFunction="validarContrasena" Display="Static" CssClass="error-validacion" ValidateEmptyText="true" ValidationGroup="GrupoGuardar"/>

          <asp:Label ID="lblRepitaContraseñaCambio" runat="server" Text="Repita Contraseña:"></asp:Label>    
            <div class="pass-container">
            <asp:TextBox ID="txtRepitaContraseñaCambio" runat="server" TextMode="Password" CssClass="input-txtbox-form"></asp:TextBox>
            <i id="togglePass4" class="bx bx-show"></i>  
            </div>
         <asp:CompareValidator ID="cvContraseñasCambio" runat="server"
        ControlToCompare="txtContraseñaCambio"
        ControlToValidate="txtRepitaContraseñaCambio"
        ErrorMessage="Las contraseñas no coinciden"
        Display="Static" 
        CssClass="error-validacion"
        ValidationGroup="GrupoGuardar"/>
        </div>
    </div>
    </div>

    <div class="fila-mensajes" > 
      <asp:Label ID="lblMensajeExito" runat="server" CssClass="mensaje-exito" Visible="false"></asp:Label>
       <asp:Label ID="lblMensajeError" runat="server" CssClass="mensaje-error" Visible="false"></asp:Label>
   </div>
    <%-- Botón guardar (siempre visible ya que hay una opción activa) --%>
    <div style="display: flex; justify-content: space-around;">
        <asp:Button ID="btnGuardarCambio"  ValidationGroup="GrupoGuardar" CssClass="btnAgregar" runat="server" Text="Guardar cambios" OnClick="btnGuardarCambio_Click" />
    </div>
  
                <%--  script para ocultar y desocultar contraseña --%>
<script>
    const toggle3 = document.getElementById("togglePass3");
    const toggle4 = document.getElementById("togglePass4");

    const pass3 = document.getElementById("<%= txtContraseñaCambio.ClientID %>");
const pass4 = document.getElementById("<%= txtRepitaContraseñaCambio.ClientID %>");

    toggle3.addEventListener("click", () => {
        if (pass3.type === "password") {
            pass3.type = "text";
            toggle3.classList.replace("bx-show", "bx-hide");
        } else {
            pass3.type = "password";
            toggle3.classList.replace("bx-hide", "bx-show");
        }
    });

    toggle4.addEventListener("click", () => {
        if (pass4.type === "password") {
            pass4.type = "text";
            toggle4.classList.replace("bx-show", "bx-hide");
        } else {
            pass4.type = "password";
            toggle4.classList.replace("bx-hide", "bx-show");
        }
    });
</script>

</asp:Content>