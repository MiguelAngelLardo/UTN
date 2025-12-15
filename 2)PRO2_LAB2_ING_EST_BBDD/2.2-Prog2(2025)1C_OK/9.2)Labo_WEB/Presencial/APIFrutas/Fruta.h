#ifndef FRUTA_H_INCLUDED
#define FRUTA_H_INCLUDED

#include <string>
#include "json.hpp"

class Fruta{
    private:
        std::string _nombre;
        int _id;
        float _azucar;

    public:
        Fruta();
        Fruta(nlohmann::json datos);
        Fruta(std::string _nombre, int _id, float _azucar);
        std::string toCSV()    ;

        std::string getNombre();
        int getID();
        float getAzucar();

        void setNombre(std::string nombre);
        void setID(int id);
        void setAzucar(float azucar);

};

#endif // FRUTA_H_INCLUDED
