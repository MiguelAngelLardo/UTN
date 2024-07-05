#include <iostream> // Incluimos la librería iostream para entrada/salida estándar

using namespace std;

const int CANT_CAMIONES = 30; //30

void loteCarga(int [], int []);
void loteProceso(int [], int  [], int [], int [],  int [], int [][31], int [][2]);

void calcularPiezasRotas(int, int , int , int [], int []); //TPD
void mostrasPtoD(int []);//PTOD
void acumularKM(int, int, int [], int [], int []); //PTOE
int mostrarPuntoE(int [], int []);//PTOE 
void acumularRoturas(int, int, int, int [], int [][31], int [][2]); 
void mostrarPuntoF(int [], int [][31], int [][2]);

int main()
{
  int vCamion [CANT_CAMIONES], vCodChofer[CANT_CAMIONES];
  int mes[31] = {}, menorPiezasRotas[31] = {}; //PTD
  int maxKM[CANT_CAMIONES] = {}, choferMaxKm[CANT_CAMIONES] = {}; //PTE 
  int mAcumRotura[30][31] = {}, mCantRotura[30][2]; //PTF
  
  loteCarga(vCamion, vCodChofer);
  loteProceso(vCodChofer, mes, menorPiezasRotas, maxKM, choferMaxKm, mAcumRotura,  mCantRotura);
  mostrasPtoD(mes);
  cout << "El chofer con max cantidad de KM recorridos es:  " << mostrarPuntoE(maxKM, choferMaxKm) << endl;
  mostrarPuntoF(vCodChofer, mAcumRotura, mCantRotura);



  return 0;
}

void loteCarga(int vCamion [], int codChofer[]){
  for(int x = 0; x < CANT_CAMIONES; x++){
    cout << x+1 << ")Ingrese el numero de camion (1 al 30): ";
    cin >> vCamion[x];
    cout << x+1 << ")Ingrese el codigo del chofer(3 digitos, no correlativos): ";
    cin >> codChofer[x];
  }

}

void loteProceso (int vCodChofer[], int mes [], int menorPiezasRotas [], int maxKM[], int choferMaxKm[], int mAcumRotura [][31], int mCantRotura [][2] ){
  int dia, codChofer, cantKM, cantPiezaRota;

  cout << "Ingrese el dia (1 a 31): ";
  cin >> dia;
  while (dia != 0)
  {
    cout << "Ingrese el codigo de chofer (3 digitos, no correlativos): ";
    cin >> codChofer;
    cout << "Cantidad de km del viaje: ";
    cin >> cantKM;
    cout << "Cantidad de piezas rotas en ese viaje: ";
    cin >> cantPiezaRota;

    calcularPiezasRotas(dia, codChofer, cantPiezaRota, mes, menorPiezasRotas);
    acumularKM(cantKM, codChofer, vCodChofer, maxKM, choferMaxKm);
    acumularRoturas(dia, cantPiezaRota, codChofer, vCodChofer, mAcumRotura, mCantRotura);


   cout << "Ingrese el dia (1 a 31): ";
   cin >> dia;
  }
}

void calcularPiezasRotas(int dia, int codChofer, int cantPiezaRota, int mes[], int menorPiezasRotas []){
  
  if(menorPiezasRotas[dia-1] == 0){
    menorPiezasRotas [dia-1] = cantPiezaRota;
    mes[dia-1] = codChofer;
  }else if(cantPiezaRota < menorPiezasRotas[dia-1]){
    menorPiezasRotas [dia-1] = cantPiezaRota;
    mes[dia-1] = codChofer; 
  }
}

void mostrasPtoD(int mes[]){
  cout << "PUNTO A" << endl;
  for(int x = 0; x < 31; x++){
    if(mes[x] != 0){
      cout << "Dia " << x+1 << " chofer: " << mes [x] << endl; 
    }
  }
}

void acumularKM(int cantKM, int codChofer, int vCodChofer [], int maxKM [], int choferMaxKm []){
  for(int x = 0; x < CANT_CAMIONES; x++){
    if(codChofer == vCodChofer[x]){
      maxKM[x] += cantKM;
      choferMaxKm[x] = codChofer;
    }
  }  
}

int mostrarPuntoE(int maxKM [], int choferMaxKm []){
  int choferMax = choferMaxKm[0];
  int maxKmilometros = maxKM[0];
  
  for(int x = 1; x < CANT_CAMIONES; x ++){
    if(maxKmilometros > maxKM[x]){
      choferMax = choferMaxKm[x];
      maxKmilometros = maxKM[x]; 
    }
  }
  return choferMax;
}

void acumularRoturas(int dia, int cantPiezaRota, int codChofer, int vCodChofer [], int mAcumRotura [][31], int mCantRotura [][2]){
  for(int x = 0; x < 30 ; x++){
    if(codChofer == vCodChofer[x]){
      mAcumRotura[x][dia-1] += cantPiezaRota;
      if(dia <= 15){
        mCantRotura[x][0] ++;
      }else{
        mCantRotura[x][1] ++;
      }
    }
  }
}

void mostrarPuntoF(int vCodChofer[], int mAcumRotura [][31], int mCantRotura [][2]){
  
  for(int i = 0; i < 30; i++)
  {
    int acc = 0;
    for(int j = 0;j < 15; j++)
    {
      acc += mAcumRotura[i][j];
    }

    cout << "Codigo Chofer: " << vCodChofer[i] << " | ";
    cout << "Pomedio de rotura Q1: " << acc / mCantRotura[i][0] << " | ";

    acc = 0;
    for(int j = 16;j < 31; j++)
    {
      acc += mAcumRotura[i][j];
    }
    cout << "Pomedio de rotura Q2: " << acc / mCantRotura[i][1];
    cout << endl; 
  }
}