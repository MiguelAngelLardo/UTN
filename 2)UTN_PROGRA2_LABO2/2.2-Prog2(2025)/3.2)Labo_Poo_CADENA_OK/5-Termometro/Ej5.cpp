#include <iostream>

using namespace std;

/*
Crea una clase llamada Termometro que represente un termómetro digital. La clase debe contener los siguientes atributos:
●	temperatura (float): Almacena la temperatura actual medida por el termómetro.
●	unidad (char): Almacena la unidad de medida de la temperatura ('C' para Celsius, 'F' para Fahrenheit).
Implementa los siguientes métodos:
●	Termometro(float tempInicial, char unidadInicial): Constructor que inicializa la temperatura y la unidad de medida.
●	get y set de temperatura.
●	cambiarUnidad(char nuevaUnidad): Cambia la unidad de medida entre Celsius y Fahrenheit. Si la nueva unidad es diferente de la actual,
 convierte la temperatura a la nueva unidad.
○	Fórmula de conversión de Celsius a Fahrenheit: (C * 9/5) + 32
○	Fórmula de conversión de Fahrenheit a Celsius: (F - 32) * 5/9
●	getUnidad(): Devuelve la unidad actual de medida.

*/
class Termometro{
private:
  float _temp;
  char _unidad;

  public:
  Termometro(float tempInicial, char unidadInicial):_temp(tempInicial), _unidad(unidadInicial){}
  void setTemp(float temp){_temp = temp;}
  void setUnidad(char unidad){_unidad = unidad;}
  float getTemp(){return _temp;}
  char getUnidad(){return _unidad;}

  void cambiarUnidad(char nuevaUnidad){
    if(_unidad != nuevaUnidad){
      if(_unidad == 'C'){
        _temp = (_temp * 9/5) + 32;//paso de celsius a fahrenheit
        _unidad = 'F';
      }else{
        _temp = (_temp - 32) * 5/9;//paso de fahrenheit a celsius
        _unidad = 'C';
      }
    }
  }  
};

int main(){
  Termometro termometro(25, 'C');
  cout << "Temperatura inicial: " << termometro.getTemp() << " " << termometro.getUnidad() << endl;

  termometro.cambiarUnidad('F');
  cout << "Temperatura en Fahrenheit: " << termometro.getTemp() << " F" << endl;
  termometro.cambiarUnidad('C');
  cout << "Temperatura en Celsius: " << termometro.getTemp() << " C" << endl;
 
 
  return 0;
}