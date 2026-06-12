<%@page import="entidad.Articulo"%>
<%@page import="java.util.List"%>
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

	<%
		List<Articulo> listaA = new ArrayList<Articulo>();
		if (request.getAttribute("listaArt") != null) {
			listaA = (List<Articulo>) request.getAttribute("listaArt");
		}
	%>

	<a href="Principal.jsp">Inicio</a>
	<a href="ServletArticulos?Param=previoInsert">Insertar articulos</a>
	<a href="ServletArticulos?Param=list">Listar articulos</a>

<br/><br/><br/>

	<table border="1">
		<tr>
			<td><b>ID ARTICULO</b></td>
			<td><b>NOMBRE</b></td>
			<td><b>PRECIO</b></td>
			<td><b>ID CATEGORIA</b></td>
			<td><b>NOMBRE CATEGORIA</b></td>
			<td><b>ESTADO</b></td>
		</tr>

		<%
			for (Articulo a : listaA) {
		%>

		<tr>
			<td><%=a.getIdArticulo()%></td>
			<td><%=a.getNombre()%></td>
			<td><%=a.getPrecio()%></td>
			<td><%=a.getCategoria().getIdCategoria()%></td>
			<td><%=a.getCategoria().getNombre()%></td>
			<td><%=a.getEstado()%></td>
		</tr>

		<%
			}
		%>



	</table>

</body>
</html>