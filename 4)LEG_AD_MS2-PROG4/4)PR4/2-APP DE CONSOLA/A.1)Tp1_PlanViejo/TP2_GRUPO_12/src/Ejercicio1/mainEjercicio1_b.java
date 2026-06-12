package Ejercicio1;

import java.util.Iterator;
import java.util.TreeSet;

public class mainEjercicio1_b {
    public static void main(String[] args) {

        TreeSet<Profesor> profesores = new TreeSet<>();

        profesores.add(new Profesor(1, "Ana", 40, "Titular", 15));
        profesores.add(new Profesor(2, "Luis", 35, "Adjunto", 10));
        profesores.add(new Profesor(3, "Sofía", 45, "Titular", 20));
        profesores.add(new Profesor(4, "Carlos", 50, "Jefe de cátedra", 25));
        profesores.add(new Profesor(5, "Elena", 38, "Ayudante", 8));

        Iterator<Profesor> it = profesores.iterator();
        while (it.hasNext()) 
        {
            System.out.println(it.next());
        }

        Profesor p1 = new Profesor(1, "Ana", 40, "Titular", 15);
        Profesor p2 = new Profesor(1, "Ana", 40, "Titular", 15);

        if (p1.equals(p2)) 
        {
            System.out.println("Es el mismo profesor.");
        }else 
        {
            System.out.println("No es el mismo profesor.");
        }
    }
}
