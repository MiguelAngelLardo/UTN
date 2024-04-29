#include <iostream>
#include <cstring>

using namespace std;


void cargarCadena(char *pal, int tam){
    int i;
    fflush (stdin); ///limpia el buffer de entrada para que la carga se haga sin caracteres que hayan quedado sin usar
    for(i=0; i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin); ///vuelve a limpiar el buffer para eliminar los caracteres sobrantes
}



class Empresa{
    private:
        int numero;
        char nombre[30];
        int cantidadEmpleados;
        int categoria;
        int numeroMunicipio;
        bool estado;
    public:
        Empresa(){estado=false;}
        void setNumero(int n){numero = n;}
        void setCategoria(int c){categoria = c;}
        void setEstado(bool e){estado = e;}
        int getNumero(){return numero;}
        int getCantidadEmpleados(){return cantidadEmpleados;}
        bool getEstado(){return estado;}
        int getCategoria(){return categoria;}
        int getMunicipio(){return numeroMunicipio;}
        void Cargar();
        void Mostrar();
};

void Empresa::Cargar(){
    cout<<"NUMERO: ";
    cin>>numero;
    if(numero<1){
        return;
    }
    cout<<"NOMBRE: ";
    cargarCadena(nombre,29);
    cout<<"CANTIDAD DE EMPLEADOS: ";
    cin>>cantidadEmpleados;
    cout<<"CATEGORIA: ";
    cin>>categoria;
    cout<<"NUMERO DE MUNICIPIO: ";
    cin>>numeroMunicipio;
    estado=true;
}

void Empresa::Mostrar(){
    if(estado==true){
        cout<<"NUMERO: "<<numero<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"CANTIDAD DE EMPLEADOS: "<<cantidadEmpleados<<endl;
        cout<<"CATEGORIA: "<<categoria<<endl;
        cout<<"NUMERO DE MUNICIPIO: "<<numeroMunicipio<<endl;
    }
}

class ArchivoEmpresas{
    private:
        char nombre[30];
    public:
        ArchivoEmpresas(const char *n="empresas.dat"){strcpy(nombre,n);}
        void grabarRegistro(Empresa obj);
        Empresa leerRegistro(int pos);
        int buscarRegistro(int num);
        int contarRegistros();
        void modificarRegistro(Empresa obj, int pos);
};



void ArchivoEmpresas::grabarRegistro(Empresa obj){
    FILE *p;
    p=fopen(nombre, "ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fwrite(&obj, sizeof (Empresa), 1, p);
    fclose(p);
}

Empresa ArchivoEmpresas::leerRegistro(int pos){
    Empresa obj;
    obj.setNumero(-1);
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        obj.setNumero(-2);
        return obj;
    }
    fseek(p, pos * sizeof(Empresa), 0);
    fread(&obj, sizeof (Empresa), 1, p);
    fclose(p);
    return obj;
}

int ArchivoEmpresas::buscarRegistro(int num){
    Empresa obj;
    int cant=contarRegistros();
    for(int i=0; i<cant; i++){
        obj = leerRegistro(i);
        if(obj.getNumero()==num){
            return i;
        }
    }
    return -1;
}

int ArchivoEmpresas::contarRegistros(){
    FILE *pEmp;
    pEmp=fopen(nombre,"rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(pEmp, 0, 2);
    int cantBytes = ftell(pEmp);
    fclose(pEmp);
    return cantBytes/sizeof(Empresa);
}

void ArchivoEmpresas::modificarRegistro(Empresa obj, int pos){
    FILE *pEmp;
    pEmp=fopen(nombre, "rb+");///+ le agrega al modo lo que le falta.
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fseek(pEmp, pos * sizeof (Empresa) , 0);
    fwrite(&obj, sizeof (Empresa), 1, pEmp);
    fclose(pEmp);
}

void grabarEmpresa(Empresa obj){
    FILE *pEmp;
    pEmp=fopen("empresas.dat", "ab");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fwrite(&obj, sizeof (Empresa), 1, pEmp);
    fclose(pEmp);
}

void modificarEmpresa(Empresa obj, int pos){
    FILE *pEmp;
    pEmp=fopen("empresas.dat", "rb+");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fseek(pEmp, pos * sizeof (Empresa) , 0);
    fwrite(&obj, sizeof (Empresa), 1, pEmp);
    fclose(pEmp);
}

void altaEmpresa(){
    ArchivoEmpresas arcEmp("empresas.dat");
    Empresa obj;
    obj.Cargar();
    int pos=arcEmp.buscarRegistro(obj.getNumero());
    if(pos != -1){
        cout<<"YA EXISTE UNA EMPRESA CON ESE NUMERO EN EL ARCHIVO"<<endl;
        obj.setEstado(false);
    }
    if(obj.getEstado()==true){
        arcEmp.grabarRegistro(obj);
    }else{
        cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
    }
}



void grabarVectorEmpresas(Empresa *v, int tam){
    FILE *pEmp;
    pEmp=fopen("empresas.dat", "ab");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fwrite(v, sizeof (Empresa), tam, pEmp);
    fclose(pEmp);
}

void cargarEmpresasVector(){
    Empresa vec[5];
    for(int i=0; i<5; i++){
        vec[i].Cargar();
    }
    grabarVectorEmpresas(vec, 5);
}

int contarRegistros(){
    FILE *pEmp;
    pEmp=fopen("empresas.dat","rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(pEmp, 0, 2);
    int cantBytes = ftell(pEmp);
    fclose(pEmp);
    return cantBytes/sizeof(Empresa);
}

/**
Crear una funci�n que reciba un n�mero de empresa, busque en el archivo y devuelva el registro con ese n�mero. En caso de no
haber una empresa con ese n�mero, devolver un objeto con el n�mero seteado en -1.

Crear una funci�n que reciba un n�mero de empresa, busque en el archivo y devuelva la posici�n que ocupa el
registro en el archivo. En caso de no existir el n�mero, devolver -1.

Agregar una funci�n que reciba como par�metro un valor de posici�n y devuelva el registro que ocupa dicha posici�n en el
archivo. En caso de no existir, devuelve un registro con n�mero de empresa en -1. (de 0 en adelante)

*/


Empresa leerEmpresa(int pos){
    Empresa obj;
    obj.setNumero(-1);
    FILE *p;
    p=fopen("empresas.dat", "rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        obj.setNumero(-2);
        return obj;
    }
///    registro 1 - sizeof (Empresa)
///    registro 2 - sizeof (Empresa)
///    registro 3
    fseek(p, pos * sizeof(Empresa), 0);
    ///SEEK_SET (0) nos desplaza desde el inicio del archivo
    ///SEEK_CUR (1) nos desplaza desde la posicion actual
    ///SEEK_END (2) nos desplaza desde el final del archivo
    fread(&obj, sizeof (Empresa), 1, p);
    fclose(p);
    return obj;
}

void listarEmpresas(){
    Empresa obj;
    int cant=contarRegistros();
    for(int i=0; i<cant; i++){
        obj = leerEmpresa(i);
        obj.Mostrar();
        if(obj.getEstado())cout<<endl;
    }
}

void mostrarPorPosicion(){
    int pos;
    cout<<"INGRESE LA POSICION A BUSCAR: ";
    cin>>pos;
    Empresa regEmp;
    regEmp = leerEmpresa(pos);
    if(regEmp.getNumero()>0){
        regEmp.Mostrar();
    }else{
        cout<<"NO EXISTE ESA POSICION EN EL ARCHIVO"<<endl;
    }
}

int buscarPosicionEmpresa(int numeroEmpresa){
    Empresa obj;
    int cant=contarRegistros();
    for(int i=0; i<cant; i++){
        obj = leerEmpresa(i);
        if(obj.getNumero()==numeroEmpresa){
            return i;
        }
    }
    return -1;
}

void buscarPosicion(){
    int num;
    cout<<"INGRESE EL NUMERO DE LA EMPRESA A BUSCAR: ";
    cin>>num;
    int pos;
    pos=buscarPosicionEmpresa(num);
    if(pos >= 0){
        cout<<"LA POSICION DEL REGISTRO EN EL ARCHIVO ES: "<<pos<<endl;
    }else{
        cout<<"NO EXISTE UNA EMPRESA CON ESE NUMERO EN EL ARCHIVO"<<endl;
    }
}


Empresa buscarEmpresa(int num){
    Empresa obj;
    int pos = buscarPosicionEmpresa(num);
    if(pos >= 0){
        obj = leerEmpresa(pos);
    }else{
        obj.setNumero(-1);
    }
    return obj;
}

void buscarRegistro(){
    int num;
    cout<<"INGRESE EL NUMERO DE LA EMPRESA A BUSCAR: ";
    cin>>num;
    Empresa obj;
    obj = buscarEmpresa(num);
    if(obj.getNumero() > 0){
        system("cls");
        obj.Mostrar();
    }else{
        cout<<"NO EXISTE UNA EMPRESA CON ESE NUMERO EN EL ARCHIVO"<<endl;
    }
}

int buscarMaximo(int *vec, int tam){
    int posMax=0;
    for(int i=1; i<tam; i++){
        if(vec[i]>vec[posMax]){
            posMax=i;
        }
    }
    return posMax;
}

int buscarMinimo(int *vec, int tam){
    int posMin=0;
    for(int i=1; i<tam; i++){
        if(vec[i]<vec[posMin]){
            posMin=i;
        }
    }
    return posMin;
}

void modificarRegistro(){
    ArchivoEmpresas arcEmp("empresas.dat");
    int num;
    cout<<"INGRESE EL NUMERO DE EMPRESA A MODIFICAR: ";
    cin>>num;
    int pos=arcEmp.buscarRegistro(num);
    if(pos<0){
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    Empresa obj;
    obj = arcEmp.leerRegistro(pos);
    int cat;
    cout<<"INGRESE LA NUEVA CATEGORIA: ";
    cin>>cat;
    obj.setCategoria(cat);
    arcEmp.modificarRegistro(obj, pos);
}

void bajaLogica(){
    ArchivoEmpresas arcEmp;
    int num;
    cout<<"INGRESE EL NUMERO DE EMPRESA A DAR DE BAJA: ";
    cin>>num;
    int pos=arcEmp.buscarRegistro(num);
    if(pos<0){
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    Empresa obj;
    obj = arcEmp.leerRegistro(pos);
    obj.setEstado(false);
    arcEmp.modificarRegistro(obj, pos);
}
///SUBMENU REPORTES
void empresasCategoria();
void muncipiosSinEmpresas();
    int contarRepetidos(int *v, int tam,int numeroBuscado);/// devuelve la cantidad de veces que se repite numeroBuscado en el vector

void submenuReportes(){
    while(true){
        int opc;
        system("cls");
        cout<<"MENU REPORTES"<<endl;
        cout<<"--------------"<<endl;
        cout<<"1 - EMPRESAS POR CATEGORIA"<<endl;
        cout<<"2 - "<<endl;
        cout<<"3 - MUNICIPIOS SIN EMPRESAS "<<endl;
        cout<<"4 - "<<endl;
        cout<<"5 - "<<endl;
        cout<<"0 - VOLVER AL MENU ANTERIOR "<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                empresasCategoria();
                break;
            case 2:

                break;
            case 3:
                muncipiosSinEmpresas();
                break;
            case 4:

                break;
            case 5:

                break;
            case 0:
                return;
            default:
                cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
                system("pause");
                break;
        }
        system("pause");
    }
    return;
}



///
#include "Funciones.h"

int main(){
    while(true){
        int opc;
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"--------------"<<endl;
        cout<<"1 - ALTA EMPRESA"<<endl;
        cout<<"2 - BAJA LOGICA EMPRESA"<<endl;
        cout<<"3 - MODIFICAR CATEGORIA EMPRESA"<<endl;
        cout<<"4 - LISTAR EMPRESAS"<<endl;
        cout<<"5 - BUSCAR EMPRESA POR NUMERO"<<endl;
        cout<<"6 - SUBMENU REPORTES "<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                altaEmpresa();
                break;
            case 2:
                bajaLogica();
                break;
            case 3:
                modificarRegistro();
                break;
            case 4:
                listarEmpresas();
                break;
            case 5:
                buscarRegistro();
                break;
            case 6: submenuReportes();
                    break;
            case 0:
                return 0;
            default:
                cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
                system("pause");
                break;
        }
        system("pause");
    }
    return 0;
}

/*
A partir del archivo de Empresas de la clase pasada, (hacer un proyecto) agregar al men� una opci�n de nombre REPORTES, que llame a un submen� con las siguientes opciones/puntos a resolver:

1. Listar los registros de las empresas que pertenezcan a una categor�a que se ingresa por teclado

2. Listar los registros de las empresas con m�s de 10 empleados

3. Calcular e informar la cantidad de municipios sin empresas.

4. Listar los municipios con m�s de 5 empresas.

5. Informar la categor�a con m�s empresas.

6. Informar el municipio con m�s empresas

7. Informar para cada municipio la cantidad de empleados de las empresas pertenecientes a ese municipio

8. Informar el municipio con mayor cantidad de empleados en las empresas pertenecientes a ese municipio

9. Informar la cantidad de empleados (entre todas las empresas) de cada categor�a

10. Informar la categor�a con m�s empleados (entre todas las empresas)
*/
///DESARROLLO DE LAS FUNCIONES DE REPORTES

void empresasCategoria(){
    int categoria;
    Empresa reg;
    ArchivoEmpresas archiEmp;
    int cantReg=archiEmp.contarRegistros();
    int i;
    cout<<"INGRESE CATEGORIA DE EMPRESA A LISTAR ";
    cin>>categoria;
    for(i=0;i<cantReg;i++){
            reg=archiEmp.leerRegistro(i);
            if(reg.getCategoria()==categoria) {
                reg.Mostrar();
                cout<<endl;
            }
    }
}

void muncipiosSinEmpresas(){
    int vMuniEmpresas[135]={0};/// cuando declaro le tengo que poner cu�ntos elementos quiero
    Empresa reg;
    ArchivoEmpresas archiEmp;
    int cantReg=archiEmp.contarRegistros();
    int i;
    for(i=0;i<cantReg;i++){
       reg=archiEmp.leerRegistro(i);
       vMuniEmpresas[reg.getMunicipio()-1]++;
    }
    ///el vector va a contener en cada posici�n la cantidad de empresas por municipio -1 (0 est� el 1, en la 1 est� el 2...)
    int sinEmpresas=contarRepetidos(vMuniEmpresas,135,0);
    cout<<"CANTIDAD DE MUNICIPIOS SIN EMPRESAS "<<sinEmpresas<<endl;
}

int contarRepetidos(int *v, int tam,int numeroBuscado){
    int i, cont=0;
    for(i=0;i<tam;i++){
            if(v[i]==numeroBuscado) cont++;
    }
    return cont;
}
