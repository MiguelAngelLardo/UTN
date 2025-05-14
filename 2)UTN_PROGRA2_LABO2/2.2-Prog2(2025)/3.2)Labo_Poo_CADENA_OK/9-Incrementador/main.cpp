#include <iostream>
using namespace std;
#include "clsIncrementador.h"

int main()
{
    Incrementador *p = nullptr;
    p = new Incrementador;

    Incrementador inc(1000, 500), inc2(0, 2);
    inc.Incrementar();
    inc.Incrementar();
    inc.Incrementar();

    delete p;


    inc2.Incrementar();
    inc2.Incrementar();
    inc2.Incrementar();
    inc2.Incrementar();
    inc2.Incrementar();
    inc2.Incrementar();
    inc2.Incrementar();


    return 0;
}
