package negocio;

import entidad.Usuario;

public interface IUsuarioNegocio {
  public abstract Usuario login(String user, String pass);
}
