#pragma once

void pruebaN1(){

    Paises objPaises;
    ArchivoPaises objAPaises;

    Jugadores objJugadores;
    ArchivoJugadores objAJugadores;

    int tam1 = objAPaises.contarRegistros();
    int tam2 = objAJugadores.contarRegistros();

    for(int i=0; i<tam1; i++){
        objPaises = objAPaises.leerRegistro(i);
    
        for(int j=0; j<tam2; j++){
            objJugadores = objAJugadores.leerRegistro(j);

            if(objPaises.getCodigoPais()==objJugadores.getCodigoPais()){
                cout<<"objPaises.getCodigoPais()"<<objPaises.getCodigoPais()<<endl;
            }

        }
    }

}