/*5 Un comercio vende tres marcas de alfajores distintas A, B y C. Hacer un
programa para ingresar por teclado la cantidad de alfajores vendidos de cada
una de las tres marcas y luego se informe el porcentaje de ventas para cada
una de ellas.
Ejemplo. Si se ingresa 100, 25 y 75 como cantidades vendidas entonces el
programa calculará e informará A: 50%, B: 12,50% y C: 37,50%.*/

#include <iostream>
using namespace std;

int main(){
float A,B,C,total,porcentajeA, porcentajeB,porcentajeC;
cout << "Ingrese la cantidad vendida de los 3 variedad de alfajores " << endl;
cin >> A >> B >> C;
total = A + B + C;
porcentajeA = (A/ total)*100;
porcentajeB = (B/total)*100;
porcentajeC = (C/total)*100;
cout << "El porcentaje vendido de alfajores A es : " << porcentajeA << "%" << endl;
cout << "El porcentaje vendido de alfajores B es : " << porcentajeB << "%" << endl;
cout << "El porcentaje vendido de alfajores B es : " << porcentajeC << "%" << endl;
return 0;
}
