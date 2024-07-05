#include <iostream>
using namespace std;

int main() {
  int kilovatio, totalPagar; 

  cin >> kilovatio;

  if(kilovatio <= 100){
    totalPagar = kilovatio * 100;
  }else if (kilovatio <= 200){
    totalPagar = 100 * 10 + (kilovatio - 100) * 12;
  } else{
    totalPagar = 100 * 10 + 100 * 12 + (kilovatio - 200) * 15;
  }

  cout << totalPagar;


  return 0;
}