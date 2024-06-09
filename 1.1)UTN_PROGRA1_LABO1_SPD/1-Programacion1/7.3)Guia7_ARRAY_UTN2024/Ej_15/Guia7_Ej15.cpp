/*
15 Dada una lista de 5 números, cargarlos en un vector. Armar luego otro vector
de 9 elementos donde por cada 2 elementos del vector original intercale el
promedio de ellos. Por ejemplo: [2, 4, 6, 8, 10], el vector queda: [2, 3, 4, 5, 6, 7,
8, 9, 10].
*/


#include <iostream>
using namespace std;

void cargarVector(int vec[], int tamanio);
void cargarVectorIntercalado(int vec[],int vec2[],int tamanio);
void mostrarVector(int vec[]);

void cargarVector(int vec[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cin >> vec[i];
    }
}
void cargarVectorIntercalado(int vec[],int vec2[]){
    int j=0;//indice para el vector original
    for(int i=0;i<9;i++){
        if(i%2==0){
            vec2[i]=vec[j];//posiciones pares tiene el valor del vector original
            j++;//actualizo el indice del vector cada dos pasos para no pasarme
        }
        else{
            vec2[i]=(vec[j-1] +vec[j])/2;//posiciones impares calculo el promedio
        }
    }
}

void mostrarVector(int vec[]) {
    for (int i = 0; i < 9; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main(){
    setlocale(LC_ALL, "Spanish");
    const int TAM = 5;
    int vecNumeros[TAM];
    int vecIntercalado[9];

    cout << "Ingrese " << TAM << " números en el vector:" << endl;
    cargarVector(vecNumeros, TAM);
    cargarVectorIntercalado(vecNumeros,vecIntercalado);

    cout << " Los números del nuevo vector son : " << endl;
    mostrarVector(vecIntercalado);

return 0;
}
