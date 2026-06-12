<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<style type="text/css"> 
    <jsp:include page="css/StyleSheet.css" /> 
</style>
<title>TP5_GRUPO_17</title>
</head>

<body class="body-login">

<form action="servletUsuario" method="post" class="login-container">
	<h1>Iniciar Sesion</h1>
	<label>Usuario</label> <input type="text" name="txtUsuario">   
  <label>Contraseña</label> <input type="password" name="txtPassword">
  
  <button type="submit" name="btnIngresar" class="btn-login">Ingresar</button>
  
  <% if(request.getAttribute("msjError") != null) { %>
  	<span class="error-message"><%= request.getAttribute("msjError") %></span>	
	<% } %>  
  
	 
</form>

</body>
</html>


 