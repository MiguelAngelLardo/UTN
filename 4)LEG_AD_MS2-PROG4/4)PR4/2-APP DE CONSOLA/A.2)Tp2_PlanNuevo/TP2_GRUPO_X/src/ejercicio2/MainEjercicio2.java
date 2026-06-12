package ejercicio2;

import java.util.ArrayList;
import java.util.Iterator;

public class MainEjercicio2 {

	public static void main(String[] args) {
   	//como es clase padre guarda polideportivos y EdificiosDeOficinas por concepto de POLIMORFISMOS
		ArrayList <Edificio> arrayListEdificios = new ArrayList <Edificio>();//Coleccion => List => ArrayList

		// Creamos los objetos Polideportivo
    Polideportivo poli1 = new Polideportivo("Polideportivo Lanús", 100.0, 50.0, 1); //nombre, 100*50, 1=Techado
    Polideportivo poli2 = new Polideportivo("Club Social", 40.0, 30.0, 2); // nombre, 40*30, 2= Abierto
    Polideportivo poli3 = new Polideportivo("Arena Gral. Paz", 80.0, 60.0, 1);//nombre, 80*60, 1=techado
    
		// Creamos los objetos EdificioDeOficinas
    EdificioDeOficinas ofi1 = new EdificioDeOficinas(10, 20.5, 30.0, 5); // 10 oficinas, 20.5x30 mts, 5 pisos
    EdificioDeOficinas ofi2 = new EdificioDeOficinas(20, 15.0, 25.0, 10); // 20 oficinas, 15x25 mts, 10 pisos
    
    //carga de datos
    arrayListEdificios.add(poli1);
    arrayListEdificios.add(poli2);
    arrayListEdificios.add(poli3);
    arrayListEdificios.add(ofi1);
    arrayListEdificios.add(ofi2);
        
    Iterator<Edificio> iterador = arrayListEdificios.iterator();
    
    System.out.println("--- Listado de Edificios ---");
    while(iterador.hasNext()) {
    	Edificio objEdificio = iterador.next();    	
      System.out.println("Superficie Total: " + objEdificio.getSuperficieEdificio() + " m2");//POLIMORFISMO=> sabe qué getSuperficieEdificio() llamar
	
      if(objEdificio instanceof Polideportivo) {//instanceof devuelve True si el obj es de tipo Polideportivo
          System.out.println("Nombre del Poli: " + ((Polideportivo)objEdificio).getNombre());//converti temporalmente el objEdificio en Polideportivo
      }
      System.out.println("\n");
    }    
	}
}
