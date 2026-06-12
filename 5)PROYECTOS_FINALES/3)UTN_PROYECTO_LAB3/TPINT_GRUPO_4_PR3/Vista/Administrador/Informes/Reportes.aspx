<%@ Page Title="" Language="C#" MasterPageFile="~/Principal.Master" AutoEventWireup="true" CodeBehind="Reportes.aspx.cs" Inherits="Vista.Administrador.Informes.Reportes" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

    <h2 class="titulo-pagina">Panel de Informes y Estadísticas</</h2>


    <%-- Ejemplo 1 de informe con filtros de fecha y un Label --%>
    <h3 style="margin-bottom: 15px; margin-top: 25px;">1. Informe de Ausentismo por Fechas</h3>

    <div class="contenedor-filtros">

        <asp:Label ID="lblFechaDesde" runat="server" Text="Fecha Desde:" />
        <asp:TextBox ID="txtFechaDesde" runat="server" CssClass="input-txtbox-busqueda" TextMode="Date"></asp:TextBox>
        <asp:Label ID="lblFechaHasta" runat="server" Text="Fecha Hasta:" />
        <asp:TextBox ID="txtFechaHasta" runat="server" CssClass="input-txtbox-busqueda" TextMode="Date"></asp:TextBox>
        <asp:Button ID="btnGenerarReporteAusentismo" runat="server" Text="Generar Reporte" CssClass="btnBuscar" OnClick="btnGenerarReporteAusentismo_Click" ValidationGroup="GrupoReporte1" />
    </div>

    <div style="width: 100%; margin-top: 5px;">

        <div>
            <asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server"
                ControlToValidate="txtFechaDesde"
                ErrorMessage="Error: La fecha 'Desde' es obligatoria."
                ForeColor="Red"
                ValidationGroup="GrupoReporte1"
                Display="Dynamic">
        </asp:RequiredFieldValidator>
        </div>

        <div>
            <asp:RequiredFieldValidator ID="RequiredFieldValidator4" runat="server"
                ControlToValidate="txtFechaHasta"
                ErrorMessage="Error: La fecha 'Hasta' es obligatoria."
                ForeColor="Red"
                ValidationGroup="GrupoReporte1"
                Display="Dynamic">
        </asp:RequiredFieldValidator>
        </div>

        <div>
            <asp:CompareValidator ID="cvFechasReporte1" runat="server"
                ControlToValidate="txtFechaHasta"
                ControlToCompare="txtFechaDesde"
                Operator="GreaterThanEqual"
                Type="Date"
                ErrorMessage="La fecha 'Hasta' debe ser mayor o igual a la fecha 'Desde'."
                ForeColor="Red"
                Display="Dynamic"
                ValidationGroup="GrupoReporte1" />
        </div>

        <div>
            <asp:Label ID="lblMensaje" runat="server" Text="" Font-Bold="true"></asp:Label>
        </div>

    </div>



    <%-- CARDS INFORME 1 - TOTAL PRESENTE AUSENTE --%>

    <div class="contenedor-kpi">

        <div class="card-kpi card-total">
            <h4 class="kpi-titulo">Presentes</h4>
            <asp:Label ID="lblPresentes" runat="server" Text="-" CssClass="kpi-numero"></asp:Label>
        </div>

        <div class="card-kpi card-total">
            <h4 class="kpi-titulo">Ausentes</h4>
            <asp:Label ID="lblAusentes" runat="server" Text="-" CssClass="kpi-numero"></asp:Label>
        </div>

        <div class="card-kpi card-total">
            <h4 class="kpi-titulo">Total Turnos</h4>
            <asp:Label ID="lblTotal" runat="server" Text="-" CssClass="kpi-numero"></asp:Label>
        </div>

    </div>

    <%-- GRID DETALLE INFORME 1 --%>
    <div style="margin-top: 25px; margin-left: 5px;">
        <asp:GridView ID="GridView1" runat="server" CssClass="tabla-medicos" AutoGenerateColumns="False" EmptyDataText="No se encontraron datos para este rango de fechas." OnRowDataBound="GridView1_RowDataBound">
            <Columns>
                <asp:BoundField DataField="Fecha_T" HeaderText="Fecha" DataFormatString="{0:dd/MM/yyyy}" />
                <asp:BoundField DataField="Hora_T" HeaderText="Hora" DataFormatString="{0:hh\:mm}" />
                <asp:BoundField DataField="Nombre_P" HeaderText="Nombre" />
                <asp:BoundField DataField="Apellido_P" HeaderText="Apellido" />
                <asp:TemplateField HeaderText="Estado">
                    <ItemTemplate>
                        <asp:Label ID="lblEstado" runat="server" Text=""> </asp:Label>
                    </ItemTemplate>
                </asp:TemplateField>
            </Columns>
        </asp:GridView>

    </div>


    <%-- Ejemplo 2 de informe con un GridView--%>
    <hr style="margin-top: 30px; margin-bottom: 30px;" />
    <h3 style="margin-bottom: 15px; margin-top: 25px;">2. Informe: Turnos por Especialidad</h3>

    <div class="contenedor-filtros">

        <asp:Label ID="Label1" runat="server" Text="Fecha Desde:" />
        <asp:TextBox ID="TextBox1" runat="server" CssClass="input-txtbox-busqueda" TextMode="Date"></asp:TextBox>
        <asp:Label ID="Label2" runat="server" Text="Fecha Hasta:" />
        <asp:TextBox ID="TextBox2" runat="server" CssClass="input-txtbox-busqueda" TextMode="Date"></asp:TextBox>
        <asp:Button ID="btnGenerarReporte2" runat="server" Text="Generar Reporte" CssClass="btnBuscar" OnClick="btnGenerarReporte2_Click" ValidationGroup="GrupoReporte2" />
    </div>

    <div style="width: 100%; margin-top: 5px;">

        <div>
            <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server"
                ControlToValidate="TextBox1"
                ErrorMessage="Error: La fecha 'Desde' es obligatoria."
                ForeColor="Red"
                ValidationGroup="GrupoReporte2"
                Display="Dynamic">
        </asp:RequiredFieldValidator>
        </div>

        <div>
            <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server"
                ControlToValidate="TextBox2"
                ErrorMessage="Error: La fecha 'Hasta' es obligatoria."
                ForeColor="Red"
                ValidationGroup="GrupoReporte2"
                Display="Dynamic">
        </asp:RequiredFieldValidator>
        </div>

        <div>
            <asp:CompareValidator ID="cvFechasReporte2" runat="server"
                ControlToValidate="TextBox2"
                ControlToCompare="TextBox1"
                Operator="GreaterThanEqual"
                Type="Date"
                ErrorMessage="La fecha 'Hasta' debe ser mayor o igual a la fecha 'Desde'."
                ForeColor="Red"
                Display="Dynamic"
                ValidationGroup="GrupoReporte2" />
        </div>
    </div>


    <div class="contenedor-kpi">

        <div class="card-kpi card-total">
            <h4 class="kpi-titulo">Cantidad maxima de turnos por especialidad</h4>
            <asp:Label ID="lblTurnoPorMedico" runat="server" Text="-" CssClass="kpi-numero"></asp:Label>
        </div>


        <div class="card-kpi card-total">
            <h4 class="kpi-titulo">Promedio de turnos por médico</h4>
            <asp:Label ID="lblPromedio" runat="server" Text="-" CssClass="kpi-numero"></asp:Label>
        </div>

        <div class="card-kpi card-total">
            <h4 class="kpi-titulo">Total de Turnos</h4>
            <asp:Label ID="lblTotalTurnos" runat="server" Text="-" CssClass="kpi-numero"></asp:Label>
        </div>

    </div>

    <%-- GridView para mostrar el informe de Turnos por Especialidad --%>
    <div style="margin-top: 15px;">
        <asp:GridView ID="gvReporteMedicos" runat="server" CssClass="tabla-medicos" AutoGenerateColumns="False" EmptyDataText="No se encontraron datos para este rango de fechas.">
            <Columns>
                <asp:BoundField DataField="Especialidad" HeaderText="Especialidad" />
                <asp:BoundField DataField="CantidadTurnos" HeaderText="Cantidad de Turnos" ItemStyle-HorizontalAlign="Center" />
            </Columns>
        </asp:GridView>
    </div>

</asp:Content>
