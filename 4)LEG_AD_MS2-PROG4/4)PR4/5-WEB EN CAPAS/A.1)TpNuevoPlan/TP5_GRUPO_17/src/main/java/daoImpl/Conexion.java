package daoImpl;

import java.sql.Connection;
import java.sql.DriverManager;

public class Conexion {

  private String host = "jdbc:mysql://localhost:3306/";
  private String user = "root";
  private String pass = "root";
  private String dbName = "sistema_clientes?useSSL=false";
	
	// Método para obtener la conexión
  public Connection obtenerConexion() {
    Connection cn = null;
    try {
      Class.forName("com.mysql.jdbc.Driver");//(despertarJar)
      cn = DriverManager.getConnection(host + dbName, user, pass); //entregamos el usuario y la ruta al cn
    } catch (Exception e) {
      e.printStackTrace();
    }
      return cn; //devolvemos la coneccion
  }
	
}
