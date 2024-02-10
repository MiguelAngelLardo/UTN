using System;

namespace practicas_clase1
{
    class Program
    {
        static void Main(String [] args)
        {   
            int maxPar = 0, minImpar = 0;
            bool banderaMaxPar = false, banderaMinImpar = false;

            for(int x = 0; x < 10; x++){
                Console.WriteLine("Ingrese un numero: ");
                int numero = int.Parse(Console.ReadLine());

                if (numero %2 == 0){
                    if (!banderaMaxPar){
                        maxPar = numero;
                        banderaMaxPar = true;
                    }else if(numero > maxPar){
                        maxPar = numero;
                    }
                }else{ 
                    if(!banderaMinImpar){
                        minImpar = numero;
                        banderaMinImpar = true;
                    }else if (numero < minImpar){
                        minImpar = numero;  
                    }       
                }       
            }
            Console.WriteLine("El mayor par es: " + maxPar + " y el menor impar es: " + minImpar);
        }                     
    }
}