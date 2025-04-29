#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
#include "funcadenas.h"

int main()
{
    while(1)
    {
      int opc;
      system("cls");
      cout<<"1. Copiar cadenas"<<endl;
      cout<<"2. Comparar cadenas"<<endl;
      cout<<"3. Trabajar con varias cadenas"<<endl;
      cout<<"4. Salir"<<endl;
      cout<<"Seleccione una opción: ";
      cin>>opc;
      switch(opc)
      {
        case 1: copiarCadenas();
                break;
        case 2: compararCadenas();
                break;
        case 3: variasCadenas();
                break;
        case 4: exit(1);
        }
      }
    return 0;
}
