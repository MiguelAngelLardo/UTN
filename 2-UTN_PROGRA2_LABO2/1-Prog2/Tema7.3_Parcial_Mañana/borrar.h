/////////////////////////////
    // Multa objM;
    // ArchivoMultas ARobjM("Multas.dat");

    // //ARobjM.crearArchivo();
    
    // cout<<endl<<endl<<"---------"<<endl<<endl;

    // int tam1= ARobjM.contarRegistros();
    // for(int i=0; i<tam1; i++){
        
    //     objM=ARobjM.leerRegistro(i);
    //     if(objM.getEstado()==true){
    //         objM.Mostrar();
    //     }
    // }

/////////////////////////////

    // Infraccion objI;
    // ArchivoInfracciones ARobjI("Infracciones.dat");

    // //ARobjI.crearArchivo();

    // cout<<endl<<endl<<"---------"<<endl<<endl;

    // int tam2= ARobjI.contarRegistros();

    // for(int i=0; i<tam2; i++){
    //     objI=ARobjI.leerRegistro(i);
        
    //     if(objI.getEstado()==true){
    //     objI.Mostrar();
    //     }

    // }

/////////////////////////////

// void crearArchivo(int tam=10){
//     Multa objE;
//     FILE *p;
//     p = fopen(nombre,"wb");
//     if(p==NULL){
//         cout << "No se pudo abrir el archivo crearArchivo" << endl;
//         exit(1);
//     }
//     for(int i=0; i<tam; i++){
//     objE.Cargar();
//     cout<<endl;
//     fwrite(&objE, sizeof(Multa), 1, p);
//     }
//     fclose(p);
// }

/////////////////////////////

// void crearArchivo(int tam=10){
//     Infraccion objE;
//     FILE *p;
//     p = fopen(nombre,"wb");
//     if(p==NULL){
//         cout << "No se pudo abrir el archivo crearArchivo" << endl;
//         exit(1);
//     }
//     for(int i=0; i<tam; i++){
//     objE.Cargar();
//     cout<<endl;
//     fwrite(&objE, sizeof(Infraccion), 1, p);
//     }
//     fclose(p);
// }

/////////////////////////////