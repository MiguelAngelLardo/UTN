package ejemplo2;

public class Principal {

	public static void main(String[] args) {

		Barcelona b = new Barcelona();
		b.setFechaClub("01/01/89");
				
		Juventus j = new Juventus();
		j.setCantJugadores(35);
		
		
		IEquipo x = b;
		IEquipo y = j;
		
		Messi messi = new Messi();
		messi.setEquipo(j);
		messi.setNacionalidad("Argentina");
		
		System.out.println(messi.toString());
		
		
	}

}
