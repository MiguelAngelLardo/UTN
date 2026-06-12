package ejercicio1;

@SuppressWarnings("serial")
public class ExVerificarDNI extends RuntimeException {
	public ExVerificarDNI() {}

 //Este constructor recibe el mensaje dinámico que armamos en el método estático
	public ExVerificarDNI(String mensaje) {
    super(mensaje); // Se lo envía a RuntimeException, y este a Throwable
	}
	
}
