package Ejercicio1;

import java.util.ArrayList;
import java.util.Iterator;

public class mainEjercicio1_a {
    public static void main(String[] args) {
    	
        ArrayList<Profesor> profesores = new ArrayList<>();
        profesores.add(new Profesor(1, "Ana", 40, "Titular", 15));
        profesores.add(new Profesor(2, "Luis", 35, "Adjunto", 10));
        profesores.add(new Profesor(3, "Sofía", 45, "Titular", 20));
        profesores.add(new Profesor(4, "Carlos", 50, "Jefe de cátedra", 25));
        profesores.add(new Profesor(5, "Elena", 38, "Ayudante", 8));

        Iterator<Profesor> it = profesores.iterator();
        while (it.hasNext()) {
            System.out.println(it.next());
        }
    }
}
