#pragma once

#include <string>

template <typename Obj>
class IArchivo {//Interface => todos metodos son puros y es clase Abstracta
                //interface es polimorfismo en tiempo de ejecucion

public:
    // Archivo();
    // Archivo(std::string nombreArchivo);
    //Archivo(std::string nombreArchivo = "") : _nombreArchivo(nombreArchivo) {}

    virtual int getCantidadRegistros() = 0;
    virtual bool agregarRegistro(Obj obj) = 0;
    virtual Obj leerUnRegistro(int pos) = 0;

    virtual int buscarPorId(int id) = 0;
    virtual bool modificarRegistro( obj, int pos) = 0;
 
    virtual ~IArchivo() = default;//el destructor es para prevenir fugas de memoria
                                 //default cumple misma funcion que el CERO, no implementa el prototipo
                                //si no añado destructor en clases derivadas el compilador lo crea implicitamente
  };