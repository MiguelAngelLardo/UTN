#include<iostream>
#include<cstring>

using namespace std;

#include"clases.h"

    /*
    1)
    - A partir de un número de municipio que se ingresa por teclado, generar un archivo con las empresas que pertenezcan e ese municipio.
    Los registros del archivo nuevo deben tener el siguiente formato:
    - Número empresa, nombre de la empresa y cantidad de empleados.

    2)
    A partir de un número de sección que se ingresa por teclado, generar un archivo nuevo con aquellas empresas que pertenezcan a municipios de esa sección. 

    Los registros del archivo nuevo deben tene el mismo formato que el archivo del punto anterior.

    NOTA: las clases para trabajar con los archivos de empresas y municipios se encuentran en el archivo clases.h que se adjunta.

    Crear la/s clase/s necesarias para resolver los puntos
    */

class Punto{

    private:
        int NumeroDeEmpresa;
        char NombreDeEmpresas[20];
        int CantidadDeEmpleados;
    public:
        //setters y getters
        void setNumeroDeEmpresa(int n){NumeroDeEmpresa = n;}
        void setNombreDeEmpresas(const char* n){strcpy(NombreDeEmpresas, n);}
        void setCantEmpleados(int n){CantidadDeEmpleados = n;}

        void setearTodo(int n, const char* n2, int n3){
            setNumeroDeEmpresa(n);
            setNombreDeEmpresas(n2);
            setCantEmpleados(n3);
        }

        int getNumeroDeEmpresa(){return NumeroDeEmpresa;}
        const char* getNombreDeEmpresas(){return NombreDeEmpresas;}
        int getCantEmpleados(){return CantidadDeEmpleados;}


        //constructor
        Punto(){}
        //destructor
        ~Punto(){}

        //metodos

        void mostrar(){
            cout<<"NUMERO DE EMPRESA: "<<NumeroDeEmpresa<<endl;
            cout<<"NOMBRE DE EMPRESA: "<<NombreDeEmpresas<<endl;
            cout<<"CANTIDAD DE EMPLEADOS: "<<CantidadDeEmpleados<<endl;
        }

        void cargar(){
            cout<<"NUMERO DE EMPRESA: "; cin>>NumeroDeEmpresa;
            cout<<"NOMBRE DE EMPRESA: "; cargarCadena(NombreDeEmpresas, 19);
            cout<<"CANTIDAD DE EMPLEADOS: "; cin>>CantidadDeEmpleados;
        }

};

class ArchivoPunto1{

public:
void GuardarArchivo(Punto& obj){
   FILE *p;
   p = fopen("puntoA.dat","ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Punto),1,p);
   fclose(p);
}

void BorrarArchivo(){
   FILE *p;
   p = fopen("puntoA.dat","wb");
   if(p == NULL){
      cout<<"No se pudo borrar el archivo";
      cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fclose(p);
}

void mostrarArchivo(){
    Punto objE;
    FILE *p;
    p = fopen("puntoA.dat","rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

while (fread(&objE, sizeof(Punto), 1, p) == true){
    objE.mostrar();
    cout << endl;
}

    fclose(p);
}

};

void PuntoA(){
    Empresa obj;
    ArchivoEmpresas obj2;
    ArchivoPunto1 obj3;
    Punto obj4;
    obj3.BorrarArchivo();

    // int tam = obj2.contarRegistros();


    // for(int i=0; i<tam; i++){
    //     obj = obj2.leerRegistro(i);

    //     if(obj.getEstado()==true){
    //     obj4.setearTodo(obj.getNumero(), obj.getNombre(), obj.getCantidadEmpleados());
    //     obj3.GuardarArchivo(obj4);
    //     }

    // }

    FILE *p;
    p = fopen("empresas.dat","rb");
    if(p == NULL){
        cout<<"No se pudo abrir el archivo";
        cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

    while(fread(&obj, sizeof(Empresa), 1, p) == true){
        if(obj.getEstado()==true){
            obj4.setearTodo(obj.getNumero(), obj.getNombre(), obj.getCantidadEmpleados());
            obj3.GuardarArchivo(obj4);
        }
    }

    fclose(p);
    obj3.mostrarArchivo();
}

void PuntoB(){
    Punto objP;
    ArchivoPunto1 obj1;
    obj1.BorrarArchivo();
    
    Empresa obj2;
    ArchivoEmpresas obj3;
    
    Municipio obj4;
    ArchivoMunicipios obj5;

    int tam1 = obj5.contarRegistros();
    int tam2 = obj3.contarRegistros();

    int Seccion=0;

    cout<<"ingrese la seccion: "; cin>>Seccion;

    for(int i=0; i<tam1; i++){  //municipios
        obj4 = obj5.leerRegistro(i);
        if((obj4.getEstado()) && (obj4.getSeccion()==Seccion)){

            for(int j=0; j<tam2; j++){  //empresa
                obj2 = obj3.leerRegistro(j);
                if((obj2.getEstado())  && (obj4.getNumero()==obj2.getNumeroMunicipio())){

                    objP.setearTodo(obj2.getNumero(), obj2.getNombre(), obj2.getCantidadEmpleados());
                    obj1.GuardarArchivo(objP);

                }
                }

        }
        }

    obj1.mostrarArchivo();

    
}

void cargarArchivoEmpresa(){
    Empresa obj;
    ArchivoEmpresas obj2;

    for(int i=0; i<7; i++){
        obj.Cargar();
        cout<<endl;
        obj2.grabarRegistro(obj);
    }
}

void cargarArchivoMunicipios(){
    Municipio obj;
    ArchivoMunicipios obj2;

    for(int i=0; i<2; i++){
        obj.Cargar();
        cout<<endl;
        obj2.grabarRegistro(obj);
    }
}

void mostrarArchivo(){
    ArchivoEmpresas obj2;
    obj2.listarRegistros();
    cout<<"/////////////////////////"<<endl;
    ArchivoMunicipios obj3;
    obj3.listarRegistros();
}

int main(){

    //PuntoA();
    PuntoB();
    //cargarArchivoMunicipios();

    //mostrarArchivo();


    return 0;
}