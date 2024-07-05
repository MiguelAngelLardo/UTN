//void Examen::punto2(){
//   Multa objMu;
//   MultaArchivo ARobjMu("multas.dat");

//   int tam = ARobjMu.getCantidadRegistros();

//   int cont1=0; //cuenta los que son objMu.getPagada()==true
//   int cont2=0; //cuenta los que son objMu.getPagada()==false
//   int cont3=0;

//   int maxIndex=0;

//   for(int i=0; i<tam; i++){
//     objMu = ARobjMu.leer(i);

//     if(objMu.getIDLocalidad()>maxIndex){
//       maxIndex = objMu.getIDLocalidad();
//     }
//   }

//   Multa *vec;
//   vec = new Multa[maxIndex];
//   if(vec == NULL){
//     cout<<"Error en Linea: "<<__LINE__<<endl;
//     exit(1);
//   }

//   int *vec2;
//   vec2 = new int[maxIndex];
//   if(vec2 == NULL){
//     cout<<"Error en Linea: "<<__LINE__<<endl;
//     exit(1);
//   }

//   for(int i=0; i<tam; i++){
//     objMu = ARobjMu.leer(i);
//     vec[objMu.getIDLocalidad()-1] = objMu;
//     vec2[objMu.getIDLocalidad()-1]++;
//   }

//   for(int i=0; i<maxIndex; i++){
    
//     for(int j=0; j<vec2[i]; j++){
//       if(vec[j].getPagada()==true){
//         cont1++;
//       }else{
//         cont2++;
//       }
//     }

//     if(cont1>cont2){
//       cont3++;
//     }
//   }

//   cout<<"La cantidad de localidades con mas multas pagadas es: "<<cont3<<endl;

//   delete [] vec2;
//   delete [] vec;

// }