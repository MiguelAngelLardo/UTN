package ejercicio2;

//clase abstracta por que no quiero realizar instancias de tipo Edificio
public abstract class Edificio {	
	private double ancho;
	private double largo;
	
	// El constructor sigue igual
	public Edificio(double ancho, double largo) {
		this.ancho = ancho;
		this.largo = largo;
	}

	// GETTERS para permitir la lectura de los datos
	public double getAncho() {
		return ancho;
	}

	public double getLargo() {
		return largo;
	}
	
	//metdo Abstracto => "no se calcular un edificio generico pero una oficina o un Polideportivo si sabra.
	public abstract double getSuperficieEdificio();
	
}
