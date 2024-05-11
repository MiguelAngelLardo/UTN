
#include<iostream>
#include<cstring>
#include <ctime>
using namespace std;

void LimpiarVector(int vec[],int tam=3,int valor=0){
    for(int i=0;i<tam;i++){
        vec[i]=valor;
    }
}

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


class Fecha{

    private:
        int dia;
        int mes;
        int anio;
    public:
        //setters y getters
        void setDia(const int dia){this->dia = dia;}
        void setMes(const int mes){this->mes = mes;}
        void setAnio(const int anio){this->anio = anio;}
        void setearTodo(const int dia, const int mes, const int anio){this->dia = dia; this->mes = mes; this->anio = anio;}

        int getDia()const{return dia;}
        int getMes()const{return mes;}
        int getAnio()const{return anio;}

        void mostrarFecha(){cout << dia << "/" << mes << "/" << anio << endl;}
        void cargar(){
            cout<<"Dia: "; cin >> dia;
            cout<<"Mes: "; cin >> mes;
            cout<<"Anio: "; cin >> anio;
        }

        int getDiaActual()
        {
            time_t t = time(NULL); //time_t es un alias para un entero de 32 y 64 bits - time(NULL) nos da el el tiempo en formato 'timestamp' -> "Epoch time" es un punto inicial (como el 1 de enero de 1970, a las 00:00:00 UTC)
            struct tm *f = localtime(&t);// el struct tm convierte el timestamp a un formato entendible
            dia = (*f).tm_mday; ////(*f).tm_mday => indirecciona f y accede a tm_day
            return dia;                     
        }

        int getMesActual()
        {
            time_t t = time(NULL);
            struct tm *f = localtime(&t);

            mes = f->tm_mon + 1;
            return mes;
        }

        int getAnioActual()
        {
            time_t t = time(NULL);
            struct tm *f = localtime(&t);
        
            anio = f->tm_year + 1900;
            return anio;
        }
        int getHoraActual(){
            time_t t = time(NULL);
            struct tm *f = localtime(&t);
            return f->tm_hour;
        }

        int getMinutoActual(){
            time_t t = time(NULL);
            struct tm *f = localtime(&t);
            return f->tm_min;
        }

        int getSegundoActual(){
            time_t t = time(NULL);
            struct tm *f = localtime(&t);
            return f->tm_sec;
        }

    //si la fecha1 le das el dia,mes,año y es mayor que me devuelta un return 1;
//si la fecha2 le das el dia,mes,año y es mayor que me devuelta un return 2;
//si son iguales un return 0
int CualFechaEsMenor(int& dia1, int& mes1, int& anio1, int& dia2, int& mes2, int& anio2){
    int d1 = dia1;
    int m1 = mes1;
    int a1 = anio1;

    int d2 = dia2;
    int m2 = mes2;
    int a2 = anio2;

    if((a1==a2)&&(m1==m2)&&(d1==d2)){ //son iguales
        return 0;
    }else if((a1>a2)||(m1>m2)||(d1>d2)){ //obj1 es mayor
        return 1;
    }else if((a1==a2)&&(m1>m2)||(d1>d2)){ //obj1 es mayor
        return 1;
    }else if((a1==a2)&&(m1==m2)&&(d1>d2)){ //obj1 es mayor
        return 1;
    }else{                                //obj2 es mayor
        return 2;
    }
}




        //constructor
        Fecha(const int dia = 0, const int mes = 0, const int anio = 0){
            setearTodo(dia, mes, anio);
        }

        //destructor
        ~Fecha(){}
};

class Tarjetas{

    private:
        int numTarjeta;
        Fecha fechaAlta;
        int dni;
        float saldo;
        bool estado;

        int cantidadViajesRealizados;//PuntoK
        float acumuladorTotalGastado; //PuntoLL

        
    public:
        //setters y getters
        void setNumTarjeta(const int numTarjeta){this->numTarjeta = numTarjeta;}
        void setFechaAlta(const Fecha fechaAlta){this->fechaAlta = fechaAlta;}
        void setDni(const int dni){this->dni = dni;}
        void setSaldo(const float saldo){this->saldo = saldo;}
        void setEstado(const bool estado){this->estado = estado;}
        void setCantidadViajesRealizados(const int cantidadViajesRealizados){this->cantidadViajesRealizados = cantidadViajesRealizados;}
        void setAcumuladorTotalGastado(const float acumuladorTotalGastado){this->acumuladorTotalGastado = acumuladorTotalGastado;}
        void setearTodo(const int numTarjeta, const int dni, const float saldo, const bool estado, int dia,int mes,int anio){
            this->numTarjeta = numTarjeta;
            this->dni = dni;
            this->saldo = saldo;
            this->estado = estado;
            this->fechaAlta.setearTodo(dia,mes,anio);        
        }


        int getNumTarjeta()const{return numTarjeta;}
        Fecha& getFechaAlta(){return fechaAlta;}
        int getDni()const{return dni;}
        float getSaldo()const{return saldo;}
        bool getEstado(){return estado;}
        int getCantidadViajesRealizados(){return cantidadViajesRealizados;}
        float getAcumuladorTotalGastado(){return acumuladorTotalGastado;}

        //metodos

        void Mostrar(){
            cout<<"Ingrese el numero de tarjeta: "; cout<<numTarjeta<<endl;
            cout<<"Fecha de alta: "; fechaAlta.mostrarFecha();
            cout<<"DNI: "; cout<<dni<<endl;
            cout<<"Saldo: "; cout<<saldo<<endl;
            //cout<<"Estado: "; cout<<estado<<endl;
        }

        void cargar(){
            cout<<"Numero de tarjeta: "; cin >> numTarjeta;
            cout<<"Fecha de alta: "<<endl;
            fechaAlta.cargar();
            cout<<"DNI: "; cin >> dni;
            cout<<"Saldo: "; cin >> saldo;
            setEstado(true);
        }


        //constructor
        Tarjetas(const int numTarjeta = 0, const int dni = 0, const float saldo = 0, const bool estado = false){
            this->numTarjeta = numTarjeta;
            this->dni = dni;
            this->saldo = saldo;
            this->estado = estado;
            fechaAlta.setearTodo(0,0,0);
        }
        Tarjetas(Tarjetas& obj){//este se uso para el punto I
            this->numTarjeta = obj.numTarjeta;
            this->fechaAlta = obj.fechaAlta;
            this->dni = obj.dni;
            this->saldo = obj.saldo;
            this->estado = obj.estado;
        }

        //destructor
        ~Tarjetas(){}
};
class ArchivoTarjetas{

    private:
        char nombre[30];
    public:
        //setters y getters
        void setNombre(const char *nombre){strcpy(this->nombre, nombre);}
        const char* getNombre(){return nombre;}

        //constructor
        ArchivoTarjetas(const char *nombre = "Tarjetas.dat"){
            strcpy(this->nombre, nombre);
        }


          void crearArchivo(int tam=20){
            Tarjetas obj;
            FILE *p;
            p = fopen(nombre,"wb");
            if(p==NULL){
                cout << "No se pudo abrir el archivo crearArchivo" << endl;
                exit(1);
            }

            for(int i=0; i<tam; i++){
            obj.cargar();
            cout<<endl;
            fwrite(&obj, sizeof(Tarjetas), 1, p);
            }

            fclose(p);
        }

        void cargarArchivo(int tam=1){
            Tarjetas objE;
            FILE *p;
            p = fopen(nombre,"ab");
            if(p==NULL){
                cout << "No se pudo abrir el archivo crearArchivo" << endl;
                exit(1);
            }

            for(int i=0; i<tam; i++){
            objE.cargar();
            cout<<endl;
            fwrite(&objE, sizeof(Tarjetas), 1, p);
            }

            fclose(p);
        }

        int contarRegistros(const char* nombre="Tarjetas.dat"){
                FILE *p;
                p=fopen(nombre, "rb");
                if(p==NULL) return -1;
                fseek(p, 0,2);
                int tam=ftell(p);
                fclose(p);
                return tam/sizeof(Tarjetas);
            }
        
        void listarArchivo(){
            Tarjetas reg;
            int tam = contarRegistros();  //si el contarRegistros esta FUERA de la clase
            for(int i=0; i<tam; i++){
                reg = leerRegistro(i);
                if(reg.getEstado()==true){
                reg.Mostrar();
                cout<<endl;
                }
            }
        }

        Tarjetas leerRegistro(int pos){
                Tarjetas reg;
                FILE *p;
                p=fopen(nombre, "rb");
                if(p==NULL) return reg;
                fseek(p, sizeof reg*pos,0);
                fread(&reg, sizeof reg,1, p);
                fclose(p);
                return reg;
            }

        void GuardarArchivo(Tarjetas& obj, const char *nombre="Tarjetas.dat"){
           FILE *p;
           p = fopen(nombre,"ab");
           if(p == NULL){
              cout<<"No se pudo abrir el archivo";
           }
           fwrite(&obj,sizeof(Tarjetas),1,p);
           fclose(p);
        }

        void BorrarArchivo(const char* nombre="Tarjetas.dat"){
           FILE *p;
           p = fopen(nombre,"wb");
           if(p == NULL){
              cout<<"No se pudo borrar el archivo";
           }
           fclose(p);
        }

        bool reemplazarRegistro(Tarjetas reg, int posicionAReemplazar){
            FILE *p = fopen("Tarjetas.dat", "rb+");
            if (p == NULL){return false;}
            fseek(p, posicionAReemplazar * sizeof(Tarjetas), SEEK_SET);
            bool pudoEscribir = fwrite(&reg, sizeof(Tarjetas), 1, p);
            fclose(p);
            return pudoEscribir;
}
};
class Viajes{

    private:
        int NumeroDeViaje;
        int NumeroDeTarjeta;
        int MedioDeTransporte;
        Fecha FechadeViaje;
        float importedeViaje;
        bool estado;

    
    public:
        //setters y getters
        
        void setNumeroDeViaje(const int NumeroDeViaje){this->NumeroDeViaje = NumeroDeViaje;}
        void setNumeroDeTarjeta(const int NumeroDeTarjeta){this->NumeroDeTarjeta = NumeroDeTarjeta;}
        void setMedioDeTransporte(const int MedioDeTransporte){if((MedioDeTransporte==1)||(MedioDeTransporte==2)||(MedioDeTransporte==3)) this->MedioDeTransporte = MedioDeTransporte;}
        void setFechadeViaje(const Fecha FechadeViaje){this->FechadeViaje = FechadeViaje;}
        void setImportedeViaje(const float importedeViaje){this->importedeViaje = importedeViaje;}
        void setEstado(const bool estado){this->estado = estado;}

        
        int getNumeroDeViaje()const{return NumeroDeViaje;}
        int getNumeroDeTarjeta()const{return NumeroDeTarjeta;}
        int getMedioDeTransporte()const{return MedioDeTransporte;}
        Fecha& getFechadeViaje(){return FechadeViaje;}
        float getImportedeViaje()const{return importedeViaje;}
        bool getEstado()const{return estado;}

        //constructor
        Viajes(int numViaje = 0, int numTarjeta = 0, int medTrans = 0, Fecha f = Fecha(), float importe = 0.0, bool estado = false) :
            NumeroDeViaje(numViaje), NumeroDeTarjeta(numTarjeta), MedioDeTransporte(medTrans), FechadeViaje(f), importedeViaje(importe), estado(estado) {}
        
        //destructor
        ~Viajes(){}

        //metodos
        void mostrar(){
            cout << "Numero de Viaje: " << NumeroDeViaje << endl;
            cout << "Numero de Tarjeta: " << NumeroDeTarjeta << endl;
            cout << "Medio de Transporte: " << MedioDeTransporte << endl;
            FechadeViaje.mostrarFecha();
            cout << "Importe de Viaje: " << importedeViaje << endl;
            //cout << "Estado: " << estado << endl;        
        }
        
        void cargar(){
            cout << "Numero de Viaje: "; cin >> NumeroDeViaje;
            cout << "Numero de Tarjeta: "; cin >> NumeroDeTarjeta;
            cout << "Medio de Transporte(1 - Colectivo, 2 - Subte, 3 - Tren): "; cin >> MedioDeTransporte;
            FechadeViaje.cargar();
            cout << "Importe de Viaje: "; cin >> importedeViaje;
            estado = true;
        }
};

class ArchivoViajes{

    private:
        char nombre[30];
    public:
        //setters y getters
        void setNombre(const char *nombre){strcpy(this->nombre, nombre);}
        const char* getNombre(){return nombre;}
        //constructor
        ArchivoViajes(const char *nombre = "Viajes.dat"){
            strcpy(this->nombre, nombre);
        }

        void crearArchivo(int tam=20){
            Viajes obj;
            FILE *p;
            p = fopen(nombre,"wb");
            if(p==NULL){
                cout << "No se pudo abrir el archivo crearArchivo" << endl;
                exit(1);
            }

            for(int i=0; i<tam; i++){
            obj.cargar();
            cout<<endl;
            fwrite(&obj, sizeof(Viajes), 1, p);
            }

            fclose(p);
        }

        void GuardarArchivo(Viajes obj, const char *nombre="Viajes.dat"){
           FILE *p;
           p = fopen(nombre,"ab");
           if(p == NULL){
              cout<<"No se pudo abrir el archivo";
           }
           fwrite(&obj,sizeof(Viajes),1,p);
           fclose(p);
        }

        void listarArchivo(){
    
            Viajes reg;
            int tam = contarRegistros();  //si el contarRegistros esta FUERA de la clase
            for(int i=0; i<tam; i++){
                reg = leerRegistro(i); //si el leerRegistro esta FUERA de la clase
                if(reg.getEstado()==true){
                reg.mostrar();
                cout<<endl;
                }
            }
        }

        void BorrarArchivo(const char *nombre="Viajes.dat"){
           FILE *p;
           p = fopen(nombre,"wb");
           if(p == NULL){
              cout<<"No se pudo borrar el archivo";
           }
           fclose(p);
        }
        int contarRegistros(){
                FILE *p;
                p=fopen(nombre, "rb");
                if(p==NULL) return -1;
                fseek(p, 0,2);
                int tam=ftell(p);
                fclose(p);
                return tam/sizeof(Viajes);
            }

        Viajes leerRegistro(int pos){
                Viajes reg;
                FILE *p;
                p=fopen(nombre, "rb");
                if(p==NULL) return reg;
                fseek(p, sizeof reg*pos,0);
                fread(&reg, sizeof reg,1, p);
                fclose(p);
                return reg;
            }

    

        void cargarArchivo(int tam=1){
            Viajes obj;
            FILE *p;
            p = fopen(nombre,"ab");
            if(p==NULL){
                cout << "No se pudo abrir el archivo crearArchivo" << endl;
                exit(1);
            }

            for(int i=0; i<tam; i++){
            obj.cargar();
            cout<<endl;
            fwrite(&obj, sizeof(Tarjetas), 1, p);
            }

            fclose(p);
        }

        bool reemplazarRegistro(Viajes reg, int posicionAReemplazar){
            FILE *p = fopen("Viajes.dat", "rb+");
            if (p == NULL){return false;}
            fseek(p, posicionAReemplazar * sizeof(Viajes), SEEK_SET);
            bool pudoEscribir = fwrite(&reg, sizeof(Viajes), 1, p);
            fclose(p);
            return pudoEscribir;
        }    

        
        


};


void puntoA(){

    int valorNumTarj=0;

    cout<<"ingrese el numero de tarjeta: "; cin>>valorNumTarj;

    Tarjetas objT;
    ArchivoTarjetas ARobjT;

    Viajes objV;
    ArchivoViajes ARobjV;

    int indice=0;

    int anioActual=(objV.getFechadeViaje().getAnioActual()-1);

    int vec[3]={0};

    int tam1 = ARobjT.contarRegistros();
    int tam2 = ARobjV.contarRegistros();

    for(int i = 0; i<tam1; i++){
        objT = ARobjT.leerRegistro(i);

        if(objT.getEstado()==true){

            for(int x = 0; x<tam2; x++){
                objV = ARobjV.leerRegistro(x);
                
                if((objV.getEstado()==true)&&(objT.getNumTarjeta() == objV.getNumeroDeTarjeta()) && (objV.getMedioDeTransporte()==1) && (objV.getFechadeViaje().getAnio() == anioActual)){
                    vec[0]++;
                }

                if((objV.getEstado()==true)&&(objT.getNumTarjeta() == objV.getNumeroDeTarjeta())  && (objV.getMedioDeTransporte()==2) && (objV.getFechadeViaje().getAnio() == anioActual)){
                    vec[1]++;
                }

                if((objV.getEstado()==true)&&(objT.getNumTarjeta() == objV.getNumeroDeTarjeta())  && (objV.getMedioDeTransporte()==3) && (objV.getFechadeViaje().getAnio() == anioActual)){
                    vec[2]++;
                }
            }

            indice++;

            if(valorNumTarj==objT.getNumTarjeta()){
                cout<<"indice: "<<indice<<endl;
                cout<<"Medio de transporte 1: "<<vec[0]<<endl;
                cout<<"Medio de transporte 2: "<<vec[1]<<endl;
                cout<<"Medio de transporte 3: "<<vec[2]<<endl;
                cout<<endl;
            }
            LimpiarVector(vec);


        }

    }
}


void puntoB(){
    //b)El viaje con menor importe. Mostrar todo el registro
    Viajes objV;
    ArchivoViajes ARobjV;

    float menorImporte;
    int indice;

    int tam = ARobjV.contarRegistros();//fseek y el ftell estan en la clase

    for(int i = 0; i<tam; i++){
        objV = ARobjV.leerRegistro(i);

        if(objV.getEstado()==true){
            if(i == 0){
                menorImporte = objV.getImportedeViaje();     
                indice = i;      
            }else if(objV.getImportedeViaje() < menorImporte){
                menorImporte = objV.getImportedeViaje();           
                indice = i;
            }
        }    
    }   

    cout << "El  registro con menor importe es: " << endl;
    objV = ARobjV.leerRegistro(indice);
    objV.mostrar();
}


void puntoC(){
    Viajes objV;
    ArchivoViajes ARobjV;
    int anioActual = objV.getFechadeViaje().getAnioActual();

    int vecMesRecaudacion[12] = {0};
    int tam = ARobjV.contarRegistros();

    //COMPLETO EL VECTOR CON LOS VALORES DEL MES DE CADA VIAJE
    for (int i = 0; i < tam; i ++){
        objV = ARobjV.leerRegistro(i);
        if(objV.getEstado()==true){
                //2024      >   2023
            if((anioActual != objV.getFechadeViaje().getAnio()) && (objV.getMedioDeTransporte() == 2)){  //objV.getFechadeViaje().getAnio() < anioActual
                vecMesRecaudacion[objV.getFechadeViaje().getMes()-1] += objV.getImportedeViaje();  
            }
        }
    }

    int posicionMaximo = 0;
    for(int i = 1; i < 12; i++){
        if(vecMesRecaudacion[i] > vecMesRecaudacion[posicionMaximo]){
            posicionMaximo = i;
        }
    }

    cout << "EL MES CON MAYOR RECAUDACION ES: " << posicionMaximo+1 << " - La recaudacion fue de $" << vecMesRecaudacion[posicionMaximo]<<  endl;
}

void borrarArchivoPundoD(){
    FILE *p = fopen("ViajesAnioActual.dat", "wb");
    fclose(p);
}

void puntoD(){
    borrarArchivoPundoD();
    Viajes objV;
    ArchivoViajes ARobjV;
    int tam = ARobjV.contarRegistros();
    int anioActual = objV.getFechadeViaje().getAnioActual();

    for (int i = 0; i < tam; i ++){
        objV = ARobjV.leerRegistro(i);
        if (objV.getEstado() == true){
            if(anioActual == objV.getFechadeViaje().getAnio()){
                // FILE *p = fopen("ViajesAnioActual.dat", "ab");
                // if(p == NULL){cout<<"No se pudo abrir el archivo";exit(1);}
                // fwrite(&objV ,sizeof(Viajes) ,1 , p);
                // fclose(p);

                ARobjV.GuardarArchivo(objV);

            }
        }
    }

    cout << "REGISTRO DE VIAJES DEL ANIO ACTUAL" << endl;
    ARobjV.listarArchivo();

    // FILE *p = fopen("ViajesAnioActual.dat","rb");
    // if(p == NULL){cout<<"No se pudo abrir el archivo";exit(1);}

    // while(fread(&objV, sizeof(Viajes), 1, p) == true){
    //     objV.mostrar();
    //     cout<<endl;
    // }
}


void puntoE(){
    Viajes objV;
    ArchivoViajes ARobjV;
    int numTarjeta;
    int tam = ARobjV.contarRegistros();

    int *vecAnioAcumulaViajes;
    int calc = objV.getFechadeViaje().getAnioActual() - 2019;  // 2024 - 2019 = 5 por que incluye el 2020
    cout<<calc<<endl;
    vecAnioAcumulaViajes = new int [calc];

    LimpiarVector(vecAnioAcumulaViajes,calc,0);

    cout << "Ingrese un numero de tarjeta para saber la cantidad de viajes que realizo en cada año: " << endl;
    cin >> numTarjeta;
    for (int i = 0; i < tam; i ++){
        objV = ARobjV.leerRegistro(i);
        if((objV.getNumeroDeTarjeta() == numTarjeta) && (objV.getEstado() == true)){
            vecAnioAcumulaViajes[objV.getFechadeViaje().getAnio() - 2020] ++;
        }
    }

    for(int i = 0; i < calc; i ++){
        cout << 2020+i << " - Cantidad de viajes: " << vecAnioAcumulaViajes[i] << endl;
    }

    delete [] vecAnioAcumulaViajes;

}


void puntoF(){
    Tarjetas objT;
    ArchivoTarjetas ARobjT;

    Viajes objV;
    ArchivoViajes ARobjV;

    int mayorImporte, maxIndice;
    int tam = ARobjT.contarRegistros();
    int tam2 = ARobjV.contarRegistros();
    for(int i = 0; i < tam; i ++){
        objT = ARobjT.leerRegistro(i);
        for(int j = 0; j < tam2; j ++){
            objV = ARobjV.leerRegistro(j);
            if((objT.getEstado() == true)&&(objV.getEstado() == true)&&(objT.getNumTarjeta() == objV.getNumeroDeTarjeta())){
                if(j == 0){
                    mayorImporte = objV.getImportedeViaje();
                    maxIndice = j;
                }else if(objV.getImportedeViaje() > mayorImporte){
                    mayorImporte = objV.getImportedeViaje();
                    maxIndice = j;
                }                   
        } 
    }
}
    cout << "REGISTRO CON EL VIAJE DE MAYOR IMPORTE: " << endl;
    objV = ARobjV.leerRegistro(maxIndice);
    objV.mostrar();
}


void puntoG(){
    Viajes objV;
    ArchivoViajes ARobV;
    int anioActual = objV.getFechadeViaje().getAnioActual();
    int menorRecaudacion, menorMesRecaudado;

    int tam = ARobV.contarRegistros();
    for(int i = 0; i < tam; i ++){
        objV = ARobV.leerRegistro(i);
        if(objV.getEstado() == true){
            if((objV.getFechadeViaje().getAnio() < anioActual) && (objV.getMedioDeTransporte() == 3)){
                if(i == 0){
                    menorRecaudacion = objV.getImportedeViaje();
                    menorMesRecaudado = objV.getFechadeViaje().getMes();
                }else if(objV.getImportedeViaje() < menorRecaudacion){
                    menorRecaudacion = objV.getImportedeViaje();
                    menorMesRecaudado = objV.getFechadeViaje().getMes();
                }
            } 
        }    
    }

    cout << "EL MES DE MENOR RECAUDACION POR VIAJES EN TREN ES: " << menorMesRecaudado << " CON UNA RECAUDACION DE: " << menorRecaudacion << endl;
}

//tarjeta de tarjeta => si esta en tarjeta de viajes => mostrar en colectivo (1) cantidad de viajes en el año pasado
void puntoH(){
    Tarjetas objT;//no es necesario, solo para validar
    Viajes objV;
    ArchivoTarjetas ARobjT;
    ArchivoViajes ARobjV;

    int anioAnterior = objT.getFechaAlta().getAnioActual() - 1;

    int tam1 = ARobjT.contarRegistros();
    int tam2 = ARobjV.contarRegistros();

    for(int i = 0; i < tam1; i ++){ // indice [0] = tarjeta 5, indice [1] = tarjeta 10, indice [2] = tarjeta 15
        objT = ARobjT.leerRegistro(i);  
        
        int auxContador = 0;
        for(int j = 0; j < tam2; j ++){
            objV = ARobjV.leerRegistro(j);
            if((objT.getEstado() == true)&&(objV.getEstado() == true)&&(objT.getNumTarjeta() == objV.getNumeroDeTarjeta()) && (objV.getFechadeViaje().getAnio() == anioAnterior) && (objV.getMedioDeTransporte() == 1)){
                auxContador ++;
                
            }                
        }

        cout << "NUMERO DE TARJETA: " << objT.getNumTarjeta() << " CANT DE VIAJES: " << auxContador << endl;
    }

}


void puntoI(){
    Viajes objV; //numero de tarjeta y menor importe
    Tarjetas objT;//y ahora en el paso 2 accedo al DNI del dueño
    Tarjetas objT2;
    ArchivoViajes ARobjV;
    ArchivoTarjetas ARobjT;

    int menorImporte, indiceMenorImporte;;
    int tam = ARobjV.contarRegistros();
    for(int i = 0; i < tam; i ++){
        objV = ARobjV.leerRegistro(i);
        if(objV.getEstado() == true){
            if(i == 0){
                menorImporte = objV.getImportedeViaje();
                indiceMenorImporte = i;
            }else if(objV.getImportedeViaje() < menorImporte){
                menorImporte = objV.getImportedeViaje();
                indiceMenorImporte = i;
            }
        }
    }

    //objV en memoria momentaneamete
    objV = ARobjV.leerRegistro(indiceMenorImporte);// leerIndice o buscarID => tengo el indice del registro con menor importe de viaje

    int tam2 = ARobjT.contarRegistros(); //los indices del archivo 
    bool bandera = false;
    for (int i = 0; i < tam2; i++){
        objT = ARobjT.leerRegistro(i);
        if(objV.getEstado()== true){
            if(objV.getNumeroDeTarjeta() == objT.getNumTarjeta()){//solamente inequivocamente habra 1 solo
               if(!bandera){
                   bandera = true;
                   objT2.setearTodo(objT.getNumTarjeta(), objT.getDni(), objT.getSaldo(),objT.getEstado(), objT.getFechaAlta().getDia(), objT.getFechaAlta().getMes(), objT.getFechaAlta().getAnio()); 
                   //objT2 = objT;
               } 
                cout << "NUMERO DE TARJETA: " << objT.getNumTarjeta() << " DNI: " << objT.getDni() << " -> El menor importe es: $" << objV.getImportedeViaje() << endl;
            }  
        }
    }

    cout << endl << "GUARDANDO EN UN OBJETO AUXILIAR PARA MANIPULARLO COMO QUIERO: " << endl;
    cout << "NUMERO DE TARJETA: " << objT2.getNumTarjeta() << " DNI: " << objT2.getDni() << " -> El menor importe es: $" << objV.getImportedeViaje() << endl;
}


void puntoJ(){
    Tarjetas objT;//numTarjeta, fechaAlta dni, saldo, estado, 
    ArchivoTarjetas ARobjT;
    Viajes objV; //numViaje, numTarjeta, medTrans, fecha del viaje, importe, estado
    ArchivoViajes ARobjV;
    
    int tam1 = ARobjT.contarRegistros();
    int tam2 = ARobjV.contarRegistros();
    float acumuladorPorAnioTarjetaActual;
    int anioActual = objV.getFechadeViaje().getAnioActual();
    
    for(int i = 0; i < tam1; i ++){
        objT = ARobjT.leerRegistro(i);
        acumuladorPorAnioTarjetaActual = 0.0;
        for(int x = 0; x < tam2; x++){
            objV = ARobjV.leerRegistro(x);
            if((objV.getNumeroDeTarjeta() == objT.getNumTarjeta()) && (objV.getFechadeViaje().getAnio() == anioActual) && (objV.getEstado() == true) && (objT.getEstado() == true)){
                acumuladorPorAnioTarjetaActual += objV.getImportedeViaje();
            }
        }
        cout << "NUMERO DE TARJETA #" << objT.getNumTarjeta() << " -> Anio actual: " << anioActual << " -> IMPORTE TOTAL $" << acumuladorPorAnioTarjetaActual << endl;
    }
}

void mostrarArchivoPuntoK(){
    Tarjetas objT;
    FILE *p;
    p = fopen("PuntoK.dat","rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        exit(1);
    }

    while (fread(&objT, sizeof(Tarjetas), 1, p) == true){
        cout << "NUMERO DE TARJETA:" << objT.getNumTarjeta()<<endl;
        cout<< "DNI:" <<objT.getDni()<<endl;
        cout<< "CANTIDAD DE VIAJES:" <<objT.getCantidadViajesRealizados()<<endl;
        cout << endl;
}

    fclose(p);
}

/*
15 - K) Generar un archivo para registrar por cada n├║mero de tarjeta la cantidad de viajes realizados encolectivos el a├▒o pasado. 
Cada registro debe tener el n├║mero de tarjeta, el DNI del due├▒o y la cantidad de viajes.
*/

void puntoK(){
    Tarjetas objT;//numTarjeta, fechaAlta dni, saldo, estado, puntoK(cantidad de viajes)
    ArchivoTarjetas ARobjT;
    ARobjT.BorrarArchivo("PuntoK.dat"); //borra por si llamo muchas veces a la funcion
    Viajes objV; //numViaje, numTarjeta, medTrans(1 - Colectivo, 2 - Subte, 3 - Tren), fecha del viaje, importe, estado
    ArchivoViajes ARobjV;
    //tarjeta 5(PK) en T con su dni => voy a V y cuento los viajes en el anio pasado

    int tam1 = ARobjT.contarRegistros();
    int tam2 = ARobjV.contarRegistros();
    int anioPasado = objV.getFechadeViaje().getAnioActual() -1;
    int contadorCantidadViajesPorTarjeta;

    for (int i = 0; i < tam1; i ++){
        objT = ARobjT.leerRegistro(i);
        if(objT.getEstado() == true){
           //contadorCantidadViajesPorTarjeta = 0;
           for(int j = 0; j < tam2; j++){
                objV = ARobjV.leerRegistro(j);
                if((objV.getEstado() == true)&&(objV.getFechadeViaje().getAnio() == anioPasado)){
                    if((objT.getNumTarjeta() == objV.getNumeroDeTarjeta() && (objV.getMedioDeTransporte() == 1))){
                        contadorCantidadViajesPorTarjeta ++;
                    }
                }
            }
            
            objT.setCantidadViajesRealizados(contadorCantidadViajesPorTarjeta);//todos los otros atributos ya estan 
            ARobjT.GuardarArchivo(objT,"PuntoK.dat");
        }
        contadorCantidadViajesPorTarjeta = 0;
    }
    mostrarArchivoPuntoK();    
}

void mostrarArchivoPuntoL(){
    cout << "MOSTRANDO PUNTO L" << endl;
    Tarjetas objT;
    FILE *p = fopen("PuntoL.dat","rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        exit(1);
    }

    while (fread(&objT, sizeof(Tarjetas), 1, p) == 1){
        cout << "NUMERO DE TARJETA:" << objT.getNumTarjeta()<<endl;
        cout << "FECHA DE ALTA";
        objT.getFechaAlta().mostrarFecha();
        cout << "DNI:" <<objT.getDni()<<endl;
        cout << endl;
    }
    fclose(p);
}


bool existeDNIPuntoL(int dni){ 
   Tarjetas obj;
   FILE *p;
   p = fopen("PuntoL.dat","rb");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
   }
   while(fread(&obj,sizeof(Tarjetas),1,p)){
      if((obj.getDni()==dni)&&(obj.getEstado())){
         fclose(p);
         return true;
      }
   }
   fclose(p);
   return false;
}





//HACER REGISTRO => tarjetas sin usar este anio + estado true => objT.NumerodeTarjeta, objT.fechaAlta, objT.dniDuenio
void puntoL(){ 
    Tarjetas objT;//numTarjeta, fechaAlta dni, saldo, estado, puntoK(cantidad de viajes)
    ArchivoTarjetas ARobjT;
    ARobjT.BorrarArchivo("PuntoL.dat"); //borra por si llamo muchas veces a la funcion

    Viajes objV; //numViaje, numTarjeta, medTrans(1 - Colectivo, 2 - Subte, 3 - Tren), fecha del viaje, importe, estado
    ArchivoViajes ARobjV;

    int tam1 = ARobjT.contarRegistros();
    int tam2 = ARobjV.contarRegistros();

    int anioActual = objV.getFechadeViaje().getAnioActual(); 
    int mesActual = objV.getFechadeViaje().getMesActual();
    int diaActual = objV.getFechadeViaje().getDiaActual();
    Fecha fechaActual(anioActual, mesActual, diaActual); 

    //////bool bandera = false;
    for (int i = 0; i < tam1; i ++){
        objT = ARobjT.leerRegistro(i);
        for(int j = 0; j < tam2; j++){
            objV = ARobjV.leerRegistro(j);
            if((objT.getEstado() == true)&&(objV.getEstado() == true) && (objT.getNumTarjeta() == objV.getNumeroDeTarjeta()) && (anioActual > objV.getFechadeViaje().getAnio())){
                ///////objT => NUMERO DE TARJETA - FECHA DE ALTA - DNI"
                //////if(!bandera){
                    
                    if(! (existeDNIPuntoL(objT.getDni()) ) ){
                        ARobjT.GuardarArchivo(objT,"PuntoL.dat");
                    }   
                    

                   ////// bandera = true;
                //////}
            } 
        }
       ////// bandera = false;
   }
 
 mostrarArchivoPuntoL();

}


//tarjeta de Tarjeta => ahora en viajes lo corroboro => hago acumulador para esa tarjeta 
//filtro => anio actual de viajes
//muestro  de tarjeta => numero tarjeta dni, 
//muestro de viajes => importe total
void puntoLL(){
    FILE *p = fopen("PuntoLL.dat","wb");
    if(p == NULL){cout<<"No se pudo abrir el archivo"; exit(1);}
    fclose(p);
    
    Tarjetas objT;//numTarjeta, fechaAlta dni, saldo, estado, puntoK(cantidad de viajes) -> se agrega gasto total
    ArchivoTarjetas ARobjT;
    Viajes objV; //numViaje, numTarjeta, medTrans(1 - Colectivo, 2 - Subte, 3 - Tren), fecha del viaje, importe, estado
    ArchivoViajes ARobjV;

    int tam1 = ARobjT.contarRegistros();
    int tam2 = ARobjV.contarRegistros();
    int anioActual = objT.getFechaAlta().getAnioActual();
    int mesActual = objT.getFechaAlta().getMesActual();
    int diaActual = objT.getFechaAlta().getDiaActual();
    Fecha fechaActual(anioActual, mesActual, diaActual);
    float acumuladorTotalGastado;
    int indice = 0;
    bool bandera;

    for(int i = 0; i < tam1; i++){
        objT = ARobjT.leerRegistro(i);
        acumuladorTotalGastado = 0.0;
        bandera = false;
        for (int j = 0; j < tam2; j++){
            objV = ARobjV.leerRegistro(j);
           
            if((objT.getEstado() == true) && (objV.getEstado() == true) && (objT.getNumTarjeta() == objV.getNumeroDeTarjeta()) && (objV.getFechadeViaje().getAnio() == anioActual)){
                acumuladorTotalGastado += objV.getImportedeViaje(); cout << endl; 
                bandera = true;
            }                
        }
        if(bandera){ 
            objT.setAcumuladorTotalGastado(acumuladorTotalGastado);  
            FILE * p2 = fopen("PuntoLL.dat", "ab");
            if(p2==NULL){cout<<"No se pudo abrir el archivo"; exit(1);}
            fwrite(&objT, sizeof(Tarjetas), 1, p2);
            fclose(p2);  
        }
        
    }

    FILE *p3 = fopen("PuntoLL.dat", "rb");
    if(p3==NULL){cout<<"No se pudo abrir el archivo"; exit(1);}
    while(fread(&objT, sizeof(Tarjetas), 1, p3)){
        cout << "NUMERO DE TARJETA: " << objT.getNumTarjeta() << endl;
        cout << "DNI: " << objT.getDni() << endl;
        cout << "ACUMULADOR TOTAL GASTADO: " << objT.getAcumuladorTotalGastado() << endl;
        cout << endl;
    }
    fclose(p3);
}

//objT poner estado false en las que objT tenga saldo menor a -15000
void puntoM(){
    Tarjetas objT;//numTarjeta, fechaAlta dni, saldo, estado, puntoK(cantidad de viajes), Punto(LL) se agrega gasto total
    ArchivoTarjetas ARobjT;
   
    int tam1 = ARobjT.contarRegistros();

    for(int i = 0; i < tam1; i++){
        objT = ARobjT.leerRegistro(i);

        if(objT.getEstado() == true && objT.getSaldo() < 107000){
            objT.setEstado(false);
            if(ARobjT.reemplazarRegistro(objT, i)){
                cout << "Se dio BAJA LOGICA a la tarjeta: " << objT.getNumTarjeta() << endl;
            }
        }
    }    
}


//objT es para validar objV
//objV => ID numViaje => filtro por anio == 2020 => poner en falso
void puntoN(){//
    Tarjetas objT;//numTarjeta, fechaAlta dni, saldo, estado, puntoK(cantidad de viajes) -> se agrega gasto total
    ArchivoTarjetas ARobjT;
    Viajes objV; //numViaje, numTarjeta, medTrans(1 - Colectivo, 2 - Subte, 3 - Tren), fecha del viaje, importe, estado
    ArchivoViajes ARobjV;

    int tam1 = ARobjT.contarRegistros();
    int tam2 = ARobjV.contarRegistros();

    for(int i = 0; i < tam1; i++){
        objT = ARobjT.leerRegistro(i);
        
        for(int j = 0; j < tam2; j++){
            objV = ARobjV.leerRegistro(j);

            if((objT.getEstado() == true) && (objV.getEstado() == true) && (objT.getNumTarjeta() == objV.getNumeroDeTarjeta()) && (objV.getFechadeViaje().getAnio() == 2020)){
                objV.setEstado(false);
                if(ARobjV.reemplazarRegistro(objV, j)){
                    cout << "Se dio BAJA LOGICA al viaje: " << objV.getNumeroDeTarjeta() << endl;                
                }    
            }    
        }    
    }    
}


bool existeNumTartjetaPuntoO(int numTarjeta){ 
   Viajes obj;
   FILE *p;
   p = fopen("PuntoL.dat","rb");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
   }
   while(fread(&obj,sizeof(Tarjetas),1,p)){
      if((obj.getNumeroDeTarjeta()==numTarjeta)&&(obj.getEstado())){
         fclose(p);
         return true;
      }
   }
   fclose(p);
   return false;
}

void mostrarArchivoPuntoO(){
    cout << "MOSTRANDO PUNTO O" << endl;
    Viajes objV;
    FILE *p = fopen("Viajes2020PtoO.dat","rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        exit(1);
    }

    while (fread(&objV, sizeof(Viajes), 1, p) == 1){
       objV.mostrar();
       cout << endl;
    }
    fclose(p);
}

//crear archivo .bkp
//elimino con wb el .dat
//del bkp traigo solo lo que quiero al .dat
// O) Generar un archivo con todos los registros de viaje del año 2020, y luego dar de baja física en el archivo de viajes a los registros viajes de ese año." << endl;
void puntoO(){//de Viaje sacar registro del 2020 y ponerlos en archivo nuevo... Luego dar de baja fisica en el original a los viajes de 2020
    
    Tarjetas objT;//numTarjeta, fechaAlta dni, saldo, estado, puntoK(cantidad de viajes) -> se agrega gasto total
    ArchivoTarjetas ARobjT;
    Viajes objV; //numViaje, numTarjeta, medTrans(1 - Colectivo, 2 - Subte, 3 - Tren), fecha del viaje, importe, estado
    ArchivoViajes ARobjV;
    ARobjV.BorrarArchivo("Viajes2020PtoO.dat");

    int tam2 = ARobjV.contarRegistros();

    for(int i = 0; i < tam2; i++){
        objV = ARobjV.leerRegistro(i);
        if((objV.getEstado() == true)&&(objV.getFechadeViaje().getAnio() == 2020)){
            if(!(existeNumTartjetaPuntoO(objV.getNumeroDeTarjeta()))){
                ARobjV.GuardarArchivo(objV, "Viajes2020PtoO.dat");
            } 
        }
    }

    mostrarArchivoPuntoO();
}


//cout << "21 - P) Sumar al saldo de las tarjetas con viajes en el presente año $1000." << endl;
void puntoP(){ //objT numTarjeta validarlo con objV num tarjeta => viajes de objV del prestente => objT sumar 1000 al saldo
    Tarjetas objT;//numTarjeta, fechaAlta dni, saldo, estado, puntoK(cantidad de viajes) -> se agrega gasto total
    ArchivoTarjetas ARobjT;
    Viajes objV; //numViaje, numTarjeta, medTrans(1 - Colectivo, 2 - Subte, 3 - Tren), fecha del viaje, importe, estado
    ArchivoViajes ARobjV;

    int tam1 = ARobjT.contarRegistros();
    int tam2 = ARobjV.contarRegistros();
    int anioActual = objT.getFechaAlta().getAnioActual();
    int sumaSaldo = 1000;
    bool bandera = false;

    for(int i = 0; i < tam1; i++){
        objT = ARobjT.leerRegistro(i);
        bandera = false;
        for(int j = 0; j < tam2; j++){
            objV = ARobjV.leerRegistro(j);

            if(!bandera){
                if((objT.getEstado() == true)&&(objV.getEstado() == true)&&(objT.getNumTarjeta() == objV.getNumeroDeTarjeta())&&(objV.getFechadeViaje().getAnio() == anioActual)){
                    cout << "TARJETA ACTUAL " << objT.getNumTarjeta() << " -> SALDO ACTUAL " << objT.getSaldo() << endl;
                    objT.setSaldo(objT.getSaldo() + sumaSaldo);
                    cout << "              " << " " << " -> SALDO NUEVO " << objT.getSaldo() << endl;
                    bandera = true;
                }    
            }
        }    
    }    
}

// "22 - Q) Sumar al saldo de las tarjetas el importe del IVA del mes de agosto. El porcentaje de IVA es del 21%." << endl;
void puntoQ(){
    Tarjetas objT;//numTarjeta, fechaAlta dni, saldo, estado, puntoK(cantidad de viajes) -> se agrega gasto total
    ArchivoTarjetas ARobjT;

    int tam1 = ARobjT.contarRegistros();

    cout << "Listar sin modificar el saldo" << endl;
    ARobjT.listarArchivo();

    cout << "Listar con el saldo modificado" << endl;
    for(int i = 0; i < tam1; i++){
        objT = ARobjT.leerRegistro(i);

        if(objT.getEstado() == true){
            objT.setSaldo(objT.getSaldo() * 1.21);
            objT.Mostrar(); 
            //ARobjT.reemplazarRegistro(objT, i);           
        }    
    }
}



void Menu(){
    Tarjetas objT;
    ArchivoTarjetas ARobjT;
    Viajes objV;
    ArchivoViajes ARobjV;
    int opc;

while(true){
    system("cls");
        cout << "MENU" << endl;
        cout << "1 - Cargar Tarjeta" << endl;
        cout << "2 - Listar Tarjetas" << endl;
        cout << "3 - Cargar Viajes" << endl;
        cout << "4 - Listar Viajes" << endl;
        cout << "------------PARTE 1-----------------" << endl;
        cout << "5 - a)Informar para un numero de tarjeta que se ingresa por teclado la cantidad de viajes realizados en cada uno de los medios de transporte el anio pasado" << endl;
        cout << "6 - b)El viaje con menor importe. Mostrar todo el registro." << endl;
        cout << "7 - c)El mes de mayor recaudacion por viajes en subte entre todos los anios, sin tener en cuenta el anioo actual." << endl;
        cout << "8 - d)Generar un archivo con los registros de los viajes del anio actual." << endl;
        cout << "------------PARTE 2-----------------" << endl;
        cout << "9 - e) Informar para un numero de tarjeta que se ingresa por teclado la cantidad de viajes realizados en cada uno de los años transcurridos" << endl;
        cout << "10 - f) El viaje con mayor importe. Mostrar todo el registro." << endl;
        cout << "11 - g) El mes de menor recaudacion por viajes en tren entre todos los anios, sin tener en cuenta el anio actual." << endl;
        cout << "------------PARTE 3-----------------" << endl;
        cout << "12 - h) Informar para CADA numero de tarjeta la cantidad de viajes realizados en colectivos el anio pasado." << endl;
        cout << "13 - i) El viaje con menor importe. Mostrar el número de tarjeta y el DNI del duenio." << endl;
        cout << "14 - j) Informar para cada una de las tarjetas el importe total gastado por viajes el año actual." << endl;
        cout << "------------PARTE 4-----------------" << endl;
        cout << "15 - K) Generar un archivo para registrar por cada número de tarjeta la cantidad de viajes realizados en";
        cout << "colectivos el año pasado. Cada registro debe tener el número de tarjeta, el DNI del dueño y la cantidad de viajes." << endl;
        cout << "16 - L) Generar un archivo con las tarjetas que no hayan sido utilizadas este año y que estén activas. Cada registro debe tener el siguiente formato:";
        cout << " -> Número de tarjeta, fecha de alta y DNI del dueño." << endl;
        cout << "17 - LL) Generar un archivo para registrar por cada una de las tarjetas el importe total gastado por viajes el año actual.";
        cout << "Cada registro debe tener el número de tarjeta, el DNI del dueño y el importe por los viajes" << endl;
        cout << "------------PARTE 5-----------------" << endl;
        cout << "18 - M) Dar de baja logica a las tarjetas que tengan un saldo negativo menor a -15000." << endl;
        cout << "19 - N) Dar de baja a todos los viajes del año 2020." << endl;
        cout << "20 - O) Generar un archivo con todos los registros de viaje del año 2020, y luego dar de baja física en el";
        cout << "archivo de viajes a los registros viajes de ese año." << endl;
        cout << "21 - P) Sumar al saldo de las tarjetas con viajes en el presente año $1000." << endl;
        cout << "22 - Q) Sumar al saldo de las tarjetas el importe del IVA del mes de agosto. El porcentaje de IVA es del 21%." << endl;



        cout << "0 - Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin>>opc;
    system("cls");
        switch (opc)
        {
        /*******************************/
        case 1:{
            ARobjT.crearArchivo(); //si quiero cambiar el tam de omision 20 le pongo otro numero
        }break;
        /*******************************/
        case 2:{
            ARobjT.listarArchivo();
        }break;
        /*******************************/
        case 3:{
            ARobjV.crearArchivo();
        }break;
        /*******************************/
        case 4:{
            ARobjV.listarArchivo();
        }break;
        /*******************************/
        case 5:{
            puntoA();
        }break;
        /*******************************/
        case 6:{
            puntoB();
        }break;
        /*******************************/
         case 7:{
            puntoC();
        }break;
        /*******************************/
        case 8:{
            puntoD();
        }break;
        /*******************************/
        case 9:{
            puntoE();
        }break;
        /*******************************/
        case 10:{
            puntoF();            
        }break;
        /*******************************/
        case 11:{
            puntoG();            
        }break;
        /*******************************/
        case 12:{
            puntoH();
        }break;
        /*******************************/
        case 13:{
            puntoI();
        }break;
        /*******************************/
        case 14:{
            puntoJ();
        }break;
        /*******************************/
        case 15:{
            puntoK();
        }break;
        /*******************************/
        case 16:{
            puntoL();
        }break;  
        /*******************************/
           case 17:{
            puntoLL();
        }break;   
        /*******************************/
        case 18:{
            puntoM();    
        }break; 
         /*******************************/
        case 19:{
            puntoN();    
        }break; 
        /*******************************/
         case 20:{
            puntoO();    
        }break; 
        /*******************************/
         case 21:{
            puntoP();    
        }break; 
        /*******************************/
         case 22:{
            puntoQ();
         }break;

        default:{

        }break;
        /*******************************/
        }
        system("pause");

    }
}


int main(){

   Menu();





    return 0;
}