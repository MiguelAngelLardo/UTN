<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

<h1> Bienvenidos </h1>

<!-- A continuación, haremos una declaración  -->
<%! String nombre="Pepe"; %>
<%! Integer edad=50; %>


<!-- A continuación, haremos un scriptlet  -->
<% nombre="Jose"; edad=20; %>

<!-- A continuación, haremos una expresion  -->
<b><%=nombre%></b>   </br>
<%=edad%>


</body>
</html>