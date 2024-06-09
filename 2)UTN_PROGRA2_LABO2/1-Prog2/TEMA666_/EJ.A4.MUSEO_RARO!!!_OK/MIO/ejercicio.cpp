/*
El ministerio de cultura provincial dispone de un sistema donde gestiona la información de los 
museos. Tiene los siguientes archivos: 
Personal: 
Dni 
Nombre 
Apellido 
Cargo (1-4) 
Número 
Localidad 
E mail 
Teléfono  
 
Museo 
Número 
Especialidad (1-8) 
Año 
Nombre 
Dni del Director  
 
Contratos 
Dni del empleado 
Número de museo 
Tipo de contrato (1-3) 
Fecha de contrato 
 
1. Generar un archivo con los jefes del Área que hayan firmado contrato en el 2020, con el siguiente 
formato : 
Dni, nombre y apellido 
 
2.listar el mes con más contratos temporarios del año 2015 
 
 
Personal cargo: 
1. Empleado 
2. Recepcionista 
3. Jefe de área 
4. Administrador 
 
Contratos tipo de contrato: 
1. Temporal 
2. Anual 
3. Bimestral
*/

#include<iostream>
#include<cstring>

using namespace std;

#include"Clases.h"

class Punto1{

    private:
        char dni[10];
        char nombre[10];
        char apellido[10];
    public:
        //setters y getters
        void setDni(const char* _dni){strcpy(dni,_dni);}
        void setNombre(const char* nom){strcpy(nombre,nom);}
        void setApellido(const char* ape){strcpy(apellido,ape);}
        
        void setearTodo(const char* _dni,const  char* _nom,const  char* _ape){
            setDni(_dni);
            setNombre(_nom);
            setApellido(_ape);
        }

        const char* getDNI(){return dni;}
        const char* getNombre(){return nombre;}
        const char* getApellido(){return apellido;}

        void mostrar(){
            cout<<"DNI: "<<dni<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Apellido: "<<apellido<<endl;
        }

        void Cargar(){
            cout << "ingrese DNI: "<<endl;
            cargarCadena(dni,9);
            cout << "nombre: "<<endl;
            cargarCadena(nombre,9);
            cout << "apellido" <<endl;
            cargarCadena(apellido,9);
        }

void GuardarArchivo(Punto1& obj){
   FILE *p;
   p = fopen("Punto1.dat","ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Punto1),1,p);
   fclose(p);
}

void mostrarArchivo(){
    Punto1 objE;
    FILE *p;
    p = fopen("Punto1.dat","rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Punto1), 1, p) == true){
    objE.mostrar();
    cout << endl;
}fclose(p);
}

void BorrarArchivo(){
   FILE *p;
   p = fopen("Punto1.dat","wb");
   if(p == NULL){
      cout<<"No se pudo borrar el archivo";
      cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fclose(p);
}

};

void PrimerPunto(){
    Personal objP;
    ArchivoPersonal ARobjP("Personal.dat");

    Contrato objC;
    ArchivoContrato ARobjC("Contrato.dat");

    Punto1 objP1;

    objP1.BorrarArchivo();

    int tam1 = ARobjP.contarRegistros();
    int tam2 = ARobjC.contarRegistros();

    for(int i=0; i<tam1; i++){
        objP = ARobjP.leerRegistro(i);

        if(objP.getCargo() == 3){
            
            for(int j=0; j<tam2; j++){
            objC = ARobjC.leerRegistro(j);
                if(strcmp(objP.getDNI(),objC.getDniEmpledo())==0){
                        if(objC.getFecha()==2020){
                            objP1.setearTodo(objP.getDNI(), objP.getNombre(), objP.getApellido());
                            objP1.GuardarArchivo(objP1);
                        }
                }
            }
        }

    }
    objP1.mostrarArchivo();
}

int main(){

    Personal objP;
    ArchivoPersonal ARobjP("Personal.dat");

    Contrato objC;
    ArchivoContrato ARobjC("Contrato.dat");

    Museo objM;
    ArchivoMuseo ARobjM("Museo.dat");

    int tam1 = ARobjP.contarRegistros();
    int tam2 = ARobjC.contarRegistros();
    int tam3 = ARobjM.contarRegistros();

    for(int i=0; i<tam1; i++){
        objP = ARobjP.leerRegistro(i);

        objP.Mostrar();
        cout<<endl;
    }
    cout<<"////////////////////////////////"<<endl;
    for(int j=0; j<tam2; j++){
        objC = ARobjC.leerRegistro(j);

        objC.Mostrar();
        cout<<endl;
    }
    cout<<"////////////////////////////////"<<endl;
    for(int k=0; k<tam3; k++){
        objM = ARobjM.leerRegistro(k);

        objM.Mostrar();
        cout<<endl;
    }

    return 0;
}