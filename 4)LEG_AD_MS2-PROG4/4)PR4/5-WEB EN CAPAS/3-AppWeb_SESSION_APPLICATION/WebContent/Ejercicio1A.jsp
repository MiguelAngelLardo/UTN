<%@page import="javax.xml.ws.Response"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Ejercicio 1A</title>
</head>
<body>

<!-- Transpaso de variable session de JSP A JSP -->

<!-- Redirigo al mismo JSP para que se cree la variable session antes de redirigir -->

<form method="get" action="Ejercicio1A.jsp">
	Ingrese valor: <input type="text" name="txtValor">
	<input type="submit" value="Aceptar" name="btnAceptar">
</form>


<%
	//Se hizo click sobre el boton aceptar
	if(request.getParameter("btnAceptar")!=null)
	{
		//Fijarse que session ya existe, asi como el request
		//Dentro de session, creo una nueva variable session mediante el setAttribute
		session.setAttribute("Session_Ej1", request.getParameter("txtValor"));
		//La variable session se va a llamar Session_Ej1 y va a tener lo que ingreso en el input txtValor
		//Redirijo a otro JSP
		response.sendRedirect("Ejercicio1B.jsp");
	}
%>


</body>
</html>