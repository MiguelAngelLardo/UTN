using System;

namespace practicas_clase1
{
    class Program
    {
        static void Main(String [] args)
        {   
          int max = 0, posicion = 0;

          for(int x = 0; x < 10; x++){
            Console.WriteLine("Ingrese un numero: ");
            int num = int.Parse(Console.ReadLine());

            if (x == 0){
                max = num;
                posicion = 1;
            }else if (num > max){
                max = num;
                posicion = x+1;
            }    
          }
          Console.WriteLine("EL mayor numero es: " + max + " y esta en la posicion: " + posicion);
        }                     
    }
}