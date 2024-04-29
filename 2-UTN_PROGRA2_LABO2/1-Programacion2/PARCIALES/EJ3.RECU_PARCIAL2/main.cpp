#include<iostream>
#include<cstring>

using namespace std;

#include"parcial2.h"
#include"basura.h"

class Archivo{

    private:
        //int IDpersona;
        char CodigoSocio[30];
        char NombreSocio[30];
        int dia,mes,anio; //Fecha de Turno
    public:

        Archivo(const char* CodSocio = "S/C", const char* NomSocio = "S/N", int dia = 0, int mes = 0, int anio = 0/*, int IDpersona = 0*/)
        : dia(dia),mes(mes),anio(anio) /*,IDpersona(IDpersona)*/ {
            strcpy(CodigoSocio,CodSocio);
            strcpy(NombreSocio,NomSocio);
        }
            
        

        //void setIDpersona(int IDpersona){this->IDpersona=IDpersona;}
        void setCodigoSocio(const char*CodigoSocio){strcpy(this->CodigoSocio,CodigoSocio);}
        void setNombreSocio(const char*NombreSocio){strcpy(this->NombreSocio,NombreSocio);}
        
        void setDia(int dia){this->dia=dia;}
        void setMes(int mes){this->mes=mes;}
        void setAnio(int anio){this->anio=anio;}

        void setFecha(int dia,int mes,int anio){
            setDia(dia);
            setMes(mes);
            setAnio(anio);
        }
        
        //int getIDpersona(){return IDpersona;}
        const char* getCodigoSocio(){return CodigoSocio;}
        const char* getNombreSocio(){return NombreSocio;}
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

        void setearTodo(const char *cod, const char *nom, int dia, int mes, int anio/*, int IDpersona*/){
            //setIDpersona(IDpersona);
            setCodigoSocio(cod);
            setNombreSocio(nom);
            setFecha(dia,mes,anio);
        }

        
        void mostrar(){
            //cout<<"ID Medico: "<<getIDpersona()<<endl;
            cout<<"Codigo de Socio: "<<getCodigoSocio()<<endl;
            cout<<"Nombre de Socio: "<<getNombreSocio()<<endl; 
            cout<<"Fecha de Turno: "<<getDia()<<"/"<<getMes()<<"/"<<getAnio()<<endl;
        }

void GuardarArchivo(Archivo& obj){
   FILE *p;
   p = fopen("Archivo.dat","ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Archivo),1,p);
   fclose(p);
}

void BorrarArchivo(){
   FILE *p;
   p = fopen("Archivo.dat","wb");
   if(p == NULL){
      cout<<"No se pudo borrar el archivo";
      cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fclose(p);
}

void mostrarArchivo(){
    Archivo objE;
    FILE *p;
    p = fopen("Archivo.dat","rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

while (fread(&objE, sizeof(Archivo), 1, p) == true){
    objE.mostrar();
    cout << endl;
}

    fclose(p);
}

};

void Punto1(){

    Socio objS;
    ArchivoSocios ARobjS("socios.dat");

    Turno objT;
    ArchivoTurnos ARobjT("turnos.dat");


    Medico objM;
    ArchivoMedicos ARobjM("medicos.dat");

    Archivo objA;
    objA.BorrarArchivo();

    int band=true;
    int tam1= ARobjS.contarRegistros();
    int tam2= ARobjT.contarRegistros();
    int tam3= ARobjM.contarRegistros();

    for(int i=0;i<tam1;i++){
        objS = ARobjS.leerRegistro(i);
        if(objS.getEstado()==true){

            for(int j=0;j<tam2;j++){
                objT = ARobjT.leerRegistro(j);
                if(objT.getEstado()==true){

                    for(int k=0;k<tam3;k++){
                        objM = ARobjM.leerRegistro(k);
                                
                        if((objM.getEstado()==true)&&(objM.getIDpersonal()==225)&& (strcmp( objS.getCodigoSocio() , objT.getCodigoSocio()) ==0 )&&(objT.getIDpersonal()==objM.getIDpersonal())){
                            if(band==true){
                                
                                // cout<<"Codigo de Socio: "<<objS.getCodigoSocio()<<endl;
                                // cout<<"Nombre de Socio: "<<objS.getNombre()<<endl; 
                                // cout<<"Fecha de Turno: "<<endl;
                                // objT.getFechaTurno().Mostrar();
                                objA.setearTodo(objS.getCodigoSocio() , objS.getNombre() , objT.getFechaTurno().getDia() , objT.getFechaTurno().getMes() , objT.getFechaTurno().getAnio() /*, objM.getIDpersonal()*/);
                                objA.GuardarArchivo(objA);
                                band=false;
                            }
                        }
                    }
                }
            }
        }
    }

    objA.mostrarArchivo();

}

int main(){
    Punto1();

    // // Turno objT;
    // // ArchivoTurnos ARobjT("turnos.dat");

    // // Especialidad objE;
    // // ArchivoEspecialidades ARobjE("especialidades.dat");

    // // int tam1= ARobjT.contarRegistros();
    // // int tam2= ARobjE.contarRegistros();

    // // int *vec;
    // // vec = new int[tam1];
    // // if(vec==NULL){
    // //     cout<<"No se pudo crear el vector"<<endl;
    // //     cout<<"Error en la Linea: "<<__LINE__<<endl;
    // //     exit(1);
    // // }

    // // for(int i=0;i<tam1;i++){
    // //     vec[i]= -1;
    // // }

    // // int codEspecialidad;

    // // cout<<"ingrese la Codigo de especialidad"<<endl;
    // // cin>>codEspecialidad;

    // // for(int i=0;i<tam1;i++){
    // //     objT = ARobjT.leerRegistro(i);
    // //     //objT.Mostrar();
    // //     if((objT.getEstado()==true)&&(objT.getCodigoEspecialidad()==codEspecialidad)){

    // //         for(int j=0;j<tam2;j++){
    // //             objE = ARobjE.leerRegistro(j);

    // //             if((objE.getEstado()==true) && (objE.getCodigoEspecialidad()==codEspecialidad) ){
    // //                //cout<<"el turno es: "<<objT.getCodigoEspecialidad();
    // //                vec[i]=objT.getNumeroTurno();
    // //             }
    // //         }

    // //     }
    // // }



    // // cout<<"el numero de especialidad es: "<<codEspecialidad<<endl;
    // // cout<<"los turnos son: "<<endl;

    // // for(int i=0;i<tam1;i++){
    // //     if(vec[i]!=-1){
    // //         cout<<vec[i]<<endl;
    // //     }
    // // }

    // // delete []vec;

/*********************************************************/

    // Turno objT;
    // ArchivoTurnos ARobjT("turnos.dat");

    // Especialidad objE;
    // ArchivoEspecialidades ARobjE("especialidades.dat");

    // int tam1= ARobjT.contarRegistros();
    // int tam2= ARobjE.contarRegistros();


    // for(int i=0;i<tam1;i++){
    //     objT = ARobjT.leerRegistro(i);
    //     if(objT.getEstado()==true){
    //         objT.mostrarLinea();
    //     }
    // }
    // cout<<"////////////////////////////"<<endl;
    // for(int i=0;i<tam2;i++){
    //     objE = ARobjE.leerRegistro(i);
    //     if(objE.getEstado()==true){
    //         objE.Mostrar();
    //     }
    // }

    return 0;
}