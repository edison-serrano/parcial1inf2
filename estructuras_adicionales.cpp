/*módulo que permite crear estructuras de datos de tamaño variable,
consistentes con las características descritas en la Consideraciones Iniciales.*/
#include <iostream>
#include "prototipos.h"
using namespace std;

//-------------------------------------------------------------------------------------------------------------------
// Función para obtener el contenido de una celda de una matriz
int obtenerContenidoCelda(int** matriz, int fila, int columna) {
    return matriz[fila][columna];
}

//---------------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------------------------------
// Función para imprimir la cerradura
void imprimirCerradura(int*** cerradura, int* tamanos, int numCerraduras, int tamanoMaximo) {
    for (int i = 0; i < numCerraduras; ++i) {
        cout << "Cerradura " << i+1 << " Original:" << endl;
        imprimirMatriz(cerradura[i], tamanos[i], tamanos[i]); // Imprime la matriz original
        cout << endl;

        cout << "Cerradura " << i+1 << " con tamanos iguales:" << endl;
        imprimirMatriz(cerradura[i], tamanos[i], tamanoMaximo); // Imprime la matriz con tamaños iguales
        cout << endl;
    }
}

//--------------------------------------------------------------------------------------
// Función para verificar si un carácter es un dígito
bool esDigito(char c) {
    return c >= '0' && c <= '9';
}
//---------------------------------------------------------------------------------------
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
