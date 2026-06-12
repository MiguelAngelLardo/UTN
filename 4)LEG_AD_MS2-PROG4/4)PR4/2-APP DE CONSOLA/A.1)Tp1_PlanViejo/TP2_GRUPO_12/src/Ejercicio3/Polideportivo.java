package Ejercicio3;

public class Polideportivo extends Edificio implements InstalacionDeportiva {

	private String nombre;
	private InstalacionDeportiva ID;
	private int tipoInstalacion;
	
	public Polideportivo(String nombre, double superficie, int tipoInstalacion) 
	{
	     super(superficie);
	     this.nombre = nombre;
	     this.tipoInstalacion = tipoInstalacion;
	}
	
	public String getNombre() 
	{
		return nombre;
	}

	public void setNombre(String nombre) 
	{
		this.nombre = nombre;
	}

	public InstalacionDeportiva getID() 
	{
		return ID;
	}

	public void setID(InstalacionDeportiva iD) 
	{
		ID = iD;
	}
	
	
	public int getTipoDeInstalacion() 
	{
	     return tipoInstalacion;
	}
	
	public String toString() 
	{
	     return "Polideportivo: " + nombre + ", Superficie: " + super.getSuperficieEdificio() + " m²";
	}
}
