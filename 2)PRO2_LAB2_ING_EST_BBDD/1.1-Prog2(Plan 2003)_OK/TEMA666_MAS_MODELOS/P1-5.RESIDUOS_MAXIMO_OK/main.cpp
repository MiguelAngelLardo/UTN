#include<iostream>
#include<cstring>

using namespace std;

#include"recoleccion.h"

void PuntoA(){
    Residuo objR;
    ArchivoResiduos ARobjR("residuos.dat");

    int tam=ARobjR.contarRegistros();

    int vecAcum[20]={0};

    for(int i=0;i<tam;i++){
        objR = ARobjR.leerRegistro(i);

        if(objR.getFecha().getAnio()==2011){
            vecAcum[objR.getCodigoZona()-1]+= objR.getCantidadKilos();
        }
    }

    int max=0;
    int pos=0;

    for(int i=0;i<20;i++){
        if(i==0){
            max=vecAcum[i];
            pos=0;
        }else if(vecAcum[i]>max){
            max=vecAcum[i];
            pos=i;
        }
    }

    cout<<"La zona con mayor cantidad de residuos de 2011 es: "<<pos+1<<endl;
    cout<<"La cantidad de residuos es: "<<max<<endl;

}

void PuntoB(){
    Camion objC;
    ArchivoCamiones ARobjC("camiones.dat");

    Residuo objR;
    ArchivoResiduos ARobjR("residuos.dat");

    int tam1 = ARobjC.contarRegistros();
    int tam2 = ARobjR.contarRegistros();

    int mContador[20][12]={0};

    for(int i=0;i<tam1;i++){
        objC = ARobjC.leerRegistro(i);

        for(int j=0;j<tam2;j++){
            objR = ARobjR.leerRegistro(j);
            if((strcmp(objC.getCodigoCamion(),objR.getCodigoCamion())==0)&&(objR.getFecha().getAnio()==2011)){
                mContador[objR.getCodigoZona()-1][objR.getFecha().getMes()-1]++;
            }
        }
    }


    for(int i=0;i<20;i++){
        cout<<"Codigo Zona: "<<i+1<<endl;
        for(int j=0;j<12;j++){
            cout<<"El Mes: "<<j+1<<" Cantidad: "<<mContador[i][j]<<endl;
        }
        cout<<endl;
    }
}

class ARpuntoC{

    private:
        int CodigoDeCentroDeRecepcion;
        char NombreDeCentroDeRecepcion[20];
        char localidad[20];
        int CantidadDeViajesEnCadaCentro;
        bool estado=true;
    public:
        //setters

        void setCodigoDeCentroDeRecepcion(int CodigoDeCentroDeRecepcion){this->CodigoDeCentroDeRecepcion = CodigoDeCentroDeRecepcion;}
        void setNombreDeCentroDeRecepcion(const char* NombreDeCentroDeRecepcion){strcpy(this->NombreDeCentroDeRecepcion,NombreDeCentroDeRecepcion);}
        void setLocalidad(const char* localidad){strcpy(this->localidad,localidad);}
        void setCantidadDeViajesEnCadaCentro(int CantidadDeViajesEnCadaCentro){this->CantidadDeViajesEnCadaCentro = CantidadDeViajesEnCadaCentro;}
        void setEstado(bool estado){this->estado = estado;}


        int getCodigoDeCentroDeRecepcion(){return CodigoDeCentroDeRecepcion;}
        const char* getNombreDeCentroDeRecepcion(){return NombreDeCentroDeRecepcion;}
        const char* getLocalidad(){return localidad;}
        int getCantidadDeViajesEnCadaCentro(){return CantidadDeViajesEnCadaCentro;}
        bool& getEstado(){return estado;}


        void setearTodo(int CodigoDeCentroDeRecepcion,const char* NombreDeCentroDeRecepcion,const char* localidad,int CantidadDeViajesEnCadaCentro){
            setCodigoDeCentroDeRecepcion(CodigoDeCentroDeRecepcion);
            setNombreDeCentroDeRecepcion(NombreDeCentroDeRecepcion);
            setLocalidad(localidad);
            setCantidadDeViajesEnCadaCentro(CantidadDeViajesEnCadaCentro);
            estado=true;
        }

        void mostrar(){
            cout<<"Codigo de centro de recepcion: "<<CodigoDeCentroDeRecepcion<<endl;
            cout<<"Nombre de centro de recepcion: "<<NombreDeCentroDeRecepcion<<endl;
            cout<<"Localidad: "<<localidad<<endl;
            cout<<"Cantidad de viajes en cada centro: "<<CantidadDeViajesEnCadaCentro<<endl;
        }

void BorrarArchivo(){
   FILE *p;
   p = fopen("ARpuntoC.dat","wb");
   if(p == NULL){
      cout<<"No se pudo borrar el archivo";
      cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fclose(p);
}

void mostrarArchivo(){
    ARpuntoC objE;
    FILE *p;
    p = fopen("ARpuntoC.dat","rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

while (fread(&objE, sizeof(ARpuntoC), 1, p) == true){
    objE.mostrar();
    cout << endl;
}

    fclose(p);
}

void GuardarArchivo(ARpuntoC& obj){
   FILE *p;
   p = fopen("ARpuntoC.dat","ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(ARpuntoC),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen("ARpuntoC.dat", "rb");
        if(p==NULL){cout<<"Error en Linea: "<<__LINE__<<endl;  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(ARpuntoC);
    }

ARpuntoC leerRegistro(int pos){
        ARpuntoC reg;
        FILE *p;
        p=fopen("ARpuntoC.dat", "rb");
        if(p==NULL){cout<<"Error en Linea: "<<__LINE__<<endl;  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(ARpuntoC& reg, int posicionAReemplazar){
    FILE *p = fopen("ARpuntoC.dat", "rb+");
    if (p == NULL){cout<<"Error en Linea: "<<__LINE__<<endl;  return false;}
    fseek(p, posicionAReemplazar * sizeof(ARpuntoC), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(ARpuntoC), 1, p);
    fclose(p);
    return pudoEscribir;
}


};

void puntoC(){
    Residuo objR;
    ArchivoResiduos ARobjR("residuos.dat");

    Centro objC;
    ArchivoCentro ARobjC("centros.dat");

    ARpuntoC objP;
    objP.BorrarArchivo();
    

    int tam1 = ARobjC.contarRegistros();
    int tam2 = ARobjR.contarRegistros();

    int cantidad=0;

    for(int i=0;i<tam1;i++){
        objC = ARobjC.leerRegistro(i);

        for(int j=0;j<tam2;j++){
            objR = ARobjR.leerRegistro(j);

            if((objC.getCodigoCentro()==objR.getCodigoCentroRecepcion()) && (objR.getFecha().getAnio()==2011)){
                cantidad++;
            }
            

        }
        //guardar
        objP.setearTodo(objC.getCodigoCentro(),objC.getNombre(),objC.getLocalidad(),cantidad);
        objP.GuardarArchivo(objP);
        cantidad=0;
    }

    objP.mostrarArchivo();



}

int Maximo(int tam){
    int max=0;
    ARpuntoC objC;
    int band=true;
    
        for(int i=0;i<tam;i++){
        objC = objC.leerRegistro(i);

        if((band==true)&& (objC.getEstado()==true)){
            max = objC.getCantidadDeViajesEnCadaCentro();
            band = false;
        }else if((objC.getCantidadDeViajesEnCadaCentro()>max)&& (objC.getEstado()==true)){
            max = objC.getCantidadDeViajesEnCadaCentro();
        }
    }

    return max;
}

void PuntoD(){
    ARpuntoC objC;
    int tam = objC.contarRegistros();

    for(int i=0;i<tam;i++){
        objC = objC.leerRegistro(i);

        if(objC.getEstado()==false){
            objC.setEstado(true);
            objC.reemplazarRegistro(objC,i);
        }
    }


    int max = Maximo(tam);
    cout<<"max: "<<max<<endl;
    /////////////////////////////////////////////
    int band=true;

    for(int x=0;x<tam;x++){

        for(int j=0;j<tam;j++){
            objC = objC.leerRegistro(j);

            if((objC.getCantidadDeViajesEnCadaCentro()==max) && (max!=-1)){
                objC.mostrar();
                cout<<endl;

                objC.setEstado(false);
                objC.reemplazarRegistro(objC,j);
                max = -1;
            }

            if((objC.getEstado()==true) && (max==-1)){
                max = Maximo(tam);
            }
        }
        
    }


    /////////////////////////////////////////////


    // for(int i=0;i<tam;i++){
    //     objC = objC.leerRegistro(i);

    //     for(int j=0;j<tam;j++){
    //         objC = objC.leerRegistro(j);

    //         if(((objC.getCantidadDeViajesEnCadaCentro()<=max)) && (objC.getCantidadDeViajesEnCadaCentro()>segmax)){
    //             // segmax = objC.getCantidadDeViajesEnCadaCentro();
    //             // indice = j;
    //             objC.mostrar();
    //         }
    //     }
    //     //cout<<"Cantidad de viajes: "<<max<<endl;
    //     max = segmax;
    // }
    // /////////////////////////////////////////////

}

int main(){


    //PuntoA();
    //PuntoB();
    //puntoC();
    PuntoD();

/**********************************************************/
    ArchivoCamiones ARobjC("camiones.dat");
    Camion objC;

    //ARobjC.crearArchivo(10);

    int tam1 = ARobjC.contarRegistros();

    // for(int i=0;i<tam1;i++){
    //     objC = ARobjC.leerRegistro(i);
    //     objC.Mostrar();
    //     cout<<endl;
    // }
/**********************************************************/
    ArchivoResiduos ARobjR("residuos.dat");
    Residuo objR;

    //ARobjR.crearArchivo(10);

    int tam2 = ARobjR.contarRegistros();

    // for(int i=0;i<tam2;i++){
    //     objR = ARobjR.leerRegistro(i);
    //     objR.Mostrar();
    //     cout<<endl;
    // }
/**********************************************************/
    ArchivoCentro ARobjCen("centros.dat");
    Centro objCen;

    //ARobjCen.crearArchivo(10);

    int tam3 = ARobjCen.contarRegistros();

    // for(int i=0;i<tam3;i++){
    //     objCen = ARobjCen.leerRegistro(i);
    //     objCen.Mostrar();
    //     cout<<endl;        
    // }
/**********************************************************/

    return 0;
}