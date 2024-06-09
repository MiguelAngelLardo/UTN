#include <iostream>
using namespace std;

int main() {
  int minimo, contador = 0, n;
  
  for(int x = 0; x < 8; x ++){
      cin >> n;
      
      if (x == 0){
        minimo = n;
      }
      
      if (n >= minimo){
          minimo = n;
          contador ++;
      }
  }
 
 if(contador == 8){
     cout << "Conjunto ordenado";
 }else{
     cout << "Conjunto no ordenado";
 }

    return 0;
}