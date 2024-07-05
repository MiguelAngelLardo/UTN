using System;

class Program
{
    static void Main()
    {
        int n, posicion = 0, posicionMax = 0, maxNum = 0;
        bool banderaMax = false;
        
        Console.Write("Ingrese un número: ");
        n = int.Parse(Console.ReadLine());

        while(n != 0)
        {
            posicion++;
            if (!banderaMax) // banderaMax == false
            {
                maxNum = n;
                banderaMax = true;
                posicionMax = posicion;
            }
            else if (n > maxNum)
            {
                maxNum = n;
                posicionMax = posicion;
            }

            Console.Write("Ingrese un número: ");
            n = int.Parse(Console.ReadLine());
        }

        Console.Write("El numero maximo es " + maxNum + " y esta en la posicion #" + posicionMax);
    }
}