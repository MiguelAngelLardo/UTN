#include <iostream>
#include "HttpClient.h"
#include "json.hpp"
#include "Fruta.h"

using namespace std;

int main()
{
    HttpClient client;
    nlohmann::json data;
    
    string res;
    
    res = client.get("https://raw.githubusercontent.com/TheRegext/programacion2-20251c-n/refs/heads/main/Semana%209/Jueves/frutas.json");
    
    data = nlohmann::json::parse(res);// hace magia
    
    int cantidad = data.size();
    Fruta *frutas;
    frutas = new Fruta[cantidad];
    
    
    
    for(int i=0; i<cantidad; i++){
      frutas[i] = Fruta(data[i]);
    }
    
    for(int i=0; i<cantidad; i++){
      cout << frutas[i].toCSV() << endl;
    }
    
    /**
    "nutritions": {
    "calories": 96,
    */
    
    
    return 0;
}
