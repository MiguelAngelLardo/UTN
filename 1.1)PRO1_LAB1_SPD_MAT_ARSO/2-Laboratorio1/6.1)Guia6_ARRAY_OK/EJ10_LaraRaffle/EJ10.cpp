#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;// Usamos el espacio de nombres estándar


/*****ARRAY*****/
const int COST_PER_NUMBER = 500;
const int TROPHY_WINNER = 30000;
const int SECOND_POSITION = 5000;

const int RAFLE_CAPACITY = 100;
/*****ARRAY*****/

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
  
  int number; 
  bool vRaffle[RAFLE_CAPACITY] = {};
  int totalPurchases = 0;//PUNTO A)

  cout << "Enter the number (0 al 99)(FINISH WHIT -1): " ;
  cin >> number;

  while(number != -1)
  {
    if(number >=0 && number < RAFLE_CAPACITY){
      if(!vRaffle[number]){
        vRaffle[number] = true;
        totalPurchases += COST_PER_NUMBER; //PUNTO A)
      }else
        cout << endl << "****Number " << number << " has already been sold. Enter a different number.****" << endl << endl;
    }else{
      cout << "*******Invalid number. Enter a number between 0 and 99.*********" << endl;
    }

    cout << "Enter the number (0 al 99)(FINISH WHIT -1): " ;
    cin >> number;
  }

  int firstPlace, secondPlace, prizesToBePaid = 0 ; //PUNTO D)
  cout << endl << "Registration completed. Please enter two numbers to determine the first and second place winners." << endl;
  cout << "Enter the number for the first place: ";
  cin >> firstPlace;
  cout << "Enter the number for the second place: ";
  cin >> secondPlace; 
  while(firstPlace == secondPlace){
    cout << "It is impossible to determine the first and second winners if both numbers are identical. Please enter different numbers." << endl;
    cout << "Enter the number for the first place: ";
    cin >> firstPlace;
    cout << "Enter the number for the second place: ";
    cin >> secondPlace; 
  }
 cout << endl;
 if(vRaffle[firstPlace] == false){
  cout << "The number " << firstPlace << " it was not purchased. No one got the first place " << endl;
 }else{
  cout << "You WIN! CONGRATULATION YOU'RE THE WINNER." << endl;
  prizesToBePaid += TROPHY_WINNER;
 }
 
 if(vRaffle[secondPlace] == false){
    cout << "The number " << secondPlace << " it was not purchased. No one got the second place " << endl;
 }else{
  cout << "You WIN! CONGRATULATION YOU'RE THE SECOND WINNERl, Well Done!" << endl;
  prizesToBePaid += SECOND_POSITION;
 }

  //PUNTO C)
  int noPurchase = 0;
  for (int x = 0; x < RAFLE_CAPACITY; x ++){
    if(vRaffle[x] == false){
      noPurchase ++;
    }
  }

  cout << endl << "PUNTO A) Total revenue from purchases for each raffle is: " << totalPurchases << endl;

  cout << "PUNTO B) ";
  if(totalPurchases > prizesToBePaid){
    cout << "Sr. Lara made a profit of $" << totalPurchases - prizesToBePaid << endl << endl;   
  }else{
    cout << "Sr.Lare incurred a loss of $" << totalPurchases - prizesToBePaid << endl << endl;
  }

  cout << "PUNTO C) No Purchases: %" << noPurchase << ". Purchases: %" << RAFLE_CAPACITY - noPurchase << ". Percentage of unsold numbers: " << fixed << setprecision(2) << (float)noPurchase * 100 / RAFLE_CAPACITY << "%." << endl;

  return 0;

}