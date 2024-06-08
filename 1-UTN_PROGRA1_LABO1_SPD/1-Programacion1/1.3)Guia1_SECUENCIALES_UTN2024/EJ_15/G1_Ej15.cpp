/*15 La amplitud térmica es la diferencia entre la temperatura máxima y la
temperatura mínima en una zona y tiempo determinado. Dada la temperatura
máxima y la temperatura mínima de San Fernando de ayer, calcular y mostrar la
amplitud térmica.
NOTA: El usuario ingresará como temperatura máxima un valor mayor o igual al
de la temperatura mínima.*/

#include <iostream>
using namespace std;

int main(){
    float tMax, tMin, aTermica;

    cout << "Ingrese la temperatura maxima y la temperatura minima de San Fernando" << endl;
    cin >> tMax >> tMin;
    aTermica = tMax - tMin;

    cout << "La amplitud termica de San Fernando es : " << aTermica << " C°";

return 0;
}
