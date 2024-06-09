#include <iostream>

using namespace std;

int main (){
  int importeSinDes = 1500, importeConDesc = 1200;

  int porcentajeDesc = ((importeSinDes - importeConDesc)*100)/importeSinDes;
  
  cout << porcentajeDesc;

 
  return 0;
}