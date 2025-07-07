#include <iostream>
#include <string>
#include "PropietarioManager.h"
#include "InmuebleArchivo.h"

using namespace std;

void PropietarioManager::cargarPropietario(){
  string nombre, apellido, dni, celular;
  
  Propietario Obj;
  //for 10
  cin.ignore();
    
  cout << "Ingrese el DNI del Propietario: "; getline(cin, dni);
    if(_PropietarioArchivo.buscarPorDNI(dni) != -1){
      cout << "El DNI ya existe" << endl;
      system("pause");
      system("cls");
      return;
    }

  cout << "Ingrese el nombre del Propietario: "; getline(cin, nombre);
  cout << "Ingrese el apellido del Propietario: "; getline(cin, apellido);
  cout << "Ingrese el celular del Propietario: "; getline(cin, celular);
  Obj = Propietario(nombre, apellido, dni, celular, true);

  if( _PropietarioArchivo.agregarRegistro(Obj)){
    cout << "Propietario cargado con exito" << endl;
  }else{
    cout << "No se pudo cargar el Propietario" << endl;
  }
}

void PropietarioManager::listarTodosLeyendoDeAUno(){
  Propietario Obj;

  int cantidad =  _PropietarioArchivo.getCantidadRegistros();
  cout << "La cantidad todal de registros es: " << cantidad << endl;
  for(int i = 0; i < cantidad; i++){
    Obj =  _PropietarioArchivo.leerUnRegistro(i);//Cliente leer un reg (int pos)
    if(Obj.getEstado() == true){
      mostrarPropietario(Obj);
    }
  }  
}

void PropietarioManager::buscarPorDNI(){
  string dni;
  cout << "Ingrese el DNI del Propietario que desea buscar: " << endl;

  int pos = _PropietarioArchivo.buscarPorDNI(dni);
  if(pos != -1){
    Propietario Obj = _PropietarioArchivo.leerUnRegistro(pos);
    cout << Obj.toCSV() << endl;
  }else{
    cout << "No se encontro el Propietario" << endl;
  }  
}


void PropietarioManager::mostrarPropietario(Propietario reg){
  cout << "*************************" << endl;
  cout << "Nombre del Propietario: " << reg.getNombre() << endl;
  cout << "Apellido del Propietario: " << reg.getApellido() << endl;  
  cout << "DNI del Propietario: " << reg.getDNI() << endl;
  cout << "Celular del Propietario: " << reg.getCelular() << endl;
  cout << "Estado del Propietario: " << reg.getEstado() << endl;
  cout << "*************************" << endl;
  cout << endl;
}

void PropietarioManager::modificarTodoElRegistro(){
  Propietario Obj;
  string nombre, apellido, dni, celular;
  cout << "Ingrese el DNI del Propietario que desea modificar: " << endl;
  cin >> dni;

  int pos = _PropietarioArchivo.buscarPorDNI(dni);
  if(pos != -1){
    Obj = _PropietarioArchivo.leerUnRegistro(pos);
    cout << Obj.toCSV() << endl;
    cout << "Ingrese el nuevo nombre del Propietario: "; cin >> nombre;
    cout << "Ingrese el nuevo apellido del Propietario: "; cin >> apellido;
    cout << "Ingrese el nuevo celular del Propietario: "; cin >> celular;
    Obj.setNombre(nombre);
    Obj.setApellido(apellido);
    Obj.setCelular(celular);
    if( _PropietarioArchivo.modificarPorIndice(Obj, pos)){
      cout << "Propietario modificado con exito" << endl;
      cout << Obj.toCSV() << endl;
    }else{
      cout << "No se pudo modificar el Propietario" << endl;
    }
  }else{
    cout << "No se encontro el Propietario" << endl;
  }

  system("pause");

}


void  PropietarioManager::bajaLogicaPorDNI(){
  string dni;
  cout << "Ingrese el DNI del Propietario que desea dar de baja: " << endl;
  cin >> dni;

  int pos = _PropietarioArchivo.buscarPorDNI(dni);

  if(pos != -1){
    Propietario Obj = _PropietarioArchivo.leerUnRegistro(pos);
    cout << Obj.toCSV() << endl;
    Obj.setEstado(false);
    if(_PropietarioArchivo.modificarPorIndice(Obj, pos)){
      cout << "Propietario dado de baja con exito" << endl;
    }else{
      cout << "No se pudo dar de baja al Propietario" << endl;
    }
  }else{
    cout << "No se encontro el Propietario" << endl;
  }

  system("pause");  

}

void  PropietarioManager::listarInactivos(){
  Propietario Obj;
  int cantidad = _PropietarioArchivo.getCantidadRegistros();
  cout << "La cantidad todal de registros es: " << cantidad << endl;
  for(int i = 0; i < cantidad; i++){
    Obj = _PropietarioArchivo.leerUnRegistro(i);//Cliente leer un reg (int pos)
    if(Obj.getEstado() == false){
      mostrarPropietario(Obj);
    }
  }
}

void PropietarioManager::listarPropiedadesDelCliente(){
  InmuebleArchivo _InmuebleArchivo;
  PropietarioArchivo _PropietarioArchivo;
  string dni;
  cout << "Ingrese el DNI del Propietario: " << endl;
  cin >> dni;

  int pos1 = _PropietarioArchivo.buscarPorDNI(dni);
  int tamInmueble = _InmuebleArchivo.getCantidadRegistros();
  
  if(pos1 != -1){
    Propietario ObjProp = _PropietarioArchivo.leerUnRegistro(pos1);
    if(ObjProp.getEstado()){
      for(int i = 0; i < tamInmueble; i++){
        Inmueble ObjInm = _InmuebleArchivo.leerUnRegistro(i);
        if(ObjInm.getEstado()){
          if(dni == ObjInm.getDniDueno()){
            cout << "Propiedades del Propietario: " << ObjInm.toCSV() << endl;
          }
        }
      }
    }
  }else{
    cout << "No se encontro el Propietario" << endl;
  }

}
