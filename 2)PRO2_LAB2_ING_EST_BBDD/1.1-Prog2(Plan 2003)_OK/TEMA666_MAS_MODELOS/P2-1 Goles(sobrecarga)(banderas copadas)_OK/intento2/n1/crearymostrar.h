#pragma once


void crearyMostrarPais(int tam){
    ArchivoPaises objARPais;

    objARPais.crearArchivo(tam);
    cout<<"\n\n\n -.--.--.--.--.--.--.--.--.--.--.--.--.--.-"<<endl;
    objARPais.mostrarArchivo();
}

void crearyMostrarJugador(int tam){
    ArchivoJugadores objARJugador;

    objARJugador.crearArchivo(tam);
    cout<<"\n\n\n -.--.--.--.--.--.--.--.--.--.--.--.--.--.-"<<endl;
    objARJugador.mostrarArchivo();
}

void crearyMostrarGoles(int tam){
    ArchivoGoles objARGoles;

    objARGoles.crearArchivo(tam);
    cout<<"\n\n\n -.--.--.--.--.--.--.--.--.--.--.--.--.--.-"<<endl;
    objARGoles.mostrarArchivo();
}

void cargarTodo(int tam){
    crearyMostrarPais(tam);
    crearyMostrarJugador(tam);
    crearyMostrarGoles(tam);
}
