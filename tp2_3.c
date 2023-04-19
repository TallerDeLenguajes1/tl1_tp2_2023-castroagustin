#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Filas 5
#define Columnas 7

int main() {
    int *pMatriz = (int *) malloc(sizeof(int) * Filas * Columnas);

    srand(time(NULL));

    for(int i = 0; i < Filas; i++) {
        for(int j = 0; j < Columnas; j++){
            *(pMatriz + i * Columnas + j) = 1 + rand() % 100;
            printf("%d", *(pMatriz + i * Columnas + j));
            printf("\n");
        }
        printf("\n");
    }

    
}
