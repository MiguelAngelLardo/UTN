#include <iostream>

using namespace std;

const int TAM_EMPRESAS = 5;

void cargarCadena(char *pal, int tam){
    int i;
    fflush (stdin); ///limpia el buffer de entrada para que la carga se haga sin caracteres que hayan quedado sin usar
    for(i=0; i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush (stdin); ///vuelve a limpiar el buffer para eliminar los caracteres sobrantes
}

class Empresa{
    private:
        int numero;
        char nombre[30];
        int cantidadEmpleados;
        int categoria;
        int numeroMunicipio;
        bool estado; ///PARA ABML
    public:
        void Cargar();
        void Mostrar();
};

void Empresa::Cargar(){
    cout<<"NUMERO: ";
    cin>>numero;
    cout<<"NOMBRE: ";
    cin.ignore();
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

1) Cargar y mostrar 5 registros en el archivo. Hacerlo de dos maneras distintas:
a)	Con un registro solo.
b)	Con un vector de 5 registros.

*/

void grabarEmpresa(Empresa obj){
    FILE *pEmp;
    pEmp = fopen ("empresas.dat", "ab");
    if(pEmp == NULL){
        cout << "ERROR DE ARCHIVO";
        return;
    }
    fwrite(&obj, sizeof (Empresa), 1, pEmp);
    fclose(pEmp);
}

void cargarEmpresas(){//para cargar 5 veces 
    Empresa obj;
    for(int i=0; i < TAM_EMPRESAS; i++){
        obj.Cargar();
        grabarEmpresa(obj);
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


void listarEmpresas(){
    Empresa obj;
    FILE *p;
    p = fopen("empresas.dat", "rb");
    if(p == NULL){
        cout << "ERROR DE ARCHIVO" << endl;
        return;
    }
    while(fread(&obj, sizeof(Empresa), 1, p)){
        obj.Mostrar();
        cout << endl;
    } 
    fclose(p);
}





int main(){
    Empresa ob;
    while(true){
        int opc;
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"--------------"<<endl;
        cout<<"666 - CARGAR UN REGISTRO"<<endl;
        cout<<"1 - CARGAR CINCO REGISTROS EN EL ARCHIVO"<<endl;
        cout<<"2 - CARGAR CINCO REGISTROS EN EL ARCHIVO CON VECTOR"<<endl;
        cout<<"3 - LISTAR LOS REGISTROS DEL ARCHIVO"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 666:
                grabarEmpresa(ob);
                break;
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
