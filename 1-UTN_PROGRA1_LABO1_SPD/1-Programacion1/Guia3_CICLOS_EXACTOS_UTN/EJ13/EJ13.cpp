#include <iostream>
using namespace std;

int main() {
    int n, primerImpar, ultimoImpar;
    bool bandera = false;
    
    for (int x = 0; x < 8; x++){
        cin >> n;
        if (n % 2 != 0 && !bandera){
            primerImpar = n;
            bandera = true;
        }else if (n % 2 != 0){
            ultimoImpar = n;
        }
    }
    
    cout << "Primer Impar: " << primerImpar << endl << "ultimo impar: " << ultimoImpar;
 

    return 0;
}