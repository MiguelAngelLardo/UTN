<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Inicio.aspx.cs" Inherits="Vista.Inicio" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Clínica - Iniciar Sesión</title>
    <link href="Estilos/Login.css" rel="stylesheet" type="text/css" />

    <link href='https://unpkg.com/boxicons@2.1.4/css/boxicons.min.css' rel='stylesheet'/>
    
</head>


<body>
    <form id="form1" runat="server">
        <div class="log-in">

            <h1>Login</h1>


            <%-- 1. TextBox para el Usuario (ID="tbUsuario") el palceholder es el texto para ayuda--%>
            <div class="input-txtbox">
                <asp:TextBox ID="tbUsuario" placeholder="Usuario" class="txt" runat="server"></asp:TextBox>
            </div>

              <%-- 2. TextBox para la Contraseña (ID="tbContraseña") uso el i de icono --%>
            <div class="input-txtbox">
                <asp:TextBox ID="tbContraseña" placeholder="Contraseña" class="txt" runat="server" TextMode="Password"></asp:TextBox>
                <i class='bx bxs-lock-alt' ></i> <%--es para el icono de boxicons --%>
                 <i id="togglePass" class='bx bx-show' style="cursor:pointer;"></i> 
            </div>

            <script>
 
            const toggle = document.getElementById("togglePass");
            const input = document.getElementById("<%= tbContraseña.ClientID %>");

            toggle.addEventListener("click", () => {
            if (input.type === "password") {
            input.type = "text";
            toggle.classList.replace("bx-show", "bx-hide");
             } else {
            input.type = "password";
            toggle.classList.replace("bx-hide", "bx-show");
            }
            });
            </script>


            <%--DropDownList para el Tipo de Usuario (ID="ddlUsuario") --%>
            <div class="input-ddl">
                <asp:DropDownList ID="ddlUsuario" runat="server" class="ddl">
                    <%-- Los 'Value' deben coincidir ("0", "Admin", "Medico") --%>
                    <asp:ListItem Text="-- Seleccione tipo de Usuario --" Value="0"></asp:ListItem>
                    <asp:ListItem Text="Administrador" Value="Admin"></asp:ListItem>
                    <asp:ListItem Text="Medico" Value="Medico"></asp:ListItem>
                </asp:DropDownList>
            </div>

            <%-- Botón de Acceso --%>
            <asp:Button ID="btnAcceder" runat="server" Text="ACCEDER" class="button-control" OnClick="btnAcceder_Click"/>

            
            <%-- Label para Errores --%>
            <div class="error-container">
                 <asp:Label ID="lblError" runat="server" ForeColor="#FF5050"></asp:Label>
            </div>



        </div>
    </form>
</body>
</html>
