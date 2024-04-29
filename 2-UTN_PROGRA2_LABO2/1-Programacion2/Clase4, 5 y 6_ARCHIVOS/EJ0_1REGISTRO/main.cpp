#include <iostream>

using namespace std;
#include "Clases.h"



bool grabarRegistroAlumno(Alumno obj){//recibe obje cargado => kloster lo carga dentro
  FILE *p;
  p = fopen("alumnos.dat", "ab");
  if(p == NULL){
    return false;
  }
  bool escribio = fwrite(&obj, sizeof (Alumno), 1, p);
  fclose(p);
  return escribio;
}

bool cargarAlumno(){ // => Cargar utiliza grabar('ab')
  Alumno obj;
  cout << "INGRESE LOS VALORES DEL REGISTRO" << endl;
  obj.Cargar();
  return grabarRegistroAlumno(obj);
}  

bool listarRegistroAlumno(){
  Alumno obj;
  FILE *p;
  p = fopen("alumnos.dat", "rb");
  if(p == NULL){    
    return false;
  }
  while(fread(&obj, sizeof(Alumno), 1, p)== 1 && obj.getEstado() == true){
    obj.Mostrar();
    cout << endl;
  }
  fclose(p);

  return true;
}

void borrarArchivo(){
  FILE *p;
  p = fopen("alumnos.dat","wb");
  if(p==NULL){
      cout << "No se pudo abrir el archivo crearArchivo" << endl;
      exit(1);
  }

  fclose(p);
}

/// PUNTO4 y 5
int contarRegistros(){//cuantos registros tengo
  FILE *p;
  p=fopen("alumnos.dat", "rb");
  if(p==NULL) return -1;
  fseek(p, 0,2); //cursor al final del codigo
  int tam=ftell(p); //del principio hasta donde esta el cursor
  fclose(p);
  return tam/sizeof(Alumno); 
  //calculo para devolver la cantidad => si alumno pesa 30 y tengo 3 registros, devolveria 3(90/30)
}

Alumno leerRegistro(int pos){//la posicion que quiero modificar
  Alumno reg;
  FILE *p;
  p=fopen("alumnos.dat", "rb");
  if(p==NULL) return reg;

  fseek(p, sizeof reg*pos, 0); //cursor a la posicion
  fread(&reg, sizeof reg, 1, p); //leer el registro

  fclose(p);
  return reg;
}

bool reemplazarRegistro(Alumno reg, int posicionAReemplazar){
  FILE *p = fopen("alumnos.dat", "rb+");
  if (p == NULL){return false;}

  fseek(p, posicionAReemplazar * sizeof(Alumno), 0); 
  bool pudoEscribir = fwrite(&reg, sizeof(Alumno), 1, p); //escribir el registro
  fclose(p);
  return pudoEscribir;
}

void punto4Simple(){//uso de leer + reemplazar
  Alumno obj;
  int posicionRegistroABorrar;
  cout << "Ingrese la posicion del registro a eliminar (logico): ";
  cin >> posicionRegistroABorrar;
  obj = leerRegistro(posicionRegistroABorrar-1); // si ingrese un 5 le resto 1 para ir de 0 a 4
  obj.setEstado(false); //ponerlo en false pero en MEMORIA  
  reemplazarRegistro(obj, posicionRegistroABorrar-1); //AHORA LO PASA AL ARCHIVO
}

void punto5Complejo(){//uso de contar + leer + reemplazar 
  Alumno obj;
  int legajo;
  cout << "Ingrese el legajo que va a dar de baja: ";
  cin >> legajo;
  
  int tam = contarRegistros();
  for(int i=0; i<tam; i++){
    obj = leerRegistro(i); //lee el registro en el que el usuario ingresa el legajo
    if(obj.getLegajo() == legajo){
      obj.setEstado(false); //LO EN MEMORIA
      reemplazarRegistro(obj, i); // LO PASE AL ARCHIVO
    }
  }
}

void Menu(){
  int opc;
  Alumno objA;
  while (true)
  {
    system("cls");
    cout << "MENU ALUMNOS" << endl;
    cout << "1-AGREGAR/GRABAR REGISTRO" << endl;
    cout << "2-MOSTRAR/LISTAR REGISTRO" << endl;
    cout << "3-ELIMINA CON WB" << endl;
    cout << "4-ELIMINA LOGICA SIMPLE" << endl;
    cout << "5-ELIMINA LOGICA COMPLEJA" << endl;
    cout << "0-SALIR" << endl;
    cout << "OPCION: ";
    cin >> opc;
    system("cls");
    switch (opc)
    {
      case 1:
        if(cargarAlumno()) {
          cout << "Registro agregado correctamente." << endl << endl;
        } else {
          cout << "Error al agregar el registro." << endl;
        }
        break;
      case 2:
        if(!listarRegistroAlumno()){
          cout << "ERROR AL LEER ARCHIVO ALUMNOS" << endl;
        }
        break;
      case 3:
        borrarArchivo();
        break;
      case 4:
        punto4Simple();
        break;
      case 5:
        punto5Complejo();
        break;
      case 0:
        return;
      default:
        cout << "OPCION INCORRECTA" << endl;
        system("pause");
        break;
    }
    system("pause");
  }
}

int main(){

  Menu();
  return 0;
}