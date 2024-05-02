#pragma once

void cargarCadena(char *palabra, int tamano){ //⇒ aca si pongo 9 por que usa el 0 del for
	int i=0;
	fflush(stdin);
	for (i=0; i<tamano; i++){
		palabra[i]=cin.get();
		if (palabra[i]=='\n'){
		break;
		}
	}
	palabra[i]='\0';
	fflush(stdin);
}
