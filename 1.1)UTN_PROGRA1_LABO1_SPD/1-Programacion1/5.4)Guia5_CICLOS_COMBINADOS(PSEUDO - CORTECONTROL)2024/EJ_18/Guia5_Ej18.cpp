/*
18 Un supermercado tiene registrada la información de las ventas efectuadas
durante el mes pasado entre todas las sucursales y se solicita un programa
para obtener determinadas estadísticas.
Los datos que se disponen por cada una de las ventas efectuadas son:
● Número de sucursal (1 a 30)
● Día de la venta (1 a 31)
● Importe de la venta
● Tipo de venta (1=Particular, 2=Obra Social)
● Forma de Pago (1=Débito, 2=Crédito, 3=Contado)
Los datos están agrupados (no ordenados) por número de sucursal y puede
haber varias ventas para la misma sucursal, para el mismo día, etc. Puede haber
sucursales sin ventas durante todo el mes o durante algunos días del mes, no
habrá registros con importes iguales a 0. Al final de todo el lote se indicará con
un registro con número de sucursal igual a 0.
Se pide determinar e informar:
a) Para cada una de las sucursales el porcentaje de recaudación total por sus
ventas en crédito, débito y contado. Se informan 3 resultados por cada
sucursal.
b) Indicar en cual sucursal se hizo el menor porcentaje de recaudación total por
ventas de Tipo Obra Social. Se informa 1 resultado al final.
c) Para cada sucursal informar la primera y segunda venta individual de mayor
importe. Se informan 2 resultados por sucursal.
d) La venta de menor importe de todas las ventas, indicando la sucursal y el día
de la venta. Se informan 3 resultados al final.
*/



#include <iostream>
using namespace std;


int main(){
    setlocale(LC_ALL, "Spanish");
    int sucursal, dia, importe, tipo,formaPago,sucursalAnterior;//variables generales
    //variables punto a
    int recaudacionDebito,recaudacionCredito,recaudacionContado,recaudacionTotal=0;
    float ptjeDebito,ptjeCredito,ptjeContado;
    //variables punto b;
    int totalOs=0,sucursalMenor;
    float ptjeTotalOs, ptjeMenorOs;
    bool esMenor=false;
    //variablesPuntoC;
    int primerMayor,segundoMayor;
    //variables punto d
    int ventaMenor,sucursalVtaMenor,diaMenor;
    bool vtaMenor=false;

    cout<< "Ingrese el numero de sucursal(1 a 30) ";
    cin >> sucursal;

    while(sucursal!=0){

        sucursalAnterior=sucursal;
        //reiniciar variables de grupo
       recaudacionCredito=recaudacionDebito=recaudacionContado=0;
       primerMayor=segundoMayor=0;


        while(sucursalAnterior==sucursal){
            cout << "Ingrese Día de la venta (1 a 31)";
            cin >>dia;
            cout << "Ingrese Importe de la venta $" ;
            cin >>importe;
            cout << " Ingrese Tipo de venta (1=Particular, 2=Obra Social) ";
            cin >> tipo,
            cout << "Ingrese Forma de Pago (1=Débito, 2=Crédito, 3=Contado) ";
            cin >> formaPago;
            cout << "--------------------------------------------------------"<<endl;

            //punto A
            switch(formaPago){
                case 1: recaudacionDebito+=importe;
                        break;
                case 2: recaudacionCredito+=importe;
                        break;
                case 3: recaudacionContado+=importe;
                        break;
            }

            //punto b
            if(tipo==2){
                totalOs+=importe;
            }
            //punto C
            if(importe>primerMayor){
                segundoMayor=primerMayor;
                primerMayor=importe;
            }
            else if(importe>segundoMayor){
                segundoMayor=importe;
            }

            cout<< "Ingrese el numero de sucursal(1 a 30) ";
            cin >> sucursal;
        }
        //mostrar punto a
        recaudacionTotal=recaudacionContado+recaudacionCredito+recaudacionDebito,
        ptjeDebito=(float)(recaudacionDebito*100)/recaudacionTotal;
        ptjeCredito=(float)(recaudacionCredito*100)/recaudacionTotal;
        ptjeContado=(float)(recaudacionContado*100)/recaudacionTotal;
        cout <<"------------------------------------" << endl;
        cout<< "           Sucursal " << sucursalAnterior << endl;
        cout << "Porcentaje recaudacion Débito " << ptjeDebito << "%"<<endl;
        cout << "Porcentaje recaudacion Crédito " << ptjeCredito << "%"<<endl;
        cout << "Porcentaje recaudacion Contado " << ptjeContado << "%"<<endl;
        cout << "--------------------------------------------------------"<<endl;

        //punto b
        ptjeTotalOs=(totalOs*100)/recaudacionTotal;
        if(!esMenor || ptjeTotalOs<ptjeMenorOs){
            ptjeMenorOs=ptjeTotalOs;
            sucursalMenor=sucursalAnterior;
            esMenor=true;
        }


        //mostrar c
        cout << "La venta de mayor importe fue de $"<<primerMayor<<endl;
        cout << "La segunda venta de mayor importe fue de $"<<segundoMayor<<endl;

        //punto d
        if(!vtaMenor || importe<ventaMenor){
            ventaMenor=importe;
            sucursalVtaMenor=sucursalAnterior;
            diaMenor=dia;
            vtaMenor=true;
        }

    }

    //mostrar punto b
    cout << "La sucursal qu hizo el menor porcentaje de recaudación total por ventas de Tipo Obra Social fue " << sucursalMenor << endl;
    //mostrar punto c

    cout << "La menor venta se realizó el día "<<diaMenor<< ", en la sucursal " << sucursalVtaMenor <<", con un importe de $" << ventaMenor<<endl;
return 0;
}
