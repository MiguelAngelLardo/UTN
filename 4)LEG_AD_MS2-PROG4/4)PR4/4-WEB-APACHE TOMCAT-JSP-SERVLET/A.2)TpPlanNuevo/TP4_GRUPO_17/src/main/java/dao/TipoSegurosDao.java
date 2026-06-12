package dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

//para listar
import java.sql.ResultSet;
import java.util.ArrayList;

import dominio.TipoSeguro;

public class TipoSegurosDao {
	private String host = "jdbc:mysql://localhost:3306/";
	private String user = "root";
	private String pass = "root";
	private String dbName = "SegurosGroup?useSSL=false"; 
	
	public TipoSegurosDao() {}
	
	private void despertarJar() {
		try {
			Class.forName("com.mysql.jdbc.Driver");
    } catch (ClassNotFoundException e) {
    	System.out.println("ERROR: No se encontró el Driver en WEB-INF/lib");
    	e.printStackTrace();
    }
  }
	
	
	public ArrayList<TipoSeguro> listarTiposSeguros() {
    despertarJar();
    ArrayList<TipoSeguro> lista = new ArrayList<TipoSeguro>();
    String query = "SELECT idTipo, descripcion FROM tipoSeguros";

    try (Connection cn = DriverManager.getConnection(host + dbName, user, pass); Statement st = cn.createStatement(); ResultSet rs = st.executeQuery(query)) {
    	while (rs.next()) {
    		TipoSeguro obj = new TipoSeguro();
        obj.setIdTipo(rs.getInt("idTipo"));
        obj.setDescripcion(rs.getString("descripcion"));    
        lista.add(obj); 
     }
    } catch (Exception e) {
    	e.printStackTrace();
    }
    return lista;
	}
}
