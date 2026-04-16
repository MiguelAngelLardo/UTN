package ejemplo2;

public class Messi {

	private String nacionalidad;
	private IEquipo equipo;
	
	
	public Messi()
	{
		
	}

	public Messi(String nacionalidad, IEquipo equipo) {
		super();
		this.nacionalidad = nacionalidad;
		this.equipo = equipo;
	}

	
	public IEquipo getEquipo() {
		return equipo;
	}

	public void setEquipo(IEquipo equipo) {
		this.equipo = equipo;
	}

	public String getNacionalidad() {
		return nacionalidad;
	}

	public void setNacionalidad(String nacionalidad) {
		this.nacionalidad = nacionalidad;
	}

	@Override
	public String toString() {
		return "Messi [nacionalidad=" + nacionalidad + "]"+ equipo.toString();
	}
	
	
}
