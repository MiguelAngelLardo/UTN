using System;

namespace practicas_clase1
{
    class Program
    {
        static void Main(String [] args)
        {   
            int maxPrimo = 0;
            bool banderaMaxPrimo = false;
            for(int x = 0; x < 10; x++){
                Console.WriteLine("Ingrese un numero (" + (x+1) + "): ");
                int num = int.Parse(Console.ReadLine());

                int contador = 0;
                for (int y = 1; y <= num; y ++){
                    if (num % y == 0)
                        contador ++;
                }

                if (contador == 2)
                {
                    if (!banderaMaxPrimo)
                    {
                        maxPrimo = num;   
                        banderaMaxPrimo = true; 
                    }
                    else if (num > maxPrimo)
                    {
                        maxPrimo = num;
                    } 
                }
            }

            if (banderaMaxPrimo)
                Console.WriteLine("El maximo primo es: " + maxPrimo);
            else
                Console.WriteLine("No hay primos.");     
        }                     
    }
}