#include <iostream>
#include <ctime>

using namespace std;

/*
Crea una clase llamada Dado que simule el comportamiento de un dado de seis caras. La clase debe contener los siguientes atributos:
●	valor (int): Almacena el valor actual del dado (un número entre 1 y 6).
Implementa los siguientes métodos públicos:
●	Dado(): Constructor que inicializa el dado con un valor aleatorio entre 1 y 6.
●	lanzar(): Simula el lanzamiento del dado, asignando un nuevo valor aleatorio entre 1 y 6 al atributo valor.
●	getValor(): Devuelve el valor actual del dado.
●	esMaximo(): Devuelve true si el valor del dado es 6, y false en caso contrario.
●	esMinimo(): Devuelve true si el valor del dado es 1, y false en caso contrario.

*/

class Dado {
private:
  int _valor;//1 a 6

public:
  Dado(int v=rand()%6+1){
    _valor=v;
  }

  int getValor(){return _valor;}

  void lanzar(){
    _valor = rand()%6+1;
  }

  bool esMaximo(){
    return _valor==6;
  }

  bool esMinimo(){
    return _valor==1;
  }
}; 

int main() {
  srand(time(0));

  Dado dado1;
  cout << "Dado 1: " << dado1.getValor() << endl;

  dado1.lanzar();
  cout << "Dado 1: " << dado1.getValor() << endl;

  cout << "Es el dado 1 un maximo? " << dado1.esMaximo() << endl;
  cout << "Es el dado 1 un minimo? " << dado1.esMinimo() << endl;

  return 0;
}