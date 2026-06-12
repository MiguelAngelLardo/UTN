package negocio;

import entidad.Cliente;

import java.util.ArrayList;

public interface IClienteNegocio {
  public abstract int altaCliente(Cliente cliente);
  
  public abstract ArrayList<Cliente> listarClientes(); 
}
