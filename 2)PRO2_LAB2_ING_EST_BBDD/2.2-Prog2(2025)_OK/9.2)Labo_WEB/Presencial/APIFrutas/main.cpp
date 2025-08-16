#include <iostream>
using namespace std;
#include "Fruta.h"
#include "HttpClient.h"
#include "json.hpp"

int main()
{

    HttpClient cliente;
    nlohmann::json datos;
    int cantidadFrutas;

    string url = "https://www.fruityvice.com/api/fruit/all";
    string respuesta = cliente.get(url);
    datos = nlohmann::json::parse(respuesta);
    cantidadFrutas = datos.size();

    Fruta frutaMax;

    for(int i=0; i<cantidadFrutas; i++){
        Fruta fruta(datos[i]);
        if (fruta.getAzucar() > frutaMax.getAzucar()){
            frutaMax = fruta;
        }
    }

    cout << "La fruta con mas nivel de azucar es: " << frutaMax.getNombre() << endl;

    return 0;
}
