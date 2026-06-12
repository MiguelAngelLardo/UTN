package entidad;

public class Articulo {

	
	private int idArticulo;
	private String nombre;
	private Float precio;
	private Categoria categoria;
	private int estado;
	
	public Articulo()
	{
		
	}

	public Articulo(int idArticulo, String nombre, Float precio, Categoria categoria, int estado) {
		super();
		this.idArticulo = idArticulo;
		this.nombre = nombre;
		this.precio = precio;
		this.categoria = categoria;
		this.estado = estado;
	}

	public int getIdArticulo() {
		return idArticulo;
	}

	public void setIdArticulo(int idArticulo) {
		this.idArticulo = idArticulo;
	}

	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public Float getPrecio() {
		return precio;
	}

	public void setPrecio(Float precio) {
		this.precio = precio;
	}

	public Categoria getCategoria() {
		return categoria;
	}

	public void setCategoria(Categoria categoria) {
		this.categoria = categoria;
	}

	public int getEstado() {
		return estado;
	}

	public void setEstado(int estado) {
		this.estado = estado;
	}

	@Override
	public String toString() {
		return "Articulo [idArticulo=" + idArticulo + ", nombre=" + nombre + ", precio=" + precio + ", categoria="
				+ categoria + ", estado=" + estado + "]";
	}
	
	
	

}
