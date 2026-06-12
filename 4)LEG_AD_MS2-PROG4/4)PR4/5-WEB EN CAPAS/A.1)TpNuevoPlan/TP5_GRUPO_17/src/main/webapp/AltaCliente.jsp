<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>TP5_GRUPO_17</title>
	<style type="text/css">
    <jsp:include page="css/StyleSheet.css" />
  </style>
</head>
<body>

	<div class="caja-ppal"> <%-- Bloque Layout --%>
    <aside class="sidebar"> <%-- Bloque Componente independiente --%>
       <h2 class="sidebar__title">Menú</h2> <%-- Elemento --%>
       <nav class="sidebar__nav">
         <a href="AltaCliente.jsp" class="sidebar__link sidebar__link--active">Alta de Cliente</a><%-- modificador --%>
         <a href="ServletListarClientes?irAListar=1" class="sidebar__link">Listado de Clientes</a>
       </nav>
    </aside>

    <main class="caja-contenido">
      <header class="header">
        <h1>Formulario de Cliente</h1>
      	<p>Usuario: <strong>${usuarioLogueado.nombreUsuario}</strong></p>
      </header>
        
      <form action="ServletAltaCliente" method="post" class="form" novalidate> <%--novalidate es para que no aparezcan los carteles naranjas feos --%>
        
        <div class="form__fila"><%-- Fila 1 --%>
        	<div class="form__columna">
            <label class="form__cout" for="txtDni">DNI *</label> 
            <input class="form__cin" type="text" id="txtDni" name="txtDni" value="${valorDni}">
						<span class="form__validar ${servErrorDni != null ? 'form__validar--error' : ''}"> ${ servErrorDni != null ? servErrorDni  : 'Solo números. 6 a 8 dígitos (ej: 1234567888).'} </span>     	
						<%--con el ternario dejo 1 o 2 clases => class="form__validar form__validar--error" --%>
						<%--para empezar muestroleyenda gris y si no lo cambio por el string del servlet " --%>
           </div>
        	
          <div class="form__columna">
            <label class="form__cout" for="txtCuil">CUIL *</label>
            <input class="form__cin" type="text" id="txtCuil" name="txtCuil" value="${valorCuil}">
            <span class="form__validar ${servErrorCuil != null ? 'form__validar--error' : ''}"> ${ servErrorCuil != null ? servErrorCuil : 'Formato: 11 dígitos(ej: 20333444555).'} </span>     	
          </div>
        </div><%-- Fila 1 --%>
				
			  <div class="form__fila"><%-- Fila 2 --%>
          <div class="form__columna">
            <label class="form__cout" for="txtNombre">Nombre *</label>
            <input class="form__cin" type="text" id="txtNombre" name="txtNombre" value="${valorNombre}">
            <span class="form__validar ${servErrorNombre != null ? 'form__validar--error' : ''}"> ${ servErrorNombre != null ? servErrorNombre : '*Segmento Requerido.'} </span>     	
          </div>

          <div class="form__columna">
            <label class="form__form__cout" for="txtApellido">Apellido *</label> 
            <input class="form__cin" type="text" id="txtApellido" name="txtApellido" value="${valorApellido}">
            <span class="form__validar ${servErrorApellido != null ? 'form__validar--error' : ''}"> ${ servErrorApellido != null ? servErrorApellido : '*Segmento Requerido.'} </span>     	
          </div>
        </div><%-- Fila 2 --%>
        
        <div class="form__fila"><%-- Fila 3 --%>
    			<div class="form__columna">
        		<label class="form__cout" for="ddlSexo">Sexo *</label>
        		<select class="form__cin" id="ddlSexo" name="ddlSexo">
            	<option value="">-- Seleccione --</option>
            		<option value="M" ${valorSexo == 'M' ? 'selected' : ''}>Masculino</option>
            		<option value="F" ${valorSexo == 'F' ? 'selected' : ''}>Femenino</option>
            		<option value="O" ${valorSexo == 'O' ? 'selected' : ''}>Otro</option>
        		</select>
            <span class="form__validar ${servErrorSexo != null ? 'form__validar--error' : ''}"> ${servErrorSexo != null ? servErrorSexo : '*Segmento Requerido.'} </span>
          </div>

		   	  <div class="form__columna">
            <label class="form__cout" for="txtNacionalidad">Nacionalidad</label>
            <input class="form__cin" type="text" id="txtNacionalidad" name="txtNacionalidad" value="${valorNacionalidad}">
            <span class="form__validar ${servErrorNacionalidad != null ? 'form__validar--error' : ''}"> ${servErrorNacionalidad != null ? servErrorNacionalidad : 'Solo Letras'} </span>
          </div>
			  </div><%-- Fila 3 --%>
					
		    <div class="form__fila"><%-- Fila 4 --%>
    			<div class="form__columna">
        		<label class="form__cout" for="txtFecha">Fecha de nacimiento *</label>
        		<input class="form__cin" type="date" id="txtFecha" name="txtFecha" value="${valorFecha}">
        		<span class="form__validar ${servErrorFecha != null ? 'form__validar--error' : ''}"> ${servErrorFecha != null ? servErrorFecha : 'Seleccione una fecha (No futura).'} </span>
  	  		</div>
	
    	    <div class="form__columna">
        		<label class="form__cout" for="txtDireccion">Dirección *</label>
        		<input class="form__cin" type="text" id="txtDireccion" name="txtDireccion" value="${valorDireccion}">
            <span class="form__validar ${servErrorDireccion != null ? 'form__validar--error' : ''}"> ${servErrorDireccion != null ? servErrorDireccion : 'Solo letras y números.'} </span>
    			</div>
				</div><%-- Fila 4 --%>
				
				<div class="form__fila"><%-- Fila 5 --%>
    			<div class="form__columna">
        		<label class="form__cout" for="txtLocalidad">Localidad *</label>
        		<input class="form__cin" type="text" id="txtLocalidad" name="txtLocalidad" value="${valorLocalidad}">
        		<span class="form__validar ${servErrorLocalidad != null ? 'form__validar--error' : ''}"> ${servErrorLocalidad != null ? servErrorLocalidad : 'Solo letras.'} </span>
    			</div>

    			<div class="form__columna">
        		<label class="form__cout" for="txtProvincia">Provincia *</label>
        		<input class="form__cin" type="text" id="txtProvincia" name="txtProvincia" value="${valorProvincia}">
        		<span class="form__validar ${servErrorProvincia != null ? 'form__validar--error' : ''}"> ${servErrorProvincia != null ? servErrorProvincia : 'Solo letras.'} </span>
    		  </div>
				</div><%-- Fila 5 --%>
				
				<div class="form__fila"><%-- Fila 6 --%>
    			<div class="form__columna">
        		<label class="form__cout" for="txtEmail">Correo electrónico *</label>
        		<input class="form__cin" type="text" id="txtEmail" name="txtEmail" value="${valorEmail}">
        		<span class="form__validar ${servErrorEmail != null ? 'form__validar--error' : ''}"> ${servErrorEmail != null ? servErrorEmail : 'Formato válido (ejemplo@mail.com).'} </span>
    		  </div>

    	    <div class="form__columna">
        		<label class="form__cout" for="txtTelefono">Teléfono *</label>
        		<input class="form__cin" type="text" id="txtTelefono" name="txtTelefono" value="${valorTelefono}">
        		<span class="form__validar ${servErrorTelefono != null ? 'form__validar--error' : ''}">  ${servErrorTelefono != null ? servErrorTelefono : '10 dígitos sin espacios.'} </span>
      		</div>
    	  </div><%-- Fila 6 --%>
			
			
 				<% if(request.getAttribute("servErrorGeneral") != null) { %> 
 				  <div style="color: #b91c1c; font-weight: bold; margin-bottom: 15px;"> ${servErrorGeneral} </div> 
 				<% } %>	
 				
        <button type="submit" name="btnGuardar" class="btn-guardar">Guardar cliente</button>
      </form>
    </main>    
	</div> <%-- Bloque Layout --%>
</body>
</html>