#pragma once
#include "Fecha.h"

/*
   La Orden de Producción es un documento o registro que organiza y controla la fabricación en una planta industrial.
   Contiene la identificación de la orden, la máquina y el tipo de pieza a producir, junto con la cantidad solicitada
   de piezas, el tiempo de trabajo, el consumo de materia prima y el costo de la producción.
   Además, incluye la fecha en que se termina la orden de producción.
*/
class OrdenProduccion{
    private:
      int _IDProduccion, _IDMaquina, _IDTipoPieza, _cantidad;//id maquina de 1 a 15 - idTipoPieza 1 a 40
      float _costo, _tiempoEnHoras, _cantidadMateriaPrima;
        Fecha _fecha;

    public:
      OrdenProduccion(int IDProduccion, int IDMaquina, int IDTipoPieza, int cantidad, float costo, float tiempoEnHoras, float cantidadMateriaPrima, Fecha fecha);
      OrdenProduccion();

      int getIDProduccion();
      int getIDMaquina();
      int getIDTipoPieza();
      int getCantidad();
      float getCosto();
      float getTiempoEnHoras();
      float getCantidadMateriaPrima();
      Fecha getFecha();

      void setIDProduccion(int IDProduccion);
      void setIDMaquina(int IDMaquina);
      void setIDTipoPieza(int IDTipoPieza);
      void setCantidad(int cantidad);
      void setCosto(float costo);
      void setTiempoEnHoras(float tiempoEnHoras);
      void setCantidadMateriaPrima(float cantidadMateriaPrima);
      void setFecha(Fecha fecha);

      std::string toCSV();

};


