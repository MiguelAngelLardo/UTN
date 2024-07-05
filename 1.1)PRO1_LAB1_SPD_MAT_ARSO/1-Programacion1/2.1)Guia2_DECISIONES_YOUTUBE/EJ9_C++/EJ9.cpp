#include <iostream>

using namespace std;

/*Hacer un programa para ingresar cinco números distintos y luego mostrar por
pantalla el mayor y el menor de ellos*/

int main (){

int n1, n2, n3, n4, n5;
int mayor, menor;


cout << "ingrese un numero: ";
cin >> n1;
cout << "ingrese otro numero: ";
cin >> n2;
cout << "ingrese otro numero: ";
cin >> n3;
cout << "ingrese otro numero: ";
cin >> n4;
cout << "ingrese otro numero: ";
cin >> n5;

if (n1 > n2){
  mayor = n1;
  menor = n2;
}else{
  mayor = n2;
  menor = n1;
}

if (n3 > mayor){
  mayor = n3;
}else if(n3 < menor){
  menor = n3;
}

if (n4 > mayor){
  mayor = n4;
}else if(n4 < menor){
  menor = n4;
}

if (n5 > mayor){
  mayor = n5;
}else if(n5 < menor){
  menor = n5;
}

cout << "El numero mayor es: " << mayor << endl;
cout << "El numero menor es: " << menor;

return 0;
}