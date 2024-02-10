using System;

class Program
{
    static void Main()
    {
        int n, divisor = 1, contador = 0;
        Console.Write("Ingrese un número: ");
        n = int.Parse(Console.ReadLine());

        while (divisor <= n)
        {
            if (n % divisor == 0)
            {
                contador++;
            }
            divisor++;
        }

        if (contador == 2)
            Console.WriteLine("El número es primo.");
        else
            Console.WriteLine("No es primo.");
    }
}