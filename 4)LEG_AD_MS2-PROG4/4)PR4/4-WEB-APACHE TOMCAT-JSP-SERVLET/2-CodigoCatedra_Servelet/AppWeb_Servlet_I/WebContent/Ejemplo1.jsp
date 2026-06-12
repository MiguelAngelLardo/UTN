<%@page import="dominio.UsuarioDao"%>
<%@page import="dominio.Usuario"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

<form action="servletUsuario" method="get">
	Ingrese su nombre:  <input type="text" name="txtNombre"> <br>
	Ingrese su apellido: <input type="text" name="txtApellido"> <br>
	<input type="submit" value="Aceptar" name="btnAceptar">
</form>

<%
	int filas=0;
	if(request.getAttribute("cantFilas")!=null)
		filas= (int)request.getAttribute("cantFilas");
	//	filas=  Integer.parseInt(request.getAttribute("cantFilas").toString());;	

%>


<% if(filas==1) 
	{
%>
		Usuario agregado con éxito
<%} %>

</body>
</html>