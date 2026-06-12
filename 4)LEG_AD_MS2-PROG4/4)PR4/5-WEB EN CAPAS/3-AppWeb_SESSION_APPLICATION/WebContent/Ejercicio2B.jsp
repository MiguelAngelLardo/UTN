<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

	<% if(session.getAttribute("Session_Ej2")!= null){ %>
		La variable session creada desde el servlet es: <%= session.getAttribute("Session_Ej2") %>
	<%} 
	else
	{ %>
		No se ha creado ninguna variable session llamada Session_Ej2
	<%} %>
</body>
</html>