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
	String valorSelect="";
	String valorRadio="";
	String valorChk1="";
	String valorChk2="";


  if(request.getParameter("btnAceptar")!=null)
  {
	  
	  valorSelect = request.getParameter("pais");
	  valorRadio= request.getParameter("tecnologias");
	  valorChk1 = request.getParameter("chk1");
	  valorChk2 = request.getParameter("chk2");	  
  }
%>

<h1>Elementos seleccionados:</h1>

Descolgable:
<%=valorSelect %>
<br>
RadioButton:
<%=valorRadio %>
<br>
Checkbox:
<%=valorChk1%>  <%=valorChk2 %>





</body>
</html>