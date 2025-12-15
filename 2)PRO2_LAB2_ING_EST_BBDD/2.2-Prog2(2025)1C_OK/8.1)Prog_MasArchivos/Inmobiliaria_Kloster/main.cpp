# include<iostream>
# include<cstring>
# include "ArchivoPropietarios.h"
# include "MenuInmuebles.h"
# include "MenuPropietarios.h"
# include "MenuReportes.h"

using namespace std;

int main(){
	int opc;
    while(true){
        system("cls");
        cout << "****** ABML INMUEBLES ******" << endl;
        cout << "1. MENU PROPIETARIOS" << endl;
        cout << "2. MENU INMUEBLES" << endl;
        cout << "3. MENU REPORTES" << endl;
        cout << "0. FIN DEL PROGRAMA" << endl;
        cout << "************************" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: menuPropietarios();
                    break;
            case 2: menuInmuebles();
                    break;
            case 3: menuReportes();
                    break;
            case 0: return 0;
                    break;
            default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;

        }
        system("pause");
    }
    return 0;
}
