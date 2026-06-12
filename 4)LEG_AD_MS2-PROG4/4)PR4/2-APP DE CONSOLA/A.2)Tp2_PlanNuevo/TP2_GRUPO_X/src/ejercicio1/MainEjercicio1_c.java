package ejercicio1;

import java.time.LocalDate;
import java.util.Iterator;
//import java.util.TreeSet; => me da error

public class MainEjercicio1_c {

	public static void main(String[] args) {
		
		//TreeSet<Empleado> listaEmpleados = new 	TreeSet<Empleado>();//Collecion => Set => TreeSet (no van repetidos)(usa comparable + compare to())
		
		java.util.TreeSet<Empleado> listaEmpleados = new java.util.TreeSet<Empleado>();
		
		Empleado emp1 = new Empleado("12345678", "Miguel", "Gómez", LocalDate.of(1990, 5, 15), "Masculino", "Calle 123, Lanús", "111", "m@m.com", "Dev");
		Empleado emp2 = new Empleado("22334455", "Valentina", "López", LocalDate.of(1995, 3, 10), "Femenino", "Av. 9 de Julio, CABA", "222", "v@v.com", "Tester QA");
		Empleado emp3 = new Empleado("33445566", "Fernando", "García", LocalDate.of(1985, 11, 20), "Masculino", "Lomas de Zamora", "333", "f@f.com", "Arquitecto Cloud");
		Empleado emp4 = new Empleado("87654321", "Ana", "Pérez", LocalDate.of(1993, 8, 22), "Femenino", "Av 742, Banfield", "444", "a@a.com", "Analista");
		Empleado emp5 = new Empleado("11223344", "Juan", "Rodríguez", LocalDate.of(1988, 12, 1), "Masculino", "Hipolito 4500, Gerli", "555", "j@j.com", "Lider");

    listaEmpleados.add(emp1);
    listaEmpleados.add(emp2);
    listaEmpleados.add(emp3);//lo agrego varias veces 
    listaEmpleados.add(emp3);//lo agrego varias veces 
    listaEmpleados.add(emp3);//lo agrego varias veces 
    listaEmpleados.add(emp3);//lo agrego varias veces    
    listaEmpleados.add(emp4);
    listaEmpleados.add(emp5);
    
    Iterator<Empleado> it = listaEmpleados.iterator();//Iterador
    
    while(it.hasNext()) {
    	Empleado objEmpleado = it.next();
    	System.out.println(objEmpleado.toString());
      System.out.println("-------------------------");
    }
	}
}
