/*
Leer 10 numeros y guardarlos en un vector. Determinar e informar los dos
ultimos numeros pares en el vector y sus respectivas posiciones en el mismo.
Suponer que habru al menos dos numeros pares.
*/


#include <iostream>
using namespace std;

const int TAM = 10;

//declaracion, firma, prototipo -> Parametro
void cargarVector(int vec[]);
void informarParesYPosicion(int vec[]);


int main(){
     setlocale(LC_ALL, "Spanish");
    int vecNumeros[TAM];
    int menorImpar,mayorPar;

    cout << "Ingresar " << TAM << " numeros al vector: " << endl;
    cargarVector(vecNumeros);//argumento de la funcion
    informarParesYPosicion(vecNumeros);

return 0;
}


//definicion
void cargarVector(int vec[]){
    for (int i=0; i < TAM; i++){
        cin >> vec[i];
    }
}

void informarParesYPosicion(int vec[]){
    int ultimoPar = 0, anteUltimoPar = 0;
    int posUltimo, posAnteUltimo;

    for (int i=0; i < TAM;i++){
        if(vec[i] % 2 == 0){
            if(i == 0){ //uso i como bandera
                ultimoPar = vec[i];
                posUltimo = i+1;
            }
            else{
                anteUltimoPar = ultimoPar;
                posAnteUltimo=posUltimo;
                ultimoPar=vec[i];
                posUltimo=i+1;
            }
        }//no necesito guardar impares
    }

    cout << "Ante ultimo numero par " << anteUltimoPar << ", posicion # " << posAnteUltimo<< endl,
    cout << "ultimo numero par " << ultimoPar << ", posicion # " << posUltimo<< endl;

}