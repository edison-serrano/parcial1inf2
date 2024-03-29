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

// Función para imprimir la matriz
void imprimirMatriz(int** matriz, int n) {
  for (int i = 0; i < n; ++i) { // Itera sobre las filas de la matriz.
    for (int j = 0; j < n; ++j) { // Itera sobre las columnas de la matriz.
      cout << matriz[i][j] << "\t"; // Imprime el elemento en la posición (i, j) de la matriz.
    }
    cout << endl; // Paso a la siguiente línea
  }
}

// Función para crear una matriz cuadrada con el cero en el centro
int** crearMatriz(int n) {
  int** matriz = new int*[n]; // Aloja memoria para las filas de la matriz.

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
    // Si no estamos en la posición central, asignamos el valor actual.
    if (fila != n / 2 || columna != n / 2) {
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

// Función para rotar una matriz 90° en sentido antihorario
int** rotarMatriz90(int** matriz, int n) {
  int** nuevaMatriz = new int*[n];
  for (int i = 0; i < n; ++i) {
    nuevaMatriz[i] = new int[n];
    for (int j = 0; j < n; ++j) {
      nuevaMatriz[i][j] = matriz[j][n - i - 1]; // Rotación antihoraria
    }
  }
  cout << "Matriz rotada 90 (estado1):" << endl;
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
  cout << "Matriz rotada 180 (estado2):" << endl;
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
  cout << "Matriz rotada 270 (estado3):" << endl;
  imprimirMatriz(nuevaMatriz, n);
  return nuevaMatriz;
}


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
