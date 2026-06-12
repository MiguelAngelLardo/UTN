package ejemplo3_RuntimeException;

public class Principal1 {

	public static void main(String[] args) {
		
		int [] vector = new int[5];
		try
		{
			vector[0]=10;
			vector[1]=35;
			vector[2]=40;
			vector[3]=50;
			vector[4]=30;
			vector[5]=30;
		}
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println("Se está tratando de acceder a una posición inválida");
		}
		
		for(int i=0; i<5; i++)
		{
			System.out.println("Números: "+vector[i]);
		}
		
	}
}
