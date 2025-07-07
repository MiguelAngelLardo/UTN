#include <iostream> // Incluimos la librería iostream para entrada/salida estándar

using namespace std;
/*3) Diseñar una función que reciba como parámetros una cadena de caracteres, un valor 
entero que representa una posición de ella y 1 carácter, e inserte en la cadena el carácter dado en la posición pedida.
Ejemplo:

CADENA FUENTE: “Hola”
CARÁCTER: ’a’
POSICION: 1
CADENA RESULTADO: “Hala”
NOTA: la función no debe hacer nada si el valor de posición es mayor que la cantidad de caracteres de la cadena
*/

void cargarCadena(char *palabra, int tamanio);
int strlen2(char *vec);
void reemplazo(char *palabra, char letra1, int pos);

int main()
{
   char vCadena[50];
   cout << "Ingrese la frase: ";
   cargarCadena(vCadena, 49);

   reemplazo(vCadena, 'a', 5);
   cout << vCadena;

  return 0;
}

void cargarCadena(char *palabra, int tamanio){
 int i;
 fflush(stdin);
 for (i = 0; i < tamanio; i++){
		palabra[i] = cin.get();
		if (palabra[i]=='\n'){
		break;
		}
	}
	palabra[i]='\0';
	fflush(stdin);
}

int strlen2(char *vec){
  int indice = 0;            // h o l a '\a' 
  while(vec[indice] != '\0'){// 0 1 2 3  4
    indice ++;
  }
  return indice; //devuelve 4
}


void reemplazo(char *palabra, char letra1, int pos){
  int longitud = strlen2(palabra);
  if(pos > longitud){
    cout << "La longitud es mayor a las letras contenidas.";
  }else{
    palabra[pos] = letra1;
  }  
}    