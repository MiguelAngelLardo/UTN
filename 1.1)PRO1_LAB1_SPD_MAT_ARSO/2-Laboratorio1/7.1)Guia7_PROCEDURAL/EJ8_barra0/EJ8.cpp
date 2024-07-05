#include <iostream> // Incluimos la librería iostream para entrada/salida estándar

using namespace std;// Usamos el espacio de nombres estándar

/*****ARRAY*****/
 const int TAM = 10;
/*****FUNCIONES*****///

void chargeCaracter(char vect[], int tam);
int counterCaracter(char vect[], int tam);

int main()
{
 char vLetters[TAM];
 int count;

 chargeCaracter(vLetters, TAM);
 count = counterCaracter(vLetters, TAM);

 cout << "The counter of letters is: " << count;

  return 0;
}

void chargeCaracter(char vect[], int tam){
  int i = 0; 
  cout << "Enter Character (FINISH WHIT ';'): ";
  cin >> vect[i];
  while (vect[i] != ';' && i < tam-1){
    i++;
    cout << "Enter Character (FINISH WHIT ';'): ";
    cin >> vect[i];
  }
  vect[i] = '\0';
}

int counterCaracter(char vect[], int tam){
  int counter = 0;
  for(int x = 0; x < tam && vect[x] != '\0'; x++){
    counter ++;
  }
  return counter;
}