<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%> 

<%@ page import="java.util.ArrayList" %>
<%@ page import="dominio.TipoSeguro" %>

<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>TP4_GRUPO_17</title>
</head>
<body>
  <%@ include file="Header.jsp" %>
	<h1>Agregar Seguros</h1>
	
	
	
	<%--
		<%
			int id = 0;
    	if(request.getAttribute("proxId") != null) { id = (int)request.getAttribute("proxId");  }
  	%>
    <tr> <td>Id Seguro:</td> <td> <strong><%=id%></strong> </td> </tr> <tr>	
	 --%>
	
	
	<form action="servletSeguro" method="post">
	  <table>
	    <tr> <td>Id Seguro:</td>              <td> <strong>${proxId}</strong> </td>                                   </tr>
	    <tr> <td>Descripción:</td>            <td> <input type="text" name="txtDescripcion" size="40" /> </td>        </tr>	      	    
			<tr> 
	    	<td>Tipo de Seguro:</td> 
	    	<td> 
	        <select name="ddlTipoSeguro">
	        	<% if(request.getAttribute("listaTipos") != null) {
	        	 //no puedo usar 	@SuppressWarnings("unchecked") por que deberia inicializar formalmente el array antes                                                           
	           for(TipoSeguro t : (ArrayList<TipoSeguro>)request.getAttribute("listaTipos")) {%> 
	             <option value="<%= t.getIdTipo() %>"><%= t.getDescripcion() %></option>         
	        	 <% } } %>																																						
	        </select> 																																					
	    	</td> 																																								
		  </tr>																																										
	    <tr> <td>Costo contratación:</td>     <td> <input type="text" name="txtCostoContratacion" /> </td>               </tr>
	    <tr> <td>Costo Máximo Asegurado:</td> <td> <input type="text" name="txtCostoMaximo" /> </td>                     </tr>
	    <tr> <td></td>                        <td> <input type="submit" name="btnAceptar" value="Aceptar" /> </td>       </tr>
		</table>
	</form>
	
		<%-- Mensaje de Éxito --%>
	<% if(request.getAttribute("seAgrego") != null) { %>
    <p style="color: green; font-weight: bold;">Seguro agregado con éxito</p>
	<% } %>

	<%-- Mensaje de Error de Validación --%>
	<% if(request.getAttribute("msjError") != null) { %>
	    <p style="color: red; font-weight: bold;"><%= request.getAttribute("msjError") %></p>
	<% } %>
	

	
</body>
</html>


<%--request.getAttribute de vuelve OBJECT(caja cerrada q pued etener cualquier cosa--%>
<%--pero al casterlo le digo Confía en mí, yo sé que adentro de esta caja hay un ArrayList de TipoSeguro--%>
<%--pdebido a algo llamado Type Erasure, no puede verificar en tiempo de compilación si hay TipoSeguro => "eso es tu responsabilidad"/Unchecked cast--%>		
<%--Type Erasure significa que usa Generic (lo que va entre los picoparentesis < >) solo existen mientras escribís el código. --%>
<%--Java ve el ArrayList pero al compilar pierde la nocion d que es de TipoSeguro => para JAVA es una "lista de objetos" --%>