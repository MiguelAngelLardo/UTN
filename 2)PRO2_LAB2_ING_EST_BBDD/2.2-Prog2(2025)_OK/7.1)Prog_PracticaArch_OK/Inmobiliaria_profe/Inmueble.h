#pragma once

class Inmueble{
private:
    int codInmueble;
    int tipoPropiedad;  //1-Casa - 2-Depto
    char calle [50];
    char numero [6];
    int antiguedad;
    float superficieTotal;
    int cantHabitaciones;
    float precioVenta;
    float precioAlquiler;
    char dniPropietario[12];
    bool estado;

public:

    ///getters y setters
    void setCodInmueble(int _cod);
    void setTipoPropiedad(int tipo);
    void setCalle(char* _calle);
    void setNumero(char* _num);
    void setAntiguedad(int _antig);
    void setSuperficieTotal(float sup);
    void setCantHabitaciones(int _cantHab);
    void setPrecioVenta(float _pv);
    void setPrecioAlquier(float _pa);
    void setDniPropietario(const char* _codPropietario);
    void setEstado(bool _estado);

    int getCodInmueble();
    int getTipoPropiedad();
    char* getCalle();
    char* getNumero();
    int getAntiguedad();
    float getSuperficieTotal();
    int getCantHabitaciones();
    float getPrecioVenta();
    float getPrecioAlquier();
    const char* getDniPropietario();
    bool getEstado();

    ///metodos:
    bool Cargar(int _cod=0);
    void Mostrar();

};

