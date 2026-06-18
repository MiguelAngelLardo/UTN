package frgp.utn.edu.ar.tp6_grupo_17.entidad;

public class Contacto implements java.io.Serializable  {
  // --- Pantalla 1 ---
  private int _idContacto;
  private String _nombre;
  private String _apellido;
  private String _telefono;
  private String _tipoTelefono;     // Casa/Trabajo/Móvil (spinner)
  private String _email;
  private String _tipoEmail;        // Casa/Trabajo/Móvil (spinner)
  private String _direccion;
  private String _fechaNacimiento;

  // --- Pantalla 2 ---
  private String _nivelEstudio;    // el radio seleccionado (texto)
  private String _intereses;        // los checkboxes marcados (ej: "Deporte, Música")
  private boolean _recibirInfo;     // el switch (true/false)

  public Contacto() {}
  public Contacto(String nombre, String apellido, String telefono, String tipoTelefono, String email, String tipoEmail, String direccion, String fechaNacimiento, String nivelEstudio, String intereses, boolean recibirInfo) {
    this._nombre = nombre;
    this._apellido = apellido;
    this._telefono = telefono;
    this._tipoTelefono = tipoTelefono;
    this._email = email;
    this._tipoEmail = tipoEmail;
    this._direccion = direccion;
    this._fechaNacimiento = fechaNacimiento;
    this._nivelEstudio = nivelEstudio;
    this._intereses = intereses;
    this._recibirInfo = recibirInfo;
  }

  public Contacto(String nombre, String apellido, String telefono, String tipoTelefono, String email, String tipoEmail, String direccion, String fechaNacimiento) {
    this._nombre = nombre;
    this._apellido = apellido;
    this._telefono = telefono;
    this._tipoTelefono = tipoTelefono;
    this._email = email;
    this._tipoEmail = tipoEmail;
    this._direccion = direccion;
    this._fechaNacimiento = fechaNacimiento;
    this._nivelEstudio = "";
    this._intereses = "";
    this._recibirInfo = false;
  }


  public void setIdContacto(int idContacto) { this._idContacto = idContacto; }
  public int getIdContacto() { return _idContacto; }

  public void setNombre(String nombre) { this._nombre = nombre; }
  public String getNombre() { return _nombre; }
  public void setApellido(String apellido) { this._apellido = apellido; }
  public String getApellido() { return _apellido; }
  public void setTelefono(String telefono) { this._telefono = telefono; }
  public String getTelefono() { return _telefono; }
  public void setTipoTelefono(String tipoTelefono) { this._tipoTelefono = tipoTelefono; }
  public String getTipoTelefono() { return _tipoTelefono; }
  public void setEmail(String email) { this._email = email; }
  public String getEmail() { return _email; }
  public void setTipoEmail(String tipoEmail) { this._tipoEmail = tipoEmail; }
  public String getTipoEmail() { return _tipoEmail; }
  public void setDireccion(String direccion) { this._direccion = direccion; }
  public String getDireccion() { return _direccion; }
  public void setFechaNacimiento(String fechaNacimiento) { this._fechaNacimiento = fechaNacimiento; }
  public String getFechaNacimiento() { return _fechaNacimiento; }
  public void setNivelEstudio(String nivelEstudio) { this._nivelEstudio = nivelEstudio; }
  public String getNivelEstudio() { return _nivelEstudio; }
  public void setIntereses(String intereses) { this._intereses = intereses; }
  public String getIntereses() { return _intereses; }
  public void setRecibirInfo(boolean recibirInfo) { this._recibirInfo = recibirInfo; }
  public boolean getRecibirInfo() { return _recibirInfo; }



}
