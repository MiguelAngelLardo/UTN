<%@page import="entidad.*"%>
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
		List<Categoria> listaC = new ArrayList<Categoria>();
		if (request.getAttribute("listaCat") != null) {
			listaC = (List<Categoria>) request.getAttribute("listaCat");
		}
	%>

	<a href="Principal.jsp">Inicio</a>
	<a href="ServletArticulos?Param=previoInsert">Insertar articulos</a>
	<a href="ServletArticulos?Param=list">Listar articulos</a>

	<br />
	<br />

	<form method="post" action="ServletArticulos">

		<table>
			<tr>
				<td>Nombre:</td>
				<td><input type="text" name="txtNombre" /></td>
			</tr>
			<tr>
				<td>Precio:</td>
				<td><input type="text" name="txtPrecio" required /></td>
			</tr>
			<tr>
				<td>Categoria:</td>
				<td><select name=comboCat>
						<%
							for (Categoria c : listaC) {
						%>
						<option value="<%=c.getIdCategoria()%>"><%=c.getNombre()%></option>
						<%
							}
						%>
				</select></td>
			</tr>

			<tr>
				<td>Estado:</td>
				<td><select name="comboEstado">
						<option value="0">Activo</option>
						<option value="1">Desactivo</option>
				</select></td>
			</tr>

			<tr>
				<td></td>
				<td><input type="submit" name="btnAceptar" value="Aceptar">
				</td>
			</tr>
		</table>

	</form>

	<%
		if (request.getAttribute("estadoArticulo") != null) {
	%>
	Articulo agregado con exito
	<%
		}
	%>

</body>
</html>