#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
 
  int n, acumulador = 0;

  cout << "Ingrese un numero: ";
  cin >> n; 
  
  for (int x = 1; x < n; x ++){
    if (n % x == 0){
      acumulador += x;
    }
  }

  if (n == acumulador){
    cout << "Es perfecto";
  }else{
    cout << "No es perfecto";
  }
}