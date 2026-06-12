package dominio;

public class Seguro {
	private int idSeguro;
  private String descripcion;
  private TipoSeguro tipo; // Composición 
  private double costoContratacion;
  private double costoAsegurado;

  public Seguro() {}

  public Seguro(int idSeguro, String descripcion, TipoSeguro tipo, double costoContratacion, double costoAsegurado) {
    this.idSeguro = idSeguro;
    this.descripcion = descripcion;
    this.tipo = tipo;
    this.costoContratacion = costoContratacion;
    this.costoAsegurado = costoAsegurado;
  }

  public int getIdSeguro() {return idSeguro;}
  public void setIdSeguro(int idSeguro) {this.idSeguro = idSeguro;}
  public String getDescripcion() {return descripcion;}
  public void setDescripcion(String descripcion) {this.descripcion = descripcion;}
  public TipoSeguro getTipoSeguro() {return tipo;}
  public void setTipoSeguro(TipoSeguro tipo) {this.tipo = tipo;}
  public double getCostoContratacion() {return costoContratacion;}
  public void setCostoContratacion(double costoContratacion) {this.costoContratacion = costoContratacion;}
  public double getCostoAsegurado() {return costoAsegurado;}
  public void setCostoAsegurado(double costoAsegurado) {this.costoAsegurado = costoAsegurado;}
}
