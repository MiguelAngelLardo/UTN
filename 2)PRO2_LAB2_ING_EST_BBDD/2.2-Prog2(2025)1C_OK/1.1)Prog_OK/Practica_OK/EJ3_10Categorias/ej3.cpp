#include <iostream>

using namespace std;

void categoriaMayorGasto(float *);//declaracion/firma/prototipo
void mostrarCategoriaYGastoAcum(float *, string *);//declaracion, firma, prototipo

void categoriasSinMovCont(float *);

void mostrasGastosPorDia(float *);

int main() {

  int dia, IDCategoria;
  float vIDCagegoriaAcumGasto[10]={}, vDiaAcumGastos[31]={};//1 al 10
  float importeGasto;

  string vCategorias[10] = {"Servicios", "Alimentacion", "Limpieza", "Transporte", "Educacion", "Salud", "Ocio", "Impuestos", "Vestimenta", "Inversiones"};

  do{
    cout << "Ingrese el dia del gasto: ";
    cin >> dia;
    if(dia != 0){
      cout << "Ingrese la IDCategoria del gasto: ";
      cin >> IDCategoria;
      cout << "Ingrese el importe del gasto: ";
      cin >> importeGasto;
    }
   
    vIDCagegoriaAcumGasto[IDCategoria-1] += importeGasto; 
    vDiaAcumGastos[dia-1] += importeGasto;

  }while(dia != 0);

  for(int i = 0; i < 10; i++){
  cout <<"mostrar vector: " << vIDCagegoriaAcumGasto[i] << endl;
  }

  cout << endl;
  categoriaMayorGasto(vIDCagegoriaAcumGasto);
  cout << endl;
  mostrarCategoriaYGastoAcum(vIDCagegoriaAcumGasto, vCategorias);
  cout << endl;
  categoriasSinMovCont(vIDCagegoriaAcumGasto);
  cout << endl;
  mostrasGastosPorDia(vDiaAcumGastos);

  
  return 0;
}

void categoriaMayorGasto(float *v){ //definicion/implementacion
  float maxGasto = v[0], maxCategoria = 0;

  for(int i = 1; i < 10; i++){
    if(v[i] > maxGasto){ 
      maxGasto = v[i];
      maxCategoria = i;
    }
  }
  cout << "La categoria de gasto que mayor dinero se haya destinado es: " << maxCategoria+1 << endl;
  cout << "El total acumulado en concepto de gastos del mes es: " << maxGasto << endl;
}

void mostrarCategoriaYGastoAcum(float *vID, string *vNom){//definicion/implementacion
  for(int i = 0; i < 10; i++){
    cout << "ID: " << i+1 << " - " << vNom[i] << ": gasto $ " << vID[i] << endl;
  }
}

void categoriasSinMovCont(float *v){
  int contNoMov = 0;

  for(int i = 0; i < 10; i++){
    if(v[i] == 0){
      contNoMov++;
    }
  }
  cout << "La cantidad de categorias de gasto que no hayan registrado movimientos es: " << contNoMov << endl;

}


void mostrasGastosPorDia(float *v){
  cout << "Mostrando gastos totales por dia: " << endl;

  for(int i = 0; i < 31; i++){
    if(v[i] != 0){
      cout << "Dia " << i+1 << ": " << v[i] << endl;
    }
  }  

}