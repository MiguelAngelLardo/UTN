<%@ Page Title="" Language="C#" MasterPageFile="~/Principal.Master" AutoEventWireup="true" CodeBehind="ListadoTurnos.aspx.cs" Inherits="Vista.Medico.AdministrarTurno.ListadoTurnos" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
    <style>
        /* Esto lo hago para que al hacer enter, se guarde y no pase a otro renglón. */
        .inputObservaciones {
            width: 100%;
            padding: 4px;
            height: 20px; 
        }

        .turno-pasado {/*if (esTurnoPasado) e.Row.CssClass = "turno-pasado";*/
            background-color: #f7e0e0 !important; /* Rojo claro */
            color: #888; /* Texto gris */
            font-style: italic;
        }

    </style>
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
<h2 class="titulo-pagina">Listado de Turnos</h2>

<div class="contenedor-busqueda">
    <asp:Label ID="lblPaciente" runat="server" Text="Paciente:"></asp:Label>
    <asp:TextBox ID="txtBuscarPorPaciente" CssClass="input-txtbox-busqueda" runat="server" placeholder="Nombre y apellido del paciente"></asp:TextBox>
    <asp:Button ID="btnBuscar" runat="server" Text="Buscar" CssClass="btnBuscar" OnClick="btnBuscar_Click" />
</div>

  <div class="contenedor-filtros">

      <asp:Label ID="lblAsistio" runat="server" Text="Filtrar por:"></asp:Label>
      <asp:DropDownList ID="ddlAsistencia" runat="server" CssClass="input-txtbox-busqueda">
            <asp:ListItem Text="Todos" Value="-1"></asp:ListItem>
            <asp:ListItem Text="Asistió" Value="1"></asp:ListItem>
            <asp:ListItem Text="No asistió" Value="0"></asp:ListItem>
      </asp:DropDownList>

       <asp:Label ID="lblFechas" runat="server" Text="Fecha:"></asp:Label>
       <asp:TextBox ID="txtFecha" CssClass="input-txtbox-busqueda" runat="server" placeholder="Seleccione una fecha"  TextMode="Date" ></asp:TextBox>
     
      <asp:Button ID="btnAplicarFiltros" runat="server" Text="Aplicar Filtros" CssClass="btnBuscar"  OnClick="btnAplicarFiltros_Click"  />
  </div>

<asp:GridView 
  ID="gvTurnos" runat="server" AutoGenerateColumns="False" CssClass="tabla-medicos" OnRowCommand="gvTurnos_RowCommand" OnRowDataBound="gvTurnos_RowDataBound" DataKeyNames="IdTurno" AllowPaging="True" PageSize="10" OnPageIndexChanging="gvTurnos_PageIndexChanging">
  <Columns>
    <asp:BoundField DataField="IdTurno" HeaderText="Id Turno" /><asp:BoundField DataField="Dia" HeaderText="Día" DataFormatString="{0:dd/MM/yyyy}" /> 
    <asp:BoundField DataField="Horario" HeaderText="Horario" /> <asp:BoundField DataField="Paciente" HeaderText="Paciente" />
    <asp:TemplateField HeaderText="Observaciones">
      <ItemTemplate>
        <asp:Panel ID="pnlObs" runat="server" DefaultButton="btnGuardarOculto"> <%--el defaul button usa enter de base Tecla 13--%>  
          <asp:TextBox ID="txtObservaciones" runat="server" CssClass="inputObservaciones" MaxLength="200" placeholder=""></asp:TextBox>  <%-- Enter funciona como Submit --%>
          <asp:Button ID="btnGuardarOculto" runat="server" style="display:none;" CommandName="Guardar"  CommandArgument='<%# Eval("IdTurno") %>' /> <%-- Botón Oculto que se dispara al presionar Enter --%>    
        </asp:Panel>
      </ItemTemplate>
    </asp:TemplateField>

    <asp:TemplateField HeaderText="Asistencia">
      <ItemTemplate> <%--this apunta al select del ddlAsistencia, y esa referencia la paso al JS para leer el ddl.Value--%>
        <asp:DropDownList ID="ddlAsistencia" runat="server"  OnSelectedIndexChanged="ddlAsistencia_SelectedIndexChanged" AutoPostBack="true"> <%-- onchange="actualizarObservacion(this,'<%# ((TextBox)((GridViewRow)Container).FindControl('txtObservaciones')).ClientID %>');  __doPostBack(this.name, '');"--%>
          <asp:ListItem Text="Seleccionar..." Value="-1"></asp:ListItem><asp:ListItem Text="Asistió" Value="1"></asp:ListItem> <asp:ListItem Text="No asistió" Value="0"></asp:ListItem>
        </asp:DropDownList>
      </ItemTemplate>
    </asp:TemplateField>
  </Columns>
</asp:GridView>


   <%-- MSJ DNI DUPLICADO --%>
 <div class="fila-mensajes">
  <asp:Label ID="lblEstadoTurno" runat="server" CssClass="mensaje-exito" Visible="false"></asp:Label>
  <asp:Label ID="lblErrorTurno" runat="server" CssClass="mensaje-error" Visible="false"></asp:Label>
 </div>


<script>
  //actualizarObservacion(this, 'ctl00_ContentPlaceHolder1_gvTurnos_ctl02_txtObservaciones'); //=> Nomenclatura Única de ASP.NET para el ClientID, asi identifica el TextBox en la misma fila del DropDownList
  // HTMLSelectElement ddl => El DropDownList que disparó el evento (referenciado por 'this'), string txtId El ClientID del TextBox de Observaciones en la misma fila

  //function actualizarObservacion(ddl, txtId) {      
  //  var pTextObser = document.getElementById(txtId);//puntero
  //  var valorSeleccionado = ddl.value.trim();         //valor real pasado a otra variable

  //  if (valorSeleccionado == "-1") {
  //    pTextObser.value = "";
  //    pTextObser.disabled = true;
  //    pTextObser.setAttribute("placeholder", "Debe seleccionar 'Asistió/No Asistió'");
  //  } else {
  //    pTextObser.disabled = false;
  //    pTextObser.setAttribute("placeholder", "Escriba aquí y presione Enter.");
  //  }
  //}
</script>

</asp:Content>

