//TP         : 05
//EJERCICIO  : 05
//AUTOR      : Angel Simón - asimon@frgp.utn.edu.ar
//DESCRIPCION: -
#include <iostream>
using namespace std;

int main(void){
  int nSuc, nSucAnt, dia, tipoDia, tipoComb;
  float importe, litros;

  //PUNTO A
  float totalLitros;
  float lhs1=0.0, lhs2=0.0, lhs3=0.0, lhs4=0.0;
  //PUNTO B
  float totalRecSuc, maxRecaudacion=0.0;
  int maxNroSuc=0;
  //PUNTO C
  float recQ1=0.0, recQ2=0.0;
  //PUNTO D
  float lh1=0.0, lh2=0.0, lh3=0.0, lh4=0.0;
  //PUNTO E
  float maxImporte;
  int maxTipoComb;

  cout << "Ingresar numero de sucursal: ";
  cin >> nSuc;
  while(nSuc < 0 || nSuc > 15){
    cout << "-- Reingresar numero de sucursal: ";
    cin >> nSuc;
  }
  while(nSuc != 0){
    nSucAnt = nSuc;
    maxImporte=lhs1=lhs2=lhs3=lhs4=totalRecSuc=totalLitros=0.0;
    while(nSuc == nSucAnt){
      cout << "Ingresar dia de la venta: ";
      cin >> dia;
      while(dia < 1 || dia > 30){
        cout << "-- Reingresar dia de la venta: ";
        cin >> dia;
      }
      cout << "Ingresar tipo de dia: ";
      cin >> tipoDia;
      while(!(tipoDia != 1 || tipoDia !=2)){
        cout << "-- Reingresar tipo de dia: ";
        cin >> tipoDia;
      }
      cout << "Ingresar tipo de combustible: ";
      cin >> tipoComb;
      while(tipoComb < 1 || tipoComb > 4){
        cout << "-- Reingresar tipo de combustible: ";
        cin >> tipoComb;
      }
      cout << "Ingresar importe de la venta: ";
      cin >> importe;
      cout << "Ingresar litros vendidos: ";
      cin >> litros;

      //PUNTO B
      totalRecSuc+= importe;
      //PUNTO C
      if(dia>= 1 && dia<=15){
        recQ1+= importe;
      }
      else{
        recQ2+= importe;
      }
      //PUNTO D-A
        switch(tipoComb){
          case 1:
            if(tipoDia == 1)
              lh1+= litros;
            lhs1+= litros;
          break;
          case 2:
            if(tipoDia == 1)
              lh2+= litros;
            lhs2+= litros;
          break;
          case 3:
            if(tipoDia == 1)
              lh3+= litros;
            lhs3+= litros;
          break;
          case 4:
            if(tipoDia == 1)
              lh4+= litros;
            lhs4+= litros;
          break;
        }

      //PUNTO E
      if(importe > maxImporte){
        maxImporte = importe;
        maxTipoComb = tipoComb;
      }

      cout << "Ingresar numero de sucursal: ";
      cin >> nSuc;
      while(nSuc < 0 || nSuc > 15){
        cout << "-- Reingresar numero de sucursal: ";
        cin >> nSuc;
      }
    }

    //PUNTO A
    cout << endl << "PUNTO A" << endl;
    cout << "---------------" << endl;
    cout << "TIPO DE COMBUSTIBLE: ";
    if((lhs1 > lhs2) && (lhs1 > lhs3) && (lhs1 > lhs4)){
      cout << "EXTRA" << endl;
    }
    else if((lhs2 > lhs1) && (lhs2 > lhs3) && (lhs2 > lhs4)){
      cout << "SUPER" << endl;
    }
    else if((lhs3 > lhs1) && (lhs3 > lhs2) && (lhs3 > lhs4)){
      cout << "COMUN" << endl;
    }
    else if((lhs4 > lhs1) && (lhs4 > lhs2) && (lhs4 > lhs3)){
      cout << "GASOIL" << endl;
    }
    //PUNTO B
    if (totalRecSuc > maxRecaudacion){
      maxRecaudacion = totalRecSuc;
      maxNroSuc = nSucAnt;
    }
    //PUNTO E
    cout << endl << "PUNTO E" << endl;
    cout << "---------------" << endl;
    cout << "NUMERO DE SUCURSAL : " << nSucAnt << endl;
    cout << "TIPO DE COMBUSTIBLE: " << maxTipoComb << endl;
    cout << "IMPORTE DE LA VENTA: $ " << maxImporte << endl;
  }

  cout << endl << "PUNTO B" << endl;
  cout << "---------------" << endl;
  cout << "La sucursal con mayor recaudacion total ($ " << maxRecaudacion << ") es la " << maxNroSuc << endl;

  cout << endl << "PUNTO C" << endl;
  cout << "---------------" << endl;
  cout << "QUINCENA 1: $ " << recQ1 << endl;
  cout << "QUINCENA 2: $ " << recQ2 << endl;

  cout << endl << "PUNTO D" << endl;
  cout << "---------------" << endl;
  cout << "EXTRA  : " << lh1 << endl;
  cout << "SUPER  : " << lh2 << endl;
  cout << "COMUN  : " << lh3 << endl;
  cout << "GASOIL : " << lh4 << endl;

  return 0;
}
