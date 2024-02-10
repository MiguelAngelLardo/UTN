#include <iostream>
#include <iomanip> // Necesario para std::fixed y std::setprecision
using namespace std;

int main(int argc, char const *argv[])
{
  int edad1, edad2, edad3, edad4, edad5, contadorMayor30Mas180 = 0, contadorAltura170A180 = 0, contadorEDAD203040 = 0, contadorMayor30 = 0;
  float altura1, altura2, altura3, altura4, altura5, acumuladorAlturaMas30 = 0;

  cout << "Ingrese la edad de la Persona 1: ";
  cin >> edad1;
  
  cout << "Ingrese la altura de la Persona 1 (METROS): ";
  cin >> altura1;

  cout << "Ingrese la edad de la Persona 2: ";
  cin >> edad2;
  
  cout << "Ingrese la altura de la Persona 2 (METROS): ";
  cin >> altura2;

  cout << "Ingrese la edad de la Persona 3: ";
  cin >> edad3;
  
  cout << "Ingrese la altura de la Persona 3 (METROS): ";
  cin >> altura3;

  cout << "Ingrese la edad de la Persona 4: ";
  cin >> edad4;
  
  cout << "Ingrese la altura de la Persona 4 (METROS): ";
  cin >> altura4;

  cout << "Ingrese la edad de la Persona 5: ";
  cin >> edad5;
  
  cout << "Ingrese la altura de la Persona 5 (METROS): ";
  cin >> altura5;

  if (edad1 > 30 && altura1 > 1.80)
    contadorMayor30Mas180 ++;
  
  if (edad2 > 30 && altura2 > 1.80) 
    contadorMayor30Mas180++;
  
  if (edad3 > 30 && altura3 > 1.80)
    contadorMayor30Mas180++;

  if (edad4 > 30 && altura4 > 1.80) 
    contadorMayor30Mas180++;
  
  if (edad5 > 30 && altura5 > 1.80) 
    contadorMayor30Mas180++;

  if (altura1 >= 1.70 && altura1 <= 1.80)
    contadorAltura170A180 ++;
  
  if (altura2 >= 1.70 && altura2 <= 1.80)
    contadorAltura170A180 ++;
   
  if (altura3 >= 1.70 && altura3 <= 1.80)
    contadorAltura170A180 ++;
  
  if (altura4 >= 1.70 && altura4 <= 1.80)
    contadorAltura170A180 ++;
  
  if (altura5 >= 1.70 && altura5 <= 1.80)
    contadorAltura170A180 ++;

  if (edad1 == 20 || edad1 == 30 || edad1 == 40)
    contadorEDAD203040 ++;  
  
  if (edad2 == 20 || edad2 == 30 || edad2 == 40)
    contadorEDAD203040 ++;   

  if (edad3 == 20 || edad3 == 30 || edad3 == 40)
    contadorEDAD203040 ++;

  if (edad4 == 20 || edad4 == 30 || edad4 == 40)
    contadorEDAD203040 ++;
  
  if (edad5 == 20 || edad5 == 30 || edad5 == 40)
    contadorEDAD203040 ++;
  
  if (edad1 > 30){
    acumuladorAlturaMas30 += altura1;
    contadorMayor30 ++;
  }

  if(edad2 > 30){
    acumuladorAlturaMas30 += altura2;
    contadorMayor30 ++;
  }

 if (edad3 > 30){
    acumuladorAlturaMas30 += altura3;
    contadorMayor30 ++;
  }
  
  if (edad4 > 30){
    acumuladorAlturaMas30 += altura3;
    contadorMayor30 ++;
  }
 
 if (edad5 > 30){
    acumuladorAlturaMas30 += altura5;
    contadorMayor30 ++;
  }
  
  cout << "Cantidad de personas con mas de 30 anios y altura mayor a 1.80 metros: " << contadorMayor30Mas180 << endl;
  cout << "Cantidad de personas con una altura entre 1.70 y 1.80 metros: " << contadorAltura170A180 << endl;
  cout << "Cantidad de personas con una edad de 20, 30 o 40 anos: " << contadorEDAD203040 << endl;
  if (contadorMayor30 > 0) {
    cout << "El promedio de altura de las personas mayores a 30 anios: " << fixed << setprecision(2) << acumuladorAlturaMas30 / contadorMayor30 << endl;
  } else {
     cout << "No hay personas mayores a 30 anios para calcular el promedio de altura." << endl;
  }
  
  return 0;
}