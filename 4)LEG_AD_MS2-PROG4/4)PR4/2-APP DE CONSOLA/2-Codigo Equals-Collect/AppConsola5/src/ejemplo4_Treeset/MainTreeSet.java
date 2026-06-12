package ejemplo4_Treeset;

import java.util.Iterator;
import java.util.TreeSet;


public class MainTreeSet {

	public static void main(String[] args) {
		
		
		TreeSet<Persona2> listaPersonas = new TreeSet<Persona2>();
	
	
		Persona2 p1 = new Persona2("Belen", "Sanchez", 11111111);
		Persona2 p2 = new Persona2("Alberto", "Rodriguez", 22222222);
		Persona2 p3 = new Persona2("Rodrigo", "Fernandez", 33333333);
		Persona2 p4 = new Persona2("Pedro", "Ibañez", 444444444);
		Persona2 p5 = new Persona2("Belen","Sanchez", 11111111);
		
		listaPersonas.add(p1);
		listaPersonas.add(p1);
		listaPersonas.add(p1);
		listaPersonas.add(p1);
		listaPersonas.add(p1); //AGREGO A P1 VARIAS VECES
		listaPersonas.add(p2);
		listaPersonas.add(p3);
		listaPersonas.add(p4);
		listaPersonas.add(p5);
		
	
	
		System.out.println("\nListado de personas for each ordenado \n");
		
		for (Persona2 x : listaPersonas) {
			System.out.println(x.toString());
		}

		System.out.println("Listado de personas iterador ordenado \n");
		
		Iterator<Persona2> it = listaPersonas.iterator();
		while(it.hasNext())
		{
			Persona2 p = (Persona2) it.next();
			System.out.println(p.toString());
		}
	}

}
