/*
24 Se dispone de la información de los exámenes rendidos por algunos
estudiantes de la UTN FRGP. Por cada registro de examen se conoce:
- Legajo del estudiante (entero)
- Código de materia (entero)
- Nota (float)
La finalización de la carga de datos se indica con un legajo de estudiante mayor
a 30000. Calcular e informar:
A- La nota promedio entre todos los estudiantes.
B- El legajo del estudiante con menor nota.
C- La cantidad de exámenes rendidos para la materia 10.
D- El porcentaje de aprobados y no aprobados.
NOTA: Un examen se considera aprobado con nota >= 6
NOTA: Si hay varios estudiantes con la menor nota. Informar el primero de ellos.

*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");

	int legajo, cantAlumnos, codigoMateria, sumaNotas, cantExamenes, notaMenor;
	int legajoMenor, cantAprobados, cantDesaprobados;
	float nota, promedioTotal, ptjeAprobado, ptjeDesaprobados;

	cantExamenes=cantDesaprobados=cantDesaprobados=cantAlumnos=0;

	cout << "Ingrese el legajo ";
	cin >> legajo;


	while(legajo <= 30000){
		cantAlumnos++;
		cout << "Ingrese el código de la materia ";
		cin >> codigoMateria;
		cout << "Ingrese la nota ";
		cin >> nota;
	//	A- La nota promedio entre todos los estudiantes
		sumaNotas += nota;

	// B- El legajo del estudiante con menor nota.
		if(cantAlumnos==1 || nota < notaMenor){
			notaMenor =nota;
			legajoMenor = legajo;
		}
	//C- La cantidad de exámenes rendidos para la materia 10.
		if(codigoMateria==10){
			cantExamenes++;
		}
    //D- El porcentaje de aprobados y no aprobados.
		if (nota>=6){
			cantAprobados++;
		}else {
			cantDesaprobados++;

		}


		cout << "-----------------------" << endl;
		cout << "Ingrese el legajo ";
		cin >> legajo;
	}

	cout << "---------------------------------------------" << endl;
	//	A- La nota promedio entre todos los estudiantes
	promedioTotal = sumaNotas/cantAlumnos;
	cout << "La nota promedio es: " << promedioTotal << endl;

	// B- El legajo del estudiante con menor nota.
	cout << "El legajo del estudiante con menor nota es :" << legajoMenor << endl;
	//C- La cantidad de exámenes rendidos para la materia 10.
	if(cantExamenes>0){
		cout << "La cantidad de exámenes rendidos para la materia 10 es: " << cantExamenes << endl;
		}
	else{
		cout << "No se rindieron exámenes para la materia 10" << endl;
	}
	 //D- El porcentaje de aprobados y no aprobados.

	 ptjeAprobado = (float)cantAprobados/cantAlumnos;
	 ptjeDesaprobados = (float)cantDesaprobados/cantAlumnos;

	 if(cantAprobados==0){
		cout << "No aprobó ningún alumno " << endl;
	 }
	 else if( cantDesaprobados==0){
		cout << "No desaprobó ningún alumno" << endl;

	 }else{
	 	cout << "El porcentaje de alumnos aprobados fue: " << ptjeAprobado << "%" << endl;
	 	cout << "El porcentaje de alumnos desaprobados fue: " << ptjeDesaprobados << "%" << endl;
	 }

return 0;
}
