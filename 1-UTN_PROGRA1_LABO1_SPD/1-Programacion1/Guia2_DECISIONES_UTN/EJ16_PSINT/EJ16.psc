Algoritmo EJ16
	Definir n1, n2, n3, n4, cantidadAprobadas Como Entero
	cantidadAprobadas <- 0
	Escribir 'Ingrese el numero 1: '
	Leer n1
	Escribir 'Ingrese el numero 2: '
	Leer n2
	Escribir 'Ingrese el numero 3: '
	Leer n3
	Escribir 'Ingrese el numero 4: '
	Leer n4
	
	Si n1>=4 Entonces
		cantidadAprobadas <- cantidadAprobadas + 1
	FinSi
	
	Si n2>=4 Entonces
		cantidadAprobadas <- cantidadAprobadas + 1
	FinSi
	
	
	Si n3>=4 Entonces
		cantidadAprobadas <- cantidadAprobadas + 1
	FinSi
	
	Si n4>=4 Entonces
		cantidadAprobadas <- cantidadAprobadas + 1
	FinSi
	
	Segun cantidadAprobadas Hacer
		1,2: 
			Escribir "Recupera Parciales"
		3: 
			Escribir	"Rinde Examen Final"
		4: 
			si n1 >= 7 Y n2 >= 7 Y n3 >= 7 Y n4 >= 7 Entonces
				Escribir "Promociona"
			SiNo
				Escribir "Rinde Examen Final"
				
			FinSi
			
	FinSegun
	
	
	
	
	
FinAlgoritmo
