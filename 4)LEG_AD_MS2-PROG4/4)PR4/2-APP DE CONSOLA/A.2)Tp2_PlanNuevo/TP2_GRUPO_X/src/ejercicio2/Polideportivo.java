package ejercicio2;

public class Polideportivo extends Edificio implements IInstalacionDeportiva {
  private String nombre; //propio de la clase
	private int tipoDeInstalacion; // 1 para techado, 2 para abierto, por ejemplo
	
	public Polideportivo(String nombre, double ancho, double largo, int tipoDeInstalacion) {
		super(ancho, largo); 
		this.nombre = nombre;
		this.tipoDeInstalacion = tipoDeInstalacion;
	}
	
	@Override//metodo de interfaz siempre son public abstract	int getTipoDeInstalacion();
	public int getTipoDeInstalacion() {
		return tipoDeInstalacion;
	}

	@Override //obligatorio para heredar de edificio
	public double getSuperficieEdificio() {
		return getAncho() * getLargo();	
	}
		
	public String getNombre() {
		return this.nombre;
	}

}
