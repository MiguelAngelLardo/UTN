package datosImpl;

import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

import datos.ArticuloDao;
import entidad.Articulo;
import entidad.Categoria;


public class ArticuloDaoImpl implements ArticuloDao {

	private Conexion cn;

	public ArticuloDaoImpl()
	{
		
	}
	
	@Override
	public List<Articulo> obtenerTodos() {
		cn = new Conexion();
		cn.Open();
		 List<Articulo> list = new ArrayList<Articulo>();
		 try
		 {
			 ResultSet rs= cn.query("Select articulos.idArticulo, articulos.nombre, articulos.precio, articulos.estado, categorias.idCategoria, categorias.nombre , categorias.estado from articulos inner join categorias on articulos.idCategoria = categorias.idCategoria");
			 while(rs.next())
			 {
				 Articulo art = new Articulo();
				 art.setIdArticulo(rs.getInt("articulos.idArticulo"));
				 art.setNombre(rs.getString("articulos.nombre"));
				 art.setPrecio(rs.getFloat("articulos.precio"));
				 
				 Categoria cat = new Categoria();
				 cat.setIdCategoria(rs.getInt("categorias.idCategoria"));
				 cat.setNombre(rs.getString("categorias.nombre"));
				 cat.setEstado(rs.getInt("categorias.estado"));
				 
				 art.setCategoria(cat);
				 art.setEstado(rs.getInt("articulos.estado"));
				 list.add(art);
			 }
			 
		 }
		 catch(Exception e)
		 {
			 e.printStackTrace();
		 }
		 finally
		 {
			 cn.close();
		 }
		 return list;
	}

	@Override
	public Articulo obtenerUno(int id) {
		cn = new Conexion();
		cn.Open();
		Articulo art = new Articulo();
		try
		 {
			 ResultSet rs= cn.query("Select articulos.idArticulo, articulos.nombre, articulos.precio, articulos.estado, categorias.idCategoria, categorias.nombre , categorias.estado from articulos inner join categorias on articulos.idCategoria = categorias.idCategoria where articulos.estado=1 && articulos.idArticulo="+id);
			 rs.next();
			 
			 art.setIdArticulo(rs.getInt("articulos.idArticulo"));
			 art.setNombre(rs.getString("articulos.nombre"));
			 art.setPrecio(rs.getFloat("articulos.precio"));
			 
			 Categoria cat = new Categoria();
			 cat.setIdCategoria(rs.getInt("categorias.idCategoria"));
			 cat.setNombre(rs.getString("categorias.nombre"));
			 cat.setEstado(rs.getInt("categorias.estado"));
			 
			 art.setCategoria(cat);
			 art.setEstado(rs.getInt("articulos.estado"));
			 
		 }
		 catch(Exception e)
		 {
			 e.printStackTrace();
		 }
		 finally
		 {
			 cn.close();
		 }
		return art;
	}

	@Override
	public boolean insertar(Articulo articulo) {
		
		boolean estado=true;

		cn = new Conexion();
		cn.Open();	

		String query = "INSERT INTO articulos (nombre,precio,idCategoria,estado) VALUES ('"+articulo.getNombre()+"','"+articulo.getPrecio()+"','"+articulo.getCategoria().getIdCategoria()+"', "+articulo.getEstado()+")";
		System.out.println(query);
		try
		 {
			estado=cn.execute(query);
		 }
		catch(Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			cn.close();
		}
		return estado;
	}

	@Override
	public boolean editar(Articulo articulo) {
		boolean estado=true;

		cn = new Conexion();
		cn.Open();	

		String query = "UPDATE  articulos SET nombre='"+articulo.getNombre()+"', precio='"+articulo.getPrecio()+"', idCategoria='"+articulo.getCategoria().getIdCategoria()+"', estado='"+articulo.getEstado()+"' WHERE idArticulo='"+articulo.getIdArticulo()+"'";
		try
		 {
			estado=cn.execute(query);
		 }
		catch(Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			cn.close();
		}
		return estado;
	}
	
	@Override
	public boolean borrar(int id) {
		boolean estado=true;
		cn = new Conexion();
		cn.Open();		 
		String query = "UPDATE articulos SET estado=0 WHERE idArticulo="+id;
		try
		 {
			estado=cn.execute(query);
		 }
		catch(Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			cn.close();
		}
		return estado;
	}


	
}
