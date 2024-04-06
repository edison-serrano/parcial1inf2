#include <iostream>
#include <prototipos.h>

using namespace std;


/*
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

*/

int main() {
    int numCerraduras;

    // Solicitar al usuario que ingrese el número de matrices en la cerradura
    cout << "Ingrese el número de matrices en la cerradura (Ejemplo: 4): ";

    // Validar la entrada para asegurar que sea un número entero positivo sin decimales
    while (!(cin >> numCerraduras) || numCerraduras <= 0 || cin.peek() != '\n') {
        cout << "Entrada inválida. Por favor, ingrese un número entero positivo sin decimales: ";

        // Limpiar el flujo de entrada para descartar caracteres incorrectos
        cin.clear();
        while (cin.get() != '\n') {}
    }
//------------------------------------------------------------------------------------------

    // Crear un arreglo dinámico para almacenar los tamaños de las matrices
    int* tamanos = new int[numCerraduras];

    // Solicitar al usuario que ingrese los tamaños de las matrices separados por comas
    cout << "Ingrese los tamaños de las matrices separados por comas (Ejemplo: 5,7,5,9): ";

    cin.ignore(); // Ignorar el salto de línea después de leer numCerraduras

    // Leer y validar los tamaños de las matrices ingresados por el usuario
    for (int i = 0; i < numCerraduras; ++i) {
        bool formatoCorrecto = false;

        do {
            int tamaño;
            char nextChar;
            cin >> tamaño;

            // Verificar si se pudo leer correctamente un entero
            if (!cin) {
                // Mostrar mensaje de error si el formato de entrada es incorrecto o el valor es inválido
                cout << "Formato incorrecto o valor inválido. Ingrese nuevamente en el formato correcto: ";
                cin.clear(); // Limpiar el estado de error

                // Descartar la entrada incorrecta hasta encontrar un salto de línea
                while (cin.get() != '\n') {
                    continue;
                }
            } else {
                tamanos[i] = tamaño;
                // Leer el siguiente carácter para verificar si es una coma o un salto de línea
                cin >> nextChar;

                // Verificar el siguiente carácter para determinar si el formato es correcto
                if (nextChar == ',') {
                    formatoCorrecto = true; // El formato es correcto si se encontró una coma
                } else if (nextChar == '\n' || cin.eof()) {
                    formatoCorrecto = true; // El formato es correcto si se llegó al final de la línea
                } else {
                    // Mostrar mensaje de error si el siguiente carácter no es una coma o el final de la línea
                    cout << "Formato incorrecto. Se esperaba una coma (,) o el final de la línea. Ingrese nuevamente: ";
                }
            }
        } while (!formatoCorrecto); // Continuar leyendo hasta que el formato sea correcto
    }

    // Mostrar los tamaños ingresados
    cout << "Tamaños ingresados:";
    for (int i = 0; i < numCerraduras; ++i) {
        cout << " " << tamanos[i]; // Imprimir cada tamaño almacenado en el arreglo
    }
    cout << endl;

//----------------------------------------------------------------------------------------------------

    // Verificar si se ingresaron la cantidad correcta de tamaños de matrices
    int numTamañosIngresados = numCerraduras;
    if (cin.peek() != '\n') {
        // Si hay caracteres adicionales después de los tamaños, significa que se ingresaron más valores de los necesarios
        cout << "Se ingresaron más tamaños de matrices de los especificados. Por favor, intente nuevamente." << endl;
        numTamañosIngresados = 0; // Reiniciar el contador de tamaños ingresados
    }
//-----------------------------------------------------------------------------------------------

}
