#include <iostream>

using namespace std;

/*
Crea una clase llamada CuentaBancaria que represente una cuenta bancaria. La clase debe tener los siguientes atributos:
●	Número de cuenta (entero)
●	Saldo actual (float)
Implementa los siguientes métodos:
●	Un constructor que me permita establecer el número de cuenta y el saldo.
●	Un método depositar(float monto) que incremente el saldo.
●	Un método retirar(float monto) que disminuya el saldo si hay fondos suficientes, caso contrario no hace nada.
●	Un método obtenerSaldo() que devuelva el saldo actual

*/

class CuentaBancaria{

private:
  int _numCuenta;
  float _saldo;

public:

  CuentaBancaria(int numCuenta, float saldo){
    _numCuenta = numCuenta;
    _saldo = saldo;
  }

  void depositar(float monto){
    _saldo += monto;
  }

  void retirar(float monto){
    if(_saldo >= monto){
      _saldo -= monto;
    }else{
      cout << "No hay suficientes fondos" << endl;
    }
  }

  int getSaldo(){
    return _saldo;
  }

  int getNumCuenta(){
    return _numCuenta;
  }

};

int main (){
  CuentaBancaria cuenta(123456, 2000);

  cout << "numero de cuenta: " << cuenta.getNumCuenta() << endl;
  cout << "Saldo actual: " << cuenta.getSaldo() << endl;

  cuenta.depositar(500);
  cuenta.retirar(250);

  cout << "Saldo actual: " << cuenta.getSaldo() << endl;

}