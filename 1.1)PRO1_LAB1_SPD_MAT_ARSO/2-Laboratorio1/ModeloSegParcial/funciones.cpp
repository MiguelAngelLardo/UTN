#include <iostream>
#include <string>
using namespace std;
#include "funciones.h"

//Funcion Cargar Datos
void cargarDatos(bool p1_clientes[600], int p2_contMismaTorta[600][7], float p3_pesoMaximo[7], bool p4_pedidosXcliente[600][4], bool p4_banPedidos[600]) {
    int idPedido;
    int idTorta;
    float peso;
    int diasAnticipacion;
    int idCliente;
    int idMedioContacto;

    cout << "Id de pedido: " << endl;
    cin >> idPedido;

    while (idPedido >= 0) {

        cout << "Id de torta: " << endl;
        cin >> idTorta;
        cout << "Peso: " << endl;
        cin >> peso;
        cout << "Dias de anticipaciondel pedido: " << endl;
        cin >> diasAnticipacion;
        cout << "Id de cliente: " << endl;
        cin >> idCliente;
        cout << "Id de medio de contacto: " << endl;
        cin >> idMedioContacto;

        //Punto1
        if (diasAnticipacion > 90) {
            p1_clientes[idCliente - 800] = true;
        }
        //punto2
        p2_contMismaTorta[idCliente - 800][idTorta - 1]++;
        //punto3
        if (peso > p3_pesoMaximo[idTorta]) {
            p3_pesoMaximo[idTorta] = (float) peso;
        }
        //Punto4
        p4_banPedidos[idCliente - 800] = true;
        p4_pedidosXcliente[idCliente - 800][(idMedioContacto) / 1000 - 1] = true;




        cout << "Id de pedido: " << endl;
        cin >> idPedido;
    }
}
//Punto1
void punto1(bool p1_clientes[600]){
    int p1_contador = 0;
    cout << "\n\t- " << "1) La cantidad de clientes distintos que hayan realizado algun pedido con mas de 90 dias de anticipacion es: " << endl;
    for (int i = 0; i < 600; i++) {
        if (p1_clientes[i] == true) {
            p1_contador++;
        }
    }
    cout << "\n\t- " << p1_contador << endl;
}
//punto2
void punto2(int p2_contMismaTorta[600][7]){
    cout << "\n\t- " << "2) ID de los clientes que hayan pedido mas de una vez la misma torta" << endl;
    for (int i = 0; i < 600; i++) {
        for (int x = 0; x < 7; x++) {
        if (p2_contMismaTorta[i][x] >= 2) {
            cout << "\n\t- " << (i + 800) << endl;
        }
        }
    }
}
//punto3
void punto3(float p3_pesoMaximo[7]){
    string nombresTorta[7] = { "Rogel", "Selva Negra", "Cheesecake", "Chocotorta", "Lemon Pie", "Balcarce", "Chaja"};
    cout << "\n\t- " << "3) Liste por cada torta el peso maximo registrado y el nombre de la torta: " << endl;
    for (int i = 0; i < 7; i++) {
        if (p3_pesoMaximo[i] > 0) {
            cout << "\n\t- " << nombresTorta[i - 1] << endl;
            cout << "\n\t- " << p3_pesoMaximo[i] << endl;
        }
    }
}
//Punto4
void punto4(bool p4_pedidosXcliente[600][4], bool p4_banPedidos[600]){
    cout << "\n\t- " << "4) Los ID de Clientes que no hayan pedido tortas en persona ni por WhatsApp: " << endl;
    for (int i = 0; i < 600; i++) {
        if (p4_banPedidos[i] == true && p4_pedidosXcliente[i][0] == false && p4_pedidosXcliente[i][2] == false) {
            cout << "\n\t- " << (i + 800) << endl;
        }
    }
}