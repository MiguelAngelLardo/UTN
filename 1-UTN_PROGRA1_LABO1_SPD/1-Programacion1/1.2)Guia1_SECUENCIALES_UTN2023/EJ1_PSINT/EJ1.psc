
//1) Hacer un programa para ingresar por teclado la cantidad de horas trabajadas 
//por un operario y el valor que se le paga por hora trabajada y listar por pantalla el sueldo que le corresponda. 
Algoritmo EJ1
	Definir cantHoras, valorHora, sueldo Como Entero
	
	Escribir "Ingrese el valor hora: "
	Leer valorHora
	Escribir  "Ingrese la cantidad de horas: "
	Leer cantHoras
	
	sueldo <- cantHoras * valorHora
	
	Escribir "Su sueldo es " , sueldo
	
FinAlgoritmo
