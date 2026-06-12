<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

<form method="post" action="Ejemplo2.jsp">
	Ingrese su nombre: <input type="text" name="txtNombre" />
	<input type="submit" name="btnSaludar" value="Saludar" />
	<input type="submit" name="btnDespedir" value="Despedir" />
</form>

<%
    String texto="";
    if(request.getParameter("btnDespedir")!= null)
    {
    	//Se hizo click sobre el botón despedir
    	texto = "Adios "+ request.getParameter("txtNombre");
    }
    if(request.getParameter("btnSaludar")!=null)
    {
    	//Se hizo click sobre el boton saludar
    	texto= "Hola "+ request.getParameter("txtNombre");
    }
%>

<%=texto%>


<!-- Otra alternativa -->
<br><br>

<% if(request.getParameter("btnDespedir")!=null) 
	{
	%>
	 <b> Adios <%=request.getParameter("txtNombre")%> </b>
	
	<%
	}
%>



</body>
</html>