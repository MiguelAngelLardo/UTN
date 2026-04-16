package Ejercicio1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Set;
import java.util.TreeSet;

public class Archivo {
	
	private String ruta;

	public Archivo() {
		
	}

	public Archivo(String ruta) {
		this.ruta = ruta;
	}

	//Getter y Setters
	public String getRuta() {
		return ruta;
	}

	public void setRuta(String ruta) {
		this.ruta = ruta;
	}
	
	//Saber si existe el Archivo
	public boolean existe()
	{
		File archivo = new File(ruta); 
		if(archivo.exists())
		      return true;
		return false;
	}

	//Crear archivo
	public boolean creaArchivo()
	{
		FileWriter escritura;
		try {
			escritura = new FileWriter(ruta, true);
			escritura.write("");
			escritura.close();
			return true;
		} catch (IOException e) {
			e.printStackTrace();
		}
		return false;
			
	}
	

	//Metodos de FileWriter y FileReader
	public void escribe_letra_x_letra(String frase) {
		try {
			FileWriter fw = new FileWriter(ruta, true);
	
			for (int i = 0; i < frase.length(); i++) {
					fw.write(frase.charAt(i));
				}		
			fw.close();

		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public void lee_letra_x_letra() {

		FileReader entrada;
		try {
			entrada = new FileReader(ruta);
			int c = entrada.read(); 
			while (c != -1) 
			{
				char letra = (char) c;
				System.out.println(letra);
				c = entrada.read();
			}
			entrada.close();
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}
	
	
	//Metodos con BufferedWriter y BufferedReader
	public void escribe_lineas(String frase) {
		try 
		{	
			FileWriter entrada = new FileWriter(ruta, true);
			BufferedWriter miBuffer = new BufferedWriter(entrada);
			miBuffer.newLine();
			miBuffer.write(frase);
			miBuffer.close();
			entrada.close();

		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	
	public Set<Persona> devolver_String() {		
		TreeSet <Persona> listaPersonas = new TreeSet<Persona>();		
		FileReader entrada;
		try {
			entrada = new FileReader(getRuta());
			BufferedReader miBuffer = new BufferedReader(entrada);			
		   String linea = "";
			while (linea != null) {				
				if(linea.length() > 0) {
					Persona persona = new Persona();
					int finNombre = linea.indexOf('-');
					int finApellido = linea.lastIndexOf('-');
					if(finNombre != -1 && finApellido != -1 ) {
						persona.setNombre(linea.substring(0,finNombre));
						persona.setApellido(linea.substring(finNombre + 1,finApellido));
                        persona.setDni(linea.substring(finApellido + 1).trim()); 
                        String dni = persona.getDni();
                        try {
                            verificarDniInvalido(dni);
                            listaPersonas.add(persona);
                        } catch (DniInvalido e) {
                            System.out.println("Error: " + e.getMessage() + " -> " + dni);
                        }
                     }					
				}			
				linea = miBuffer.readLine();
			}
			miBuffer.close();
			entrada.close();

		} catch (IOException e) {
			System.out.println("No se encontro el archivo");
		}		
		return listaPersonas;
	}		
				
	public static boolean verificarDniInvalido(String DNI) throws DniInvalido {
	    for (int i = 0; i < DNI.length(); i++) {
	        char c = DNI.charAt(i);
	        if (c < '0' || c > '9') {
	            throw new DniInvalido();
	        }
	    }
	    return true;
	}
	
	public void lee_lineas() {
		FileReader entrada;
		try {
			entrada = new FileReader(ruta);
			BufferedReader miBuffer = new BufferedReader(entrada);
			
		   String linea = "";
			while (linea != null) {
				System.out.println(linea);
				linea = miBuffer.readLine();
			}
			miBuffer.close();
			entrada.close();

		} catch (IOException e) {
			System.out.println("No se encontro el archivo");
		}
	}


}
