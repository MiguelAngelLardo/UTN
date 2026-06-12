package entidad;

public class Usuario {
  private int id;
  private String nombreUsuario;
  private String contrasena;

  public Usuario() {}

  public Usuario(int id, String nombreUsuario) {
    this.id = id;
    this.nombreUsuario = nombreUsuario;
  }

  public void setId(int id) { this.id = id; }
  public int getId() { return id; }

  public void setNombreUsuario(String nombreUsuario) { this.nombreUsuario = nombreUsuario; }
  public String getNombreUsuario() { return nombreUsuario; }

  public void setContrasena(String contrasena) { this.contrasena = contrasena; }
  public String getContrasena() { return contrasena; }
}