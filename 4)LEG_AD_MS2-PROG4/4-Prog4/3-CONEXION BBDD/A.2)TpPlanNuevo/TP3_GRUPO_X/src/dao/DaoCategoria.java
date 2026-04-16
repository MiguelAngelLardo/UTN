package dao;

//conexion
import java.sql.DriverManager;//es el que le pasa a Connection al string
import java.sql.Connection;// usa el Statement que es un camion con la ruta del Connection => ese st devuelve int si es ABM o en L un ResulSet "cajas para el remolque"
import java.sql.Statement;//Statment es para ABML
                          //PreparedStatement es para buscar por id
													//Callable Statement es para SP
//para listar
import java.sql.ResultSet;
import java.util.ArrayList; 

import entidad.Categoria;

public class DaoCategoria {
	private String host = "jdbc:mysql://localhost:3306/";
	private String user = "root";
	private String pass = "root";
	private String dbName = "bdInventario?useSSL=false"; //sin el ss=false da error 
	//Modernamente, Java bloquea protocolos de seguridad (SSL/TLS) viejos por considerarlos inseguros.
	//Tu driver de MySQL está intentando usar uno de esos protocolos viejos para encriptar la conexión, Java le dice 
	//"No, eso es inseguro", y como no se ponen de acuerdo (el famoso SSLHandshakeException), la conexión se corta.
	//El símbolo ? le dice a la conexión "Acá empiezan mis configuraciones extra", y el useSSL=false apaga la encriptación problemática.
	
	public DaoCategoria() {}
	
	public int agregarCategoria(Categoria categoria) {
		String query = "Insert into Categorias(IdCategoria,Nombre) values ('"+categoria.getIdCategoria()+"','"+categoria.getNombre()+"')";//sintaxis de bbdd
		Connection cn = null; //usa import java.sql.Connection;
		int filas=0;
		try
		{
			cn = DriverManager.getConnection(host+dbName,user,pass); //DriverManager viene de import java.sql.DriverManager; - host+bdName es para la bbdd especifica
		  //el DriveManager es el manejador de choferes => es el que lee "mysql" y sabe que tiene q ir a la ciudad MySQL => luego va al contratista .jar que agregamos
			//llama al driver de MySQL y le da las credenciales root, root, le dael puerto, valida la pass y arma la autopista que se la devuelve a cn
			//si uso oracle deberia tener jdbc::oracle y agregar su dirver , luego el driver manager hace el resto
			
			Statement st = cn.createStatement();//hacela consulta - Connection tiene un metodo llamado createStatement() 
		  //Statement st = new Statement() no puedo hacerlo por q el camion nace CIEGO, no sabe a que bbdd ir, ni que user, ni que puerto.  - la Connection ya tiene dentro esos dtos
		  
		  filas = st.executeUpdate(query);//executeUpdate hace insert, update o delete => devuelve int con cant de filas afectadas - hace la consulta y la ejecuta
		  
		  //si Connection cn es la ruta que una java con MySwlel Statement es el camion la cual carga la consulta y se la da a MySql para q ejecute
		}
		catch(Exception e) 
		{
			e.printStackTrace();//muestra error por consola
		}
		return filas;		
		
	}
	
	//listar
	public ArrayList<Categoria> listarCategoria() {
		ArrayList<Categoria> listCategorias = new ArrayList<Categoria>();		
		String query = "SELECT * FROM Categorias";
		Connection cn = null;
		
		try {
			cn = DriverManager.getConnection(host+dbName, user, pass); 
			Statement st = cn.createStatement();			
			ResultSet rs = st.executeQuery(query);//Si el Statement era el camión, el ResultSet es el remolque lleno de cajas
			
			while(rs.next()) {
				Categoria cat = new Categoria();
				
				cat.setIdCategoria(rs.getInt("IdCategoria")); //columna de bbdd
				cat.setNombre(rs.getString("Nombre")); //columna de bbDD
				
				listCategorias.add(cat);
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		} 
		
		return listCategorias;
	}
	
	
  //Baja (Física)
	public int eliminarCategoria(int idCategoria) {
		String query = "DELETE FROM Categorias WHERE IdCategoria = " + idCategoria;	// La consulta SQL con la condición WHERE (¡súper importante para no borrar toda la tabla!)	
		Connection cn = null;
		int filas = 0;
		
		try {
			cn = DriverManager.getConnection(host+dbName, user, pass); 
			Statement st = cn.createStatement();
			filas = st.executeUpdate(query);// Mandamos el camión con el DELETE. Nos devuelve 1 si borró, o 0 si no encontró el ID.


		} catch(Exception e) {
			e.printStackTrace();
		} 
		
		return filas;
	}
	
	
	//Modificación (Update)
	public int modificarCategoria(Categoria categoria) {
		String query = "UPDATE Categorias SET Nombre = '" + categoria.getNombre() + "' WHERE IdCategoria = " + categoria.getIdCategoria();
		Connection cn = null;
		int filas = 0;
		try {
			cn = DriverManager.getConnection(host+dbName, user, pass); 
			Statement st = cn.createStatement();
			filas = st.executeUpdate(query);// Mandamos el camión. Devuelve 1 si encontró el ID y lo modificó.

		} catch(Exception e) {
			e.printStackTrace();
		} 
		
		return filas;
	}
	
	
	
	
	
	
	
	

	
}
