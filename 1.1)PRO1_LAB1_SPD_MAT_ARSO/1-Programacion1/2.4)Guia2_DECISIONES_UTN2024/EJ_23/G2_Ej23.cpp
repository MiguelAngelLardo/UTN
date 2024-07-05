/*23 Hacer un programa para ingresar un número de mes y listar por pantalla a qué
bimestre corresponde ese mes. Tener en cuenta esta lista:
Mes 1 y 2. Bimestre 1. Mes 3 y 4. Bimestre 2. Mes 5 y 6. Bimestre 3.
Mes 7 y 8. Bimestre 4. Mes 9 y 10. Bimestre 5. Mes 11 y 12. Bimestre 6.
Resolver este ejercicio utilizando la menor cantidad de salidas de IF posibles, de
forma tal que si en un hipotético caso, hubiera años de 200 meses su diagrama
no deba ser modificado en tal situación.
Recordar también que la división directa con el operador / genera un resultado
con fracción. Por ejemplo si mes=7 y usted calcula bimestre=7/2 el resultado
que obtendrá es bimestre= 3.5, lo cual es incorrecto.*/

#include <iostream>
using namespace std;


int main(){
    int mes, bimestre, resto;

    cout << "Ingrese un numero de mes" << endl;
    cin >> mes;
    resto = mes % 2;

    if( resto !=0){
        bimestre = ((mes -resto)/2) +1;
    }else{
        bimestre = mes/2;
    }

    cout << "El mes " << mes << " corresponde al bimestre " << bimestre << endl;

return 0;
}
