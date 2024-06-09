using System;

class Program
{
    static void Main()
    {
        int numeros, primerMenor = 0, segundoMenor = 0;
        bool banderaMenor = false;

        Console.Write("Ingrese los números: ");
        numeros = int.Parse(Console.ReadLine());

        while (numeros != 0)
        {
            if (!banderaMenor) // banderaMenor == false
            {
                segundoMenor = 0;
                primerMenor = numeros;
                banderaMenor = true;
            }
            else if (numeros < primerMenor)
            {
                segundoMenor = primerMenor;
                primerMenor = numeros;
            }
            else if (numeros > primerMenor && numeros < segundoMenor)
            {
                segundoMenor = numeros;
            }

            Console.Write("Ingrese los números: ");
            numeros = int.Parse(Console.ReadLine());
        }

        Console.WriteLine($"El primer menor es: {primerMenor}");
        Console.WriteLine($"El segundo menor es: {segundoMenor}");
    }
}