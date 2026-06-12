package negocio;

import java.util.List;

import entidad.Categoria;

public interface CategoriaNeg {

	public List<Categoria> obtenerTodos();
	public Categoria obtenerUno(int id);
	public boolean insertar(Categoria cat);
	public boolean editar(Categoria cat);
	public boolean borrar(int id);
}
