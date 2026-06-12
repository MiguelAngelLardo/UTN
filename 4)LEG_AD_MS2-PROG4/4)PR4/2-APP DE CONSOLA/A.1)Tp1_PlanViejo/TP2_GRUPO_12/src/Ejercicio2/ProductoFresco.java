package Ejercicio2;

public class ProductoFresco extends Producto {
    
	private String fechaEnvasado;
    private String paisOrigen;
    
    public ProductoFresco()
    {
    	super();
    	fechaEnvasado = "9-9-999";
    	paisOrigen = "Ninguno";
    }
    
    public ProductoFresco(String fechaCaducidad, int numeroLote, String fechaEnvasado, String paisOrigen)
    {
    	super(fechaCaducidad, numeroLote);
    	this.fechaEnvasado = fechaEnvasado;
    	this.paisOrigen = paisOrigen;
    }
    
	public String getFechaEnvasado() {
		return fechaEnvasado;
	}
	public void setFechaEnvasado(String fechaEnvasado) {
		this.fechaEnvasado = fechaEnvasado;
	}
	public String getPaisOrigen() {
		return paisOrigen;
	}
	public void setPaisOrigen(String paisOrigen) {
		this.paisOrigen = paisOrigen;
	}

	@Override
	public String toString() {
		return "Producto Fresco" + ", Fecha Envasado: " + fechaEnvasado + ", Pais de Origen: " + paisOrigen + super.toString();
	}
	
	public void mostrarProducto ()
	{
		System.out.println(this.toString());
	}
	
    
    
}
