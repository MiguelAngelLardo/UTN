/*
9 Dada una lista de 20 números enteros, cargarlos en un vector. Determinar e
informar con un cartel aclaratorio si el vector está ordenado estrictamente en
forma creciente. Por ejemplo: el vector [1, 3, 5, 7, 9] está ordenado
estrictamente. El vector [1, 5, 3, 7] no lo está.
*/


#include <iostream>
using namespace std;
 void cargarVector(int vec[], int tamanio);
 bool estaOrdenado(int vec[], int tamanio);


 void cargarVector(int vec[], int tamanio){
    for (int i=0;i<tamanio;i++){
        cin >> vec[i];
    }
 }
bool estaOrdenado(int vec[], int tamanio){
    bool ordenado =true;
    int aux= vec[0];
    for(int i=0;i<tamanio;i++){
        if(vec[i]>=aux){
            aux=vec[i];
        }
        else{
            ordenado=false;
        }
    }
    return ordenado;
}


int main(){
    setlocale(LC_ALL, "Spanish");
    const int TAM =20;
    int vecNumeros[TAM];
    bool ordenado;

    cout << "Ingrese " << TAM << " números en el vector "<< endl;
    cargarVector(vecNumeros,TAM);
    ordenado=estaOrdenado(vecNumeros,TAM);
    if(ordenado){
        cout << "El vector está ordenado " << endl;
    }
    else{
        cout << "El vector no está ordenado" << endl;
    }

return 0;
}
