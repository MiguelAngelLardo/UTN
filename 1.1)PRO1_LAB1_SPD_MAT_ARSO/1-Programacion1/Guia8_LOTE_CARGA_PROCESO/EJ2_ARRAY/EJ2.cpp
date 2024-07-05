#include <iostream>

using namespace std;

int main()
{
    int vecArt[3] = {};
    int vecArtCliente[3] = {};
    int vecCant[3] = {};
    int vecStock[3] = {};
    float vecPrecio[3] = {};

    int nro_articulo, nro_cliente, cant_vendidad, cliente_max_importe, stock, importe_total;
    float precio, max_importe = 0;

    for (int i = 0; i < 3; i++)
    {
        cout << "Numero de articulo: ";
        cin >> nro_articulo;
        cout << "Stock: ";
        cin >> stock;
        cout << "Precio unitario: ";
        cin >> precio;

        vecArt[i] = nro_articulo;
        vecPrecio[i] = precio;
        vecStock[i] = stock;
    }

    cout << "Numero de cliente: ";
    cin >> nro_cliente;

    while (nro_cliente != 0)
    {
        cout << "Numero de articulo: ";
        cin >> nro_articulo;
        cout << "Cantidad vendida: ";
        cin >> cant_vendidad;

        for (int i = 0; i < 3; i++)
        {
            if (nro_articulo == vecArt[i])
            {
                if (vecStock[i] >= cant_vendidad)
                {
                    vecStock[i] -= cant_vendidad;
                    vecArtCliente[nro_cliente - 1] = nro_articulo; // solo guardo aquellos registros con stock disponible.
                    vecCant[nro_cliente - 1] += cant_vendidad;
                }
                else
                {
                    cout << "No se dispone de stock para este articulo \n";
                }
            }
        }
        cout << "Numero de cliente: ";
        cin >> nro_cliente;
    }

    cout << "*****Listado de ventas***** \n";
    cout << "Nro cliente |"
         << " "
         << "Nro articulo |"
         << " "
         << "Cant vendida |"
         << " "
         << "Importe total\n";
    for (int z = 0; z < 3; z++)
    {
        for (int x = 0; x < 3; x++)
        {
            if (vecArtCliente[z] == vecArt[x] && vecCant[z] != 0)
            {
                importe_total = vecCant[z] * vecPrecio[x];
            }
        }
        // A
        if (vecCant[z] != 0)
        {
            cout << z + 1 << "             " << vecArtCliente[z] << "             " << vecCant[z] << "             " << '$' << importe_total << endl;
        }

        if (importe_total > max_importe)
        {
            max_importe = importe_total;
            cliente_max_importe = z + 1;
        }
    }
    // B
    cout << "Cliente que mas compro en total: " << cliente_max_importe << endl;

    cout << endl;

    // C
    cout << "Articulos que no registraron ventas: \n";
    for (int z = 0; z < 3; z++)
    {
        if (vecCant[z] == 0 && vecArtCliente[z] != 0)
        {
            cout << "Codigo de articulo: " << vecArtCliente[z] << endl;
        }
    }

    cout << endl;
    return 0;
}