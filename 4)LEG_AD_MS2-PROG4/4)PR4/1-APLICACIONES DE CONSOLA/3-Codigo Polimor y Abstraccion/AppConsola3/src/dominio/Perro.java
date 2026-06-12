package dominio;

public class Perro extends Animal {

	private String raza;

	//constructores
	
	public Perro()
	{
		super();
		raza = "sin raza";
	}
	
	public Perro(String nombre, String raza)
	{
		super(nombre);
		this.raza = raza;
	}
	
	//gets y sets
	
	public String getRaza() {
		return raza;
	}

	public void setRaza(String raza) {
		this.raza = raza;
	}
	
	
	// toString()
	
	@Override
	public String toString() {
		return "ES UN PERRO, SU NOMBRE ES:"+getNombre()+" Y SU RAZA ES:" + raza;
	}

	@Override
	public String habilidades() {
		return "Los perros pueden localizar y separar olores.";
	}
	
}
