#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
 
 int n;

cout << "Ingrese un numero: ";
 cin >> n; 

 cout << "Divisores: " << endl;
 for (int x = 1; x <= n; x++){
  if(n % x == 0 && x % 2 == 0){
    cout << x;
    if (n != x){
      cout << ", ";
    }
  } 
 }
}