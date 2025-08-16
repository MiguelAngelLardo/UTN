<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Ej2a.aspx.cs" Inherits="Ej1_Formulario.WebForm2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
          Nombre:&nbsp;
          <asp:TextBox ID="txtNombre" runat="server"></asp:TextBox>
          <br />
          <br />
          Apellido:
          <asp:TextBox ID="txtApellido" runat="server"></asp:TextBox>
          <br />
          <br />
          Ciudad:&nbsp;
          <asp:DropDownList ID="ddlCiudades" runat="server">
          </asp:DropDownList>
          <br />
          <br />
          Temas:&nbsp;
          <blockquote> <%-- Aquí empieza la sangría --%>
            <asp:CheckBoxList ID="cblTemas" runat="server">
            </asp:CheckBoxList>
          </blockquote>
          <blockquote> <%-- Aquí empieza la sangría --%>
            <asp:Button ID="btnResumen" runat="server" Text="Ver resumen" UseSubmitBehavior="False" OnClick="btnResumen_Click" />
          </blockquote>
          <br />
        </div>
    </form>
</body>
</html>
