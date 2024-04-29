#pragma once

void cargarDatos(int vCandidatos[], int *vMunicipios);
void puntoA(int vCandidatos[], int cantidadCandidato);
void puntoB (int vMunicipios[], int candidadMunicipios);

/**
 * Busca el valor mas grande dentro del vector y devuelvo su indice.
 * @param int El vector a buscar el maximo.
 * @param int La cantidad de elementos del vector.
 * @returns El indice correspondiente a el valor mas grande del vector.
*/
int buscarIndiceMaximo (int vectorBusqueda[], int cantidad);

/**
 * Cuenta cuantos elementos dentro del vectir son mayores a valorReferencia.
 * @param int El vector de busqueda.
 * @param int La cantidad de elementos del vector.
 * @param int El valor de referencia para contabilizar los elementos del vector.
 * @returns La cantidad de elementos del vector mayores al valor de referencia.
*/
int contarMayoresAReferencia(int vectorBusqueda[], int cantidad, int valorReferencia);