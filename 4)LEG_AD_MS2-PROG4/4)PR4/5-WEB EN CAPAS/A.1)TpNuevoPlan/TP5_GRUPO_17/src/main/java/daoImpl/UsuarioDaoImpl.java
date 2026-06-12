package daoImpl;

import java.sql.Connection;
import java.sql.PreparedStatement;//evito inyeccion SQL con palce holder string
import java.sql.ResultSet; //para guardar toda la tabla


import dao.IUsuarioDao;//interfaz
import entidad.Usuario;//clase mapeada de bbdd


public class UsuarioDaoImpl extends Conexion implements IUsuarioDao {

  @Override //por la interfaz
  public Usuario leerUsuario(String user, String pass) {
    String query = "SELECT id_usuario, usuario FROM usuarios WHERE usuario = ? AND contrasena = ?"; 

    try (Connection cn = obtenerConexion(); PreparedStatement pst = cn.prepareStatement(query)) {//try-with-resources		    
      pst.setString(1, user);//luego de precompila la consulta agrega los valores como strings(planos de datos) y no como palabras reservadas(plano de control)
      pst.setString(2, pass);
              
      try (ResultSet rs = pst.executeQuery()) {//try-with-resources	=> trae tabla
        if (rs.next()) return new Usuario(rs.getInt("id_usuario"), rs.getString("usuario"));//Objeto Anonimo  => si no hay filas devuelve false     
      }//se cierra conexion del ResulSet
    
    } catch (Exception e) {//del primer try => igualmente sirve para el segundo try si falla, tamb entra aca
      e.printStackTrace();
    }
  return null; // Si no lo encontró, devuelve null
  }//metodo
}//clase