#pragma once

#include<iostream>
#include<cstring>

using namespace std;

#include "clases.h"

void cargarCadena2(char *pal, int tam){
    int i;
    tam = tam-1; //<--- esto es opcional
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

void cargarArchivos(int tam = 10){
    Clientes objC;
    ArchivoClientes arObjC;

    Ventas objV;
    ArchivoVentas arObjV;

    cout << "Cargar archivo de clientes" << endl;
    arObjC.crearArchivo(tam);

    cout<<endl<<"//////////////////////////////"<<endl<<endl;

    cout << "Cargar archivo de ventas" << endl;
    arObjV.crearArchivo(tam);
}

void mostrarArchivos(){
    Clientes objC;
    ArchivoClientes arObjC;

    Ventas objV;
    ArchivoVentas arObjV;

    cout << "Mostrar archivo de clientes" << endl;
    arObjC.mostrarArchivo();

    cout << "Mostrar archivo de ventas" << endl;
    arObjV.mostrarArchivo();
}