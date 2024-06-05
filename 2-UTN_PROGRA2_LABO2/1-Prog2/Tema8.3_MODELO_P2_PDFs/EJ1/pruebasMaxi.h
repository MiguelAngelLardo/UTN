#pragma once

template <typename T>
void MostrarVector(T vec[], int tam){
    for(int i=0; i<tam; i++){
        vec[i].Mostrar();
        cout<<endl;
    }
}


template <typename T>
int buscarPosicionMaximoDelVector(T vec[], int tam){
    int posMax=0;
    for(int i=1; i<tam; i++){
        if(vec[i].getIDequipo()>vec[posMax].getIDequipo()){
            posMax=i;
        }
    }
    return posMax;
}

template <typename T>
int MaximoValorVector(T *vec, int tam){
    bool Max=0;
    int posMax=0;
    for(int i=1; i<tam; i++){
        if(vec[i].getIDequipo()>vec[posMax].getIDequipo()){
            Max=vec[i].getIDequipo();
        }
    }
    return Max;
}

template <typename T>
void CargarVector(T vec[], int tam){
    for(int i=0; i<tam; i++){
        vec[i].Cargar();
    }
}

template <typename T>
void CargarMatriz(T **mat, int filas, int columnas){
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            mat[i][j].Cargar();
        }
    }
}























