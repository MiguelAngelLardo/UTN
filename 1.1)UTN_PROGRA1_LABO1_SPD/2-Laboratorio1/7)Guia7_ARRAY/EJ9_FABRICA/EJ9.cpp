#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;// Usamos el espacio de nombres estándar

/*****ARRAY*****/
const int EMPLOYEE = 80;
const int DAY = 31;
/*****ARRAY*****/
int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 

  int employeeID;
  float hourlyRate, overTimeRate;  //Rate es la tasa o tarifa del empleado
  int day;
  float totalWorkHours; 
  float matrizEmployeexDay_Hours[EMPLOYEE][DAY] = {}; //empleado en fila - dias en columnas

  cout << "Enter your employe ID (1-80 or 0 to Finish): ";
  cin >> employeeID;
  if(employeeID != 0){
    cout << "Enter the hourly rate: ";
    cin >> hourlyRate;
    cout << "Enter the overtime rate per hour: ";
    cin >> overTimeRate;
  }

  while(employeeID != 0)
  {
    cout << "Enter the WORKDAY (1-31): ";
    cin >> day;
    cout << "Enter the total hours worked: ";
    cin >> totalWorkHours;

    matrizEmployeexDay_Hours[employeeID-1][day-1] += totalWorkHours;

    cout << endl << "================" << endl;
    cout << "Enter your employe ID (or 0 to Finish): ";
    cin >> employeeID;
  }

  for(int fila=0; fila<EMPLOYEE; fila++)
  {
    float totalToPayPerEmployeeInMonth = 0;
    for(int col=0; col<DAY; col++)
    {
      if(matrizEmployeexDay_Hours[fila][col] < 9){
        totalToPayPerEmployeeInMonth += matrizEmployeexDay_Hours[fila][col] * hourlyRate;
      }else{
        totalToPayPerEmployeeInMonth += 9 * hourlyRate;
        totalToPayPerEmployeeInMonth += (matrizEmployeexDay_Hours[fila][col] -9) * overTimeRate;;
      }
    }

    cout << "Employee ID " << fila+1 << ". total earnings at the end of the month: " << fixed << setprecision(2) << totalToPayPerEmployeeInMonth << endl;
  }

  return 0;

}