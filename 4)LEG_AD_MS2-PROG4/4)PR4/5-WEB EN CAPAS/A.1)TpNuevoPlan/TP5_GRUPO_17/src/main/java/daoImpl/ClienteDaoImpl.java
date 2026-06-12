package daoImpl;


import java.sql.Connection;
import java.sql.PreparedStatement;//evito inyeccion SQL con palce holder string
import java.sql.ResultSet;//para el listar

import java.util.ArrayList;

import dao.IClienteDao;
import entidad.Cliente;

public class ClienteDaoImpl extends Conexion implements IClienteDao {
  //static se crea con la clase => no se crea con cada objeto
  //Final es == a constante
  private static final String queryInsertar = "INSERT INTO clientes (dni, cuil, nombre, apellido, sexo, fecha_nacimiento, direccion, nacionalidad, localidad, provincia, correo_electronico, telefono) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
  private static final String queryListar = "SELECT dni, cuil, nombre, apellido, sexo, fecha_nacimiento, direccion, nacionalidad, localidad, provincia, correo_electronico, telefono FROM clientes";//traigo todo pero no uso los dos ultimos
  @Override
  public boolean insertarCliente(Cliente cliente) {
    int filas = 0;
    
    try (Connection cn = obtenerConexion(); PreparedStatement pst = cn.prepareStatement(queryInsertar)){
      pst.setString(1, cliente.getDni());
      pst.setString(2, cliente.getCuil());
      pst.setString(3, cliente.getNombre());
      pst.setString(4, cliente.getApellido());
      pst.setString(5, cliente.getSexo());
      pst.setString(6, cliente.getFechaNacimiento());
      pst.setString(7, cliente.getDireccion());
      pst.setString(8, cliente.getNacionalidad());
      pst.setString(9, cliente.getLocalidad());
      pst.setString(10, cliente.getProvincia());
      pst.setString(11, cliente.getCorreoElectronico());
      pst.setString(12, cliente.getTelefono());
     
      filas = pst.executeUpdate();
    } catch (Exception e) {
      e.printStackTrace();
    }
    return filas > 0;
  }
  
  @Override
  public boolean dniCuilRepetido(Cliente cliente) {//En SQL, COUNT() es una función de agregación que devuelve el número de filas que coinciden con los criterios de una consulta. 
    boolean repetido = false;
    String query = "SELECT COUNT(*) FROM clientes WHERE dni = ? OR cuil = ?";//el * es todas las columnas. => conta todas las filas q cumplan con la condicion sin importar q la columna esta vacia o llena. Si encuentra 2 iguales me da una tabla con un 2
    
    try(Connection cn = obtenerConexion(); PreparedStatement pst = cn.prepareStatement(query)){
      pst.setString(1, cliente.getDni());
      pst.setString(2, cliente.getCuil());
      
      try(ResultSet rs = pst.executeQuery()){
        if (rs.next()) repetido = rs.getInt(1) > 0; //con el get obtengo el dato de la tablita virtual - Traeme el valor de la columna número 1 de este resultado, y convertimelo a un número entero 
      }
      
    } catch (Exception e) {
      e.printStackTrace();
    }
    return repetido;  
  }

  
  @Override
  public ArrayList<Cliente> listar(){
    ArrayList<Cliente> lista = new ArrayList<>();
   
    try (Connection cn = obtenerConexion(); PreparedStatement pst = cn.prepareStatement(queryListar); ResultSet rs = pst.executeQuery()) { //podria usar Statement como vimos en los videos para el LISTAR, pero tambien funciona al PreparedStatement.
      
      while (rs.next()) {
        Cliente cliente = new Cliente();
        
        cliente.setDni(rs.getString("dni"));
        cliente.setCuil(rs.getString("cuil"));
        cliente.setNombre(rs.getString("nombre"));
        cliente.setApellido(rs.getString("apellido"));
        cliente.setSexo(rs.getString("sexo"));
        cliente.setFechaNacimiento(rs.getString("fecha_nacimiento"));
        cliente.setDireccion(rs.getString("direccion"));
        cliente.setNacionalidad(rs.getString("nacionalidad"));
        cliente.setLocalidad(rs.getString("localidad"));
        cliente.setProvincia(rs.getString("provincia"));
        
        //valores extra
        cliente.setCorreoElectronico(rs.getString("correo_electronico"));
        cliente.setTelefono(rs.getString("telefono"));
         
        lista.add(cliente);
        
        System.out.println("entre");
      }
      
    } catch (Exception e) {
      e.printStackTrace();
    }
  
    return lista;
  }
}

  
  
  
  

  