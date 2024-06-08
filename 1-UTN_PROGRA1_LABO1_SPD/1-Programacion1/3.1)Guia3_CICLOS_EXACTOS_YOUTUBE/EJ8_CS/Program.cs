using System;

namespace practicas_clase1
{
    class Program
    {
        static void Main(String [] args)
        {   
          int min = 0, posicion = 0;

          for(int x = 0; x < 10; x++){
            Console.WriteLine("Ingrese un numero: ");
            int num = int.Parse(Console.ReadLine());

            if (x == 0){
                min = num;
                posicion = 1;
            }else if (num < min){
                min = num;
                posicion = x+1;
            }    
          }
          Console.WriteLine("EL mayor numero es: " + min + " y esta en la posicion: " + posicion);
        }                     
    }
}