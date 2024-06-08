#include <iostream>
using namespace std;

int main() {
   
   int n, primerImpar, segundoImpar, contador = 0;
   
   for (int x = 0; x < 7; x ++){
       cin >> n;
       
       if (n % 2 != 0 && contador < 1){
           primerImpar = n;
           contador ++;
       }else if (n % 2 != 0 && contador < 2){
           segundoImpar = n;
           contador ++;
       }
   }
   
   cout << endl << "Primer impar: " << primerImpar << endl << "Segundo impar: " << segundoImpar;  
   

    return 0;
}