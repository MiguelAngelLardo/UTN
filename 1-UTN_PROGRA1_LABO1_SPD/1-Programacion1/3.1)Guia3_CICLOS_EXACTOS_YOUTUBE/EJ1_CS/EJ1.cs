using System;

namespace practicas_clase1
{
    class Program
    {
        static void Main(String [] args)
        {   
            int n, max = 0;

            for (int i = 0; i < 5; i++){
                Console.WriteLine("Ingrese el numero " + (i+1) + ": ");
                n = int.Parse(Console.ReadLine());

                if(n > max)
                    max = n;
            }
            Console.WriteLine("El valor maximo es: " + max);   

            //--------------------BANDERA con la X del FOR--------------------------------------//

            int n2, max2 = 0;

            for (int x = 0; x < 5; x++){
                Console.WriteLine("Ingrese el numero " + (x+1) + ": ");
                n2 = int.Parse(Console.ReadLine());

                if (x==0)
                    max2 = n2;
                else if (n2 > max)
                    max2 = n2;
            }
            Console.WriteLine("El valor maximo es: " + max2);   
        }                     
    }
}