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



class Municipios{
    private:
        int NumeroDeMunicipio;
        char NombreMunicipio[20];
        int SeccionAlaQuePertenece;
        int CantidadDeHabitantes;
        int cantidadEmpresaCategoria1;
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

        void setCantidadEmpresaCategoria1(int cantidadEMpresaCategoria1){cantidadEmpresaCategoria1 = cantidadEMpresaCategoria1;}
        int getCantidadEmpresaCategoria1() const{return cantidadEmpresaCategoria1;}

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

class Empresas{
private:
    int _numEmpresa;
    char _nombre[30];
    int _cantEmpleados;
    int _categoria; //1 a 80
    int _NumeroDeMunicipioAlQuepertenece; // 1 a 135
    Municipios _nombreMunicipio; //composicipon
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

    void setNombreMunicipio(Municipios municipio){_nombreMunicipio = municipio;}
    Municipios getNombreMunicipio(){return _nombreMunicipio;}

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

void SetAbrirArchivoConWB(const char* nombre,FILE **p){
    *p=fopen(nombre, "wb");
    if(*p==NULL){
        cout << "ERROR : AbrirArchivoConWB()" << endl;
        system("pause");
    }
}

void cargarConFwrite(Empresas &objE, FILE *p, int tam){
    for(int i=0; i<tam; i++){
        objE.cargar();
        fwrite(&objE, sizeof(Empresas), 1, p);
    }
}

void crearArchivo(int tam=5){ //int tam=5
    Empresas objE;
    FILE *p;

    SetAbrirArchivoConWB("Empresas.dat", &p);
    cargarConFwrite(objE, p, tam);

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

void Actividad3puntoA();
void Actividad3puntoB();
void Actividad3puntoC();


////////////////////////////
class Categorias{
private:
    int numeroCaterogia; // 1 a 80
    char nombreCaterogia[20];
    bool estado;
public:
    void setNumeroCaterogia(const int num){numeroCaterogia = num;}
    int getNumeroCaterogia()const {return numeroCaterogia;}

    void setNombreCategoria(const char* nom){strcpy(nombreCaterogia, nom);}
    const char *getNombreCategoria()const {return nombreCaterogia;}

    void setEstadoCategoria(const bool est){estado = est;}
    bool getEstadoCategoria()const {return estado;}

    Categorias(int num=0, const char* nom = "X", bool est = false){
        numeroCaterogia = num;
        strcpy(nombreCaterogia, nom);
        estado = est;
    }

    void cargar(){
        cout << "Numero de Caterogia: "; cin >> numeroCaterogia;
        cout << "Nombre de Caterogia: "; cargarCadena(nombreCaterogia, 20);
        estado = true;
    }

    void mostrar(){
        cout << "Numero de Caterogia: " << numeroCaterogia << endl;
        cout << "Nombre de Caterogia: " << nombreCaterogia << endl;
        //cout << "Activo: " << estado << endl;
    }

       void crearArchivo(int tam=5){
            Categorias objC;
            FILE *p;
            p = fopen("Categorias.dat","wb");
            if(p==NULL){
                cout << "No se pudo abrir el archivo crearArchivo" << endl;
                exit(1);
            }

            for(int i=0; i<tam; i++){
            objC.cargar();
            cout<<endl;
            fwrite(&objC, sizeof(Categorias), 1, p);
            }

            fclose(p);
        }

    void mostrarArchivo(){
       Categorias obj;
       FILE *p;
        p = fopen("Categorias.dat","rb");
        if(p==NULL){
            cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
            exit(1);
        }

        while (fread(&obj, sizeof(Categorias), 1, p) == true){
            obj.mostrar();
            cout << endl;
        }

        fclose(p);
        }

        
        int contarRegistros(){
            FILE *p;
            p=fopen("Categorias.dat", "rb");
            if(p==NULL) return -1;
            fseek(p, 0,2);
            int tam=ftell(p);
            fclose(p);
            return tam/sizeof(Categorias);
        }

        Categorias leerRegistro(int pos){
            Categorias reg;
            FILE *p;
            p=fopen("Categorias.dat", "rb");
            if(p==NULL) return reg;
            fseek(p, sizeof reg*pos,0);
            fread(&reg, sizeof reg,1, p);
            fclose(p);
            return reg;
        }

};




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
    Categorias objC;

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
        cout<<"------------------------------"<<endl;
        cout<<"12 - ALTA DE CATEGORIA"<<endl;
        cout<<"13 - LISTAR CATEGORIA"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"14 - PUNTO A - ACTIVIDAD 3"<<endl;
        cout<<"15 - PUNTO B - ACTIVIDAD 3"<<endl;
        cout<<"16 - PUNTO C - ACTIVIDAD 3"<<endl;
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
             /***************************************/
            case 12:{
                objC.crearArchivo();
            }break;
            /***************************************/
            case 13:{
                objC.mostrarArchivo();
            }break; 
            /***************************************/
            case 14:{
                Actividad3puntoA(); 
            }break;
            /***************************************/
            case 15:{
                Actividad3puntoB();           
            }break;  
            /***************************************/
            case 16:{
                Actividad3puntoC();           
            }break;    
            /***************************************/
            case 0:{                
                return;
            }break;
            /***************************************/
            default:{
                cout << "OPCION INVALIDA" << endl;
                system("pause");
            }
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



void Actividad3puntoA(){
    Empresas objE;
    Categorias objC;

    int tam1=objE.contarRegistros(); 
    int tam2=objC.contarRegistros();

    int vecCategoria[80] = {0};

    for(int i=0; i<tam1; i++){ //indice

        objE = objE.leerRegistro(i);
        if(objE.getEstado()==true){
            for(int x=0; x<80; x++){
                if(x==objE.getCategoria()-1){//corroboras que haya categoria 
                    vecCategoria[x]++;
                }
            }
        }
    }


    //Maximo
    int max=0;
    int maxIndice;
    for(int x = 0; x < tam1; x ++){
        objE = objE.leerRegistro(x);
        if(objE.getEstado()==true){
            
            for(int i=0; i<tam2; i++){
                objC = objC.leerRegistro(i);

                if((objE.getCategoria() == objC.getNumeroCaterogia())){ // && (objC.getEstadoCategoria()==true)
                    

                    if(vecCategoria[objC.getNumeroCaterogia()-1] > max){
                        max=vecCategoria[objC.getNumeroCaterogia()-1];
                        maxIndice = objC.getNumeroCaterogia();
                    }
                }
            }

        }
    }

    cout<<"La categoria con mas empresas es: "<<maxIndice<<endl;
    cout<<"Con una Cantidad de empresas: "<<max<<endl;
}



void GuardarArchivoPuntoB(Empresas obj){
   FILE *p;
   p = fopen("PuntoB.dat","ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
   }
   fwrite(&obj,sizeof(Empresas),1,p);
   fclose(p);
}

void BorrarArchivoPuntoB(){
   FILE *p;
   p = fopen("PuntoB.dat","wb");
   if(p == NULL){
      cout<<"No se pudo borrar el archivo";
   }
   fclose(p);
}

void mostrarArchivoPuntoB(){
    Empresas objE;
    FILE *p;
    p = fopen("PuntoB.dat","rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        exit(1);
    }

while (fread(&objE, sizeof(Empresas), 1, p) == true){

if(objE.getEstado()){

cout<<"Numero de empresa: "<<objE.getNumEmpresa()<<endl;
cout<<"Nombre de la empresa: "<<objE.getNombre()<<endl;
cout<<"Estado: "<<objE.getEstado()<<endl;
cout<<"Nombre del municipio: "<<objE.getNombreMunicipio().getNombreMunicipio()<<endl; 
cout << endl;

}
}

    fclose(p);
}

// void Actividad3puntoB(){ //usando 2 for => forma facil
//     BorrarArchivoPuntoB();
//     Empresas objE;
//     Municipios objM;

//     int tam1 = objE.contarRegistros();
//     int tam2 = objM.contarRegistros();

//     for(int i = 0; i < tam1; i++){
//         objE = objE.leerRegistro(i);
//         if((objE.getEstado() == true) && (objE.getCategoria() == 15)){
            

//             for(int j = 0; j < tam2; j++){
//                 objM = objM.leerRegistro(j);

//                 if((objM.getEstado() == true) && (objM.getNumeroDeMunicipio() == objE.getNumeroDeMunicipioAlQuepertenece())){
//                     
//                     objE.setNombreMunicipio(objM); //aca entendi

//                     GuardarArchivoPuntoB(objE);
//                 }
//             }
                
//         }
//     }
//     mostrarArchivoPuntoB();
// }

void Actividad3puntoB(){//usando 3 for para validar
    BorrarArchivoPuntoB();
    Empresas objE;
    Municipios objM;    
    Categorias objC;

    int tam1 = objE.contarRegistros();
    int tam2 = objM.contarRegistros();
    int tam3 = objC.contarRegistros();

    for(int i = 0; i < tam1; i++){
        objE = objE.leerRegistro(i);
        if((objE.getEstado() == true) && (objE.getCategoria() == 15)){
            

            for(int j = 0; j < tam2; j++){
                objM = objM.leerRegistro(j);
                
                for(int k = 0; k < tam3; k++){
                    objC = objC.leerRegistro(k);
                
                if((objM.getEstado() == true) && (objM.getNumeroDeMunicipio() == objE.getNumeroDeMunicipioAlQuepertenece()) && (objC.getNumeroCaterogia() == objE.getCategoria())){
                    // objE.setNumEmpresa(objE.getNumEmpresa());
                    // objE.setNombre(objE.getNombre());
                    // objE.setEstado(objE.getEstado());
                    objE.setNombreMunicipio(objM); //aca entendi

                    GuardarArchivoPuntoB(objE);
                }


                }

                
            }
                
        }
    }
    mostrarArchivoPuntoB();
}




/*
c) Generar un archivo con la cantidad de empresas de categoría 1 para cada municipio.
Cada registro tiene que tener los siguientes campos
Número de municipio, nombre de municipio, cantidad de empresas de categoría 1 para ese
municipio y estado.
*/

bool Existe(int numMunicipio){
   Municipios obj;
   FILE *p;
   p = fopen("PuntoC.dat","rb");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
   }
   while(fread(&obj,sizeof(Municipios),1,p)){
      if((obj.getNumeroDeMunicipio()==numMunicipio)&&(obj.getEstado())){
         fclose(p);
         return true;
      }
   }
   fclose(p);
   return false;
}

void BorrarArchivoPuntoC(){//esto es para cada vez que lo ejecute se borre y cree uno nuevo
   FILE *p;
   p = fopen("PuntoC.dat","wb");
   if(p == NULL){
      cout<<"No se pudo borrar el archivo";
   }
   fclose(p);
}

void GuardarArchivoPuntoC(Municipios obj){
   FILE *p;
   p = fopen("PuntoC.dat","ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
   }
   fwrite(&obj,sizeof(Municipios),1,p);
   fclose(p);
}

void mostrarArchivoPuntoC(){
    Municipios objM;
    FILE *p;
    p = fopen("PuntoC.dat","rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        exit(1);
    }

    while (fread(&objM, sizeof(Municipios), 1, p) == true){

        if(objM.getEstado()){
            cout<<"Numero de Municipio: " << objM.getNumeroDeMunicipio() <<endl;
            cout<<"Nombre municipio: "<< objM.getNombreMunicipio() << endl;
            cout<<"Cantidad de empresas de categoria 1: " <<objM.getCantidadEmpresaCategoria1()<<endl;
            cout<<"Estado: "<<objM.getEstado()<<endl;
            cout << endl;
        }
    }

    fclose(p);
}


void Actividad3puntoC(){
    BorrarArchivoPuntoC();
    Municipios objM;
    Empresas objE;

    int tam1=objM.contarRegistros();
    int tam2=objE.contarRegistros();

    int vecMunicipios[135] = {0};

/*******************************************************/
    for(int i=0; i<tam1; i++){
        objM = objM.leerRegistro(i);

        if((objM.getEstado()==true)){

            for(int j=0; j<tam2; j++){

                objE = objE.leerRegistro(j);
                if((objE.getEstado()==true) && (objE.getCategoria() == 1) && (objE.getNumeroDeMunicipioAlQuepertenece() == objM.getNumeroDeMunicipio())){
                    vecMunicipios[objM.getNumeroDeMunicipio()-1]++;
                }
            }
        }
    }
/*******************************************************/
    for(int i=0; i<tam1; i++){
        objM = objM.leerRegistro(i);

        if((objM.getEstado()==true)){

            for(int j=0; j<tam2; j++){

                objE = objE.leerRegistro(j);
                if((objE.getEstado()==true) && (objE.getCategoria() == 1) && (objE.getNumeroDeMunicipioAlQuepertenece() == objM.getNumeroDeMunicipio())){
                    objM.setCantidadEmpresaCategoria1(vecMunicipios[objM.getNumeroDeMunicipio()-1]);
                    
                    if(Existe(objM.getNumeroDeMunicipio()) == false){
                    GuardarArchivoPuntoC(objM);
                    }
                }
            }
        }
    }
/*******************************************************/

 mostrarArchivoPuntoC();
 
}


int main(){

    Menu();

    return 0;
}