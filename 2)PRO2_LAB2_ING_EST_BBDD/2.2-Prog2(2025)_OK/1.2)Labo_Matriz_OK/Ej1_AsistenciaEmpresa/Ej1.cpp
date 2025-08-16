#include <iostream>

using namespace std;

/*
Una empresa lleva un registro de asistencia de sus 30 empleados. Cada vez que un empleado asiste al trabajo, 
se registra la siguiente información:
● Número de empleado (100 a 129)
● Mes (1 a 12)
● Día (1 a 31)
● Horas trabajadas en el día
Los registros finalizan cuando se ingresa un número de empleado igual a 0.

Al fi nalizar la carga de datos, se debe calcular:
1. Para cada mes del año, mostrar cuántos días tuvieron al menos un empleado presente.
2. Listar los días del año en los que ningún empleado trabajó.
3. Por cada empleado, indicar el número de empleado y la cantidad de horas trabajadas en total en el año.
*/

int main() {
  int numeroEmpleado;//0 a 29 => son 30
  int mes, dia, hsTrabajadas;
  
  //punto 1 y 2
  int mMesDiasCont[12][31] = {};

  //punto 3
  int vEmpleadosHsTrabajadas[30]={};

  cout << "Numero empleado: ";
  cin >> numeroEmpleado;

  while(numeroEmpleado != 0){
    cout << "ingrese el mes: ";
    cin >> mes;
    cout << "ingrese el dia: ";
    cin >> dia;
    cout << "ingrese las hs trabajadas: ";
    cin >> hsTrabajadas;
    
    mMesDiasCont[mes-1][dia-1] ++;
    vEmpleadosHsTrabajadas[numeroEmpleado-100] += hsTrabajadas;

    cout << "Numero empleado: ";
    cin >> numeroEmpleado;
  }  

  cout << endl <<"Punto 1" << endl;
  int contParaCadaMes;
  for(int i = 0; i < 12; i ++){
    contParaCadaMes = 0;
    for(int j = 0; j < 31; j ++){
      if(mMesDiasCont[i][j] > 0){
        contParaCadaMes++;
      }
    }
    if(contParaCadaMes > 0){
      cout << "Mes Numero " << i+1 << " la cantidad de dias con al menos un empleado es: " << contParaCadaMes << endl;
    }
  } 

  //punto 2
  cout <<endl <<"Punto 2" << endl;//dias del año sin ningun empleado
  
  for(int i = 0; i < 12; i ++){
    contParaCadaMes = 0;
    cout << endl << "Mes Numero " << i+1 << ": " << endl;
    for(int j = 0; j < 31; j ++){
      if(mMesDiasCont[i][j] == 0){
        cout << "- Dia " << j+1 << " no se trabajo" << endl;
      }
    }
  } 

  cout << endl << "Punto 3: " << endl;
  for(int x = 0; x < 30; x++){
    if(vEmpleadosHsTrabajadas[x] != 0){
      cout << "Empleado #" << x+100 << " trabajo " << vEmpleadosHsTrabajadas[x] << " horas " << endl;
    }
  }

  return 0;

}