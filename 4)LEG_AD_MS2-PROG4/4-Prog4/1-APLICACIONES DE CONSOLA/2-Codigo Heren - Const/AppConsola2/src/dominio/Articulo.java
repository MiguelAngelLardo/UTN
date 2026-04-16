package dominio;

public class Articulo {
	
	//atributos
	
	private int id;
	private String nombre;
	
	private static int cont=0;
	
	//método
	
	public static int devuelveProximoId()
	{
		return cont+1;
	}
	
	
	//contructores
	
	public Articulo()
	{
		cont++;
		this.id = cont;
		this.nombre = "Sin nombre";
	}
	
	public Articulo(String nombre)
	{
		cont++;
		this.id = cont;
		this.nombre = nombre;
	}
	
	// getters y setters 
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getNombre() {
		return nombre;
	}
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	
	@Override
	public String toString() {
		return "Articulo ID=" + id + ", NOMBRE=" + nombre;
	}
	
	//método toString()
	
	
	
	

}
