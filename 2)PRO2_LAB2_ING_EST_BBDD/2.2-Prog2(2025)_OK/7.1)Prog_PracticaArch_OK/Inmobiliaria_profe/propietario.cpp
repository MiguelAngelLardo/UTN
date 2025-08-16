# include "Propietario.h"
# include<iostream>
# include<cstring>
# include "ArchivoPropietarios.h"

using namespace std;

    /// getters y setters
    void Propietario::setApellido(const char* _ap){strcpy(apellido, _ap);}
    void Propietario::setNombre(const char* _no){strcpy(nombre,_no);}
    void Propietario::setDni(const char* _dni){strcpy(dni,_dni);}
    void Propietario::setCelular(const char* _celu){strcpy(celular,_celu);}
    void Propietario::setEstado(bool _estado){estado=_estado;}

    char* Propietario::getApellido(){return apellido;}
    char* Propietario::getNombre(){return nombre;}
    char* Propietario::getDni(){return dni;}
    char* Propietario::getCelular(){return celular;}
    bool Propietario::getEstado(){return estado;}

    /// métodos
    bool Propietario::Cargar(char* _nuevoDni){
        ArchivoPropietario archiProp;

        if(strcmp(_nuevoDni,"NADA")==0){
            cout<<"Ingrese DNI: ";
            cin>>dni;
            if(archiProp.buscarPropietario(dni)>=0){
                cout<<"Ya existe el usuario."<<endl;
                return false;
            }
        }
        else{
            strcpy(dni,_nuevoDni);
        }
        cout<<"Ingrese Apellido: ";
        cin>>apellido;
        cout<<"Ingrese nombre: ";
        cin>>nombre;
        cout<<"Ingrese Celular: ";
        cin>>celular;
        estado=true;
        return true;
    }
    void Propietario::Mostrar(){
        cout<<"Datos del Propietario:"<<endl;
        cout<<"Apellido: "<<apellido<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"DNI: "<<dni<<endl;
        cout<<"Celular: "<<celular<<endl;
        cout<<endl;
    }
