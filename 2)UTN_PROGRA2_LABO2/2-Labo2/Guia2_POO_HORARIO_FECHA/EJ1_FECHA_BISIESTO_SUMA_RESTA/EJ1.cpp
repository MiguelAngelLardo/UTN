#include <iostream>
using namespace std;
#include "Fecha.h"
int main(){
  Fecha f(2, 3, 2004);
;

  cout << endl;
  f.restarDias(5);
  cout << f.toString();


  return 0;
}