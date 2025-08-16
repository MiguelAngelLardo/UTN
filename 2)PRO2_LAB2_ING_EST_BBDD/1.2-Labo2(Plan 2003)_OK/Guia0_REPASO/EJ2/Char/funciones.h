#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

using namespace std;

///PROTOTIPOS
void ponerCeroMatriz(int mat [20][31], int fila, int col);
void mostrarMatriz(int mat [][31], int fila, int col);
bool ingresarDatosAccesos(int vMat[], int m[20][31]);
void pntoA(int vMat[], char mat[][30], int mAccesos[][31]);
void puntoB(int vMat[], char mat[][30]);
int buscarMaximo (float v[], int tam);
int buscarMaximo (int *v, int tam);

void puntoC(int m[20][31], char mat[][30]);

void cargarMaterias (char nombres[][30]);
void cargarCadena (char *pal, int tam);
void mostrarMatrizCaracteres (char m[][30], int cant);
void inicializarVector (float *v, int tam, int valor);
void inicializarVector (int *v, int tam, int valor);
void mostrarVector (int *v, int tam);

const char *mostrarMateria (char nombres[][30], int numero);//devuelve puntero char
bool estaEnCero(int m[][31], int fila);

///FIN PROTOTIPOS

bool estaEnCero(int m[][31], int fila){
  int suma = 0, i;
  for(i = 0; i < 31; i ++){
    suma += m [fila][i];
  }
  if(suma == 0){
    return true;
  }else{
    return false;

  }
}


const char *mostrarMateria (char nombres[][30], int numero){
  return nombres[numero-1];
}

///SOBRECARGA DE FUNCIONES: Me permite hacer funciones con el mismo nombre.
///Se elige cual usr de acuerdo al tipo de dato del parametro cuando se llama a la funcion.
void inicializarVector(float *v, int tam, int valor = 0){ ///Tercer valor es por DEFECTO
  for (int i = 0; i < tam; i ++){
    v[i] = valor;
  }
}

void inicializarVector(int *v, int tam, int valor = 0){ ///Tercer valor es por DEFECTO
  for (int i = 0; i < tam; i ++){
    v[i] = valor;
  }
}

void mostrarVector(float *v, int tam){
  for (int i = 0; i < tam; i ++){
    cout << v[i] << endl;
  }
}

void mostrarVector(int *v, int tam){
  for (int i = 0; i < tam; i ++){
    cout << v[i] << endl;
  }
}

void cargarCadena(char *pal, int tam){
  fflush(stdin);//elimina caracter no leido en el bufer de entrada 'stdin'
  int i;
  for(i = 0; i < tam; i ++){
    pal[i] = cin.get(); //lee el caracter y lo almacena en pal[i]
    if(pal[i] == '\n'){
      break;
    }
  }
  pal[i] = '\n';
  fflush(stdin);
}

void ponerCeroMatriz(int mat[20][31], int fila, int col){
  int i, j;
  for(i=0; i < fila; i++){
    for(j=0; j < col; j++){
      mat[i][j] = 0;
    }
  }
}

void mostrarMatriz(int mat[20][31], int fila, int col){
  int i, j;
  for(i=0; i < fila; i++){
    for(j=0; j < col; j++){
      cout << mat[i][j] << "\t";
    }
    cout << endl;
  }
}


bool ingresarDatosAccesos(int *vMat, int m[][31]){
  int legajo, dia, nroMat;
  cout << "LEGAJO: ";
  cin >> legajo;
  while(legajo != 0){
    cout << "MATERIA: ";
    cin >> nroMat;
    cout << "DIA: ";
    cin >> dia;
    ///PUNTO A y B
    vMat[nroMat-1]++;
    ///PUNTO C
    m[nroMat-1][dia-1]++;
    cout << "LEGAJO: ";
    cin >> legajo;
  }
  return true;
}

void puntoA(int vMat[], char mat[][30], int mAccesos[][31]){
  int x;
  cout << "MATERIAS SIN ACCESO" << endl;
  for (x = 0; x < 20; x ++){
    //if(vMat[x] ==0){
      if(estaEnCero(mAccesos, x)){
      cout << x+1 << "\t" << mat[x] << endl;
    }
  }
  system("pause");
}

void puntoB(int vMat[], char mat[][30]){
  int matMax;
  matMax = buscarMaximo(vMat, 20);
  cout << "LA MATERIA CON MAS ACCESOS FUE: " << matMax+1 << "\t" << mat[matMax] << endl;
}

int buscarMaximo (float *v, int tam){
  int posMax = 0;

  for (int x = 1; x < tam; x ++){
    if(v[x] > v[posMax]){
      posMax = x;
    }
  }
  return posMax;
}

int buscarMaximo (int *v, int tam){
  int posMax = 0;

  for (int x = 1; x < tam; x ++){
    if(v[x] > v[posMax]){
      posMax = x;
    }
  }
  return posMax;
}

void puntoC(int m[20][31], char mat[][30]){
  int i, j;
  for (i = 0; i < 20; i++){ //son 20 materias
    cout << "MATERIA: " << i + 1 << " " << mat [i] << endl; // lo que esta en matri< de nombre
    for(j = 0; j < 31; j ++){ //31 son los dias
      if(m[i][j] != 0){
        cout << "DIA " << j + 1 << " ACCESOS " << m[i][j] << endl;
      }
    }
    system("pause");
  }
}

void cargarMaterias (char nombres [][30]){
  int i, numeroMateria;
  for(i=0; i<10 ; i++){
    cout << "NUMERO MATERIA: ";
    cin >> numeroMateria;
    cout << "NOMBRE MATERIA: ";
    cargarCadena(nombres[numeroMateria-1], 29);
  }
}

void mostrarMatrizCaracteres (char m[][30], int cant){
  int i;
  for(i = 0; i < cant; i ++){
    cout << "NUMERO DE MATERIA: " << i+1 << "\t";
    cout << m[i] << endl;
  }
}


#endif // FUNCIONES_H_INCLUDED
