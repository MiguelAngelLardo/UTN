#include <iostream>

using namespace std;
/*
3- 🧾 Actividad: Registro de Asistencia con Memoria Dinámica
Se está llevando a cabo un evento donde es necesario registrar la asistencia de los participantes.
Para ello, se te pide desarrollar un programa para almacenar la información de asistencia.

El sistema debe ofrecer el siguiente menú:
1. Crear asistentes: Solicita al usuario la cantidad total de asistentes esperados.
2. Marcar asistencia: permite ingresar el número de asistente (del 1 al N) y lo marca como asistió.
3. Mostrar estado de asistencia: muestra la lista de asistentes, indicando por cada uno si asistió o no. 
El número de asistente debe mostrarse junto al estado:
○ Ejemplo: 
Asistente 1: Asistió Asistente 2: No asistió
4. Salir: fi naliza el programa.
*/

bool *crearAsistentes(int &nAsistente);
void marcarAsistencias(bool vDinAsistentes[], int size);
void mostrarAsistencias(bool vDinAsistentes[], int size);

int main(){
  int opcion, numAsistentes;
  bool *vDinAsistentes = nullptr;

  do{
    system("cls");
    cout << "1. Crear asistentes: Solicita al usuario la cantidad total de asistentes esperados." << endl;
    cout << "2. Marcar asistencia: permite ingresar el numero de asistente (del 1 al N) y lo marca como asistiu." << endl;
    cout << "3. Mostrar estado de asistencia: muestra la lista de asistentes, indicando por cada uno si asistiu o no. El número de asistente debe mostrarse junto al estado:" << endl;
    cout << "4. Salir: finaliza el programa." << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:{
      if(vDinAsistentes != nullptr) delete[] vDinAsistentes;
      vDinAsistentes = crearAsistentes(numAsistentes);
    }break;

    case 2:{
      if (vDinAsistentes == nullptr) {
        cout << "Primero crea los asistentes (opcion 1).\n";
        system("pause");
    } else {
        marcarAsistencias(vDinAsistentes, numAsistentes);
    }
    }break;
    case 3:{
      if(vDinAsistentes == nullptr) {
        cout << "Primero crea los asistentes (opcion 1).\n";
      } else {
        mostrarAsistencias(vDinAsistentes, numAsistentes);
      }  
    }break;

    }
  
  }while(opcion!=4);
  delete[] vDinAsistentes; 
  return 0;
}

bool *crearAsistentes(int &nAsistente){

  bool *vDinAsistentes = nullptr;
  cout << "Ingrese la cantidad de asistentes: ";
  cin >> nAsistente;

  vDinAsistentes = new bool[nAsistente];

  if(vDinAsistentes == nullptr) exit(1);

  for(int i = 0; i < nAsistente; i++){
    vDinAsistentes[i] = false;
  }

  return vDinAsistentes;
}

void marcarAsistencias(bool vDinAsistentes[], int size){
  int nAsistio;
  cout << "Marca el numero del asistente para marcar su asistencia (sale con 0)" << endl;
  
  cout << "Asistio el asistente: ";
  cin >> nAsistio;

  while(nAsistio !=0){
    if(nAsistio < 1 || nAsistio > size){
      cout << "Numero invalido" << endl;
    }else{
      vDinAsistentes[nAsistio-1] = true;
    }

    cout << "Asistio el asistente: ";
    cin >> nAsistio;
  }
  
}
  
void mostrarAsistencias(bool vDinAsistentes[], int size){
  for(int i = 0; i < size; i++){
    (vDinAsistentes[i] == true) ? cout << "Asistente " << i+1 << ": Asistio" << endl : cout << "Asistente " << i+1 << ": No asistio" << endl;
  }  
  system("pause");
}