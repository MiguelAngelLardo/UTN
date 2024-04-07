#include <iostream> // Incluimos la librería iostream para entrada/salida estándar

using namespace std;
/*2) Hacer una función que reciba como parámetros una cadena de caracteres y dos caracteres, y r
eemplace en la cadena todas las ocurrencias del primer carácter dado por el segundo.
Ejemplo:
CADENA FUENTE: “La mar estaba serena”
CARÁCTER 1: ‘a’
CARÁCTER 2: ‘i’
CADENA RESULTADO: “Li mir estibi sereni”
*/

void cargarCadena(char *palabra, int tamanio);
void reemplazo(char *palabra, char letra1, char letra2);

int main()
{
   char vCadena[50];
   cout << "Ingrese la frase: ";
   cargarCadena(vCadena, 49);
   reemplazo(vCadena, 'a', 'i');
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

void reemplazo(char *palabra, char letra1, char letra2){
  int index = 0;
  while (palabra[index] != '\0'){
   if(palabra[index] == letra1){
    palabra[index] = letra2;
   }
   index ++;
  }
}    