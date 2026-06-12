<%@page import="javax.websocket.Session"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

<!-- La variable session ya esta definida asi como el request
	 Mediante el getAttribute consulto por el valor de una variable session ya creada
 -->
	<% if(session.getAttribute("Session_Ej1")!=null )
		  { %>
			El valor guardado es: <%= session.getAttribute("Session_Ej1") %>
    	<%} 
		else
    	  { %>
    		No esta creada la variable session
    	 <%} 
     %>
</body>
</html>