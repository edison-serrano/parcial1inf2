#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

int** crearMatriz(int n);
void imprimirMatriz(int** matriz, int n, int tamanoMaximo);
int** rotarMatriz90(int** matriz, int n);
int** rotarMatriz180(int** matriz, int n);
int** rotarMatriz270(int** matriz, int n);
int*** crearArregloDeMatrices(int* tamanos, int numMatrices);
//<<<<<<< rama-jorge
void imprimirCerradura(int*** cerradura, int* tamanos, int numCerraduras, int tamanoMaximo);

=======
int** rotarMatriz90(int** matriz, int n);
int** rotarMatriz180(int** matriz, int n);
int** rotarMatriz270(int** matriz, int n);
//>>>>>>> master

#endif // PROTOTIPOS_H
