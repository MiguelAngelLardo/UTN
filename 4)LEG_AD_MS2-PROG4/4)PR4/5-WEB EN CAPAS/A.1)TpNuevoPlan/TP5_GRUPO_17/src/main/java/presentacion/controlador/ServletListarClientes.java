package presentacion.controlador;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


import entidad.Cliente;

import negocio.IClienteNegocio;
import negocioImpl.ClienteNegocioImpl;

import java.util.ArrayList;

@WebServlet("/ServletListarClientes")
public class ServletListarClientes extends HttpServlet {
	private static final long serialVersionUID = 1L;
  public ServletListarClientes() {super();}
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	  IClienteNegocio objNegocioCliente = new ClienteNegocioImpl();
	  
	  ArrayList<Cliente> colClientes = objNegocioCliente.listarClientes();
	  request.setAttribute("listaClientes", colClientes);
	  
    request.getRequestDispatcher("ListadoClientes.jsp").forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}
}
 