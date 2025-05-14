#include <iostream>

using namespace std;

int main (){
  int mesAdopcion;
  int tipoAnimal;//10-15
  int edad;
  int tipoVivienda;//1-5

  int vAnimalCont[6] = {};
  float vAnimalPromEdadAdoptantes[6] = {};
  int mAnimalviviendaCont[6][5] = {};


  cout << "Ingrese mes de adopcion: ";
  cin >> mesAdopcion;

  while (mesAdopcion != 0){
    cout << "Ingrese tipo de animal: ";
    cin >> tipoAnimal;
    cout << "Ingrese edad del adoptante: ";
    cin >> edad;
    cout << "Ingrese tipo de vivienda: ";
    cin >> tipoVivienda;

    vAnimalCont[tipoAnimal - 10]++;//pto A

    vAnimalPromEdadAdoptantes[tipoAnimal - 10] += edad;//pto B

    mAnimalviviendaCont[tipoAnimal - 10][tipoVivienda - 1]++;//pto C   
   
    cout << "Ingrese mes de adopcion: ";
    cin >> mesAdopcion;
  }



  cout << endl;
  int maxIndice = 0;
  for (int i = 1; i < 6; i++){
    if (vAnimalCont[i] > vAnimalCont[maxIndice]){
      maxIndice = i;      
    }  
  }  
  cout << "El tipo de animal mas adoptado es: " << maxIndice + 10 << " con " << vAnimalCont[maxIndice] << endl;

  cout << "Promedio de edad de los adoptantes de cada animal: " << endl;
  for (int i = 0; i < 6; i++){
    cout <<"Animal " << i + 10 << ": " << vAnimalPromEdadAdoptantes[i] / vAnimalCont[i] << endl;
  }

  cout << "Cantidad por animal y tipo de vivienda: " << endl;
  for (int i = 0; i < 6; i++){
    cout << "Animal " << i + 10 << ": " << endl;
    for (int j = 0; j < 5; j++){
      cout << "Vivienda " << j + 1 << ": #" << mAnimalviviendaCont[i][j] << endl;
    }
  }  





  return 0;
}

