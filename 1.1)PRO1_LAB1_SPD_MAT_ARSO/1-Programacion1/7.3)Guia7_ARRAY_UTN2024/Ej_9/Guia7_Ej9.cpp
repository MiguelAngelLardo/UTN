/*
9 Dada una lista de 20 numeros enteros, cargarlos en un vector. Determinar e
informar con un cartel aclaratorio si el vector esta ordenado estrictamente en
forma creciente. Por ejemplo: el vector [1, 3, 5, 7, 9] est� ordenado
estrictamente. El vector [1, 5, 3, 7] no lo est�.
*/


#include <iostream>
using namespace std;

const int TAM =20;

void cargarVector(int vec[]);
bool estaOrdenado(int vec[]);




int main(){
    setlocale(LC_ALL, "Spanish");
    int vecNumeros[TAM];
    bool ordenado;

    cout << "Ingrese " << TAM << " numeros en el vector "<< endl;
    cargarVector(vecNumeros);
   
    ordenado=estaOrdenado(vecNumeros);
   
    if(ordenado){
        cout << "El vector esta ordenado " << endl;
    }
    else{
        cout << "El vector no esta ordenado" << endl;
    }

return 0;
}

void cargarVector(int vec[]){
    for (int i=0; i < TAM;i++){
        cin >> vec[i];
    }
}

bool estaOrdenado(int vec[]){
    bool ordenado =true;
    int aux= vec[0];
    for(int i = 1; i < TAM; i++){
        if(vec[i] >= aux){
            aux=vec[i];
        }
        else{
            ordenado=false;
        }
    }
    return ordenado;
}
