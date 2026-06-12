package Ejercicio3;

class EdificioDeOficinas extends Edificio {
	
	private int numeroDeOficinas;
	
	public EdificioDeOficinas()
	{
		super();
		this.numeroDeOficinas = 0;
	}
	public EdificioDeOficinas(int numeroDeOficinas, double superficie)
	{
		super(superficie);
		this.numeroDeOficinas = numeroDeOficinas;
	}
	
	
	public void setNumeroDeOficinas(int numeroDeOficinas) {this.numeroDeOficinas = numeroDeOficinas;}
	
	
	public int getNumeroDeOficinas() {return numeroDeOficinas;}
	
	@Override	
	 public String toString() {
	     return "Edificio de Oficinas Superficie: " + super.getSuperficieEdificio() + "m², Oficinas: " + numeroDeOficinas;
	 }
	
}
