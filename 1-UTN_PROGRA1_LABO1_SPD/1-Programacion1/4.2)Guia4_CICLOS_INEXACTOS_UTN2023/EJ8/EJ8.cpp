#include <iostream>
using namespace std;

int main() {
    int numero, maximo, posicionMaximo, posicionActual;
    
    cout << "Ingrese una lista de números (finalice con 0):" << endl;
    cin >> numero;
    
    if (numero != 0) {
        maximo = numero;
        posicionMaximo = 1;
        posicionActual = 1;
    }
        
        while (numero != 0) {
            cin >> numero;

            posicionActual++;
            
            if (numero > maximo) {
                maximo = numero;
                posicionMaximo = posicionActual;
            }
        }
        
    cout << endl << "Máximo " << maximo << " Posición " << posicionMaximo << endl;
   
    return 0;
}