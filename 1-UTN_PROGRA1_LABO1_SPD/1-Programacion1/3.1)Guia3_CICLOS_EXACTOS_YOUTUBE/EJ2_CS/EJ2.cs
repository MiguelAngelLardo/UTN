using System;

namespace practicas_clase1
{
    class Program
    {
        static void Main(String [] args)
        {   
            int n, contador = 0;

            for (int i = 0; i < 5; i++){
                Console.WriteLine("Ingrese el numero " + (i+1) + ": ");
                n = int.Parse(Console.ReadLine());

                if (n > 0)
                    contador ++;
            }
            Console.WriteLine("La cantidad de numeros positivos son: " + contador);
        }                     
    }
}