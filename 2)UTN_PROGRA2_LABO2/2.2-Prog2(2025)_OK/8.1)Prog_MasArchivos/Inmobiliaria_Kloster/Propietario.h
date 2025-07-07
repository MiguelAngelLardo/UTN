#pragma once

class Propietario{
private:
    char apellido[50];
    char nombre[50];
    char dni[12];
    char celular[15];
    bool estado;

public:
    /// getters y setters
    void setApellido(const char* _ap);
    void setNombre(const char* _no);
    void setDni(const char* _dni);
    void setCelular(const char* _celu);
    void setEstado(bool _estado);

    char* getApellido();
    char* getNombre();
    char* getDni();
    char* getCelular();
    bool getEstado();

    /// métodos
    bool Cargar(char* _nuevoDni = (char*) "NADA");
    void Mostrar();
};
