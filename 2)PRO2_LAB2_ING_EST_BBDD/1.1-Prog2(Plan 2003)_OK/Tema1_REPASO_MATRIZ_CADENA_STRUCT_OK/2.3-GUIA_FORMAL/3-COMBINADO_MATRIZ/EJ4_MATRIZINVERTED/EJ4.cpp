#include <iostream>

using namespace std;

/*



4) Una fábrica produce 70 distintos tipos de engranajes en 15 máquinas. 
Dispone de un lote de registros con la producción del último mes, con la siguiente información:
- Día
- Tipo de Engranaje (1 a 70)
- Número de máquina utilizada (1 a 15)
- Cantidad producida

Los registros están desordenados y se pueden repetir para un mismo día y para una misma máquina la 
producción del mismo tipo de engranaje. El fin del lote se indica con un registro con día 32.
Confeccionar un programar para informar:

a) El tipo de engranaje del cual se han producido en total la mayor cantidad de unidades.
b) El número de máquina que menos cantidad en total produjo.

c) Un listado con el siguiente formato:
Tipo de Engranaje     Nro. de Máquina       Cant. Producida

70 enrganajes salen de 15 maquinas

C=>salida de datos

A=> que grabaje se produjo mas entre als 15 maquinas
B => la maquina que menos granajes saco

            engranaje 1  engranaje 2   engranaje 3  
maquina 1
maquina 2
maquina 3


*/

const int TAM_MAQUINA = 3;
const int TAM_ENGRANAJE = 3;

int main(){
  int dia, engranaje, numMaquina, cantidadProducida;
  int mMaquinaEngranajeCantidad[TAM_MAQUINA][TAM_ENGRANAJE] = {};

  cout << "Ingrese el dia(corta con 32): ";
  cin >> dia;
  while (dia != 32){
    cout << "Ingrese el tipo de engranaje (1 al 70): ";  
    cin >> engranaje;
    cout << "Ingrese el numero de maquina (1 a 15): ";  
    cin >> numMaquina;
    cout << "Ingrese la cantidad producida: ";
    cin >> cantidadProducida;

    mMaquinaEngranajeCantidad[numMaquina-1][engranaje-1] += cantidadProducida;
       
    cout << "Ingrese el dia(corta con 32): ";
    cin >> dia; 
  }

  cout << "\nPTO C\n";
  cout << "TIPO ENGRANAJE      Nro.Maquina     Cant. Producida" << endl;
  for(int i = 0; i < TAM_MAQUINA; i ++){    
    for(int j = 0; j  < TAM_ENGRANAJE; j ++){
      cout << j+1 << "                        " << i+1 <<  "            " << mMaquinaEngranajeCantidad[i][j] << endl;
    }
    cout << endl;   
  }

  cout << "\nPTO C\n";
  int acumGranaje, maximoProducido = -1, tipoMaxProducido;
  for(int j = 0; j < TAM_ENGRANAJE; j ++){
    acumGranaje = 0;
    for(int i = 0; i < TAM_MAQUINA; i ++){
      acumGranaje += mMaquinaEngranajeCantidad[i][j];//0 1/2/3
    }
    if(maximoProducido == -1){
      maximoProducido = acumGranaje;
      tipoMaxProducido = j+1;
    }else if( acumGranaje > maximoProducido){
      maximoProducido = acumGranaje;
      tipoMaxProducido = j+1;
    }
  }
  cout << "El Engranaje mas producido es #" << tipoMaxProducido << " con " << maximoProducido << " unidades";
  
  cout << endl;
  
  cout << "\nPTO B\n";
  int acumMaq, minimoProducido = -1, tipoMinProducido;
  for(int i = 0; i < TAM_MAQUINA; i ++){
    acumMaq = 0;
    for(int j = 0; j < TAM_ENGRANAJE; j ++){
      acumMaq += mMaquinaEngranajeCantidad[i][j];//0 1/2/3
    }
    if(minimoProducido == -1){
      minimoProducido = acumMaq;
      tipoMinProducido = i+1;
    }else if( acumMaq < minimoProducido){
      minimoProducido = acumMaq;
      tipoMinProducido = i+1;
    }
  }

  cout << "La maquina que menos engranaje hizo es #" << tipoMinProducido << " con " << minimoProducido << " unidades";


  return 0;
}