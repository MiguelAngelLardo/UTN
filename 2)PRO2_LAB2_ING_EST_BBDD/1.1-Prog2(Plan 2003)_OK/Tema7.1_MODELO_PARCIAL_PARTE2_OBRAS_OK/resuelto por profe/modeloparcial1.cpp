///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>
using namespace std;


# include "parcialm1.h"

void punto1();
void punto2();

int main(){
    punto1();
    punto2();
	cout<<endl;
	system("pause");
	return 0;
}

///Generar un archivo con el código de obra, la dirección y la provincia,
///de las obras cuyo estado de ejecución sea "en ejecución".

class ObraEnEjecucion{
private:
    char codigoObra[5];
    char direccion[30];
    int provincia;
    bool activo;
public:
    void setCodigoObra(const char *co){
        strcpy(codigoObra,co);
    }
    void setDireccion(const char *d){
        strcpy(direccion,d);
    }
    void setProvincia(int p){
        provincia=p;
    }
    void setActivo(bool e){
        activo=e;
    }
};
bool grabarObraEnEjecucion(ObraEnEjecucion aux){
    FILE *p;
    p=fopen("obrasEjecucion.dat", "ab");
    if(p==NULL)return false;
    bool escribio=fwrite(&aux, sizeof aux,1, p);
    fclose(p);
    return escribio;
}

void punto1(){
    Obra reg;
    ArchivoObras archiObras("obras.dat");
    int cantReg=archiObras.contarRegistros();
    int i;
    ObraEnEjecucion aux;
    for(i=0;i<cantReg;i++){
        ///leer registro a registro el archivo de obras
        reg=archiObras.leerRegistro(i);
    ///por cada registro ver si el estado de ejecución es igual a 3
        if(reg.getEstadoEjecucion()==3 && reg.getActivo()){
        ///si es verdadero
        ///copiar los campos correspondientes en una variable de memoria
        ///que tenga lo que se definió para el archivo nuevo
                aux.setCodigoObra(reg.getCodigoObra());
                aux.setDireccion(reg.getDireccion());
                aux.setProvincia(reg.getProvincia());
                aux.setActivo(true);
        ///grabar el registro en el archivo nuevo
                if(grabarObraEnEjecucion(aux)==false){
                        cout<<"ERROR DE CREACION DE ARCHIVO"<<endl;
                        return;
                }
        }
        ///si no, ignorar el registro y seguir la lectura
    }
}

///La provincia con menos proveedores
/// (ignorando las provincias sin proveedores).

int buscarMinimo(int *v,int tam){///hacer la función
    int i;
    for(i=0;i<24;i++){
        cout<<v[i]<<endl;
    }
    return 2;
}


void punto2(){
    Proveedor reg;
    ArchivoProveedores archiPro("proveedores.dat");
    int vProv[24]={0};
    int cantReg=archiPro.contarRegistros();
    int i;
    for(i=1;i<cantReg;i++){
        reg=archiPro.leerRegistro(i);
        vProv[reg.getProvincia()-1]++;
    }
    int posMin=buscarMinimo(vProv, 24);
    cout<<"LA PROVINCIA CON MENOS PROVEEDORES ES "<<posMin+1<<endl;
}
