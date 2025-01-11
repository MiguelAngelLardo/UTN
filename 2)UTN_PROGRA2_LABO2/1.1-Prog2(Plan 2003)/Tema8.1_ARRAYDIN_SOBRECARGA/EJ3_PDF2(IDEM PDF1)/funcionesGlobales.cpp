#include<iostream>

using namespace std;

#include"funcionesGlobales.h"


void CargarVector(int vec[], int tam, int valor){
    for(int i=0; i<tam; i++){
        vec[i]=valor;
    }
}