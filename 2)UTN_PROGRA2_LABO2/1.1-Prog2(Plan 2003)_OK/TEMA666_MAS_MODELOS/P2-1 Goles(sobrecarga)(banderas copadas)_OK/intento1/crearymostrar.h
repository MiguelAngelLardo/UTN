#pragma once

void crearyMostrarPais(int tam){
    //Pais objPais; // PK codigo pais - uso el nombre del pais para el nuevo archivo
    ArchivoPais objARPais;

    //objARPais.crearArchivo(tam);
    cout<<"\n\n\n -.--.--.--.--.--.--.--.--.--.--.--.--.--.-"<<endl;
    objARPais.mostrarArchivo();
}

void crearyMostrarJugador(int tam){
    //Jugador objJugador; // PK codigo pais - uso el nombre del pais para el nuevo archivo
    ArchivoJugador objARJugador;

    //objARJugador.crearArchivo(tam);
    cout<<"\n\n\n -.--.--.--.--.--.--.--.--.--.--.--.--.--.-"<<endl;
    objARJugador.mostrarArchivo();
}

void crearyMostrarGoles(int tam){
    //Gol objGoles; // PK codigo pais - uso el nombre del pais para el nuevo archivo
    ArchivoGol objARGoles;

    //objARGoles.crearArchivo(tam);
    cout<<"\n\n\n -.--.--.--.--.--.--.--.--.--.--.--.--.--.-"<<endl;
    objARGoles.mostrarArchivo();
}