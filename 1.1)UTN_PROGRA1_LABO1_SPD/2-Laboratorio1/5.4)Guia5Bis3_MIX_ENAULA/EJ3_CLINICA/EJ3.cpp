#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  int especialidad, numConsulta, duracionConsulta, diaSemana, horaDia;
  int contDiruno = 0, contTarde = 0, contNoche = 0, sumaTotal = 0;  // PTOC
  float totalFacturado = 0.0; //PTOD

  cout << "Ingrese la especialidad (CORTA CON NEGATIVO): ";
  cin >> especialidad;
 
  while(especialidad != 0)
  {
    int acc = 0, cont = 0; //PTO A
    float promConsulta = 0.0; //PTOA
    int maxDuracion = 0, maxHora = 0, maxConsultaMedica; // PTOB

    cout << "Ingrese numero Consulta (cambia registro con -1): ";
    cin >> numConsulta;
    while (numConsulta >=0)
    {
      cout << "Ingrese la duracion de la consulta: ";
      cin >> duracionConsulta;
      cout << "Ingrese el dia de la semana: ";
      cin >> diaSemana;
      cout << "Ingrese la hora: ";
      cin >> horaDia;
      //PTOA
      cont ++;
      acc += duracionConsulta;

      //PTOB
      if(diaSemana == 1 && duracionConsulta > maxDuracion){
        maxDuracion = duracionConsulta;
        maxHora = horaDia;
        maxConsultaMedica = numConsulta;
      }

      //PTOC
      if(horaDia >= 6 && horaDia <= 13){//diurno
        contDiruno ++;
      }

      if(horaDia >= 14 && horaDia <= 19){//tarde
        contTarde ++;
      }

      if(horaDia < 6 || horaDia > 19){//noche
        contNoche ++;
      }

      //PTOD
      if(diaSemana >= 1 && diaSemana <= 5)
      {
        totalFacturado += 2000;
        if(duracionConsulta > 30){
          totalFacturado += 500;
        }  
      }else if(diaSemana == 6 || diaSemana == 7){
        totalFacturado += 2000 * 1.25;
        if(duracionConsulta > 30){
          totalFacturado += 500 * 1.25;
        }
      }

      cout << "Ingrese numero Consulta (cambia registro con -1): ";
      cin >> numConsulta;
    }

    promConsulta = (float)acc / cont;
    cout << endl << "Promedio de consultas en la especialidad " << especialidad << ":" << fixed << setprecision(2) << promConsulta << endl;
    cout << "ESPECIALIDAD -> " << especialidad << " Consulta mvs extensa del dia lunes: " << maxConsultaMedica << " - Duracion: " << maxDuracion << " - Hora: " << maxHora << endl; 

    cout << "Ingrese la especialidad (CORTA CON NEGATIVO): ";
    cin >> especialidad; 
  }

  sumaTotal = contDiruno + contTarde + contNoche;
  cout << "suma total" << sumaTotal ;
  cout << "Porcentaje de consultas medicas segun Turno: \n";
  cout << "DIURNO: " << contDiruno * 100 / sumaTotal << "%\n";  
  cout << "TARDE: " << contTarde * 100 / sumaTotal << "%\n";
  cout << "NOCHE: " << contNoche * 100 / sumaTotal << "%\n"; 

  cout << endl << "TOTAL FACUTRADO: $" << totalFacturado << endl;

  return 0;
}

