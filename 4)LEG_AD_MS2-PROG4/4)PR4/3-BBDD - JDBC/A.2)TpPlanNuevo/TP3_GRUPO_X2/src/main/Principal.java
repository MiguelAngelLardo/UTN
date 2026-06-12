package main;



import dao.*;       
import entidad.*;   

import java.util.ArrayList; 


public class Principal {

	public static void main(String[] args) {
	  DaoCategoria catDao = new DaoCategoria();
    DaoProducto prodDao = new DaoProducto();

    System.out.println("=== INICIO DE DEMOSTRACIÓN TP4 - UTN ===\n");  
    
    /**********PARTE A -> CATEGORIAS <- **********/
    // 1. AGREGAR CATEGORÍAS
    System.out.println(">>> 1. Agregando categorías nuevas...");
    Categoria catCaviar = new Categoria(100, "Caviar de Beluga");
    Categoria catRaro = new Categoria(200, "Esencia de Meteorito");

    System.out.println(catDao.agregarCategoria(catCaviar) > 0 ? "✅ Categoria agregada." : "❌ Categoria ya existe o error.");
    System.out.println(catDao.agregarCategoria(catRaro) > 0 ? "✅ Categoria agregada." : "❌ Categoria ya existe o error.");

    System.out.println("\nListado actual:");
    for (Categoria c : catDao.listarCategoria()) System.out.println(c.toString());

    // 2. MODIFICAR Y ELIMINAR CATEGORÍA
    System.out.println("\n>>> 2. Modificando y eliminando categorías...");
    
    catRaro.setNombre("Esencia de Meteorito - EDICIÓN LIMITADA");//modifico una CATEGORIA
    
    // MODIFICAR => modifico la categoria rara de METEORITO
    System.out.println(catDao.modificarCategoria(catRaro) > 0 ? "✅ Lista modificada: " + catRaro.getNombre() : "❌ No se pudo modificar la categoría");
    // ELIMINAR => elimino el ID 100 osea el CAVIAR
    System.out.println(catDao.eliminarCategoria(100) > 0 ? "✅ Categoría eliminada exitosamente." : "❌ Error al eliminar.");
    
    System.out.println("\nListado final de categorías:");
    for (Categoria c : catDao.listarCategoria()) System.out.println(c.toString());
     
    /**********PARTE B -> PRODUCTOS <- **********/
    // AGREGAR 10 PRODUCTOS (A la categoría 200 que quedó)
    System.out.println("\n>>> 3. Cargando 10 productos a la categoría 200...");
    for (int i = 1; i <= 10; i++) {//Codigo         Nombre               Precio     Stock  Composicion
   // Usamos paréntesis para forzar la suma matemática primero
      String codigo = "M" + (100 + i); //Conversión Implícita a String => string * int = string
      Producto p = new Producto(codigo, "Producto Raro " + i, 1000.0 * i, 10 + i, catRaro);
      System.out.println(prodDao.spAgregarProducto(p) > 0 ? "✅ Insertado: " + p.getNombre() : "❌ Error: " + p.getNombre() + " ya existe.");
    }

    // ELIMINAR 5 PRODUCTOS
    System.out.println("\n>>> 4. Eliminando 5 productos...");
    for (int i = 1; i <= 5; i++) {
    	String codABorrar = "M" + (100 + i);      
    	System.out.println(prodDao.eliminarProducto(codABorrar) > 0 ? "✅ Eliminado: " + codABorrar : "❌ Error");
  }

    // MODIFICAR 2 DE LOS QUE QUEDAN
    System.out.println("\n>>> 5. Modificando 2 nombres de los productos restantes...");
    Producto pMod1 = new Producto("M106", "Meteorito Envasado al Vacío", 9999.99, 5, catRaro);
    Producto pMod2 = new Producto("M107", "Polvo de Estrellas Pro", 8888.88, 3, catRaro);

    System.out.println(prodDao.modificarProducto(pMod1) > 0 ? "✅ Modificado M106" : "❌ Error al modificar M106");
    System.out.println(prodDao.modificarProducto(pMod2) > 0 ? "✅ Modificado M107" : "❌ Error al modificar M107");

    // LISTADO FINAL DE PRODUCTOS
    System.out.println("\n>>> 6. LISTADO FINAL DE PRODUCTOS EN BASE DE DATOS:");
    ArrayList<Producto> listaFinal = prodDao.listarProducto();
    if (listaFinal.isEmpty()) {
    	System.out.println("No hay productos en la base de datos.");
    } else {
    	for (Producto p : listaFinal) {
    		System.out.println(p.toString());
      }
    }

    System.out.println("\n=== FIN DE LA DEMOSTRACIÓN ===");
  }
}
	
