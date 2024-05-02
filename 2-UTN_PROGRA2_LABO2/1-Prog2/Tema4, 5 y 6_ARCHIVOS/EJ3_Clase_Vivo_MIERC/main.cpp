
/*
A partir del archivo de Empresas de la clase pasada, (hacer un proyecto) agregar al menú una opción de nombre REPORTES, que llame a un submenú con las siguientes opciones/puntos a resolver:

1. Listar los registros de las empresas que pertenezcan a una categoría que se ingresa por teclado

2. Listar los registros de las empresas con más de 10 empleados

3. Calcular e informar la cantidad de municipios sin empresas.

4. Listar los municipios con más de 5 empresas.

5. Informar la categoría con más empresas.

6. Informar el municipio con más empresas

7. Informar para cada municipio la cantidad de empleados de las empresas pertenecientes a ese municipio

8. Informar el municipio con mayor cantidad de empleados en las empresas pertenecientes a ese municipio 

9. Informar la cantidad de empleados (entre todas las empresas) de cada categoría

10. Informar la categoría con más empleados (entre todas las empresas)


11-Hacer la funcion buscarRegistro() que se llama desde el menu. La funcion debe pedir un numero de empresa y mostrar la empresa que
 tenga ese numero. Si no encuentra la empresa debe informarlo.

12-Modificar la funcion altaEmpresa(). No debe aceptar un registro que contenga un numero de empresa existente.

13-Hacer la funcion modificarCantidadEmpleados() que se llama desde el menu principal. La funci�n debe pedir un n�mero de empresa, verificar si
existe en el archivo, y cambiar la cantidad de empleados de esa empresa. El nuevo valor de cantidad se debe ingresar por teclado

14-Crear una funcion que reciba un numero de empresa, busque en el archivo y devuelva el registro con ese numero. En caso de no
haber una empresa con ese numero, devolver un objeto con el numero seteado en -1.

Número Nombre  Cantida de empleados Categoría Municipio Estado
1 ABC 50 5 1 1
2 SRL 20 4 2 0
3 DEK 10 3 3 1
4 SAP 5 7 4 1
5 USB 23 1 4 0
6 RET 14 1 4 1

*/

#include <iostream>
#include <cstring>

using namespace std;


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
        int getCategoria(){return categoria;}
        void setEstado(bool e){estado = e;}
        int getNumero(){return numero;}
        int getCantidadEmpleados(){return cantidadEmpleados;}
        bool getEstado(){return estado;}
        void Cargar();
        void Mostrar();
        int getMunicipio(){return numeroMunicipio;}
        void setCantidadEmpleados(int c){cantidadEmpleados = c;}
};

void Empresa::Cargar(){
    cout<<"NUMERO: ";
    cin>>numero;
    //cin.ignore();
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
        ArchivoEmpresas(const char *n="Empresas.dat"){strcpy(nombre,n);}
        void grabarRegistro(Empresa obj);
        Empresa leerRegistro(int pos);
        int buscarRegistro(int num);
        int contarRegistros();
        bool modificarRegistro(Empresa reg, int posicionAReemplazar);
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

bool ArchivoEmpresas::modificarRegistro(Empresa reg, int posicionAReemplazar){
    FILE *p = fopen("Empresas.dat", "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Empresa), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Empresa), 1, p);
    fclose(p);
    return pudoEscribir;
}

void grabarEmpresa(Empresa obj){
    FILE *pEmp;
    pEmp=fopen("Empresas.dat", "ab");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fwrite(&obj, sizeof (Empresa), 1, pEmp);
    fclose(pEmp);
}

void modificarEmpresa(Empresa obj, int pos){
    FILE *pEmp;
    pEmp=fopen("Empresas.dat", "rb+");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fseek(pEmp, pos * sizeof (Empresa) , 0);
    fwrite(&obj, sizeof (Empresa), 1, pEmp);
    fclose(pEmp);
}

void altaEmpresa(int tam=5){
    Empresa objE;
    FILE *p;
    p = fopen("Empresas.dat","wb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.Cargar();
    cout<<endl;
    fwrite(&objE, sizeof(Empresa), 1, p);
    }

    fclose(p);
}

// void altaEmpresa(int tam=5){
//     for(int i=0; i<tam; i++){
//     Empresa objE;
//     FILE *p;
//     p = fopen("Empresas.dat","ab");
//     if(p==NULL){
//         cout << "No se pudo abrir el archivo crearArchivo" << endl;
//         cout<<"En la Linea: "<<__LINE__<<endl;
//         exit(1);
//     }

    
//     objE.Cargar();
//     cout<<endl;
//     if(punto12AltaEmpresaNoExistente(objE.getNumero())==false){
//     fwrite(&objE, sizeof(Empresa), 1, p);
//     }else{
//         cout<<"La empresa ya existe"<<endl;
//         exit(1);
//     }

//     fclose(p);
//     }
// }


void grabarVectorEmpresas(Empresa *v, int tam){
    FILE *pEmp;
    pEmp=fopen("Empresas.dat", "ab");
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
    pEmp=fopen("Empresas.dat","rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(pEmp, 0, 2);
    int cantBytes = ftell(pEmp);
    fclose(pEmp);
    return cantBytes/sizeof(Empresa);
}




Empresa leerEmpresa(int pos){
    Empresa obj;
    obj.setNumero(-1);
    FILE *p;
    p=fopen("Empresas.dat", "rb");
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

// void listarEmpresas(){
//     Empresa obj;
//     int cant=contarRegistros();
//     for(int i=0; i<cant; i++){
//         obj = leerEmpresa(i);
//         obj.Mostrar();
//         if(obj.getEstado())cout<<endl;
//     }
// }

void listarEmpresas(){
    Empresa objE;
    FILE *p;
    p = fopen("Empresas.dat","rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

while (fread(&objE, sizeof(Empresa), 1, p) == true){
if(objE.getEstado()){
    objE.Mostrar();
    cout << endl;
}
}

    fclose(p);
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
    ArchivoEmpresas arcEmp("Empresas.dat");
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

//#include"funciones.h"

//prototipos
void punto1();
void punto2();
void punto3();
void punto4();
void punto5();
void punto6();
void punto7();
void punto8();
void punto9();
void punto10();
void punto11BuscarRegistro();
bool punto12AltaEmpresaNoExistente(int NumEmp);
void punto13ModificarCantidadEmpleados();
Empresa punto14BusquedaPorNumero();
int punto15DevolverPosicionRegistro();


int main(){
    while(true){
        int opc;
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"--------------"<<endl;
        cout<<"1 - ALTA EMPRESA WB"<<endl;
        cout<<"2 - BAJA LOGICA EMPRESA"<<endl;
        cout<<"3 - MODIFICAR CATEGORIA EMPRESA"<<endl;
        cout<<"4 - LISTAR EMPRESAS"<<endl;
        cout<<"5 - BUSCAR EMPRESA POR NUMERO"<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"6 - punto 1"<<endl;
        cout<<"7 - punto 2"<<endl;
        cout<<"8 - punto 3"<<endl;
        cout<<"9 - punto 4"<<endl;
        cout<<"10 - punto 5"<<endl;
        cout<<"11 - punto 6"<<endl;
        cout<<"12 - punto 7"<<endl;
        cout<<"13 - punto 8"<<endl;
        cout<<"14 - punto 9"<<endl;
        cout<<"15 - punto 10"<<endl;
        cout << "16 - punto 11 buscarRegistro()" << endl;
        cout << "17 - punto12AltaEmpresa()" << endl;
        cout << "18 - punto13ModificarCantidadEmpleados" << endl;
        cout << "19 - punto14Busqueda de empresa en el archivo y devuelva el registro con ese numero de lo contrario -1 en ID" << endl;
        cout << "20- punto15DevolverPosicionRegistro" << endl;

        cout<<"----------------------------------------"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                cout<<"//////////////////"<<endl;
                altaEmpresa(50);
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
            case 6:
                punto1();
                break;
            case 7:
                punto2();
                break;
            case 8:
                punto3();
                break;
            case 9:
                punto4();
                break;
            case 10:
                punto5();
                break;
            case 11:
                punto6();
                break;
            case 12:
                punto7();
                break;
            case 13:
                punto8();
                break;
            case 14:
                punto9();
                break;
            case 15:
                punto10();
                break;
            case 16:
                punto11BuscarRegistro();
                break;
            case 17:{
   // /*---->*/            cout << (punto12AltaEmpresaNoExistente() ? "Nuevo registro Agregado exitosamente\n" : "UPS el registro ya existe\n");
                }break;
            case 18:
                punto13ModificarCantidadEmpleados();
                break;
            case 19:{
                Empresa obj;
                obj = punto14BusquedaPorNumero();
                cout << "REGISTRO DEVUELTO PUNTO 14: " << endl;
                obj.Mostrar();
            }break;
            case 20:{
                int pos;
                pos = punto15DevolverPosicionRegistro();
                if(pos >= 0){
                    cout << "POSICION: " << pos+1 << endl;
                }else{
                    cout << "POSICION: " << pos << endl;
                }


            }break;

            case 0:
                return 0;
            default:
                cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
                system("pause");
                break;
        }
        cout<<"----------------------------------------------"<<endl;
        system("pause");
        system("cls");
    }
    return 0;
}



//declarar Puntos

void punto1(){//igresar 1 categoria y listar toda las empresas
    Empresa objE;
    ArchivoEmpresas ARobjE;
    int categoriaEmpresa;

    int tam = ARobjE.contarRegistros();
    cout << "Ingrese una categoria para ver todas las emrpesas a la que pertenece: ";
    cin >> categoriaEmpresa;

    for(int i=0; i<tam; i++){
        objE = ARobjE.leerRegistro(i);

        if(objE.getEstado()){
            if(objE.getCategoria() == categoriaEmpresa){
                cout << "INDICE #" << i+1 << endl;
                cout << "REGISTRO ENTERO: " << endl;
                objE.Mostrar();
                cout << endl;
            }
        }    
    }
}


void punto2(){//listar los registros de las empresas con mas de 50 empleados
    Empresa objE;
    ArchivoEmpresas ARobjE;
    int tam = ARobjE.contarRegistros();

    for(int i=0; i<tam; i++){
        objE = ARobjE.leerRegistro(i);

        if(objE.getEstado()){
            
            if(objE.getCantidadEmpleados() > 50){
                cout << "INDICE #" << i+1 << endl;
                cout << "REGISTRO ENTERO: " << endl;
                objE.Mostrar();
                cout << endl;
            }
        }    
    }
}

/*
  private:
        int numero;
        char nombre[30];
        int cantidadEmpleados;
        int categoria;  
        int numeroMunicipio;
        bool estado;
*/
void punto3(){//calcular e informar la cantidad de minicipios sin empresa
    Empresa objE;
    ArchivoEmpresas ARobjE;
    int tam = ARobjE.contarRegistros();

    int vMunicipiosCantidadSinEmpresa [135] = {0};//el que esta en cero no tiene empresa

    for(int i=0; i<tam; i++){
        objE = ARobjE.leerRegistro(i);
        if(objE.getEstado()){
            if(objE.getNumero() > 0){//tiene empresa 
                vMunicipiosCantidadSinEmpresa[objE.getMunicipio()-1]=1;      
            }    
        }    
    }

    int contadorMuniSinEmpresa = 0;
    for(int i=0; i<135; i++){
        if(vMunicipiosCantidadSinEmpresa[i] == 0){//si esta en cero es que no tiene empresa
            contadorMuniSinEmpresa++;
        }    
    }   

    cout << "La cantidad de municipios sin empresa es: " << contadorMuniSinEmpresa << endl;
}



void punto4(){   //4. Listar los municipios con más de 5 empresas.
    Empresa objE;
    ArchivoEmpresas ARobjE;

    int tam = ARobjE.contarRegistros();

    int vMunicipiosCantidadCon3oMasEmpresa [135] = {0};

    for(int i=0; i<tam; i++){
        objE = ARobjE.leerRegistro(i);
        if(objE.getEstado()){
            vMunicipiosCantidadCon3oMasEmpresa [objE.getMunicipio()-1]++;            
        }    
    }

    cout << "NUMEROS DE LOS MUNICIPIOS CON MAS DE 2 EMPRESAS: " << endl;
    for(int i=0; i<135; i++){
        if(vMunicipiosCantidadCon3oMasEmpresa[i] >= 3){
            cout << "MUNICIPIO #" << i+1 << " con " <<  vMunicipiosCantidadCon3oMasEmpresa[i] << " empresas" << endl;
        }    
    }    
}

void punto5(){//informar la categoria con mas empresas
    Empresa objE;//nombre, cantidadEmpleados, categoria, numeroMunicipio
    ArchivoEmpresas ARobjE;

    int vCategoriasMaxEmpresas[80] = {0}; //contador de toda la vida

    int tam = ARobjE.contarRegistros();

    for (int i= 0; i < tam; i++){//recorre todas las empresas 
        objE = ARobjE.leerRegistro(i);
        if(objE.getEstado()){
            vCategoriasMaxEmpresas[objE.getCategoria()-1]++; 
        } 
    }    

    int mayor = 0;
    for(int i = 1; i < 80; i++){
        if(vCategoriasMaxEmpresas[i] > vCategoriasMaxEmpresas[mayor]){
            mayor = i;
        }
    }

    cout << "La categoria con mas empresas es: " << mayor+1 << " -> La cantidad de empresas es: " << vCategoriasMaxEmpresas[mayor] << endl;
}

void punto6(){//6. Informar el municipio con más empresas

    Empresa obj1;
    ArchivoEmpresas obj2;

    int tam = obj2.contarRegistros();

    int vec[80]={0};

    for(int i=0; i<tam; i++){
        obj1 = obj2.leerRegistro(i);

        if(obj1.getEstado()){
            vec[obj1.getMunicipio()-1]++;
        }
    }

    int mayor = 0;
    int pos;

    for(int i=0; i<80; i++){
        if(i == 0){
            mayor = vec[i];
            pos=i;
        }else if(vec[i]>mayor){
            mayor = vec[i];
            pos=i;
        }
    }

    cout<<"El municipio con mas empresas es: " << pos+1 << " -> La cantidad de empresas es: " << mayor << endl;
}

void punto7(){//7. Informar para cada municipio la cantidad de empleados de las empresas pertenecientes a ese municipio
    Empresa objE;//nombre, cantidadEmpleados, categoria, numeroMunicipio
    ArchivoEmpresas ARobjE;

    int tam = ARobjE.contarRegistros();

    int vCantidadEmpleadosPorMunicipio[135] = {0};

    for(int i=0; i<tam; i++){
        objE = ARobjE.leerRegistro(i);
        if(objE.getEstado()){
            vCantidadEmpleadosPorMunicipio[objE.getMunicipio()-1] += objE.getCantidadEmpleados();
        }    
    }

    for(int i=0; i<135; i++){
        cout << "MUNICIPIO #" << i+1 << " con " << vCantidadEmpleadosPorMunicipio[i] << " empleados" << endl;
    }
    
}

void punto8(){//8. Informar el municipio con mayor cantidad de empleados en las empresas pertenecientes a ese municipio 
    Empresa objE;//nombre, cantidadEmpleados, categoria, numeroMunicipio
    ArchivoEmpresas ARobjE;

    int tam = ARobjE.contarRegistros();

    int vCantidadEmpleadosPorMunicipio[135] = {0};

    for(int i=0; i<tam; i++){
        objE = ARobjE.leerRegistro(i);
        if(objE.getEstado()){
            vCantidadEmpleadosPorMunicipio[objE.getMunicipio()-1] += objE.getCantidadEmpleados();
        }    
    }

    int mayor = 0;
    for(int i=1; i<135; i++){
       if(vCantidadEmpleadosPorMunicipio[i] > vCantidadEmpleadosPorMunicipio[mayor]){
        mayor = i;
       }
    }

    cout << "El municipio con mayor cantidad de empleados es: " << mayor+1 << " -> La cantidad de empleados es: " << vCantidadEmpleadosPorMunicipio[mayor] << endl;
    
}
    


void punto9(){//9. Informar la cantidad de empleados (entre todas las empresas) de cada categoría
    Empresa objE;//nombre, cantidadEmpleados, categoria, numeroMunicipio
    ArchivoEmpresas ARobjE;

    int tam = ARobjE.contarRegistros();

    int vCantidadEmpleadosPorCategoria[80] = {0};

    for(int i=0; i<tam; i++){
        objE = ARobjE.leerRegistro(i);
        if(objE.getEstado()){
            vCantidadEmpleadosPorCategoria[objE.getCategoria()-1] += objE.getCantidadEmpleados();
        }        
    }    
    
    for(int i=0; i<80; i++){
        cout << "CATEGORIA #" << i+1 << " con " << vCantidadEmpleadosPorCategoria[i] << " empleados" << endl;
    }
}

void punto10(){//10. Informar la categoría con más empleados (entre todas las empresas) 
    Empresa objE;//nombre, cantidadEmpleados, categoria, numeroMunicipio
    ArchivoEmpresas ARobjE;

    int tam = ARobjE.contarRegistros();

    int vCantidadEmpleadosPorCategoria[80] = {0};

    for(int i=0; i<tam; i++){
        objE = ARobjE.leerRegistro(i);
        if(objE.getEstado()){
            vCantidadEmpleadosPorCategoria[objE.getCategoria()-1] += objE.getCantidadEmpleados();
        }        
    }    
    
    int mayor = 0;
    for(int i=1; i<80; i++){
        (vCantidadEmpleadosPorCategoria[i] > vCantidadEmpleadosPorCategoria[mayor]) ? (mayor = i) : (mayor = mayor);
    }

    cout << "La categoria con mayor cantidad de empleados es: " << mayor+1 << " -> La cantidad de empleados es: " << vCantidadEmpleadosPorCategoria[mayor] << endl;
}

//11-Hacer la funcion buscarRegistro() que se llama desde el menu. La funcion debe pedir un numero de empresa y mostrar la empresa que
// tenga ese numero. Si no encuentra la empresa debe informarlo.
void punto11BuscarRegistro(){
    Empresa objE;//numero, nombre, cantidadEmpleados, categoria, numeroMunicipio
    ArchivoEmpresas ARobjE;

    int tam = ARobjE.contarRegistros();
    
    int numBuscado;
    cout << "Ingrese el numero de empresa que desea buscar: " << endl;
    cin >> numBuscado;

    int i;
    for(i=0; i<tam; i++){
        objE = ARobjE.leerRegistro(i);
        if(objE.getEstado()){
            if(objE.getNumero() == numBuscado){
                cout << "REGISTRO ENCONTRADO: " << endl;
                objE.Mostrar();
                i=tam+20;
            }  
        }
    } 

    if(i == tam){
        cout << "REGISTRO NO ENCONTRADO" << endl;
    }   
}



//12-Modificar la funcion altaEmpresa(). No debe aceptar un registro que contenga un numero de empresa existente.
// // bool punto12AltaEmpresaNoExistente(){
// //    Empresa obj1;
// //    ArchivoEmpresas ARobj1;
// //    Empresa obj2;
// //    FILE *p = fopen("Empresas.dat","rb");
// //    if(p == NULL){cout<<"No se pudo abrir el archivo"; cout<<"En la Linea: "<<__LINE__<<endl;}
   
// //    cout << "Ingrese un nuevo registro de empresa para sumar al ARCHIVO: " << endl;
// //    obj2.Cargar();

// //    while(fread(&obj1,sizeof(Empresa),1,p)){
// //       if(obj1.getNumero() == obj2.getNumero()){
// //         fclose(p);
// //         return false;        
// //       }
// //    }

// //    ARobj1.grabarRegistro(obj2);

// //    fclose(p);
// //    return true;
// // }


bool punto12AltaEmpresaNoExistente(int NumEmp){
   Empresa obj;
   FILE *p;
   p = fopen("Empresas.dat","rb");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      cout<<"En la Linea: "<<__LINE__<<endl;
   }
   while(fread(&obj,sizeof(Empresa),1,p)){
      if(obj.getNumero()==NumEmp){
         fclose(p);
         return true;
      }
   }
   fclose(p);
   return false;
}


/*
13-Hacer la funcion modificarCantidadEmpleados() que se llama desde el menu principal. La funcion debe pedir un numero de empresa, verificar si
existe en el archivo, y cambiar la cantidad de empleados de esa empresa. El nuevo valor de cantidad se debe ingresar por teclado
*/

void punto13ModificarCantidadEmpleados(){
    Empresa objE;//numero, nombre, cantidadEmpleados, categoria, numeroMunicipio
    ArchivoEmpresas ARobjE;

    int tam = ARobjE.contarRegistros();

    int NumEmp;
    int cantidadEmpleadosAModificar;
    cout << "Ingrese numero de empresa para verificar si existe y modificar la tantidad de empelados: " << endl;
    cin >> NumEmp;

    int cantidadEmpleadoAModificar;
    bool banderaEncontrado = false;
    for(int i=0; i<tam; i++){
        objE = ARobjE.leerRegistro(i);
        if(objE.getEstado()){
            if(objE.getNumero() == NumEmp){
                cout << "REGISTRO ENCONTRADO: " << endl;
                cout << "Ingrese la nueva cantidad de empleados: " << endl;
                cin >> cantidadEmpleadosAModificar;
                objE.setCantidadEmpleados(cantidadEmpleadosAModificar);
                ARobjE.modificarRegistro(objE, i);
                cout << "Registro modificado con exito ahora la cantidad de empleados es: " << objE.getCantidadEmpleados() << "" << endl;
                system("pause");
                banderaEncontrado = true;
            }    
        }    
    }  

    if(!banderaEncontrado){
        cout << "REGISTRO NO ENCONTRADO" << endl;
    }  

}

Empresa punto14BusquedaPorNumero(){
    Empresa objE;//numero, nombre, cantidadEmpleados, categoria, numeroMunicipio
    ArchivoEmpresas ARobjE;

    int tam = ARobjE.contarRegistros();

    int numEmp;
    cout << "Ingrese numero de empresa para buscar: " << endl;
    cin >> numEmp;

    bool encontrado = false;
    for (int i=0; i<tam; i++){
        objE = ARobjE.leerRegistro(i);

        if(objE.getEstado()){
            if(objE.getNumero() == numEmp){
                return objE;
                encontrado = true;
                cout << "Registro encontrado";
                system("pause");
            }    
        }
    }

    if(!encontrado){
        objE = ARobjE.leerRegistro(0);
        objE.setNumero(-1);
        return objE;
    }
}


int punto15DevolverPosicionRegistro(){
    Empresa objE;//numero, nombre, cantidadEmpleados, categoria, numeroMunicipio
    ArchivoEmpresas ARobjE;

    int tam = ARobjE.contarRegistros();

    int numEmp;
    cout << "Ingrese numero de empresa para buscar: " << endl;
    cin >> numEmp;

    for (int i=0; i<tam; i++){
        objE = ARobjE.leerRegistro(i);

        if(objE.getEstado()){
            if(objE.getNumero() == numEmp){
                cout << "Registro encontrado\n";
                system("pause");
                return i;
            }    
        }
    }
  
    return -1;

}

