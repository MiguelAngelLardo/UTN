#include <iostream>
using namespace std;

int main() {
 
 int mayor1, mayor2, n;
 
 for (int x = 0; x < 5; x++){
     cout << "vuelta " << x + 1 << "    ";
     cin >> n;
     
     if (x == 0){
       mayor1 = n;    
     }else if (n >= mayor1){
         mayor2 = mayor1;
         mayor1 = n;
     }else if (n > mayor2){
        mayor2 = n;
     }
 }
 
 cout << "Primer mayor: " << mayor1 << "Segundo mayor: " << mayor2;

    return 0;
}