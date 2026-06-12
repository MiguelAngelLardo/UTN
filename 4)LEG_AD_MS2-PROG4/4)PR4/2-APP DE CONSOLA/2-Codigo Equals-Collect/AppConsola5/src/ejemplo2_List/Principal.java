package ejemplo2_List;

import java.util.ArrayList;
import java.util.ListIterator;

import ejemplo1_Equals.Persona;

public class Principal {

	public static void main(String[] args) {
		
		Persona p1 = new Persona("Belen", "Sanchez", "11111111");
		Persona p2 = new Persona("Alberto", "Rodriguez", "22222222");
		Persona p3 = new Persona("Rodrigo", "Fernandez", "33333333");
		Persona p4 = new Persona("Pedro", "Ibañez", "444444444");
		Persona p5= new Persona("Mariano", "Martinez", "555555");
		Persona p6 = new Persona("Belen", "Sanchez", "11111111");
		
		ArrayList<Persona> listaPersonas = new ArrayList<Persona>();
		listaPersonas.add(p1);
		listaPersonas.add(p1);
		listaPersonas.add(p2);
		listaPersonas.add(p3);
		listaPersonas.add(p4);
		listaPersonas.add(p5);
		listaPersonas.add(p6);
		
		System.out.println("Listado de personas FOR: ");

		for(int i=0; i<listaPersonas.size(); i++)
		{
			System.out.println(listaPersonas.get(i).toString());
		}
		

		// ELIMINO
	
		listaPersonas.remove(0);
		
		
		System.out.println("Listado de personas CON ITERADOR: ");
	
		
		ListIterator<Persona> it = listaPersonas.listIterator();
		while (it.hasNext()) {
			Persona persona = it.next();
			it.remove();
			System.out.println(persona.toString());
		}
		

	}
}
