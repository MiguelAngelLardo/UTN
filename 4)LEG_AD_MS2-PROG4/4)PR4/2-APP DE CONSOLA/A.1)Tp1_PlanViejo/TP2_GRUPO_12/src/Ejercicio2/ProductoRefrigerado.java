package Ejercicio2;

public class ProductoRefrigerado extends Producto {

	private String codigoOrganismo;
	
	public ProductoRefrigerado()
	{
		super();
		codigoOrganismo = "0";
	}

	public ProductoRefrigerado(String fechaCaducidad, int numeroLote, String codigoOrganismo)
	{
		super(fechaCaducidad,numeroLote);
		this.codigoOrganismo = codigoOrganismo;
	}
	
	public String getCodigoOrganismo() {
		return codigoOrganismo;
	}

	public void setCodigoOrganismo(String codigoOrganismo) {
		this.codigoOrganismo = codigoOrganismo;
	}

	@Override
	public String toString() {
		return "Producto Refrigerado" + ", Codigo de Organismo:" + codigoOrganismo + super.toString();
	}
	
	public void mostrarProducto ()
	{
		System.out.println(this.toString());
	}
	

}
