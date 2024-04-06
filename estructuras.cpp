/*módulo que permite crear estructuras de datos de tamaño variable,
consistentes con las características descritas en la Consideraciones Iniciales.*/
#include <iostream>
using namespace std;

//-------------------------------------------------------------------------------------------

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

//-------------------------------------------------------------------------------------------------------------------
// Función para obtener el contenido de una celda de una matriz
int obtenerContenidoCelda(int** matriz, int fila, int columna) {
    return matriz[fila][columna];
}

//---------------------------------------------------------------------------------------------------------
// Función para comparar las celdas indicadas en dos matrices
int compararMatrices(int** matriz1, int** matriz2, int fila, int columna, int n, int& rotacionesSinExito, int& totalRotaciones) {
    // Intentar la comparación en cada rotación (0°, 90°, 180°, 270°)
    for (int rotacion = 0; rotacion < 4; ++rotacion) {
        totalRotaciones++;
        if (rotacion != 0) {
            // Girar la matriz en sentido antihorario
            int** matrizTemporal = new int*[n];
            for (int i = 0; i < n; ++i) {
                matrizTemporal[i] = new int[n];
                for (int j = 0; j < n; ++j) {
                    matrizTemporal[i][j] = matriz1[j][n - 1 - i];
                }
            }

            // Liberar memoria de la matriz anterior (matriz1)
            for (int i = 0; i < n; ++i) {
                delete[] matriz1[i];
            }
            delete[] matriz1;

            // Asignar matrizTemporal a matriz1
            matriz1 = matrizTemporal;
        }

        // Realizar la comparación en la matriz rotada
        if (matriz1[fila][columna] > matriz2[fila][columna])
            return 1;
        else if (matriz1[fila][columna] < matriz2[fila][columna])
            return -1;
    }

    // Si ninguna comparación es exitosa, aumentar el contador de rotaciones sin éxito
    rotacionesSinExito++;

    // Liberar memoria de la matriz rotada (matriz1)
    for (int i = 0; i < n; ++i) {
        delete[] matriz1[i];
    }
    delete[] matriz1;

    return 0;
}

// Función para liberar la memoria de una matriz
void liberarMatriz(int** matriz, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

// Función para crear un arreglo de matrices cuadradas de acuerdo a los tamaños proporcionados
int*** crearArregloDeMatrices(int* tamanos, int numMatrices) {
    int*** arregloDeMatrices = new int**[numMatrices]; // Aloja memoria para el arreglo de matrices.

    for (int i = 0; i < numMatrices; ++i) { // Itera sobre los tamaños proporcionados.
        arregloDeMatrices[i] = crearMatriz(tamanos[i]); // Crea la matriz de tamaño correspondiente.
    }

    return arregloDeMatrices;
}

void igualarTamanos(int*** cerradura, int* tamanos, int numCerraduras, int tamanoMaximo) {
    for (int i = 0; i < numCerraduras; ++i) {
        if (tamanos[i] < tamanoMaximo) { // Si el tamaño de la matriz es menor que el tamaño máximo
            int diferencia = tamanoMaximo - tamanos[i]; // Calcula la diferencia en tamaño
            int** matrizActual = cerradura[i]; // Obtiene la matriz actual

            // Crea una nueva matriz del tamaño máximo e inicializa con ceros
            int** nuevaMatriz = new int*[tamanoMaximo];
            for (int j = 0; j < tamanoMaximo; ++j) {
                nuevaMatriz[j] = new int[tamanoMaximo]();
            }

            // Copia la matriz original a la nueva matriz en la posición correcta
            for (int j = 0; j < tamanos[i]; ++j) {
                for (int k = 0; k < tamanos[i]; ++k) {
                    nuevaMatriz[j + diferencia][k + diferencia] = matrizActual[j][k];
                }
            }

            // Libera la memoria de la matriz actual
            for (int j = 0; j < tamanos[i]; ++j) {
                delete[] matrizActual[j];
            }
            delete[] matrizActual;

            // Actualiza la matriz en el arreglo cerradura
            cerradura[i] = nuevaMatriz;
        }
    }
}

/// Función para imprimir la cerradura
void imprimirCerradura(int*** cerradura, int* tamanos, int numCerraduras, int tamanoMaximo) {
    for (int i = 0; i < numCerraduras; ++i) {
        cout << "Cerradura " << i+1 << " Original:" << endl;
        imprimirMatriz(cerradura[i], tamanos[i], tamanos[i]); // Imprime la matriz original
        cout << endl;

        cout << "Cerradura " << i+1 << " con tamaños iguales:" << endl;
        imprimirMatriz(cerradura[i], tamanos[i], tamanoMaximo); // Imprime la matriz con tamaños iguales
        cout << endl;
    }
}


// Función para verificar si un carácter es un dígito
bool esDigito(char c) {
    return c >= '0' && c <= '9';
}

// Función para verificar si una cadena representa un número entero positivo
bool esNumeroEnteroPositivo(const char* str) {
    if (*str == '\0') {
        return false; // La cadena está vacía
    }
    while (*str) {
        if (!esDigito(*str)) {
            return false; // Caracter no es un dígito
        }
        str++;
    }
    return true;
}
