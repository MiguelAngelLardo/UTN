package dominio;

public class Principal {

	public static void main(String[] args) {
		
		UsuarioDao daoU = new UsuarioDao();
		
		Usuario x = new Usuario();
		x.setNombre("Federico 2");
		x.setApellido("Perez 2");
		
		int filas = daoU.agregarUsuario(x);
		if(filas==1)
			System.out.println("Usuario agregado con exito");
		else
			System.out.println("El usuario no pudo ser agregado");
		
	}
}
