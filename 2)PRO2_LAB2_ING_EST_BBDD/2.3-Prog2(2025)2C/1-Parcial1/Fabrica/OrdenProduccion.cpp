#include "OrdenProduccion.h"

OrdenProduccion::OrdenProduccion(int IDProduccion, int IDMaquina, int IDTipoPieza, int cantidad, float costo, float tiempoEnHoras, float cantidadMateriaPrima, Fecha fecha){
    _IDProduccion = IDProduccion;
    _IDMaquina = IDMaquina;
    _IDTipoPieza = IDTipoPieza;
    _cantidad = cantidad;
    _costo = costo;
    _tiempoEnHoras = tiempoEnHoras;
    _cantidadMateriaPrima = cantidadMateriaPrima;
    _fecha = fecha;
}

OrdenProduccion::OrdenProduccion(){
    _IDProduccion = 0;
    _IDMaquina = 0;
    _IDTipoPieza = 0;
    _cantidad = 0;
    _costo = 0;
    _tiempoEnHoras = 0;
    _cantidadMateriaPrima = 0;
    _fecha = Fecha();
}

int OrdenProduccion::getIDProduccion() {
    return _IDProduccion;
}

int OrdenProduccion::getIDMaquina() {
    return _IDMaquina;
}

int OrdenProduccion::getIDTipoPieza() {
    return _IDTipoPieza;
}

int OrdenProduccion::getCantidad() {
    return _cantidad;
}

float OrdenProduccion::getCosto() {
    return _costo;
}

float OrdenProduccion::getTiempoEnHoras() {
    return _tiempoEnHoras;
}

float OrdenProduccion::getCantidadMateriaPrima() {
    return _cantidadMateriaPrima;
}

Fecha OrdenProduccion::getFecha() {
    return _fecha;
}

void OrdenProduccion::setIDProduccion(int IDProduccion) {
    _IDProduccion = IDProduccion;
}

void OrdenProduccion::setIDMaquina(int IDMaquina) {
    _IDMaquina = IDMaquina;
}

void OrdenProduccion::setIDTipoPieza(int IDTipoPieza) {
    _IDTipoPieza = IDTipoPieza;
}

void OrdenProduccion::setCantidad(int cantidad) {
    _cantidad = cantidad;
}

void OrdenProduccion::setCosto(float costo) {
    _costo = costo;
}

void OrdenProduccion::setTiempoEnHoras(float tiempoEnHoras) {
    _tiempoEnHoras = tiempoEnHoras;
}

void OrdenProduccion::setCantidadMateriaPrima(float cantidadMateriaPrima) {
    _cantidadMateriaPrima = cantidadMateriaPrima;
}

void OrdenProduccion::setFecha(Fecha fecha) {
    _fecha = fecha;
}

std::string OrdenProduccion::toCSV() {
    return std::to_string(_IDProduccion) + "," +
           std::to_string(_IDMaquina) + "," +
           std::to_string(_IDTipoPieza) + "," +
           std::to_string(_cantidad) + "," +
           std::to_string(_costo) + "," +
           std::to_string(_tiempoEnHoras) + "," +
           std::to_string(_cantidadMateriaPrima) + "," +
           _fecha.toString();
}
