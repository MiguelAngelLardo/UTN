package ejercicio1;
import java.util.HashSet;
import java.util.Iterator;

public class MainEjercicio1_d {

	public static void main(String[] args) {
		
		
    HashSet<Persona> conjuntoPersonas = new HashSet<Persona>();
    
    Persona p1 = new Persona("111", "Miguel", "Gomez", null, null, null, null, null);
    Persona p2 = new Persona("222", "Ana", "Perez", null, null, null, null, null);
    Persona p3 = new Persona("333", "Juan", "Garcia", null, null, null, null, null);
    Persona p4 = new Persona("444", "Vale", "Lopez", null, null, null, null, null);
    Persona p5 = new Persona("111", "Miguel", "Gomez", null, null, null, null, null); // Intentamos agregar un DUPLICADO (mismo DNI que p1)

    conjuntoPersonas.add(p1);
    conjuntoPersonas.add(p2);
    conjuntoPersonas.add(p3);
    conjuntoPersonas.add(p4);
    conjuntoPersonas.add(p5); // <--- El HashSet lo va a RECHAZAR gracias al equals/hashCode

    Iterator<Persona> it = conjuntoPersonas.iterator();
    while(it.hasNext()) {
        System.out.println(it.next().toString());
        System.out.println("-------------------------");
    }
		
	}

}
