package Ejercicio1;

import java.io.IOException;

public class DniInvalido extends IOException  {		

	public DniInvalido() { 
		
	}

	@Override
	public String getMessage() {
		// TODO Auto-generated method stub
		return "El dni no puede contener letras.";
	}
	
	
}
