#pragma once

class Persona{
    private:
        char nombre[30];
        int edad;
    public:
        void setEdad(int edad);
        int getEdad();

        void setNombre(const char *n);
        const char *getNombre();

        void cargar();

        void mostrar();

void crearArchivo(int tam=5,const char* nombre="Persona.dat");

void cargarArchivo(int tam=5,const char* nombre="Persona.dat");

void mostrarArchivo(const char* nombre="Persona.dat");

void BorrarArchivo(const char* nombre="Persona.dat");

int contarRegistros(const char* nombre="Persona.dat");

Persona leerRegistro(int pos,const char* nombre="Persona.dat");

};