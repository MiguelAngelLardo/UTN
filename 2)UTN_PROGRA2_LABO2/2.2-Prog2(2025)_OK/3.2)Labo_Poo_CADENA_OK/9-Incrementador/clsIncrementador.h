#ifndef CLSINCREMENTADOR_H_INCLUDED
#define CLSINCREMENTADOR_H_INCLUDED

class Incrementador{

    private:
    int _valor,
        _valorIncremento,
        _valorInicial,
        _cantIncrementos;


    public:
    Incrementador(); // Constructor #1 - Sin params
    Incrementador(int valorInicial, int valorIncremento); // Constructor #2 - Con params
    ~Incrementador();

    void Restablecer();
    void Incrementar();
    int getValor();
    int getCantidadIncrementos();

};


#endif // CLSINCREMENTADOR_H_INCLUDED
