package ejemplo3_HashCode;

public class Principal {

	public static void main(String[] args) {
	
		String nombre1="Pepe";
	
		System.out.println(nombre1.hashCode());
		
		String nombre2="Pepe";
		System.out.println(nombre2.hashCode());
		
		String nombre3="PEPE";
		System.out.println(nombre3.hashCode());
		
		
		Persona x = new Persona();
		x.setNombre("Jose");
		x.setApellido("Casas");
		x.setDni("1111");
		
		System.out.println(x.hashCode());
		
		
		Persona y = new Persona();
		y.setNombre("Jose");
		y.setApellido("Casas");
		y.setDni("1111");
		
		
		System.out.println(y.hashCode());
		
	}

}