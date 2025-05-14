#include <iostream>

using namespace std;


/*
Crea una clase llamada Rectangulo que represente un rectángulo. La clase debe tener dos atributos correspondientes a la base y altura. 
Implementa las siguientes metodos:
●	Getters y Setter de cada atributo.
●	calcularArea(): Devuelve el área del rectángulo.
●	calcularPerimetro(): Devuelve el perímetro del rectángulo.

*/

class Rectangulo{
private:
  int _base, _altura;

public:

  void setBase(int base){_base = base;}
  void setAltura(int altura){_altura = altura;}
  int getBase(){return _base;}
  int getAltura(){return _altura;}

  int calcularArea(){
    return _base * _altura;
  }

  int calcularPerimetro(){
    return 2 * (_base + _altura);
  }


};

int main (){
  Rectangulo miRectangulo;
    
  // Establecer base y altura
  miRectangulo.setBase(5);
  miRectangulo.setAltura(3);
  
  // Calcular y mostrar área y perímetro
  std::cout << "Área del rectángulo: " << miRectangulo.calcularArea() << std::endl;
  std::cout << "Perímetro del rectángulo: " << miRectangulo.calcularPerimetro() << std::endl;

  return 0;
}