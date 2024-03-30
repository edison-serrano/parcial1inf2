/*módulo que permite crear estructuras de datos de tamaño variable,
consistentes con las características descritas en la Consideraciones Iniciales.*/

#include <iostream>
#include <prototipos.h>

using namespace std;


// Función para crear un arreglo de matrices cuadradas de acuerdo a los tamaños proporcionados
int*** crearArregloDeMatrices(int* tamanos, int numMatrices) {
    int*** arregloDeMatrices = new int**[numMatrices]; // Aloja memoria para el arreglo de matrices.

    for (int i = 0; i < numMatrices; ++i) { // Itera sobre los tamaños proporcionados.
        arregloDeMatrices[i] = crearMatriz(tamanos[i]); // Crea la matriz de tamaño correspondiente.
    }

    return arregloDeMatrices;
}
