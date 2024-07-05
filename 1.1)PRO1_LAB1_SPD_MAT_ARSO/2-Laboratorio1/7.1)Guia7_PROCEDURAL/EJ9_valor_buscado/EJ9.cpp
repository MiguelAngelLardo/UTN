#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema
//setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
using namespace std;// Usamos el espacio de nombres estándar

/*****ARRAY*****/
 const int TAM = 10;
/*****FUNCIONES*****///pepa pig apunta a A - la guitarra de pepa es pepa misma

/*
  int *punteroA = &a;
  cout << "Memory Address of 'a': " << &a << endl;
  cout << "punteroA has the memory adress of 'a': " << punteroA << endl;
  cout << "&punteroA has its own memory Adress : " << &punteroA << endl;
  cout << "*punteroA has a value of 'a': " << *punteroA << endl;  */

/*****FUNCIONES*****/
void writeVector(char vect [], int tam);
int searchLetters(char vect[],int tam, char letter);

int main()
{
  char vLetters[TAM], letter;
  writeVector(vLetters, TAM);
  cout << endl;
  cout << "Enter the letter to compare: ";
  cin >> letter;
  searchLetters(vLetters, TAM, letter);

  return 0;
}

void writeVector(char vect [], int tam){
  int counter = 0;
  cout << "Enter de Letter (FINISH WHIT ';'): ";
  cin >> vect [counter];

  while(vect[counter] != ';' && counter < tam - 1){
    counter ++;
    cout << "Enter de Letter (FINISH WHIT ';): ";
    cin >> vect [counter];
  }
  vect[counter] = '\0';
  cout << "Vect is: " << endl;
  for (int x = 0; x < tam && vect[x] != '\0'; x ++){
    cout << vect[x] << " ";
  }
}

int searchLetters(char vect[],int tam, char letter){
  int counterLetters = 0;
  for(int x = 0; x < tam; x++){
    if(vect[x] == letter)
      counterLetters ++;
  }
  cout << "The letters '" << letter << "' appeared " << counterLetters << " times."; 
}