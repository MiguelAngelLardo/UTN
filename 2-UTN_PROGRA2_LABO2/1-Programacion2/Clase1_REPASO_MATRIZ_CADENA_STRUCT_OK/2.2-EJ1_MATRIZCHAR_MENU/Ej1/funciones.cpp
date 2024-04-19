#include <iostream>
#include"funciones.h"

using namespace std;


void cargarCadena(char *palabra, int tam){
  int i = 0;
  fflush(stdin);//limpia Buffer de C
  for (i = 0; i < tam; i ++)
  {
    palabra[i] = cin.get(); //es de c++
    if(palabra[i] == '\n')
    {
      break;
    }
  }
  palabra[i] = '\n';
  fflush(stdin);
}

void cargarMaterias(char mat[][35]){
  int nMat;
  for (int i = 0; i < 5; i ++)
  {
    cout << "INGRESE EL NUMERO DE LA MATERIA: ";
    cin >> nMat;
    cout << "INGRESE MATERIA: ";
    cargarCadena(mat[nMat-1], 34);
  }
}
void mostrarMaterias(char mat[][35]){
  for (int i = 0; i < 5; i ++)
  {
    cout << "NUMERO DE LA MATERIA: " << i+1 << endl;
    cout << "NOMBRE MATERIA: " << mat[i] << endl; // mat[i] = &mat[i][0]
  }
}

void cargatAccesos(float *vHorasMaterias, int accesos[][31]){
  int legajo, dia, mes, materias;
  float horas;
  cout << "LEGAJO: ";
  cin >> legajo;
  while(legajo != 0)
  {
    cout << "DIA: ";
    cin >> dia;
    cout << "MES: ";
    cin >> mes;
    cout << "MATERIA: ";
    cin >> materias;
    cout << "HORAS: ";
    cin >> horas;

    vHorasMaterias[materias-1] += horas;//PUNTO a Y b

    if(mes == 3)
    {
      accesos[materias -1][dia-1] ++;
    }

    cout << "LEGAJO: ";
    cin >> legajo;

  }

}
void puntoA(float *vHorasMaterias, char mat[][35]){
  for (int i = 0; i < 5; i ++)
  {
    if(vHorasMaterias[i]==0){
      cout << mat[i] << endl;
    }
  }
}
void puntoB(float *vHorasMaterias, char mat[][35]){
  int  maxHoras = 0;
  for (int i = 1; i < 5; i ++)
  {
    if(vHorasMaterias[i] > vHorasMaterias[maxHoras] ){
      maxHoras = i;
    }
  }
  cout << "LA MATERIA CON MAS HORAS ES: " << mat[maxHoras];

}
void puntoC(int accesos[][31], char mat[][35]){
  cout << "MES DE MARZO: " << endl << endl;
  for (int i = 0; i < 5; i ++)
  {
    for(int j = 0; j < 31; j ++)
    {
      if(accesos[i][j] > 0)
      {
        cout << "MATERIA " << mat[i] << " - DIA " << j+ 1 << " - #ACCESOS: " << accesos[i][j] << endl << endl;
      }
    }
  }
}
