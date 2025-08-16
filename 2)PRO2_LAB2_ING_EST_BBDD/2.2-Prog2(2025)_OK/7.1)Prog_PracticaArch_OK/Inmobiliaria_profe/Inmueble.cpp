# include "Inmueble.h"
# include "Propietario.h"
# include "ArchivoPropietarios.h"
# include "ArchivoPropiedades.h"
# include<iostream>
# include<cstring>

using namespace std;
    ///getters y setters
    void Inmueble::setCodInmueble(int _cod){codInmueble=_cod;}
    void Inmueble::setTipoPropiedad(int tipo){tipoPropiedad=tipo;}
    void Inmueble::setCalle(char* _calle){strcpy(calle, _calle);}
    void Inmueble::setNumero(char* _num){strcpy(numero, _num);}
    void Inmueble::setAntiguedad(int _antig){antiguedad=_antig;}
    void Inmueble::setSuperficieTotal(float sup){superficieTotal=sup;}
    void Inmueble::setCantHabitaciones(int _cantHab){cantHabitaciones=_cantHab;}
    void Inmueble::setPrecioVenta(float _pv){precioVenta=_pv;}
    void Inmueble::setPrecioAlquier(float _pa){precioAlquiler=_pa;}
    void Inmueble::setDniPropietario(const char* _codPropietario){strcpy(dniPropietario, _codPropietario);}
    void Inmueble::setEstado(bool _estado){estado=_estado;}
    int Inmueble::getCodInmueble(){return codInmueble;}
    int Inmueble::getTipoPropiedad(){return tipoPropiedad;}
    char* Inmueble::getCalle(){return calle;}
    char* Inmueble::getNumero(){return numero;}
    int Inmueble::getAntiguedad(){return antiguedad;}
    float Inmueble::getSuperficieTotal(){return superficieTotal;}
    int Inmueble::getCantHabitaciones(){return cantHabitaciones;}
    float Inmueble::getPrecioVenta(){return precioVenta;}
    float Inmueble::getPrecioAlquier(){return precioAlquiler;}
    const char* Inmueble::getDniPropietario(){return dniPropietario;}
    bool Inmueble::getEstado(){return estado;}

    ///m�todos:
    bool Inmueble::Cargar(int _cod){
        ArchivoPropiedades archiProp;
        Propietario propietario;
        ArchivoPropietario archiPropietario;
        codInmueble=archiProp.proximoId();
        int aux=0;

        cout<<"Dni del propietario: ";
        cin>>dniPropietario;
        int pos= archiPropietario.buscarPropietario(dniPropietario);
        if(pos>=0){
            propietario=archiPropietario.leerRegistro(pos);
            if(!propietario.getEstado()){
                cout<<"El cliente esta dado de baja, desea reactivarlo? (1-SI/0-NO):";
                cin>>aux;
                if(aux==1){
                    if(archiPropietario.altaLogica(dniPropietario)){
                        cout<<"Cliente reactivado."<<endl;
                    }
                }
            }
        }
        if(pos<0){
                cout<<endl;
                cout<<"El propietario no existe, debe cargarlo a continuación: "<<endl;
                propietario.Cargar(dniPropietario);
                archiPropietario.agregarRegistro(propietario);
            }
            cout<<endl;

        cout<<"Tipo de propiedad (1.Casa - 2.Departamento): ";
        cin>>tipoPropiedad;
        cout<<"Calle: ";
        cin>>calle;
        cout<<"Numero: ";
        cin>>numero;
        if(archiProp.buscarInmueble(calle,numero)==-3){
            cout<<"Esa propiedad ya existe en sistema!. Cancelando carga."<<endl;
            return false;
        }
        else{
            cout<<"Antiguedad: ";
            cin>>antiguedad;
            cout<<"Superficie total: ";
            cin>>superficieTotal;
            cout<<"Cantidad de habitaciones: ";
            cin>>cantHabitaciones;
            cout<<"Precio de venta: USD";
            cin>>precioVenta;
            cout<<"Precio de alquiler: $";
            cin>>precioAlquiler;
            estado=true;
            return true;
        }

    }
    void Inmueble::Mostrar(){
        ArchivoPropietario archiPropietario;
        Propietario propietario;

        cout<<"Codigo de la propiedad: "<<codInmueble<<endl;
        cout<<"Tipo de propiedad: ";
        if(tipoPropiedad==1)
        {
            cout<<"Casa."<<endl;
        }
        if(tipoPropiedad==2)
        {
            cout<<"Departamento."<<endl;
        }
        cout<<"Calle: "<<calle<<endl;
        cout<<"Numero: "<<numero<<endl;
        cout<<"Antiguedad: "<<antiguedad<<endl;
        cout<<"Superficie total: "<<superficieTotal<<endl;
        cout<<"Cantidad de habitaciones: "<<cantHabitaciones<<endl;
        cout<<"Precio de venta: USD"<<precioVenta<<endl;
        cout<<"Precio de alquiler: $"<<precioAlquiler<<endl;
        cout<<"Dni del propietario: "<<dniPropietario<<endl;
        int pos= archiPropietario.buscarPropietario(dniPropietario);
        propietario=archiPropietario.leerRegistro(pos);
        cout<<"Nombre del propietario: "<<propietario.getNombre()<<endl;
        cout<<"Apellido del propietario: "<<propietario.getApellido()<<endl;
        cout<<"Celular: "<<propietario.getCelular()<<endl<<endl;
    }

