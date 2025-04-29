#ifndef FUNCADENAS_H_INCLUDED
#define FUNCADENAS_H_INCLUDED
void copiarCadenas();
void compararCadenas();
void variasCadenas();
void cargarPalabras(char [5][15]);
void mostrarPalabras(char [5][15]);

void copiarCadenas()
{
  system("cls");
  char cad1[15],cad2[15];
  cout<<"Ingrese la primer cadena: ";
  cin>>cad1;
  //Como son vectores, no se puede asignar directamente una cadena a otra.
  //La siguiente instrucción no es válida:
  //cad2=cad1;
  //Debe usarse la función strcpy(char *, char *) de la siguiente manera:
  strcpy(cad2,cad1);
  cout<<"La cadena 2 contiene: "<<cad2<<endl;
  system("pause");
  }


void compararCadenas()
{
  int valorDevuelto;
  system("cls");
  char cad1[15],cad2[15];
  cout<<"Ingrese la primer cadena: ";
  cin>>cad1;
  cout<<"Ingrese la segunda cadena: ";
  cin>>cad2;
  valorDevuelto=strcmp(cad1,cad2);
  if(valorDevuelto==0) cout<<"Las dos cadenas son iguales"<<endl;
  if(valorDevuelto>0) cout<<"La cadena 1 es mayor a la cadena 2"<<endl;
  if(valorDevuelto<0) cout<<"La cadena 2 es mayor a la cadena 1"<<endl;
  //Una cadena es mayor a otra cuando se encuentra más adelante en el diccionario.
  // Por ejemplo, zapato es más grande que cartera
  //Nota: no es necesario almacenar el valor devuelto por strcmp()
  //Podría haberse codificado de la siguiente manera:
  //if(strcmp(cad1,cad2)==0) cout<<"Las dos cadenas son iguales"<<endl;
  system("pause");
  }

void variasCadenas()
{
  char palabras[5][15]; //matriz para almacenar 5 palabras de hasta 14 caracteres
  cargarPalabras(palabras);
  mostrarPalabras(palabras);
  system("pause");
  }

void cargarPalabras(char pal[5][15])
{
  int i;
  for(i=0;i<5;i++)
    {
    cout<<"Ingrese una palabra: ";
    cin>>pal[i];
    }
  }

void mostrarPalabras(char pal[5][15])
  {
  int i;
  for(i=0;i<5;i++)
    {
    cout<<"Palabra: "<<i+1<<"\t";
    cout<<pal[i]<<endl;
    }
  }
#endif // FUNCADENAS_H_INCLUDED

