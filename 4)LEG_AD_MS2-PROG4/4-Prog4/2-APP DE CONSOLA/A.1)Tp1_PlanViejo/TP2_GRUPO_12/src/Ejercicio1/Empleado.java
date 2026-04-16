package Ejercicio1;

public class Empleado {
	private int id;
    private String nombre;
    private int edad;
	
	private static int NumeroId = 1000;
	
	public Empleado()
	{
		id = NumeroId;
		nombre = "sin nombre";
		edad = 99;
		NumeroId+=1;
	}
	
	public Empleado(int id, String nombre, int edad) {
        this.id = id;
        this.nombre = nombre;
        this.edad = edad;
    }
	
	public int getId() { return id; }
    public String getNombre() { return nombre; }
    public int getEdad() { return edad; }

    public void setId(int id) { this.id = id; }
    public void setNombre(String nombre) { this.nombre = nombre; }
    public void setEdad(int edad) { this.edad = edad; }
	
	public String toString() {
		return "ID: " + id + " Nombre: " + nombre + " Edad: " + edad;
	}
	
	public static int devuelveProximoID() 
	{
		return NumeroId+1;
	}
	
}
