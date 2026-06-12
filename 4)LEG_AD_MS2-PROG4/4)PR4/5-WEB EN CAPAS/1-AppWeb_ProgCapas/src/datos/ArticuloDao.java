package datos;

import java.util.List;

import entidad.Articulo;

public interface ArticuloDao {

	public List<Articulo> obtenerTodos();
	public Articulo obtenerUno(int id);
	public boolean insertar(Articulo articulo);
	public boolean editar(Articulo articulo);
	public boolean borrar(int id);
	
	
}
