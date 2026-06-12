package ejemplo4_HashSet;
import java.util.HashSet;
import java.util.Iterator;

//NO ES POSIBLE ORDENAR UN HASHSET

public class Principal {

	public static void main(String[] args) {
	
		
		
		Libro p1 = new Libro("Autor1", "Libro1", 111111);
		Libro p2 = new Libro("Autor2", "Libro2", 222222);
		Libro p3 = new Libro("Autor3", "Libro3", 333333);
		Libro p4 = new Libro("Autor4", "Libro4", 444444);
		Libro p5 = new Libro("Autor1", "Libro1", 111111);
		
		

		HashSet<Libro> listaLibros = new HashSet<Libro>();
		listaLibros.add(p1);
		listaLibros.add(p1);
		listaLibros.add(p1);
		listaLibros.add(p1);
		listaLibros.add(p1);
		
		listaLibros.add(p2);
		listaLibros.add(p3);
		listaLibros.add(p4);
		listaLibros.add(p5); // No debería agregarlo
		
	
		
		System.out.println("Listado de libros con FOR \n");
		for (Libro x : listaLibros) {
			System.out.println(x.toString());
		}

		
		System.out.println("Listado de libros \n");		
		Iterator<Libro> it = listaLibros.iterator();
		while(it.hasNext())
		{
			Libro p = (Libro) it.next();
			System.out.println(p.toString());
		}
		
		
		//Codigo para eliminar un elemento
		System.out.println("\n Remuevo el libro 444444 \n");
		
		Iterator<Libro> it2 = listaLibros.iterator();
		while(it2.hasNext())
		{
			Libro p = (Libro) it2.next();
		   if(p.getISBN() == 444444)
			it2.remove();
		}
		
		
	}
}
