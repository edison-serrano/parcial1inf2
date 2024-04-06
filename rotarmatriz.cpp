
#include <iostream>
#include <prototipos.h>

using namespace std;

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

/*
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
  imprimirMatriz(nuevaMatriz, n);
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
  imprimirMatriz(nuevaMatriz, n);
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
  imprimirMatriz(nuevaMatriz, n);
  return nuevaMatriz;
}

//>>>>>>> master
*/
