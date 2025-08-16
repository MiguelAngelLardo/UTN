#include<iostream>
#include<cstring>

using namespace std;

#include"ModeloParcial.h"

void cargarCadena(char *pal, int tam){
    int i;
    tam = tam-1; //<--- esto es opcional
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

void mostrarArchivos(){
        Billete objB;
    ArchivoBillete ARobjB("billete.dat");
    
    Sorteo objS;
    ArchivoSorteo ARobjS("sorteo.dat");

    int tam1 = ARobjB.contarRegistros();
    int tam2 = ARobjS.contarRegistros();

    for(int i=0; i<tam1; i++){
        objB = ARobjB.leerRegistro(i);
        objB.MostrarLineal();
        cout<<endl;
    }

    cout<<"///////////////////////"<<endl;

    for(int i=0; i<tam2; i++){
        objS = ARobjS.leerRegistro(i);
        objS.MostrarLineal();
        cout<<endl;
    }
}

void CargarSoloMatriz(int mat[][24], int filas, int columnas, int valor=0){
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            mat[i][j]=valor;
        }
    }
}


class PuntoA{

private:
    int _codSorteo;
    int _numGanador;
    int _mes;
    int _codProvinciaVenta;

public:

    PuntoA(int codSorteo = 0, int numGanador = 0, int mes = 0, int codProvinciaVenta = 0)
        : _codSorteo(codSorteo), _numGanador(numGanador), _mes(mes), _codProvinciaVenta(codProvinciaVenta) {} 
    
    void setCodSorteo(int codSorteo){_codSorteo = codSorteo;}

    void setNumGanador(int numGanador){_numGanador = numGanador;}

    void setMes(int mes){_mes = mes;}

    void setCodProvinciaVenta(int codProvinciaVenta){_codProvinciaVenta = codProvinciaVenta;}

    void setearTodos(int codSorteo, int numGanador, int mes, int codProvinciaVenta){
        _codSorteo = codSorteo;
        _numGanador = numGanador;
        _mes = mes;
        _codProvinciaVenta = codProvinciaVenta;
    }

    int getCodSorteo(){
        return _codSorteo;
    }

    int getNumGanador(){
        return _numGanador;
    }

    int getMes(){
        return _mes;
    }

    int getCodProvinciaVenta(){
        return _codProvinciaVenta;
    }

     void cargar(){
        cout << "codSorteo: "; cin >> _codSorteo;
        cout << "numGanador: "; cin >> _numGanador;
        cout << "mes: "; cin >> _mes;
        cout << "codProvinciaVenta: "; cin >> _codProvinciaVenta;
     }


    void mostrar(){
        cout << "CODIGO DEL SORTEO: " << _codSorteo << endl;
        cout << "NUMERO DE GANADOR: " << _numGanador << endl;
        cout << "MES SORTEO: " << _mes << endl;
        cout << "CODIGO DE PROVINCIA DE VENTA: " << _codProvinciaVenta << endl;
    }
};

class ArchivoPuntoA{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoPuntoA(const char* nombre="PuntoA.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(PuntoA& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(PuntoA),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(PuntoA);
    }

PuntoA leerRegistro(int pos){
        PuntoA reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(PuntoA& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(PuntoA), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(PuntoA), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    PuntoA objE;
    FILE *p;
    p = fopen(nombre,"ab");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.cargar();
    cout<<endl;
    fwrite(&objE, sizeof(PuntoA), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    PuntoA objE;
    FILE *p;
    p = fopen(nombre,"wb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.cargar();
    cout<<endl;
    fwrite(&objE, sizeof(PuntoA), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    PuntoA objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(PuntoA), 1, p) == true){
    objE.mostrar();
    cout << endl;
}
    fclose(p);
}

void BorrarArchivo(){
   FILE *p;
   p = fopen(nombre,"wb");
   if(p == NULL){
      cout<<"No se pudo borrar el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fclose(p);
}

// bool ExisteDNI(int dni){
//    PuntoA obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(PuntoA),1,p)){
//       if(obj.getDNI()==dni){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }

void SetAbrirArchivoConRB(const char* nombre,FILE** p){
    *p=fopen(nombre, "rb");
    if(*p==NULL){
        cout << "ERROR : AbrirArchivoConRB()" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        system("pause");
    }
}

void SetAbrirArchivoConRBMAS(const char* nombre,FILE** p){
    *p=fopen(nombre, "rb+");
    if(*p==NULL){
        cout << "ERROR : AbrirArchivoConRB()" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        system("pause");
    }
}

void SetAbrirArchivoConWB(const char* nombre,FILE **p){
    *p=fopen(nombre, "wb");
    if(*p==NULL){
        cout << "ERROR : AbrirArchivoConWB()" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        system("pause");
    }
}

};



void puntoA(){
    Sorteo objS; //codsorteo(PK) - numGanador(fk) - mes - 
    ArchivoSorteo ARobjS("sorteo.dat");

    Billete objB; // numGanador(PK) - codigoProvincia
    ArchivoBillete ARobjB("billete.dat");

    PuntoA objPtoA; //TAREA
    ArchivoPuntoA ARobjPtoA;
    ARobjPtoA.BorrarArchivo();

    int tam1 = ARobjS.contarRegistros();
    int tam2 = ARobjB.contarRegistros();

    for(int i=0; i<tam1; i++){
        objS = ARobjS.leerRegistro(i);
        //la clase no tiene el atributo getEstado;
        for(int j=0; j<tam2; j++){
            objB = ARobjB.leerRegistro(j);
             //la clase no tiene el atributo getEstado;

                    //89                          89                         69                         9     
            if((objS.getCodigoSorteo() == objB.getCodigoSorteo()) && (objB.getNumero() == objS.getNumGanador())){
                objPtoA.setearTodos(objS.getCodigoSorteo(), objB.getNumero(), objS.getMesSorteo(), objB.getCodProvincia());
                ARobjPtoA.GuardarArchivo(objPtoA);
            }
        }    
    }    

    cout << endl << endl;
    ARobjPtoA.mostrarArchivo();


}

//por cada mes la cantidad de billetes vendidos en cada provincia

void puntoB(){
    
    Billete objB;
    ArchivoBillete ARobjB("billete.dat");

    int tam=ARobjB.contarRegistros();
    
    int vAcum[12][24];
    CargarSoloMatriz(vAcum, 12, 24);
    
    for(int i=0; i<tam; i++){
        objB = ARobjB.leerRegistro(i);

        vAcum[objB.getMes()-1][objB.getCodProvincia()-1]++;
    }    

    cout << "MOSTRAMOS la cantidad de billetes vendidos por mes y por provincia" << endl;
    system("pause");

    for(int i = 0; i < 12; i++){
        bool flagMostrador = true;
        bool flagProvinciaConDato = false;

        for(int j = 0; j < 24; j++){
            if(vAcum[i][j] != 0){
                if(flagMostrador){
                    cout << "PROVINCIA: " << i+1 << endl;
                    flagMostrador = false;
                }   
                cout << "\tMES " << j+1 << "- > CANTIDAD: " << vAcum[i][j] << endl;
                flagProvinciaConDato = true;
            }    
        }        
        if(flagProvinciaConDato){ 
            cout << endl;
        }
    }    
}

//calcular e informar la ganancia / perdida obtenida por la loteria pro cada sorteo => precios de los billetes-importe premio

void puntoC(){
    Sorteo objS; //codsorteo(PK) - numGanador(fk) - importe premio (PERDIDA)
    ArchivoSorteo ARobjS("sorteo.dat");

    Billete objB; // numGanador(PK) - precio billete (GANANCIA)
    ArchivoBillete ARobjB("billete.dat");

    int tam1 = ARobjS.contarRegistros();
    int tam2 = ARobjB.contarRegistros();

    float acumVentasBilletes = 0.0; //ganancia
    float acumPremiosOtorgados = 0.0; //perdida

    for(int i=0; i<tam1; i++){
        objS = ARobjS.leerRegistro(i);
        
        for(int j=0; j<tam2; j++){
            objB = ARobjB.leerRegistro(j);
            if(objS.getCodigoSorteo() == objB.getCodigoSorteo()){
                acumVentasBilletes += objB.getPrecio();
            }
        }
    } 


    for(int i=0; i<tam2; i++){
        objB = ARobjB.leerRegistro(i);

        for(int j=0; j<tam1; j++){
            objS = ARobjS.leerRegistro(j);
            if(objB.getNumero() == objS.getNumGanador()){
                acumPremiosOtorgados += objS.getImporte();
            }
        } 
    }    

    cout << "Ganancia RECIBIDA: $" << acumVentasBilletes << endl;
    cout << "Premios OTORGADOS: $" << acumPremiosOtorgados << endl;
    system("pause");

    if(acumVentasBilletes > acumPremiosOtorgados){
        cout << "GANANCIA: $" << acumVentasBilletes - acumPremiosOtorgados << endl;
    }else if(acumVentasBilletes < acumPremiosOtorgados){
        cout << "PERDIDA: $" << acumPremiosOtorgados - acumVentasBilletes << endl;
    }else{
        cout << "La ganancia y la perdida son iguales" << endl;
    }    

}



int main(){ 
    
    //puntoA();
    //puntoB();
    //puntoC();
    

    return 0;
}