package frgp.utn.edu.ar.Servlet;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;


@WebServlet("/ServletEjercicio2")

public class ServletEjercicio2 extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	
    public ServletEjercicio2() {
        super();
    }


	protected void doGet(HttpServletRequest request, HttpServletResponse response)     throws ServletException, IOException {
		
		if(request.getParameter("btnAceptar")!=null)
		{
			//En htttpSession obtengo todas las variables session creadas
			HttpSession session = request.getSession();
			
			String valor="";
			if(request.getParameter("txtValor")!=null)
			{
				valor=request.getParameter("txtValor");
			}
			
			//Mediate el setAttribute creo la variable session
			session.setAttribute("Session_Ej2", valor);
			//Redirijo a otro jsp
			
			RequestDispatcher miDispacher = request.getRequestDispatcher("/Ejercicio2B.jsp"); // Es el archivo JSP al que le vamos a enviar la informacion
		    miDispacher.forward(request, response);
		}
	}

	

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
	}

}
