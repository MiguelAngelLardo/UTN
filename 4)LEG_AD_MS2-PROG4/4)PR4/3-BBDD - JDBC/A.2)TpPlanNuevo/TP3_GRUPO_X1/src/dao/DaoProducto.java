package dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

//sp
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
	
	public DaoProducto() {}
	
 
	
  //Alta usando Procedimiento Almacenado (CallableStatement)
	public int spAgregarProducto(Producto producto) {
		int filas = 0; 		
		
		// TRY-WITH-RESOURCES: Declaramos la conexión y el CallableStatement (cst) aquí.
		try (Connection cn = DriverManager.getConnection(host+dbName, user, pass); CallableStatement cst = cn.prepareCall("CALL sp_AgregarProducto(?, ?, ?, ?, ?)")) { // Los signos (?) son los "huecos" que el Procedimiento Almacenado está esperando

			// Llenamos los ? en orden (del 1 al 5)
			cst.setString(1, producto.getCodigo());
			cst.setString(2, producto.getNombre());  
			cst.setDouble(3, producto.getPrecio()); // setDouble va con la 'D' mayuscula
			cst.setInt(4, producto.getStock());
			cst.setInt(5, producto.getCategoria().getIdCategoria()); //composicion => solo la categoria meto sin el nombre por q no pertenece el nombreCategoria a la tabla Prodcto
			
			filas = cst.executeUpdate(); //cst.execute() se usaria solo sin filas =
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		// Al llegar aquí, Java cierra automáticamente tanto 'cst' como 'cn'.
		
		return filas; // Devolvemos el recibo (1 si funcionó, 0 si falló)
	}

	public ArrayList<Producto> listarProducto() {
		ArrayList<Producto> listProductos = new ArrayList<Producto>();		
		
		// Usamos INNER JOIN para cruzar las tablas y traernos también el Nombre de la categoría
		String query = "SELECT p.Codigo, p.Nombre, p.Precio, p.Stock, p.IdCategoria, c.Nombre AS NombreCategoria " +
		               "FROM Productos p INNER JOIN Categorias c ON p.IdCategoria = c.IdCategoria";
		
		// TRY-WITH-RESOURCES: Abrimos la ruta, el camión y el remolque aquí
		try (Connection cn = DriverManager.getConnection(host+dbName, user, pass); 
			 Statement st = cn.createStatement();			
			 ResultSet rs = st.executeQuery(query)) {
			
			while(rs.next()) {
				Producto prod = new Producto();
				//Le cargamos sus datos básicos
				prod.setCodigo(rs.getString("Codigo")); 
				prod.setNombre(rs.getString("Nombre")); 
				prod.setPrecio(rs.getDouble("Precio"));
				prod.setStock(rs.getInt("Stock"));
				
				//  COMPOSICIÓN => Instanciamos la categoría, la llenamos y la metemos en el producto
				Categoria cat = new Categoria();
				cat.setIdCategoria(rs.getInt("IdCategoria")); 
				cat.setNombre(rs.getString("NombreCategoria")); // Viene del JOIN				
				
				prod.setCategoria(cat); // Acá establecemos la relación
				
				listProductos.add(prod);
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		} 
		// En esta llave, Java cierra automáticamente el rs, el st y la cn en ese orden.
		
		return listProductos;
	}
	
//--- MODIFICACIÓN (Update) ---
	public int modificarProducto(Producto producto) {		
		String query = "UPDATE Productos SET Nombre = '" + producto.getNombre() + "', " +
		               "Precio = " + producto.getPrecio() + ", " +
		               "Stock = " + producto.getStock() + ", " +
		               "IdCategoria = " + producto.getCategoria().getIdCategoria() + 
		               " WHERE Codigo = '" + producto.getCodigo() + "'";
		
		int filas = 0;
		
		// TRY-WITH-RESOURCES: Declaramos la conexión y el statement dentro del paréntesis
		try (Connection cn = DriverManager.getConnection(host+dbName, user, pass); 
			 Statement st = cn.createStatement()) {
			
			filas = st.executeUpdate(query);

		} catch(Exception e) {
			e.printStackTrace();
		} 
		// Al salir del try, Java cierra automáticamente tanto el Statement como la Connection
		
		return filas;
	}

	
	
	
	
	//--- BAJA (Física) ---
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
