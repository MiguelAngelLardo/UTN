#pragma once
#include <string>

class Fecha
{
private:
    int _dia;
    int _mes;
    int _anio;
    int _hora;
    int _minuto;
    int _segundo;

public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);

    int getDia() const;
    int getMes() const;
    int getAnio() const;

    void setFechaActual();
    void setHoraActual();

    bool esBisiesto(int anio) const;
    bool esFechaValida(int dia, int mes, int anio) const;

    void mostrar() const;
    void mostrarHora() const;
    bool operator==(const Fecha &otra) const;
    bool operator>(const Fecha &otra) const;
    bool operator<(const Fecha &otra) const;

    std::string toString() const;

};

