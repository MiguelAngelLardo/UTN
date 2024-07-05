/*
17 Una empresa registró las ventas que efectuó durante un día y para cada venta
registró los siguientes datos:
● Número de Artículo Vendido (1 a 30)
● Cantidad de Unidades Vendidas
● Importe de la Venta
El lote finaliza cuando se ingresa un registro con Número de Artículo igual a 0.
En el lote anterior no aparecen registros de los artículos que por alguna razón
no se hayan vendido durante el día. Los registros están agrupados por número
de artículo.
Se pide determinar e informar:
a) La recaudación total para cada uno de los artículos vendidos. Se informa 1
resultado para cada uno de los grupos.
b) El número de artículo con mayor cantidad TOTAL de unidades vendidas.
*/


#include <iostream>
using namespace std;


int main(){
    setlocale(LC_ALL, "Spanish");
    int articulo, unidades, importe, artAnterior;//variables generales
    int recaudacionTotal;// variable punto a
    int totalUnidades,mayorUnidades=0, artMayor; // variable punto b

    cout<< "Ingrese el numero de Articulo (1,2 o 3) ";
    cin >>articulo;
    cout<< "Ingrese la candidad vendida ";
    cin >>unidades;
    cout<< "Ingrese el importe de la venta $";
    cin >>importe;

    while(articulo !=0){
         artAnterior=articulo;//corte de control

         recaudacionTotal=0;//reinicio de variable de grupo
         totalUnidades=0;//reinicio de variable de grupo

         while(artAnterior==articulo){
            //punto a
            recaudacionTotal+=importe;
            //punto b
            totalUnidades+=unidades;



            cout<< "Ingrese el numero de Articulo (1,2 o 3) ";
            cin >>articulo;
            cout<< "Ingrese la candidad vendida ";
            cin >>unidades;
            cout<< "Ingrese el importe de la venta $";
            cin >>importe;

         }
         //mostrar punto a
         cout <<"-------------------------"<< endl;
         cout <<"Articulo " << artAnterior <<endl;
         cout <<"Recaudación total: $" << recaudacionTotal<<endl;

         //punto b
         if(totalUnidades>mayorUnidades){
            mayorUnidades=totalUnidades;
            artMayor=artAnterior;
         }
    }

    //mostrar punto b
    cout<< "El Articulo con la mayor cantidad total de unidades vendidas fue "<<artMayor<<endl;


return 0;
}
