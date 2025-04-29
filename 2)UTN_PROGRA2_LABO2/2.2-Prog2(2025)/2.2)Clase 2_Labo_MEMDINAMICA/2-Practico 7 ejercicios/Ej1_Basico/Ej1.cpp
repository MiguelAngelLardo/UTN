#include <iostream>

using namespace std;

int main() {
  int *vDinEntero = nullptr;
  int n;

  cout << "Ingrese el tamaño del vector: ";
  cin >> n;

  vDinEntero = new int[n];

  if(vDinEntero == nullptr) {
    exit(500);
  }

  for(int i = 0; i < n; i++) {
    cout << "Ingrese un numero: ";
    cin >> vDinEntero[i];
  }
  
  cout << "mostrando vector: " << endl;

  for(int i = 0; i < n; i++) {
    cout << vDinEntero[i] << endl;
  }  

  delete []vDinEntero;

  return 0;
}

/*
Escribe un programa que solicite al usuario el tamaño de un array de enteros, lo
cree dinámicamente utilizando new, el usuario debe poder cargar el array y
mostrarlo, y luego libere la memoria con delete*/