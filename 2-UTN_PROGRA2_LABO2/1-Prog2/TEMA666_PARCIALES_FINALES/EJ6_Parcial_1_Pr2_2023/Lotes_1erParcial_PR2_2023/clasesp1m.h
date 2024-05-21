

void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}


class Fecha{
private:
    int dia,mes, anio;
public:
    void Cargar(){
        cout<<"DIA ";cin>>dia;
        cout<<"MES ";cin>>mes;
        cout<<"ANIO ";cin>>anio;
    }
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};





class Multa{
    private:
        int codigo;
        int categoria;
        char descripcion[40];
        float importe;
        bool estado;
    public:
        int getCodigo(){return codigo;}
        int getCategoria(){return categoria;}
        const char *getDescripcion(){return descripcion;}
        float getImporte(){return importe;}
        bool getEstado(){return estado;}
        void Cargar(){
            cout<<"CODIGO ";cin>>codigo;
            cout<<"CATEGORIA ";cin>>categoria;
            cout<<"DESCRIPCION ";cargarCadena(descripcion,39);
            cout<<"IMPORTE ";cin>>importe;
            estado=true;
        }
        void Mostrar(){
            cout<<"CODIGO "<<codigo<<endl;
            cout<<"CATEGORIA"<<categoria<<endl;
            cout<<"DESCRIPCION "<<descripcion<<endl;
            cout<<"IMPORTE "<<importe<<endl;
            cout<<endl;
        }

		void setEstado(bool e){estado=e;}
};

class Infraccion{
    private:
        int numero;
        int legajoInspector;
        int codigoMulta;
        int localidad;
        Fecha fechaMulta;
        bool estado;
    public:
        int getNumero(){return numero;}
        int getLegajoInspector(){return legajoInspector;}
        int getCodigoMulta(){return codigoMulta;}
        int getLocalidad(){return localidad;}
        Fecha getFechaMulta(){return fechaMulta;}
		bool getEstado(){return estado;}

        void Cargar(){
            cout<<"NUMERO ";cin>>numero;
            cout<<"LEGAJO ";cin>>legajoInspector;
            cout<<"CODIGO ";cin>>codigoMulta;
            cout<<"LOCALIDAD ";cin>>localidad;
            cout<<"FECHA "<<endl;fechaMulta.Cargar();
        }
        void Mostrar(){
            cout<<"NUMERO "<<numero<<endl;
            cout<<"LEGAJO "<<legajoInspector<<endl;
            cout<<"CODIGO "<<codigoMulta<<endl;
            cout<<"LOCALIDAD "<<localidad<<endl;
            fechaMulta.Mostrar();
            cout<<endl;
        }
		void setEstado(bool e){estado=e;}
};



class Inspector{
private:
        int legajo;
        char nombre[30];
        char apellido[30];
        char email[40];
        char telefono[20];
        Fecha fechaIngreso;
        int cargo;
        bool estado;
public:
    void Cargar(){
        cout<<"LEGAJO ";cin>>legajo;
        cout<<"NOMBRE ";cargarCadena(nombre,29);
        cout<<"APELLIDO ";cargarCadena(apellido,29);
        cout<<"EMAIL ";cargarCadena(email,29);
        cout<<"TELEFONO ";cargarCadena(telefono,29);
        fechaIngreso.Cargar();
        cout<<"CARGO ";cin>>cargo;
        estado=true;
    }
    void Mostrar(){
        if (estado==true){
        cout<<"LEGAJO "<<legajo<<endl;
        cout<<"NOMBRE "<<nombre<<endl;
        cout<<"APELLIDO "<<apellido<<endl;
        cout<<"EMAIL "<<email<<endl;
        cout<<"TELEFONO "<<telefono<<endl;
        fechaIngreso.Mostrar();
        cout<<"CARGO "<<cargo<<endl;
        }
    }

    int getLegajo(){return legajo;}
    int getCargo(){return cargo;}
    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    const char *getEmail(){return email;}
    bool getEstado(){return estado;}
	Fecha getFechaIngreso(){return fechaIngreso;};
    void setlegajo(int np){legajo=np;}
	void setEstado(bool e){estado=e;}
};

class ArchivoMultas{
private:
	char nombre[30];
public:
	ArchivoMultas(const char *n){
		strcpy(nombre, n);
	}
	Multa leerRegistro(int pos){
		Multa reg;
		reg.setEstado(false);
		FILE *p;
		p=fopen(nombre, "rb");
		if(p==NULL) return reg;
		fseek(p, sizeof reg*pos,0);
		fread(&reg, sizeof reg,1, p);
		fclose(p);
		return reg;
	}
		int contarRegistros(){
			FILE *p;
			p=fopen(nombre, "rb");
			if(p==NULL) return -1;
			fseek(p, 0,2);
			int tam=ftell(p);
			fclose(p);
			return tam/sizeof(Multa);
		}
			bool grabarRegistro(Multa reg){
				FILE *p;
				p=fopen(nombre, "ab");
				if(p==NULL) return false;
				int escribio=fwrite(&reg, sizeof reg,1, p);
				fclose(p);
				return escribio;
			}
};

class ArchivoInspectores{
private:
	char nombre[30];
public:
	ArchivoInspectores(const char *n){
		strcpy(nombre, n);
	}
	Inspector leerRegistro(int pos){
		Inspector reg;
		reg.setEstado(false);
		FILE *p;
		p=fopen(nombre, "rb");
		if(p==NULL) return reg;
		fseek(p, sizeof reg*pos,0);
		fread(&reg, sizeof reg,1, p);
		fclose(p);
		return reg;
	}
		int contarRegistros(){
			FILE *p;
			p=fopen(nombre, "rb");
			if(p==NULL) return -1;
			fseek(p, 0,2);
			int tam=ftell(p);
			fclose(p);
			return tam/sizeof(Inspector);
		}
			bool grabarRegistro(Inspector reg){
				FILE *p;
				p=fopen(nombre, "ab");
				if(p==NULL) return false;
				int escribio=fwrite(&reg, sizeof reg,1, p);
				fclose(p);
				return escribio;
			}
};

class ArchivoInfracciones{
private:
	char nombre[30];
public:
	ArchivoInfracciones(const char *n){
		strcpy(nombre, n);
	}
	Infraccion leerRegistro(int pos){
		Infraccion reg;
		reg.setEstado(false);
		FILE *p;
		p=fopen(nombre, "rb");
		if(p==NULL) return reg;
		fseek(p, sizeof reg*pos,0);
		fread(&reg, sizeof reg,1, p);
		fclose(p);
		return reg;
	}
		int contarRegistros(){
			FILE *p;
			p=fopen(nombre, "rb");
			if(p==NULL) return -1;
			fseek(p, 0,2);
			int tam=ftell(p);
			fclose(p);
			return tam/sizeof(Infraccion);
		}
			bool grabarRegistro(Infraccion reg){
				FILE *p;
				p=fopen(nombre, "ab");
				if(p==NULL) return false;
				int escribio=fwrite(&reg, sizeof reg,1, p);
				fclose(p);
				return escribio;
			}
};
