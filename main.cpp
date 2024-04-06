#include <iostream>
#include <prototipos.h>
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

// Función para rotar una matriz 90° en sentido antihorario
int** rotarMatriz90(int** matriz, int n) {
    int** nuevaMatriz = new int*[n];
    for (int i = 0; i < n; ++i) {
        nuevaMatriz[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            nuevaMatriz[i][j] = matriz[j][n - i - 1]; // Rotación antihoraria
        }
    }
    cout << "Matriz rotada 90°:" << endl;
    imprimirMatriz(nuevaMatriz, n, n); // Aquí se pasa el tercer argumento tamanoMaximo
    return nuevaMatriz;
}

// Función para rotar una matriz 180°
int** rotarMatriz180(int** matriz, int n) {
    int** nuevaMatriz = new int*[n];
    for (int i = 0; i < n; ++i) {
        nuevaMatriz[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            nuevaMatriz[i][j] = matriz[n - i - 1][n - j - 1]; // Rotación de 180°
        }
    }
    cout << "Matriz rotada 180°:" << endl;
    imprimirMatriz(nuevaMatriz, n, n); // Aquí se pasa el tercer argumento tamanoMaximo
    return nuevaMatriz;
}

// Función para rotar una matriz 270°
int** rotarMatriz270(int** matriz, int n) {
    int** nuevaMatriz = new int*[n];
    for (int i = 0; i < n; ++i) {
        nuevaMatriz[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            nuevaMatriz[i][j] = matriz[n - j - 1][i]; // Rotación de 270° corregida
        }
    }
    cout << "Matriz rotada 270°:" << endl;
    imprimirMatriz(nuevaMatriz, n, n); // Aquí se pasa el tercer argumento tamanoMaximo
    return nuevaMatriz;
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

        cout << "Cerradura " << i+1 << " con tamanos iguales:" << endl;
        imprimirMatriz(cerradura[i], tamanos[i], tamanoMaximo); // Imprime la matriz con tamaños iguales
        cout << endl;
    }
}



int main() {
    int numCerraduras;
    cout << "Ingrese el número de matrices en la cerradura (Ejemplo: 4): ";
    cin >> numCerraduras;  // Número de matrices en la cerradura
    cin.ignore(); // Limpiar el buffer

    int* tamanos = new int[numCerraduras];
    cout << "Ingrese los tamaños de las matrices separados por comas (Ejemplo: 5,7,5,9): ";
    for (int i = 0; i < numCerraduras; ++i) {
        cin >> tamanos[i];
        if (i < numCerraduras - 1) {
            char comma;
            cin >> comma; // Leer la coma
        }
    }

  int*** cerradura = crearArregloDeMatrices(tamanos, numCerraduras); // Crea la cerradura

  // Encuentra el tamaño máximo de las matrices en el arreglo
  int tamanoMaximo = 0;
  for (int i = 0; i < numCerraduras; ++i) {
      if (tamanos[i] > tamanoMaximo) {
          tamanoMaximo = tamanos[i];
      }
  }

  cout << "Cerradura generada:" << endl;
  imprimirCerradura(cerradura, tamanos, numCerraduras, tamanoMaximo); // Imprime la cerradura original
  cout << endl;
}
