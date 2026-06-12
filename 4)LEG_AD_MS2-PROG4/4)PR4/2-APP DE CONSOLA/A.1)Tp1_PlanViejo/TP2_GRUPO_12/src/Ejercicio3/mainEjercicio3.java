package Ejercicio3;

import java.util.ArrayList;
import java.util.Iterator;

public class mainEjercicio3 {
	
	 public static void main(String[] args) {
	            
	        ArrayList<Edificio> listaEdificios = new ArrayList<Edificio>();
	        
	        listaEdificios.add(new Polideportivo("Norte",1500,1));
	        listaEdificios.add(new Polideportivo("Centro",2000,2));
	        listaEdificios.add(new Polideportivo("Sur",1800,3));
	        
	        listaEdificios.add(new EdificioDeOficinas(50,3000));
	        listaEdificios.add(new EdificioDeOficinas(80,5000));
	        
	        Iterator<Edificio> it = listaEdificios.iterator();
	        
	        while (it.hasNext()) {
	        	
	            Edificio edificio = it.next();
	            
	            if (edificio instanceof Polideportivo) {
	            	
	                Polideportivo polideportivo = (Polideportivo) edificio;
	                System.out.println("Polideportivo: " + polideportivo.getNombre());
	                System.out.println("Superficie: " + polideportivo.getSuperficieEdificio() + " m²");
	                System.out.println("Tipo de Instalación: " + polideportivo.getTipoDeInstalacion());
	                
	            } else if (edificio instanceof EdificioDeOficinas) {
	            	
	                EdificioDeOficinas oficinas = (EdificioDeOficinas) edificio;
	                System.out.println("Edificio de Oficinas:");
	                System.out.println("Superficie: " + oficinas.getSuperficieEdificio() + " m²");
	                System.out.println("Número de oficinas: " + oficinas.getNumeroDeOficinas());
	            }
	            
	            System.out.println("--------------------------------------");
	        }
	        
	 }
	 
}


