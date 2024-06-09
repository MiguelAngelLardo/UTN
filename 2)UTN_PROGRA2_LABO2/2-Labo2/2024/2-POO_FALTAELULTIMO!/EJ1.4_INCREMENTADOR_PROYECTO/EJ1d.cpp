#include <iostream>
using namespace std;
#include "Incrementador.h"

int main(){
  Incrementador inc (0, 5);
  bool incrementar = true;

  cout << "Quiere incrementar?" << endl;
  cin >> incrementar;

  while (incrementar){
    inc.incrementar();

    cout << "Valor actual: " << inc.getValor() << endl;

    cout << "Quiere incrementar?" << endl;
    cin >> incrementar;

  }
  inc.incrementar();

  cout << "Valor final: " << inc.getValor() << endl;
  cout << "Cantidad de incrementos " << inc.getCantidadIncrementos() << endl;
  
  return 0;
}

