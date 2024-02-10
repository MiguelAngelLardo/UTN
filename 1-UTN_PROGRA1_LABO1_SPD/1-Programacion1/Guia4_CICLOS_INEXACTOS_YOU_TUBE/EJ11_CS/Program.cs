using System;

class Program
{
    static void Main()
    {
        int n, contPos = 0, contNeg = 0, contPares = 0, contPrimo = 0;

        Console.Write("Ingrese un número: ");
        n = int.Parse(Console.ReadLine());

        int x, prePrimo; // PUNTO C
        while (n != 0)
        {
            contPos += (n > 0) ? 1 : 0; // PUNTO A
            contNeg += (n < 0) ? 1 : 0;

            contPares += (n % 2 == 0) ? 1 : 0; // PUNTO B

            x = 1;
            prePrimo = 0;
            while (x <= n)
            {
                prePrimo += (n % x == 0) ? 1 : 0;
                x++;
            }
            contPrimo += (prePrimo == 2) ? 1 : 0;

            Console.Write("Ingrese un número: ");
            n = int.Parse(Console.ReadLine());
        }

        Console.WriteLine($"NUMEROS POSITIVOS #{contPos}");
        Console.WriteLine($"NUMEROS NEGATIVOS #{contNeg}");
        Console.WriteLine($"NUMEROS PARES #{contPares}");
        Console.WriteLine($"NUMEROS PRIMOS #{contPrimo}");
    }
}