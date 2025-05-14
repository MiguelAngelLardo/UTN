#ifndef HORA_H
#define HORA_H
#include <string>

class Horario
{
    public:
        Horario(int hora, int minuto);
        Horario();
        int getHora();
        int getMinuto();
        void setHora(int hora);
        void setMinuto(int minuto);
        void mostrar();
        std::string toString();

    private:
        int _hora, _minuto;
};

#endif // HORA_H
