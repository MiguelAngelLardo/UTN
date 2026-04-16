package EJERCICIO1;

public class Empleado {
	private final int id;
	private String nombre;
	private int edad;
	
	private static int NumeroId = 1000;
	
	public static int devuelveProximoID() 
	{
		return NumeroId; //funcion modificada se quito el "+1"
	}
	
	public Empleado()
	{
		id = NumeroId;
		nombre = "sin nombre";
		edad = 99;
		NumeroId+=1;
	}
	
	public Empleado(String nombre, int edad)
	{
		id = NumeroId;
		this.nombre = nombre;
		this.edad = edad;
		NumeroId+=1;
	}
	
	public int getId() {
		return id;
	}
	public String getNombre() {
		return nombre;
	}
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	public int getEdad() {
		return edad;
	}
	public void setEdad(int edad) {
		this.edad = edad;
	}
	
	public String toString() {
		return "ID: " + id + " Nombre: " + nombre + " Edad: " + edad;
	}
}
