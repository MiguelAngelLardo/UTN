using System;

namespace practicas_clase1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Ingrese un numero: ");
            int num1 = int.Parse(Console.ReadLine());
            Console.WriteLine("Ingrese otro numero: ");
            int num2 = int.Parse(Console.ReadLine());

            if (num1 < num2)
                Console.WriteLine("El menor fue: " + num1);
            else
                Console.WriteLine("El menor fue: " + num2);

            Console.WriteLine("El menor fue: " + (num1 < num2 ? num1 : num2));              
        }             
    }
}