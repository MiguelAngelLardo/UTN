#include <iostream>

using namespace std;

void cargarDatos(float matRec [3][5]);
void mostrarRecaudacion(float matRec [3][5]);


int main(){
  float matRec[3][5]={0};//guarda dinero
  cargarDatos(matRec);
  system("cls");
  mostrarRecaudacion(matRec);
  cout << endl;
  system("pause");
  return 0;
}

void cargarDatos(float matRec [3][5]){
  int mes, empleado;
  float importe;

  cout << "Ingrese mes: ";
  cin >> mes;
  while (mes != 0){
    cout << "EMPLEADO ";
    cin >> empleado;
    cout << "IMPORTE ";
    cin >> importe;

    matRec[mes-1][empleado-1] += importe;

    cout << "Ingrese mes: ";
    cin >> mes;
  }
}

void mostrarRecaudacion(float matRec [3][5]){
  int i, j;
  for(i = 0; i < 3; i++){
    for(j = 0; j < 5; j++){
      cout << "MES " << i+1 << " RECAUDACION EMPLEADO " << j+1 << " " << matRec[i][j] << endl;
    }
    cout << endl;
  }


}
