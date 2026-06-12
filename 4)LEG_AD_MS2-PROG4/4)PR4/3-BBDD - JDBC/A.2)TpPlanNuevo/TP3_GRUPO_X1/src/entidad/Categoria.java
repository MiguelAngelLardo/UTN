package entidad;

public class Categoria {
	private int idCategoria;    // INT PK	
	private String nombre;      // VARCHAR(45)	
	
	public Categoria() {
	}
	
	public Categoria(int idCategoria, String nombre) {
		this.idCategoria = idCategoria;
		this.nombre = nombre;
	}

	
	public int getIdCategoria() {
		return idCategoria;
	}
	
	public void setIdCategoria(int idCategoria) {
		this.idCategoria = idCategoria;
	}
	
	public String getNombre() {
		return nombre;
	}
	
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	
	@Override
	public String toString() {
		return "Categoría: " + nombre + " (ID: " + idCategoria + ")";	
	}
}