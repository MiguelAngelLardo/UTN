#include <iostream>
#include <string>
#include "InmuebleManager.h"

using namespace std;

void InmuebleManager::cargarInmueble(){
  int inmueble, tipoPropiedad, antiguedad, habitaciones;//tipo es 1 casa o 2 departamento
  string calle, numero, dniDueno;//calle y numero son cadenas de 50 y 6 caracteres respectivamente, dniDueno de 12 caracteres
  float superficieTotal, precioVenta, precioAlquiler;
  
  Inmueble objInm;
  //for 10
   
  cout << "Ingrese el ID del Inmueble: "; cin >> inmueble;
  cout << "Ingrese el tipo de propiedad: "; cin >> tipoPropiedad;
  
  cin.ignore();
  cout << "Ingrese la calle: "; getline(cin, calle); 
  cout << "Ingrese el numero: "; getline(cin, numero); 
  cout << "Ingrese la antiguedad: "; cin >> antiguedad; 
  cout << "Ingrese la superficie total: "; cin >> superficieTotal; 
  cout << "Ingrese el numero de habitaciones: "; cin >> habitaciones; 
  cout << "Ingrese el precio de venta: "; cin >> precioVenta; 
  cout << "Ingrese el precio de alquiler: "; cin >> precioAlquiler;
  cin.ignore(); 
  cout << "Ingrese el DNI del dueno: "; getline(cin, dniDueno);

  
  objInm = Inmueble(inmueble, tipoPropiedad, calle, numero, antiguedad, superficieTotal, habitaciones, precioVenta, precioAlquiler, dniDueno, true);
  
  if( _inmuebleArchivo.agregarRegistro(objInm)){
    cout << "Inmueble cargado con exito" << endl;
  }else{
    cout << "No se pudo cargar el Inmueble" << endl;
  }
}



void InmuebleManager::listarTodosLeyendoDeAUno(){
  Inmueble objInm;

  int cantidad =  _inmuebleArchivo.getCantidadRegistros();
  cout << "La cantidad todal de registros es: " << cantidad << endl;
  for(int i = 0; i < cantidad; i++){
    objInm =  _inmuebleArchivo.leerUnRegistro(i);//Cliente leer un reg (int pos)
    if(objInm.getEstado() == true){
      mostrarInmueble(objInm);
    }
  }  
}


void InmuebleManager::mostrarInmueble(Inmueble reg){
  cout << "*************************" << endl;
  cout << "Codigo del Inmueble: " << reg.getCodigo() << endl;
  cout << "Tipo de propiedad: " << reg.getTipoPropiedad() << endl;  
  cout << "Calle: " << reg.getCalle() << endl;
  cout << "Numero: " << reg.getNumero() << endl;
  cout << "Antiguedad: " << reg.getAntiguedad() << endl;
  cout << "Superficie total: " << reg.getSuperficieTotal() << endl;
  cout << "Numero de habitaciones: " << reg.getHabitaciones() << endl;
  cout << "Precio de venta: " << reg.getPrecioVenta() << endl;
  cout << "Precio de alquiler: " << reg.getPrecioAlquiler() << endl;
  cout << "DNI del dueno: " << reg.getDniDueno() << endl;
  cout << "Estado del Inmueble: " << reg.getEstado() << endl;
  cout << "*************************" << endl;
  cout << endl;
}

void InmuebleManager::modificarInmueble(){
  int idParaModificar;
  Inmueble reg;

  cout << "Ingrese el ID del Inmueble a modificar: "; cin >> idParaModificar;

  int indice = _inmuebleArchivo.buscarPorId(idParaModificar);
 
  if(indice != -1){
    reg = _inmuebleArchivo.leerUnRegistro(indice);//cargo en memoria
    
    reg.toCSV();//muestro

    volverACargarSinId(reg);
    if(_inmuebleArchivo.modificarPorIndice(reg, indice)){
      cout << "Inmueble modificado" << endl;
    }else{
      cout << "No se pudo modificar el Inmueble" << endl;
    }

  }else{
    cout << "No se encontro el Inmueble" << endl;
  }
}

void InmuebleManager::volverACargarSinId(Inmueble &reg){
  int inmueble, tipoPropiedad, antiguedad, habitaciones;//tipo es 1 casa o 2 departamento
  string calle, numero, dniDueno;//calle y numero son cadenas de 50 y 6 caracteres respectivamente, dniDueno de 12 caracteres
  float superficieTotal, precioVenta, precioAlquiler;

  //cout << "Ingrese el ID del Inmueble: "; cin >> inmueble;
  cout << "Ingrese el tipo de propiedad: "; cin >> tipoPropiedad;
  
  cin.ignore();
  cout << "Ingrese la calle: "; getline(cin, calle); 
  cout << "Ingrese el numero: "; getline(cin, numero); 
  cout << "Ingrese la antiguedad: "; cin >> antiguedad; 
  cout << "Ingrese la superficie total: "; cin >> superficieTotal; 
  cout << "Ingrese el numero de habitaciones: "; cin >> habitaciones; 
  cout << "Ingrese el precio de venta: "; cin >> precioVenta; 
  cout << "Ingrese el precio de alquiler: "; cin >> precioAlquiler;
  cin.ignore(); 
  cout << "Ingrese el DNI del dueno: "; getline(cin, dniDueno);

  reg.setTipoPropiedad(tipoPropiedad);
  reg.setCalle(calle);
  reg.setNumero(numero);
  reg.setAntiguedad(antiguedad);
  reg.setSuperficieTotal(superficieTotal);
  reg.setHabitaciones(habitaciones);
  reg.setPrecioVenta(precioVenta);
  reg.setPrecioAlquiler(precioAlquiler);
  reg.setDniDueno(dniDueno);
}

void InmuebleManager::modificarPrecioInmueble(){
  int idParaModificar;
  int nuevoPrecio;
  Inmueble reg;

  cout << "Ingrese el ID del Inmueble para modificar su precio: "; cin >> idParaModificar;

  int indice = _inmuebleArchivo.buscarPorId(idParaModificar);
  if(indice != -1){
    reg = _inmuebleArchivo.leerUnRegistro(indice);//cargo en memoria

    cout << "Calle: " << reg.getCalle() << endl;
    cout << "Precio de venta: " << reg.getPrecioVenta() << endl;
    system("pause");

    cout << "Ingrese el nuevo precio de venta: "; cin >> nuevoPrecio;
    reg.setPrecioVenta(nuevoPrecio);

    if(_inmuebleArchivo.modificarPorIndice(reg, indice)){
      cout << "Inmueble modificado" << endl;
    }else{
      cout << "No se pudo modificar el Inmueble" << endl;
    }
  }
}

void InmuebleManager::eliminarLogico(){
  int idEliminar;
  bool eliminarSiNo;
  Inmueble obj;
  cout << "Ingrese el ID del Inmueble a eliminar: "; cin >> idEliminar;

  int indice = _inmuebleArchivo.buscarPorId(idEliminar);
 
  if(indice != -1){
    obj = _inmuebleArchivo.leerUnRegistro(indice);
    cout << "Datos del Inmueble: " << obj.toCSV() << endl; // Luego mostrar
    

    cout << "Desea eliminar el Inmueble? (1=Si/0=No): "; cin >> eliminarSiNo;

    if(eliminarSiNo){
      obj.setEstado(false);//cambia el estado a false para poder eliminarlo logico

      if(_inmuebleArchivo.modificarPorIndice(obj, indice)){
        cout << "Se elimino el Inmueble" << endl;
      }else{
        cout << "No se pudo eliminar el Inmueble" << endl;
      }

    }else{
      cout << "No se elimino el Inmueble" << endl;
    }
  }  
}

void InmuebleManager::reactivarInmueble(){
  int idReactivar;
  bool reactivarSiNo;
  Inmueble obj;
  cout << "Ingrese el ID del Inmueble a reactivar: "; cin >> idReactivar;

  int indice = _inmuebleArchivo.buscarPorId(idReactivar);

  if(indice != -1){
    obj = _inmuebleArchivo.leerUnRegistro(indice);
    cout << "Datos del Inmueble: " << obj.toCSV();

    cout << "Desea reactivar el Inmueble? (1=Si/0=No): "; cin >> reactivarSiNo;

    if(reactivarSiNo){
      obj.setEstado(true);//cambia el estado a true para poder reactivarlo

      if(_inmuebleArchivo.modificarPorIndice(obj, indice)){
        cout << "Se reactivo el Inmueble" << endl;
      }else{
        cout << "No se pudo reactivar el Inmueble" << endl;
      }
    }else{
      cout << "No se reactivo el Inmueble" << endl;
    }
  }
}



// void InmuebleManager::mostrarCantidadRegistros(){
//  InmuebleArchivo objArch;
//  int cantRegistros = objArch.getCantidadRegistros();
//  cout << "Cantidad de Registros: " << cantRegistros << endl;  
// }



// void InmuebleManager::listarContratados(){
//   InmuebleArchivo objtArch;
//   Inmueble reg;

//   int cantidadContratados = objtArch.getCantidadRegistros();

//   cout << "Los contratados son: " << endl;
//   for(int i = 0; i < cantidadContratados; i++){
//     reg = objtArch.leerUnRegistro(i);
//     if(reg.getContratado() == true){
//       cout << "Nombre: " << reg.getNombres() << endl;
//       cout << "Apellidos: " << reg.getApellidos() << endl;
//       cout << endl;
//     }  
//   }  
// }

void InmuebleManager::buscarPorCalle(){
  string calle;
  Inmueble obj;

  cin.ignore();
  cout << "Ingrese la calle: "; getline(cin, calle);

  int pos = _inmuebleArchivo.buscarPorCalle(calle);
  if(pos != -1){
    obj = _inmuebleArchivo.leerUnRegistro(pos);
    cout << "El Inmueble es: " << endl;
    cout << obj.toCSV() << endl;
  }else{
    cout << "No se encontro el Inmueble" << endl;
  }
}

void InmuebleManager::buscarPorRangoPrecio(){
  float precioMinimo, precioMaximo;
  cout << "Ingrese el precio minimo: "; cin >> precioMinimo;
  cout << "Ingrese el precio maximo: "; cin >> precioMaximo;

  int pos = _inmuebleArchivo.buscarPorRangoPrecio(precioMinimo, precioMaximo);

  if(pos != -1){
    Inmueble obj = _inmuebleArchivo.leerUnRegistro(pos); 
    cout << obj.toCSV() << endl; 
  }else{
    cout << "No se encontro el Inmueble" << endl;
  }
}


// void InmuebleManager::mostrarPorPuestoYExperiencia(){
//   string puesto;
//   int aniosExp;
//   Inmueble obj;
//   InmuebleArchivo objtArch;

//   cin.ignore();
//   cout << "Ingrese Puesto: "; getline(cin, puesto);
//   cout << "Ingrese Anios de experiencia: "; cin >> aniosExp;

//   int pos = objtArch.buscarPorPuestoYExperiencia(puesto, aniosExp);
//   if(pos != -1){
//     obj = objtArch.leerUnRegistro(pos);
//     cout << "El Inmueble es: " << endl;
//     cout << obj.toCSV() << endl;
//   }else{
//     cout << "No se encontro el Inmueble" << endl;
//   }
// }





// void InmuebleManager::listarTodosLeyenedoConVecDin(){
//   InmuebleArchivo objtArch;

//   int cantidadTotal = objtArch.getCantidadRegistros();
//   Inmueble *vDinPos = nullptr;
//   vDinPos = new Inmueble[cantidadTotal];
//   if(vDinPos == nullptr){
//     cout << "No se pudo crear el vector dinamico" << endl;
//     return;
//   }

//   objtArch.leerTodosLeyenedoConVecDin(vDinPos, cantidadTotal);

//   for(int i = 0; i < cantidadTotal; i++){
//     if(vDinPos[i].getContratado()){
//       cout << vDinPos[i].toCSV() << endl;
//     }
//   }  

//   delete [] vDinPos;
// }



// */