using System;

namespace practicas_clase1
{
    class Program
    {
        static void Main(String [] args)
        {   
            int contador = 0, acumulador = 0;

            for(int x = 0; x < 5; x++){
                Console.WriteLine("Ingrese una edad: ");
                int edad = int.Parse(Console.ReadLine());

                if (edad > 18){
                    contador++;
                    acumulador += edad;
                }
            }
            Console.WriteLine("EL promedio de edades es: " + (float)(acumulador/contador));
        }                     
    }
}