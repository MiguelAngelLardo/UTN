


// #include<iostream>
// #include<cstring>

// #include"Multa.h"
// #include"MultaArchivo.h"
// #include"MultaManager.h"

// #include"Agente.h"
// #include"AgenteArchivo.h"
// #include"Fecha.h"

// using namespace std;


// class CopiaMulta{

//     private:
//     char _patente[10];
//     int _idMulta;
//     Fecha _fechaMulta;
//     float _monto;
//     int _idAgente;
//     int _tipoInfraccion;
//     int _idLocalidad;
//     bool _pagada;
//     bool _eliminado;
//     public:

//     //setters y getters

//     //metodos
//     void mostrar(){
//         cout<<"Patente: "<<_patente<<endl;
//         cout<<"ID Multa: "<<_idMulta<<endl;
//         cout<<"Fecha Multa: "; cout<<_fechaMulta.getDia()<<"/"<<_fechaMulta.getMes()<<"/"<<_fechaMulta.getAnio()<<endl;
//         cout<<"Monto: "<<_monto<<endl;
//         cout<<"ID Agente: "<<_idAgente<<endl;
//         cout<<"Tipo Infraccion: "<<_tipoInfraccion<<endl;
//         cout<<"ID Localidad: "<<_idLocalidad<<endl;
//         cout<<"Pagada: "<<_pagada<<endl;
//     }

//     void mostrarLineal(){
//         cout<<_patente<<";"<<_idMulta<<";"<<_fechaMulta.getDia()<<"/"<<_fechaMulta.getMes()<<"/"<<_fechaMulta.getAnio()<<";"<<_monto<<";"<<_idAgente<<";"<<_tipoInfraccion<<";"<<_idLocalidad<<";"<<_pagada<<";"<<_eliminado<<endl;
//     }

//     void setear(const char* patente, int idMulta, Fecha fechaMulta, float monto, int idAgente, int tipoInfraccion, int idLocalidad, bool pagada, bool eliminado){
//         strcpy(_patente, patente);
//         _idMulta=idMulta;
//         _fechaMulta=fechaMulta;
//         _monto=monto;
//         _idAgente=idAgente;
//         _tipoInfraccion=tipoInfraccion;
//         _idLocalidad=idLocalidad;
//         _pagada=pagada;
//     }

//     void cargar(){}

//     //constructor
//     CopiaMulta(){}

//     //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
//    // ~CopiaMulta(){}

// };

// class ArchivoCopiaMulta{

//     private:
//         char nombre[30];
//     public:
//         //constructor
//         ArchivoCopiaMulta(const char* nombre="CopiaMulta.dat"){
//             strcpy(this->nombre, nombre);
//         }

// //metodos

// void GuardarArchivo(CopiaMulta& obj){
//    FILE *p;
//    p = fopen(nombre,"ab");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    fwrite(&obj,sizeof(CopiaMulta),1,p);
//    fclose(p);
// }

// int contarRegistros(){
//         FILE *p;
//         p=fopen(nombre, "rb");
//         if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
//         fseek(p, 0,2);
//         int tam=ftell(p);
//         fclose(p);
//         return tam/sizeof(CopiaMulta);
//     }

// CopiaMulta leerRegistro(int pos){
//         CopiaMulta reg;
//         FILE *p;
//         p=fopen(nombre, "rb");
//         if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
//         fseek(p, sizeof reg*pos,0);
//         fread(&reg, sizeof reg,1, p);
//         fclose(p);
//         return reg;
//     }

// bool reemplazarRegistro(CopiaMulta& reg, int posicionAReemplazar){
//     FILE *p = fopen(nombre, "rb+");
//     if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
//     fseek(p, posicionAReemplazar * sizeof(CopiaMulta), SEEK_SET);
//     bool pudoEscribir = fwrite(&reg, sizeof(CopiaMulta), 1, p);
//     fclose(p);
//     return pudoEscribir;
// }

// void cargarArchivo(int tam=1){
//     CopiaMulta objE;
//     FILE *p;
//     p = fopen(nombre,"ab");
//     if(p==NULL){
//         cout << "No se pudo abrir el archivo crearArchivo" << endl;
//         //cout<<"En la Linea: "<<__LINE__<<endl;
//         exit(1);
//     }

//     for(int i=0; i<tam; i++){
//     objE.cargar();
//     cout<<endl;
//     fwrite(&objE, sizeof(CopiaMulta), 1, p);
//     }

//     fclose(p);
// }

// void crearArchivo(int tam=1){
//     CopiaMulta objE;
//     FILE *p;
//     p = fopen(nombre,"wb");
//     if(p==NULL){
//         cout << "No se pudo abrir el archivo crearArchivo" << endl;
//         //cout<<"En la Linea: "<<__LINE__<<endl;
//         exit(1);
//     }

//     for(int i=0; i<tam; i++){
//     objE.cargar();
//     cout<<endl;
//     fwrite(&objE, sizeof(CopiaMulta), 1, p);
//     }

//     fclose(p);
// }

// void mostrarArchivo(){
//     CopiaMulta objE;
//     FILE *p;
//     p = fopen(nombre,"rb");
//     if(p==NULL){
//         cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
//         //cout<<"En la Linea: "<<__LINE__<<endl;
//         exit(1);
//     }
// while (fread(&objE, sizeof(CopiaMulta), 1, p) == true){
//     objE.mostrar();
//     cout << endl;
// }
//     fclose(p);
// }

// void BorrarArchivo(){
//    FILE *p;
//    p = fopen(nombre,"wb");
//    if(p == NULL){
//       cout<<"No se pudo borrar el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    fclose(p);
// }



// };


// class CopiaAgente{

//     private:
//     int _idAgente;
//     char _apellidos[50];
//     char _nombres[50];
//     int _anioIngreso;
//     int _categoria;
//     float _sueldo;
//     public:
//     //setters y getters

//     void setearTodo(int idAgente,const char* apellidos,const char* nombres,int anioIngreso,int categoria,float sueldo){
//         _idAgente=idAgente;
//         strcpy(_apellidos,apellidos);
//         strcpy(_nombres,nombres);
//         _anioIngreso=anioIngreso;
//         _categoria=categoria;
//         _sueldo=sueldo;
//     }



//     //metodos
//     void mostrar(){
//         cout<<"Id Agente: "<<_idAgente<<endl;
//         cout<<"Apellidos: "<<_apellidos<<endl;
//         cout<<"Nombres: "<<_nombres<<endl;
//         cout<<"Anio Ingreso: "<<_anioIngreso<<endl;
//         cout<<"Categoria: "<<_categoria<<endl;
//         cout<<"Sueldo: "<<_sueldo<<endl;
//     }
//     void mostrarLineal(){
//         cout<<_idAgente<<";"<<_apellidos<<";"<<_nombres<<";"<<_anioIngreso<<";"<<_categoria<<";"<<_sueldo<<endl;}

//     void cargar(){

//     }

//     //constructor
//     CopiaAgente(){}

//     //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
//    // ~CopiaAgente(){}

// };


// int main(){

//     Multa objM;
//     MultaArchivo ARobjM("multas.dat");

//    // CopiaMulta CobjM;

//     int tam1=ARobjM.getCantidadRegistros();

//     // for(int i=0; i<tam1; i++){
//     //     objM = ARobjM.leer(i);

//     //     CobjM.setear(objM.getPatente().c_str(),objM.getIDMulta(),objM.getFechaMulta(),objM.getMonto(),objM.getIDAgente(),objM.getTipoInfraccion(),objM.getIDLocalidad(),objM.getPagada(),objM.getEliminado());
//     //     CobjM.mostrarLineal();
//     // }

//     cout<<"//////////////////////"<<endl;

//     Agente objA;
//     AgenteArchivo ARobjA("agentes.dat");

//     CopiaAgente CobjA;
//     int tam2=ARobjA.getCantidadRegistros();

//     for(int i=0; i<tam2; i++){
//         objA = ARobjA.leer(i);

//         CobjA.setearTodo(objA.getIdAgente(),objA.getApellidos().c_str(),objA.getNombres().c_str(),objA.getAnioIngreso(),objA.getCategoria(),objA.getSueldo());
//         CobjA.mostrarLineal();
//     }

//     return 0;
// }