#include <iostream>

using namespace std;

int main(){
  float capacidadesVaso[3] = {0.15f, 0.2f, 0.3f};

  ///Stock de Batidos
  float stockBanana = 20, stockAnana = 35, stockSandia = 44;

  //Cantidad de batidos vendidos
  int cantBanana = 0, cantAnana = 0, cantSandia = 0;

  //Registro de una venta
  int codBatido, codVaso;
  float litros;

  cout << "Ingrese Batido (1 - Banana, 2 - Anana, 3 - Sandia): ";
  cin >> codBatido;

  while(codBatido != 0){
    cout << "Vaso (1 - 150 ml, 2 - 200 ml, 3 - 300 ml): ";
    cin >> codVaso;

    litros = capacidadesVaso[codVaso-1];

    switch (codBatido)
    {
      case 1:
      if (stockBanana >= litros){
        stockBanana -= litros;
        cantBanana ++;
      }else{
        cout << "Sin stock de ese producto" << endl;
      }  
      break;
      case 2:   
        if (stockAnana >= litros){
          stockAnana -= litros;
          cantAnana ++;
        }else{
        cout << "Sin stock de ese producto" << endl;
        }     
      break;
      case 3:
        if (stockSandia >= litros){  
          stockSandia -= litros;
          cantSandia ++;    
        }else{
        cout << "Sin stock de ese producto" << endl;
        }   
      break;
    
    
    
      default:
        cout << "No existe ese sabor.";
      break;
    }
    cout << "--------------------------------" << endl;
    cout << "Ingrese Batido (1 - Banana, 2 - Anana, 3 - Sandia): ";
    cin >> codBatido;
  }

  cout << endl << "ESTADISTICA DEL DIA: " << endl;
  cout << "-------------------------------------" << endl;
  cout << "Banana: " << stockBanana << " lts(" << cantBanana << " ventas)" << endl;
  cout << "Anana: " << stockAnana << " lts(" << cantAnana << " ventas)" << endl;
  cout << "Sandia: " << stockSandia << " lts(" << cantSandia << " ventas)" << endl;


  return 0;
}