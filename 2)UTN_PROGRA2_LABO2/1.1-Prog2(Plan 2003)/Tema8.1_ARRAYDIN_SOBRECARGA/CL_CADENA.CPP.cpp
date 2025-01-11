#include<iostream>

using namespace std;


class Cadena
	{
	private:
		char *p;
		int tam;
	public:
		Cadena(const char*);//constructor
		Cadena (const Cadena &c):p(NULL){*this=c;};// constructor de copia
		~Cadena(){if(p)delete p;};
		const char *getP(){return p;}
		void setP(const char *cad);
		void setP(const Cadena &);
	  void Mostrar();
	  //SOBRECARGAS
	   //void operator=(Cadena &);// Limita la asignaci¢n a uno a uno a=b
		Cadena& operator=(const Cadena &);//Permita apilar a=b=c=d
		Cadena& operator=(const char *);  //Para asignar una cadena a un objeto Cadena

		bool operator==(const Cadena &obj);
		bool operator==(const char *obj);

		void operator+=(const char *obj);
    void operator+=(const Cadena&);

		Cadena operator+(const Cadena&);//Para sumar 2 objetos Cadena
		Cadena operator+(const char *);//Para sumar un objeto Cadena con una cadena

		friend ostream& operator<<(ostream &salida,Cadena &obj);
		friend istream& operator>>(istream &entrada,Cadena &obj);

	};
//DESARROLLO DE LOS METODOS
//CONSTRUCTOR
Cadena:: Cadena(const char *cad=NULL)
	{
	if(cad==NULL){
	  p=NULL;
	  tam=0;
	  return;
	  }
	tam=strlen(cad)+1;
	p=new char[tam];
	if(p==NULL) exit(1);
	strcpy(p,cad);
	}


//SETS
void Cadena::setP(const char *cad){
  if(p)delete p;
  tam=strlen(cad)+1;
  p=new char[tam];
  if(p==NULL) exit(1);
  strcpy(p,cad);
  }

void Cadena::setP(const Cadena &cad){
  if(p)delete p;
  tam=cad.tam;
  p=new char[tam];
  if(p==NULL) exit(1);
  strcpy(p,cad.p);
  }

//MOSTRAR
void Cadena::Mostrar()
	{
	cout<<p;
	}


//SOBRECARGAS
/*void Cadena::operator=(const char *cad)//Para asignar un objeto a otro
	{
	tam=strlen(cad)+1;
	delete p;
	p=new char[tam];
	if(p==NULL) exit(1);
	strcpy(p,cad);
	 }
*/
//ASIGNACION
Cadena& Cadena::operator=(const char *cad)//Para asignar a un objeto una cadena
	{
	if(p)delete p;
	tam=strlen(cad)+1;
	p=new char[tam];
	if(p==NULL) exit(1);
	strcpy(p,cad);
	return *this;
	}

Cadena& Cadena::operator=(const Cadena &c)
{
if(this != &c)
{
  delete p;
  if(c.p)
    {
    p= new char[c.tam];
    strcpy(p, c.p);
    }
  else p = NULL;
}
return *this;
}

//==
bool Cadena::operator==(const Cadena &obj)//Para comparar dos objetos
	{
	if(strcmp(p,obj.p)==0) return true;
	return false;
	}

bool Cadena::operator==(const char *obj)//Para comparar un objeto con una cadena
	{
	if(strcmp(p,obj)==0) return true;
	return false;
	}

//+
Cadena Cadena::operator+(const Cadena &obj) //Para concatenar dos objetos Cadena en un 3
	{
	Cadena aux;
	aux.tam=tam+obj.tam-1;
	aux.p=new char[aux.tam];
	if(aux.p==NULL) exit(1);
	strcpy(aux.p,p);
	strcat(aux.p,obj.p);
	return aux;
	}

Cadena Cadena::operator+(const char *obj)//Para concatenar un objeto con una cadena
	{
	Cadena aux;
	aux.tam=strlen(p)+strlen(obj)+1;
	aux.p=new char[aux.tam];
	if(aux.p==NULL) exit(1);
	strcpy(aux.p,p);
	strcat(aux.p,obj);
	return aux;
	}

//+=
void Cadena::operator+=(const char *obj)//Para concatenar un objeto con una cadena
	{
	char *temp;
	temp=new char[tam];
	if(temp==NULL) exit(1);
	strcpy(temp,p);
	tam=tam+strlen(obj)+1;
	delete p;
	p=new char[tam];
	if(p==NULL) exit(1);
	strcpy(p,temp);
	strcat(p,obj);
	delete temp;
	}

void Cadena::operator+=(const Cadena &cad)//Para concatenar dos objetos cadena
	{
	char *temp;
	temp=new char[tam];
	if(temp==NULL) exit(1);
	strcpy(temp,p);
	tam=tam+cad.tam-1;
	delete p;
	p=new char[tam];
	if(p==NULL) exit(1);
	strcpy(p,temp);
	strcat(p,cad.p);
	delete temp;
	}

//FUNCIONES AMIGAS PARA USAR CIN Y COUT
//NOTESE QUE DENTRO DE ESTAS FUNCIONES NO EXISTE this
//YA QUE NO SON FUNCIONES DE LAS CLASES
ostream& operator<<(ostream &salida,Cadena &obj)
	{
	salida<<obj.p;
	return salida;
	}

istream& operator>>(istream &entrada,Cadena &obj)
	{
	char palabra[30];
	entrada>>palabra;
	delete obj.p;
	obj.tam=strlen(palabra)+1;
	obj.p=new char[obj.tam];
	strcpy(obj.p,palabra);
	return entrada;
	}


int main()
	{
	Cadena a("Hola a todos"),b("chau"),c;
  char z[20];
  cout<<"Muestra el valor que le pasamos en el constructor: ";
  cout<<a<<endl<<endl;//PODEMOS USAR cout<< POR LA SOBRECARGA
  cout<<"Se asigna una cadena literal a un objeto Cadena y lo muestra: ";
  c="Prueba";
  cout<<c<<endl<<endl;
  cout<<"Se ingresa un valor en una cadena y se asigna a un objeto: ";
  cin>>z;
  a=z;
  cout<<a<<endl<<endl;
  cout<<"A la cadena anterior se le suma otra y se la muestra: ";
  a+=" Palabra";
  cout<<a<<endl<<endl;
  cout<<"SE SUMAN OBJETOS Y CADENAS LITERALES"<<endl;
	a=b+" "+c+" "+"otra"+" "+"palabra";
	cout<<a<<endl;
	a=b+"alguna"+" palabra";
	cout<<a<<endl;

  cout<<a.getP()<<endl;
  a.setP("esta es una prueba del uso del setP para la clase Cadena");
  cout<<a.getP()<<endl;
  a.setP(c);
  cout<<a.getP()<<endl;
 	return 0;
	}

