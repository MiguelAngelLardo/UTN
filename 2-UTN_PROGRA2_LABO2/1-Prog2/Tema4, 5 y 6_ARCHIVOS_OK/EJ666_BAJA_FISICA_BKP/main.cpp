#include"Persona.h"
#include"bkpPersona.h"

#include<iostream>
#include<cstring>

using namespace std;


int main(){

    Persona obj;

    obj.mostrarArchivo();
    
    bkpPersona obj2;
    obj2.bajaFisica(333);
    obj2.MostrarBackup();

    return 0;
}