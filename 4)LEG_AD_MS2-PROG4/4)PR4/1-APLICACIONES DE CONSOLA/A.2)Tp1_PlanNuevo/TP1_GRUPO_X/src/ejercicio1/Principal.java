package ejercicio1;
import java.time.LocalDate;
public class Principal {

	public static void main(String[] args) {
    Empleado vEmpleados[] = {
        new Empleado(), 
        new Empleado(),
        new Empleado("12345678", "Miguel", "Gómez", LocalDate.of(1990, 5, 15), "Masculino", "Calle Falsa 123, Lanús", "11-1234-5678", "miguel.gomez@email.com", "Desarrollador Java Junior"),
        new Empleado("87654321", "Ana", "Pérez", LocalDate.of(1993, 8, 22), "Femenino", "Av. Siempre Viva 742, Banfield", "11-8765-4321", "ana.perez@email.com", "Analista de Sistemas"),
        new Empleado("11223344", "Juan", "Rodríguez", LocalDate.of(1988, 12, 1), "Masculino", "Hipólito Yrigoyen 4500, Gerli", "11-1122-3344", "juan.rodriguez@email.com", "Líder de Proyecto")
    };
    
    for (int i = 0; i < vEmpleados.length; i++) {
      Empleado empActual = vEmpleados[i];      
      System.out.println("Empleado " + (i + 1) + ":");      
      System.out.println(empActual.toString()); 
      System.out.println(); 
    }
    
	  System.out.println("--- Información del Próximo Legajo ---");
	  System.out.println(); 
	  System.out.println("El próximo legajo será el " + Empleado.devuelveProximoLegajo());
	}
}


