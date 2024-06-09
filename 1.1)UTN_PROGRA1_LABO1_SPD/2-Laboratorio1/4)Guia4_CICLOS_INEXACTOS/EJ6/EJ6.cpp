#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{
 int numero, consecutivosNegativos = 0, numerosPares = 0, ternas = 0;

    while (numerosPares < 5) 
    {
        cout << "Ingrese un numero: ";
        cin >> numero;

        if (numero % 2 == 0) 
            numerosPares++;
        
        if (numero < 0) 
          consecutivosNegativos++;
        else 
          consecutivosNegativos = 0;
        
        //consecutivosNegativos = (numero < 0) ? consecutivosNegativos + 1 : 0;

        cout << "Consecutivos negativos : " << consecutivosNegativos << endl;

        if (consecutivosNegativos == 3) {
            ternas++;
            consecutivosNegativos = 0;
        }
    }

    cout << "Cantidad de ternas de numeros negativos consecutivos: " << ternas << endl;
}