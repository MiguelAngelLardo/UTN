package main;

/*
import dao.DaoCategoria;
import entidad.Categoria;
 * */

import dao.*;       // Trae DaoCategoria, DaoProducto y cualquier otro DAO que crees
import entidad.*;   // Trae Categoria, Producto y cualquier otra entidad

import java.util.ArrayList; //para el listar

//agrego el paquete

public class Principal {

	public static void main(String[] args) {
			/*
		
		  DaoCategoria categoriaDao = new DaoCategoria();			
			Categoria objCat = new Categoria();
			objCat.setIdCategoria(4);
			objCat.setNombre("Pescados"); 
			
			System.out.println("Intentando agregar la categoría en la base de datos...");
			
			int filas = categoriaDao.agregarCategoria(objCat);
			
			if(filas == 1) {
				System.out.println("La categoría se agregó correctamente en MySQL.\n");
			} else {
				System.out.println("Error: No se pudo agregar la categoría. Revisá los datos o la conexión.\n");
			}
			
			
			System.out.println("Intentando eliminar la categoría...");	
			int filasBorradas = categoriaDao.eliminarCategoria(2);	
			if(filasBorradas > 0) {
			    System.out.println("¡Baja exitosa! La categoría se eliminó.\n");
			} else {
			    System.out.println("No se borró nada\n");
			}
			
			
			System.out.println("Intentando modificar una categoría...");
			Categoria catParaModificar = new Categoria();
			catParaModificar.setIdCategoria(3); // Supongamos que queremos cambiar la categoría 3 (Carnes)
			catParaModificar.setNombre("Carnes Premium"); // Este es el nuevo valor
			int filasModificadas = categoriaDao.modificarCategoria(catParaModificar);
			if(filasModificadas > 0) {
					System.out.println("Modificación exitosa La categoría se actualizó.\n");
				} else {
					System.out.println("No se modificó nada\n");
				}
					
			
				System.out.println("Listado actual de Categorías en la Base de Datos:");
				
		
				ArrayList<Categoria> arrayListCat =  categoriaDao.listarCategoria(); //aca dentro abri conexion y mande el query de selelect * from Categorias
				
				for(Categoria cat: arrayListCat) {
					System.out.println(cat.toString());
				}
				*/
		
		
    DaoProducto productoDao = new DaoProducto();		
		/*
    System.out.println("Preparando la carga de 10 productos...");		
		
		Categoria catCarnes = new Categoria(3, "Carnes Premium");//la categoria 3 que quedo
		Categoria catPescados = new Categoria(4, "Pescados");//la categoria 4 que quedo
		
		ArrayList<Producto> arrayListProd = new ArrayList<Producto>();
		
		// Cargamos 5 productos de Carnes
		arrayListProd.add(new Producto("C001", "Bife de Chorizo", 8500.50, 20, catCarnes));
		arrayListProd.add(new Producto("C002", "Ojo de Bife", 9200.00, 15, catCarnes));
		arrayListProd.add(new Producto("C003", "Asado de Tira", 6500.00, 30, catCarnes));
		arrayListProd.add(new Producto("C004", "Vacio", 7100.25, 25, catCarnes));
		arrayListProd.add(new Producto("C005", "Matambre", 6800.00, 10, catCarnes));
		
		// 4. Cargamos 5 productos de Pescados
		arrayListProd.add(new Producto("P001", "Filet de Merluza", 4500.00, 50, catPescados));
		arrayListProd.add(new Producto("P002", "Salmon Rosado", 15000.00, 10, catPescados));
		arrayListProd.add(new Producto("P003", "Medallon de Atun", 12000.00, 12, catPescados));
		arrayListProd.add(new Producto("P004", "Gatuzo", 4200.00, 20, catPescados));
		arrayListProd.add(new Producto("P005", "Cornalitos", 3000.00, 40, catPescados));
		
		
		System.out.println("Iniciando inserción en MySQL con el Procedimiento Almacenado...\n");
		int agregadosExitosamente = 0;
		for (Producto prod : arrayListProd) {
			int filas = productoDao.spAgregarProducto(prod);
			
			if (filas > 0) {
				System.out.println("✅ Agregado: " + prod.getNombre());
				agregadosExitosamente++;
			} else {
				System.out.println("❌ Error al agregar: " + prod.getNombre());
			}
		}
		
		System.out.println("\nResumen: Se agregaron " + agregadosExitosamente + " de 10 productos.");
		*/
		
    /*
 		System.out.println("\nIniciando modificación de 4 productos..."); 		
 		Categoria catCarnes = new Categoria(3, "Carnes Premium");
 		Categoria catPescados = new Categoria(4, "Pescados");
 		
 		// Modificamos 2 de Carnes (C001 y C002)
 		// suben los precios, y bajó el stock
 		Producto modCarne1 = new Producto("C001", "Bife de Chorizo", 9500.00, 10, catCarnes); 
 		Producto modCarne2 = new Producto("C002", "Ojo de Bife", 10000.00, 12, catCarnes);
 		
 		// Modificamos 2 de Pescados (P001 y P002)
 		// estos además les vamos a cambiar un poquito el nombre
 		Producto modPescado1 = new Producto("P001", "Filet de Merluza Fresco", 4800.00, 40, catPescados);
 		Producto modPescado2 = new Producto("P002", "Salmon Rosado Premium", 16500.00, 5, catPescados);
 		
 		// Mandamos las modificaciones a la base de datos
 		productoDao.modificarProducto(modCarne1);
 		productoDao.modificarProducto(modCarne2);
 		productoDao.modificarProducto(modPescado1);
 		productoDao.modificarProducto(modPescado2);
 		
 		System.out.println("✅ Las 4 modificaciones se enviaron a MySQL.");
 		*/

    
   // --- BAJA DE PRODUCTOS ---
 		System.out.println("\nIntentando eliminar 2 productos...");
 		
 		// Vamos a borrar el Matambre (C005) y los Cornalitos (P005)
 		int baja1 = productoDao.eliminarProducto("C005");
 		int baja2 = productoDao.eliminarProducto("P005");
 		
 		if (baja1 > 0) {
 			System.out.println("Baja exitosa: El producto C005 (Matambre) fue eliminado.");
 		} else {
 			System.out.println("❌ No se pudo eliminar C005");
 		}
 		
 		if (baja2 > 0) {
 			System.out.println("Baja exitosa: El producto P005 (Cornalitos) fue eliminado.");
 		} else {
 			System.out.println("❌ No se pudo eliminar P005");
 		}
 		
    
 		// --- VERIFICACIÓN FINAL --- 		
		System.out.println("\n--- LISTADO COMPLETO DE PRODUCTOS ---");
		ArrayList<Producto> productosGuardados = productoDao.listarProducto();
		for (Producto p : productosGuardados) {
			System.out.println(p.toString());// el p tiene todos los valores de p y de categoria pero de categoria solo muestro lo que puse en el toString y eso es el nombreCategoria
		}
		
		
		
		
		
		
		
	
 
			
	}

}
