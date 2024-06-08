//2) Hacer un programa que solicite por teclado que se ingresen dos números y luego 
//guardarlos en dos variables distintas. A continuación se deben intercambiar mutuamente los valores en ambas variables y mostrarlos por pantalla.
//Ejemplo: Suponiendo que se ingresan 3 y 8 como valores y que la variables usadas son A y B,
//entonces A=3 y B=8, pero luego debe quedar A=8 y B=3. 

Algoritmo EJ2_AUX
	Definir a, b, aux Como Entero
	
	Escribir "Ingrese el valor de a: "
	leer a
	Escribir "Ingrese el valor de b: "
	leer b
	
	aux <- a
	a <- b
	b <- aux
	
	Escribir "A = ", a, " - B = ", b
	
FinAlgoritmo
