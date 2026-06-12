package ejercicio1;
import java.time.LocalDate;

public class Empleado extends Persona implements Comparable<Empleado> {
	
	private final int legajo;//constante
	private String puesto;
	
	private static int contadorLegajo = 1000;//atributo de la CLASE
	
	public Empleado() { 
		super();
		this.legajo = contadorLegajo;
			contadorLegajo ++;
	}
	
	
	public Empleado(String dni, String nombre, String apellido, LocalDate fechaNacimiento, String genero, String direccion, String telefono, String email, String puesto) {
		super(dni, nombre, apellido, fechaNacimiento, genero, direccion, telefono, email);
		this.legajo = contadorLegajo; 
		contadorLegajo++;             
		this.puesto = puesto;
	}
	
	public static int devuelveProximoLegajo() {
		return contadorLegajo;
	}
	
	public int getLegajo() {
		return legajo;
	}
	
	/*public void setLegajo(int legajo) {
		this.legajo = legajo;
	}*/
	
	public String getPuesto() {
		return puesto;
	}
	public void setPuesto(String puesto) {
		this.puesto = puesto;
	}
	
	@Override
	public String toString() {
		return super.toString() + 		
				"\nLegajo: " + legajo + ", \n" +
				"Puesto: " + puesto;	
	}

	@Override
	public int compareTo(Empleado o) {//compareTo devuelve 0, -1 o 1 segun el orden
    if (this.getDni().equals(o.getDni())) {	// Reemplazo == por equals ya que el == comopara direcciones
        return 0;
    }

    if (this.getDni().compareTo(o.getDni()) < 0) {//< solo funciona con numeros asi que uso String.compareTo(String otro)
        return -1;
    }

    return 1;		
	 //return this.getDni().compareTo(o.getDni()); => puedo resumir todo en 1 linea => si es igual  devuelve 0, si es menor devuelve -1, si es mayor devuelve 1
	}
		
}
