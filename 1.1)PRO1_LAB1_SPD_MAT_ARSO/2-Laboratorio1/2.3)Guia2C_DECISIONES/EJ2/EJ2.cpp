/**
Igual al Problema 1 pero el programa debe poder informar también el vuelto que debe
otorgarse al cliente, si es que debe hacerlo

------------------------------------------------------
| Datos Entrada ---> ???? ---> Información de salida |
------------------------------------------------------

UX: User Experience --> Experiencia del usuario
UI: User Interface ---> Interfaz del usuario

*/
#include <iostream>
using namespace std;

int main()
{

    float precioUnitario, importeVenta, abonaCon, vuelto;
    string nombreProducto;
    int cantidadUnidades;

    cout << "Nombre de producto: ";
    cin >> nombreProducto;
    cout << "Cantidad de unidades: ";
    cin >> cantidadUnidades;
    cout << "Precio Unitario: $";
    cin >> precioUnitario;

    importeVenta = precioUnitario * cantidadUnidades;

    cout << endl;
    cout << endl << nombreProducto << " " << cantidadUnidades << " u. x $";
    cout << precioUnitario << " : $" << importeVenta;

    cout << endl << "Abona con: $";
    cin >> abonaCon;

    vuelto = abonaCon - importeVenta;

    if (vuelto < 0)
    {
        cout << endl << "Falta abonar dinero: $" << vuelto * (-1) << endl;
    }
    else
    {
        if (vuelto == 0)
        {
            cout << endl << "Pago exacto";
        }
        else
        {
            cout << endl << "Vuelto $ " << vuelto << endl;
        }
    }
    return 0;
}