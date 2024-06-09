#include <iostream>
using namespace std;

int main() {
  

  for (int i = 1; i <= 1000; i ++)
  {     
    int contadorPrimo = 0;
    
    for(int x = 1; x <= i; x ++)
    {
      if(i % x == 0)
        contadorPrimo ++;      
    }

    if(contadorPrimo == 2)
      cout << i << endl;
  }
	return 0;
}