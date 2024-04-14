#include <iostream>

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
        void Cargar();
        void Mostrar();
};

void Empresa::Cargar(){
    cout<<"NUMERO: ";
    cin>>numero;
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
    cout<<"NUMERO: "<<numero<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"CANTIDAD DE EMPLEADOS: "<<cantidadEmpleados<<endl;
    cout<<"CATEGORIA: "<<categoria<<endl;
    cout<<"NUMERO DE MUNICIPIO: "<<numeroMunicipio<<endl;
}

/**
Empresas.dat
Número de empresa (Número entero. No se repite en el archivo. Es único para cada empresa)
Nombre (char[30])
Cantidad de empleados
Categoría (1 a 80)
Número de municipio al que pertenece (1 a 135)
Estado (bool)

1) Cargar y mostrar 5 registros en el archivo. Hacerlo de dos maneras distintas:
Con un registro solo.
Con un vector de 5 registros.


Hacer un menú con las opciones para cargar y mostrar el contenido del archivo.
*/

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

void cargarEmpresas(){
    Empresa obj;
    for(int i=0; i<5; i++){
        obj.Cargar();
        grabarEmpresa(obj);
    }
}

/**
6
Empresa 6
6
6
6
7
Empresa 7
7
7
7
8
Empresa 8
8
8
8
9
Empresa 9
9
9
9
10
Empresa 10
10
10
10
*/

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

void listarEmpresas(){
    Empresa obj;
    FILE *pEmp;
    pEmp=fopen("empresas.dat","rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    while(fread(&obj, sizeof (Empresa), 1, pEmp)){
        obj.Mostrar();
        cout<<endl;
    }
    fclose(pEmp);
}

int main(){
    while(true){
        int opc;
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"--------------"<<endl;
        cout<<"1 - CARGAR CINCO REGISTROS EN EL ARCHIVO"<<endl;
        cout<<"2 - CARGAR CINCO REGISTROS EN EL ARCHIVO CON VECTOR"<<endl;
        cout<<"3 - LISTAR LOS REGISTROS DEL ARCHIVO"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                cargarEmpresas();
                break;
            case 2:
                cargarEmpresasVector();
                break;
            case 3:
                listarEmpresas();
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
