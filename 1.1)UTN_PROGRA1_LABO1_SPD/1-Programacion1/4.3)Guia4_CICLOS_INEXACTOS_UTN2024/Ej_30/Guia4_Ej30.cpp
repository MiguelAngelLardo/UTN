/*
30
Hacer un programa para ingresar por teclado los saldos de los clientes de un banco.
 Cada registro contiene los siguientes datos:
- Número del cliente
- Número de sucursal (1, 2, 3 o 4)
- Saldo del cliente

El lote finaliza cuando se ingresa un registro con número de sucursal igual a 10.
Se pide determinar e informar.
a) El número de sucursal con mayor porcentaje de clientes con saldo superior a $ 20000.
b) El número de cliente con mayor saldo, indicando también de qué número de sucursal es ese cliente.
Se listan 2 resultados.
c) Para cada una de las sucursales la suma de los saldos de todos sus clientes. Se listan 4 resultados.

*/

#include <iostream>
using namespace std;


int main(){
    setlocale(LC_ALL, "Spanish");
    int cliente, sucursal, saldo, saldoMayor=0, clienteMayorSaldo, sucursalMayorSaldo;
    int total1, total2, total3, total4;
    int totalClientes=0, clienteSaldoMayor1, clienteSaldoMayor2, clienteSaldoMayor3, clienteSaldoMayor4;
    float ptje1,ptje2, ptje3, ptje4;

    clienteSaldoMayor1=clienteSaldoMayor2=clienteSaldoMayor3=clienteSaldoMayor4=0;
    total1=total2=total3=total4=0;

    cout << "Ingrese el número de sucursal (1,2,3 o,4) ";
    cin >> sucursal;

    while (sucursal != 10){
        cout << "Ingrese el número de cliente";
        cin >> cliente;
        cout << "Ingrese el saldo del cliente";
        cin >>saldo;
        totalClientes++;

        switch(sucursal){
        case 1: //PUNTO A
                if (saldo>2000){
                    clienteSaldoMayor1++;
                }
                //PUNTOC
                total1+=saldo;
                break;
        case 2: //PUNTO A
                if (saldo>2000){
                    clienteSaldoMayor2++;
                }
                //PUNTOC
                total2+=saldo;
                break;
        case 3: //PUNTO A
                if (saldo>2000){
                    clienteSaldoMayor3++;
                }
                //PUNTO C
                total3+=saldo;
                break;
        case 4: //PUNTO A
                if (saldo>2000){
                    clienteSaldoMayor4++;
                }
                //PUNTO C
                total4+=saldo;
                break;
        }

        //PUNTO B
        if (saldoMayor==0|| saldo > saldoMayor){
            saldoMayor=0;
            clienteMayorSaldo=cliente;
            sucursalMayorSaldo=sucursal;
        }

        cout << "Ingrese el número de sucursal (1,2,3 o,4) ";
        cin >> sucursal;
    }

    //MOSTRAR A
    ptje1= (float)(clienteSaldoMayor1*100) /totalClientes;
    ptje2= (float)(clienteSaldoMayor2*100) /totalClientes;
    ptje3= (float)(clienteSaldoMayor3*100) /totalClientes;
    ptje4= (float)(clienteSaldoMayor4*100) /totalClientes;

    if(ptje1>ptje2 && ptje1>ptje3 && ptje1>ptje4){
        cout<< "La sucursal 1 tiene mayor porcentaje de clientes con saldo superior a $2000" << endl;
    }
    else if (ptje2>ptje1 && ptje2>ptje3 && ptje2>ptje4){
        cout<< "La sucursal 2 tiene mayor porcentaje de clientes con saldo superior a $2000" << endl;
    }
    else if(ptje3>ptje1 && ptje3>ptje2 && ptje3>ptje4){
        cout<< "La sucursal 3 tiene mayor porcentaje de clientes con saldo superior a $2000" << endl;
    }
    else{
        cout<< "La sucursal 4 tiene mayor porcentaje de clientes con saldo superior a $2000" << endl;
    }

    //MOSTRAR B
    cout << " El cliente con mayor saldo es el N° " << clienteMayorSaldo;
    cout << "Corresponde a la sucursal N° " << sucursalMayorSaldo;

    //MOSTRAR C
    cout << "La suma de saldos de la sucursal 1 es: $" << total1 << endl;
    cout << "La suma de saldos de la sucursal 2 es: $" << total2 << endl;
    cout << "La suma de saldos de la sucursal 3 es: $" << total3 << endl;
    cout << "La suma de saldos de la sucursal 4 es: $" << total4 << endl;
return 0;
}
