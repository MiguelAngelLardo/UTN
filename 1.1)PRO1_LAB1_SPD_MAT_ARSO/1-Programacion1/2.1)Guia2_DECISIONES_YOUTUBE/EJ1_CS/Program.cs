using System;

namespace practicas_clase1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Ingrese un numero para ver si es Mayor o Menor de 10: ");
            int numero = int.Parse(Console.ReadLine());

            if (numero > 10)
                Console.WriteLine("Es mayor a 10");
            else
                Console.WriteLine("No es mayor a 10");          

						Console.WriteLine(numero > 10 ? "Es mayor a 10" : "NO Es menor a 10");       
        }
    }
}