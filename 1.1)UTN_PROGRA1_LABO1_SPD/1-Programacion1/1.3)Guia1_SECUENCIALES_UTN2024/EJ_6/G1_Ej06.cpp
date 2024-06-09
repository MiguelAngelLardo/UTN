/*6
Hacer un programa para que un comercio ingrese por teclado la recaudación en pesos para cada una
de las cuatro semanas del mes. El programa debe listar la recaudación promedio por semana y el
porcentaje de recaudación por semana.
Ejemplo. Si se ingresa $1600, $1200, $4800 y $400 se listará como recaudación promedio $2000 y
como porcentajes por semana: 20%, 15%, 60% y 5%.*/

#include <iostream>

using namespace std;

int main(){
int semana1,semana2,semana3,semana4, total, promedio1,promedio2,promedio3,promedio4, promedioMes;
cout << "Ingrese la recaudación de las 4 semanas del mes"<< endl;
cin >> semana1 >> semana2 >> semana3 >> semana4;
total  = semana1 +semana2 + semana3 + semana4;
promedioMes = total/4;
promedio1 = (semana1*100)/total;
promedio2 = (semana2*100)/total;
promedio3 = (semana3*100)/total;
promedio4 = (semana4*100)/total;

cout << "El promedio de recaudacion mensual es : $" << promedioMes << endl;
cout << "El promedio de recaudacion de la semana 1 es : " << promedio1 << "%"<< endl;
cout << "El promedio de recaudacion de la semana 2 es : " << promedio2 << "%"<< endl;
cout << "El promedio de recaudacion de la semana 3 es : " << promedio3 << "%"<< endl;
cout << "El promedio de recaudacion de la semana 4 es : " << promedio4 << "%"<< endl;



return 0;
}
