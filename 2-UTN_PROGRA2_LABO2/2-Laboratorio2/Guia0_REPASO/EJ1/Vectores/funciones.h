#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///PROTOTIPO DE FUNCIONES
bool cargarVector(int vec[], int tam);
void mostrarVector(int *vec, int tam);
int maximoVector(int *vec, int tam);
int minimoVector(int *vec, int tam);

bool cargarVector(int vec[], int tam){
  int i;
  for (i = 0; i < tam; i++){
    cout << "INGRESE NUMERO: ";
    cin >> vec[i];
  }
  return true;
}

void mostrarVector(int *vec, int tam){
  for (int x = 0; x < tam; x ++){
    cout << vec[x] << endl;
  }
}

int maximoVector(int *vec, int tam){
  int posMax = 0;
  for (int i = 1; i < tam; i ++){
    if(vec[i] > vec[posMax]){
      posMax = i;
    }
  }
  return posMax;
}


int minimoVector(int *vec, int tam){
  int posMin = 0;
  for (int i = 1; i < tam; i ++)
    if(vec[i] < vec[posMin])
      posMin = i;

  return posMin;
}




#endif // FUNCIONES_H_INCLUDED
