#include <iostream>

using namespace std;
/*
Crear un programa que contenga un menú con las siguientes opciones:
1- Cargar Vector: El programa debe solicitar al usuario la cantidad de elementos
que va a cargar, posteriormente se solicitara cuales son dichos números para
almacenarlos en un vector utilizando asignación dinámica de memoria.
2- Mostrar Vector: En caso de tener cargado el vector, debe mostrarlo por
pantalla.
3- Salir: Sale del programa (no olvidar liberar la memoria)
Pista: Recordar que se puede inicializar un puntero con el valor nullptr
*/

int* creaCargarVector(int &size);
void mostrarVector(int vDin[], int size);

int main (){
  int *vDinNumMain = nullptr;
  int tam;
  int opcion;

  do{

    cout << "1- Cargar Vector" << endl;
    cout << "2- Mostrar Vector" << endl;
    cout << "3- Salir" << endl;
    cin >> opcion;

    switch (opcion)
    {
      case 1:{
        if(vDinNumMain != nullptr) delete [] vDinNumMain;
        cout << "Ingrese tam: ";
        cin >> tam;
        vDinNumMain = creaCargarVector(tam);
      }break;
      
      case 2:{
        if(vDinNumMain == nullptr){
          cout << "No hay vector cargado, cargalo con opcion 1.\n" << endl;
        }else{
          mostrarVector(vDinNumMain, tam);
        }
      }break;
      case 3:{
        if(vDinNumMain == nullptr){
          cout << "No hay vector cargado, cargalo con opcion 1.\n" << endl;
        }else{
          delete [] vDinNumMain;
          vDinNumMain = nullptr;
          cout << "Vector liberado" << endl;
        }
      }break;
    }

  }while(opcion != 3);

  return 0;
}

int* creaCargarVector(int &size){
  int *vDinNum = nullptr;
  
  vDinNum = new int[size];

  if(vDinNum == nullptr)exit(1);

  for(int i = 0; i < size; i++){
    cout << "Ingrese numero: ";
    cin >> vDinNum[i];
  }  

  return vDinNum;
}

void mostrarVector(int vDin[], int size){
  for(int i = 0; i < size; i++){
    cout << vDin[i] << endl;
  }
}
