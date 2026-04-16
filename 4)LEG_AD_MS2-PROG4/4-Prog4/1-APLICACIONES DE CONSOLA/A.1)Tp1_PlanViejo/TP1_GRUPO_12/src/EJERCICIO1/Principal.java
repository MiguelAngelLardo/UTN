package EJERCICIO1;

//import dominio.Articulo;

public class Principal {

	public static void main(String[] args) {
		/*
		Empleado Emp1 = new Empleado();
		Empleado Emp2 = new Empleado("Juan2", 25);
		Empleado Emp3 = new Empleado();;
		Empleado Emp4 = new Empleado("Juan4", 29);
		Empleado Emp5 = new Empleado("Juan5", 30);
		

		System.out.println(Emp1.toString());
		System.out.println(Emp2.toString());
		System.out.println(Emp3.toString());
		System.out.println(Emp4.toString());
		System.out.println(Emp5.toString());
		*/
		
		//incorporación de vectores
		Empleado[] vEmp = new Empleado[5];
		vEmp[0] = new Empleado();
		vEmp[1] = new Empleado("Juan", 25);
		vEmp[2] = new Empleado();
		vEmp[3] = new Empleado("Simon", 29);
		vEmp[4] = new Empleado("Pepe", 30);
		
		
		for (Empleado empleado : vEmp) {
			System.out.println(empleado.toString());
		}
		
		System.out.println("El próximo ID será el " + Empleado.devuelveProximoID()); //funcion agregada muestra el proximo id en consola
		
	}

}
