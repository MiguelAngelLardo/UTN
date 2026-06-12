package dao;

import entidad.Usuario;

public interface IUsuarioDao {
	
  public abstract Usuario leerUsuario(String user, String pass);//abstract igual viene implicito - recibe lo q escribe el usuario
}
