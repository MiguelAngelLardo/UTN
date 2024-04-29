#include<iostream>
#include<cstring>

using namespace std;

#include"parcial1l.h"

void GuardarArchivo(Jugador& obj){
   FILE *p;
   p = fopen("cat5.dat","ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
   }
   fwrite(&obj,sizeof(Jugador),1,p);
   fclose(p);
}

void BorrarArchivo(){
   FILE *p;
   p = fopen("cat5.dat","wb");
   if(p == NULL){
      cout<<"No se pudo borrar el archivo";
   }
   fclose(p);
}

void mostrarArchivo(){
    Jugador objE;
    FILE *p;
    p = fopen("cat5.dat","rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        exit(1);
    }

while (fread(&objE, sizeof(Jugador), 1, p) == true){
if(objE.getEstado()){
    cout<<"DNI :"<<objE.getDNI()<<endl;
    cout<<"NOMBRE :"<<objE.getNombre()<<endl;
    cout<<"APELLIDO :"<<objE.getApellido()<<endl;
    cout<<"Fecha de inscripcion :"<<endl;
    objE.getFechaInscirpcion().Mostrar();
    cout << endl;
}
}

    fclose(p);
}

bool ExisteDNI(int dni){
   Jugador obj;
   FILE *p;
   p = fopen("cat5.dat","rb");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
   }
   while(fread(&obj,sizeof(Jugador),1,p)){
      if(obj.getDNI()==dni){
         fclose(p);
         return true;
      }
   }
   fclose(p);
   return false;
}

int main(){

    Jugador objJ;
    ArchivoJugadores ARobjJ("jugadores.dat");

    Deporte objD;
    ArchivoDeportes ARobjD("deportes.dat");

    BorrarArchivo();

    //int band=true;

    int tam1= ARobjJ.contarRegistros();
    int tam2 = ARobjD.contarRegistros();

    for(int i=0;i<tam1;i++){
        objJ = ARobjJ.leerRegistro(i);

        if((objJ.getEstado()==true)){
            
            for(int j=0;j<tam2;j++){

                objD = ARobjD.leerRegistro(j);

                if((objD.getEstado()==true) && (objD.getIdCtegoria()==5) && (objJ.getClaustro()==2) && (objD.getIdDeporte() == objJ.getIdDeporte())){
                    
                    //if(band==true){
                        //GuardarArchivo(objJ);
                        //band=false;
                    //}

                    if(ExisteDNI(objJ.getDNI())==false){
                        GuardarArchivo(objJ);
                    }
                    
                }

            }

        }
        //band=true;
    }

    mostrarArchivo();

    return 0;
}