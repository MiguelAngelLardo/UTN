// // void PuntoD(){
// //     ARpuntoC objC;

// //     int tam = objC.contarRegistros();

// //     int max = 0;

    
// //     int band=true;

// //     for(int i=0;i<tam;i++){
// //         objC = objC.leerRegistro(i);

// //         if(band==true){
// //             max = objC.getCantidadDeViajesEnCadaCentro();
// //             band = false;
// //         }else if(objC.getCantidadDeViajesEnCadaCentro()>max){
// //             max = objC.getCantidadDeViajesEnCadaCentro();
// //         }
// //     }
// //     /////////////////////////////////////////////
// //     int segmax = 0;
// //     int indice = 0;
// //     int aux=0;
// //     band=true;

// //     for(int x=0;x<tam;x++){

// //         for(int j=0;j<tam;j++){
// //             objC = objC.leerRegistro(j);

// //             if((objC.getCantidadDeViajesEnCadaCentro()==max) && (band==true)){
// //                 objC.mostrar();
// //                 cout<<endl;
// //                 band=false;
// //             }

// //             if((objC.getCantidadDeViajesEnCadaCentro()>segmax)/*&&(objC.getCantidadDeViajesEnCadaCentro()<max)*/ && (band==false)){

// //                 if(objC.getCantidadDeViajesEnCadaCentro()<max){
// //                     segmax = objC.getCantidadDeViajesEnCadaCentro();
// //                     max = objC.getCantidadDeViajesEnCadaCentro();
// //                     band = true;

// //                     cout<<"Segundo maximo: "<<segmax<<endl;
// //                 }
// //             }
// //         }
        
// //     }
// //     /////////////////////////////////////////////


// //     // for(int i=0;i<tam;i++){
// //     //     objC = objC.leerRegistro(i);

// //     //     for(int j=0;j<tam;j++){
// //     //         objC = objC.leerRegistro(j);

// //     //         if(((objC.getCantidadDeViajesEnCadaCentro()<=max)) && (objC.getCantidadDeViajesEnCadaCentro()>segmax)){
// //     //             // segmax = objC.getCantidadDeViajesEnCadaCentro();
// //     //             // indice = j;
// //     //             objC.mostrar();
// //     //         }
// //     //     }
// //     //     //cout<<"Cantidad de viajes: "<<max<<endl;
// //     //     max = segmax;
// //     // }
// //     // /////////////////////////////////////////////

// // }