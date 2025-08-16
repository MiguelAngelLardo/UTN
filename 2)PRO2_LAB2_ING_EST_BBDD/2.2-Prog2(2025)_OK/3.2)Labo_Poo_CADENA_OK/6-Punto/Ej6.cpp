#include <iostream>
#include <math.h>

using namespace std;

/*
Crea una clase llamada Punto que represente un punto en un plano cartesiano. 
La clase debe contener los siguientes atributos:
●	x (float): Almacena la coordenada en el eje X.
●	y (float): Almacena la coordenada en el eje Y.

Implementa los siguientes métodos públicos:
●	Punto(float xInicial, float yInicial): Constructor que inicializa las coordenadas x y y del punto.
●	Getters y Setters para cada atributo.

●	calcularDistancia(Punto otroPunto): Devuelve la distancia entre el punto actual y otro punto dado. 
La fórmula para calcular la distancia entre dos puntos (x1, y1) y (x2, y2) es: sqrt((x2 - x1)^2 + (y2 - y1)^2).
●	mover(float deltaX, float deltaY): Mueve el punto sumando deltaX a x y deltaY a y.

*/

class Punto{
private:
  float _x, _y;

public:
  Punto(float x, float y): _x(x), _y(y){}

  void setX(float x){_x = x;}
  void setY(float y){_y = y;}
  float getX(){return _x;}
  float getY(){return _y;}

  float calcularDistancia(Punto otroPunto){//recibe x y
    cout << "X2 - x1 => " << otroPunto.getX() << " - " << _x << endl;
    cout << "Y2 - y1 => " << otroPunto.getY() << " - " << _y << endl;
    
    cout << "Pow(X2 - x1, 2) => " << pow( otroPunto.getX() - _x, 2) << endl;
    cout << "Pow(Y2 - y1, 2) => " << pow( otroPunto.getY() - _y, 2) << endl;

    cout << "Raiz => " << sqrt( pow( otroPunto.getX() - _x, 2) + pow( otroPunto.getY() - _y, 2) ) << endl;
    
    return sqrt( pow( otroPunto.getX() - _x, 2) + pow( otroPunto.getY() - _y, 2) );
  } 

  void mover(float deltaX, float deltaY){
    _x += deltaX;
    _y += deltaY;
  }

};

int main(){
  Punto p1(1,5);
  Punto p2(2,3);

  p1.calcularDistancia(p2);
  cout << endl;

  p1.mover(1,1);
  cout << p1.getX() << ", " << p1.getY() << endl;

  return 0;
}