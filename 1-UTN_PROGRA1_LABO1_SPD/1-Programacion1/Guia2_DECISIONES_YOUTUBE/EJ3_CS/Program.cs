using System;

namespace practicas_clase1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Ingrese un numero: ");
            int numero1 = int.Parse(Console.ReadLine());
             Console.WriteLine("Ingrese otro numero: ");
            int numero2 = int.Parse(Console.ReadLine());
            
            if(numero1 == numero2)
                Console.WriteLine("Son iguales.");
            else if (numero1 > numero2)
                Console.WriteLine("El mayor fue: " + numero1);
            else    
                Console.WriteLine("El mayor fue: " + numero2);

            Console.WriteLine (numero1 == numero2  ? "Son iguales." : (numero1 > numero2 ? "El mayor es: " + numero1 : "El mayor es: " + numero2));
        }             
    }
}