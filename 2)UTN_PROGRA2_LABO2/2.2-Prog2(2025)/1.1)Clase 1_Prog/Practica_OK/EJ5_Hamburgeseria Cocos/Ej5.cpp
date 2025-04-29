#include <iostream>

using namespace std;

struct Hamburgesa
{
  int _codigo;
  float _precio;
  int _stock;
};


int main(){
  int vContHamburgesa[5] = {0};
  float vTotalRecaudado[5] = {0};

  Hamburgesa vHamburgesa[5];
  for(int i = 0; i < 5; i++){
    cout << "Ingrese el codigo de la hamburguesa " << i << ": ";
    cin >> vHamburgesa[i]._codigo;
    cout << "Ingrese el precio de la hamburguesa " << i << ": ";
    cin >> vHamburgesa[i]._precio;
    cout << "Ingrese el stock de la hamburguesa " << i << ": ";
    cin >> vHamburgesa[i]._stock;
  }  

  cout << "Mostrando la informacion de las hamburguesas" << endl;
  for(int i = 0; i < 5; i++){
    cout << endl << vHamburgesa[i]._codigo << " " << vHamburgesa[i]._precio << " " << vHamburgesa[i]._stock << endl;
  }  

  //Punto A
  int codigoHamburguesa, dia, cantidadVendida;
  char tipoAcompanamiento;//B - con batatas / P - con papas / C - Aros de cebolla / X - sin acompanamiento
   
  //Punto B
  int vVendidasViernes[5] = {0};

  //Punto C
  bool vDiasVentaBatatas[7] = {}, vDiasVentaCebolla[7] = {};//PTO C

  //Punto D
  int vAcumVentaHamburgesa[5] = {0};

  //Punto E
  int mDiaAcompAcum [7][4] = {0};
  string vAcompaniamiento[4] = {"Batatas", "Papas", "Aros de cebolla", "Sin acompanamiento"};

  cout << "Se ingresan los registros de ventas" << endl;
  cout << "Ingrese el codigo de la hamburguesa: ";
  cin >> codigoHamburguesa;
  while(codigoHamburguesa != 0){
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese la cantidad vendida: ";
    cin >> cantidadVendida;
    cout << "Ingrese el tipo de acompanamiento: ";
    cin >> tipoAcompanamiento;

    vContHamburgesa[codigoHamburguesa - 1] += cantidadVendida;// PTO A
    if(dia ==5) vVendidasViernes[codigoHamburguesa-1] += cantidadVendida; //PTO B
    if(tipoAcompanamiento == 'B') vDiasVentaBatatas[dia-1] = true; //PTO C
    if(tipoAcompanamiento == 'C') vDiasVentaCebolla[dia-1] = true; //PTO C

    vAcumVentaHamburgesa[codigoHamburguesa-1] += cantidadVendida;//PTO D

    //PTO E
    switch (tipoAcompanamiento)
    {
    case 'B':{
      mDiaAcompAcum[dia-1][0] += cantidadVendida;
    }break;
    case 'P':{
      mDiaAcompAcum[dia-1][1] += cantidadVendida;
    }break;
    case 'C':{
      mDiaAcompAcum[dia-1][2] += cantidadVendida;
    }break;
    case 'X':{
      mDiaAcompAcum[dia-1][3] += cantidadVendida;
    }break;
    }

    cout << "Ingrese el codigo de la hamburguesa: ";
    cin >> codigoHamburguesa;
  }   

  //Punto A
  cout << endl;
  for(int i = 0; i < 5; i++){
    vTotalRecaudado[i] += (vContHamburgesa[i] * vHamburgesa[i]._precio);
    // cout << endl << vHamburgesa[i]._codigo << " " << vHamburgesa[i]._precio << " " << vHamburgesa[i]._stock << endl;
    // system("pause");
  }
  for(int i = 0; i < 5; i++){
    cout << "Hamburguesa " << i + 1 << ": " << vContHamburgesa[i] << " unidades vendidas. Total recaudado: $" << vTotalRecaudado[i] << endl; 
  }  

  //Punto B
  int indiceMax = 0;
  for (int i = 1; i < 5; i++){
    if(vVendidasViernes[i] > vVendidasViernes[indiceMax]) indiceMax = i;
  }
  cout << endl << "La hamburguesa mas vendida el viernes es la " << indiceMax + 1 << " con una cantidad de " << vVendidasViernes[indiceMax] << endl;
  
  //punto C
  cout << endl;
  for(int i = 0; i < 7; i++){
    if(vDiasVentaBatatas[i] && !vDiasVentaCebolla[i]){
      cout << "El dia " << i + 1 << " se vendieron hamburguesas con batatas pero no se vendieron hamburguesas con aros de cebolla" << endl;
    }  
  }  

  //Punto D
  cout << endl;
 for(int i = 0; i < 5; i++){
  if(vHamburgesa[i]._stock == vAcumVentaHamburgesa[i]){
    cout << "La hamburguesa " << i + 1 << " logro un sold out" << endl;
  }  
}

//PUNTO E
cout << endl;
for(int i = 0; i < 7; i++){
  cout << "Dia " << i + 1 << endl;
  for(int j = 0; j < 4; j++){
    cout << " -> " << vAcompaniamiento[j] << ": " << mDiaAcompAcum[i][j] << endl;
  }  
}  
  

  return 0;

}

