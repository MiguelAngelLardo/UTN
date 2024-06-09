using System;

class Program
{
    static void Main()
    {
        int edad, contador = 0;
        Console.Write("Ingrese una edad: ");
        edad = int.Parse(Console.ReadLine());

        while (edad >= 18)
        {
            contador++;
            Console.Write("Ingrese una edad: ");
            edad = int.Parse(Console.ReadLine());
        }

        Console.WriteLine($"Se registraron {contador} personas mayor de edad.");
    }
}