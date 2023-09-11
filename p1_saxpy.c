#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

void get_wall_time(double *wcTime) {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    *wcTime = (double)(tp.tv_sec + tp.tv_usec / 1000000.0);
}

int main(int argc, char *argv[]) {
    int i, j, k, n = 5000;
    int **matrizA, **matrizB, **matrizC;
    double S1, E1;

    // Inicializar matrices
    matrizA = (int **)malloc(n * sizeof(int *));
    matrizB = (int **)malloc(n * sizeof(int *));
    matrizC = (int **)malloc(n * sizeof(int *));
    
    for (i = 0; i < n; i++) {
        matrizA[i] = (int *)malloc(n * sizeof(int));
        matrizB[i] = (int *)malloc(n * sizeof(int));
        matrizC[i] = (int *)malloc(n * sizeof(int));
    }

    // Llenar matrices con valores aleatorios
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            matrizA[i][j] = rand() % 6;
            matrizB[i][j] = rand() % 6;
            matrizC[i][j] = 0; // Inicializar matrizC con ceros
        }
    }

    get_wall_time(&S1);

    // Multiplicación de matrices (algoritmo ijk)
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            for (k = 0; k < n; ++k) {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    get_wall_time(&E1);

    printf("Tiempo método ijk: %f s\n", (E1 - S1));

    // Liberar memoria asignada dinámicamente
    for (i = 0; i < n; i++) {
        free(matrizA[i]);
        free(matrizB[i]);
        free(matrizC[i]);
    }
    free(matrizA);
    free(matrizB);
    free(matrizC);

    return 0;
}