using System;

class Program
{
    const int TAM = 3;

    static void Main()
    {
        int n;
        int maxPar, maxImpar; // PTO A
        bool banderaPar, banderaImpar; // PTO A
        int cantidadPositivos, cantidadNegativos; // PTO B
        int contGeneral = 0; // PTO C

        for (int x = 0; x < TAM; x++)
        {
            Console.Write("Ingrese un numero: ");
            n = int.Parse(Console.ReadLine());

            maxPar = maxImpar = 0; // PTO A
            banderaPar = banderaImpar = false; // PTO A
            cantidadPositivos = cantidadNegativos = 0; // PTO B

            while (n != 0) // SUB GRUPO
            {
                contGeneral++; // PTO C

                if (n % 2 == 0) // PTO A
                {
                    if (!banderaPar)
                    {
                        maxPar = n;
                        banderaPar = true;
                    }
                    else if (n > maxPar)
                    {
                        maxPar = n;
                    }
                }
                else
                {
                    if (!banderaImpar)
                    {
                        maxImpar = n;
                        banderaImpar = true;
                    }
                    else if (n > maxImpar)
                    {
                        maxImpar = n;
                    }
                }

                if (n > 0) cantidadPositivos++; // PTO B
                else cantidadNegativos++;

                Console.Write("Ingrese un numero: ");
                n = int.Parse(Console.ReadLine());
            }

            Console.WriteLine($"SUB GRUPO(SUB LOTE) #{x + 1}");
            Console.WriteLine("***PUNTO A***");
            Console.WriteLine($"MAX PAR: {maxPar} - MAX IMPAR: {maxImpar}\n"); // PTO A 
            Console.WriteLine("***PUNTO B***");
            Console.WriteLine($"PORCENTAJES de POSITIVOS %: {100.0 * cantidadPositivos / (cantidadNegativos + cantidadPositivos):F2}");
            Console.WriteLine($"PORCENTAJES de NEGATIVOS %: {100.0 * cantidadNegativos / (cantidadNegativos + cantidadPositivos):F2}\n");
        }

        Console.WriteLine($"LA CANTIDAD TOTAL DE NUMEROS ES: {contGeneral}");
    }
}