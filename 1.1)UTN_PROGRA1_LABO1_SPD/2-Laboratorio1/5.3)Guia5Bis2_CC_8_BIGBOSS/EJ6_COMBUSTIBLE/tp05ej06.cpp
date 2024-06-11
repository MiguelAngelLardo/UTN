//TP         : 05
//EJERCICIO  : 06
//AUTOR      : Angel Simón - asimon@frgp.utn.edu.ar
//DESCRIPCION: -
#include <iostream>
using namespace std;

int main(void){
  int nSuc, nSucAnt, dia, tipoComb, tipoPago;
  float importe, litros;
  char tipoDia, zona;
  //PUNTO A
  float totalLitros;
  float lhs1=0.0, lhs2=0.0, lhs3=0.0, lhs4=0.0;
  //PUNTO B
  float totRecSuc=0.0, maxRecTorcuato1=0.0, maxRecTorcuato2=0.0, maxRecTigre1=0.0, maxRecTigre2=0.0, maxRecPacheco1=0.0, maxRecPacheco2=0.0;
  int maxSucTorcuato1=0, maxSucTorcuato2=0, maxSucTigre1=0, maxSucTigre2=0, maxSucPacheco1=0, maxSucPacheco2=0;
  //PUNTO C
  float totE1=0.0, totE2=0.0, totTa1=0.0, totTa2=0.0, totTi1=0.0, totTi2=0.0;
  //PUNTO D
  float litrosTicket=0.0;
  //PUNTO E
  float maxImporte;
  int maxTipoCombustible;

  cout << "Ingresar numero de sucursal: ";
  cin >> nSuc;
  while(nSuc < 0 || nSuc > 15){
    cout << "-- Reingresar numero de sucursal: ";
    cin >> nSuc;
  }
  while(nSuc != 0){
    nSucAnt = nSuc;
    maxImporte = totalLitros = totRecSuc = 0.0;
    maxTipoCombustible = lhs1 = lhs2 = lhs3 = lhs4 = 0;
    cout << "Ingresar zona de la sucursal: ";
    cin >> zona;
    while(toupper(zona) != 'D' && toupper(zona) != 'T' && toupper(zona) != 'P'){
      cout << "-- Reingresar zona de la sucursal: ";
      cin >> zona;
    }
    while(nSuc == nSucAnt){
      cout << "Ingresar dia de la venta: ";
      cin >> dia;
      while(dia < 1 || dia > 30){
        cout << "-- Reingresar dia de la venta: ";
        cin >> dia;
      }
      cout << "Ingresar tipo de dia: ";
      cin >> tipoDia;
      while(!(toupper(tipoDia) != 'H' || toupper(tipoDia) != 'F')){
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
      cout << "Ingresar tipo de pago: ";
      cin >> tipoPago;
      while(tipoPago < 1 || tipoPago > 3){
        cout << "-- Reingresar tipo de pago: ";
        cin >> tipoPago;
      }

      //PUNTO A
      switch(tipoComb){
        case 1:
          if(tipoPago == 1 || tipoPago == 2)
            lhs1+= litros;
        break;
        case 2:
          if(tipoPago == 1 || tipoPago == 2)
            lhs2+= litros;
        break;
        case 3:
          if(tipoPago == 1 || tipoPago == 2)
            lhs3+= litros;
        break;
        case 4:
          if(tipoPago == 1 || tipoPago == 2)
            lhs4+= litros;
        break;
      }
      //PUNTO B
      totRecSuc+= importe;
      //PUNTO C
      if(dia >= 1 && dia <=15){
        switch(tipoPago){
          case 1:
            totE1+= importe;
          break;
          case 2:
            totTa1+= importe;
          break;
          case 3:
            totTi1+= importe;
          break;
        }
      }
      else{
        switch(tipoPago){
          case 1:
            totE2+= importe;
          break;
          case 2:
            totTa2+= importe;
          break;
          case 3:
            totTi2+= importe;
          break;
        }
      }
      //PUNTO D
      if(toupper(tipoDia) == 'H' && tipoPago == 3){
        litrosTicket+= litros;
      }
      //PUNTO E
      if(importe > maxImporte){
        maxImporte = importe;
        maxTipoCombustible = tipoComb;
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
    switch(toupper(zona)){
      case 'D':
        if(totRecSuc > maxRecTorcuato1){
          maxRecTorcuato2 = maxRecTorcuato1;
          maxSucTorcuato2 = maxSucTorcuato1;
          maxRecTorcuato1 = totRecSuc;
          maxSucTorcuato1 = nSucAnt;
        }
        else if(totRecSuc > maxRecTorcuato2){
          maxRecTorcuato2 = totRecSuc;
          maxSucTorcuato2 = nSucAnt;
        }
      break;
      case 'T':
        if(totRecSuc > maxRecTigre1){
          maxRecTigre2 = maxRecTigre1;
          maxSucTigre2 = maxSucTigre1;
          maxRecTigre1 = totRecSuc;
          maxSucTigre1 = nSucAnt;
        }
        else if(totRecSuc > maxRecTigre2){
          maxRecTigre2 = totRecSuc;
          maxSucTigre2 = nSucAnt;
        }
      break;
      case 'P':
        if(totRecSuc > maxRecPacheco1){
          maxRecPacheco2 = maxRecPacheco1;
          maxSucPacheco2 = maxSucPacheco1;
          maxRecPacheco1 = totRecSuc;
          maxSucPacheco1 = nSucAnt;
        }
        else if(totRecSuc > maxRecPacheco2){
          maxRecPacheco2 = totRecSuc;
          maxSucPacheco2 = nSucAnt;
        }
      break;
    }
    //PUNTO E
    cout << endl << "PUNTO E" << endl;
    cout << "---------------" << endl;
    cout << "NUMERO DE SUCURSAL : " << nSucAnt << endl;
    cout << "TIPO DE COMBUSTIBLE: " << maxTipoCombustible << endl;
    cout << "IMPORTE DE LA VENTA: $ " << maxImporte << endl;
  }
  cout << endl << "PUNTO B" << endl;
  cout << "---------------" << endl;
  cout << "DON TORCUATO" << endl;
  cout << "------------" << endl;
  cout << "MAX1 SUCURSAL: " << maxSucTorcuato1 << endl;
  cout << "MAX2 SUCURSAL: " << maxSucTorcuato2 << endl << endl;
  cout << "TIGRE" << endl;
  cout << "-----" << endl;
  cout << "MAX1 SUCURSAL: " << maxSucTigre1 << endl;
  cout << "MAX2 SUCURSAL: " << maxSucTigre2 << endl << endl;
  cout << "GENERAL PACHECO" << endl;
  cout << "---------------" << endl;
  cout << "MAX1 SUCURSAL: " << maxSucPacheco1 << endl;
  cout << "MAX2 SUCURSAL: " << maxSucPacheco2 << endl;

  cout << endl << "PUNTO C" << endl;
  cout << "----------------" << endl;
  cout << "PRIMERA QUINCENA EFECTIVO: " << totE1 << endl;
  cout << "SEGUNDA QUINCENA EFECTIVO: " << totE2 << endl;
  cout << "PRIMERA QUINCENA TARJETA : " << totTa1 << endl;
  cout << "SEGUNDA QUINCENA TARJETA : " << totTa2 << endl;
  cout << "PRIMERA QUINCENA TICKET  : " << totTi1 << endl;
  cout << "SEGUNDA QUINCENA TICKET  : " << totTi2 << endl;

  cout << endl << "PUNTO D" << endl;
  cout << "----------------" << endl;
  cout << "LITROS PARA DIAS HABILES CON TICKET: " << litrosTicket;

  return 0;
}
