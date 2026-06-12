package presentacion.controller;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import entidad.Articulo;
import entidad.Categoria;
import negocio.ArticuloNeg;
import negocio.CategoriaNeg;
import negocioImpl.ArticuloNegImpl;
import negocioImpl.CategoriaNegImpl;


@WebServlet("/ServletArticulos")
public class ServletArticulos extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	CategoriaNeg negCat = new CategoriaNegImpl();
	ArticuloNeg negArt = new ArticuloNegImpl();
	
	
    public ServletArticulos() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

		if(request.getParameter("Param")!=null)
		{
			String opcion = request.getParameter("Param").toString();
			
			switch (opcion) {
			case "previoInsert":
			{
				//Se quiere insertar entonces cargo la lista de categorias
				request.setAttribute("listaCat", negCat.obtenerTodos());
				RequestDispatcher dispatcher = request.getRequestDispatcher("/InsertarArticulos.jsp");
				dispatcher.forward(request, response);
				break;
			}
			case "list":
			{
				request.setAttribute("listaArt", negArt.listarArticulos());	
				RequestDispatcher dispatcher = request.getRequestDispatcher("/ListarArticulos.jsp");
				dispatcher.forward(request, response);
				break;
			}
			default:
				break;
			}
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	    if(request.getParameter("btnAceptar")!=null)
	    {
	    	Articulo x = new Articulo();
	    	x.setNombre(request.getParameter("txtNombre"));
	    	x.setPrecio(Float.parseFloat(request.getParameter("txtPrecio")));
	    	x.setEstado(Integer.parseInt(request.getParameter("comboEstado")));
	    	x.setCategoria(new Categoria(Integer.parseInt(request.getParameter("comboCat"))));
	    	boolean estado=true;
	    	estado = negArt.insertar(x);
	    	
	    	request.setAttribute("listaCat", negCat.obtenerTodos());
	    	request.setAttribute("estadoArticulo", estado);
	    	RequestDispatcher dispatcher = request.getRequestDispatcher("/InsertarArticulos.jsp");
			dispatcher.forward(request, response);
	    }
	
	}

}
