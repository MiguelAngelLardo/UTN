#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema
#include <vector> //es para verctor dinamico STL
#include <ctime> //es para la hs
#include <cstdlib>  // Necesario para std::rand y std::srand

//setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
using namespace std;// Usamos el espacio de nombres estándar

/*****ARRAY*****/
/*****FUNCIONES*****///pepa pig apunta a A - la guitarra de pepa es pepa misma

/*
  int *punteroA = &a;
  cout << "Memory Address of 'a': " << &a << endl;
  cout << "punteroA has the memory adress of 'a': " << punteroA << endl;
  cout << "&punteroA has its own memory Adress : " << &punteroA << endl;
  cout << "*punteroA has a value of 'a': " << *punteroA << endl;  */

/*****FUNCIONES*****/
const int TAM_CARGA = 20;
const int TAM_CAMION = 100;

void loteCarga(int vTarifa[], float vImportePorKM[], int tam);
void loteProceso(int *vTarifa, float *vImportePorKM, float *vTotalRecaudadoPorTarifa, float *vTotalRecaudadoPorCamion, int *vAcumuladorKilometrosPorCamion, int tammm);
int buscarIndex(int [], int, int);
void mostrarTotalRecaudadoPorTarifa(int vecTarifa[], float vecTotalRecaudado[], int tam);
void mostrarTotalRecaudadoPorCamion(float vTotalRecaudadoPorCamion[], int tamCamion, int vCamiones[]);
void burbujeroTotalRecCamion(float vTotalRecaudadoPorCamion[], int tamCamion, int vCamionesIndice[]);
void mostrarCamionQueRecorrioMenorCantidadKM(int vAcumuladorKilometrosPorCamion [], int tamCamion);
void inicializacionDeCamiones(int vCamiones[], int tamCamiones);
void cargadorDeKmACero(int vCamiones[], int tamCamiones);

int main()
{
 
 int vTarifa[TAM_CARGA];
 float vimportePorKM[TAM_CARGA];
 float vtotalRecaudadoPorTarifa[TAM_CARGA] = {}; //PTO A
 float vTotalRecaudadoPorCamion[TAM_CAMION] = {};//PTOB
 int vCamiones[TAM_CAMION];
 int vAcumuladorKilometrosPorCamion[TAM_CAMION];//PTO C

 inicializacionDeCamiones(vCamiones, TAM_CAMION); //ahora  vCamion empieza en 1 y termina en 100. 
 cargadorDeKmACero(vAcumuladorKilometrosPorCamion, TAM_CAMION);//ahora los KM se inicializan en cero

 loteCarga(vTarifa, vimportePorKM,TAM_CARGA);
 loteProceso(vTarifa, vimportePorKM, vtotalRecaudadoPorTarifa, vTotalRecaudadoPorCamion, vAcumuladorKilometrosPorCamion, TAM_CARGA);
 mostrarTotalRecaudadoPorTarifa(vTarifa, vtotalRecaudadoPorTarifa, TAM_CARGA);
 mostrarTotalRecaudadoPorCamion(vTotalRecaudadoPorCamion, TAM_CAMION, vCamiones);
 mostrarCamionQueRecorrioMenorCantidadKM(vAcumuladorKilometrosPorCamion, TAM_CAMION);
 
  return 0;
}

void inicializacionDeCamiones(int vCamiones[], int tamCamiones){
  for (int x = 0; x < tamCamiones; x ++){
    vCamiones[x] = x+1;
  }
}

void loteCarga(int vTarifa[], float vImportePorKM[], int tam){
  for(int x = 0; x < tam; x++){
    cout << x+1 << ") Ingrese el numero de tarifa (4 numeros): ";
    cin >> vTarifa[x];
    cout << x+1 << ") Ingrese el numero de Importe Por Km: ";
    cin >> vImportePorKM[x];
  }
}

void loteProceso(int *vTarifa, float *vImportePorKM, float *vTotalRecaudadoPorTarifa, float *vTotalRecaudadoPorCamion, int *vAcumuladorKilometrosPorCamion, int tammm){
  int numCamion, numTarifa, kmRecorridos;

  cout << "Ingrese el numero de camion (1 a 100)(corta con -1): ";
  cin >> numCamion;

  int indice;
  while(numCamion > 0){
    cout << "Ingrese el numero de tarifa(4 numeros, son 20 tipos diferentes): ";
    cin >> numTarifa;
    cout << "Ingrese los km recorridos: ";
    cin >> kmRecorridos;

    indice = buscarIndex(vTarifa, numTarifa, tammm);
    vTotalRecaudadoPorTarifa[indice] += kmRecorridos*vImportePorKM[indice];
    vTotalRecaudadoPorCamion[numCamion-1] += kmRecorridos*vImportePorKM[indice];
    vAcumuladorKilometrosPorCamion[numCamion-1] += kmRecorridos;
    
    cout << "Ingrese el numero de camion (1 a 100)(corta con -1): ";
    cin >> numCamion;
  }
}


int buscarIndex(int vTarifa[], int numTarifa, int tam){
  for(int x = 0; x < tam; x++){
    if(vTarifa[x] == numTarifa){
      return x;
    }
  }  
}

void mostrarTotalRecaudadoPorTarifa(int vecTarifa[], float vecTotalRecaudado[], int tam){
  cout << endl << "TOTAL RECAUDADO POR TARIFA: " << endl;
  for(int x = 0; x < tam; x++){
    cout << x+1 << ") Tarifa #" << vecTarifa[x] << " tiene un total recaudado de: $" << vecTotalRecaudado [x] << endl; 
  }
}

void mostrarTotalRecaudadoPorCamion(float vTotalRecaudadoPorCamion[], int tamCamion, int vCamiones[]){
  burbujeroTotalRecCamion(vTotalRecaudadoPorCamion, tamCamion, vCamiones);
  cout << endl << "TOTAL RECAUDADO POR CAMION: " << endl;
  for (int x = 0; x < tamCamion; x ++){
    cout << "Camion " << vCamiones[x] << " TOTAL RECAUDACION $" << vTotalRecaudadoPorCamion[x] << endl;
  }

}

void burbujeroTotalRecCamion(float vTotalRecaudadoPorCamion[], int tamCamion, int vCamionesIndice[]){
  int aux;
  for (int y = 0; y < tamCamion; y ++){
    for (int x = 0; x < tamCamion - 1; x ++){
      if(vTotalRecaudadoPorCamion[x] < vTotalRecaudadoPorCamion[x+1]){
        aux = vTotalRecaudadoPorCamion[x+1];
        vTotalRecaudadoPorCamion[x+1] = vTotalRecaudadoPorCamion[x];
        vTotalRecaudadoPorCamion[x] = aux;
        aux = vCamionesIndice[x+1];
        vCamionesIndice[x+1] = vCamionesIndice[x];
        vCamionesIndice[x] = aux;
      }
    }
  }
}

void cargadorDeKmACero(int vCamiones[], int tamCamiones){
  for(int x = 0; x < tamCamiones; x ++){
    vCamiones[x] = 0;
  }
}

void mostrarCamionQueRecorrioMenorCantidadKM(int vAcumuladorKilometrosPorCamion [], int tamCamion){
  int menorKilometraje = vAcumuladorKilometrosPorCamion[0];
  int numeroCamionMenorKilometraje = 1;
  
  cout << endl << "MENOR KILOMETRAJE EN TOTAL ENTRE TODOS LOS CAMIONES: " << endl;
  for(int x = 1; x < tamCamion; x ++){
    if (vAcumuladorKilometrosPorCamion[x] != 0 && vAcumuladorKilometrosPorCamion[x] < menorKilometraje){
      menorKilometraje = vAcumuladorKilometrosPorCamion[x];
      numeroCamionMenorKilometraje = x + 1;
    } 
  }

  cout << "El Numero de camion que recorrio la menor cantidad de KM es: " << numeroCamionMenorKilometraje << " y el kilometraje es: " << menorKilometraje;

}