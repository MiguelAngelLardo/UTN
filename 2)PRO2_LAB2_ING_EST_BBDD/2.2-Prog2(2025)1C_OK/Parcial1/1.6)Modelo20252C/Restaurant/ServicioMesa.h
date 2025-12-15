#pragma once
#include "Fecha.h"

class ServicioMesa{
    private:
        int _IDServicioMesa, _IDMozo, _IDPlato, _tiempoPreparacion;//Mozo 1 a 20 - Plato 1 a 70 
        float _puntajeObtenido, _propina, _importe; //propina = 0 => no recibio
        Fecha _fecha;//Composicion 

    public:
    ServicioMesa();
    ServicioMesa(int IDServicioMesa, int IDMozo, int IDPlato, int tiempoPreparacion, float puntajeObtenido, float propina, float importe, Fecha fecha);
    
    int getIDServicioMesa();//prototipo - Declaracion - Firma
    int getIDMozo();
    int getIDPlato();
    int getTiempoPreparacion();
    float getPuntajeObtenido();
    float getPropina();
    float getImporte();
    Fecha getFecha();

    void setIDServicioMesa(int IDServicioMesa);
    void setIDMozo(int IDMozo);
    void setIDPlato(int IDPlato);
    void setTiempoPreparacion(int TiempoPreparacion);
    void setPuntajeObtenido(float PuntajeObtenido);
    void setPropina(float Propina);
    void setImporte(float Importe);
    void setFecha(Fecha fecha);

    std::string toCSV();
    
};