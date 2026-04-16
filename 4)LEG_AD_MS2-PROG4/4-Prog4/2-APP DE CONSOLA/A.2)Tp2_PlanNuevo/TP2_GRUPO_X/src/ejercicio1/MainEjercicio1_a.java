package ejercicio1;

public class MainEjercicio1_a {

	public static void main(String[] args) {
	
    try {
        
        Persona.exVerificarDNI("AA202020"); // Validamos. Si esto falla, salta al catch y NO sigue.        
        Persona p1 = new Persona();
        p1.setDni("AA202020");
        System.out.println("Persona agregada correctamente");
        
    } catch (ExVerificarDNI e) {
        System.out.println("Persona no agregada por no verificar el DNI");//msj error        
        System.out.println("Detalle técnico: " + e.getMessage());//OPCIONAL: mensaje dinámico (el que viaja por super):
    }

    System.out.println("------------------------------------------------");

    try {        
        Persona.exVerificarDNI("20202020");        
        Persona p2 = new Persona();
        p2.setDni("20202020");
        System.out.println("Persona agregada correctamente");
        
    } catch (ExVerificarDNI e) {
        System.out.println("Persona no agregada por no verificar el DNI");
    }
	}
}
