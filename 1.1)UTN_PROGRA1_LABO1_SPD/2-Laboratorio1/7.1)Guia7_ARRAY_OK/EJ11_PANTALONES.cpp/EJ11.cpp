#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;// Usamos el espacio de nombres estándar

/*****FUNCIONES*****///pepa pig apunta a A - la guitarra de pepa es pepa misma

/*
  int *punteroA = &a;
  cout << "Memory Address of 'a': " << &a << endl;
  cout << "punteroA has the memory adress of 'a': " << punteroA << endl;
  cout << "&punteroA has its own memory Adress : " << &punteroA << endl;
  cout << "*punteroA has a value of 'a': " << *punteroA << endl;  */

/*****FUNCIONES*****/
int convertAsciiColorToIntIndex(char color){
  switch (color)
  {
    case 'N':
      return 0;    
    break;
    case 'A':
      return 1;    
    break;
    case 'B':
      return 2;    
    break;       
    case 'O':
      return 3;    
    break;
    default:
      return -1;
  }
}

char converIntToCharColor(int i){
  switch (i)
  {
    case 0:
      return 'N';    
    break;
    case 1:
      return 'A';    
    break;
    case 2:
      return 'B';    
    break;
    case 3:
      return 'O';    
    break;
  }
}

/*****ARRAY*****/
const int TOTAL_COLOR = 4; // PUNTO A
const int TOTAL_SEX = 2; // PUNTO A

const int TOTAL_DECADE = 10; //PUNTO B
/*****ARRAY*****/

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
  int age;
  char colorSelected, sex;
  
  int mColxSex_Accu[TOTAL_COLOR][TOTAL_SEX]; // PUNTO A
  for(int i = 0; i < TOTAL_COLOR; i++)
    for(int j = 0; j < TOTAL_SEX; j++)    
      mColxSex_Accu[i][j] = 0;

  int vCounterDecade[TOTAL_DECADE] = {}, decade; // PUNTO B

  cout << "Enter the age (1 to 99) (FINISH WHIT ZERO): ";
  cin >> age;
  
  int colorIndex, sexIndex;
  while(age != 0)
  {
    cout << "Enter your Color (N egro, A zul, B lanco, O tros): ";
    cin >> colorSelected;
    cout << "Enter your Sex(M or F): ";
    cin >> sex;    
    
    colorIndex = convertAsciiColorToIntIndex(colorSelected);
    sexIndex = (sex == 'M') ? 0 :1;

    mColxSex_Accu[colorIndex][sexIndex] ++; // PUNTO A

    decade = age/10; // PUNTO B
    vCounterDecade[decade] ++;// PUNTO B 


    cout << "Enter the age (1 to 99) (FINISH WHIT ZERO): ";
    cin >> age;
  }

  //PUNTO A COLOR MAS VOTADO POR LAS MUJERES
  int maxVoteFem = mColxSex_Accu[0][1]; //EL mayor INT voto
  int mostVotedColorIndex = 0; //El color del indice CERO
  for(int i = 1;  i < TOTAL_COLOR; i ++){
    if(mColxSex_Accu[i][1] > maxVoteFem){
      maxVoteFem = mColxSex_Accu[i][1];
      mostVotedColorIndex = i;
    } 
  }

  char mostVotedColor = converIntToCharColor(mostVotedColorIndex); // PUNTO A
  cout << endl << "Max voted color in Female case is: " << mostVotedColor << " whit " << maxVoteFem << " votes." << endl;  // PUNTO A

  cout << endl;
  for(int i = 0; i < TOTAL_DECADE; i ++){
    cout << "Total votes in DECADE #" << i << " are: " << vCounterDecade[i] << endl;
  }

  return 0;

}