#include <iostream>
#include "prototipos.h"
using namespace std;




int main() {
    int numCerraduras;

    // Solicitar al usuario que ingrese el numero de matrices en la cerradura
    cout << "Ingrese el numero de matrices en la cerradura (Ejemplo: 4): ";

    // Validar la entrada para asegurar que sea un numero entero positivo sin decimales
    while (!(cin >> numCerraduras) || numCerraduras <= 0 || cin.peek() != '\n') {
        cout << "Entrada invalida. Por favor, ingrese un numero entero positivo sin decimales: ";

        // Limpiar el flujo de entrada para descartar caracteres incorrectos
        cin.clear();
        while (cin.get() != '\n') {}
    }
    //----------------------------------------------------------------------------------------------------
    int* tamanos = new int[numCerraduras];

    cout << "Ingrese los tamanos de las matrices separados por comas (Ejemplo: 5,7,5,9,)\ncolocar una (,) al final: ";
    cin.ignore(); // Ignorar el salto de línea después de leer numCerraduras

    for (int i = 0; i < numCerraduras; ++i) {
        bool formatoCorrecto = false;

        do {
            int tamano;
            char nextChar;
            cin >> tamano;

            if (!cin || tamano % 2 == 0) {
                cout << "Formato incorrecto o valor invalido (se permiten solo numeros impares).\nIngrese nuevamente en el formato correcto: ";
                cin.clear(); // Limpiar el estado de error
                while (cin.get() != '\n') {
                    continue; // Descartar la entrada incorrecta hasta encontrar un salto de línea
                }
            } else {
                tamanos[i] = tamano;

                // Leer el siguiente carácter para verificar si es una coma o un salto de línea
                cin >> nextChar;

                if (nextChar == ',') {
                    formatoCorrecto = true;
                } else if (nextChar == '\n' || cin.eof()) {
                    formatoCorrecto = true;
                } else {
                    cout << "Formato incorrecto. Se esperaba una coma (,) o el final de la linea. Ingrese nuevamente: ";
                }
            }
        } while (!formatoCorrecto);
    }

    // Imprimir los tamaños de las matrices ingresados si se ingresaron correctamente
    cout << "Tamanos de matrices ingresados (impares): ";
    for (int i = 0; i < numCerraduras; ++i) {
        cout << tamanos[i];
        if (i != numCerraduras - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    //--------------------------------------------------------------------------------------------------------------------------
    // Verificar si se ingresaron la cantidad correcta de tamaños de matrices
    int numTamanosIngresados = numCerraduras;
    if (cin.peek() != '\n') {
        // Si hay caracteres adicionales después de los tamaños, significa que se ingresaron más valores de los necesarios
        cout << "Se ingresaron mas tamaños de matrices de los especificados.\nSaliendo del Programa..." << endl;
        //numTamañosIngresados = 0; // Reiniciar el contador de tamaños ingresados
        delete[] tamanos;
        return 0;
    }
    //------------------------------------------------------------------------------------------------------------
    // Imprimir los tamaños de las matrices ingresados si se ingresaron correctamente
    if (numTamanosIngresados == numCerraduras) {
        cout << "Tamanos de matrices ingresados: ";
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
    int filaCasilla, columnaCasilla;
    char comma;

    bool formatoValido = false;

    while (!formatoValido) {
        cout << "Ingrese las coordenadas para la primera matriz (fila,columna): ";

        // Leer la fila
        if (!(cin >> filaCasilla) || filaCasilla <= 0) {
            cout << "Error: La fila debe ser un numero entero positivo. Intente nuevamente." << endl;
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(10000, '\n'); // Descartar la entrada incorrecta
            continue; // Volver a solicitar las coordenadas
        }

        // Leer el siguiente carácter
        cin.get(comma);

        // Verificar si el carácter leído es una coma
        if (comma != ',') {
            cout << "Error: Se esperaba una coma ',' despues de la fila. Intente nuevamente." << endl;
            cin.ignore(10000, '\n'); // Descartar la entrada incorrecta
            continue; // Volver a solicitar las coordenadas
        }

        // Leer la columna
        if (!(cin >> columnaCasilla) || columnaCasilla <= 0) {
            cout << "Error: La columna debe ser un numero entero positivo. Intente nuevamente." << endl;
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

    cout << "Ingrese las comparaciones en el formato (1: Mayor, -1: Menor)\n(Ejjemplo 1,-1,1,) colocar una (,) al final: ";
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
            cout << "La comparacion no coincide con la matriz girada." << endl;
            break; // Salir del bucle al primer fallo
        }

        comparaciones.erase(0, pos + 1);
    }
    //----------------------------------------------------------------------------------------------------------
    // Mostrar el estado de la cerradura
    if (cerraduraAbierta) {
        cout << "La cerradura esta abierta." << endl;
    } else {
        cout << "La cerradura permanece cerrada." << endl;
    }
    //--------------------------------------------------------------------------------------
    /*

    // Mostrar el número de rotaciones sin éxito
    cout << "Número de rotaciones sin éxito: " << rotacionesSinExito << endl;
    // Mostrar el número total de rotaciones realizadas
    cout << "Número total de rotaciones: " << totalRotaciones << endl;
*/



 //---------------------------------------------------------------
    // Liberar memoria
    for (int i = 0; i < numCerraduras; ++i) {
        liberarMatriz(cerradura[i], tamanos[i]);
    }
    delete[] cerradura;
    delete[] tamanos;

    return 0;
}
