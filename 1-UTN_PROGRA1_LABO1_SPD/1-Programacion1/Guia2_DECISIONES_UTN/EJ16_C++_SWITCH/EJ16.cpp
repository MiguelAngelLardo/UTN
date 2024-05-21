#include <iostream>
using namespace std;

int main() {
  int nota1, nota2, nota3, nota4;
    
  cout << "Ingrese las cuatro notas de los exámenes: " << endl;
  cin >> nota1; 
  cin >> nota2;
  cin >> nota3;
  cin >> nota4;   
  
  int cantidadAprobados = 0;

  if (nota1 >= 4) {
      cantidadAprobados++;
  }
  if (nota2 >= 4) {
      cantidadAprobados++;
  }
  if (nota3 >= 4) {
      cantidadAprobados++;
  }
  if (nota4 >= 4) {
      cantidadAprobados++;
  }

  switch (cantidadAprobados) {
    case 4:
      if (nota1 >= 7 && nota2 >= 7 && nota3 >= 7 && nota4 >= 7) {
          cout << "Promociona" << endl;
      }else{
        cout << "Rinde examen final"; 
      }
      break;
    case 3:
      cout << "Rinde examen final" << endl;
      break;
    case 2:
      cout << "Recupera Parciales" << endl;
      break;
    case 1:
      cout << "Recupera Parciales" << endl;
      break;
    default:
      cout << "Recursa la materia" << endl;
      break;
  }

  return 0;
}