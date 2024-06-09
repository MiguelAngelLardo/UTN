#include <iostream>
using namespace std;
 
int main(){
 
   char letra1 = 'A', letra2;
   int posicion;
 
   cout << "Ingresar letra: ";
   cin >> letra2;
 
   posicion=letra2-letra1;
 
   cout << "La diferencia de posiciones es de: " << posicion << endl;
 
   return 0;
}