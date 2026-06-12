package servlets;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import dominio.Usuario;
import dominio.UsuarioDao;

/**
 * Servlet implementation class servletUsuario
 */
@WebServlet("/servletUsuario")
public class servletUsuario extends HttpServlet {
	private static final long serialVersionUID = 1L;
       


    public servletUsuario() {
        super();
        // TODO Auto-generated constructor stub
    }


	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	
		if(request.getParameter("btnEliminar2")!=null)
		{
			String aux = request.getParameter("idUsuario").toString();
			System.out.println(aux);
			int id = Integer.parseInt(request.getParameter("idUsuario").toString()) ;
			UsuarioDao udao = new UsuarioDao();
			udao.eliminarUsuario(id);
			
            ArrayList<Usuario> lista= udao.obtenerUsuarios();
			request.setAttribute("listaU", lista);
			
			RequestDispatcher rd = request.getRequestDispatcher("/Ejemplo3.jsp");   
	        rd.forward(request, response);
		}
		
		if(request.getParameter("Param")!=null)
		{
			//Entra por haber echo click en el hyperlink mostrar usuarios
			UsuarioDao udao = new UsuarioDao();
			ArrayList<Usuario> lista= udao.obtenerUsuarios();
			
			request.setAttribute("listaU", lista);
			
			RequestDispatcher rd = request.getRequestDispatcher("/Ejemplo3.jsp");   
	        rd.forward(request, response);
			
			
		}
		
		
		int filas=0;
		if(request.getParameter("btnAceptar")!=null)
		{
			Usuario u  =  new Usuario();
			u.setNombre(request.getParameter("txtNombre"));
			u.setApellido(request.getParameter("txtApellido"));
			
			UsuarioDao udao = new UsuarioDao();
			filas=udao.agregarUsuario(u);
			//REQUESTDISPATCHER
			request.setAttribute("cantFilas", filas);
			RequestDispatcher rd = request.getRequestDispatcher("/Ejemplo1.jsp");   
	        rd.forward(request, response);    
			
		}
		
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		if(request.getParameter("btnMostrarUsuarios")!=null)
		{
			UsuarioDao udao = new UsuarioDao();
			ArrayList<Usuario> lista= udao.obtenerUsuarios();
			
			request.setAttribute("listaU", lista);
			
			RequestDispatcher rd = request.getRequestDispatcher("/Ejemplo2.jsp");   
	        rd.forward(request, response);
		}
		if(request.getParameter("btnEliminar")!=null)
		{
			int id = Integer.parseInt(request.getParameter("idUsuario").toString()) ;
			UsuarioDao udao = new UsuarioDao();
			udao.eliminarUsuario(id);
			
            ArrayList<Usuario> lista= udao.obtenerUsuarios();
			request.setAttribute("listaU", lista);
			
			RequestDispatcher rd = request.getRequestDispatcher("/Ejemplo2.jsp");   
	        rd.forward(request, response);
			
		}
	
	}

}
