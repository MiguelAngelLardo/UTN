#pragma once


// void punto2larga(){ //manera corta
//     Equipo objE; //**numero equipo(PK)**, **nombre**
//     ArchivoEquipos ARobjE("equipos.dat");

//     Jugador objJ; //DNI(PK), numeroequipo(fk), id deporte (fk) -> 10 o mas
//     ArchivoJugadores ARobjJ("jugadores.dat");

//     Deporte objD; //id de eporte(PK), **categoria de deporte**
//     ArchivoDeportes ARobjD("deportes.dat");

//     Punto1 objPunto1;
//     ArchivoPunto1 ARobjPunto1;
//     ARobjPunto1.BorrarArchivo();

    
//     int *setIdEquipo; 
//     char *setNombreEquipo;
//     int *setCategoriaDeporte;


//     int tam1 = ARobjE.contarRegistros();
//     int tam2 = ARobjJ.contarRegistros(); //relacion con equipo
//     int tam3 = ARobjD.contarRegistros(); //relacion con jugador


//     int contadorTotalMatch=0;

//     for(int i=0; i<tam1; i++){
//         objE = ARobjE.leerRegistro(i);

//         if(objE.getEstado() == true){
            
//             for (int j=0; j<tam2; j++){
//                 objJ = ARobjJ.leerRegistro(j);
//                 if((objJ.getEstado() == true) && (objE.getIDequipo() == objJ.getIDequipo())){  
                    
                                      
//                     contadorTotalMatch++;
//                     }
//                 }    
//             } 
//         }    
        
//     if(contadorTotalMatch >= 2){
//         setIdEquipo = new int[contadorTotalMatch];
//         (setIdEquipo == NULL) ? "No hay memoria" : "";
//         setNombreEquipo = new char [contadorTotalMatch];
//         (setNombreEquipo == NULL) ? "No hay memoria" : "";
                        
//         setCategoriaDeporte = new int(contadorTotalMatch);
//         (setCategoriaDeporte == NULL) ? "No hay memoria" : "";
//     }

  
//     int indexVector = 0;

//     int cont = 0;
//     for(int i=0; i<tam1; i++){
//         objE = ARobjE.leerRegistro(i);

//         if(objE.getEstado() == true){
            
//             for (int j=0; j<tam2; j++){
//                 objJ = ARobjJ.leerRegistro(j);
//                 if((objJ.getEstado() == true) && (objE.getIDequipo() == objJ.getIDequipo())){                    
//                     cont ++;
                    
//                     if(cont == 2){
//                         setIdEquipo[indexVector] = objE.getIDequipo();
//                         setNombreEquipo[indexVector] = *objE.getNombre();


//                         for(int k=0; k<tam3; k++){
//                             objD = ARobjD.leerRegistro(k);
//                             if((objD.getEstado() == true) && (objJ.getIDdeporte() == objD.getIDdeporte())){
//                                 setCategoriaDeporte[indexVector] = objD.getIDcategoria();
//                             }
//                         }  

//                     }
                    
//                 }
//             }    
//         } 
//     } 


    


    


// }


/*

//preguntando la ia como crear un vector dinamico tipo char
//https://sl.bing.net/eqpO4X5NXPw
//https://sl.bing.net/eqpO4X5NXPw
void punto2larga(){ //manera corta
    Equipo objE; //**numero equipo(PK)**, **nombre**
    ArchivoEquipos ARobjE("equipos.dat");

    Jugador objJ; //DNI(PK), numeroequipo(fk), id deporte (fk) -> 10 o mas
    ArchivoJugadores ARobjJ("jugadores.dat");

    Deporte objD; //id de eporte(PK), **categoria de deporte**
    ArchivoDeportes ARobjD("deportes.dat");

    Punto1 objPunto1;
    ArchivoPunto1 ARobjPunto1;
    ARobjPunto1.BorrarArchivo();

    int tam1 = ARobjE.contarRegistros();
    int tam2 = ARobjJ.contarRegistros(); //relacion con equipo
    int tam3 = ARobjD.contarRegistros(); //relacion con jugador

    //crear vectores dinamicos de Equipos
    int *NumDeEquipo;
    char **NombDeEquipo;
    int *CategoriaDeDeporte;


    NumDeEquipo = new int[tam1];
    if(NumDeEquipo == NULL){
        cout << "No se pudo crear el vector" << endl;
    }

    CargarVector(NumDeEquipo, tam1, -1);

    NombDeEquipo = new char*[tam1];
    for(int i = 0; i < tam1; ++i) {
        NombDeEquipo[i] = new char[30];  // Asume que MAX_NOMBRE_LENGTH es la longitud máxima de un nombre
    }

    CategoriaDeDeporte = new int[tam1];  //tam3
    if(CategoriaDeDeporte == NULL){
        cout << "No se pudo crear el vector" << endl;
    }


    int cont=0;

    for(int i=0; i<tam1; i++){
        objE = ARobjE.leerRegistro(i);

        if(objE.getEstado() == true){
            
            for (int j=0; j<tam2; j++){
                objJ = ARobjJ.leerRegistro(j);
                if((objJ.getEstado() == true) && (objE.getIDequipo() == objJ.getIDequipo())){
                    
                    cont++;
                    if(cont == 2){ //cambiamos a cont==2 pero deberia poner cont == 10
                        //objPunto1.setIdEquipo(objE.getIDequipo());
                        //objPunto1.setNombreEquipo(objE.getNombre());
                        NumDeEquipo[i] = objE.getIDequipo();
                        strcpy(NombDeEquipo[i], objE.getNombre());

                        for(int k=0; k<tam3; k++){
                            objD = ARobjD.leerRegistro(k);
                            if((objD.getEstado() == true) && (objJ.getIDdeporte() == objD.getIDdeporte())){
                                    //objPunto1.setCategoriaDelDeporte(objD.getIDcategoria());
                                    CategoriaDeDeporte[i] = objD.getIDcategoria();
                                    //ARobjPunto1.GuardarArchivo(objPunto1);
                            }
                        }  

                    }
                }    
            } 
            cont=0; 
        }    
    }    
    //ARobjPunto1.mostrarArchivo();

    for(int i=0; i<tam1; i++){

        if(NumDeEquipo[i] != -1){
        cout<<"Numero de equipo: "<<NumDeEquipo[i]<<endl;
        cout<<"Nombre de equipo: "<<NombDeEquipo[i]<<endl;
        cout<<"Categoria del deporte: "<<CategoriaDeDeporte[i]<<endl<<endl;
        }
    }

    delete []NumDeEquipo;

    for(int i = 0; i < tam1; ++i) {
    delete[] NombDeEquipo[i];
    }

    delete []CategoriaDeDeporte;
}



*/



/*



void puntoD(){
    Deporte objD;//idDeporte (PK), **nombre de deporte**
    ArchivoDeportes ARobjD("deportes.dat");

    Jugador objJ;//**DNI(PK)**, **nombre**, **apellido**, **claustro**, id deporte (fk) -> matricula > 10000 y fecha inscrip == 2024
    ArchivoJugadores ARobjJ("jugadores.dat");

    //PuntoD objPuntoD;
    //ArchivoPuntoD ARobjPuntoD("puntod.dat");
    //ARobjPuntoD.BorrarArchivo();

    int tam1 = ARobjD.contarRegistros();
    int tam2 = ARobjJ.contarRegistros();

    for(int i=0; i<tam1; i++){
        objD = ARobjD.leerRegistro(i);
        if(objD.getEstado() == true){
        
            for(int j=0; j<tam2; j++){
                objJ = ARobjJ.leerRegistro(j);
            
                if((objJ.getEstado() == true) && (objD.getIDdeporte() == objJ.getIDdeporte())){ 
                    
                    if((objJ.getMatricula() > 10000) && (objJ.getFechaInscirpcion().getAnio() == 2024)){
                        //objPuntoD.setearTodo(objJ.getDni(), objJ.getNombre(), objJ.getApellido(), objJ.getClaustro(), objD.getNombre());
                        //ARobjPuntoD.guardarRegistro(objPuntoD);
                    }
                }     
            }        
        }    
    }    
}



*/
















