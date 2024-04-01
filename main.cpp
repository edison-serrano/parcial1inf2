#include <iostream>
#include <prototipos.h>

using namespace std;


/*

int main() {
    int n;
    cout << "\nINFORMA2\n" << endl;
    cout << "SISTEMA DE CERRADURAS DIGITALES\n" << endl;
    cout << "Bienvenido\n" << endl;
    cout << "Ingrese un número impar para el tamaño de la matriz cuadrada: ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "El número ingresado no es impar." << endl;
        return 1;
    }

    int** matriz = crearMatriz(n); // Crea una matriz cuadrada

    cout << "Matriz generada:" << endl;
    imprimirMatriz(matriz, n);

    // Liberar memoria
    for (int i = 0; i < n; ++i) { // Itera sobre las filas de la matriz.
        delete[] matriz[i]; // Libera la memoria de cada fila.
    }
    delete[] matriz; // Libera la memoria de la matriz.

    return 0;
}
*/

/*
int main() {
    int tamanos[] = {5, 7, 5, 9}; // Ejemplo de tamaños de matrices proporcionados por el usuario.
    int numMatrices = sizeof(tamanos) / sizeof(tamanos[0]); // Calcula la cantidad de matrices.

    // Crea el arreglo de matrices según los tamaños proporcionados.
    int*** arregloDeMatrices = crearArregloDeMatrices(tamanos, numMatrices);

    // Imprime las matrices creadas
    for (int i = 0; i < numMatrices; ++i) {
        cout << "Matriz " << i+1 << ":\n";
        imprimirMatriz(arregloDeMatrices[i], tamanos[i]);
        cout << endl;
    }

    // Liberar la memoria
    for (int i = 0; i < numMatrices; ++i) {
        for (int j = 0; j < tamanos[i]; ++j) {
            delete[] arregloDeMatrices[i][j];
        }
        delete[] arregloDeMatrices[i];
    }
    delete[] arregloDeMatrices;

    return 0;
}
*/


int main() {
  int n;
  cout << "Ingrese un numero impar para el tamano de la matriz cuadrada: ";
  cin >> n;

  if (n % 2 == 0) {
    cout << "El numero ingresado no es impar." << endl;
    return 1;
  }

  int** matriz = crearMatriz(n); // Crea una matriz cuadrada

  cout << "Matriz generada:" << endl;
  imprimirMatriz(matriz, n);

  // Rotación
  int** matriz_rotada_90 = rotarMatriz90(matriz, n);
  int** matriz_rotada_180 = rotarMatriz180(matriz, n);
  int** matriz_rotada_270 = rotarMatriz270(matriz, n);
      // Liberar memoria
      for (int i = 0; i < n; ++i) { // Itera sobre las filas de la matriz original.
        delete[] matriz[i]; // Libera la memoria de cada fila.
        delete[] matriz_rotada_90[i]; // Libera la memoria de cada fila de la matriz rotada.
        delete[] matriz_rotada_180[i];
        delete[] matriz_rotada_270[i];
      }
      delete[] matriz; // Libera la memoria de la matriz original.
      delete[] matriz_rotada_90; // Libera la memoria de la matriz rotada.
      delete[] matriz_rotada_180; // Libera la memoria de la matriz rotada.
      delete[] matriz_rotada_270;
      return 0;
}

