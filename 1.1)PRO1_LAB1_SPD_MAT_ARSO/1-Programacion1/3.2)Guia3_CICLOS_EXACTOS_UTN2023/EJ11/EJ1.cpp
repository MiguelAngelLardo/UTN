#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int maxNeg, minPos, n;
  bool banderaNeg, banderaPos = false;

  for(int x=0; x < 10; x ++) {
    cout << x+1 << ") Ingrese un numero: ";
    cin >> n;

    if (!banderaNeg && n < 0){
      banderaNeg = true;
      maxNeg = n;
    }else if (!banderaPos && n >= 0){
      banderaPos = true;
      minPos = n;
    }else if (n < 0 && n > maxNeg){
      maxNeg = n;
    }else if (n >= 0 && n < minPos){
      minPos = n;
    }
  }

  cout << endl << "maxNeg: "  << maxNeg << " minPos " << minPos; 

}