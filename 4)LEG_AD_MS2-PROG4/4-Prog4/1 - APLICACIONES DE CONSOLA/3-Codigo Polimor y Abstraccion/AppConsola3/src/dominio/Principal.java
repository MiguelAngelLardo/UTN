package dominio;

public class Principal {

	public static void main(String[] args) {
		
		Animal animal = new Perro("Lola","Dobermann");
		Animal gato = new Gato("Pepita");
		Animal perro = new Perro("Huesos","Galgo");
	
		Animal[] animales = new Animal[3];
		animales[0] = animal;
		animales[1] = gato;
		animales[2] = perro;
		
			for (Animal a : animales) {
				System.out.println(a.toString()+ " "+ a.habilidades());
			}
			
		}	

}
