package frgp.utn.edu.ar.Servlet;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.sun.javafx.scene.layout.region.Margins.Converter;


@WebServlet("/ServletEjercicio3")
public class ServletEjercicio3 extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public ServletEjercicio3() {
        super();
    }


	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		if(request.getParameter("btnAceptar")!=null)
		{
			
			Integer valor=0;
			if(request.getParameter("txtValor")!=null)
			{
				valor= Integer.parseInt(request.getParameter("txtValor"));
			}
			
		   //Para crear una variable de tipo application se utiliza getServletContext()
		   // SetAttribute crea la variable de tipo application con nombre Application_Ej3_2 
			getServletContext().setAttribute("Application_Ej3_2", valor);
		}
		
		RequestDispatcher miDispacher = request.getRequestDispatcher("/Ejercicio3B.jsp"); // Es el archivo JSP al que le vamos a enviar la informacion
	    miDispacher.forward(request, response);
	    
		// También se puede redirigir de la siguiente manera:
		//response.sendRedirect(request.getContextPath()+"/Ejercicio3B.jsp");
	}

	

}
