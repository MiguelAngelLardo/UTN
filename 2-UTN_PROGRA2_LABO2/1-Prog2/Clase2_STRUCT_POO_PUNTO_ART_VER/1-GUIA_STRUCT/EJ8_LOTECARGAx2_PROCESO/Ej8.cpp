#include <iostream>
#include <iomanip>

using namespace std;

/*
8) Una municipalidad desea efectuar un control de la cobranza del Impuesto Municipal en los 6 bimestres de los
últimos 5 años. Existen 1200 contribuyentes, numerados del 1 al 1200.
Se dispone de un primer lote ordenado por año-bimestre, con 30 registros, conteniendo los importes de los
impuestos de los últimos cinco años. Cada registro contiene:
- Año del Bimestre (2005 a 2009)
- Bimestre (1 a 6)
- Importe

Otro lote, ordenado secuencialmente por nro. de contribuyente, nos informa sobre cada pago efectuado. Cada
registro contiene:
- Nro. de Contribuyente (1 a 1200)
- Año del Impuesto
- Bimestre

Si el contribuyente no pago algún bimestre, entonces ese registro no existe en el lote.
Se pide confeccionar un programa para pedir que se ingrese por teclado un número de año a procesar (2005 a
2009) y luego emitir para ese año la deuda de cada contribuyente, con el siguiente formato:

DEUDAS REGISTRADAS EN EL AÑO: 200X

CONTRIBUYENTE         BIMESTRES: 1-2-3-4-5-6            IMPORTE ADEUDADO
XXXX                    X X                               XXXX.XX
XXXX                X X X                                    XXXX.XX
Nota: Los pagos que no son del año ingresado por teclado se deben ignorar.
*/
const int TAM_IMPUESTOS = 30;
const int TAM_DEUDORES = 2; //serian 1200

struct Impuesto{ //30 registros
  int anio; //2005 a 2009
  int bimestre; // 1 al 6
  float importe;
};

struct Deudor{
  float mAnioBimestreImporte[5][6] = {}; 
};

void cargaImpuesto(Impuesto *impuesto);
void cargaDeudas(Deudor *deudor, Impuesto *impuestos);

void bimestre(Impuesto impuestos[30], Deudor deudores[TAM_DEUDORES],  int anio, int nroContribuyente);//dentro de cargaDeuda
void muestraDeudas(Deudor deudores[TAM_DEUDORES]);

void mostrarformato(Deudor deudores[TAM_DEUDORES]);

void mostrarformatoIngresandoAnio(Deudor deudores[TAM_DEUDORES]);



int main(){
 
 Impuesto vImpuestos[TAM_IMPUESTOS] = {
    {2005, 1, 150.20}, {2005, 2, 180.50}, {2005, 3, 200.75}, {2005, 4, 220.30}, {2005, 5, 190.65}, {2005, 6, 210.40}, 
    {2006, 1, 160.75}, {2006, 2, 175.30}, {2006, 3, 185.60}, {2006, 4, 195.80}, {2006, 5, 205.90}, {2006, 6, 215.25},
    {2007, 1, 170.40}, {2007, 2, 190.50}, {2007, 3, 210.80}, {2007, 4, 230.90}, {2007, 5, 240.60}, {2007, 6, 250.75},
    {2008, 1, 180.65}, {2008, 2, 200.80}, {2008, 3, 220.95}, {2008, 4, 240.20}, {2008, 5, 260.35}, {2008, 6, 280.50},
    {2009, 1, 190.90}, {2009, 2, 210.20}, {2009, 3, 230.40}, {2009, 4, 250.60}, {2009, 5, 270.80}, {2009, 6, 290.95}
    };

 Deudor vDeudores[TAM_DEUDORES];
  
 cargaDeudas(vDeudores, vImpuestos);
 //muestraDeudas(vDeudores);
 //mostrarformato(vDeudores);
 mostrarformatoIngresandoAnio(vDeudores);


  return 0;
}

void cargaImpuesto(Impuesto *impuesto){ //cargo los 30 valores
  for(int x = 0; x < TAM_IMPUESTOS; x ++){
    cout << x+1 << ")INGRESE EL ANIO (2005 a 2009): ";
    cin >> impuesto[x].anio;
    cout << x+1 << ")INGRESE EL BIMESTRE (1 a 6): ";
    cin >> impuesto[x].bimestre;
    cout << x+1 << ")INGRESE EL IMPORTE: ";
    cin >> impuesto[x].importe;
  }
}

void cargaDeudas(Deudor *deudor, Impuesto *impuestos){
  int anio;
  cout << "\nCARGA DEUDAS\n";  
   
  for(int x = 0; x < TAM_DEUDORES; x ++){
    do{
      printf("Ingrese el anio que quiere cargar del deudor #%d (2005 a 2009) -> OTROS ANIOS NO SE CONTEMPLAN): ", x+1);
      cin >> anio;
    }while(anio < 2005 || anio > 2009);
    
    for(int y = 0; y < 5; y ++){
      switch (anio) 
      {
        case 2005:
          bimestre(impuestos, deudor, anio, x);
          do{
            printf("Ingrese el anio que quiere cargar del deudor #%d (2005 a 2009) -> OTROS ANIOS NO SE CONTEMPLAN): ", x+1);
            cin >> anio;
          }while(anio < 2005 || anio > 2009);
          break;
        case 2006:
          bimestre(impuestos, deudor, anio, x);
          do{
            printf("Ingrese el anio que quiere cargar del deudor #%d (2005 a 2009) -> OTROS ANIOS NO SE CONTEMPLAN): ", x+1);
            cin >> anio;
          }while(anio < 2005 || anio > 2009);
          break;
        case 2007:
          bimestre(impuestos, deudor, anio, x);
          do{
            printf("Ingrese el anio que quiere cargar del deudor #%d (2005 a 2009) -> OTROS ANIOS NO SE CONTEMPLAN): ", x+1);
            cin >> anio;
          }while(anio < 2005 || anio > 2009);
          break;
        case 2008:
          bimestre(impuestos, deudor, anio, x);
          do{
            printf("Ingrese el anio que quiere cargar del deudor #%d (2005 a 2009) -> OTROS ANIOS NO SE CONTEMPLAN): ", x+1);
            cin >> anio;
          }while(anio < 2005 || anio > 2009);
          break;
        case 2009:
          bimestre(impuestos, deudor, anio, x);
          break;
      } 
    }
  }  
}

void bimestre(Impuesto impuestos[30], Deudor deudores[TAM_DEUDORES],  int anio, int nroContribuyente){
  bool pagoEfectuado;
  cout << "ANIO " << anio << endl;
  for(int bimestre = 0; bimestre < 6; bimestre ++){
    cout << "BIMESTRE " << bimestre + 1 << " => PAGO IMPUESTO (1-si 0-NO): ";
    cin >> pagoEfectuado;
    if(!pagoEfectuado){
      deudores[nroContribuyente].mAnioBimestreImporte[anio-2005][bimestre] = impuestos[(anio-2005) * 6 + bimestre].importe;
    }
  }
}

void muestraDeudas(Deudor deudores[TAM_DEUDORES]){
  for(int x = 0; x < TAM_DEUDORES; x ++){
    cout << "\nDEUDOR #" << x+1 << endl;
    for(int i = 0; i < 5; i ++){
      cout << "ANIO 200" << i+5 << " => ";
      for(int j = 0; j < 6;j++){
        cout << "Bimestre " << j+1 << " -> "<< deudores[x].mAnioBimestreImporte[i][j] << "\t"; 
      }
      cout << endl;
    }
  }
}

void mostrarformato(Deudor deudores[TAM_DEUDORES]){
  float importeAdeudado;
  int contadorEspacio;
  for(int x = 0; x < TAM_DEUDORES; x ++){
    for(int i = 0; i < 5; i ++){
      cout << "\nDEUDAS REGISTRADAS EN EL ANIO 200" << i+5 << endl;
      cout << "CONTRIBUYENTE\t" << "BIMESTRES: 1-2-3-4-5-6\t" << "IMPORTE ADEUDADO" << endl; 
      importeAdeudado = 0;
      contadorEspacio = 0;
      cout << setw(6) << x+1 << setw(15);
         
      for(int j = 0; j < 6;j++){
        if(deudores[x].mAnioBimestreImporte[i][j] > 0){
          cout << j+1 << " "; 
          importeAdeudado += deudores[x].mAnioBimestreImporte[i][j];
          contadorEspacio ++;
        }       
      }

      if(contadorEspacio == 0){
        cout << setw(38) << fixed << setprecision(2) << importeAdeudado ;
      }else if(contadorEspacio ==6){
        cout << setw(6) << "\t" << fixed << setprecision(2) << importeAdeudado ;      
      }else{
      cout << setw(12) << "\t" << fixed << setprecision(2) << importeAdeudado ;
      }  
      cout << endl;
    }
  }
} 

void mostrarformatoIngresandoAnio(Deudor deudores[TAM_DEUDORES]){
  int anio, contadorEspacio;
  float importeAdeudado;
  cout << "Ingrese el anio para ver las deudas de todos los contribuyentes: ";
  cin >> anio;
  while(anio >=2005 && anio <= 2009){
    for(int x = 0; x < TAM_DEUDORES; x ++){
    cout << "\nDEUDAS REGISTRADAS EN EL ANIO " << anio << endl;
    cout << "CONTRIBUYENTE\t" << "BIMESTRES: 1-2-3-4-5-6\t" << "IMPORTE ADEUDADO" << endl; 
    importeAdeudado = 0;
    contadorEspacio = 0;
    cout << setw(6) << x+1 << setw(15);
        
    for(int j = 0; j < 6;j++){
      if(deudores[x].mAnioBimestreImporte[anio-2005][j] > 0){
        cout << j+1 << " "; 
        importeAdeudado += deudores[x].mAnioBimestreImporte[anio-2005][j];
        contadorEspacio ++;
      }       
    }

    if(contadorEspacio == 0){
      cout << setw(38) << fixed << setprecision(2) << importeAdeudado ;
    }else if(contadorEspacio ==6){
      cout << setw(6) << "\t" << fixed << setprecision(2) << importeAdeudado ;      
    }else{
    cout << setw(12) << "\t" << fixed << setprecision(2) << importeAdeudado ;
    }  
    cout << endl;
   }

    cout << "Ingrese el anio para ver las deudas de todos los contribuyentes: ";
    cin >> anio;
 }
  
  
}




