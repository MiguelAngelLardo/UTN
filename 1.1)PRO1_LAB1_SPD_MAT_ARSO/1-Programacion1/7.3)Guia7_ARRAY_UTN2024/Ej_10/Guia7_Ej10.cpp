/*
10 Dada una lista de 20 números, cargarlos en un vector. Determinar e informar la
cantidad de “rupturas” que tiene el vector con respecto a un orden
estrictamente creciente. Ejemplo: el vector 1,3,4,2,4,4,6,8,1,7,9 tiene 3 rupturas.
*/


#include <iostream>
using namespace std;

 void cargarVector(int vec[], int tamanio);
 int contarRupturas(int vec[], int tamanio);


 void cargarVector(int vec[], int tamanio){
    for (int i=0;i<tamanio;i++){
        cin >> vec[i];
    }
 }
int contarRupturas(int vec[], int tamanio){
    int rupturas=0;
    for (int i = 1; i < tamanio; i++) {
        if (vec[i] <= vec[i - 1]) {
            rupturas++;
        }
    }
    return rupturas;
}


int main(){
    setlocale(LC_ALL, "Spanish");
    const int TAM =11;
    int vecNumeros[TAM];
    int rupturas;

    cout << "Ingrese " << TAM << " números en el vector "<< endl;
    cargarVector(vecNumeros,TAM);

    rupturas=contarRupturas(vecNumeros,TAM);
    if(rupturas>0){
        cout << "El vector no está estrictamente ordenado " << " tiene " << rupturas << " rupturas" <<endl;
    }
    else{
        cout << "El vector está estrictamente ordenado" << endl;
    }

return 0;
}
