package negocioImpl;

import java.util.ArrayList;

import datos.ArticuloDao;
import datosImpl.ArticuloDaoImpl;
import entidad.Articulo;
import negocio.ArticuloNeg;

public class ArticuloNegImpl implements ArticuloNeg{

	private ArticuloDao artDao = new ArticuloDaoImpl();
	
	//Se puede recibir por constructor
	public ArticuloNegImpl(ArticuloDao artDao)
	{
		this.artDao = artDao;
	}
	
	public ArticuloNegImpl()
	{
	}
	
	@Override
	public ArrayList<Articulo> listarArticulos() {
		return (ArrayList<Articulo>) artDao.obtenerTodos();
	}

	@Override
	public Articulo obtenerUno(int id) {
		return artDao.obtenerUno(id);
	}

	@Override
	public boolean insertar(Articulo articulo) {
		return artDao.insertar(articulo);
	}

	@Override
	public boolean editar(Articulo articulo) {
		return artDao.editar(articulo);
	}

	@Override
	public boolean borrar(int id) {
		
		return artDao.borrar(id);
	}

	
	
}
