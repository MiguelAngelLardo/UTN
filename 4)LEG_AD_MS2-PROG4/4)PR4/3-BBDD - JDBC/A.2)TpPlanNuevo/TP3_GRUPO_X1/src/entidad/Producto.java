package entidad;

public class Producto {
//Miembros individuales reflejando las columnas exactas de la tabla
	private String codigo;      // VARCHAR(20) PK
	private String nombre;     
	private double precio;      // DECIMAL(10,2) 
	private int stock;          // INT
	
	private Categoria categoria;//un producto TIENE una Categoria => adentro uso la FK
	
	// Constructor vacío Obligatorio por que hice uno con parametros
	public Producto() {}

	public Producto(String codigo, String nombre, double precio, int stock, Categoria categoria) {
		this.codigo = codigo;
		this.nombre = nombre;
		this.precio = precio;
		this.stock = stock;
		this.categoria = categoria;
	}

	public String getCodigo() {
		return codigo;
	}

	public void setCodigo(String codigo) {
		this.codigo = codigo;
	}

	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public double getPrecio() {
		return precio;
	}

	public void setPrecio(double precio) {
		this.precio = precio;
	}

	public int getStock() {
		return stock;
	}

	public void setStock(int stock) {
		this.stock = stock;
	}

	public Categoria getCategoria() {
		return categoria;
	}

	public void setCategoria(Categoria categoria) {
		this.categoria = categoria;
	}

	// --- toString para pruebas ---
	@Override
	public String toString() {//Producto: Alfajor de Chocolate (P001) - $850.5 [Stock: 150, Categoria: Golosinas]
		return "Producto: " + nombre + " (" + codigo + ") - $" + precio + 
               " [Stock: " + stock + ", Categoria: " + categoria.getNombre() + "]";
	}
	
	
}
