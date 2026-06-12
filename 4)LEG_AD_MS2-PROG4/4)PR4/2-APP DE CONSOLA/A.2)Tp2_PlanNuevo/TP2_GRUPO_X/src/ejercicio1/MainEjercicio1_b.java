package ejercicio1;

import java.time.LocalDate;
import java.util.ArrayList; // Importación obligatoria
import java.util.Iterator;  // Importación obligatoria

public class MainEjercicio1_b {
	public static void main(String[] args) {
		
    ArrayList<Empleado> listaEmpleados = new ArrayList<Empleado>();//Coleccion => List => ArrayList
    
    listaEmpleados.add(new Empleado());//constructor vacio 
    listaEmpleados.add(new Empleado());//constructor vacio    
    listaEmpleados.add(new Empleado("12345678", "Miguel", "Gómez", LocalDate.of(1990, 5, 15), "Masculino", "Calle 123", "111", "m@m.com", "Dev"));    
    listaEmpleados.add(new Empleado("87654321", "Ana", "Pérez", LocalDate.of(1993, 8, 22), "Femenino", "Av 742", "222", "a@a.com", "Analista"));    
    listaEmpleados.add(new Empleado("11223344", "Juan", "Rodríguez", LocalDate.of(1988, 12, 1), "Masculino", "Hipolito 4500", "333", "j@j.com", "Lider"));
		
    Iterator<Empleado> it = listaEmpleados.iterator();//Iterador
    
    while (it.hasNext()) {//mientras haya un proximo objEmpleado => si hay alguien adelante devuelve true
        Empleado objEmpleado = it.next();//como el iterador comienza en la posicion -1 siempre comenzara por el cero
        System.out.println(objEmpleado.toString());
        System.out.println("-------------------------");
    }
	}
}
