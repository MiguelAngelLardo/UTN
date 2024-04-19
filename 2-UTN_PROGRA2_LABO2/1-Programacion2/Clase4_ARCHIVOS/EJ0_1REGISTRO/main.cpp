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

bool cargarAlumno(){
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
  while(fread(&obj, sizeof(Alumno), 1, p)== 1){
    obj.Mostrar();
    cout << endl;
  }
  fclose(p);

  return true;
}

int main(){
  int opc;
  while (true)
  {
    system("cls");
    cout << "MENU ALUMNOS" << endl;
    cout << "1-AGREGAR/GRABAR REGISTRO" << endl;
    cout << "2-MOSTRAR/LISTAR REGISTRO" << endl;
    cout << "3-ELIMINA CON WB" << endl;
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
        break;

      case 0:
        return 0;

      default:
        cout << "OPCION INCORRECTA" << endl;
        system("pause");
        break;
    }
    system("pause");




  }
  












  return 0;
}