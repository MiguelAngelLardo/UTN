#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{
  const int CATEGORIA1 = 38000, CATEGORIA2 = 70000, CATEGORIA3 = 105000;

  int categoria, antiguedad, empleados = 50;
  int empleadosCategoria1 = 0,empleadosCategoria2 = 0, empleadosCategoria3 = 0; //A)
  int sueldo, totalSueldoCategoria1 = 0, totalSueldoCategoria2 = 0, totalSueldoCategoria3 = 0; //B)
  int sueldoMaximoDeLos3 = -1, categoriaMaximoSueldo = 0;

  cout << "------restan " << empleados << " empleados------" << endl;
  cout << "Ingrese la categoria(1, 2, 3): ";
  cin >> categoria;
  cout << "Ingrese la antiguedad: ";
  cin >> antiguedad;

  while(categoria != 0)
  {
    empleados --;
    switch (categoria)
    {
      case 1:
        empleadosCategoria1 ++;
        sueldo = CATEGORIA1 + (antiguedad * 1200);
        totalSueldoCategoria1 += sueldo; 
      break;
      case 2:
        empleadosCategoria2 ++;  
        sueldo = CATEGORIA2 + (antiguedad * 1200);
        totalSueldoCategoria2 += sueldo; 
      break;
      case 3:
        empleadosCategoria3 ++; 
        sueldo = CATEGORIA3 + (antiguedad * 1200);
        totalSueldoCategoria3 += sueldo;    
      break;
    }

    if(sueldo > sueldoMaximoDeLos3){
      sueldoMaximoDeLos3 = sueldo;   
      categoriaMaximoSueldo = categoria;
      cout << "Categoria maximo sueldo: " << categoriaMaximoSueldo << endl;
    }

    cout << "------restan " << empleados << " empleados------" << endl;
    if (empleados > 0) {
      cout << "Ingrese la categoria(1, 2, 3): ";
      cin >> categoria;
      if (categoria != 0) {
        cout << "Ingrese la antiguedad: ";
        cin >> antiguedad;
      }
    }
  } 

  cout << endl << "Empleados por categoria: " << endl;
  cout << "Categoria 1: " << empleadosCategoria1 << endl;
  cout << "Categoria 2: " << empleadosCategoria2<< endl;
  cout << "Categoria 3 " << empleadosCategoria3 << endl << endl;

  cout << "Total sueldos por categoria: " << endl;
  cout << "Total sueldo Categoria 1: " << totalSueldoCategoria1 << endl;
  cout << "Total sueldo Categoria 2: " << totalSueldoCategoria2<< endl;
  cout << "Total sueldo Categoria 3: " << totalSueldoCategoria3 << endl << endl;

  cout << "Sueldo promedio: " << (totalSueldoCategoria1 + totalSueldoCategoria2 + totalSueldoCategoria3) / 3.0f << endl;

  cout << "Sueldo maximo de los 3: " << sueldoMaximoDeLos3 << ". Es de la categoria: " << categoriaMaximoSueldo;

 return 0;

}