/*
16 Una empresa registró las ventas que efectuó durante un día y para cada venta
registró los siguientes datos:
● Número de Artículo Vendido (1 a 3)
● Cantidad de Unidades Vendidas
● Importe de la Venta
El lote finaliza cuando se ingresa un registro con Número de Artículo igual a 0.
Se pide determinar e informar:
a) La recaudación total para cada uno de los 3 artículos. Se informan 3
resultados al final.
b) El número de artículo con mayor cantidad TOTAL de unidades vendidas. Se
informa 1 resultado al final.
*/


#include <iostream>
using namespace std;


int main(){
    setlocale(LC_ALL, "Spanish");

    int articulo, unidades, importe;
    int recaudacionTotal1=0,recaudacionTotal2=0,recaudacionTotal3=0;
    int totalUnidades1,totalUnidades2,totalUnidades3;

    cout<< "Ingrese el numero de Articulo (1,2 o 3) ";
    cin >>articulo;
    cout<< "Ingrese la candidad vendida ";
    cin >>unidades;
    cout<< "Ingrese el importe de la venta $";
    cin >>importe;

    while(articulo!=0){
    //punto A
        switch(articulo){
            case 1: recaudacionTotal1+=importe;
                    totalUnidades1+=unidades;
                    break;
            case 2: recaudacionTotal2+=importe;
                    totalUnidades2+=unidades;
                    break;
            case 3: recaudacionTotal3+=importe;
                    totalUnidades3+=unidades;
                    break;
        }

        cout<< "Ingrese el numero de Articulo (1,2 o 3) ";
        cin >>articulo;
        cout<< "Ingrese la candidad vendida ";
        cin >>unidades;
        cout<< "Ingrese el importe dela venta $";
        cin >>importe;
    }

    cout<< "----------------------------------------" <<endl;
    cout<< "Recaudación total Articulo 1: " << recaudacionTotal1<<endl;
    cout<<"Recaudación total Articulo 2: " << recaudacionTotal2<<endl;
    cout<< "Recaudación total Articulo 3: " << recaudacionTotal3<<endl;
    if(totalUnidades1>totalUnidades2 &&totalUnidades1>totalUnidades3){
        cout<<"El Articulo 1 es el de mayor cantidad total de unidades vendidas"<<endl;
    }
    else if(totalUnidades2>totalUnidades1 && totalUnidades2>totalUnidades3){
         cout<< "El Articulo 2 es el de mayor cantidad total de unidades vendidas"<<endl;
    }
    else{
         cout<< "El Articulo 3 es el de mayor cantidad total de unidades vendidas"<<endl;
    }


return 0;
}
