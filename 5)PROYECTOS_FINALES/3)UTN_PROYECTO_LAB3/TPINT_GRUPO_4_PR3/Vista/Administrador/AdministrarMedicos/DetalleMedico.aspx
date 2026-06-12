<%@ Page Title="Detalle de Médico" Language="C#" MasterPageFile="~/Principal.Master"
    AutoEventWireup="true" CodeBehind="DetalleMedico.aspx.cs" Inherits="Vista.Administrador.AdministrarMedicos.DetalleMedico" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
    <style>
    </style>
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

    <div class="contenedor-detalle">
        <div class="info-grid">
        <asp:Label ID="lblNombre" runat="server" CssClass="titulo-detalle"/>
                
            <span class="label-dato" style="padding-left:10px">Legajo:</span>
<asp:Label ID="lblLegajo" runat="server" CssClass="valor-dato"></asp:Label>
            <div>
        <br />
        
                <span class="label-dato">DNI:</span>
                <asp:Label ID="lblDNI" runat="server" CssClass="valor-dato"></asp:Label>
            </div>

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

            <div>
                <span class="label-dato">Especialidad:</span>
                <asp:Label ID="lblEspecialidad" runat="server" CssClass="valor-dato"></asp:Label>
            </div>

            <div style="grid-column: span 2;">
                <span class="label-dato">Días y horario de atención:</span>
                <asp:Label ID="lblDiasHorario" runat="server" CssClass="valor-dato"></asp:Label>
            </div>
           <asp:Button ID="btnVolver" runat="server" Text="Volver" CssClass="btnAccion btnVer" OnClick="btnVolver_Click"/>
        </div>
       

<%--        <div class="contenedor-botones">
            <asp:Button ID="btnEditar" runat="server" Text="Editar" CssClass="btnAccion btnEditar" />
            <asp:Button ID="btnEliminar" runat="server" Text="Eliminar" CssClass="btnAccion btnEliminar" />
        </div>--%>
        </div>
</asp:Content>
