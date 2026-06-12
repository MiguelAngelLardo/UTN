<%@page import="dominio.Usuario"%>
<%@page import="java.util.ArrayList"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

<a href="servletUsuario?Param=1"> Mostrar usuarios </a>

<br/>
<br/>
<br/>

<% 
	ArrayList<Usuario> listaUsuarios = null;
	if(request.getAttribute("listaU")!=null)
	{
		listaUsuarios = (ArrayList<Usuario>) request.getAttribute("listaU");
	}

 %>


<table id="table_id" class="display">
    <thead>
        <tr>
            <th>ID</th>
            <th>Nombre</th>
            <th>Apellido</th>
            <th></th>
        </tr>
    </thead>
    <tbody>
       <%  if(listaUsuarios!=null)
		for(Usuario user : listaUsuarios) 
		{
	%>
		<tr>  
		    <form name="formulario" action="servletUsuario?idUsuario=<%=user.getId()%>" method="get">
				<td><%=user.getId() %>    <input type="hidden" name="idUsuario" value="<%=user.getId()%>"> </td> 
				<td><%=user.getNombre() %></td>   
				<td><%=user.getApellido() %></td>
				<td> <input type="submit" name="btnEliminar2" value="Eliminar"> </td>   
			</form> 
		</tr>
	<%  } %>
    </tbody>
</table>

</body>
</html>