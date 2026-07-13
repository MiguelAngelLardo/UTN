#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename Obj>
class TArchivo {
public:

  bool agregarRegistro(Obj reg, std::string nombreArchivo){
    FILE *pFile = fopen(nombreArchivo.c_str(), "ab");
    if(pFile == NULL){
        return false;
    }

    bool escribio = fwrite(&reg, sizeof(Obj), 1, pFile);
    fclose(pFile);
    return escribio;
  };


  Obj leer(int pos, std::string nombreArchivo){
    FILE *pFile = fopen(nombreArchivo.c_str(), "rb");
    if(pFile == NULL){
      return Obj();
    }

    Obj reg;
    fseek(pFile, pos * sizeof(Obj), SEEK_SET);//primer reg es el cero
    fread(&reg, sizeof(Obj), 1, pFile);
    fclose(pFile);
    return reg;
  };

  /**
  * @brief Lee todos los regs del archivo binario y los almacena en un array dinámico.
  *
  * Este método carga en memoria todos los regs existentes en un archivo `.DAT`.
  * No se realiza ninguna verificación por clave primaria ya que se asume que todos
  * los regs son únicos y válidos. El array dinámico debe tener espacio suficiente
  * para contener la cantidad total de regs especificada.
  *
  * @param v[] Array dinámico donde se almacenarán los regs leídos desde el archivo.
  * @param cantidadregs Cantidad total de regs a leer (generalmente obtenida con otro método).
  * @param nombreArchivo Nombre del archivo binario (.DAT) desde donde se leerán los datos.
  *
  * @note El array debe estar previamente reservado dinámicamente con el tamaño adecuado.
  *       Ya que se conoce desde afuera de la función la cantidad total de regs a leer.
  *       Esta función no realiza validaciones internas sobre la integridad del archivo.
  */
  void leer(Obj v[], int cantidadregs, std::string nombreArchivo){//aca no necesito preguntar nada, por que cada reg tiene PK unica
    FILE *pFile = fopen(nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
      return;
    }
    for(int i = 0; i < cantidadregs; i++){
      fread(&v[i], sizeof(Obj), 1, pFile);
    }
    fclose(pFile);
  }; // método sobrecargado


  bool modificar(Obj reg, int pos, std::string nombreArchivo){
    FILE *pFile = fopen(nombreArchivo.c_str(), "rb+");
    if(pFile == NULL){
      return false;
  }
    fseek(pFile, pos * sizeof(Obj), SEEK_SET);//primer reg es cero
    bool escribio = fwrite(&reg, sizeof(Obj), 1, pFile);
    fclose(pFile);
    return escribio;
  };


  // Retorna la cantidad de regs del archivo => puede ser cero
 // Si el archivo no existe o no se puede abrir, devuelve -1.
  int getCantidadRegistros(std::string nombreArchivo){
    FILE *pFile = fopen(nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return -1;
    }
    fseek(pFile, 0, SEEK_END);//se mueve cero desde el final
    int cantidad = ftell(pFile) / sizeof(Obj); //ftell es cuanto pesa desde el inicio hasta el puntero
    fclose(pFile);
    return cantidad;
    };

  bool existeArchivo(std::string nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo.c_str(), "rb");
    if (archivo == nullptr) return false;
    fclose(archivo);
    return true;
  };

};
