using System;

class Program
{
    static void Main()
    {
        int n, minPos = 0, maxNeg = 0;
        bool banderaMinPos = false, banderaMaxNeg = false;

        Console.Write("Ingrese un número: ");
        n = int.Parse(Console.ReadLine());

        while (n != 0)
        {
            if (n > 0)
            {
                if (!banderaMinPos)
                {
                    minPos = n;
                    banderaMinPos = true;
                }
                else if (n < minPos)
                {
                    minPos = n;
                }
            }
            else // (n < 0)
            {
                if (!banderaMaxNeg)
                {
                    maxNeg = n;
                    banderaMaxNeg = true;
                }
                else if (n > maxNeg)
                {
                    maxNeg = n;
                }
            }

            Console.Write("Ingrese un número: ");
            n = int.Parse(Console.ReadLine());
        }

        Console.WriteLine($"El mínimo positivo es: {minPos} y el máximo negativo es: {maxNeg}");
    }
}