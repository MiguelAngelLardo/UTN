/*3 4 Hacer un programa para ingresar por teclado dos números y luego informar por
pantalla la diferencia absoluta entre ambos.
Ejemplo A: Si se ingresan 3 y 8 se emite 5. Si se ingresan 8 y 3 se emite 5.
Ejemplo B: Si se ingresan -3 y 9 se emite 12. Si se ingresan -12 y -1 se emite 11.
Ejemplo C: Si se ingresan -3 y -9 se emite 6. Si se ingresan -12 y -9 se emite 3.
Importante: Verifique que el programa emite SIEMPRE UN VALOR POSITIVO
porque la diferencia absoluta siempre es un valor positivo.*/

#include <iostream>
using namespace std;

int main(){
    int num1, num2, dAbsoluta;
    cout << "Ingrese dos numeros"<< endl;
    cin >> num1 >> num2;
    dAbsoluta = num1 - num2;

    if (dAbsoluta < 0){
        dAbsoluta = dAbsoluta * -1;
    }
    cout << "La diferencia absoluta entre " << num1 << " y " << num2 << " es: " << dAbsoluta;


return 0;
}
