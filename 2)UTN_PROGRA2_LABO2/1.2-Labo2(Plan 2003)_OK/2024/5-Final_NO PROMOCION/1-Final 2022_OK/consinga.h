/*
Resolver los siguientes ejercicios utilizando C++.
1) Realizar una clase Conjunto que represente un conjunto matemático de números enteros. Para
ello deberán realizar:
- Un constructor que reciba un tamaño y solicite memoria de forma dinámica para esa
cantidad.
- Hacer un método llamado Agregar al cual se le envíe como parámetro un valor y este sea
agregado a la posición disponible más inmediata. En caso de haber ocupado todos los
elementos del conjunto, no almacenar el valor. Además, verificar que dicho valor no se
encuentre repetido dentro del conjunto.
- Hacer un método llamado getTamanio que devuelva la cantidad de elementos agregados.
- Hacer un método llamado getElemento que reciba como parámetro una posición y
devuelva el contenido del conjunto en dicha posición.
- Hacer una función global llamada CompararConjuntos que reciba dos objetos de tipo
Conjunto y devuelva true si ambos conjuntos son iguales o false si no lo son.
NOTA: Para que dos conjuntos sean iguales deberán tener el mismo tamaño y exactamente los
mismos elementos sin importar su orden.
Por ejemplo:
Conjunto A(1, 2, 3) es igual a Conjunto B(2, 3, 1)
Conjunto A(1, 2, 3) no es igual a Conjunto B(1, 2, 3, 4)
2) Dada las clases Participante, Participacion y participaciones.dat, hacer los métodos de clase y
funciones globales que considere necesarios para resolver los siguientes puntos:
A) Un listado general con todos los participantes de género femenino y su mejor
lanzamiento:
Mejores lanzamientos de participantes femeninos:
Simón, Angela
75 mts
Lara, Briana
80 mts
González, Juana
95 mts
Kloster, Daniela
77 mts
. . .
B) La cantidad de participantes que hayan registrado al menos un foul.
NOTA: Un lanzamiento es considerado foul si sus metros son iguales a cero
*/