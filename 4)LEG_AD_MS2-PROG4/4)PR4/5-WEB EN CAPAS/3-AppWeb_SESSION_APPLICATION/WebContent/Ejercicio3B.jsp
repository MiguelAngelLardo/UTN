<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

<% if(application.getAttribute("Application_Ej3_1")!=null){ %>
Valor de la variable application creada en el JSP: <%= application.getAttribute("Application_Ej3_1") %>
<%} %>
<br>
<% if(application.getAttribute("Application_Ej3_2")!=null){ %>
Valor de la variable application creada en el SERVLET: <%= application.getAttribute("Application_Ej3_2") %>
<%} %>


</body>
</html>