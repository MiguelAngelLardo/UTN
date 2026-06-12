package frgp.utn.edu.ar.controller;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/servletPersonas")
public class servletPersonas extends HttpServlet {
	private static final long serialVersionUID = 1L;
       

    public servletPersonas() {
        super();
    }


	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

		if(request.getParameter("btnEliminar")!=null)
		{
			//Obtengo los datos del JSP PaginaInicio.jsp
			//Los datos viajan por get, a través de la funcion javascript onclick
			String nombre= request.getParameter("txtNombre");
			String apellido= request.getParameter("txtApellido");
			String dni= request.getParameter("txtDni");
			
			String mensaje_a_enviar="El usuario quiere eliminar: "+dni+" "+nombre+ " "+apellido;
			//Mensaje que se envia al JSP
			request.setAttribute("mensaje", mensaje_a_enviar);
			RequestDispatcher rd=request.getRequestDispatcher("PaginaInicio.jsp");  
			rd.forward(request, response);			
		}
	}


	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
