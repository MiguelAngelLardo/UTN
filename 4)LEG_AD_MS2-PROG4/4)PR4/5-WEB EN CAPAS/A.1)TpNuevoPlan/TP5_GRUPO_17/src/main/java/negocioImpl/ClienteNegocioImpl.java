package negocioImpl;


import negocio.IClienteNegocio;
import entidad.Cliente;

import java.util.ArrayList;

import dao.IClienteDao;
import daoImpl.ClienteDaoImpl;

public class ClienteNegocioImpl implements IClienteNegocio {
  private IClienteDao objClienteDao = new ClienteDaoImpl();
  
  @Override
  public int altaCliente(Cliente cliente) {
    if (objClienteDao.dniCuilRepetido(cliente))  return 2; // 2 para dni cuil repetido
    
    boolean insertOk = objClienteDao.insertarCliente(cliente);
    return insertOk ? 1 : 3; // 1 todo ok, 3 fallo sql    
  }
  
  @Override
  public ArrayList<Cliente> listarClientes(){
    return objClienteDao.listar();
  }
}