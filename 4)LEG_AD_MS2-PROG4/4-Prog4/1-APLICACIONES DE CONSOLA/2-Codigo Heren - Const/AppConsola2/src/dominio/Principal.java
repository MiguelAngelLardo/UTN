package dominio;

public class Principal {

	public static void main(String[] args) {
	
		ArticuloGimnasio art = new ArticuloGimnasio();
		art.setNombre("Mancuerna");
		art.setPeso(5);
		
		System.out.println(art.toString());
		System.out.println(art.devuelvePesoEnGramos()+ " gramos ");
		
		
	}

}
