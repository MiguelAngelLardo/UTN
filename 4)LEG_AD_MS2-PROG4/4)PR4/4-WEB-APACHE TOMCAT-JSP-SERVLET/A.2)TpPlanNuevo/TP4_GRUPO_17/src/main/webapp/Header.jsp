<%@ page language="java" contentType="text/html; charset=UTF-8"  pageEncoding="UTF-8"%>
<nav>
    <a href="Inicio.jsp">Inicio</a> 
    <a href="servletSeguro?irAAgregar=1">Agregar seguro</a> <!-- puedo poner =loquesea que dara true en el if(request.getParameter("irAAgregar") != null) lo mejor e susar 1 o ture -->
    <a href="servletSeguro?irAListar=1">Listar seguros</a>
</nav>
<hr>