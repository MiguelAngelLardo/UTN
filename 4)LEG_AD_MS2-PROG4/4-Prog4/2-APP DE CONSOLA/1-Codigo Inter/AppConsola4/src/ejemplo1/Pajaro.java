package ejemplo1;

public class Pajaro implements ICantar{

	private int edad;
	
	public Pajaro()
	{
		
	}
	
	
	public Pajaro(int edad) {
		super();
		this.edad = edad;
	}

	public int getEdad() {
		return edad;
	}

	public void setEdad(int edad) {
		this.edad = edad;
	}

	@Override
	public String toString() {
		return "Pajaro [edad=" + edad + "]";
	}


	@Override
	public void cantar() {
		System.out.println("PIO PIO PIO PIO");
	}


	
	
	
	
}
