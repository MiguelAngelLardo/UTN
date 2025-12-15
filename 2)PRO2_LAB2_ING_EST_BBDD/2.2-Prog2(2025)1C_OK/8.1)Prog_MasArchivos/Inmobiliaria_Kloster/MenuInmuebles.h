# include<iostream>
# include<cstring>
# include "ArchivoPropiedades.h"
# include "Inmueble.h"
# include "FuncionesMenuPropiedades.h"

using namespace std;

int menuInmuebles(){
	int opc;
    while(true){
        system("cls");
        cout << "****** ABML INMUEBLES ******" << endl;
        cout << "1. AGREGAR PROPIEDAD" << endl;
        cout << "2. BAJA DE PROPIEDAD" << endl;
        cout << "3. MODIFICAR PRECIO DE LA PROPIEDAD" << endl;
        cout << "4. LISTAR PROPIEDADES" << endl;
        cout << "5. BUSCAR POR CALLE"<<endl;
        cout << "6. BUSCAR POR RANGO DE PRECIOS"<<endl;
        cout << "7. REACTIVAR PROPIEDAD"<<endl;
        cout << "0. REGRESAR AL MENU PRINCIPAL" << endl;
        cout << "************************" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: agregarPropiedad();
                    break;
            case 2: bajaPropiedad();
                    break;
            case 3: modificarPrecio();
                    break;
            case 4: listarPropiedades();
                    break;
            case 5: buscarPorCalle();
                    break;
            case 6: buscarPorRangoPrecios();
                    break;
            case 7: reactivarPropiedad();
                    break;
            case 0: return 0;
                    break;
            default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;
        }
        system("pause");
    }
    return 0;

}
