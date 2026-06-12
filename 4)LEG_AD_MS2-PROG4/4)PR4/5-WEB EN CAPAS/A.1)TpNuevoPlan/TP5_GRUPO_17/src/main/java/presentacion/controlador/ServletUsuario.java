package presentacion.controlador;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import entidad.Usuario;
import negocio.IUsuarioNegocio;
import negocioImpl.UsuarioNegocioImpl;

import javax.servlet.http.HttpSession;//para hacer objetos de session

@WebServlet("/servletUsuario")
public class ServletUsuario extends HttpServlet {
	private static final long serialVersionUID = 1L;
  public ServletUsuario() {super();}


	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	  if(request.getParameter("btnIngresar") != null) {
      String user = request.getParameter("txtUsuario");
      String pass = request.getParameter("txtPassword");

      if (user == null || user.trim().isEmpty() || pass == null || pass.trim().isEmpty()) {
        request.setAttribute("msjError", "Por favor, complete todos los campos.");
        request.getRequestDispatcher("Login.jsp").forward(request, response);
        return; //Antes de ir a negocio valido lo que es del front
      }
      
      //si escribio vengo aca
      IUsuarioNegocio negocio = new UsuarioNegocioImpl();//capa negocio => Interfaz + Impl
      Usuario usuario = negocio.login(user, pass); //cargo el usuario si los datos son correctos
      
      if (usuario != null) {
        HttpSession variableSession = request.getSession();
        variableSession.setAttribute("usuarioLogueado", usuario);//lo pide la consigna
        response.sendRedirect("AltaCliente.jsp");//si todo esta OK me voy al otro jsp
      } else {//si no hay usuario registrado con esos valores
        request.setAttribute("msjError", "Usuario o contraseña incorrectos");
        request.getRequestDispatcher("Login.jsp").forward(request, response);//me voy al Login
      }
    }//btnIngresar
	}//goGet

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
