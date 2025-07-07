#include <iostream>
#include "ReportesMenu.h"
#include "InmuebleArchivo.h"

using namespace std;
void reportesMenu()
{
  int opcion = 0;
  do{
    cout << "Menu de Reportes" << endl;
    cout << "1. Cantidad de inmuebles por tipo" << endl;
    cout << "2. Tipo de inmueble con mas cantidad de propiedades registradas" << endl;
    cout << "3. Cantidad de inmuebles por antiguedad" << endl;
    cout << "4. Antiguedad con menos cantidad de inmuebles" << endl;
    cout << "0. Regresar al menu principal" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:{
      cantInmueblesPorTipo();
    }break;

    case 2:{
      tipoInmuebleConMasPropiedadesRegistradas();
    }break;

    case 3:{
      cantidadInmueblesPorAntiguedad();
    }break;

    case 4:{
      antiguedadConMenosCantidadInmuebles();
    }break;

   }

  }while(opcion != 0);
  
}

void cantInmueblesPorTipo(){//son 5 tipos
  InmuebleArchivo objInmArch;
  int vTipos[5]={};

  int tam = objInmArch.getCantidadRegistros();

  for(int i=0; i<tam; i++){
    Inmueble obj = objInmArch.leerUnRegistro(i);
    if(obj.getEstado()){
      vTipos[obj.getTipoPropiedad()-1]++;
    }
  }
  cout << "Cantidad de inmuebles por tipo:" << endl;
  for(int i=0; i<5; i++){
    cout << "Tipo " << i+1 << ": " << vTipos[i] << endl;
  }
  system("pause");
  system("cls");
   
}

void tipoInmuebleConMasPropiedadesRegistradas(){
  InmuebleArchivo objInmArch;
  int vTipos[5]={};

  int tam = objInmArch.getCantidadRegistros();

  for(int i=0; i<tam; i++){
    Inmueble obj = objInmArch.leerUnRegistro(i);
    if(obj.getEstado()){
      vTipos[obj.getTipoPropiedad()-1]++;
    }
  }
  
  int mayorIndice = 0;
  for(int i=1; i<5; i++){
    if(vTipos[i] > vTipos[mayorIndice]){
      mayorIndice = i;
    }
  }

  cout << "El tipo de inmueble con mas propiedades registradas es el tipo " << mayorIndice+1 << " con " << vTipos[mayorIndice] << " propiedades." << endl;

  system("pause");
  system("cls");
}

void cantidadInmueblesPorAntiguedad(){
  Inmueble objInm;
  InmuebleArchivo objInmArch;

  int tam = objInmArch.getCantidadRegistros();

  int maxAntiguedad = 0;
  for(int i=0; i<tam; i++){
    objInm = objInmArch.leerUnRegistro(i);
    if(objInm.getEstado()){
      if(objInm.getAntiguedad() > maxAntiguedad){
        maxAntiguedad = objInm.getAntiguedad();
      }
    }
  }

  int *vDinAntiguedades = nullptr;
  vDinAntiguedades = new int[maxAntiguedad+1];
  if(vDinAntiguedades == nullptr){
    cout << "Error al reservar memoria" << endl;
    return;
  }

  for(int i=0; i<maxAntiguedad+1; i++){
    vDinAntiguedades[i] = 0;
  }

  for(int i=0; i<tam; i++){
    objInm = objInmArch.leerUnRegistro(i);
    if(objInm.getEstado()){
      vDinAntiguedades[objInm.getAntiguedad()-1]++;
    }
  }

  cout << "Cantidad de inmuebles por antiguedad:" << endl;
  for(int i=0; i<maxAntiguedad; i++){
    cout << "Antiguedad " << i+1 << ": " << vDinAntiguedades[i] << endl;
  }
  system("pause");
  system("cls");
  delete[] vDinAntiguedades;
  vDinAntiguedades = nullptr;

}

void antiguedadConMenosCantidadInmuebles(){
  Inmueble objInm;
  InmuebleArchivo objInmArch;

  int tam = objInmArch.getCantidadRegistros();

  int maxAntiguedad = 0;
  for(int i=0; i<tam; i++){
    objInm = objInmArch.leerUnRegistro(i);
    if(objInm.getEstado()){
      if(objInm.getAntiguedad() > maxAntiguedad){
        maxAntiguedad = objInm.getAntiguedad();
      }
    }
  }

  int *vDinAntiguedades = nullptr;
  vDinAntiguedades = new int[maxAntiguedad+1];
  if(vDinAntiguedades == nullptr){
    cout << "Error al reservar memoria" << endl;
    return;
  }

  for(int i=0; i<maxAntiguedad+1; i++){
    vDinAntiguedades[i] = 0;
  }

  for(int i=0; i<tam; i++){
    objInm = objInmArch.leerUnRegistro(i);
    if(objInm.getEstado()){
      vDinAntiguedades[objInm.getAntiguedad()-1]++;
    }
  }

  int menorIndice = 0;
  for(int i=1; i<maxAntiguedad+1; i++){
    if(vDinAntiguedades[i] < vDinAntiguedades[menorIndice]){
      menorIndice = i;
    }
  }

  cout << "La antiguedad con menos cantidad de inmuebles es la antiguedad " << menorIndice+1 << " con " << vDinAntiguedades[menorIndice] << " inmuebles." << endl;

  system("pause");
  system("cls");
  
  delete[] vDinAntiguedades;
  vDinAntiguedades = nullptr;


}