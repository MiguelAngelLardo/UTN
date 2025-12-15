#include <iostream>

using namespace std;

/*
Crea una clase llamada Triangulo que represente un triángulo. 
La clase debe contener un vector de 3 elementos
-donde cada elemento corresponde a la longitud de un lado del triángulo. Implementa los siguientes métodos:
●	getLado(int numero): Devuelve la longitud del valor del lado correspondiente al número proporcionado (1, 2, o 3). 
  Si el número es incorrecto (fuera del rango 1-3), devuelve cero.
●	setLado(int numero, float valor): Establece el valor del lado correspondiente al número proporcionado (1, 2, o 3). 
Si el número es incorrecto (fuera del rango 1-3), no realiza ninguna acción.

●	getTipo(): Devuelve el tipo de triángulo según sus lados:
○	1 para un triángulo equilátero (todos los lados iguales).
○	2 para un triángulo isósceles (dos lados iguales).
○	3 para un triángulo escaleno (todos los lados diferentes).

●	isEscaleno(): Devuelve true si el triángulo es escaleno, false en caso contrario.
●	isIsosceles(): Devuelve true si el triángulo es isósceles, false en caso contrario.
●	isEquilatero(): Devuelve true si el triángulo es equilátero, false en caso contrario.

*/

class Triangulo{
private:
  int _vLados[3];

public:
  void setLado(int indice, float valorLado){
    if(indice >=1 && indice <=3){
      _vLados[indice-1] = valorLado;
    }
  }

  int getLado(int indice){
    return (indice >=1 && indice <=3) ? _vLados[indice-1] : 0;
  }

  string getTipo(){	
    if(_vLados[0] == _vLados[1] && _vLados[1] == _vLados[2]){
      return "Equilatero";
    }else if(_vLados[0] == _vLados[1] || _vLados[0] == _vLados[2] || _vLados[1] == _vLados[2]){
      return "Isosceles";
    }else{
      return "Escaleno";
    }
  }  
    
};

int main(){
  system("cls");

  Triangulo t1;
  t1.setLado(1, 3.3);
  t1.setLado(2, 3.3);
  t1.setLado(3, 3.3);

  // Imprimir lados.
  cout << "Lado 1: " << t1.getLado(1) << endl;
  cout << "Lado 2: " << t1.getLado(2) << endl;
  cout << "Lado 3: " << t1.getLado(3) << endl;

  // Imprimir tipo de triángulo.
  cout << "Tipo: " << t1.getTipo() << endl;

  t1.setLado(1, 4.3);
  t1.setLado(2, 3.3);
  t1.setLado(3, 4.3);

   // Imprimir tipo de triángulo.
   cout << "Tipo: " << t1.getTipo() << endl;

  return 0;
}