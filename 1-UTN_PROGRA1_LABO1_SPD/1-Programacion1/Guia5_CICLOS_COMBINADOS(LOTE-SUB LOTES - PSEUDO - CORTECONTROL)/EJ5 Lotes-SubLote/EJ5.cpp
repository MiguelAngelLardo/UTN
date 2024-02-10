#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
  int minimoTodosLosGrupos, posicionDelGrupoDelMinimo, grupoDelMayorPromedio, posicionRelativaDelMinimo;
  float mayorPromedioDeTodosLosGrupos;
  bool banderaMayorPromedio = false;

  for(int x = 0; x < 10; x ++)
  { 
    int n, contTotalDelGrupo = 0, acumuladorDelGrupo = 0;
    float promedioDelGrupoActual = 0;

    cout << "Ingrese un numero: ";
    cin >> n;
    while(n != 0)
    {
      contTotalDelGrupo ++;
      acumuladorDelGrupo += n; 

      if(x==0){
        minimoTodosLosGrupos = n;
        posicionRelativaDelMinimo = contTotalDelGrupo;
        posicionDelGrupoDelMinimo = x + 1;
      }else if (n < minimoTodosLosGrupos){
        minimoTodosLosGrupos = n;
        posicionRelativaDelMinimo = contTotalDelGrupo;
        posicionDelGrupoDelMinimo = x + 1;
      }

     cout << "Ingrese un numero: ";
     cin >> n;    
    }

    promedioDelGrupoActual = (float)acumuladorDelGrupo/contTotalDelGrupo;

    if(!banderaMayorPromedio)
    {
      banderaMayorPromedio = true;
      mayorPromedioDeTodosLosGrupos = promedioDelGrupoActual;
      grupoDelMayorPromedio = x+1;
    }
    else 
    {
      if (promedioDelGrupoActual > mayorPromedioDeTodosLosGrupos) 
      {
        mayorPromedioDeTodosLosGrupos = promedioDelGrupoActual;
        grupoDelMayorPromedio = x+1;  
      }
    }

    cout << endl << "Grupo " << x+1 << ") El promedio de numeros es: " << fixed << setprecision(2) << promedioDelGrupoActual << endl;

  }  
  
  cout << "El numero minimo de todos los grupos es: " << minimoTodosLosGrupos << ". Es del grupo " << posicionDelGrupoDelMinimo << ". Su posicion en el grupo es: " << posicionRelativaDelMinimo << endl; 
  cout << "El mayor promedio de todos los grupos es: " << mayorPromedioDeTodosLosGrupos << ". Pertenece al grupo " << grupoDelMayorPromedio << endl;
 
  return 0;
}