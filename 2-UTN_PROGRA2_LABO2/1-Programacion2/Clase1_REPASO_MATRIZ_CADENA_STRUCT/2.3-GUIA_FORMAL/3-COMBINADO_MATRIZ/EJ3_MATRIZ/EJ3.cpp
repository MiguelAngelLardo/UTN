#include <iostream>

using namespace std;
/*
3) Una empresa fabrica 200 productos que son vendidos por 5 vendedores. 
La empresa
quiere obtener un listado en el que figure el monto total en pesos de 
las ventas efectuadas en 2018 por cada uno de sus vendedores, mes por mes.
Para ello dispone de un lote de registros con los siguientes datos
 de cada una de las ventas:
- Día (1 a 31)
- Mes (1 a 12)
- Importe ($)
- Código de vendedor (‘a’, ‘b’, ‘c’, ‘d’, ‘e’)
Este lote está desordenado y cualquier vendedor puede haber vendido
 el mismo producto, en un mismo día, a diferentes clientes. 
 El fin se indica con un registro con día igual a cero.
Construya un programa C para resolver el problema
                mes 1    mes 2   mes 12
vendedor 1      
vendedor 2
vendedor 5

mes a mes ver venta de cada vendedor (1 a 5)
dia != 0

*/
const int NUM_VENDEDORES = 5;//
const int NUM_MESES = 6;//son 12

int obtenerIndexVendedor(char codigoVendedor);

int main(){
  float mVendedorMesImporte[NUM_VENDEDORES][NUM_MESES] = {}, importe;
  int dia,mes;
  char codigoVendedor;
  int indiceVendedor;

  cout << "Ingrese el dia (corta con cero): ";
  cin >> dia;
  while(dia != 0){
    cout << "Ingrese el mes: ";
    cin >> mes;
    cout << "Ingrese el importe: ";
    cin >> importe;
    cout << "Ingrese codigo del vendedor (a, b, c, d, e): ";
    cin >> codigoVendedor;
    indiceVendedor = obtenerIndexVendedor(codigoVendedor);

    mVendedorMesImporte[indiceVendedor][mes-1] += importe;

    cout << "Ingrese el dia (corta con cero): ";
    cin >> dia;  
  }

  cout << "\nPTO A => MOSTRAR EN CADA MES LA VENTA TOTAL DE CADA VENDEDOR\n";
  cout << "                         MES 1      MES 2        MES 3    MES 4   MES 5   MES 6" << endl; 
  for(int i = 0; i < NUM_VENDEDORES; i ++){
    cout << "VENDEDOR #" << i +1 <<"(recaudacion)";
    for(int j = 0; j < NUM_MESES; j ++){
      cout << "   " << mVendedorMesImporte[i][j] << "    "; 
    }
    cout << endl;
  }
  cout << endl;



}

int obtenerIndexVendedor(char codigoVendedor){
  switch (codigoVendedor)
  {
  case 'a':
    return 0;
  case 'b':
    return 1;
  case 'c':
    return 2;
  case 'd':
    return 3;
  case 'e':
    return 4;
  }
}
