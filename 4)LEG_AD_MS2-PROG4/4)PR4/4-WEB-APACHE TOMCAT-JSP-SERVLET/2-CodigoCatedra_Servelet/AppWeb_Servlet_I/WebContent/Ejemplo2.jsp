<%@page import="dominio.Usuario"%>
<%@page import="java.util.ArrayList"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

<form method="post" action="servletUsuario">
	<input type="submit" name="btnMostrarUsuarios" value="Mostrar usuarios">
</form>


<% 
	ArrayList<Usuario> listaUsuarios = null;
	if(request.getAttribute("listaU")!=null)
	{
		listaUsuarios = (ArrayList<Usuario>) request.getAttribute("listaU");
	}

 %>

<table border="1">
	<tr> <th>ID</th>  <th>Nombre</th>  <th>Apellido</th>  <th></th> </tr>
	
	<%  if(listaUsuarios!=null)
		for(Usuario user : listaUsuarios) 
		{
	%>
	<tr>  
	     <form action="servletUsuario" method="post">
	     <td><%=user.getId() %> <input type="hidden" name="idUsuario" value="<%=user.getId() %>"> </td>    
	     <td><%=user.getNombre() %></td>   
	     <td><%=user.getApellido() %></td>   
	     <td> <input type="submit" name="btnEliminar" value="Eliminar"> </td>  
	     </form>  
	</tr>
	<%  } %>

</table>



</body>
</html>