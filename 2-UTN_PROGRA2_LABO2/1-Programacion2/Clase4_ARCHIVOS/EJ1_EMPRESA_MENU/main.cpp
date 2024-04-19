#include<iostream>
#include<cstring>

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


class Empresas{
private:
    int _numEmpresa;
    char _nombre[30];
    int _cantEmpleados;
    int _categoria; //1 a 80
    int _NumeroDeMunicipioAlQuepertenece; // 1 a 135
    bool _estado;

public:
    Empresas(int numEmpresa = 0, const char* nombre = "X", int cantEmpleados = 0, int categoria = 0, int NumeroDeMunicipioAlQuepertenece = 0, bool estado = false){
        _numEmpresa = numEmpresa;
        strcpy(_nombre, nombre);
        _cantEmpleados = cantEmpleados;
        _categoria = categoria;
        _NumeroDeMunicipioAlQuepertenece = NumeroDeMunicipioAlQuepertenece;
        _estado = estado;
    }


    //setters y getters
    void setNumEmpresa(const int numEmpresa){_numEmpresa = numEmpresa;}
    int getNumEmpresa()const {return _numEmpresa;}

    void setNombre(const char* nombre){strcpy(_nombre, nombre);}
    const char* getNombre()const {return _nombre;}

    void setCantEmpleados(const int cantEmpleados){_cantEmpleados = cantEmpleados;}
    int getCantEmpleados()const {return _cantEmpleados;}

    
    void setCategoria(const int categoria){_categoria = categoria;}
    int getCategoria()const {return _categoria;}

    void setNumeroDeMunicipioAlQuepertenece(const int NumeroDeMunicipioAlQuepertenece){_NumeroDeMunicipioAlQuepertenece = NumeroDeMunicipioAlQuepertenece;}
    int getNumeroDeMunicipioAlQuepertenece()const {return _NumeroDeMunicipioAlQuepertenece;}

    void setEstado(const bool estado){_estado = estado;}
    bool getEstado()const {return _estado;}
    
    void mostrar(){
        cout<<"Numero de empresa: "<<_numEmpresa<<endl;
        cout<<"Nombre: "<<_nombre<<endl;
        cout<<"Cant. Empleados: "<<_cantEmpleados<<endl;
        cout<<"Categoria: "<<_categoria<<endl;
        cout<<"Numero de municipio: "<<_NumeroDeMunicipioAlQuepertenece<<endl;
        //cout<<"Estado: "<<_estado<<endl;        
    }

    void cargar(){
        cout << "NUMERO EMPRESA: "; cin >> _numEmpresa;
        cout << "NOMBRE: "; cargarCadena(_nombre, 30);
        cout << "CANT. EMPLEADOS: "; cin >> _cantEmpleados;
        cout << "CATEGORIA: "; cin >> _categoria;
        cout << "NUMERO DE MUNICIPIO: "; cin >> _NumeroDeMunicipioAlQuepertenece;
        _estado = true;
    }

    void cargar(Empresas obj[], int tam=5){
        for (int i = 0; i < tam; i++){
            obj[i].cargar();
            cout<<endl;
        }
    }

    void mostrar(Empresas obj[], int tam=5){
        for(int i=0; i < tam; i++){
            obj[i].mostrar();
            cout<<endl;
        }
    }
void crearArchivo(int tam=5){ //int tam=5
    Empresas objE;
    FILE *p;
    p = fopen("Empresas.dat","wb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        exit(1);
    }

    for(int i=0; i<tam; i++){
        objE.cargar();
        fwrite(&objE, sizeof(Empresas), 1, p);
    }

    fclose(p);
}

void crearArchivo(Empresas vec[], int tam=5){ //Empresas vec[], int tam=5
    FILE *p;
    p = fopen("Empresas.dat","wb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        exit(1);
    }

    for(int i=0; i<tam; i++){
        fwrite(&vec[i], sizeof(Empresas), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Empresas objE;
    FILE *p;
    p = fopen("empresas.dat","rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        exit(1);
    }

while (fread(&objE, sizeof(Empresas), 1, p) == true){
    if(objE.getEstado()==true){
    objE.mostrar();
    cout << endl;
    }
}

    fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen("empresas.dat", "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Empresas);
    }

Empresas leerRegistro(int pos){
        Empresas reg;
        FILE *p;
        p=fopen("empresas.dat", "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }


bool reemplazarRegistro(Empresas reg, int posicionAReemplazar){
    FILE *p = fopen("empresas.dat", "rb+");
    if (p == NULL){return false;}
    fseek(p, posicionAReemplazar * sizeof(Empresas), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Empresas), 1, p);
    fclose(p);
    return pudoEscribir;
}

void BajaLogica(){

    int numEmp;
    Empresas objE;

    int tam = objE.contarRegistros();

    cout<<"Ingrese Numero de Empresa:"; cin>>numEmp;

    for(int i=0; i<tam; i++){
        objE = objE.leerRegistro(i);

        if( numEmp == objE.getNumEmpresa() ){
            objE.setEstado(false);
            reemplazarRegistro(objE, i);
        }
    }
}

void AltaLogica(){


    int numEmp;
    Empresas objE;

    int tam = objE.contarRegistros();

    cout<<"Ingrese Numero de Empresa:"; cin>>numEmp;

    for(int i=0; i<tam; i++){
        objE = objE.leerRegistro(i);

        if( numEmp == objE.getNumEmpresa() ){
            objE.setEstado(true);
            reemplazarRegistro(objE, i);
        }
    }
}

void modificarEmpresa(){
    int numEmp;
    int categoria;
    Empresas objE;

    int tam = objE.contarRegistros();

    cout<<"Ingrese Numero de Empresa:"; cin>>numEmp;

    for(int i=0; i<tam; i++){
        objE = objE.leerRegistro(i);

        if(( numEmp == objE.getNumEmpresa() ) && ( objE.getEstado() == true )){
            cout<<"Ingrese nueva categoria:"; cin>>categoria;
            objE.setCategoria(categoria);
            reemplazarRegistro(objE, i);
            cout<<"se encontro la empresa y se modifico la categoria"<<endl;
            return;
        }
    }
cout<<"No se encontro la empresa"<<endl;
}


void listarEmpresasPorNumero(){
    int numEmp;
    Empresas objE;

    cout<<"Ingrese Numero de Empresa:"; cin>>numEmp;

    int tam= objE.contarRegistros();

    for(int i=0; i<tam; i++){
        objE = objE.leerRegistro(i);
        if((numEmp == objE.getNumEmpresa()) && (objE.getEstado() == true)){
            objE.mostrar();
        }
    }
}

};
//PROTOTIPOS
void Actividad1puntoA();
void Actividad1puntoB();
void Actividad1puntoC();


void subMenuListar(){
    Empresas obj;
    int opc;     
    while(true){
        system("cls");
        cout << "1-LISTAR TODAS LAS EMPRESAS" << endl;
        cout << "2-LISTAR EMPRESA POR NUMERO" << endl;
        cout << "0-SALIR" << endl;
        cout << "OPCION: "; cin >> opc;
        system("cls");
        switch(opc){
            /****************************************/
            case 1:{
                obj.mostrarArchivo();
                //system("pause");
            }break;
             /****************************************/
            case 2:{
                obj.listarEmpresasPorNumero();
                //system("pause");
            }break;
            /****************************************/
            case 0:{
                return;
            }break;
        }
        system("pause");
    }

}

void Menu(){
    int opc;
    Empresas obj[5];

    while(true){
        system("cls");
        cout<<"1 - ALTA DE EMPRESAS"<<endl; //cargar archivo "wb"
        cout<<"2 - BAJA DE EMPRESAS"<<endl; //dar de baja el estado, ingresando un numero de empresa
        cout<<"3 - MODIFICAR EMPRESAS"<<endl; //modificar archivo, ingresando un numero de empresa "rb+"
        cout<<"4 - SubMenu de Listar"<<endl; //mostrar archivo "rb"
        cout<<"------------------------------"<<endl;
        cout<<"5 - Punto A - Actividad 1"<<endl;
        cout<<"6 - Punto B - Actividad 1"<<endl;
        cout<<"7 - Punto C - Actividad 1"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout << "OPCION: "; cin >> opc;
        system("cls");
        
        switch (opc)
        {
            /***************************************/
            case 1:{
                obj->cargar(obj,5);
                obj->crearArchivo(obj,5);
            }break;
            /***************************************/
            case 2:{
                obj->BajaLogica();
            }break;
            /***************************************/
            case 3:{
                obj->modificarEmpresa();
            }break;
             /***************************************/
            case 4:{
                subMenuListar();
            }break;        
            /***************************************/
            case 5:{
                Actividad1puntoA();
            }break;        
            /***************************************/
            case 6:{
                Actividad1puntoB();
            }break;  
            /***************************************/
            case 7:{
                Actividad1puntoC();
            }break;  
            /***************************************/
            case 0:{
                return;
            }break;
            /***************************************/
        }    
        system("pause");
    }

}



void Actividad1puntoA(){
    //a) Calcular e informar la cantidad de empresas de cada municipio.
    int contVec[135] = {};
    Empresas obj;
    FILE *p;

    p = fopen("empresas.dat","rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }   

    int indice = 0;
    while (fread(&obj, sizeof(Empresas), 1, p) == true){//registro 0
        if(obj.getEstado()==true){
        contVec[obj.getNumeroDeMunicipioAlQuepertenece()-1] ++; // sumo en el municipio al que pertenece la empresa
        }
    }
    fclose(p);

    cout<<"CANTIDAD DE EMPRESAS POR MUNICIPIO"<<endl;
    for(int i=0; i<135; i++){
        cout<<"MUNICIPIO "<<i+1<<" - "<<contVec[i]<<endl;
    }
}

void Actividad1puntoB(){
    //b) Informar los nombres de las empresas con más de 200 empleados

    Empresas obj;
    int tam = obj.contarRegistros();

    cout << "EMPRESAS CON MAS DE 200 EMPLEADOS\n"; 
    for(int i=0; i<tam; i++){
        obj = obj.leerRegistro(i);
        if(obj.getCantEmpleados() > 200 && obj.getEstado()==true){
            cout << "EMPRESA: " << obj.getNumEmpresa()<<endl;
        }        
    }        
}

void Actividad1puntoC(){
    //c) Calcular e informar la categoría de empresa con más empleados
    int vecCategoriaMaxEmpleado[80] = {0};
    int posCategoria=0;

    Empresas obj;
    FILE *p = fopen("empresas.dat", "rb");
    if(p == NULL){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }  
    
    while (fread(&obj, sizeof(Empresas), 1, p) == true){
        if(obj.getEstado()==true){
            vecCategoriaMaxEmpleado[obj.getCategoria()-1] += obj.getCantEmpleados();
        }
    }

    fclose(p);

    cout<<"//////////////"<<endl;

    //BUSCAR MAXIMO
    int maxCantEmpleado = vecCategoriaMaxEmpleado[0];
    for(int x = 1; x < 80; x++){
        if(vecCategoriaMaxEmpleado[x] > maxCantEmpleado){
            maxCantEmpleado = vecCategoriaMaxEmpleado[x];
        }
    }

    //BUSCAR CATEGORIA CON EL MAXIMO

    p = fopen("empresas.dat", "rb");
    if(p == NULL){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }  

    while (fread(&obj, sizeof(Empresas), 1, p) == true){
        if(obj.getEstado()==true){

            if(obj.getCantEmpleados() == maxCantEmpleado){
                posCategoria = obj.getCategoria();
            }

        }
    }

    cout<<"MAXIMO: "<<maxCantEmpleado<<endl;
    cout<<"CATEGORIA CON MAS EMPLEADOS es: "<<posCategoria<<endl;

    fclose(p);

}

int main(){

    Menu();

    return 0;
}