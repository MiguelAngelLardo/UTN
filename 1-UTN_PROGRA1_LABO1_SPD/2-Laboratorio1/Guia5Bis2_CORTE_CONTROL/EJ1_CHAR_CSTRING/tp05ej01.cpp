//TP         : 05
//EJERCICIO  : 01
//AUTOR      : Angel Simón - asimon@frgp.utn.edu.ar
//DESCRIPCION: -
#include <iostream>
using namespace std;
#include <cstring>

const int CANT_SECCIONES=3; //Originalmente 10.

int main(void){
  char maxNombre[20], nombre[20], sexo, maxSexo;
  int edad, i, maxSeccion, cantSeccionMasc, cantSeccionFem, cantTotalMasc, cantTotalFem;
  float sueldo, maxSueldo, sumaSueldoMasc, sumaSueldoFem;

  sumaSueldoFem=sumaSueldoMasc=maxSueldo=0.0;
  cantTotalFem=cantTotalMasc=0;
  for(i=1; i<=CANT_SECCIONES; i++){
    cantSeccionFem=cantSeccionMasc=0;
    cout << "Ingresar sexo del operario: ";
    cin >> sexo;
    while(sexo!='*'){
      cout << "Ingresar nombre: ";
      cin >> nombre;
      cout << "Ingresar edad: ";
      cin >> edad;
      cout << "Ingresar sueldo: ";
      cin >> sueldo;
      if (sueldo > maxSueldo){
        strcpy(maxNombre, nombre);
        maxSueldo = sueldo;
        maxSexo = sexo;
        maxSeccion = i;
      }
      if(sexo == 'f'){
        cantSeccionFem++;
        sumaSueldoFem += sueldo;
      }
      else if(sexo == 'm'){
        cantSeccionMasc++;
        sumaSueldoMasc += sueldo;
      }
      cout << endl << "Ingresar sexo del operario: ";
      cin >> sexo;
    }
    cantTotalFem += cantSeccionFem;
    cantTotalMasc += cantSeccionMasc;

    cout << endl << "PUNTO C:" << endl;
    cout << "------------------" << endl;
    cout << "CANT. MUJERES: " << cantSeccionFem << endl;
    cout << "CANT. HOMBRES: " << cantSeccionMasc << endl;
  }
  cout << endl << "PUNTO A:" << endl;
  cout << "--------------------" << endl;
  cout << "Operario con mejor sueldo: " << maxNombre << endl;
  cout << "Sexo: " << maxSexo << endl;
  cout << "Sueldo: $" << maxSueldo << endl;
  cout << "Seccion: " << maxSeccion << endl;

  cout << endl << "PUNTO B:" << endl;
  cout << "---------------------" << endl;

  if (cantTotalMasc > 0)
    cout << "Sueldo promedio masculinos: $" << (sumaSueldoMasc / cantTotalMasc) << endl;
  if (cantTotalFem > 0)
    cout << "Sueldo promedio femeninos : $" << (sumaSueldoFem / cantTotalFem) << endl;
  return 0;
}
