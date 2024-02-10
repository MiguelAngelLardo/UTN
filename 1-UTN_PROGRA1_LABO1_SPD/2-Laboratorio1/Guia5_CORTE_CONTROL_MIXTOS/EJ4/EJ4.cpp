#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;// Usamos el espacio de nombres estándar

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
  
  const int PESO_MAXIMO_CAMION = 200;

  float pesoEncomienda, pesoCamion;//Para el PseudoCorte CONTROL
  float importeA, importeB, importeC, costoEncomienda;
  float contadorNumeroEncomienda;
  int contNumeroCamion = 0;
  float totalFacturdo = 0; //D)
  
  cout << "Ingrese el valor para el contenedor importe A '<= 10 kg' (por ej $1000): ";
  cin >> importeA;
  cout << "Ingrese el valor para el contenedor importe B '>10 y <= 40' (por ej $2000): ";
  cin >> importeB;
  cout << "Ingrese el valor para el contenedor importe C '>40' (por ej $3000): ";
  cin >> importeC;

  cout << "Ingrese el peso de la encomienda ('corta con -1'): ";
  cin >> pesoEncomienda;
  while (pesoEncomienda < - 1 || pesoEncomienda > 200){
    cout << "Ingrese un valor entre 1 y 200 por favor...";
    cin >> pesoEncomienda;
  }

  while(pesoEncomienda > 0 || pesoEncomienda != -1)
  {
  //PROCESAR-LISTAR DATOS DE TODO EL LOTE DE CAMIONES(CON SUS ENCOMIENDAS)
    pesoCamion = contadorNumeroEncomienda = costoEncomienda = 0;
    contNumeroCamion ++;
 
      while (pesoCamion + pesoEncomienda <= PESO_MAXIMO_CAMION && pesoEncomienda > 0 && pesoEncomienda != -1)
      { 
      //PROCESAR-LISTAR CADA CAMION(CON SUS ENCOMIENDA)
        contadorNumeroEncomienda ++;
        pesoCamion += pesoEncomienda;

        cout << endl << "      ****CAMION #" << contNumeroCamion << ". ENCOMIENDA #" << contadorNumeroEncomienda << ".****";
        cout << endl << "El camion pesa: " << fixed << setprecision(2)<< pesoCamion << " KG.... La encomienda fue de " << fixed << setprecision(2) << pesoEncomienda << " KG." << endl;

        //PROCESAR PUNTO C 
        if(pesoEncomienda <= 10){
          costoEncomienda += importeA;
        }else if(pesoEncomienda > 10  && pesoEncomienda <= 40){
          costoEncomienda += importeB;
        }else{
          costoEncomienda += importeC;
        }

        cout << "Llevas gastado $" << costoEncomienda << ".";

        cout << endl << endl << "Ingrese el peso de la encomienda: ";
        cin >> pesoEncomienda;
        while (pesoEncomienda < -1 || pesoEncomienda > 200){
          cout << "Ingrese un valor entre 1 y 200 por favor...";
          cin >> pesoEncomienda;
        }
      } 

      //PROCESAR D
      totalFacturdo += costoEncomienda;
      //LISTAR DATOS POR CAMION => PUNTO C
      cout << endl << "C) El numero de camion: " << contNumeroCamion << ". Tranporto " << fixed << setprecision(2) << pesoCamion << " KG." << " Se le cobro $" << fixed << setprecision(2) << costoEncomienda << "." << endl;
  }
  //LISTAR DATOS GLOBALES => PUNTO D
  cout << "B) Cantidad total de camiones: " << contNumeroCamion << ". Total Facturado $" << fixed << setprecision(2) << totalFacturdo << ".";
    
  return 0;
}