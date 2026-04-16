package Ejercicio2;

import java.util.ArrayList;
import java.util.Iterator;

import Ejercicio1.Profesor;

public class mainEjercicio2 {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		ProductoCongelado congelado = new ProductoCongelado("14/04/2023", 155, -18.5);
		System.out.println("=== Producto Congelado ===");
        congelado.mostrarProducto();
        System.out.println();
		
		ProductoFresco fresco = new ProductoFresco("14/04/2025",155,"15/05/2023","Argentina");
		System.out.println("=== Producto Fresco ===");
        fresco.mostrarProducto();
        System.out.println();
		
		ProductoRefrigerado refrigerado = new ProductoRefrigerado("14/04/2025",155,"A001");
        System.out.println("=== Producto Refrigerado ===");
        refrigerado.mostrarProducto();
        System.out.println();	
		
	}
	
}