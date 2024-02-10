#include <iostream>

using namespace std;

int main(){
  int numSucursal, numSucAnterior, dia, tipoDia, tipoCombustible;
  float litrosVendidos, importe;

  float maxLitros, maxTipoCombustible1, maxTipoCombustible2, maxTipoCombustible3, maxTipoCombustible4; //PTOA
  int tipoMax; //PTOA
  float maxRecaudacion = 0, recaudacionSucursal; //PTOB 
  int maxSucursal;//PTOB
  float recaudPrimQuin = 0, recaudSecQuin = 0; //PTOC
  float acumLitros1 = 0, acumLitros2 = 0, acumLitros3 = 0, acumLitros4 = 0; //PTOD
  float ventaIndivMax; //PTOE
  int tipoCombustibleMax; // PTOE

  cout << "Ingrese numero sucursal (1 al 15) (CORTA CON CERO):  "; 
  cin >> numSucursal;
  while(numSucursal !=0)
  {
    maxTipoCombustible1 = maxTipoCombustible2 = maxTipoCombustible3 = maxTipoCombustible4 = 0.0; //PTOA
    recaudacionSucursal = 0; //PTOB
    ventaIndivMax = 0; //PTOE

    numSucAnterior = numSucursal;
    while (numSucursal == numSucAnterior)
    { 
      cout << "Ingrese el dia de la venta (1 al 30): "; 
      cin >> dia;
      cout << "Tipo de dia (1-Habil, 2-find e semana): "; 
      cin >> tipoDia;
      cout << "Tipo de combustible (1-Extra, 2-super, 3-comun, 4-gasoil): "; 
      cin >> tipoCombustible;
      cout << "Importe de la venta ($): "; 
      cin >> importe;
      cout << "Litros vendidos: "; 
      cin >> litrosVendidos;

      switch (tipoCombustible)
      {
      case 1:
        maxTipoCombustible1 += litrosVendidos;
        acumLitros1 += (tipoDia == 1) ? litrosVendidos : 0;
        break;
      case 2:
         maxTipoCombustible2 += litrosVendidos;
         acumLitros2 += (tipoDia == 1) ? litrosVendidos : 0;
         break;
      case 3:
         maxTipoCombustible3 += litrosVendidos;
         acumLitros3 += (tipoDia == 1) ? litrosVendidos : 0;
         break;
      case 4:
         maxTipoCombustible4 += litrosVendidos;
         acumLitros4 += (tipoDia == 1) ? litrosVendidos : 0;
         break;       
      }

      recaudacionSucursal += litrosVendidos * importe; //PTOB

      recaudPrimQuin += (dia >=1 && dia <= 15) ? recaudacionSucursal : 0;//PTOC
      recaudSecQuin += (dia >=16 && dia <= 30) ? recaudacionSucursal : 0;//PTOC

      if(importe * litrosVendidos  > ventaIndivMax){
        ventaIndivMax = importe * litrosVendidos;
        tipoCombustibleMax = tipoCombustible;
      }

      cout << "Ingrese numero sucursal (1 al 15) (CORTA CON CERO):  "; 
      cin >> numSucursal;
    }

    if(maxTipoCombustible1 > maxTipoCombustible2 && maxTipoCombustible1 > maxTipoCombustible3 && maxTipoCombustible1 > maxTipoCombustible4){
      maxLitros = maxTipoCombustible1;
      tipoMax = 1;
    }else if(maxTipoCombustible2 > maxTipoCombustible1 && maxTipoCombustible2 > maxTipoCombustible3 && maxTipoCombustible2 > maxTipoCombustible4){
      maxLitros = maxTipoCombustible2;
      tipoMax = 2;
    }else if (maxTipoCombustible3 > maxTipoCombustible1 && maxTipoCombustible3 > maxTipoCombustible2 && maxTipoCombustible3 > maxTipoCombustible4){
      maxLitros = maxTipoCombustible3;
      tipoMax = 3;
    }else if(maxTipoCombustible4 > maxTipoCombustible1 && maxTipoCombustible4 > maxTipoCombustible2 && maxTipoCombustible4 > maxTipoCombustible3){
      maxLitros = maxTipoCombustible4;
      tipoMax = 4;
    }

    cout << endl << "PTOA => SUCURSAL: " << numSucAnterior << " tipo combustible mas vendido ";
    if(tipoMax == 1){
      cout << "Extra ";
    }else if (tipoMax == 2){
      cout << "SUPER ";
    }else if(tipoMax == 3){
      cout << "comun ";
    }else if(tipoMax == 4){
      cout << "gasoil ";
    }        
    cout << "cantidad de litros: " << maxLitros << endl;

    cout << "PUNTO E: " << "SUCURSAL: " << numSucAnterior << " - venta individual mayor: $" << ventaIndivMax << " - TIPO COMBUSTIBLE: " << tipoCombustibleMax << endl;

    if(recaudacionSucursal > maxRecaudacion){
      maxRecaudacion = recaudacionSucursal;
      maxSucursal = numSucAnterior;
    }
  }  

  cout << endl << "PUNTO B: Maxima recaudacion en sucursal: " << maxSucursal << " es : $" << maxRecaudacion << endl;
  cout << "PUNTO C: RECUADACION PRIMER QUINCENA: " << recaudPrimQuin << " - RECAUDACION SEGUNDA QUINCENA: " << recaudSecQuin << endl;
  cout << "PUNTO D: LITROS VENDIDOS EXTRA: " << acumLitros1 << " - LITROS VENDIDOS SUPER: " << acumLitros2 << " - LITROS VENDIDOS COMUN: " << acumLitros3 << " - LITROS VENDIDOS GASOIL: " << acumLitros4 << endl;

  return 0;
}