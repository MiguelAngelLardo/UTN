/*
20 Una empresa registró las ventas que realizó durante el mes anterior. Para cada
venta se ingresan los siguientes datos.
● Número de artículo (1 a 30)
● Día de la venta (1 a 31)
● Cantidad de unidades vendidas
● Importe de la venta
Este lote finaliza con un registro con número de artículo igual a cero. Los
registros están agrupados (no ordenados) por número de artículo, y puede
haber varios registros para el mismo artículo, para el mismo día, etc. En el lote
no aparecen registros de los artículos que no se vendieron durante el mes.
Se pide determinar e informar:
a) El número de artículo más vendido en unidades totales considerando las
ventas de la primera quincena.
b) Para cada uno de los artículos informar la recaudación total del mes.
c) Informar en cual quincena se vendió mayor cantidad de unidades totales.
d) Informar el número de artículo del que más se haya vendido en cantidad de
unidades en una venta individual indicando además en qué día fue esa
venta.
Considerar para el tema de las quincenas que la Quincena 1 corresponde a los
días 1 al 15 y la Quincena 2 corresponde a los días 16 al 31.
*/

#include <iostream>
using namespace std;


int main(){
    setlocale(LC_ALL, "Spanish");
      int articulo, dia, importe, cantidad,artAnterior;//variables generales
      //variables punto a
      int ptoA_cantidad=0;
      int ptoA_articulo;
      //variables punto b
      int ptoB_recaudacionTotal;
      //variables punto c
      int ptoC_total1Quincena=0;
      int ptoC_total2Quincena=0;
      //variables punto d
      int ptoD_articulo;
      int ptoD_dia;
      int ptoD_cantidadMayor=0;

    cout<< "Ingrese el numero de articulo (1 a 30) ";
    cin >> articulo;

    while(articulo!=0){

        artAnterior=articulo;
        //reiniciar variables de grupo
        ptoB_recaudacionTotal=0;



        while(artAnterior==articulo){
            cout << "Ingrese Día de la venta (1 a 31)";
            cin >>dia;
            cout << "Ingrese la cantidad vendida ";
            cin >>cantidad;
            cout << "Ingrese Importe de la venta $" ;
            cin >>importe;

            cout << "--------------------------------------------------------"<<endl;
            //punto A
            if(dia<=15){
                if(cantidad>ptoA_cantidad){
                    ptoA_cantidad=cantidad;
                    ptoA_articulo=artAnterior;
                }
             //punto C
                ptoC_total2Quincena+=cantidad;
            }else{
               ptoC_total1Quincena+=cantidad;
            }

            //punto B
            ptoB_recaudacionTotal+=importe;

            //punto D
            if(cantidad>ptoD_cantidadMayor){
                ptoD_cantidadMayor=cantidad;
                ptoD_dia=dia;
                ptoD_articulo=artAnterior;
            }


            cout<< "Ingrese el numero de articulo (1 a 30) ";
            cin >> articulo;
        }
        cout << "--------------------------------------------------------"<<endl;
        //mostrar punto b
        cout << "           Articulo " <<artAnterior<<endl;
        cout << "Recaudación total: $" <<ptoB_recaudacionTotal<<endl;;
    }
     cout << "--------------------------------------------------------"<<endl;
    //mostrar punto a
    cout << "El articulo con más unidades vendidas fue el N°:" <<ptoA_articulo<<endl;
    //mostrar punto c

    if(ptoC_total1Quincena>ptoC_total2Quincena){
        cout << "La primer quincena vendío mas unidades"<<endl;
    }
    else if(ptoC_total2Quincena>ptoC_total1Quincena){
        cout << "La segunda quincena vendío mas unidades"<<endl;
    }
    else{
        cout << "Ambas quincenas vendieron la misma cantidad de unidades"<<endl;
    }
    //mostrar pundo D
    cout << "El artículo que más unidades vendio en una  venta individual fue el N° "<<ptoD_articulo<<endl;
    cout << "La venta se realizó el dia " <<ptoD_dia<<endl;
return 0;
}
