# include<iostream>
# include<cstring>
# include "FuncionesMenuPropietarios.h"

using namespace std;

int menuPropietarios(){
	int opc;
    while(true){
        system("cls");
        cout << "****** ABML PROPIETARIOS ******" << endl;
        cout << "1. ALTA DE CLIENTE" << endl;
        cout << "2. BAJA DE CLIENTE" << endl;
        cout << "3. MODIFICAR DATOS DEL CLIENTE" << endl;
        cout << "4. LISTAR CLIENTES" << endl;
        cout << "5. BUSCAR CLIENTE POR DNI"<<endl;
        cout << "6. BUSCAR TODAS LAS PROPIEDADES DEL CLIENTE"<<endl;
        cout << "7. LISTAR INACTIVOS"<<endl;
        cout << "0. FIN DEL PROGRAMA" << endl;
        cout << "************************" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: agregarPropietario();
                    break;
            case 2: bajaPropietario();
                    break;
            case 3: modificarCliente();
                    break;
            case 4: listarPropietarios();
                    break;
            case 5: buscarPorDni();
                    break;
            case 6: buscarTodasLasPropiedadesDelCliente();
                    break;
            case 7: listarInactivos();
                    break;
            case 0: return 0;
                    break;
            default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;

        }
        system("pause");
    }
    return 0;

}
