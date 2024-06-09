#include <iostream>
#include <vector> //STL, Standard Template Library

using namespace std;

struct Empleado{
  int nroEmpleado; // buscamos indice
  int categoria;
  int antiguedad;
};

void carga(vector<Empleado> &);
void proceso (vector<Empleado> &, int [], int [], float [], int []);
void funcionPTA (vector<Empleado> &, int [], int [], int, int, int);
void mostrarPTA (vector<Empleado> &, int [], int []);
void funcionPTOB(vector<Empleado> &, float [], int [], int , int , int , float );
void mostrarPTOB(vector<Empleado> &, float [], int []);
void mostrarPTOC(vector<Empleado> &, float []);

int main()
{
  vector<Empleado> empleados1;
  carga(empleados1);

  //en tiempo de ejecucion no puedo modificar ARRAY por eso uso VECTOR y ese tamaño DINAMICO lo asigno a CONSTANTE
  const int MAX_EMPLEADO = empleados1.size();
  int empleadoDia[MAX_EMPLEADO] = {}, empleadoHoras [MAX_EMPLEADO]= {};//PTA
  float totalCobrar[MAX_EMPLEADO] = {}; //PTOB
  int contadorDias[MAX_EMPLEADO] = {};//PTOB

  proceso (empleados1, empleadoDia, empleadoHoras, totalCobrar, contadorDias);
  mostrarPTA (empleados1, empleadoDia, empleadoHoras);
  mostrarPTOB(empleados1, totalCobrar, contadorDias);
  mostrarPTOC(empleados1, totalCobrar);

  return 0;
}

void carga(vector<Empleado> &empleados){
  for(int i = 0; i < 200; i ++ ){
    empleados.push_back(Empleado());// Agregar un nuevo elemento al final del vector

    cout << i+1 << ") Ingrese el nro de empleado (digitios no correlativos): ";
    cin >> empleados[i].nroEmpleado;
    cout << i+1 << ") Ingrese la categoria (1 a 20)(CORTA CON CERO): ";
    cin >> empleados[i].categoria;
    cout <<  i+1 << ") Antiguedad: ";
    cin >> empleados[i].antiguedad;
    
    if(!empleados[i].categoria){   
      i = 200;
      cout << "saliendo de fcarga";
      empleados.pop_back();
    }
  }
}

void proceso (vector<Empleado> &empleados1, int empleadoDia [], int empleadoHoras [], float totalCobrar[], int contadorDias []){
  int dia, nroEmpleado, horasTrabajadas;
  float jornal;

  cout << "Ingrese el dia (1 a 31): ";
  cin >> dia;
  cout << "Ingrese el nro de empleado(3 digitos no correlativos)(CORTA CON CERO): ";
  cin >> nroEmpleado;
  while (nroEmpleado != 0)
  {
    cout << "Ingrese las HS trabajadas: ";
    cin >> horasTrabajadas;
    cout << "Ingrese el jornal cobrado en el dia: ";
    cin >> jornal;  

    funcionPTA (empleados1, empleadoDia, empleadoHoras, nroEmpleado, horasTrabajadas, dia);
    funcionPTOB(empleados1, totalCobrar, contadorDias, dia, nroEmpleado, horasTrabajadas, jornal);

    cout << "Ingrese el dia (1 a 31): ";
    cin >> dia;
    cout << "Ingrese el nro de empleado(e digitos no correlativos): ";
    cin >> nroEmpleado;
  }
}

void funcionPTA (vector<Empleado> &empleados1, int empleadoDia [], int empleadoHoras [], int nroEmpleado, int horasTrabajadas, int dia){
  for(int i = 0; i < empleados1.size(); i ++){
    if(empleados1[i].nroEmpleado == nroEmpleado)
    {
      if(horasTrabajadas > empleadoHoras [i])
      {
        empleadoHoras[i] = horasTrabajadas;
        empleadoDia [i] = dia;
      }
    }
  }
}

void mostrarPTA (vector<Empleado> &empleados1, int empleadoDia [], int empleadoHoras []){
  for(int x = 0; x < empleados1.size(); x ++){
    cout << "EMPLEADO: " << empleados1[x].nroEmpleado << " | DIA que mas trabajo es: " << empleadoDia [x] << " | Fueron HS: " << empleadoHoras [x] << endl;
  }
}

void funcionPTOB(vector<Empleado> &empleados1, float totalCobrar[], int contadorDias [], int dia, int nroEmpleado, int horasTrabajadas, float jornal){
  for(int i = 0; i < empleados1.size(); i ++){
    if(nroEmpleado == empleados1[i].nroEmpleado){
      totalCobrar[i] += jornal * horasTrabajadas;
      contadorDias[i] += (dia >=1 && dia <= 31) ? 1 : 0;
    }
  }
}
  
void mostrarPTOB(vector<Empleado> &empleados1, float totalCobrar[], int contadorDias []){
  for(int i = 0; i < empleados1.size(); i ++){
    if(contadorDias[i] >= 20){
      totalCobrar[i] += 200;
    }
    cout << "EMPLEADO: " << empleados1[i].nroEmpleado << endl;
    cout << "TOTAL A COBRAR: " << totalCobrar[i] << endl;
  }      
}  

void mostrarPTOC(vector<Empleado> &empleados1, float totalCobrar[]){
  float maxSueldo = totalCobrar[0];
  int maxIndice = 0;
  for(int i = 1; i < empleados1.size(); i ++){
    if(totalCobrar[i] > maxSueldo){
      maxSueldo = totalCobrar[i];
      maxIndice = i;
    }
  }

  cout << "NUMERO CATEGORIA CON MAYOR SUELDO: " << empleados1[maxIndice].categoria << endl;
}