package entidad;

public class Categoria {

	private int idCategoria;
    private String nombre;
    private int estado;
    
   
    public Categoria()
    {
    	
    }
    
	public Categoria(int idCategoria, String nombre, int estado) {
		super();
		this.idCategoria = idCategoria;
		this.nombre = nombre;
		this.estado = estado;
	}
	
	public Categoria(int idCategoria) {
		super();
		this.idCategoria = idCategoria;
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
	public int getEstado() {
		return estado;
	}
	public void setEstado(int estado) {
		this.estado = estado;
	}
    
	 
	@Override
	public String toString() {
		return "Categoria [idCategoria=" + idCategoria + ", nombre=" + nombre + ", estado=" + estado + "]";
	} 
	

}
