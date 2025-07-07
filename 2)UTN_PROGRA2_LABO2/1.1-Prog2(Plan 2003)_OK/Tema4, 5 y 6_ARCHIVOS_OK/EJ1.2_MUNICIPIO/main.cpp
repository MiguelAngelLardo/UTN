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

class Municipios{
    private:
        int NumeroDeMunicipio;
        char NombreMunicipio[20];
        int SeccionAlaQuePertenece;
        int CantidadDeHabitantes;
        bool Estado;
    public:
        //setters y getters
        void setNumeroDeMunicipio(int num){NumeroDeMunicipio = num;}
        int getNumeroDeMunicipio() const{return NumeroDeMunicipio;}

        void setNombreMunicipio(const char* nombre){strcpy(NombreMunicipio, nombre);}
        const char *getNombreMunicipio() const {return NombreMunicipio;}

        void setSeccionAlaQuePertenece(int seccion){SeccionAlaQuePertenece = seccion;}
        int getSeccionAlaQuePertenece() const{return SeccionAlaQuePertenece;}

        void setCantidadDeHabitantes(int habitantes){CantidadDeHabitantes = habitantes;}
        int getCantidadDeHabitantes() const{return CantidadDeHabitantes;}

        void setEstado(bool estado){Estado = estado;}
        bool getEstado() const{return Estado;}
        
            
        void cargar(){
            cout<<"NUMERO DE MUNICIPIO: "; cin>>NumeroDeMunicipio;
            cout<<"NOMBRE DEL MUNICIPIO: "; cin>>NombreMunicipio;
            cout<<"SECCION ALA QUE PERTENECE: "; cin>>SeccionAlaQuePertenece;
            cout<<"CANTIDAD DE HABITANTES: "; cin>>CantidadDeHabitantes;
            Estado = true;
        }

        void mostrar(){
            cout << "NUMERO DE MUNICIPIO: " << NumeroDeMunicipio << endl;
            cout << "NOMBRE DEL MUNICIPIO: " << NombreMunicipio << endl;
            cout << "SECCION A LA QUE PERTENECE: " << SeccionAlaQuePertenece << endl;
            cout << "CANTIDAD DE HABITANTES: " << CantidadDeHabitantes << endl;
            //cout << "ESTADO: " << Estado << endl;
        }

        //constructor
        Municipios(int num=0, const char* nombre = "X", int seccion = 0, int habitantes = 0, bool estado = false){
            NumeroDeMunicipio = num;
            strcpy(NombreMunicipio, nombre);
            SeccionAlaQuePertenece = seccion;
            CantidadDeHabitantes = habitantes;
            Estado = estado;
        }

        //destructor
        ~Municipios(){}

        void crearArchivo(int tam=5){
            Municipios objE;
            FILE *p;
            p = fopen("Municipios.dat","wb");
            if(p==NULL){
                cout << "No se pudo abrir el archivo crearArchivo" << endl;
                exit(1);
            }

            for(int i=0; i<tam; i++){
            objE.cargar();
            cout<<endl;
            fwrite(&objE, sizeof(Municipios), 1, p);
            }

            fclose(p);
        }

        void mostrarArchivo(){
            Municipios objE;
            FILE *p;
            p = fopen("Municipios.dat","rb");
            if(p==NULL){
                cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
                exit(1);
            }

        while (fread(&objE, sizeof(Municipios), 1, p) == true){
        if(objE.getEstado()){
            objE.mostrar();
            cout << endl;
        }
        }

            fclose(p);
        }

        int contarRegistros(){
                FILE *p;
                p=fopen("Municipios.dat", "rb");
                if(p==NULL) return -1;
                fseek(p, 0,2);
                int tam=ftell(p);
                fclose(p);
                return tam/sizeof(Municipios);
            }

        Municipios leerRegistro(int pos){
                Municipios reg;
                FILE *p;
                p=fopen("Municipios.dat", "rb");
                if(p==NULL) return reg;
                fseek(p, sizeof reg*pos,0);
                fread(&reg, sizeof reg,1, p);
                fclose(p);
                return reg;
            }

    

void Actividad2puntoB(){//b) Calcular e informar la cantidad de municipios con menos de 200.000 habitantes.
    Municipios mun;
    int tam = mun.contarRegistros(); //use seek + teel
    int contadorMenosDe200000Habitantes;

    for (int x = 0; x < tam; x++){
        mun = mun.leerRegistro(x); //fseek + fread
        if(mun.getCantidadDeHabitantes() < 200000 && mun.getEstado() == true){
            contadorMenosDe200000Habitantes ++;
        }
    }

    cout << "La cantidad de municipios con menos de 200.000 habitantes es de: " << contadorMenosDe200000Habitantes << endl;
}

void Actividad2puntoC(){ //seccion 1 a 9 + cant habitantes - informar la seccion con mayor cant de habitantes
    Municipios mun;
    int vSeccionHabitantes[9] = {0};
    int tam = mun.contarRegistros(); //seek + tell para contar

    //CARGA VECTOR        
    for (int x = 0; x < tam; x++){
        mun = mun.leerRegistro(x); // fseek y fread      
        vSeccionHabitantes[mun.getSeccionAlaQuePertenece()-1] += mun.getCantidadDeHabitantes();  
    }

    //CALCULA MAXIMO
    int maxCantHabitante = vSeccionHabitantes[0];
    int maxSeccion = 1;
    for(int x = 1; x < 9; x++){
        if(vSeccionHabitantes[x] > maxCantHabitante){
            maxCantHabitante = vSeccionHabitantes[x];
            maxSeccion = x+1;
        }
    }

    cout << "La seccion con mas cantidad de habitantes es: " << maxSeccion << " con " << maxCantHabitante << " habitantes." << endl;
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
    Municipios objM;

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
        cout<<"8 - ALTA DE MUNICIPIOS"<<endl;
        cout<<"9 - LISTAR MUNICIPIOS"<<endl;
        cout<<"10 - PUNTO B - ACTIVIDAD 2"<<endl;
        cout<<"11 - PUNTO C - ACTIVIDAD 2"<<endl;
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
            case 8:{
                objM.crearArchivo();
            }break;  
            /***************************************/
            case 9:{
                objM.mostrarArchivo();
            }break;  
            /***************************************/
            case 10:{
                objM.Actividad2puntoB();
            }break; 
            /***************************************/
            case 11:{
                objM.Actividad2puntoC();
            }break; 
            case 0:{
                return;
            }break;
            /***************************************/
        }    
        system("pause");
    }

}



// void Actividad1puntoA(){
//     //a) Calcular e informar la cantidad de empresas de cada municipio.
//     int contVec[135] = {};
//     Empresas obj;
//     FILE *p;

//     p = fopen("empresas.dat","rb");
//     if(p==NULL){
//         cout << "No se pudo abrir el archivo" << endl;
//         exit(1);
//     }   

//     int indice = 0;
//     while (fread(&obj, sizeof(Empresas), 1, p) == true){//registro 0
//         if(obj.getEstado()==true){
//         contVec[obj.getNumeroDeMunicipioAlQuepertenece()-1] ++; // sumo en el municipio al que pertenece la empresa
//         }
//     }
//     fclose(p);

//     cout<<"CANTIDAD DE EMPRESAS POR MUNICIPIO"<<endl;
//     for(int i=0; i<135; i++){
//         cout<<"MUNICIPIO "<<i+1<<" - "<<contVec[i]<<endl;
//     }
// }

void Actividad1puntoA(){
    //a) Calcular e informar la cantidad de empresas de cada municipio.
    int contVec[135] = {};
    Empresas obj;
    Municipios mun;
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

    int tam = mun.contarRegistros();

    cout<<"CANTIDAD DE EMPRESAS POR MUNICIPIO"<<endl;
    for(int i=0; i<135; i++){
        cout<<"MUNICIPIO "<<i+1<<endl;
        cout<<"Cantidad: "<<contVec[i]<<endl;

        for(int j=0; j<tam; j++){
            mun = mun.leerRegistro(j);

            if( (i == mun.getNumeroDeMunicipio()) && (mun.getEstado()==true) ){
                cout << "MUNICIPIO: " << mun.getNombreMunicipio() << endl;
            }
        }
        cout<<endl;
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