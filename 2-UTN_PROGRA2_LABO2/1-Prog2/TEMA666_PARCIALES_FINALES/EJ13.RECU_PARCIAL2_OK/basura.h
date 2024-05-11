#pragma once

#include"parcial2.h"

//aqui hice una clase con "constructores" en private:
void maneraNumero1Basura(){
// #include<iostream>
// #include<cstring>

// using namespace std;

// #include"parcial2.h"
// #include"basura.h"

// class Archivo{

//     private:
//         //Medico IDpersona; //composiciones
//         Socio CodigoSocio; //composiciones
//         Socio NombreSocio; //composiciones
//         Turno Fecha; //composiciones
//     public:
//         Socio& getSocio(){return CodigoSocio;}
//         Socio& getNombre(){return NombreSocio;}
//         Turno& getTurno(){return Fecha;}
//         //Medico& getMedico(){return IDpersona;}

//         void setSocio(Socio C){CodigoSocio = C;}
//         void setNombre(Socio C){NombreSocio = C;}
//         void setTurno(Turno C){Fecha = C;}
//         //void setMedico(Medico C){IDpersona = C;}
        
//         void setearTodo(Socio S,Turno T/*,Medico M*/){
//             setSocio(S); 
//             setNombre(S);
//             setTurno(T);
//             //setMedico(M);
//         }

//         void mostrar(){
//             //cout<<"ID Medico: "<<getMedico().getIDpersonal()<<endl;
//             cout<<"Codigo de Socio: "<<getSocio().getCodigoSocio()<<endl;
//             cout<<"Nombre de Socio: "<<getSocio().getNombre()<<endl;
//             cout<<"Fecha de Turno: "<<endl;
//             getTurno().getFechaTurno().Mostrar();
//         }

// void GuardarArchivo(Archivo& obj){
//    FILE *p;
//    p = fopen("Archivo.dat","ab");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    fwrite(&obj,sizeof(Archivo),1,p);
//    fclose(p);
// }

// void BorrarArchivo(){
//    FILE *p;
//    p = fopen("Archivo.dat","wb");
//    if(p == NULL){
//       cout<<"No se pudo borrar el archivo";
//       cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    fclose(p);
// }

// void mostrarArchivo(){
//     Archivo objE;
//     FILE *p;
//     p = fopen("Archivo.dat","rb");
//     if(p==NULL){
//         cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
//         cout<<"En la Linea: "<<__LINE__<<endl;
//         exit(1);
//     }

// while (fread(&objE, sizeof(Archivo), 1, p) == true){
//     objE.mostrar();
//     cout << endl;
// }

//     fclose(p);
// }

// };



// int main(){

//     Socio objS;
//     ArchivoSocios ARobjS("socios.dat");

//     Turno objT;
//     ArchivoTurnos ARobjT("turnos.dat");


//     Medico objM;
//     ArchivoMedicos ARobjM("medicos.dat");

//     Archivo objA;
//     objA.BorrarArchivo();

//     int band=true;
//     int tam1= ARobjS.contarRegistros();
//     int tam2= ARobjT.contarRegistros();
//     int tam3= ARobjM.contarRegistros();

//     for(int i=0;i<tam1;i++){
//         objS = ARobjS.leerRegistro(i);
//         if(objS.getEstado()==true){

//             for(int j=0;j<tam2;j++){
//                 objT = ARobjT.leerRegistro(j);
//                 if(objT.getEstado()==true){

//                     for(int k=0;k<tam3;k++){
//                         objM = ARobjM.leerRegistro(k);
                                
//                         if((objM.getEstado()==true)&&(objM.getIDpersonal()==225)&& (strcmp(objS.getCodigoSocio(),objT.getCodigoSocio())==0)&&(objT.getIDpersonal()==objM.getIDpersonal())){
//                             if(band==true){
//                                 //objT.getIDpersonal() == objM.getIDpersonal())
//                                 // cout<<"Codigo de Socio: "<<objS.getCodigoSocio()<<endl;
//                                 // cout<<"Nombre de Socio: "<<objS.getNombre()<<endl; 
//                                 // cout<<"Fecha de Turno: "<<endl;
//                                 // objT.getFechaTurno().Mostrar();
                                
//                                 objA.setearTodo(objS,objT/*,objM*/);
//                                 objA.GuardarArchivo(objA);

//                                 band=false;

//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     objA.mostrarArchivo();


//     return 0;
// }
}

//aqui hice una clase con "variables" en private:
void maneraNumero2Basura(){
// #include<iostream>
// #include<cstring>

// using namespace std;

// #include"parcial2.h"
// #include"basura.h"

// class Archivo{

//     private:
//         //int IDpersona;
//         char CodigoSocio[30];
//         char NombreSocio[30];
//         int dia,mes,anio; //Fecha de Turno
//     public:
//         //void setIDpersona(int IDpersona){this->IDpersona=IDpersona;}
//         void setCodigoSocio(const char*CodigoSocio){strcpy(this->CodigoSocio,CodigoSocio);}
//         void setNombreSocio(const char*NombreSocio){strcpy(this->NombreSocio,NombreSocio);}
        
//         void setDia(int dia){this->dia=dia;}
//         void setMes(int mes){this->mes=mes;}
//         void setAnio(int anio){this->anio=anio;}

//         void setFecha(int dia,int mes,int anio){
//             setDia(dia);
//             setMes(mes);
//             setAnio(anio);
//         }
        
//         //int getIDpersona(){return IDpersona;}
//         const char* getCodigoSocio(){return CodigoSocio;}
//         const char* getNombreSocio(){return NombreSocio;}
//         int getDia(){return dia;}
//         int getMes(){return mes;}
//         int getAnio(){return anio;}

//         void setearTodo(const char *cod, const char *nom, int dia, int mes, int anio/*, int IDpersona*/){
//             //setIDpersona(IDpersona);
//             setCodigoSocio(cod);
//             setNombreSocio(nom);
//             setFecha(dia,mes,anio);
//         }

        
//         void mostrar(){
//             //cout<<"ID Medico: "<<getIDpersona()<<endl;
//             cout<<"Codigo de Socio: "<<getCodigoSocio()<<endl;
//             cout<<"Nombre de Socio: "<<getNombreSocio()<<endl; 
//             cout<<"Fecha de Turno: "<<getDia()<<"/"<<getMes()<<"/"<<getAnio()<<endl;
//         }

// void GuardarArchivo(Archivo& obj){
//    FILE *p;
//    p = fopen("Archivo.dat","ab");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    fwrite(&obj,sizeof(Archivo),1,p);
//    fclose(p);
// }

// void BorrarArchivo(){
//    FILE *p;
//    p = fopen("Archivo.dat","wb");
//    if(p == NULL){
//       cout<<"No se pudo borrar el archivo";
//       cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    fclose(p);
// }

// void mostrarArchivo(){
//     Archivo objE;
//     FILE *p;
//     p = fopen("Archivo.dat","rb");
//     if(p==NULL){
//         cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
//         cout<<"En la Linea: "<<__LINE__<<endl;
//         exit(1);
//     }

// while (fread(&objE, sizeof(Archivo), 1, p) == true){
//     objE.mostrar();
//     cout << endl;
// }

//     fclose(p);
// }

// };



// int main(){

//     Socio objS;
//     ArchivoSocios ARobjS("socios.dat");

//     Turno objT;
//     ArchivoTurnos ARobjT("turnos.dat");


//     Medico objM;
//     ArchivoMedicos ARobjM("medicos.dat");

//     Archivo objA;
//     objA.BorrarArchivo();

//     int band=true;
//     int tam1= ARobjS.contarRegistros();
//     int tam2= ARobjT.contarRegistros();
//     int tam3= ARobjM.contarRegistros();

//     for(int i=0;i<tam1;i++){
//         objS = ARobjS.leerRegistro(i);
//         if(objS.getEstado()==true){

//             for(int j=0;j<tam2;j++){
//                 objT = ARobjT.leerRegistro(j);
//                 if(objT.getEstado()==true){

//                     for(int k=0;k<tam3;k++){
//                         objM = ARobjM.leerRegistro(k);
                                
//                         if((objM.getEstado()==true)&&(objM.getIDpersonal()==225)&& (strcmp( objS.getCodigoSocio() , objT.getCodigoSocio()) ==0 )&&(objT.getIDpersonal()==objM.getIDpersonal())){
//                             if(band==true){
                                
//                                 // cout<<"Codigo de Socio: "<<objS.getCodigoSocio()<<endl;
//                                 // cout<<"Nombre de Socio: "<<objS.getNombre()<<endl; 
//                                 // cout<<"Fecha de Turno: "<<endl;
//                                 // objT.getFechaTurno().Mostrar();
//                                 objA.setearTodo(objS.getCodigoSocio() , objS.getNombre() , objT.getFechaTurno().getDia() , objT.getFechaTurno().getMes() , objT.getFechaTurno().getAnio() /*, objM.getIDpersonal()*/);
//                                 objA.GuardarArchivo(objA);
//                                 band=false;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     objA.mostrarArchivo();


//     return 0;
// }
}

void mostrarArchivoBasura(){


    Socio objS;
    ArchivoSocios ARobjS("socios.dat");

    Turno objT;
    ArchivoTurnos ARobjT("turnos.dat");

    Especialidad objE;
    ArchivoEspecialidades ARobjE("especialidades.dat");

    Medico objM;
    ArchivoMedicos ARobjM("medicos.dat");


    int tam1= ARobjS.contarRegistros();
    int tam2= ARobjT.contarRegistros();
    int tam3= ARobjE.contarRegistros();
    int tam4= ARobjM.contarRegistros();

    cout<<"/////////////////////////////////////////////"<<endl;
    for(int i=0;i<tam1;i++){
        objE = ARobjE.leerRegistro(i);

        if(objE.getEstado()){
            objE.Mostrar();
        }
    }
    cout<<"/////////////////////////////////////////////"<<endl;
    for(int i=0;i<tam2;i++){
        objT = ARobjT.leerRegistro(i);

        if(objT.getEstado()){
            objT.Mostrar();
        }
    }
    cout<<"/////////////////////////////////////////////"<<endl;
    for(int i=0;i<tam3;i++){
        objS = ARobjS.leerRegistro(i);

        if(objS.getEstado()){
            objS.Mostrar();
        }
    }
    cout<<"/////////////////////////////////////////////"<<endl;
    for(int i=0;i<tam4;i++){
        objM = ARobjM.leerRegistro(i);

        if(objM.getEstado()){
            objM.Mostrar();
        }
    }
    cout<<"/////////////////////////////////////////////"<<endl;

}