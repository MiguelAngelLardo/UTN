package negocioImpl;

import java.util.List;

import datos.CategoriaDao;
import datosImpl.CategoriaDaoImpl;
import entidad.Categoria;
import negocio.CategoriaNeg;

public class CategoriaNegImpl implements CategoriaNeg {

	public CategoriaDao cdao = new CategoriaDaoImpl();
	
	@Override
	public List<Categoria> obtenerTodos() {
		return cdao.obtenerTodos();
	}

	@Override
	public Categoria obtenerUno(int id) {
		return cdao.obtenerUno(id);
	}

	@Override
	public boolean insertar(Categoria cat) {
		return cdao.insertar(cat);
	}

	@Override
	public boolean editar(Categoria cat) {
		return cdao.editar(cat);
	}

	@Override
	public boolean borrar(int id) {
		return cdao.borrar(id);
	}

}
