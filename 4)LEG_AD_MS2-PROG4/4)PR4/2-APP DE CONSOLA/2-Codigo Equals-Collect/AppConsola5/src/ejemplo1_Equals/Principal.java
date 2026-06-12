package ejemplo1_Equals;

public class Principal {

	public static void main(String[] args) {
		
		Persona p1 = new Persona();
		p1.setNombre("Jose");
		p1.setApellido("Diaz");
		p1.setDni("12345678");
		
		Persona p2 = new Persona();
		p2.setNombre("Jose");
		p2.setApellido("Diaz");
		p2.setDni("12345678");
		
		if(p1.equals(p2))
		{
			System.out.println("Son la misma persona");
		}
		else
		{
			System.out.println("No son la misma persona");
		}
		
	}
	
}
