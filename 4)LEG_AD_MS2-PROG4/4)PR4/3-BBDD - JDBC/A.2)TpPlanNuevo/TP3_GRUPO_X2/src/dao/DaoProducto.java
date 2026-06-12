package dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

import java.sql.CallableStatement;

//para listar
import java.sql.ResultSet;
import java.util.ArrayList;


import entidad.Producto;
import entidad.Categoria;

public class DaoProducto {
	private String host = "jdbc:mysql://localhost:3306/";
	private String user = "root";
	private String pass = "root";
	private String dbName = "bdInventario?useSSL=false"; 
 
	
	public int spAgregarProducto(Producto producto) {
    int filas = 0; 		
    try (Connection cn = DriverManager.getConnection(host+dbName, user, pass); CallableStatement cst = cn.prepareCall("CALL sp_AgregarProducto(?, ?, ?, ?, ?)")) {
        
        cst.setString(1, producto.getCodigo());
        cst.setString(2, producto.getNombre());  
        cst.setDouble(3, producto.getPrecio());
        cst.setInt(4, producto.getStock());
        cst.setInt(5, producto.getCategoria().getIdCategoria());
        
        filas = cst.executeUpdate();
    } catch (Exception e) {
        e.printStackTrace();
    }
    return filas;
	}
	
	public ArrayList<Producto> listarProducto() {
    ArrayList<Producto> listProductos = new ArrayList<Producto>();
    String query = "SELECT p.Codigo, p.Nombre, p.Precio, p.Stock, p.IdCategoria, c.Nombre AS NombreCategoria " +
                   "FROM Productos p INNER JOIN Categorias c ON p.IdCategoria = c.IdCategoria";

    try (Connection cn = DriverManager.getConnection(host+dbName, user, pass); 
         Statement st = cn.createStatement(); 
         ResultSet rs = st.executeQuery(query)) {

        while(rs.next()) {
            Producto prod = new Producto();
            prod.setCodigo(rs.getString("Codigo")); 
            prod.setNombre(rs.getString("Nombre")); 
            prod.setPrecio(rs.getDouble("Precio"));
            prod.setStock(rs.getInt("Stock"));

            Categoria cat = new Categoria();
            cat.setIdCategoria(rs.getInt("IdCategoria")); 
            cat.setNombre(rs.getString("NombreCategoria")); 

            prod.setCategoria(cat);
            listProductos.add(prod);
        }
    } catch (Exception e) {
        e.printStackTrace();
    } 
    return listProductos;
}

	public int modificarProducto (Producto producto) {
	String query = "UPDATE Productos SET Nombre = '" + producto.getNombre() + "', " +
					"Precio = " + producto.getPrecio() + "," +
					"Stock = " + producto.getStock() + ", " +
					"IdCategoria = " + producto.getCategoria().getIdCategoria() +
					" WHERE Codigo = '" + producto.getCodigo() + "'";
	int filas = 0;
	try (Connection cn = DriverManager.getConnection(host+dbName, user, pass); 
	     Statement st = cn.createStatement()){
		filas = st.executeUpdate(query);	 
	   }
	 catch (Exception e) {
	      e.printStackTrace();
	    }
	 return filas;
	}
	

	  public int eliminarProducto(String codigo) {
		  	String query = "DELETE FROM Productos WHERE Codigo = '" + codigo + "'";
		    int filas = 0;

		    try (Connection cn = DriverManager.getConnection(host + dbName, user, pass);
		      Statement st = cn.createStatement()) {
		      filas = st.executeUpdate(query);
		      } catch (Exception e) {
		          e.printStackTrace();
		      }
		      
		      return filas;
		  }
		
}
