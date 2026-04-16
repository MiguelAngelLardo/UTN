package ejemplo4_CreandoExcepciones;

public class FaltaArrobaException extends RuntimeException {

	public FaltaArrobaException()
	{
		
	}

	@Override
	public String getMessage() {
		
		return "Falta colocar el arroba";
	}
	
	
}
