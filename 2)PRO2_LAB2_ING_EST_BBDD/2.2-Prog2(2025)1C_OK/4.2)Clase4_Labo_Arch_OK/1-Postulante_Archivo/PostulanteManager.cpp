#include <iostream>
#include <string>
#include "PostulanteArchivo.h"
#include "PostulanteManager.h"
using namespace std;


void PostulanteManager::menu(){
  
  int opcion;
  //system("cls");
  do{
    //system("cls");
    cout << "========================================================" << endl;
    cout << "        SISTEMA DE REGISTRO DE POSTULANTES" << endl;
    cout << "========================================================" << endl;
    cout << "1. Registrar nuevo postulante" << endl;
    cout << "2. Listar todos los postulantes" << endl;
    cout << "3. Buscar postulantes por puesto y experiencia" << endl;
    cout << "4. Mostrar postulantes contratados" << endl;
    cout << "5. Cantidad de Registros" << endl;
    cout << "6. Modificar postulante por ID" << endl;
    cout << "7. Listar todos usando vector dinamico" << endl;
    cout << "8. Eliminar postulante por ID" << endl;
    cout << "0. Salir" << endl;
    cout << "===============================" << endl;
    cout << "Ingrese una opcion: ";

    cin >> opcion;

    switch(opcion) 
    {
    case 1:
        cargarPostulante();
      break;
    case 2:
      listarTodosLeyendoDeAUno();
      break;
    case 3:
      mostrarPorPuestoYExperiencia();
      break;
    case 4:
      listarContratados();
      break;
    case 5:
      mostrarCantidadRegistros();
      break;
    case 6:{
      modificarPostulante();
    }break;
    case 7:{
      listarTodosLeyenedoConVecDin();
    }break;
    case 8:{
      eliminarLogico();
    }break;
    case 0:
      cout << "Saliendo..." << endl;
    break;
   }
    system("pause");
    cout << endl << endl;

  }while(opcion != 0);
}

void PostulanteManager::cargarPostulante(){
  int id, experiencia, edad;
  string nombres, apellidos, puesto;
  bool contratado;
  Postulante post;
  PostulanteArchivo objPosArch;

  id = objPosArch.crearNuevoIdAUtomatico();
  cout << "Ingrese ID: " <<  id << endl;
  cin.ignore();

  cout << "Ingrese Nombres: "; getline(cin, nombres); 
  cout << "Ingrese Apellidos: "; getline(cin, apellidos);
  
  cout << "Ingrese Edad: "; cin >> edad;
  cin.ignore();

  cout << "Ingrese Puesto: "; getline(cin, puesto);
  cout << "Ingrese Anios de experiencia: "; cin >> experiencia;
  cout << "Ingrese Contratado (1=Si/2=No): "; cin >> contratado;

  post = Postulante(id, apellidos, nombres, edad, puesto, experiencia, contratado);

  (objPosArch.agregarRegistro(post)) ? cout << "Postulante registrado" << endl : cout << "No se pudo registrar el postulante" << endl; 

}

void PostulanteManager::mostrarPostulante(Postulante reg){
  cout << "ID: " << reg.getId() << endl;
  cout << "Nombres: " << reg.getNombres() << endl;
  cout << "Apellidos: " << reg.getApellidos() << endl;
  cout << "Edad: " << reg.getEdad() << endl;
  cout << "Puesto: " << reg.getPuesto() << endl;
  cout << "Anios de experiencia: " << reg.getAniosExperiencia() << endl;
  cout << "Contratado: " << (reg.getContratado() ? "Si" : "No") << endl;
}


void PostulanteManager::mostrarCantidadRegistros(){
 PostulanteArchivo objPosArch;
 int cantRegistros = objPosArch.getCantidadRegistros();
 cout << "Cantidad de Registros: " << cantRegistros << endl;  
}

void PostulanteManager::listarTodosLeyendoDeAUno(){
  Postulante objPos;
  PostulanteArchivo objPostArch;

  int cantidad = objPostArch.getCantidadRegistros();
  cout << "La cantidad todal de registros es: " << cantidad << endl;
  for(int i = 0; i < cantidad; i++){
    objPos = objPostArch.leerUnRegistro(i);
    mostrarPostulante(objPos);
  }  
}

void PostulanteManager::listarContratados(){
  PostulanteArchivo objPostArch;
  Postulante reg;

  int cantidadContratados = objPostArch.getCantidadRegistros();

  cout << "Los contratados son: " << endl;
  for(int i = 0; i < cantidadContratados; i++){
    reg = objPostArch.leerUnRegistro(i);
    if(reg.getContratado() == true){
      cout << "Nombre: " << reg.getNombres() << endl;
      cout << "Apellidos: " << reg.getApellidos() << endl;
      cout << endl;
    }  
  }  
}

void PostulanteManager::mostrarPorPuestoYExperiencia(){
  string puesto;
  int aniosExp;
  Postulante objPos;
  PostulanteArchivo objPostArch;

  cin.ignore();
  cout << "Ingrese Puesto: "; getline(cin, puesto);
  cout << "Ingrese Anios de experiencia: "; cin >> aniosExp;

  int pos = objPostArch.buscarPorPuestoYExperiencia(puesto, aniosExp);
  if(pos != -1){
    objPos = objPostArch.leerUnRegistro(pos);
    cout << "El postulante es: " << endl;
    cout << objPos.toCSV() << endl;
  }else{
    cout << "No se encontro el postulante" << endl;
  }
}

void PostulanteManager::modificarPostulante(){
  int idParaModificar;
  Postulante reg;
  PostulanteArchivo objPostArch;

  cout << "Ingrese el ID del postulante a modificar: "; cin >> idParaModificar;

  int indice = objPostArch.buscarPorId(idParaModificar);
 
  if(indice != -1){
    reg = objPostArch.leerUnRegistro(indice);//cargo en memoria
    
    reg.toCSV();//muestro
    volverACargarSinId(reg);
    if(objPostArch.modificarPorIndice(reg, indice)){
      cout << "Postulante modificado" << endl;
    }else{
      cout << "No se pudo modificar el postulante" << endl;
    }

  }else{
    cout << "No se encontro el postulante" << endl;
  }
}

void PostulanteManager::volverACargarSinId(Postulante &reg){
  int  experiencia, edad;
  string nombres, apellidos, puesto;
  bool contratado;
  Postulante post;
  PostulanteArchivo objPosArch;

  cin.ignore();
  cout << "Ingrese Nombres: "; getline(cin, nombres); 
  cout << "Ingrese Apellidos: "; getline(cin, apellidos);
  
  cout << "Ingrese Edad: "; cin >> edad;
  cin.ignore();

  cout << "Ingrese Puesto: "; getline(cin, puesto);
  cout << "Ingrese Anios de experiencia: "; cin >> experiencia;
  cout << "Ingrese Contratado (1=Si/2=No): "; cin >> contratado;

  reg.setNombres(nombres);
  reg.setApellidos(apellidos);
  reg.setEdad(edad);
  reg.setPuesto(puesto);
  reg.setAniosExperiencia(experiencia);
  reg.setContratado(contratado);

}

void PostulanteManager::listarTodosLeyenedoConVecDin(){
  PostulanteArchivo objPostArch;

  int cantidadTotal = objPostArch.getCantidadRegistros();
  Postulante *vDinPos = nullptr;
  vDinPos = new Postulante[cantidadTotal];
  if(vDinPos == nullptr){
    cout << "No se pudo crear el vector dinamico" << endl;
    return;
  }

  objPostArch.leerTodosLeyenedoConVecDin(vDinPos, cantidadTotal);

  for(int i = 0; i < cantidadTotal; i++){
    if(vDinPos[i].getContratado()){
      cout << vDinPos[i].toCSV() << endl;
    }
  }  

  delete [] vDinPos;
}

void PostulanteManager::eliminarLogico(){
  int idEliminar;
  bool eliminarSiNo;
  Postulante objPos;
  PostulanteArchivo objPostArch;
  cout << "Ingrese el ID del postulante a eliminar: "; cin >> idEliminar;

  int indice = objPostArch.buscarPorId(idEliminar);

  if(indice != -1){
    objPos = objPostArch.leerUnRegistro(indice);
    objPos.toCSV();

    cout << "Desea eliminar el postulante? (1=Si/0=No): "; cin >> eliminarSiNo;

    if(eliminarSiNo){
      objPos.setContratado(false);//cambia el estado a false para poder eliminarlo logico

      if(objPostArch.modificarPorIndice(objPos, indice)){
        cout << "Se elimino el postulante" << endl;
      }else{
        cout << "No se pudo eliminar el postulante" << endl;
      }

    }else{
      cout << "No se elimino el postulante" << endl;
    }

  }  

}


