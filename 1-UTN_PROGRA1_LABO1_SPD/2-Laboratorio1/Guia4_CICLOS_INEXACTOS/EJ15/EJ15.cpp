#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{ 
 int opcion;
 float medidaMetros;
    
  do {
      cout << "Menu principal" << endl;
      cout << "-----------------------------" << endl;
      cout << "1 - Ingresar medida en metros" << endl;
      cout << "2 - Convertir a centimetros" << endl;
      cout << "3 - Convertir a kilometros" << endl;
      cout << "4 - Convertir a pulgadas" << endl;
      cout << "5 - Convertir a pies" << endl;
      cout << "-----------------------------" << endl;
      cout << "0 - Salir del programa" << endl;
      cout << "Ingrese opcion: ";
      cin >> opcion;
      
      switch (opcion) {
          case 1:
              cout << "Ingrese la medida en metros: ";
              cin >> medidaMetros;
              break;
          case 2:
              cout << "Medida en centimetros: " << medidaMetros * 100 << " cm" << endl;
              break;
          case 3:
              cout << "Medida en kilometros: " << medidaMetros / 1000 << " km" << endl;
              break;
          case 4:
              cout << "Medida en pulgadas: " << medidaMetros * 39.3701 << " in" << endl;
              break;
          case 5:
              cout << "Medida en pies: " << medidaMetros * 3.28084 << " ft" << endl;
              break;
          case 0:
              cout << "Saliendo del programa." << endl;
              break;
          default:
              cout << "Opción no valida. Intente de nuevo." << endl;
      }
      
  } while (opcion != 0);

 return 0;

}