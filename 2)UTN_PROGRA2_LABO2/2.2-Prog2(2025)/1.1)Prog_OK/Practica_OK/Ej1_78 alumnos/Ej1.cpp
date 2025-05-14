#include <iostream>

using namespace std;
/*
Cargar las notas del primer parcial de los 78 estudiantes de un curso. Luego de cargar todas las notas:

- Pedir un número y mostrar por pantalla la nota registrada. Por ejemplo, se ingresa 10 para mostrar el décimo examen.

- Listar cuántos estudiantes obtuvieron una nota mayor al promedio.
*/

const int ESTUDIANTES = 10;//78


void cargarNotas(int *v, int cant){
  for(int i = 0; i < cant; i++){
    cout << "Ingrese la nota del alumno " << i + 1 << ": ";
    cin >> *(v+i); //
    }
}

void mostarExamenPorIndice(int *v, int indice){
  cout << "El examen numero " << indice << " es: " << *(v+indice-1) << endl;
  cout << "El examen numero " << indice << " es: " << *v+indice << "=> muesta v[0] + " << indice << "=> v[0]: " << v[0] << endl;
  cout << "El examen numero " << indice << " es: " << v[indice-1] << endl;
}

int obtenerPromedio(int *v, int cant){
  int acum = 0;

  for(int i = 0; i < cant; i++){
    acum += v[i]; //*(v+i)    
  }  

  return acum / cant;
}

int contadorMayoresPromedio(int *v, int cant, int obtenerPromedio(int [], int)){//call back
  int promedio = obtenerPromedio(v, cant);

  int contador = 0;

  for(int i = 0; i < cant; i++){
    if(*(v+i) > promedio){
      contador++;
    }
  }  

  return contador;  
}

int main() {

  int vEstudiantes[ESTUDIANTES], opcion;
  
  do{
    
    cout << "Bienvenido al MENU: " << endl;
    cout << "1-Ingresar las notas de los alumnos => son " << ESTUDIANTES << " alumnos" << endl;
    cout << "2-Mostrar el examen de un alumno" << endl;
    cout << "3-Mostrar cuantos alumnos obtuvieron una nota mayor al promedio" << endl;
    cout << "0-para salir" << endl;
    cin >> opcion;

    switch (opcion)
    {
      case 1:{
        cargarNotas(vEstudiantes, ESTUDIANTES);
      }break;
    
      case 2:{
        int indice;
        cout << "Ingrese el indice del examen: ";
        cin >> indice;
        mostarExamenPorIndice(vEstudiantes, indice);
      }break;  

      case 3:{
        int contador = contadorMayoresPromedio(vEstudiantes, ESTUDIANTES, obtenerPromedio);
        int promedio = obtenerPromedio(vEstudiantes, ESTUDIANTES);
        cout << "EL promedio es: " << promedio << endl;
        cout << "La cantidad de notas mayores al promedio es: " << contador << endl;
      }break;  

    }

  } while(opcion != 0);
  

  return 0;
}