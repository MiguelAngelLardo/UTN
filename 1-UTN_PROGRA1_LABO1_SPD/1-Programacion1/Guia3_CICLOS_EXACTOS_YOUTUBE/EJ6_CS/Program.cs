using System;

namespace practicas_clase1
{
    class Program
    {
        static void Main(String [] args)
        {   
            int contador = 0;           
            Console.WriteLine("Ingrese un numero: ");
            int num = int.Parse (Console.ReadLine());
            for (int x = 1; x <= num; x++){
                if( num % x == 0)
                    contador ++;
            }
            if (contador == 2)
                Console.WriteLine("Primo");
            else   
                Console.WriteLine("No primo");
        }                     
    }
}