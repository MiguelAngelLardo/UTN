#pragma once
#include "Fecha.h"

class Servicio{
    private:
        int _IDServicio, _IDPersonal, _IDReparacion, _tiempo;
        float _calificacion, _costoRepuestos, _importe;
        Fecha _fecha;

    public:
    Servicio();
    Servicio(int IDServicio, int IDpersonal, int IDReparacion, int tiempo, float calificacion, float costoRepuestos, float importe, Fecha fecha);

    int getIDServicio();
    int getIDPersonal();
    int getIDReparacion();
    int getTiempo();
    float getCalificacion();
    float getCostoRepuestos();
    float getImporte();
    Fecha getFecha();

    void setIDServicio(int IDServicio);
    void setIDPersonal(int IDPersonal);
    void setIDReparacion(int IDReparacion);
    void setTiempo(int tiempo);
    void setCalificacion(float calificacion);
    void setCostoRepuestos(float costoRepuestos);
    void setImporte(float Importe);
    void setFecha(Fecha fecha);

    std::string toCSV();

};
