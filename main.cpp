#include <iostream>

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

//<<<<<<< rama-edison
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

    // Imprimir los tamaños de las matrices ingresados si se ingresaron correctamente
    if (numTamañosIngresados == numCerraduras) {
        cout << "Tamaños de matrices ingresados: ";
        for (int i = 0; i < numCerraduras; ++i) {
            cout << tamanos[i];
            if (i != numCerraduras - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    //-------------------------------------------------------------------------------------------------

    int*** cerradura = crearArregloDeMatrices(tamanos, numCerraduras); // Crea la cerradura
    //-------------------------------------------------------------------------------------------
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
    //---------------------------------------------------------------------------------------------------------
    // Almacena las cerraduras con tamaños iguales
    int** cerradurasConTamanosIguales[numCerraduras]; // Arreglo para almacenar las cerraduras con tamaños iguales
    int numCerradurasConTamanosIguales = 0; // Contador para el número de cerraduras con tamaños iguales

    for (int i = 0; i < numCerraduras; ++i) {
        if (tamanos[i] == tamanoMaximo) {
            cerradurasConTamanosIguales[numCerradurasConTamanosIguales++] = cerradura[i];
            cout << endl;
        }
    }

    //------------------------------------------------------------------------------------------
    //para tomar las coordenadas

    int filaCasilla, columnaCasilla;
    char comma;

    bool formatoValido = false;

    while (!formatoValido) {
        cout << "Ingrese las coordenadas para la primera matriz (fila,columna): ";

        // Leer la fila
        if (!(cin >> filaCasilla) || filaCasilla <= 0) {
            cout << "Error: La fila debe ser un número entero positivo. Intente nuevamente." << endl;
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(10000, '\n'); // Descartar la entrada incorrecta
            continue; // Volver a solicitar las coordenadas
        }

        // Leer el siguiente carácter
        cin.get(comma);

        // Verificar si el carácter leído es una coma
        if (comma != ',') {
            cout << "Error: Se esperaba una coma ',' después de la fila. Intente nuevamente." << endl;
            cin.ignore(10000, '\n'); // Descartar la entrada incorrecta
            continue; // Volver a solicitar las coordenadas
        }

        // Leer la columna
        if (!(cin >> columnaCasilla) || columnaCasilla <= 0) {
            cout << "Error: La columna debe ser un número entero positivo. Intente nuevamente." << endl;
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(10000, '\n'); // Descartar la entrada incorrecta
            continue; // Volver a solicitar las coordenadas
        }

        // Verificar si no quedan caracteres adicionales en la entrada
        if (cin.peek() != '\n') {
            cout << "Error: Formato de entrada incorrecto. Intente nuevamente." << endl;
            cin.ignore(10000, '\n'); // Descartar la entrada incorrecta
            continue; // Volver a solicitar las coordenadas
        }

        // Si todas las verificaciones pasan, el formato es válido
        formatoValido = true;
    }

    cout << "Coordenadas ingresadas correctamente: (" << filaCasilla << "," << columnaCasilla << ")" << endl;

    //cout << "Contenido de la celda en la posición (" << filaCasilla << ", " << columnaCasilla << ") de la matriz 1:" << endl;
    cout << obtenerContenidoCelda(cerradurasConTamanosIguales[0], filaCasilla, columnaCasilla) << endl;
    //-----------------------------------------------------------------------------------------------------------
    // Comparar matrices consecutivas en orden inverso
    int rotacionesSinExito = 0; // Contador de rotaciones sin éxito
    int totalRotaciones = 0; // Contador de rotaciones totales
    bool cerraduraAbierta = true; // Suponemos que la cerradura está abierta

    cout << "Ingrese las comparaciones en el formato (1: Mayor, -1: Menor)(Ejjemplo 1,-1,1) separadas por comas: ";
    string comparaciones;
    cin.ignore(); // Limpiar el buffer
    getline(cin, comparaciones);

    size_t pos = 0;
    string token;
    while ((pos = comparaciones.find(",")) != string::npos) {
        token = comparaciones.substr(0, pos);
        int comparacion = stoi(token);

        if (compararMatrices(cerradura[totalRotaciones + 1], cerradura[totalRotaciones], filaCasilla, columnaCasilla, tamanos[totalRotaciones + 1], rotacionesSinExito, totalRotaciones) != comparacion) {
            // Si la comparación no es exitosa, mostrar mensaje y cambiar estado de la cerradura
            cerraduraAbierta = false;
            cout << "La comparación no coincide con la matriz girada." << endl;
            break; // Salir del bucle al primer fallo
        }

        comparaciones.erase(0, pos + 1);
    }

    //----------------------------------------------------------------------------------------------------------
    // Mostrar el estado de la cerradura
    if (cerraduraAbierta) {
        cout << "La cerradura está abierta." << endl;
    } else {
        cout << "La cerradura permanece cerrada." << endl;
    }
    //--------------------------------------------------------------------------------------
    // Mostrar el número de rotaciones sin éxito
    cout << "Número de rotaciones sin éxito: " << rotacionesSinExito << endl;
    // Mostrar el número total de rotaciones realizadas
    cout << "Número total de rotaciones: " << totalRotaciones << endl;

    // Liberar memoria
    for (int i = 0; i < numCerraduras; ++i) {
        liberarMatriz(cerradura[i], tamanos[i]);
    }
    delete[] cerradura;
    delete[] tamanos;
//=======

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

//<<<<<<< rama-jorge
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
//>>>>>>> master


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
//<<<<<<< rama-edison



//=======

//=======
//>>>>>>> master


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
//<<<<<<< rama-jorge
  }

  cout << "Cerradura generada:" << endl;
  imprimirCerradura(cerradura, tamanos, numCerraduras, tamanoMaximo); // Imprime la cerradura original
  cout << endl;
}
//=======
      delete[] matriz; // Libera la memoria de la matriz original.
      delete[] matriz_rotada_90; // Libera la memoria de la matriz rotada.
      delete[] matriz_rotada_180; // Libera la memoria de la matriz rotada.
      delete[] matriz_rotada_270;
      return 0;
}
//>>>>>>> master

//>>>>>>> master
