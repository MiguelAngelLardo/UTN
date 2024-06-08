#include<stdio.h>

int main(){

  int opcionProcesador, opcionRam, opcionDisco, totalPagar;

  printf ("Ingrese el procesador (1 - I5, 2 - I7, 3 - I9)");
  scanf("%i", &opcionProcesador);
  printf ("Ingrese la RAM (1 - 8RAM, 2 - 16RAM, 3 - 32RAM)");
  scanf("%i", &opcionRam);
  printf ("QUIERE EXTENDER EL DISCO(1 - SI, 2 - NO");
  scanf("%i", &opcionDisco);

  switch (opcionProcesador)
  {
    //opcionProcesador == 1 
    case 1:
    switch (opcionRam)
    {
      case 1:
        totalPagar = 800;      
      break;

      case 2:
        totalPagar = 900;
      break;

      case 3:
        totalPagar = 100;
      break;  
    }
    break;

    //opcionProcesador == 2 
    case 2:
   	switch (opcionRam)
   	{
   		case 1:
				totalPagar = 900;
			break;
			
			case 2:
				totalPagar = 1000;
			break;
			
			case 3:
				totalPagar = 1400;
			break; 	
		}
    break;
	
	  //opcionProcesador == 3 
    case 3: 
	 	switch	(opcionRam)
	 	{
	 		case 1:
	 			totalPagar = 1200;
	 		break;
			 	
			case 2:
				totalPagar = 1400;
			break;
			
			case 3:
				totalPagar = 2000;
			break;	
	 	}   
    break;
  }
  
  /* if(opcionDisco == 1)
	{
  	totalPagar = totalPagar + 300;
	} */
	totalPagar = (opcionDisco) ? totalPagar + 300 : totalPagar;
	
	printf("El total a pagar es: $%i", totalPagar);
	
	return 0;
}