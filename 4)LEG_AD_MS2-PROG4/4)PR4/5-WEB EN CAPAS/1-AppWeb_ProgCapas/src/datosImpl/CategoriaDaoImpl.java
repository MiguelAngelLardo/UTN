package datosImpl;

import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

import datos.CategoriaDao;
import entidad.Categoria;


public class CategoriaDaoImpl implements CategoriaDao{

	private Conexion cn;
	
	@Override
	public List<Categoria> obtenerTodos() {
		cn = new Conexion();
		cn.Open();
		 List<Categoria> list = new ArrayList<Categoria>();
		 try
		 {
			 ResultSet rs= cn.query("Select * from categorias where estado=1");
			 while(rs.next())
			 {
				 
				 Categoria cat = new Categoria();
				 cat.setIdCategoria(rs.getInt("categorias.idCategoria"));
				 cat.setNombre(rs.getString("categorias.nombre"));
				 cat.setEstado(rs.getInt("categorias.estado"));
				 list.add(cat);
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
	public Categoria obtenerUno(int id) {
		cn = new Conexion();
		cn.Open();
		 Categoria cat = new Categoria();
		 try
		 {
			 ResultSet rs= cn.query("Select * from categorias");
			 cat.setIdCategoria(rs.getInt("categorias.idCategoria"));
			 cat.setNombre(rs.getString("categorias.nombre"));
			 cat.setEstado(rs.getInt("categorias.estado"));
		 }
		 catch(Exception e)
		 {
			 e.printStackTrace();
		 }
		 finally
		 {
			 cn.close();
		 }
		 return cat;
	}

	@Override
	public boolean insertar(Categoria cat) {

		boolean estado=true;

		cn = new Conexion();
		cn.Open();	

		String query = "INSERT INTO categorias (nombre,estado) VALUES ('"+cat.getNombre()+"', '"+cat.getEstado()+"')";
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
	public boolean editar(Categoria cat) {
		boolean estado=true;

		cn = new Conexion();
		cn.Open();	

		String query = "UPDATE categorias SET nombre='"+cat.getNombre()+"', estado="+cat.getEstado()+" WHERE idCategoria="+cat.getIdCategoria();
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
	public boolean borrar(int id) {
		boolean estado=true;
		cn = new Conexion();
		cn.Open();
		 
		String query = "UPDATE categorias SET estado=0 WHERE idCategoria="+id;
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

	
}
