package dao;

import java.sql.DriverManager;
import java.sql.Connection;
//import java.sql.Statement;

//para el PreparedStatement que impide la inyeccion de SQL
import java.sql.PreparedStatement;

//para el listar recibe el remolque lleno de cajas
import java.sql.ResultSet;
import java.util.ArrayList;

import dominio.*;

public class SeguroDao {
	private String host = "jdbc:mysql://localhost:3306/";
	private String user = "root";
	private String pass = "root";
	private String dbName = "SegurosGroup?useSSL=false"; 
	
	public SeguroDao() {};
	
	private void despertarJar() {
		try {
			Class.forName("com.mysql.jdbc.Driver");
    } catch (ClassNotFoundException e) {
    	System.out.println("ERROR: No se encontró el Driver en WEB-INF/lib");
    	e.printStackTrace();
    }
  }
	
	
	public int obtenerUltimoId() {//usamos el prepareStatement es util para busquedas por ID
		despertarJar();
		
    String query = "SELECT MAX(idSeguro) FROM seguros";
    int id = 0;
    try (Connection cn = DriverManager.getConnection(host + dbName, user, pass); PreparedStatement pst = cn.prepareStatement(query); ResultSet rs = pst.executeQuery()) {        
      if (rs.next()) 	id = rs.getInt(1);// id = rs.getInt("MAX(idSeguro)")
    } catch (Exception e) {
    	System.out.println("ERROR EN DAO: " + e.getMessage());
      e.printStackTrace();
    }
    return id;
	}
	
	
	public int agregarSeguro(Seguro s) {
		despertarJar();
	  // Usamos ? para que Java se encargue de las comillas y la seguridad
    String query = "INSERT INTO seguros(descripcion, idTipo, costoContratacion, costoAsegurado) VALUES (?, ?, ?, ?)";
    int filas = 0;

    try (Connection cn = DriverManager.getConnection(host + dbName, user, pass); PreparedStatement pst = cn.prepareStatement(query)) { 
    	pst.setString(1, s.getDescripcion());// Seteamos los valores (PreparedStatement cuenta desde 1)
      pst.setInt(2, s.getTipoSeguro().getIdTipo());
      pst.setDouble(3, s.getCostoContratacion());
      pst.setDouble(4, s.getCostoAsegurado());
      
      filas = pst.executeUpdate();
      // Ya no hace falta cn.close() ni pst.close(). ¡Java se encarga! 
   } catch (Exception e) {
  	 e.printStackTrace();
   }
   return filas;
	}		

	
	
	public ArrayList<Seguro> listarSeguros() {
    despertarJar();

	  ArrayList<Seguro> listSeguros = new ArrayList<Seguro>();		
			
		String sql = "SELECT s.idSeguro, s.descripcion, s.idTipo, t.descripcion as descTipo, s.costoContratacion, s.costoAsegurado " +
                 "FROM seguros s INNER JOIN tipoSeguros t ON s.idTipo = t.idTipo";
		
		try (Connection cn = DriverManager.getConnection(host + dbName, user, pass); PreparedStatement st = cn.prepareStatement(sql); ResultSet rs = st.executeQuery()) {
			while (rs.next()) {
		    Seguro s = new Seguro();
		    s.setIdSeguro(rs.getInt("idSeguro")); // Limpio y seguro
		    s.setDescripcion(rs.getString("descripcion"));
		    s.setCostoContratacion(rs.getDouble("costoContratacion"));
		    s.setCostoAsegurado(rs.getDouble("costoAsegurado"));

		    TipoSeguro ts = new TipoSeguro();//comp
		    ts.setIdTipo(rs.getInt("idTipo"));//comp
		    ts.setDescripcion(rs.getString("descTipo")); // comp con alias por que no sabe que descripcion es
		    s.setTipoSeguro(ts);

		    listSeguros.add(s);
		}
       
   } catch (Exception e) { 
  	 e.printStackTrace(); 
   }
	
   return listSeguros;
	}
	
	public ArrayList<Seguro> listarPorIdTipo(String idTipoSeguro){
    despertarJar();

	  ArrayList<Seguro> listSegurosPorIdTipo = new ArrayList<Seguro>();		
		
		String sql = "SELECT s.idSeguro, s.descripcion, s.idTipo, t.descripcion as descTipo, s.costoContratacion, s.costoAsegurado " +
                 "FROM seguros s INNER JOIN tipoSeguros t ON s.idTipo = t.idTipo " +
				         "WHERE s.idTipo =?";
		   
		try (Connection cn = DriverManager.getConnection(host + dbName, user, pass); 
		  PreparedStatement st = cn.prepareStatement(sql)) {//el servidor de bbd "pre-compila" la consulta y dejo reservado el espacio con "?"  ademas de "pre-compilar" se usa para proteger la inyeccion
      
			st.setInt(1, Integer.parseInt(idTipoSeguro)); //el ? es el placeholder
       
      try (ResultSet rs = st.executeQuery()) {
        while (rs.next()) {
        Seguro s = new Seguro();
          s.setIdSeguro(rs.getInt("idSeguro"));
          s.setDescripcion(rs.getString("descripcion"));
          s.setCostoContratacion(rs.getDouble("costoContratacion"));
          s.setCostoAsegurado(rs.getDouble("costoAsegurado"));

          TipoSeguro ts = new TipoSeguro();
          ts.setIdTipo(rs.getInt("idTipo"));
          ts.setDescripcion(rs.getString("descTipo"));
          s.setTipoSeguro(ts);

          listSegurosPorIdTipo.add(s);
        }
     }
   } catch (Exception e) { 
     e.printStackTrace(); 
   }
   
		return listSegurosPorIdTipo;
  }

}
	
	
	

	


	

