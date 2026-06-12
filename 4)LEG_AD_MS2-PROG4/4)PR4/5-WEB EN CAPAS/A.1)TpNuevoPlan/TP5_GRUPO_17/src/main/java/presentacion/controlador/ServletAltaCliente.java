package presentacion.controlador;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import entidad.Cliente;
import negocioImpl.ClienteNegocioImpl;

@WebServlet("/ServletAltaCliente")
public class ServletAltaCliente extends HttpServlet {
	private static final long serialVersionUID = 1L;
  public ServletAltaCliente() {super();}


	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	  request.setCharacterEncoding("UTF-8");
	  boolean hayError = false;
	  
	  String dni = request.getParameter("txtDni");
    String cuil = request.getParameter("txtCuil");
  
    String nombre = request.getParameter("txtNombre");
    String apellido = request.getParameter("txtApellido");
    
    String sexo = request.getParameter("ddlSexo");
    String nacionalidad = request.getParameter("txtNacionalidad");
    
    String fecha = request.getParameter("txtFecha");
    String direccion = request.getParameter("txtDireccion");
    
    String localidad = request.getParameter("txtLocalidad");
    String provincia = request.getParameter("txtProvincia");
    
    String email = request.getParameter("txtEmail");
    String telefono = request.getParameter("txtTelefono");
    
    //Envio de datos para que persistan en el HTML
    request.setAttribute("valorDni", dni);
    request.setAttribute("valorCuil", cuil);
    
    request.setAttribute("valorNombre", nombre);
    request.setAttribute("valorApellido", apellido);
    
    request.setAttribute("valorSexo", sexo);
    request.setAttribute("valorNacionalidad", nacionalidad);
    
    request.setAttribute("valorFecha", fecha);
    request.setAttribute("valorDireccion", direccion);
    
    request.setAttribute("valorLocalidad", localidad);
    request.setAttribute("valorProvincia", provincia);
    
    request.setAttribute("valorEmail", email);
    request.setAttribute("valorTelefono", telefono);
   
    
    if (dni.isEmpty() || cuil.isEmpty() || nombre.isEmpty() || apellido.isEmpty() ||  sexo.isEmpty() || nacionalidad.isEmpty() || fecha.isEmpty() || direccion.isEmpty() || localidad.isEmpty() || provincia.isEmpty() ||  email.isEmpty() || telefono.isEmpty()) {
      request.setAttribute("servErrorGeneral", "Debe ingresar todos los campos para poder continuar.");
      hayError = true; 
    }

    if (dni == null || !dni.matches("[1-9][0-9]{5,7}")) { request.setAttribute("servErrorDni", "El DNI debe tener entre 6 y 8 números."); hayError = true; }
    if (!cuil.matches("\\d{11}")) { request.setAttribute("servErrorCuil", "El CUIL debe tener 11 números."); hayError = true; }
    
    if (nombre == null || nombre.trim().isEmpty() || !nombre.matches("[A-Za-zÁ-ÿ\\s]+")) { request.setAttribute("servErrorNombre", "Solo letras y espacios."); hayError = true; }
    if (apellido == null || apellido.trim().isEmpty() || !apellido.matches("[A-Za-zÁ-ÿ\\s]+")) { request.setAttribute("servErrorApellido", "Solo letras y espacios."); hayError = true; }
    
    if (sexo == null || sexo.isEmpty()) { request.setAttribute("servErrorSexo", "Debe seleccionar un sexo."); hayError = true; }  
    if (nacionalidad == null || nacionalidad.isEmpty() || !nacionalidad.matches("[A-Za-zÁ-ÿ\\s]+")) { request.setAttribute("servErrorNacionalidad", "Debe ingresar la nacionalidad."); hayError = true; }
    
    if (fecha == null || fecha.isEmpty()) {
      request.setAttribute("servErrorFecha", "Debe ingresar una fecha.");
      hayError = true;
    } else {
      java.time.LocalDate fechaNac = java.time.LocalDate.parse(fecha);//parseo la fecha en tipo LocalDate. Lo que entra es un String Ej: "2026-05-09". Usa el formato ISO (AAAA-MM-DD) que es el que traer el HTML5
      if (fechaNac.isAfter(java.time.LocalDate.now())) { 
        request.setAttribute("servErrorFecha", "La fecha no puede ser futura."); 
        hayError = true; 
      }
	   }
    
    if (direccion == null || direccion.trim().isEmpty() || !direccion.matches("[A-Za-z0-9Á-ÿ\\s]+")) { request.setAttribute("servErrorDireccion", "Dirección inválida (sin símbolos *, !, %, etc)."); hayError = true; }

    if (localidad == null || localidad.trim().isEmpty() || !localidad.matches("[A-Za-zÁ-ÿ\\s]+")) { request.setAttribute("servErrorLocalidad", "Ingrese una localidad válida (solo letras)."); hayError = true; }
    if (provincia == null || provincia.trim().isEmpty() || !provincia.matches("[A-Za-zÁ-ÿ\\s]+")) { request.setAttribute("servErrorProvincia", "Ingrese una provincia válida (solo letras)."); hayError = true; }
    
    if (email == null || !email.matches("[a-zA-Z0-9ñ._-]+@[a-zA-Z0-9]+\\.[a-zA-Z]{2,4}(\\.[a-zA-Z]{2,3})?")) { request.setAttribute("servErrorEmail", "Ingrese un correo electrónico válido."); hayError = true; }
    if (telefono == null || !telefono.matches("\\d{10}")) { request.setAttribute("servErrorTelefono", "El teléfono debe tener 10 números."); hayError = true; }
    
 
   
    if (hayError) {
        request.getRequestDispatcher("AltaCliente.jsp").forward(request, response);
    } else {
      int resultadoAgregar = new ClienteNegocioImpl().altaCliente(new Cliente(0, dni, cuil, nombre, apellido, sexo, fecha, direccion, nacionalidad, localidad, provincia, email, telefono));
      
      //siwtch para escalar
      switch (resultadoAgregar)
      {
      case 1: response.sendRedirect("ServletListarClientes?exito=1"); break; // ok
        
      case 2: // DNI o CUIL Duplicado 
        request.setAttribute("servErrorGeneral", "El DNI o CUIL ya se encuentran registrados en el sistema.");
        request.getRequestDispatcher("AltaCliente.jsp").forward(request, response);
        break;
          
      case 3: // Error de Base de datos / SQL Exception
        request.setAttribute("servErrorGeneral", "Hubo un problema al conectar con la base de datos. Intente más tarde.");
        request.getRequestDispatcher("AltaCliente.jsp").forward(request, response);
        break;
          
      default: // un caso base por defecto
        request.setAttribute("servErrorGeneral", "Ocurrió un error inesperado.");
        request.getRequestDispatcher("AltaCliente.jsp").forward(request, response);
        break;
      }//switch
    }//if
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}

/*Cliente nuevoCliente = new Cliente(0, dni, cuil, nombre, apellido, sexo, fecha, direccion, nacionalidad, localidad, provincia, email, telefono);
IClienteNegocio neg = new ClienteNegocioImpl();
boolean agregadoExitoso = neg.altaCliente(nuevoCliente);*/


