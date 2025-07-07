# include<iostream>
# include<cstring>
# include "FuncionesMenuPropietarios.h"
# include "ArchivoPropietarios.h"
# include "Propietario.h"
# include "ArchivoPropiedades.h"

using namespace std;

ArchivoPropietario archiPropietario;
ArchivoPropiedades archiPropiedades;
char dni[12];
Propietario propietario;
int pos2=0;
char nuevoNombre[50];
int aux2=0;

void agregarPropietario(){
    if(archiPropietario.agregarRegistro()==true){
        cout<<"REGISTRO AGREGADO";
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO";
    }
    cout<<endl;
}
void bajaPropietario(){
    cout<<"Ingrese DNI: ";
    cin>>dni;
    if(archiPropietario.bajaLogica(dni)==true){
        cout<<"REGISTRO BORRADO"<<endl;
    }
    else{
        cout<<"NO SE PUDO BORRAR EL REGISTRO"<<endl;
    }
}
void modificarCliente(){
    cout<<"Ingrese DNI: ";
    cin>>dni;
    pos2=archiPropietario.buscarPropietario(dni);
    propietario=archiPropietario.leerRegistro(pos2);
    if(pos2>0 && propietario.getEstado()){
        cout<<"Ingrese nuevo nombre: ";
        cin>>nuevoNombre;
        propietario.setNombre(nuevoNombre);
        if(archiPropietario.modificarRegistro(propietario,pos2)){
            cout<<"REGISTRO MODIFICADO"<<endl;
        }
        else{
            cout<<"NO SE PUDO MODIFICAR EL REGISTRO"<<endl;
        }
    }
    else if(!propietario.getEstado()){
        cout<<"Propietario dado de baja, desea reactivarlo? (1-Si - 0-No):"<<endl;
        cin>>aux2;
        if(aux2==1){
            propietario.setEstado(true);
            if(archiPropietario.modificarRegistro(propietario,pos2)==1){
                cout<<"Propietario reactivado!"<<endl;
            }
        }

    }
    else{
        cout<<"PROPIETARIO NO ENCONTRADO"<<endl;
    }
}
void listarPropietarios(){
    if(archiPropietario.listarRegistros()==false){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    }
    cout<<endl;
}
void buscarPorDni(){
    cout<<"Ingrese DNI: ";
    cin>>dni;
    pos2=archiPropietario.buscarPropietario(dni);
    if(pos2>=0){
        propietario=archiPropietario.leerRegistro(pos2);
        propietario.Mostrar();
    }
    else{
        cout<<"No existe ese cliente."<<endl;
    }
}
void buscarTodasLasPropiedadesDelCliente(){
    cout<<"Ingrese DNI: ";
    cin>>dni;
    pos2=archiPropietario.buscarPropietario(dni);
    if(pos2>0){
        aux2=archiPropiedades.listarPropiedadesPorCliente(dni);

    }
    else{
        cout<<"No existe ese cliente."<<endl;
    }
    cout<<"Total de propiedades encontradas: "<<aux2<<endl;
}
void listarInactivos(){
    archiPropietario.listarInactivos();
    cout<<"Desea activar algún cliente? (1-Si / 0-No):";
    cin>>aux2;

    if(aux2==1){
     cout<<"Ingrese DNI: ";
        cin>>dni;
        pos2=archiPropietario.buscarPropietario(dni);
        if(pos2>0){
            if(archiPropietario.altaLogica(dni)){
                cout<<"Cliente reactivado satisfactoriamente."<<endl;
            }
        }
        else{
            cout<<"No existe ese cliente."<<endl;
        }
    }
}
