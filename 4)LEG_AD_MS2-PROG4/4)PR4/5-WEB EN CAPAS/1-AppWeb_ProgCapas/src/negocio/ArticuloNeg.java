package negocio;

import java.util.ArrayList;

import entidad.Articulo;

public interface ArticuloNeg {

	public ArrayList<Articulo> listarArticulos();
	public Articulo obtenerUno(int id);
	public boolean insertar(Articulo articulo);
	public boolean editar(Articulo articulo);
	public boolean borrar(int id);
}
