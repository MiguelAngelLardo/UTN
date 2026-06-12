<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>


<%@ page import="java.util.ArrayList" %>
<%@ page import="entidad.Cliente" %>

<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
<title>TP5_GRUPO_17</title>
<link rel="stylesheet" type="text/css" href="https://cdn.datatables.net/1.10.19/css/jquery.dataTables.css">

<script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.4/jquery.min.js"></script>
<script type="text/javascript" charset="utf8" src="https://cdn.datatables.net/1.10.19/js/jquery.dataTables.js"></script>

<script type="text/javascript"> <%--JS puro es => document.getElementById('tablaClientes') . JQuery es mas simple =>  $('#tablaClientes'). --%>
    $(document).ready(function () { <%---Fx de JQuery => "espera q se cargue todo el HTML antes de hacer algo"... Usa Fx anonima como argumento--%>
        $('#tablaClientes').DataTable({ <%-- El # es para el selector ID => .DataTable llama a la libreria de la liea 10--%>
        	"pageLength": 5, // Fuerza a que muestre 5 registros al principio
        	"lengthMenu": [[5, 10, 25, 50, -1], [5, 10, 25, 50, "Todos"]], // Opciones del selector
        	"language": {"url": "https://cdn.datatables.net/plug-ins/1.10.19/i18n/Spanish.json"}
        });	
    });
</script>


	<style type="text/css">
    <jsp:include page="css/StyleSheet.css" />
  </style>
</head>
<body>

	<div class="caja-ppal"> <%-- Bloque Layout --%>
    <aside class="sidebar"> <%-- Bloque Componente independiente --%>
      <h2 class="sidebar__title">Menú</h2> <%-- Elemento --%>
      <nav class="sidebar__nav">
         <a href="AltaCliente.jsp" class="sidebar__link">Alta de Cliente</a><%-- modificador --%>
         <a href="ServletListarClientes" class="sidebar__link sidebar__link--active">Listado de Clientes</a>
      </nav>
    </aside>
    
    <main class="caja-contenido">
    	<header class="header">
        <h1>Formulario de Cliente</h1>
      	<p>Usuario: <strong>${usuarioLogueado.nombreUsuario}</strong></p>
      </header>
      
      <div class="form">
        <h3>Listado de Clientes (${listaClientes.size()})</h3>
        <table id="tablaClientes" class="display">
			  	<thead>
			      <tr><th>DNI</th><th>CUIL</th><th>Nombre y Apellido</th><th>Sexo</th><th>Fecha de Nacimiento</th><th>Dirección</th><th>Nacionalidad</th><th>Localidad</th><th>Provincia</th></tr>
			  	</thead>
			  	
			  	<tbody>
			  	 <% 
			   	  ArrayList<Cliente> lista = (ArrayList<Cliente>) request.getAttribute("listaClientes");
			      
			   	  if (lista != null && !lista.isEmpty()) { // Si la lista existe y tiene datos
			        for (Cliente cliente : lista) {      // Empezamos a recorrer
			      %>
			        <tr> 
			          <td><%= cliente.getDni() %></td> 
		              <td><%= cliente.getCuil() %></td>  	
		              <td><%= cliente.getNombre() + " " + cliente.getApellido() %></td> 
		              <td><%= cliente.getSexo() %></td>
		              <td><%= cliente.getFechaNacimiento() %></td> 
		              <td><%= cliente.getDireccion() %></td>
		              <td><%= cliente.getNacionalidad() %></td>
		              <td><%= cliente.getLocalidad() %></td> 
		              <td><%= cliente.getProvincia() %></td>
			        </tr>
			      <% 
			        } // FOR
			      } // IF
			      else { // lista NULL
			      %> 
			        <tr>
			          <td colspan="9" style="text-align:center;">No se encontraron clientes para mostrar.</td>
			        </tr>
			      <% 
			      } // ELSE
			      %>
			  	</tbody>
			  </table>
      </div>
    </main> 		
  </div> <%-- Bloque Layout --%>

</body>
</html>