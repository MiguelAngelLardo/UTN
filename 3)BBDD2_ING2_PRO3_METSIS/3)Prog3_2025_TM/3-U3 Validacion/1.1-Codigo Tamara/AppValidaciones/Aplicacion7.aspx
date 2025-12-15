<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Aplicacion7.aspx.cs" Inherits="Video9.Aplicacion7" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
        .auto-style2 {
            width: 203px;
        }
        .auto-style3 {
            width: 203px;
            height: 23px;
        }
        .auto-style4 {
            height: 23px;
        }
        .auto-style5 {
            width: 211px;
        }
        .auto-style6 {
            height: 23px;
            width: 237px;
        }
        .auto-style7 {
            width: 237px;
        }
        .auto-style8 {
            width: 232px;
        }
        .auto-style9 {
            width: 90px;
            height: 23px;
        }
        .auto-style10 {
            width: 90px;
        }
        .auto-style11 {
            width: 88px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <br />
        <table class="auto-style1">
            <tr>
                <td class="auto-style9">&nbsp;</td>
                <td class="auto-style3">Ingrese nombre:</td>
                <td class="auto-style6">
                    <asp:TextBox ID="txtNombre" runat="server" ValidationGroup="Grupo1"></asp:TextBox>
                </td>
                <td class="auto-style4">
                    <asp:RequiredFieldValidator ID="rfvnombre" runat="server" ControlToValidate="txtNombre" ValidationGroup="Grupo1">*</asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style10">&nbsp;</td>
                <td class="auto-style2">Ingrese apellido:</td>
                <td class="auto-style7">
                    <asp:TextBox ID="txtApellido" runat="server" ValidationGroup="Grupo1"></asp:TextBox>
                </td>
                <td>
                    <asp:RequiredFieldValidator ID="rfvApellido" runat="server" ControlToValidate="txtApellido" ValidationGroup="Grupo1">*</asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style10">&nbsp;</td>
                <td class="auto-style2">&nbsp;</td>
                <td class="auto-style7">
                    <asp:Button ID="btnGuardarUsuario" runat="server" Text="Guardar usuario" OnClick="btnGuardarUsuario_Click" ValidationGroup="Grupo1" />
                </td>
                <td>&nbsp; &nbsp;<asp:Label ID="lblMensaje1" runat="server"></asp:Label>
                </td>
            </tr>
        </table>
        <br />
        <br />
        <table class="auto-style1">
            <tr>
                <td class="auto-style10">&nbsp;</td>
                <td class="auto-style5">Ingrese email :</td>
                <td class="auto-style8">
                    <asp:TextBox ID="txtEmail" runat="server" ValidationGroup="Grupo2"></asp:TextBox>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style10">&nbsp;</td>
                <td class="auto-style5">Repita email :</td>
                <td class="auto-style8">
                    <asp:TextBox ID="txtRepitaEmail" runat="server" ValidationGroup="Grupo2"></asp:TextBox>
                </td>
                <td>
                    <asp:CompareValidator ID="cvMail" runat="server" ControlToCompare="txtEmail" ControlToValidate="txtRepitaEmail" ValidationGroup="Grupo2">*</asp:CompareValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style10">&nbsp;</td>
                <td class="auto-style5">&nbsp;</td>
                <td class="auto-style8">
                    <asp:Button ID="btnGuardarMail" runat="server" Text="Guardar Mail" OnClick="btnGuardarMail_Click" ValidationGroup="Grupo2" />
                </td>
                <td>
                    <asp:Label ID="lblMensaje2" runat="server"></asp:Label>
                </td>
            </tr>
        </table>
        <br />
        <br />
        <table class="auto-style1">
            <tr>
                <td class="auto-style11">&nbsp;</td>
                <td>
                    <asp:Button ID="btnRedirigir" runat="server" Text="Ir a aplicacion6.aspx" OnClick="btnRedirigir_Click" ValidationGroup="Grupo3" />
                </td>
            </tr>
        </table>
        <br />
        <br />
        <br />
    
    </div>
    </form>
</body>
</html>

