package dao;

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;

import java.sql.ResultSet;
import java.util.ArrayList;

import entidad.Categoria;

public class DaoCategoria {
	private String host = "jdbc:mysql://localhost:3306/";
	private String user = "root";
	private String pass = "root";
	private String dbName = "bdInventario?useSSL=false"; //sin el ss=false da error 
	
	public DaoCategoria() {}
	
	
	public int agregarCategoria(Categoria categoria) {
		String query = "Insert into Categorias(IdCategoria,Nombre) values ('"+categoria.getIdCategoria()+"','"+categoria.getNombre()+"')";
		int filas = 0; 
		
		// TRY-WITH-RESOURCES
		try (Connection cn = DriverManager.getConnection(host+dbName,user,pass); Statement st = cn.createStatement()) {				 
			filas = st.executeUpdate(query);//como es int va afuera
    } catch(Exception e) {
			  e.printStackTrace(); 
		}		
		return filas;		
	}	
	
	public ArrayList<Categoria> listarCategoria() {
		ArrayList<Categoria> listCategorias = new ArrayList<Categoria>();		
		String query = "SELECT * FROM Categorias";
		
		try (Connection cn = DriverManager.getConnection(host+dbName, user, pass); 
		  Statement st = cn.createStatement();			
			ResultSet rs = st.executeQuery(query)) {
			
			while(rs.next()) {
			  Categoria cat = new Categoria();
				
				cat.setIdCategoria(rs.getInt("IdCategoria")); 
				cat.setNombre(rs.getString("Nombre")); 
				
				listCategorias.add(cat);
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		} //aca se cierra el CN, ST,RS 		

		return listCategorias;
	}

	public int eliminarCategoria(int idCategoria) {
    String query = "DELETE FROM Categorias WHERE IdCategoria = " + idCategoria;
    int filas = 0;
    
    try (Connection cn = DriverManager.getConnection(host+dbName, user, pass); 
         Statement st = cn.createStatement()) {
        filas = st.executeUpdate(query);
    } catch(Exception e) {
        e.printStackTrace();
    } 
    
    return filas;
  }
	
	
	public int modificarCategoria(Categoria categoria) {
	String query = "UPDATE Categorias SET Nombre ='" + categoria.getNombre() + "' where IdCategoria = " + categoria.getIdCategoria();
	  int filas = 0;
		
		try (Connection cn = DriverManager.getConnection(host+dbName, user, pass); 
			Statement st = cn.createStatement()) {
			filas = st.executeUpdate(query);
		} catch (Exception e) {
			e.printStackTrace();
		} 		
		return filas;
  }
	
}
