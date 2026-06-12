package dao;

//conexion
import java.sql.DriverManager;//(El Gerente de Logística): Es el jefe de tránsito en Java. Vos le das la dirección a la que querés ir (el String con la URL jdbc:mysql...
import java.sql.Connection;// (La Ruta / Autopista): Es el resultado del trabajo del Driver. Es el asfalto puro que une tu programa en Java con la base de datos MySQ
import java.sql.Statement;//=> (El Camión): ¡Este es el vehículo! La ruta (Connection) por sí sola no hace nada,
                          // int => filas = st.executeUpdate(query);
													//ResulSet es el remolque con muchas cajas => LISTAR => ResultSet rs = st.executeQuery(query)
                          //PreparedStatement es para buscar por id
													//Callable Statement es para SP
//para listar
import java.sql.ResultSet;
import java.util.ArrayList; 

import entidad.Categoria;


/*
import java.sql.DriverManager; // El Gerente que busca al contratista (Driver) para armar la ruta.
import java.sql.Connection;    // La RUTA terminada de asfalto que une Java con MySQL.
import java.sql.Statement;     // El CAMIÓN que viaja por la ruta llevando tu consulta SQL (INSERT, UPDATE, DELETE).
import java.sql.ResultSet;     // El REMOLQUE con cajas que vuelve por la ruta (solo cuando el camión lleva un SELECT).
 * */

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
		int filas=0;
		
	  // TRY-WITH-RESOURCES: Declaramos la "ruta" y el "camión" acá adentro
		try (Connection cn = DriverManager.getConnection(host+dbName,user,pass);//DriverManager viene de import java.sql.DriverManager; - host+bdName es para la bbdd especifica
		  //el DriveManager es el manejador de choferes => es el que lee "mysql" y sabe que tiene q ir a la ciudad MySQL => luego va al contratista .jar que agregamos
			//llama al driver de MySQL y le da las credenciales root, root, le dael puerto, valida la pass y arma la autopista que se la devuelve a cn
			//si uso oracle deberia tener jdbc::oracle y agregar su dirver , luego el driver manager hace el resto
			
			Statement st = cn.createStatement()){//hacela consulta - Connection tiene un metodo llamado createStatement() 
		  //Statement st = new Statement() no puedo hacerlo por q el camion nace CIEGO, no sabe a que bbdd ir, ni que user, ni que puerto.  - la Connection ya tiene dentro esos dtos
		  
		  filas = st.executeUpdate(query);//executeUpdate hace insert, update o delete => devuelve int con cant de filas afectadas - hace la consulta y la ejecuta
		  
		  //si Connection cn es la ruta que una java con MySwlel Statement es el camion la cual carga la consulta y se la da a MySql para q ejecute
		}	catch(Exception e) {
			e.printStackTrace();//muestra error por consola
		}
		return filas;		
		
	}
	
	
	/*Try whit sources
	La definición técnica en Java:
	Cuando los creadores de Java inventaron esta sintaxis en la versión 7 (año 2011), 
	decidieron ponerle Try-with-Resources ("Intentar con Recursos") porque crearon una regla estricta:
	
	En Java, se considera un "Resource" (Recurso) única y exclusivamente a cualquier objeto que implemente la interfaz AutoCloseable. Si volvemos a nuestra analogía de la logística: un "Recurso" es como alquilar herramientas de trabajo. Alquilaste el asfalto privado (Connection), alquilaste el camión (Statement) y alquilaste el acoplado (ResultSet). El try-with-resources es simplemente el contrato que dice: "Yo los uso en esta obra, y apenas termino, la empresa de alquiler pasa a retirarlos automáticamente sin que yo los tenga que llamar".
	*/
	
		
  //listar
	public ArrayList<Categoria> listarCategoria() {
		ArrayList<Categoria> listCategorias = new ArrayList<Categoria>();		
		String query = "SELECT * FROM Categorias";
		
		// TRY-WITH-RESOURCES: Instanciamos todo lo que se tiene que cerrar acá adentro.
		try (Connection cn = DriverManager.getConnection(host+dbName, user, pass); 
			 Statement st = cn.createStatement();			
			 ResultSet rs = st.executeQuery(query)) { //Si el Statement era el camión, el ResultSet es el remolque lleno de cajas
			
			while(rs.next()) {
				Categoria cat = new Categoria();
				
				cat.setIdCategoria(rs.getInt("IdCategoria")); //columna de bbdd
				cat.setNombre(rs.getString("Nombre")); //columna de bbDD
				
				listCategorias.add(cat);
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		} 
		
		// Cuando llega acá, Java ya cerró automáticamente el rs, el st y la cn.
		return listCategorias;
	}
	
	
 	
	public int eliminarCategoria(int idCategoria) {
		String query = "DELETE FROM Categorias WHERE IdCategoria = " + idCategoria;	// La consulta SQL con la condición WHERE (¡súper importante para no borrar toda la tabla!)	
		int filas = 0; // La declaramos afuera para que no muera al terminar el try
		
		// TRY-WITH-RESOURCES: Declaramos e instanciamos la ruta (cn) y el camión (st) acá adentro
		try (Connection cn = DriverManager.getConnection(host+dbName, user, pass); 
			 Statement st = cn.createStatement()) {
			
			filas = st.executeUpdate(query); // Mandamos el camión con el DELETE. Nos devuelve 1 si borró, o 0 si no encontró el ID.

		} catch(Exception e) {
			e.printStackTrace();
		} 
		// Al llegar a esta llave, Java apaga el camión (st.close) y levanta la ruta (cn.close) automáticamente.
		
		return filas;
	}
	
  //Modificación (Update)
	public int modificarCategoria(Categoria categoria) {
		String query = "UPDATE Categorias SET Nombre = '" + categoria.getNombre() + "' WHERE IdCategoria = " + categoria.getIdCategoria();
		int filas = 0; // La declaramos afuera para que sobreviva al bloque try
		
		// TRY-WITH-RESOURCES: Declaramos e instanciamos la ruta (cn) y el camión (st) acá adentro
		try (Connection cn = DriverManager.getConnection(host+dbName, user, pass); 
			 Statement st = cn.createStatement()) {
			
			filas = st.executeUpdate(query); // Mandamos el camión. Devuelve 1 si encontró el ID y lo modificó.

		} catch(Exception e) {
			e.printStackTrace();
		} 
		// Al llegar a esta llave de cierre, Java apaga el camión (st.close) y levanta la ruta (cn.close) automáticamente.
		
		return filas;
	}
	
	
	
	
	
	
	

	
}
