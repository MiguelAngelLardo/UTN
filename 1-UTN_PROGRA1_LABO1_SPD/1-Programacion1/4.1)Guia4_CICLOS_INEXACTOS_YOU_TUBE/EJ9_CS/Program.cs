using System;

class Program
{
    static void Main()
    {
        int n, minimo1 = 0, minimo2 = 0;
        int posicion = 1, posPrimerMin = 0, posSegundoMin = 0;
        bool bandera = false;

        Console.Write("1) Ingrese un número: ");
        n = int.Parse(Console.ReadLine());
        minimo1 = n;
        posPrimerMin = posicion;

        while (n != 0)
        {
            if (n < minimo1)
            {
                minimo2 = minimo1;
                posSegundoMin = posPrimerMin;
                minimo1 = n;
                posPrimerMin = posicion;
            }
            else if (!bandera)
            {
                minimo2 = n;
                posSegundoMin = posicion;
                bandera = true;
            }
            else if (n < minimo2)
            {
                minimo2 = n;
                posSegundoMin = posicion;
            }

            Console.Write($"{posicion + 1}) Ingrese un número: ");
            n = int.Parse(Console.ReadLine());
            posicion++; // POSICION GENERAL
        }

        Console.WriteLine($"El primer número mínimo es: {minimo1} y está en la posición: {posPrimerMin}");
        Console.WriteLine($"El segundo número mínimo es: {minimo2} y está en la posición: {posSegundoMin}");
    }
}