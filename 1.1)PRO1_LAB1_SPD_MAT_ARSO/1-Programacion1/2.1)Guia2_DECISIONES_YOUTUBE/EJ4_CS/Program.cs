using System;

namespace practicas_clase1
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine("Ingrese un numero: ");
            int numero1 = int.Parse(Console.ReadLine());

            if(numero1 == 0)
                Console.WriteLine("Es un cero");
            else if(numero1 > 0)
                Console.WriteLine("Positivo");
            else   
                Console.WriteLine("Negativo");

            Console.WriteLine(numero1 == 0 ? "Es un  cero" : (numero1 > 0 ? "Positivo" : "Negativo"));
        }             
    }
}