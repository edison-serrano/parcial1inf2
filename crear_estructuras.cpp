/*módulo para configurar cerraduras de la tal forma que
la cantidad y el tamaño de las estructuras que la componen sea variable.*/

#include <iostream>
#include "prototipos.h"
using namespace std;


void imprimirMatriz(int** matriz, int n, int tamanoMaximo) {
    // Calcula las coordenadas de inicio y fin para imprimir la matriz original en la cerradura.
    int inicioFila = (tamanoMaximo - n) / 2;
    int inicioColumna = (tamanoMaximo - n) / 2;
    int finFila = inicioFila + n;
    int finColumna = inicioColumna + n;

    for (int i = 0; i < tamanoMaximo; ++i) {
        for (int j = 0; j < tamanoMaximo; ++j) {
            if (i >= inicioFila && i < finFila && j >= inicioColumna && j < finColumna) {
                // Imprime la parte central de la matriz original.
                cout << matriz[i - inicioFila][j - inicioColumna] << "\t";
            } else {
                // Imprime cero para los elementos fuera de la matriz original.
                cout << "0\t";
            }
        }
        cout << endl;
    }
}

//---------------------------------------------------------------------------------------
// Función para crear una matriz cuadrada
int** crearMatriz(int n) {
    int** matriz = new int*[n];
    for (int i = 0; i < n; ++i) {
        matriz[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = 0;
        }
    }

    int valor = 1;
    int fila = 0;
    int columna = 0;

    while (valor < n * n) {
        if (fila != n / 2 || columna != n / 2) {
            matriz[fila][columna] = valor++;
        }
        if (++columna >= n) {
            columna = 0;
            ++fila;
        }
    }

    return matriz;
}
