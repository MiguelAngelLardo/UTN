<%@ Page Title="" Language="C#" MasterPageFile="~/Principal.Master" AutoEventWireup="true" CodeBehind="DetallePaciente.aspx.cs" Inherits="Vista.Administrador.AdministrarPacientes.DetallePaciente" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
        <div class="contenedor-detalle">
        <div class="info-grid">
        <asp:Label ID="lblNombre" runat="server" CssClass="titulo-detalle"/>
                
            <span class="label-dato" style="padding-left:10px">DNI:</span>
<asp:Label ID="lblDNI" runat="server" CssClass="valor-dato"></asp:Label>
            <div>
        <br />
        

            <div>
                <span class="label-dato">Sexo:</span>
                <asp:Label ID="lblSexo" runat="server" CssClass="valor-dato"></asp:Label>
            </div>

            <div>
                <span class="label-dato">Nacionalidad:</span>
                <asp:Label ID="lblNacionalidad" runat="server" CssClass="valor-dato"></asp:Label>
            </div>

            <div>
                <span class="label-dato">Fecha de nacimiento:</span>
                <asp:Label ID="lblFechaNacimiento" runat="server" CssClass="valor-dato"></asp:Label>
            </div>

            <div>
                <span class="label-dato">Dirección:</span>
                <asp:Label ID="lblDireccion" runat="server" CssClass="valor-dato"></asp:Label>
            </div>

            <div>
                <span class="label-dato">Localidad:</span>
                <asp:Label ID="lblLocalidad" runat="server" CssClass="valor-dato"></asp:Label>
            </div>

            <div>
                <span class="label-dato">Provincia:</span>
                <asp:Label ID="lblProvincia" runat="server" CssClass="valor-dato"></asp:Label>
            </div>

            <div>
                <span class="label-dato">Correo electrónico:</span>
                <asp:Label ID="lblCorreo" runat="server" CssClass="valor-dato"></asp:Label>
            </div>

            <div>
                <span class="label-dato">Teléfono:</span>
                <asp:Label ID="lblTelefono" runat="server" CssClass="valor-dato"></asp:Label>
            </div>
        
            <asp:Button ID="btnVolver" runat="server" Text="Volver" CssClass="btnAccion btnVer" OnClick="btnVolver_Click"/>
            </div>
       </div>

       <%-- <div class="contenedor-botones">
            
        </div>--%>
        </div>
</asp:Content>
