#include <iostream>
using namespace std;

int main() {
 int num1, num2, num3, num4;

    cout << "Ingrese cuatro números: ";
    cin >> num1 >> num2 >> num3 >> num4;

    if (num1 <= num2 && num2 <= num3 && num3 <= num4) {
        cout << "Conjunto Ordenado" << endl;
    } else {
        cout << "Conjunto Desordenado" << endl;
    }
  return 0;
}