package dao;

import entidad.Cliente; 

import java.util.ArrayList;

public interface IClienteDao {
  public abstract boolean insertarCliente(Cliente cliente);
  public abstract boolean dniCuilRepetido(Cliente cliente);
  public abstract ArrayList<Cliente>listar();
}
