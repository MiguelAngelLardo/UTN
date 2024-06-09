//TP         : 05
//EJERCICIO  : 03
//AUTOR      : Angel Simón - asimon@frgp.utn.edu.ar
//DESCRIPCION: -
#include <iostream>
using namespace std;
#include <stdio.h>

int main(void){
  const int CANT_ALQ_PUNTO_D = 2; //Originalmente 15
  int nroPeli, nroPeliAnt, nroSocio, tipoSocio, dia, calificacion;
  char genero, sexo;
  float costo, totalRec=0.0;
  //PUNTO A
  int cantA=0, cantC=0, cantT=0, maxA=0, maxC=0, maxT=0, maxPA=0, maxPC=0, maxPT=0;
  //PUNTO B
  int cSolF=0, cSolM=0, maxCSolF=0, maxCSolM=0, maxCalSolF=0, maxCalSolM=0;
  //PUNTO C
  float recSoc1=0.0, recSoc2=0.0, recSoc3=0.0;
  //PUNTO D
  int cantAlq=0, maxAlq=0, maxPel=0, maxCal=0;
  float recPel=0.0, maxRecPel=0.0;
  //PUNTO E
  int cantAlqF=0, cantAlqM=0;


  cout << "Ingresar numero de pelicula: ";
  cin >> nroPeli;
  while((nroPeli < 1000 || nroPeli > 2000) && nroPeli!=0){
    cout << "-- Reingresar numero de pelicula: ";
    cin >> nroPeli;
  }
  while(nroPeli!=0){
    nroPeliAnt=nroPeli;

    cantAlq=0;
    recPel=0.0;
    //PUNTO A
    cantA=cantC=cantT=0;
    //PUNTO B
    cSolF=cSolM=0;
    //PUNTO D
    cantAlq=0;
    //PUNTO E
    cantAlqF=cantAlqM=0;

    cout << "Ingresar genero de la pelicula: ";
    cin >> genero;
    while(toupper(genero)!='A' && toupper(genero)!='C' && toupper(genero)!='T'){
      cout << "-- Reingresar genero de la pelicula: ";
      cin >> genero;
    }
    cout << "Ingresar calificacion de la pelicula: ";
    cin >> calificacion;
    while(calificacion!=0 && calificacion!=13 && calificacion!=16){
      cout << "-- Reingresar calificacion de la pelicula: ";
      cin >> calificacion;
    }
    while (nroPeli == nroPeliAnt){
      cout << "Ingresar numero de socio: ";
      cin >> nroSocio;
      while(nroSocio<1 || nroSocio >500){
        cout << "-- Reingresar numero de socio: ";
        cin >> nroSocio;
      }
      cout << "Ingresar sexo del socio: ";
      cin >> sexo;
      while(toupper(sexo) != 'F' && toupper(sexo)!='M'){
        cout << "-- Reingresar sexo del socio: ";
        cin >> sexo;
      }
      cout << "Ingresar tipo de socio: ";
      cin >> tipoSocio;
      while(tipoSocio<1 || tipoSocio>3){
        cout << "-- Reingresar tipo de socio: ";
        cin >> tipoSocio;
      }
      cout << "Ingresar dia del alquiler: ";
      cin >> dia;
      while(dia<1 || dia>30){
        cout << "-- Reingresar dia del alquiler: ";
        cin >> dia;
      }
      cout << "Ingresar costo del alquiler: ";
      cin >> costo;
      //PUNTO A
      switch(genero){
        case 'a':
        case 'A':
          cantA++;
        break;
        case 'c':
        case 'C':
          cantC++;
        break;
        case 't':
        case 'T':
          cantT++;
        break;
      }
      //PUNTO B
      if (dia>=1 && dia<=15){
        if(toupper(sexo)=='F'){
          cSolF++;
        }
        else if(toupper(sexo)=='M'){
          cSolM++;
        }
      }
      //PUNTO C
      switch(tipoSocio){
        case 1:
          recSoc1+=costo;
        break;
        case 2:
          recSoc2+=costo;
        break;
        case 3:
          recSoc3+=costo;
        break;
      }

      //PUNTO D
      cantAlq++;
      recPel+=costo;
      
      //PUNTO E
      if(toupper(sexo)=='F'){
        cantAlqF++;
      }
      else if(toupper(sexo)=='M'){
        cantAlqM++;
      }
      cout << endl << "Ingresar numero de pelicula: ";
      cin >> nroPeli;
      while((nroPeli < 1000 || nroPeli > 2000) && nroPeli!=0){
        cout << "-- Reingresar numero de pelicula: ";
        cin >> nroPeli;
      }

    }
    //PUNTO A
    if(cantA > maxA){
      maxA = cantA;
      maxPA = nroPeliAnt;
    }
    if(cantC > maxC){
      maxC = cantC;
      maxPC = nroPeliAnt;
    }
    if(cantT > maxT){
      maxT = cantT;
      maxPT = nroPeliAnt;
    }
  //  cout << "cSolM: " << cSolM << " maxCSolM: " << maxCSolM << " cSolF: " << cSolF << " maxCSolF: " << maxCSolF;
  //  cout << "maxCalSolM: " << maxCalSolM << " maxCalSolF: " << maxCalSolF << endl;
    //PUNTO B
    if(cSolM > maxCSolM){
      maxCSolM = cSolM;
      maxCalSolM = calificacion;
    }
    if(cSolF > maxCSolF){
      maxCSolF = cSolF;
      maxCalSolF = calificacion;
    }
    //PUNTO C
    totalRec += recPel;
    //PUNTO D
    if(cantAlq > CANT_ALQ_PUNTO_D){
      cout << endl << "PUNTO D" << endl;
      cout << "-------------------" << endl;
      cout << "NRO PELICULA: " << nroPeliAnt << endl;
      cout << "RECAUDACION : $ " << recPel << endl;
      cout << "CALIFICACION: " << calificacion << endl;
    }
    //PUNTO E
    cout << endl << "PUNTO E" << endl;
    cout << "---------------------" << endl;
    if((cantAlqF + cantAlqM) > 0){
      cout << "MASCULINO: " << ((float) cantAlqM / (cantAlqF + cantAlqM)) * 100 << endl;
      cout << "FEMENINO : " << ((float) cantAlqF / (cantAlqF + cantAlqM)) * 100 << endl;
    }
  }
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    cout << endl << "PUNTO A" << endl;
    cout << "---------------------" << endl;
    cout << "ACCION : " << maxPA << endl;
    cout << "COMEDIA: " << maxPC << endl;
    cout << "TERROR : " << maxPT << endl;

    cout << endl << "PUNTO B" << endl;
    cout << "---------------------" << endl;
    cout << "MASCULINO: " << maxCalSolM << endl;
    cout << "FEMENINO : " << maxCalSolF << endl;

    cout << endl << "PUNTO C" << endl;
    cout << "---------------------" << endl;
    if(cantAlq > 0){
      cout << "SOCIO TIPO 1: " << ((float) recSoc1 / totalRec) * 100 << endl;
      cout << "SOCIO TIPO 2: " << ((float) recSoc2 / totalRec) * 100 << endl;
      cout << "SOCIO TIPO 3: " << ((float) recSoc3 / totalRec) * 100 << endl;
    }

    return 0;
}
