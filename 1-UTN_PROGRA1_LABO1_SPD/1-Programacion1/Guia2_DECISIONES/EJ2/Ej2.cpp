#include <iostream>

using namespace std;

int main(){
  int n1, n2;

  cout << "Ingrese un numero: ";
  cin >> n1;
  cout << "Ingrese un numero: ";
  cin >> n2;

  if(n1 % n2 == 0){
    cout << "MULTIPLO";
  }else{
    cout << "NO ES MULTIPLO";
  }


  return 0;
}