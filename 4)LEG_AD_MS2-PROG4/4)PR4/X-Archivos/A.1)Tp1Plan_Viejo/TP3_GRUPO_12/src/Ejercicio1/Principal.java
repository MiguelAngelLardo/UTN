package Ejercicio1;


import java.io.IOException;
import java.util.Set;

public class Principal {
	

	public static void main(String[] args) throws IOException {
		
		/*
		String[] dnisDePrueba = {"12345678", "12A4567B"};

	    for (String dni : dnisDePrueba) {
	        try {
	            verificarDniInvalido(dni);
	            System.out.println("DNI válido: " + dni);
	        } catch (DniInvalido e) {
	            System.out.println("DNI inválido: " + dni);
	        }
	    }
		*/		
		
		
		String RutaPer = "src/Archivos/Personas.txt";
	    Archivo archivo = new Archivo(RutaPer);
	    Set<Persona> personas = archivo.devolver_String();
	    
	    for (Persona p : personas) {
            System.out.println(p);
        }	    	
	    
	    String RutaRes = "src/Archivos/Resultado.txt";
	    Archivo resultado = new Archivo(RutaRes);
	    
	    for (Persona p : personas) {
	    	resultado.escribe_lineas(p.toString());
	    	
	    }
	    
	}

}
