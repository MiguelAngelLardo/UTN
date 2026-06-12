<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>

<%@ page import="java.util.ArrayList, dominio.TipoSeguro, dominio.Seguro" %>


<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>TP4_GRUPO_17</title>
</head>
<body>
  <%@ include file="Header.jsp" %>
  <h1>Listado de Seguros</h1>
  
  <form action="servletSeguro" method="post">
   	Filtrar por tipo: 
    <select name="ddlTipoSeguro">
    	<option value="0">-- Todos --</option> 
      	<% if(request.getAttribute("listaTipos") != null) {
      		for(TipoSeguro t : (ArrayList<TipoSeguro>)request.getAttribute("listaTipos")) { %>
      			<option value="<%= t.getIdTipo() %>"><%= t.getDescripcion() %></option>
         <% } } %>
    </select>
    <input type="submit" name="btnFiltrar" value="Filtrar"> 
    <input type="submit" name="btnMostrarTodos" value="Mostrar todos">
  </form>
   
   <br><br>
   <table border="1">
   <tr> 	<th>ID<br>Seguro</th> <th>Descripción</th> <th>Tipo de<br>Seguro</th> <th>Costo<br>Contratación</th> <th>Costo Máx.<br>Asegurado</th> </tr>
	 <% if(request.getAttribute("listaSeguros") != null) {
       for(Seguro s : (ArrayList<Seguro>)request.getAttribute("listaSeguros")) { %>
        <tr>
            <td><%= s.getIdSeguro() %></td>
            <td><%= s.getDescripcion() %></td>
            <td><%= s.getTipoSeguro().getDescripcion() %></td>
            <td><%= s.getCostoContratacion() %></td>
            <td><%= s.getCostoAsegurado() %></td>
        </tr>
    <% } } %>
   </table>

</body>
</html>