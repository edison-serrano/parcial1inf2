#include <iostream>

using namespace std;

// Función para imprimir la matriz
void imprimirMatriz(int** matriz, int n) {
    for (int i = 0; i < n; ++i) { // Itera sobre las filas de la matriz.
        for (int j = 0; j < n; ++j) { // Itera sobre las columnas de la matriz.
            cout << matriz[i][j] << "\t"; // Imprime el elemento en la posición (i, j) de la matriz.
        }
        cout << endl; // paso a la otra linea
    }
}

// Función para crear una matriz cuadrada
int** crearMatriz(int n) {
    int** matriz = new int*[n]; // Aloja memoria para las filas de la matriz.

    // Determina la fila y columna central de la matriz.
    int filaCentral = n / 2;
    int columnaCentral = n / 2;

    // Aloja memoria para las columnas y llena la matriz con ceros.
    for (int i = 0; i < n; ++i) { // Itera sobre las filas.
        matriz[i] = new int[n]; // Aloja memoria para una fila.
        for (int j = 0; j < n; ++j) { // Itera sobre las columnas.
            matriz[i][j] = 0; // Asigna cero a cada elemento de la matriz.
        }
    }

    // Llena la matriz con números del 1 al n^2 - 1, organizados por filas.
    int valor = 1;
    int fila = 0;
    int columna = 0;

    while (valor < n * n) { // Llena la matriz hasta que se alcance el último número.
        // Si no estamos en la fila y columna central, asignamos el valor actual.
        if (fila != filaCentral || columna != columnaCentral) {
            matriz[fila][columna] = valor++; // Asigna el valor actual y aumenta el contador.
        }

        // Movemos a la siguiente posición en la fila actual.
        if (++columna >= n) { // Si hemos alcanzado el límite de la columna, pasamos a la siguiente fila.
            columna = 0; // Reinicia la columna al principio de la fila.
            ++fila; // Avanza a la siguiente fila.
        }
    }

    return matriz;
}

