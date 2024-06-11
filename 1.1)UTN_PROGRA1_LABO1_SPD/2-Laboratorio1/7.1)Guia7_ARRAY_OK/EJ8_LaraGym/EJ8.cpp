#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;// Usamos el espacio de nombres estándar

/*****ARRAY*****/
/*
MATRIZ (BI DIMEN)
      1 2 3 4 5 6 7 8 9 10
101   5 0 8                -> min total del alumno
102
103
-------------------------------
    min total 
*/

/*****ARRAY*****/

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
  // 50 workouts => numberTraining(1-9999), client(101-150), workout type(1-10), training time(minutes)

  int trainigNumber, clientID, workType, workTime;
  int vectTimeperCliente[50] = {}; //Tiempo total de entrenamiento por cliente
  int matClientexTipoEntreno_Min[20][10] = {}; //20 clientes en fila y 10 entreno en columna - //Punto 1 al 5
  int matclientexTipoEntreno_Veces[20][10] = {};//cual fue el maximo entreno q hizo
  int maxTiempo = 0, maxNumEntrenamiento = 0; //punto 4, mayor tiempo de entreno y numero cliente
  int maxSesionesTipoEntrenamiento = 0, tipoEntrenamientoMasSesiones = 0; // punto 6
  int maxExtensoEntrenamientoTODOS = 0, maxNroMaxExtensoTODOS = 0;

  cout << "Enter training number (Finish Whit Zero) (1-9999): ";
  cin >> trainigNumber;

  while(trainigNumber != 0)
  {
    cout << "Enter client ID (101-150): ";
    cin >> clientID;
    cout << "Enter training type(1-10): ";
    cin >> workType;
    cout << "Enter training time (minutes): "; 
    cin >> workTime;

    vectTimeperCliente[clientID - 101] += workTime; //Pinto 1 
    matClientexTipoEntreno_Min[clientID - 101][workType-1] += workTime; //Punto 1 
    matclientexTipoEntreno_Veces[clientID - 101][workType-1] ++; //punto 6

    if(workTime > maxExtensoEntrenamientoTODOS){
      maxExtensoEntrenamientoTODOS = workTime;
      maxNroMaxExtensoTODOS = workType;
    }

    cout << "=========================================" << endl;
    cout << "Enter training number(Finish Whit Zero): ";
    cin >> trainigNumber;
  }

   cout << "PUNTO 1 - con Vector" << endl;
    for(int i = 0; i<20; i ++){
      int horas, minutos;
      horas = vectTimeperCliente[i] / 60;
      minutos =  vectTimeperCliente[i] % 60;
      cout << " VUELTA " << i << "Cliente: " << i+101 << " - Tiempo Entrenamiento: " << horas << ":" << minutos << endl; 
    }

    cout << endl << "PUNTO 1 - con Matriz " << endl;
    for(int filaPorClientes = 0; filaPorClientes<20; filaPorClientes++){
      int minutosTotales = 0;
      for(int columnasEntrenamiento = 0; columnasEntrenamiento<10; columnasEntrenamiento++){
        minutosTotales += matClientexTipoEntreno_Min[filaPorClientes][columnasEntrenamiento];
      }
    int horas, minutos;
    horas = minutosTotales / 60;  // Corregir aquí
    minutos = minutosTotales % 60;  // Corregir aquí
    cout << "Cliente: " << filaPorClientes + 101 << " - Tiempo Entrenamiento: " << horas << ":" << minutos << endl;
    }

    cout << endl << "PUNTO 2 - por cada cliente el entrenamiento que realizo " << endl;
    for (int f = 0; f < 20; f++)    {
        cout << "Cliente " << f + 101 << ": realizo los siguientes entrenamientos ";
        for (int c = 0; c < 10; c++){
            if (matClientexTipoEntreno_Min[f][c] != 0){
                cout << c + 1 << " ";
            }
        }
        cout << endl;
    }

    cout << endl << "PUNTO 3 - Por cada cada cliente y tipo de entrenamiento, la cantidad total de minutos entrenados. Solo listar aquellos registros que sean superiores a 0 " << endl;
    for(int f = 0; f < 20; f ++)
    {
      int tiempoTotal = 0;
      cout << "Cliente " << f + 101 << " MINUTOS TOTALES: ";
      for(int c = 0; c<10; c++){
        tiempoTotal += matClientexTipoEntreno_Min[f][c];  
      }
      cout << tiempoTotal << endl;
    }
    
    maxTiempo = matClientexTipoEntreno_Min[0][0];
    maxNumEntrenamiento = 0; //indice cero
    cout << endl << "PUNTO 4 - El numero de cliente que mas tiempo haya entrenado. " << endl;
    for(int f = 0; f < 20; f ++)
    {
      int tiempoTotal = 0;
      for(int c = 0; c<10; c++){
        tiempoTotal += matClientexTipoEntreno_Min[f][c];  
      }
    // Actualizamos el máximo
    if (tiempoTotal > maxTiempo){
        maxTiempo = tiempoTotal;
        maxNumEntrenamiento = f + 101;
    }

    }
    cout << "Cliente con más tiempo: " << maxNumEntrenamiento << " - Tiempo total: " << maxTiempo << " minutos." << endl;

    cout << endl << "PUNTO 5 - Los tipos de entrenamiento que no se realizaron por ningún cliente" << endl;
    for(int c = 0; c<10; c++){ 
      bool tipoNoRealizado = true;
      for(int f = 0; f<20; f++){
        if(matClientexTipoEntreno_Min[f][c] != 0)
          tipoNoRealizado = false;
        
      }
      if(tipoNoRealizado)
        cout << "Tipo de entrenamiento " << c + 1 << " no realizado por ningun cliente. " << endl;
    }

    cout << endl << "PUNTO 6 - Por cada cliente, el tipo de entrenamiento que más sesiones haya realizado" << endl;
    for (int f = 0; f < 20; f++){
      maxSesionesTipoEntrenamiento = 0;
      tipoEntrenamientoMasSesiones = 0;
      cout << "Cliente " << f + 101 << ": ";
      for (int c = 0; c < 10; c++)
      {
        if (matclientexTipoEntreno_Veces[f][c] > maxSesionesTipoEntrenamiento){
            maxSesionesTipoEntrenamiento = matclientexTipoEntreno_Veces[f][c];
            tipoEntrenamientoMasSesiones = c + 1;
        }
      }
      cout << "Tipo de entranmiento " << tipoEntrenamientoMasSesiones << " con " << maxSesionesTipoEntrenamiento << " sesiones." << endl;
    }

    cout << endl << "PUNTO 7 -El numero de entrenamiento mas extenso en minutos" << endl;
    cout << "El numero de entrenamiento mas extenso: " << maxNroMaxExtensoTODOS << ". Minutos :" << maxExtensoEntrenamientoTODOS << endl; 
    
  return 0;

}