<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

	<form action="Ejemplo4b.jsp" method="get">

		<b>Seleccione un pais:</b> 
		
					<select name="pais">
						<option value="1">México</option>
						<option value="2">Colombia</option>
						<option value="3">Chile</option>
						<option value="4">Perú</option>
						<option value="5">Argentina</option>
						<option value="6">España</option>
					</select> 
		
		<br />
		<br /> 
		
	<b> Seleccione un idioma: </b>
		
		Java        <input type="radio" name="tecnologias" value="Java">
		PHP         <input type="radio" name="tecnologias" value="PHP">
		JavaScript  <input type="radio" name="tecnologias" value="JavaScript">

		<br />
		<br />
		
	<b>	Seleccion experiencia: </b> 
	 
		
		Programador     <input type="checkbox" name="chk1" value="Programador" > 
		Soporte Técnico <input type="checkbox" name="chk2" value="Soporte Tecnico">

		<input type="submit" value="Aceptar" name="btnAceptar">
	</form>

</body>
</html>