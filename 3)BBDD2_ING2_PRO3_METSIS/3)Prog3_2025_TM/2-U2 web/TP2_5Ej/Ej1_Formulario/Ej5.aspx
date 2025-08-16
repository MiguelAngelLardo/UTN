<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Ej5.aspx.cs" Inherits="Tp2Ej1_Formulario.Ej5" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
          Elija su configuracion<br />
          <br />
          Seleccione cantidad de memoria :<br />
          <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
          <asp:DropDownList ID="ddlCantMem" runat="server">
          </asp:DropDownList>
          <br />
          <br />
          <br />
          <br />
          Seleccione accesorios:<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
          <asp:CheckBoxList ID="cblAccesorios" runat="server" Height="45px" style="margin-left: 40px" Width="101px">
          </asp:CheckBoxList>
          <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
          <asp:Button ID="btnCalculoPrecio" runat="server" OnClick="btnCalculoPrecio_Click" Text="Calcular Precio" />
          <br />
          <br />
          <br />
          <asp:Label ID="lblPrecioFinal" runat="server"></asp:Label>
          <br />
&nbsp;&nbsp;&nbsp;
        </div>
    </form>
</body>
</html>
