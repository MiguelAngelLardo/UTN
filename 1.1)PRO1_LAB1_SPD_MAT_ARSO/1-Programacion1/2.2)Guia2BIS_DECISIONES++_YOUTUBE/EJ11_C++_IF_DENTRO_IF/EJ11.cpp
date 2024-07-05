#include <iostream>

using namespace std;

/*11. Hacer un programa para ingresar tres números y luego mostrarlos ordenados
de menor a mayor.*/

int main(){
  int n1, n2, n3;

  cout << "Ingresa el numero 1: ";
  cin >> n1;
  cout << "Ingresa el numero 2: ";
  cin >> n2;
  cout << "Ingresa el numero 3: ";
  cin >> n3;

  if(n1 < n2 && n1 < n3)
  {
    cout << n1 << endl;
    if(n2 < n3)
    {
      cout << n2 << endl;
      cout << n3 << endl;
    }
    else
    {
      cout << n3 << endl;
      cout << n2 << endl; 
    }
  }
  else
  {
    if(n2 < n1 && n2 < n3) //  8  6  7
    {
      cout << n2 << endl;
      if(n1 < n3)
      {
        cout << n1 << endl;
        cout << n3 << endl;
      }
      else
      {
        cout << n3 << endl;
        cout << n1 << endl;
      }
    }
    else
    {
      cout << n3 << endl; // 7 8  6 
      if(n1 < n2)
      {
        cout << n1 << endl;
        cout << n2 << endl;
      }
      else
      {
        cout << n2 << endl;
        cout << n1 << endl;
      }  
    }
  }



  return 0;
}