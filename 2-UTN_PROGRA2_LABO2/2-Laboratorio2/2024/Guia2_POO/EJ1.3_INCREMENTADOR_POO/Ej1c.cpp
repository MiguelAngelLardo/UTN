#include <iostream>

using namespace std;

class Incrementador{
private:  
  int _valor;
  int _valorIncremento;
  int _cantidadIncrementos;

  void setValorIncremento(int valorIncremento){
    _valorIncremento = valorIncremento;
    if(_valorIncremento < 0){
      _valorIncremento = 0;
    }
  }

public:
  Incrementador(){
    _valor = 0;
    _valorIncremento = 1;
    _cantidadIncrementos = 0;
  }

  Incrementador (int inicial, int incremento){
    _valor = inicial;
    _valorIncremento = incremento;
    setValorIncremento(incremento);
  }

 
  void incrementar(){
    _valor += _valorIncremento;
    _cantidadIncrementos ++;
  }

  int getValor(){
    return _valor;
  }

  /*~Incrementador(){
    cout << "Me destruyo.." << endl;
  }*/

};

int main(){
  Incrementador inc (0, 5);
  
  inc.incrementar();
  cout << "Valor actual: " << inc.getValor() << endl;
  
  inc.incrementar();
  cout << "Valor actual: " << inc.getValor() << endl;
  
  inc.incrementar();
  cout << "Valor actual: " << inc.getValor();
 

  return 0;
}

