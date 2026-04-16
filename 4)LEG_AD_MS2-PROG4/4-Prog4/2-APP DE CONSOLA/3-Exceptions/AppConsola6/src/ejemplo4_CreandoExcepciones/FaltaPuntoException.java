package ejemplo4_CreandoExcepciones;

public class FaltaPuntoException extends RuntimeException{

	public FaltaPuntoException()
	{
		
	}

	@Override
	public String getMessage() {

		return "Falta colocar un punto";
	}
	
	
	
}
