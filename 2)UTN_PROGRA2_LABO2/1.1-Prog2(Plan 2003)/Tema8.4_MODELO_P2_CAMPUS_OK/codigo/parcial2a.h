///Ejercicio: Parcial 2 de Programaci�n II
///Autor:DEK
///Fecha:13/07/2022
///Comentario:

void cargarCadena(char *pal, int tam){
    int i;
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
    int dia,mes, anio;
public:
    void Cargar(){
        cout<<"DIA: "; cin>>dia;
        cout<<"MES: "; cin>>mes;
        cout<<"ANIO: "; cin>>anio;
    }
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};

class Obra{
private:
    char codigoObra[5];
    char direccion[30];
    int provincia;
    float superficie;
    int estadoEjecucion;
    bool activo;
public:
    void Cargar(){
        cargarCadena(codigoObra,4);
        cargarCadena(direccion,29);
        cin>>provincia;
        cin>>superficie;
        cin>>estadoEjecucion;
        activo=true;
    }

    void Mostrar(){
        cout<<codigoObra<<endl;
        cout<<direccion<<endl;
        cout<<provincia<<endl;
        cout<<superficie<<endl;
        cout<<estadoEjecucion<<endl;
    }

    const char* getCodigoObra(){return codigoObra;}
    const char* getDireccion(){return direccion;}
    int getProvincia(){return provincia;}
    int getEstadoEjecucion(){return estadoEjecucion;}
    float getSuperficie(){return superficie;}
    bool getActivo(){return activo;}

    void setCodigoObra(const char *co){strcpy(codigoObra, co);}
    void setDireccion(const char *d){strcpy(direccion,d);}
    void setProvincia(int p){provincia=p;}
    void setEstadoEjecucion(int e){estadoEjecucion=e;}
    void setSuperficie(float s){superficie=s;}
    void setActivo(bool a){activo=a;}
//SOBRE CARGA DE OPERADORES
bool operator==(float s);


};

class ArchivoObras{
    private:
        char nombre[30];
    public:
        ArchivoObras(const char *n){
            strcpy(nombre,n);
        }
        Obra leerRegistro(int pos){
            Obra reg;
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return reg;
            }
            fseek(p, pos * sizeof reg, 0);
            fread(&reg, sizeof reg, 1, p);
            fclose(p);
            return reg;
        }
        int contarRegistros(){
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            fseek(p, 0, 2);
            int cant=ftell(p)/sizeof(Obra);
            fclose(p);
            return cant;
        }
        bool grabarRegistro(Obra reg){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
};

class Material{
private:
    int codigoMaterial;
    char nombre[30];
    char marca[30];
    int tipo;
    float pu;
    bool activo;
public:
    void Cargar(){
        cin>>codigoMaterial;
        cargarCadena(nombre,29);
        cargarCadena(marca,29);
        cin>>tipo;
        cin>>pu;
        activo=true;
    }
    void Mostrar(){
        cout<<codigoMaterial<<endl;
        cout<<nombre<<endl;
        cout<<marca<<endl;
        cout<<tipo<<endl;
        cout<<pu<<endl;
    }
    int getCodigoMaterial(){return codigoMaterial;}
    int getTipo(){return tipo;}
    const char *getNombre(){return nombre;}
    const char *getMarca(){return marca;}
    float getPU(){return pu;}
    bool getActivo(){return activo;}

    void setCodigoMaterial(int cm){codigoMaterial=cm;}
    void setTipo(int t){tipo=t;}
    void setNombre(const char *m){strcpy(nombre,m);}
    void setMarca(const char *m){strcpy(marca,m);}
    void setPU(float p){pu=p;}
    void setActivo(bool a){activo=a;}
};

class ArchivoMateriales{
    private:
        char nombre[30];
    public:
        ArchivoMateriales(const char *n){
            strcpy(nombre, n);
        }
        Material leerRegistro(int pos){
            Material reg;
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return reg;
            }
            fseek(p, pos * sizeof reg, 0);
            fread(&reg, sizeof reg, 1, p);
            fclose(p);
            return reg;
        }
        int contarRegistros(){
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            fseek(p, 0, 2);
            int cant=ftell(p)/sizeof(Material);
            fclose(p);
            return cant;
        }
        bool grabarRegistro(Material reg){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
};

class Compra{
private:
    int numeroCompra, numeroProveedor, codigoMaterial;
    char codigoObra[5];
    int cantidad;
    float importe;
    Fecha fechaCompra;
    bool activo;
public:
    void Cargar(){
        cout<<"Numero de compra: ";cin>>numeroCompra;
        cout<<"Numero de proveedor: ";cin>>numeroProveedor;
        cout<<"Codigo de material: ";cin>>codigoMaterial;
        cout<<"Codigo de obra: ";cargarCadena(codigoObra,4);
        cout<<"Cantidad: ";cin>>cantidad;
        cout<<"Importe: ";cin>>importe;
        cout<<"Fecha: "<<endl;
        fechaCompra.Cargar();
        activo=true;
    }

    void Mostrar(){
        cout<<"Numero de compra: "<<numeroCompra<<endl;
        cout<<"Numero de proveedor: "<<numeroProveedor<<endl;
        cout<<"Codigo de material: "<<codigoMaterial<<endl;
        cout<<"Codigo de obra: "<<codigoObra<<endl;
        cout<<"Cantidad: "<<cantidad<<endl;
        cout<<"Importe: "<<importe<<endl;
        fechaCompra.Mostrar();
        cout<<endl;
    }
    int getNumeroCompra(){return numeroCompra;}
    int getNumeroproveedor(){return numeroProveedor;}
    int getCodigoMaterial(){return codigoMaterial;}
    int getCantidad(){return cantidad;}
    float getImporte(){return importe;}
    Fecha getFechaCompra(){return fechaCompra;}
    const char *getCodigoObra(){return codigoObra;}
    bool getActivo(){return activo;}

    void setNumeroCompra(int nc){numeroCompra=nc;}
    void setNumeroproveedor(int np){numeroProveedor=np;}
    void setCodigoMaterial(int cm){codigoMaterial=cm;}
    void setCantidad(int c){cantidad=c;}
    void setImporte(float i){importe=i;}
    void setFechaCompra(Fecha f){fechaCompra=f;}
    void setCodigoObra(const char *co){strcpy(codigoObra,co);}
    void setActivo(bool a){activo=a;}
};

class ArchivoCompras{
    private:
        char nombre[30];
    public:
        ArchivoCompras(const char *n){
            strcpy(nombre, n);
        }
        Compra leerRegistro(int pos){
            Compra reg;
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return reg;
            }
            fseek(p, pos * sizeof reg, 0);
            fread(&reg, sizeof reg, 1, p);
            fclose(p);
            return reg;
        }
        int contarRegistros(){
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            fseek(p, 0, 2);
            int cant=ftell(p)/sizeof(Compra);
            fclose(p);
            return cant;
        }
        bool grabarRegistro(Compra reg){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
};

class Proveedor{
private:
    int numeroProveedor;
    char nombre[30];
    char telefono[30];
    char direccion[30];
    int provincia;
    bool activo;
public:
    void Cargar(){
        cout<<"Numero de proveedor: ";cin>>numeroProveedor;
        cout<<"Nombre: ";cargarCadena(nombre,29);
        cout<<"Telefono: ";cargarCadena(telefono,29);
        cout<<"Direccion: ";cargarCadena(direccion,29);
        cout<<"Provincia: ";cin>>provincia;
        activo=true;
    }
    void Mostrar(){
        cout<<"Numero de proveedor: "<<numeroProveedor<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Telefono: "<<telefono<<endl;
        cout<<"Direccion: "<<direccion<<endl;
        cout<<"Provincia: "<<provincia<<endl;
    }

    int getNumeroProveedor(){return numeroProveedor;}
    int getProvincia(){return provincia;}
    const char *getNombre(){return nombre;}
    const char *getTelefono(){return telefono;}
    const char *getDireccion(){return direccion;}
    bool getActivo(){return activo;}

    void setNumeroProveedor(int np){numeroProveedor=np;}
    void setProvincia(int np){provincia=np;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setTelefono(const char *n){strcpy(telefono,n);}
    void setDireccion(const char *n){strcpy(direccion,n);}
    void setActivo(bool a){activo=a;}
};

class ArchivoProveedores{
    private:
        char nombre[30];
    public:
        ArchivoProveedores(const char *n){
            strcpy(nombre, n);
        }
        Proveedor leerRegistro(int pos){
            Proveedor reg;
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return reg;
            }
            fseek(p, pos * sizeof reg, 0);
            fread(&reg, sizeof reg, 1, p);
            fclose(p);
            return reg;
        }
        int contarRegistros(){
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            fseek(p, 0, 2);
            int cant=ftell(p)/sizeof(Proveedor);
            fclose(p);
            return cant;
        }
        bool grabarRegistro(Proveedor reg){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
};

