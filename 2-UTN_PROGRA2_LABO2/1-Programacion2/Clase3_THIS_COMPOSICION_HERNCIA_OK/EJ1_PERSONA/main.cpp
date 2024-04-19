#include <iostream>

using namespace std;
#include "Docente.h"
#include "Proveedor.h"

int main()
{
  Proveedor p;

    p.cargar();
    cout << endl;
    cout << endl;
    p.mostrar();


    return 0;
}
