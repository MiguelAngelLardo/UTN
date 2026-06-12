<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

<% // Para fijar una variable applicattion en un jsp
   application.setAttribute("Application_Ej3_1", new Integer(1000));

   // Para leerla en otro o el mismo JSP
   Integer numero = (Integer)application.getAttribute("Application_Ej3_1");
%>

<br/>

<!-- Vamos al servlet para crear otra variable application  -->
<form method="get" action="ServletEjercicio3">
	Ingrese valor entero: <input type="text" name="txtValor">
	<input type="submit" value="Aceptar" name="btnAceptar">	
</form>


</body>
</html>