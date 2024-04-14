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

/**
puntero sobre el que hago la apertura:
FILE
abrir el archivo        fopen
leer el archivo         fread
escribir el archivo     fwrite
cerrar el archivo       fclose
*/

void reciboVector(int *v, int tam){
    cout<<sizeof v<<endl;
}

class Articulo{
    private:
        int codigo;
        char nombre[30];
        int stock;
        float precio;
    public:
        void setCodigo(int c){codigo=c;}
        void setNombre(const char *n){strcpy(nombre, n);}
        void setStock(int s){stock=s;}
        void setPrecio(float p){precio=p;}
        int getCodigo(){return codigo;}
        const char *getNombre(){return nombre;}
        int getStock(){return stock;}
        float getPrecio(){return precio;}
        void Cargar();
        void Mostrar();
};

void Articulo::Cargar(){
    cout<<"CODIGO: ";
    cin>>codigo;
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 29);
    cout<<"STOCK: ";
    cin>>stock;
    cout<<"PRECIO: ";
    cin>>precio;
}

void Articulo::Mostrar(){
    cout<<"CODIGO: "<<codigo<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"STOCK: "<<stock<<endl;
    cout<<"PRECIO: "<<precio<<endl;
}

void grabarArticulo(Articulo obj){
    FILE *pArt;
    pArt=fopen("articulos.dat", "ab");
    if(pArt==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fwrite(&obj, sizeof (Articulo), 1, pArt);
    fclose(pArt);
}

void mostrarArticulos(){
    Articulo obj;
    FILE *pArt;
    pArt=fopen("articulos.dat","rb");
    if(pArt==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    while(fread(&obj, sizeof (Articulo), 1, pArt)){
        obj.Mostrar();
        cout<<endl;
    }
    fclose(pArt);
}

int main(){
    Articulo obj;
    obj.Cargar();
    grabarArticulo(obj);
    mostrarArticulos();
    return 0;
}

/**
int main(){
    FILE *pAlu;
    Alumno obj;
    pAlu=fopen("z:\\datos_importantes\\alumnos.dat", "ab");
    if(pAlu==nullptr){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return -1;
    }
    fwrite(&obj, sizeof (Alumno), 1, pAlu);
    fclose(pAlu);
    pAlu=fopen("alumnos.dat", "rb");
    if(pAlu==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return -1;
    }
    fread(&obj, sizeof (Alumno), 1, pAlu);
    fclose(pAlu);
//    modo de apertura:
//    rb: read binary - nos permite abrir el archivo en modo lectura
//    wb: write binary - crea un archivo vacío y lo abre en modo escritura. Si ya existe, lo pisa.
//    ab: append binary - abre el archivo en modo escritura. Si no existe, lo crea.
//
    return 0;
}*/
