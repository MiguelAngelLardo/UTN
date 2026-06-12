<%@ Page Language="C#" MasterPageFile="~/Principal.Master"
         AutoEventWireup="true"
         CodeBehind="CrearUsuario.aspx.cs"
         Inherits="Vista.Administrador.AdministrarMedicos.CrearUsuario" %>


<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

  <h2 class="titulo-pagina">Crear usuario</h2>

  <div class="contenedor-unacolumna">
      <div class="columna-centrada">
            <%-- Legajo: este campo ya viene completado de la pantalla anterior --%>
            <asp:Label ID="lblLegajoMedico" runat="server" Text="N° Legajo:"></asp:Label>
            <asp:TextBox ID="txtLegajoMedico" runat="server" CssClass="input-txtbox-form" ></asp:TextBox>
            <br />
          <%--  usuario: Validamos que no haya otro usuario con ese nombre --%>
          <asp:Label ID="lblUsuario" runat="server" Text="Usuario:"></asp:Label>
          <asp:TextBox ID="txtUsuario" runat="server" CssClass="input-txtbox-form"></asp:TextBox>
           <asp:CustomValidator ID="cvUsuario" runat="server" ControlToValidate="txtUsuario" ErrorMessage="-"  ClientValidationFunction="validarUsuario" Display="Static" CssClass="error-validacion" ValidateEmptyText="true"/>

          <%--  Contraseña --%>
        <asp:Label ID="lblContraseña" runat="server" Text="Contraseña:"  ></asp:Label>
        <div class="pass-container">
        <asp:TextBox ID="txtContraseña" runat="server" TextMode="Password" CssClass="input-txtbox-form" ></asp:TextBox>
        <i id="togglePass1" class="bx bx-show"></i>
        </div>
       <asp:CustomValidator ID="cvPassword" runat="server" ControlToValidate="txtContraseña" ErrorMessage="-"  ClientValidationFunction="validarContrasena" Display="Static" CssClass="error-validacion" ValidateEmptyText="true"/>

          <%-- Repita contraseña --%>
           <asp:Label ID="lblRepitaContraseña" runat="server" Text="Repita Contraseña:"></asp:Label>
            <div class="pass-container">
            <asp:TextBox ID="txtRepitaContraseña" runat="server" TextMode="Password" CssClass="input-txtbox-form" ></asp:TextBox>
            <i id="togglePass2" class="bx bx-show"></i>
            </div>
          <asp:RequiredFieldValidator 
    ID="rfvRepitaContrasena"
    runat="server"
    ControlToValidate="txtRepitaContraseña"
    ErrorMessage="Debe repetir la contraseña"
    Display="Static"
    CssClass="error-validacion" />

          <asp:CompareValidator 
    ID="compararPass" 
    runat="server" 
    ControlToValidate="txtRepitaContraseña" 
    ControlToCompare="txtContraseña" 
    Operator="Equal" 
    Type="String" 
    ErrorMessage="Las contraseñas no coinciden" 
    Display="Static" 
    CssClass="error-validacion" />
          </div>
  </div>
  
  <div class="fila-mensajes" > 
        <asp:Label ID="lblMensajeExito" runat="server" CssClass="mensaje-exito" Visible="false"></asp:Label>
         <asp:Label ID="lblMensajeError" runat="server" CssClass="mensaje-error" Visible="false"></asp:Label>
    </div>

      <div class="fila-boton-guardar"> 
      <asp:Button ID="btnGuardarUsuario" CssClass="btnAgregar" runat="server" Text="Guardar"  OnClick="btnGuardarUsuario_Click"  />
     </div>
      <%--  script para ocultar y desocultar contraseña --%>
  <script>
      const toggle1 = document.getElementById("togglePass1");
      const toggle2 = document.getElementById("togglePass2");

      const pass1 = document.getElementById("<%= txtContraseña.ClientID %>");
  const pass2 = document.getElementById("<%= txtRepitaContraseña.ClientID %>");

      toggle1.addEventListener("click", () => {
          if (pass1.type === "password") {
              pass1.type = "text";
              toggle1.classList.replace("bx-show", "bx-hide");
          } else {
              pass1.type = "password";
              toggle1.classList.replace("bx-hide", "bx-show");
          }
      });

      toggle2.addEventListener("click", () => {
          if (pass2.type === "password") {
              pass2.type = "text";
              toggle2.classList.replace("bx-show", "bx-hide");
          } else {
              pass2.type = "password";
              toggle2.classList.replace("bx-hide", "bx-show");
          }
      });
  </script>

    </asp:Content>
