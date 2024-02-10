#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{
  
  int numeroArtista, integrante, jornada, duracionShow, showMasLargo = 0, numeroArtistaShowMasLargo;
  int contSolistaJornada1 = 0, contSolistaJornada2 = 0, contSolistaJornada3 = 0;
  int jornadaMasExtensa = 0;
  int acumuladorDuracionJornada1 = 0, acumuladorDuracionJornada2 = 0, acumuladorDuracionJornada3 = 0;
  int artistaActual, contadorShowArtistaActual = 0;

  cout << "Ingrese el numero del artista: "; 
  cin >> numeroArtista;
  cout << "Ingrese la cantidad de integrante: "; 
  cin >> integrante;
  cout << "Ingrese la jornada (1, 2, 3): "; 
  cin >> jornada;
  cout << "Duracion del Show: "; 
  cin >> duracionShow;

  while(numeroArtista != 0)
  {
    if(jornada ==1){
      if(showMasLargo ==  0){
        showMasLargo = duracionShow;
        numeroArtistaShowMasLargo = numeroArtista;
      }else if(duracionShow > showMasLargo){
        showMasLargo = duracionShow;
        numeroArtistaShowMasLargo = numeroArtista;
      }
    }

    if(integrante == 1)
    {
      switch (jornada)
      {
      case 1:
        contSolistaJornada1 ++;
      break;
      case 2:
        contSolistaJornada2 ++;
      break;
      case 3:
        contSolistaJornada3 ++;
      break;            
      }
    }

    if(jornadaMasExtensa == 0){
      jornadaMasExtensa = duracionShow;
    }else if (duracionShow > jornadaMasExtensa){
      jornadaMasExtensa = duracionShow;
    }  

    if (numeroArtista != artistaActual){
      contadorShowArtistaActual = 0;
      acumuladorDuracionJornada1 = 0;
      acumuladorDuracionJornada2 = 0;
      acumuladorDuracionJornada3 = 0;
    }
    
    artistaActual = numeroArtista;
    if (numeroArtista == artistaActual){
      contadorShowArtistaActual ++;
      switch (jornada)
      {
        case 1:
          acumuladorDuracionJornada1 += duracionShow;
        break;
        case 2:
          acumuladorDuracionJornada2 += duracionShow;
        break;
        case 3:
          acumuladorDuracionJornada3 += duracionShow;
        break;   
      }  
    }   

    cout << "Ingrese el numero del artista: "; 
    cin >> numeroArtista;

    if(numeroArtista != artistaActual){      
      cout << endl << "EL Artista " << artistaActual << " promedio " << (float)(acumuladorDuracionJornada1 + acumuladorDuracionJornada2 + acumuladorDuracionJornada3)/contadorShowArtistaActual << " minutos de show." << endl; 
    }

    if(numeroArtista != 0){
      cout << "Ingrese la cantidad de integrante: "; 
      cin >> integrante;
      cout << "Ingrese la jornada (1, 2, 3): "; 
      cin >> jornada;
      cout << "Duracion del Show: "; 
      cin >> duracionShow;
    }

  }

  cout << endl << "Numero artista con show mas largo en la jornada 1: " << numeroArtistaShowMasLargo << ". Duracion del show: " << showMasLargo << " min." << endl;
  cout << "Cantidad de solistas => jornada 1: " << contSolistaJornada1 << " - jornada 2: " << contSolistaJornada2 << " - jornada 3: " << contSolistaJornada3 << endl;
  cout << "La jornada mas extanse fue de " << jornadaMasExtensa << " minutos." << endl;

 return 0;

}