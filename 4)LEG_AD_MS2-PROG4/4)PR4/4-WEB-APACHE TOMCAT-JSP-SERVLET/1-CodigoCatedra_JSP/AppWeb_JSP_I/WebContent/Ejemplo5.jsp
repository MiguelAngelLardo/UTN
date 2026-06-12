<%@page import="dominio.Usuario"%>
<%@page import="dominio.UsuarioDao"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

<form action="Ejemplo5.jsp" method="get">
	Ingrese su nombre: <input type="text" name="txtNombre"> <br>
	Ingrese su apellido: <input type="text" name="txtApellido"> <br>
	<input type="submit" name="btnAceptar" value="Aceptar">
</form>


<%
	int filas=0;
	if(request.getParameter("btnAceptar")!=null)
	{
		String nombre = request.getParameter("txtNombre");
		String apellido = request.getParameter("txtApellido");
		
		Usuario usuario = new Usuario();
		usuario.setApellido(apellido);
		usuario.setNombre(nombre);
		
		UsuarioDao usuarioDao = new UsuarioDao();
		filas= usuarioDao.agregarUsuario(usuario);
	}
%>


<% if(filas==1) 
	{
%>
     Se agrego exitosamente.
<% }%>

</body>
</html>