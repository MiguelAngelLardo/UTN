package negocioImpl;

import dao.IUsuarioDao;//interfaz
import daoImpl.UsuarioDaoImpl; // implementacio de UsusarioDao

import entidad.Usuario;// para recibir el Ususario de DaoImpl y hacer el pasamano
import negocio.IUsuarioNegocio; 

public class UsuarioNegocioImpl implements IUsuarioNegocio {
  private IUsuarioDao objUsuarioDao = new UsuarioDaoImpl();//permite hacer new UsusarioDaoOracle(); => escalabilidad
  
  @Override
  public Usuario login (String user, String pass) {
    // validamos de vuelta para la independecia de la capa negocio, para escalar sin usaer Servlet
    if (user == null || user.trim().isEmpty() || pass == null || pass.trim().isEmpty()) {
      return null; 
    }
    return  objUsuarioDao.leerUsuario(user, pass);// El "pasamano" hacia el DAO
  } 
}


