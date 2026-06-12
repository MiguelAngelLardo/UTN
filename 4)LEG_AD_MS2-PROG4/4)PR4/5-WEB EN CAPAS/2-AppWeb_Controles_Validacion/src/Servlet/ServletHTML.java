package Servlet;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet("/ServletHTML")
public class ServletHTML extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public ServletHTML() {
        super();
    }


	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//Validaciones
		if(request.getParameter("btnEnviarValidaciones")!=null)
		{
			String nombre = request.getParameter("txtNombre");
			String apellido = request.getParameter("txtApellido");
			String correo = request.getParameter("txtCorreo");
			String edad = request.getParameter("txtEdad"); 
		
			
			String resultado="";
			resultado+="Nombre: "+nombre+"<br>Apellido: "+apellido+ "<br>Correo: "+ correo+"<br>Edad: "+edad;
			request.setAttribute("ControlesSelecciones", resultado);			
			RequestDispatcher miDispacher = request.getRequestDispatcher("/Validaciones.jsp"); // Es el archivo JSP al que le vamos a enviar la informacion
			   miDispacher.forward(request, response);
		}
		if(request.getParameter("btnEnviarPropiedades")!=null)
		{
			String leer = request.getParameter("txtLeer");
			String caracter = request.getParameter("txtCaracter");
			String value = request.getParameter("txtValue");
			String marcaAgua = request.getParameter("txtMarcaAgua"); 
			String maximo = request.getParameter("txtMaximo");
			String minimo = request.getParameter("txtMinimo");
			String incremento = request.getParameter("txtIncremento");
			String area = request.getParameter("txtArea");
			String resultado= leer+" "+caracter+" "+value+" "+marcaAgua+" "+maximo+" "+minimo+" "+incremento+" "+area;
			request.setAttribute("ControlesSelecciones", resultado);			
			RequestDispatcher miDispacher = request.getRequestDispatcher("/Propiedades.jsp"); // Es el archivo JSP al que le vamos a enviar la informacion
			   miDispacher.forward(request, response);
		}
	}



	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	
		if(request.getParameter("btnEnviarControles")!=null)
		{
			eventobtnEnviarControles(request,response);
		}
	}
	
	
	public void eventobtnEnviarControles( HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	{
		String ColorSelec = request.getParameter("Color");
		String FechaSelec = request.getParameter("Fecha");
		String FechahoraSelec = request.getParameter("FechaHora");
		String FechahoraLocalSelec = request.getParameter("FechaHoraLocal"); 
		String ArchivoSelec = request.getParameter("File");	
		String EmailSelec = request.getParameter("Email");
		String MesSelec = request.getParameter("Mes");
		String NumeroSelec = request.getParameter("Numero");
		String RangoSelec = request.getParameter("Rango");
		String BusquedaSelec = request.getParameter("Busqueda");
		String TelSelec = request.getParameter("Telefono");
		String HoraSelec = request.getParameter("Hora");
		String UrlSelec = request.getParameter("Url");
		String SemanaSelec = request.getParameter("Semana");
		
		String resultado="";
		resultado+="Color: "+ColorSelec+"<br>Fecha: "+FechaSelec+ "<br>Fecha hora: "+ FechahoraSelec+"<br>Fecha hora local: "+FechahoraLocalSelec+ "<br>Archivo: "+ ArchivoSelec;
		resultado+="<br>Email: "+EmailSelec+"<br>Mes: "+MesSelec+"<br>Numero: "+NumeroSelec+"<br>Rango: "+RangoSelec+"<br>Busqueda: "+BusquedaSelec+" ";
		resultado+="<br>Telefono:"+TelSelec+ "<br>Hora: "+HoraSelec+"<br>Url: "+UrlSelec+ "<br>Semana: "+SemanaSelec;
		
		request.setAttribute("ControlesSelecciones", resultado);
		System.out.println("b");
		RequestDispatcher miDispacher = request.getRequestDispatcher("/Controles.jsp"); // Es el archivo JSP al que le vamos a enviar la informacion
		   miDispacher.forward(request, response);
		
	}
	
	
	

}
