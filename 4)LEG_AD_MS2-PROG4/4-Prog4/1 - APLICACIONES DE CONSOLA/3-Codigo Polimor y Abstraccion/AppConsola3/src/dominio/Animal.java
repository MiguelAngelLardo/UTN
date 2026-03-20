package dominio;

public abstract class Animal {

	private String nombre;

	//constructores
	
	public Animal()
	{
		nombre = "sin nombre";
	}
	
	public Animal(String nombre)
	{
		this.nombre = nombre;
	}
	
	
	//getters y setters
	
	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	// método toString()
	
	@Override
	public String toString() {
		return "ES UN ANIMAL, SU NOMBRE ES: " + nombre;
	}
	
	
	public abstract String habilidades();
	
}
	

