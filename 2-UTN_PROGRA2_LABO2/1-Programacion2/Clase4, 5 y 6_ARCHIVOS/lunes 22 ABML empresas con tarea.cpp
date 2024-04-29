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
        ///Fecha fechaCreacion;  ///usar un objeto de una clase (Fecha) como propiedad de otra clase (Empresa) ->COMPOSICION
        int categoria; /// 1 a 80
        int numeroMunicipio;  //1 a 135
        bool estado;///true si el registro está activo; false si está borrado
    public:
        Empresa(){estado=false;}
        void setNumero(int n){numero = n;}
        void setCategoria(int c){categoria = c;}
        void setEstado(bool e){estado = e;}
        int getNumero(){return numero;}
        int getCantidadEmpleados(){return cantidadEmpleados;}
        bool getEstado(){return estado;}
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
        bool grabarRegistro(Empresa obj);
        Empresa leerRegistro(int pos);
        int buscarRegistro(int num);
        int contarRegistros();
        bool modificarRegistro(Empresa obj, int pos);
        bool listarRegistros();
};


bool ArchivoEmpresas::grabarRegistro(Empresa obj){
    FILE *p;
    p=fopen(nombre, "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}


bool ArchivoEmpresas::listarRegistros(){
    FILE *p;
    Empresa obj;
    p=fopen(nombre, "rb");
    if(p==NULL) return false;
    while(fread(&obj, sizeof obj, 1, p)==1){
            obj.Mostrar();
            cout<<endl;
    }
    fclose(p);
    return true;
}

int ArchivoEmpresas::buscarRegistro(int num){
    FILE *p;
    Empresa obj;
    p=fopen(nombre, "rb");
    int pos=0;
    if(p==NULL) return -1;
    while(fread(&obj, sizeof obj, 1, p)==1){
                if(obj.getNumero()==num){
                    fclose(p);
                    return pos;
                }
                pos++;
    }
    fclose(p);
    return -2;
}

Empresa ArchivoEmpresas::leerRegistro(int pos){
    FILE *p;
    Empresa obj;
    p=fopen(nombre, "rb");
    obj.setNumero(-5);
    if(p==NULL) return obj;
    fseek(p, pos*sizeof obj,0);///función que permite ubicarse dentro del archivo
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

bool ArchivoEmpresas::modificarRegistro(Empresa obj, int pos){
    FILE *p;
    p=fopen(nombre, "rb+"); ///agrega al modo de apertura lo que le falta
    if(p==NULL) return false;
    fseek(p, pos*sizeof obj,0);///función que permite ubicarse dentro del archivo
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoEmpresas::contarRegistros(){
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);///función que permite ubicarse dentro del archivo, en este caso lo ubiqué al final EOF
    int tam=ftell(p);///me devuelve la cantidad de bytes que hay desde el principio del archivo a la posición actual del indicador de pFILE.
    fclose(p);
    return tam/sizeof(Empresa);
}

void altaEmpresa(){
    Empresa reg;
    ArchivoEmpresas archiEmp("empresas.dat");
    reg.Cargar();
    archiEmp.grabarRegistro(reg);
}

void listarEmpresas(){
    ArchivoEmpresas archiEmp("empresas.dat");
    archiEmp.listarRegistros();

}

void bajaLogica(){
    Empresa reg;
    ArchivoEmpresas archiEmp("empresas.dat");
    cout<<"INGRESE EL NUMERO DE EMPRESA A BORRAR ";
    int num;
    cin>>num;
    int pos=archiEmp.buscarRegistro(num);
    if(pos<0){
        cout<<"NO SE ENCUENTRA EL REGISTRO"<<endl;
        return;
    }
    reg=archiEmp.leerRegistro(pos);
    reg.Mostrar();
    cout<<"ESTA SEGURO DE ELIMINAR EL REGISTRO ? (S/N) ";
    char respuesta;
    cin>>respuesta;
    if(respuesta=='S' || respuesta =='s'){
        reg.setEstado(false);
        if(archiEmp.modificarRegistro(reg,pos)){
            cout<<"REGISTRO ELIMINADO";
        }
        else{
            cout<<"NO SE PUDO ELIMINAR EL REGISTRO";
        }
        cout<<endl;
    }

}

int main(){
    ArchivoEmpresas archiE("empresas.dat");
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
                cout<<"CANTIDAD DE REGISTROS "<<archiE.contarRegistros()<<endl;
                system("pause");
                bajaLogica();
                break;
            case 3:
///                modificarCantidadEmpleados();
                break;
            case 4:
                listarEmpresas();
                break;
            case 5:
//                buscarRegistro();
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

 ///Hacer la función buscarRegistro() que se llama desde el menú. La función debe pedir un número de empresa y mostrar la empresa que
 ///tenga ese número. Si no encuentra la empresa debe informarlo.

 ///Modificar la función altaEmpresa(). No debe aceptar un registro que contenga un número de empresa existente.

 ///Hacer la función modificarCantidadEmpleados() que se llama desde el menú principal. La función debe pedir un número de empresa, verificar si
 ///existe en el archivo, y cambiar la cantidad de empleados de esa empresa. El nuevo valor de cantidad se debe ingresar por teclado

 ///Calcular e informar la cantidad de municipios sin empresas.

 ///Listar los municipios con más de 5 empresas.

 ///Listar los registros de las empresas que pertenezcan a una categoría que se ingresa por teclado
