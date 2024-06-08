/*20 Hacer un programa en el que se ingrese la edad y altura de 5 personas. Luego,
calcular e informar:
punto a) La cantidad de personas mayores a 30 años que midan más de 1.8
metros.
punto b)  El promedio de altura de las personas mayores a 30 años.
punto c) La cantidad de personas con altura entre 1.7 y 1.8 (ambos inclusive)
punto d) La cantidad de personas cuya edad sea de 20, 30 o 40 años.*/

#include <iostream>
using namespace std;


int main(){
    int e1,e2,e3,e4,e5, mayores30A180 = 0, altura170A180=0, personas203040=0, mayores30=0;
    float a1,a2,a3,a4,a5, sumaAlturas;

  cout << "Ingrese la edad de la Persona 1: ";
  cin >> e1;

  cout << "Ingrese la altura (en metros) de la Persona 1: ";
  cin >> a1;

  cout << "Ingrese la edad de la Persona 2: ";
  cin >> e2;

  cout << "Ingrese la altura (en metros) de la Persona 2: ";
  cin >> a2;

  cout << "Ingrese la edad de la Persona 3: ";
  cin >> e3;

  cout << "Ingrese la altura (en metros) de la Persona 3: ";
  cin >> a3;

  cout << "Ingrese la edad de la Persona 4: ";
  cin >> e4;

  cout << "Ingrese la altura (en metros) de la Persona 4: ";
  cin >> a4;

  cout << "Ingrese la edad de la Persona 5: ";
  cin >> e5;

  cout << "Ingrese la altura en metros de la Persona 5: ";
  cin >> a5;

  // PUNTO A
  if (e1 > 30 && a1 > 1.80)
    mayores30A180 ++;

  if (e2 > 30 && a2 > 1.80)
    mayores30A180++;

  if (e3 > 30 && a3 > 1.80)
    mayores30A180++;

  if (e4 > 30 && a4 > 1.80)
    mayores30A180++;

  if (e5 > 30 && a5 > 1.80)
    mayores30A180++;
  // PUNTO B

  if (e1 > 30){
    sumaAlturas += a1;
    mayores30 ++;
  }

  if(e2 > 30){
    sumaAlturas += a2;
    mayores30 ++;
  }

 if (e3 > 30){
    sumaAlturas += a3;
    mayores30 ++;
  }

  if (e4 > 30){
    sumaAlturas += a4;
    mayores30 ++;
  }

 if (e5 > 30){
   sumaAlturas += a5;
    mayores30 ++;
  };

    // PUNTO C
  if (a1 >= 1.70 && a1 <= 1.80)
    altura170A180 ++;

  if (a2 >= 1.70 && a2 <= 1.80)
    altura170A180 ++;

  if (a3 >= 1.70 && a3 <= 1.80)
    altura170A180 ++;

  if (a4 >= 1.70 && a4 <= 1.80)
    altura170A180 ++;

  if (a5 >= 1.70 && a5 <= 1.80)
   altura170A180 ++;

   // PUNTO D

  if (e1 == 20 || e1 == 30 || e1 == 40)
    personas203040 ++;

  if (e2 == 20 || e2 == 30 || e2 == 40)
    personas203040 ++;

  if (e3 == 20 || e3 == 30 || e3 == 40)
    personas203040 ++;

  if (e4 == 20 || e4 == 30 || e4 == 40)
    personas203040 ++;

  if (e5 == 20 || e5 == 30 || e5 == 40)
    personas203040 ++;


 cout << "--------------------------------------------------------------------------------------" << endl;
  if (mayores30 > 0) {
    cout << "Cantidad de personas con mas de 30 anios y altura mayor a 1.80 metros: " << mayores30A180 << endl;
    cout << "El promedio de altura de las personas mayores a 30 anios             : " << sumaAlturas/mayores30 << endl;
  } else {
     cout << "No hay personas mayores a 30 anios para calcular cuantas miden mas de 1.8 metros, ni el promedio de altura" << endl;

  }
    cout << "Cantidad de personas con una altura entre 1.70 y 1.80 metros          : " << altura170A180 << endl;
    cout << "Cantidad de personas con una edad de 20, 30 o 40 anios                : " << personas203040 << endl;
cout << "--------------------------------------------------------------------------------------" << endl;


return 0;
}
