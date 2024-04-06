#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

#include <iostream>
using namespace std;

void imprimirMatriz(int** matriz, int n, int tamanoMaximo);
int** crearMatriz(int n);
int obtenerContenidoCelda(int** matriz, int fila, int columna);
int compararMatrices(int** matriz1, int** matriz2, int fila, int columna, int n, int& rotacionesSinExito, int& totalRotaciones);
void liberarMatriz(int** matriz, int n);
int*** crearArregloDeMatrices(int* tamanos, int numMatrices);
void igualarTamanos(int*** cerradura, int* tamanos, int numCerraduras, int tamanoMaximo);
void imprimirCerradura(int*** cerradura, int* tamanos, int numCerraduras, int tamanoMaximo);
bool esDigito(char c);
bool esNumeroEnteroPositivo(const char* str);
#endif // PROTOTIPOS_H
