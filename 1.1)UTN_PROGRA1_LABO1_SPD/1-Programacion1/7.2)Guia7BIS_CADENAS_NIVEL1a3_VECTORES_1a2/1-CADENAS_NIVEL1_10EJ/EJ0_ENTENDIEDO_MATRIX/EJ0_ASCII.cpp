#include <iostream>
using namespace std;
/*
Realiza la diferencia entre A y B
*/

int main (){
    char A = 'A'; // a vale 61
    char B = 'B'; // b vale 62

    cout << "CUANTO VALE A " << (int)A << endl;
    cout << "CUANTO VALE B " << (int)B << endl;

    int diferencia = B - A;
    cout << "La diferencia entre A y B es: " << diferencia;



  return 0;
}