package ejemplo4_Treeset;

public class Persona2 implements Comparable<Persona2>{
	
	private String nombre;
	private String apellido;
	private int dni;
	
	public int getDni() {
		return dni;
	}

	public void setDni(int dni) {
		this.dni = dni;
	}
	
	public Persona2(String nombre, String apellido, int dni){
		this.nombre = nombre;
		this.apellido = apellido;
		this.dni = dni;
	}
	
	public String getNombre() {
		return nombre;
	}
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}


	@Override
	public String toString() {
		return nombre + " " + apellido + ", Dni=" + dni;
	}


	@Override
	public int compareTo(Persona2 o) {
	
		//ORDENAMIENTO por DNI de > a <
		if(o.dni == this.dni)
			return 0;
		
		if (o.dni<this.dni)
		{
			return 1;
		}		
		return -1;
		
	}

	@Override
	public int hashCode() {
		return dni+31;
	}
	
	
	public boolean equals(Object obj)
	{
		Persona2 objPersona;
		if(obj instanceof Persona2)
		{
			objPersona = (Persona2) obj;
			if(objPersona.getDni() == this.getDni())
			{
				return true;
			}
		}
		    return false;
	}
	
	
}
