#include <iostream>
#include <iomanip>
#include <regex>

using namespace std;

//las constantes 
const int CANTIDAD_BANCOS = 3;
const int  CANTIDAD_ANIOS = 3;

const string NOMBRES[CANTIDAD_BANCOS] = {"Provincia", "Nacion", "Hipotecario"};
const int ANIO_ACTUAL = 2025-1;

//objeto struct
struct Banco {
  string nombre;
  float vTasaAnual[CANTIDAD_ANIOS];
  float promedio = 0.0; //promedio de las 3 anios (vector)
  float tasaTrimestral = 0.0;//considerando el promedio de los 3 años
  float tasaMensual = 0.0; // considerando el promedio de los 3 anios
};

//Carga nombre de Bancos, TNA - Capita, validaciones
void cargaNombreBancos(Banco vBancos[]);
void cargaTasaAnualCapital(Banco vBancos[], float &capitalInicial);
float validarTasaCapital(Banco vBancos [], int i, int j, float &capitalInicial);

//Puntos para Resolucion
void mostrarPunto3a(Banco vBancos[], float capitalInicial);
void mostrarPunto3b(Banco vBancos[], float capitalInicial);
void mostrarPunto3c(Banco vBancos[], float capitalInicial);

//Menu principal
void menu();

int main()
{
  menu();
  return 0;
}


void cargaNombreBancos(Banco vBancos[]){
  for(int i = 0; i < CANTIDAD_BANCOS; i++){
    vBancos[i].nombre = NOMBRES[i]; 
  }
}

float validarTasaCapital(Banco vBancos [], int i, int j, float &capitalInicial){
  string entrada;
  bool valido;  
  regex entradaTestigo(("^ [0-9]+(\\.[0-9]+)?$"));   
  
  if(i == 0 && j == 0){ //valido el capital inicial
    cout << "Ingrese el CAPITAL INICIAL: $";
    do{
      cin >> entrada; //no uso getline(cin, entrada) ya q no hace falta
      valido = regex_match(entrada, entradaTestigo);
      if(!valido) cout << "Por favor ingrese un capital valido: $";
    }while(!valido); 
    capitalInicial = stof(entrada); 
    cout << endl; 
  }
  
  cout << "Ingrese para el banco " << vBancos[i].nombre << " la tasa anual del anio " << ANIO_ACTUAL - j << ": ";
  do{
    cin >> entrada; //no uso getline(cin, entrada) ya q no hace falta
    valido = regex_match(entrada, entradaTestigo);
    if(!valido) cout << "Por favor ingrese un valor valido: ";
  }while(!valido);  

  return stof(entrada);  //stof castea string a float
}

void cargaTasaAnualCapital(Banco vBancos[], float &capitalInicial){
  for(int i = 0; i < CANTIDAD_BANCOS; i++){
    for(int j = 0; j < CANTIDAD_ANIOS; j++){
      vBancos[i].vTasaAnual[j] = validarTasaCapital(vBancos, i, j, capitalInicial);
      vBancos[i].promedio += vBancos[i].vTasaAnual[j]; //acumulo para luego sacar el  promedio
    }
    cout << endl;
  }

  cout << endl;

  //calculo promedio
  for(int i = 0; i < CANTIDAD_BANCOS; i++){
    vBancos[i].promedio = vBancos[i].promedio / CANTIDAD_ANIOS;
  }

  //calculo tasa trimestral
  for(int i = 0; i < CANTIDAD_BANCOS; i++){
    vBancos[i].tasaTrimestral = vBancos[i].promedio / 4;
  }

  //calculo tasa mensual
  for(int i = 0; i < CANTIDAD_BANCOS; i++){
    vBancos[i].tasaMensual = vBancos[i].promedio / 12;
  }
}


void mostrarPunto3a(Banco vBancos[], float capitalInicial){
  //obtengo promedio maximo por indice
  int mayorTasaIndiceBanco = 0; //asumo que el indice cero es el mayor
  for(int i = 1; i < CANTIDAD_BANCOS; i++){
    if(vBancos[i].promedio > vBancos[mayorTasaIndiceBanco].promedio){
      mayorTasaIndiceBanco = i;
    }
  }

  cout << left << setw(12) << "BANCO" << setw(18) << "CAPITAL INICIAL"  << setw(18) << "TNA PROMEDIO"  << "RENDIMIENTO(Ganancia)" << endl;
  cout << "--------------------------------------------------------------------------" << endl;
  for(int i = 0; i < CANTIDAD_BANCOS; i++){
    cout << left << setw(12) << vBancos[i].nombre << "$" << setw(17) << capitalInicial << setw(5) << vBancos[i].promedio << "%" << right << setw(13) << "$" << (capitalInicial * (vBancos[i].promedio / 100)) << endl; 
  }
  cout << endl << "La opcion mas rentables es en el banco " << vBancos[mayorTasaIndiceBanco].nombre << " con una tasa anual de " << vBancos[mayorTasaIndiceBanco].promedio << "%" << endl;
}

void mostrarPunto3b(Banco vBancos[], float capitalInicial){
  //Capitales Iniciales para Cada Banco
  float capitalAcumulativoTrimestral[CANTIDAD_BANCOS];
  for(int i = 0; i < CANTIDAD_BANCOS; i++){
    capitalAcumulativoTrimestral[i] = capitalInicial;
  }

  //calculo del maximo indice entre las tasas trimestrales del struct
  int maxIndice = 0; 
  for(int i = 1; i < CANTIDAD_BANCOS; i++){
    if(vBancos[i].tasaTrimestral > vBancos[maxIndice].tasaTrimestral){
      maxIndice= i;
    }
  }

  //acumulo por cada banco 4 re-inversiones de interes compuesto
  for(int i = 0; i < CANTIDAD_BANCOS; i++){
    for(int j = 0; j < 4; j++){     
      float ganancia = capitalAcumulativoTrimestral[i] * (vBancos[i].tasaTrimestral / 100); //850000*0.80   
      capitalAcumulativoTrimestral[i] += ganancia; //sumo la ganancia al capital
      cout << "Banco " << vBancos[i].nombre << " -> trimestre " << j + 1 << " -> GANANCIA $" <<  ganancia  << endl;
    }
    cout << endl;
  }

  //HEADER
  cout << left << setw(12) << "BANCO" << setw(18) << "CAPITAL INICIAL"  << setw(18) << "TASA TRIMESTRAL" << "RENDIMIENTO(Ganancia)" << endl;
  cout << "--------------------------------------------------------------------------" << endl;
  for(int i = 0; i < CANTIDAD_BANCOS; i++){
    cout << left << setw(12) << vBancos[i].nombre << "$" << setw(17) << capitalInicial << setw(5) << vBancos[i].tasaTrimestral << "%"  << right << setw(13) << "$" << (capitalAcumulativoTrimestral[i] - capitalInicial) << endl; 
  }
    
  cout << endl << "La opcion mas rentable es en el banco " << vBancos[maxIndice].nombre  << " con un rendimiento total de $"  << (capitalAcumulativoTrimestral[maxIndice] - capitalInicial) << endl;
}

void mostrarPunto3c(Banco vBancos[], float capitalInicial){
  //Capitales Iniciales para Cada Banco
  float capitalAcumulativoMensual[CANTIDAD_BANCOS];
  for(int i = 0; i < CANTIDAD_BANCOS; i++){
    capitalAcumulativoMensual[i] = capitalInicial;
  }

  //calculo del maximo indice entre las tasas mensuales del struct
  int maxIndice = 0; 
  for(int i = 1; i < CANTIDAD_BANCOS; i++){
    if(vBancos[i].tasaMensual> vBancos[maxIndice].tasaMensual){
      maxIndice= i;
    }
  }

  //acumulo por cada banco 12 re-inversiones de interes compuesto
  for(int i = 0; i < CANTIDAD_BANCOS; i++){
    for(int j = 0; j < 12; j++){     
      float ganancia = capitalAcumulativoMensual[i] * (vBancos[i].tasaMensual / 100);   //850000 * 0.25  
      capitalAcumulativoMensual[i] += ganancia; //sumo la ganancia al capital
      cout << "Banco " << vBancos[i].nombre << " -> Mes " << j + 1 << " -> GANANCIA $" <<  ganancia  << endl;
    }
    cout << endl;
  }

  //HEADER
  cout << left << setw(12) << "BANCO" << setw(18) << "CAPITAL INICIAL"  << setw(18) << "TASA MENSUAL" << "RENDIMIENTO(Ganancia)" << endl;
  cout << "--------------------------------------------------------------------------" << endl;
  for(int i = 0; i < CANTIDAD_BANCOS; i++){
    cout << left << setw(12) << vBancos[i].nombre << "$" << setw(17) << capitalInicial << setw(5) << vBancos[i].tasaMensual << "%"  << right << setw(13) << "$" << (capitalAcumulativoMensual[i] - capitalInicial) << endl; 
  }
    
  cout << endl << "La opcion mas rentable es en el banco " << vBancos[maxIndice].nombre  << " con un rendimiento total de $"  << (capitalAcumulativoMensual[maxIndice] - capitalInicial) << endl;
}


void menu(){
  int opcion;
  float capitalInicial;
  Banco vBancos[CANTIDAD_BANCOS];
  
  cargaNombreBancos(vBancos);//cargo los 3 nombres
  cargaTasaAnualCapital(vBancos, capitalInicial);//cargo las 3 tasas => validar con regex

  system("pause");//luego de la carga hago pausa para ver datos  
  cout << fixed << setprecision(2); // es para que todos los COUT sean con 2 decimales a partir de aqui

  do{
    system("cls");

    cout << endl << "********************Rendimientos Obtenidos********************" << endl << endl;
    cout << "1. Inversion por un anio completo con la tasa anual promedio para cada banco(con el banco recomendado y la opcion mas rentable)" << endl;
    cout << "2. Inversion trimestral con interes compuesto por un anio para cada banco(con el banco recomendado y la opcion mas rentable)" << endl;
    cout << "3. Inversion mensual con interes compuesto por un anio para cada banco(con el banco recomendado y la opcion mas rentable)" << endl;
    cout << "0. Salir" << endl; 
    
    cout << endl << "Ingrese la Opcion: ";
    cin >> opcion;
    system("cls");

    switch(opcion)
    {  
      case 1: mostrarPunto3a(vBancos, capitalInicial); break;   
      case 2: mostrarPunto3b(vBancos, capitalInicial); break; 
      case 3: mostrarPunto3c(vBancos, capitalInicial); break; 
      case 0: cout << "Gracias por usar el programa" << endl; break;
      default: cout << "¡Opcion no valida! Por favor, intente de nuevo." << endl; break; 
    }
    if(opcion != 0) system("pause");//en el break corta switch y entra por aca siempre
  }while(opcion != 0);
}

