# include<iostream>
# include<cstring>
# include "FuncionesMenuPropiedades.h"
# include "ArchivoPropiedades.h"

using namespace std;

ArchivoPropiedades archiPropiedad;
Inmueble propiedad;
int codProp;
int pos=0;
char _calle[50];
float precioActualizado=0;
int tipoOperacion=0;
float precioMin=0;
float precioMax=0;
int aux=0;

void agregarPropiedad(){
    if(archiPropiedad.agregarRegistro()==true){
        cout<<"REGISTRO AGREGADO";
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO";
    }
    cout<<endl;
}

void bajaPropiedad(){
    cout<<"Ingrese el codigo de la propiedad: ";
    cin>>codProp;
    pos=archiPropiedad.buscarInmueble(codProp);
    propiedad=archiPropiedad.leerRegistro(pos);
    if(archiPropiedad.bajaLogica(codProp)==true){
        cout<<"REGISTRO BORRADO"<<endl;
    }
    else{
        cout<<"NO SE PUDO BORRAR EL REGISTRO"<<endl;
    }
}
void modificarPrecio(){
    cout<<"Ingrese el codigo de la propiedad: ";
    cin>>codProp;
    pos=archiPropiedad.buscarInmueble(codProp);
    propiedad=archiPropiedad.leerRegistro(pos);
    cout<<"Ingrese si el cambio se aplicara a el precio de venta o el precio de alquiler: (1-Venta, 2-Alquiler)";
    cin>>tipoOperacion;
    cout<<"Ingrese nuevo precio: ";
    cin>>precioActualizado;
    if(tipoOperacion==1){
        propiedad.setPrecioVenta(precioActualizado);
    }
    if(tipoOperacion==2){
        propiedad.setPrecioAlquier(precioActualizado);
    }
    if(archiPropiedad.modificarRegistro(propiedad,pos)==true){
        cout<<"REGISTRO MODIFICADO"<<endl;
    }
    else{
        cout<<"NO SE PUDO MODIFICAR EL REGISTRO"<<endl;
    }
}
void listarPropiedades(){
    if(archiPropiedad.listarRegistros()==false){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    }
    cout<<endl;
}
void buscarPorCalle(){
    cout<<"Ingrese calle: ";
    cin>>_calle;
    if(!archiPropiedad.listarRegistrosPorDireccion(_calle)){
        cout<<"No se encontraron propiedades en esa calle."<<endl;
    }
}
void buscarPorRangoPrecios(){
    cout<<"Venta o Alquiler? 1.Venta - 2.Alquiler: ";
    cin>>tipoOperacion;
    cout<<"Ingrese el rango mínimo del precio buscado: ";
    cin>>precioMin;
    cout<<"Ingrese el rango máximo del precio buscado: ";
    cin>>precioMax;
    cout<<endl;
    aux=archiPropiedad.listarRegistrosPorRangoDePrecios(precioMin, precioMax, tipoOperacion);
    cout<<aux<<" propiedades encontradas."<<endl;
    if(aux==0){
        cout<<"No se encontraron propiedades en ese rango de precios."<<endl<<endl;
    }
}
void reactivarPropiedad(){
    cout<<"Listado de propiedades inactivas:"<<endl;
    archiPropiedad.listarInactivos();
    cout<<"Ingrese el codigo de la propiedad a reactivar: ";
    cin>>codProp;
    pos=archiPropiedad.buscarInmueble(codProp);
    propiedad=archiPropiedad.leerRegistro(pos);
    if(archiPropiedad.altaLogica(codProp)==true){
        cout<<"Propiedad reactivada satisfactoriamente."<<endl;
    }
    else{
        cout<<"NO SE PUDO PROCESAR"<<endl;
    }
}
