using System;

class Program
{
    static void Main()
    {
        int n1, n2, menor = 0, mayor = 0;
        Console.Write("Ingrese numero 1: ");
        n1 = int.Parse(Console.ReadLine());
        Console.Write("Ingrese numero 2: ");
        n2 = int.Parse(Console.ReadLine());

        if (n1 > n2)
        {
            mayor = n1;
            menor = n2;
        }
        else
        {
            mayor = n2;
            menor = n1;
        }

        while (menor < mayor)
        {
            Console.WriteLine(menor);
            menor++;
        }
    }
}