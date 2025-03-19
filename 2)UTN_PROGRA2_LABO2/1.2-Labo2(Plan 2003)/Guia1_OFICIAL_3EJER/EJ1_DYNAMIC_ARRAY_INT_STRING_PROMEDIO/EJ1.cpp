#include <iostream>
#include <string>

using namespace std;

void cargarNotas(int *vec, const int tam);
void cargarNombresApellidos(string *vec, const int tam);
int obtenerCantidadPuntajeFinalMayorPromedio(int *vec, const int tam);
void obtenerListadoPuntajeMayorPromedioAprobados(string *vecNom, int *vecNot,  const int tam);

int main(){
  int cantAlumnos;
  int *vNotasFinales = nullptr;
  string *vNombreApellido = nullptr;

  int puntoA;
  
  cout << "Ingrese la cantidad de alumnos de su materia: ";
  cin >> cantAlumnos;
  vNotasFinales = new int[cantAlumnos];
  vNombreApellido = new string [cantAlumnos];
  
  if(vNombreApellido != nullptr && vNotasFinales != nullptr)
  {
    cargarNotas(vNotasFinales, cantAlumnos);
    cargarNombresApellidos(vNombreApellido, cantAlumnos);
    puntoA = obtenerCantidadPuntajeFinalMayorPromedio(vNotasFinales, cantAlumnos);
    cout << "PTO A => cantidad de notas mayor al promedio: " << puntoA << endl;

    cout << "PUNTO B" << endl;
    obtenerListadoPuntajeMayorPromedioAprobados(vNombreApellido, vNotasFinales, cantAlumnos);

    delete []vNombreApellido;
    delete []vNotasFinales;
  }


  return 0;
}
/**
 CARGAS LAS NOTAS
 @param vec Es el vector de notas para llenar
 @param tam Es la cantidad denotas
*/
void cargarNotas(int *vec, const int tam){
  cout << "Ingrese las notas" << endl;
  for(int x = 0; x < tam; x ++){
    printf("Nota #%d: ", x+1);
    cin >> vec[x];
  }
}

void cargarNombresApellidos(string *vec, const int tam){
  cout << "Ingrese nombre y apellido" << endl;
  for(int x = 0; x < tam; x ++){
    cout << x+1 << ") Nombre y Apellido:";
    cin.ignore();
    getline(cin, vec[x]);
  }
}


int obtenerCantidadPuntajeFinalMayorPromedio(int *vec, const int tam){
  int acumNotas = 0, contadorMayorPromedio = 0;
  for(int x = 0; x < tam; x ++){
    acumNotas += vec[x];
  }

  float promedio = (float)acumNotas / tam;

  for(int x = 0; x < tam; x ++){
    //contadorMayorPromedio += (vec[x] > promedio) ? 1 : 0;
    contadorMayorPromedio = (vec[x] > promedio) ? contadorMayorPromedio + 1 : contadorMayorPromedio + 0;
  }

  return contadorMayorPromedio;
}

void obtenerListadoPuntajeMayorPromedioAprobados(string *vecNom, int *vecNot,  const int tam){
  string *vListadoPuntajeSuperiorPromedio = nullptr;
  int acumMayor6 = 0, contNot = 0;
  int alumnosConMasNotaDelPromedio = 0;

  for(int x = 0; x < tam; x ++){
    if(vecNot[x] > 6){
      acumMayor6 += vecNot[x];
      contNot ++;
    }
  }

  float promedioMayorA6 = (float) acumMayor6 / contNot;

  for(int x = 0; x < tam; x ++){
    alumnosConMasNotaDelPromedio += (vecNot [x] > promedioMayorA6 ) ?  1 : 0;
  }

  vListadoPuntajeSuperiorPromedio = new string[alumnosConMasNotaDelPromedio];

  if(vListadoPuntajeSuperiorPromedio != nullptr)
  {
    for(int x = 0; x < tam; x ++){
      if(vecNot[x] > promedioMayorA6){
        vListadoPuntajeSuperiorPromedio[x] = vecNom[x];
      }
    }
    for(int x = 0; x < alumnosConMasNotaDelPromedio; x ++){
      cout << x+1 << ")ALUMNO:" << vListadoPuntajeSuperiorPromedio[x];
    }

    delete []vListadoPuntajeSuperiorPromedio;  
  }
}

