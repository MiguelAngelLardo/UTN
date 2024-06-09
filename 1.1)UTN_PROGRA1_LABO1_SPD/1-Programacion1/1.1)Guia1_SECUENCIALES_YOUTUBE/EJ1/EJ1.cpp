#include <iostream> //esto posibilita el in y out

using namespace std; //esto me ahorra el std::cout y el std::cin

int main (){
  int numero;
  int numero2;
  int resultado;

  cout << "Por favor ingrese un numero: ";
  cin >> numero; 
  cout << "Ingrese otro numero por favor: ";
  cin >> numero2;

  resultado = numero + numero2;
  
  cout << endl;  
  cout << "EL resultado de sumar " << numero << " con " << numero2 << " es " << resultado;

  return 0;
}