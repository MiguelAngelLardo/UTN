#include <iostream>

using namespace std;

int main (){
  int mMesDiaImporte[12][31] = {};
  int dia, mes, importe;

  cout << "Ingrese el Mes(corta con cero): ";
  cin >> mes;

  while(mes != 0){
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el importe: ";
    cin >> importe;
    mMesDiaImporte[mes-1][dia-1] += importe;
    
   
    cout << "Ingrese el mes(corta con cero): ";
    cin >> mes;
  }

  int gastoTotalalMes;
  cout << endl << "PUNTO A GASTOS POR MES" << endl;
  for(int i = 0; i < 12; i ++){
    gastoTotalalMes = 0;
    cout << "MES #" << i+1;
    for(int j = 0; j < 31; j ++){
      gastoTotalalMes += mMesDiaImporte[i][j];
    }
    cout << " -> GASTO TOTAL $" << gastoTotalalMes << endl;  
  }

  int diagasto, maxGastoMes, indiceMaxgasto;
  cout << endl << "PUNTO B y C DIA MAS GASTADO EN EL MES CON SU MONTO" << endl;
  for(int i = 0; i < 12; i ++){
    indiceMaxgasto = 0;
    maxGastoMes = mMesDiaImporte[i][0];
    cout << "MES #" << i+1;
    for(int j = 1; j < 31; j ++){
      if(mMesDiaImporte[i][j] > maxGastoMes){
        maxGastoMes = mMesDiaImporte[i][j];
        indiceMaxgasto = j;
      }

    }
    if(maxGastoMes != 0)
      cout << " -> DIA CON MAYOR GASTO " << indiceMaxgasto + 1 << " -> SU MONTO ES $" << maxGastoMes << endl;
    else
      cout << " -> NO SE HICIERON GASTOS EN EL MES" << endl;  
  }


  return 0;
}