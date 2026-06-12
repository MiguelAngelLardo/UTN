package ejercicio1;
import java.time.LocalDate;
import java.util.Objects;

public class Persona {
	private String dni;
  private String nombre;
  private String apellido;
  private LocalDate fechaNacimiento;
  private String genero;
  private String direccion;
  private String telefono;
  private String email;
  
  public Persona() {
  	this.nombre = "sin nombre";
  	this.fechaNacimiento = LocalDate.of(2025, 1, 1);// Año, Mes, Día
  	
  }
  
  public Persona(String dni, String nombre, String apellido, LocalDate fechaNacimiento, String genero, String direccion, String telefono, String email) {
		this.dni = dni;
		this.nombre = nombre;
		this.apellido = apellido;
		this.fechaNacimiento = fechaNacimiento;
		this.genero = genero;
		this.direccion = direccion;
		this.telefono = telefono;
		this.email = email;
  }
  
  public String getDni() {
		return dni;
	}
	public void setDni(String dni) {
		this.dni = dni;
	}
	public String getNombre() {
		return nombre;
	}
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	public String getApellido() {
		return apellido;
	}
	public void setApellido(String apellido) {
		this.apellido = apellido;
	}
	public LocalDate getFechaNacimiento() {
		return fechaNacimiento;
	}
	public void setFechaNacimiento(LocalDate fechaNacimiento) {
		this.fechaNacimiento = fechaNacimiento;
	}
	public String getGenero() {
		return genero;
	}
	public void setGenero(String genero) {
		this.genero = genero;
	}
	public String getDireccion() {
		return direccion;
	}
	public void setDireccion(String direccion) {
		this.direccion = direccion;
	}
	public String getTelefono() {
		return telefono;
	}
	public void setTelefono(String telefono) {
		this.telefono = telefono;
	}
	public String getEmail() {
		return email;
	}
	public void setEmail(String email) {
		this.email = email;
	}
	
	@Override
	public String toString() {
		return "DNI: " + dni + ", \n" +
     "Nombre: " + nombre + ", \n" +
     "Apellido: " + apellido + ", \n" +
     "Fecha de Nacimiento: " + fechaNacimiento + ", \n" +
     "Género: " + genero + ", \n" +
     "Dirección: " + direccion + ", \n" +
     "Teléfono: " + telefono + ", \n" +
     "Email: " + email; 
	}
	
	
	public static boolean exVerificarDNI(String dni) throws ExVerificarDNI {
		//usamos aca el msj y no cokmo @Override publi String getMessage() para poder lanzar multiples msj
		
		
    if (dni.length() != 8) {//verificar longitud de 8
        throw new ExVerificarDNI("El DNI " + dni + " es inválido: debe tener 8 caracteres.");
    }

    for (int i = 0; i < dni.length(); i++) { //verificar solo numeros
        if (!Character.isDigit(dni.charAt(i))) {
            throw new ExVerificarDNI("El DNI " + dni + " es inválido: contiene letras o símbolos.");
        }
    }

    return true; // Si llegó acá, está todo bien
		/*
    ExVerificarDNI exec = new ExVerificarDNI();
		throw exec;*/
	}

	@Override
	public int hashCode() {//para un lista.add(p1) usa el hascode para transformar el DNI a hash => siusara el equals deberia comparar con 1 millon de registros
		                     //en cambio con el hash comapra con los poquitos similares
		return Objects.hash(dni);//genera un hash segun los caracteres del dni
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj) //si son dos obj iguales no pierde tiempo comparando DNI
			return true;
		if (obj == null)
			return false;
		
		if (getClass() != obj.getClass())//si comparo Persona con Perro da false
			return false;
		
		Persona other = (Persona) obj; //ya sabe que entro un obj Persona => hace un casteo de obj a Persona
		return Objects.equals(dni, other.dni);//Objects.equals(this.dni, other.dni)
	}
	
}//clase
