package Ejercicio1;

public class Persona implements Comparable<Persona> {

	private String nombre;
    private String apellido;
    private String dni;

	public Persona(){
		nombre = "John";
		apellido = "Doe";
		dni = "0";
	}

	public Persona(String nombre, String apellido, String dni) {
		this.nombre = nombre;
		this.apellido = apellido;
		this.dni = dni;
	}


	public String getNombre() {return nombre;}
	public void setNombre(String nombre) {this.nombre = nombre;}

	public String getApellido() {return apellido;}
	public void setApellido(String apellido) {this.apellido = apellido;}

	public String getDni() {return dni;}
	public void setDni(String dni) {this.dni = dni;}

	@Override
    public int compareTo(Persona persona) {
        return this.apellido.compareTo(persona.apellido);
    }

	@Override
    public String toString() {
		return nombre + " - " + apellido + " - " + dni;
    }

}
