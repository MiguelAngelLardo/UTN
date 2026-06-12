package ejercicio2;

public class EdificioDeOficinas extends Edificio {
	private int numeroOficinas; //lo pide la consigna 
	private int cantidadDePisos; //idem ancho
	
	public EdificioDeOficinas(int numeroOficinas, double ancho, double largo, int cantidadDePisos) {
		super(ancho, largo); 
		this.numeroOficinas = numeroOficinas;
		this.cantidadDePisos = cantidadDePisos;
	}
	
   // Getter para el dato específico que pide la consigna
  public int getNumeroOficinas() {
      return numeroOficinas;
  }
  
  // El @Override OBLIGATORIO porque Edificio es abstract
  @Override
  public double getSuperficieEdificio() {
      return (getAncho() * getLargo()) * cantidadDePisos;
  }
	
}
