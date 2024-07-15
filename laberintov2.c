#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 30

void generarLaberinto(int laberinto[N][N]) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            laberinto[i][j] = rand() % 2;
        }
    }
    // Asegurar entrada y salida
    laberinto[0][1] = 0; // Entrada
    laberinto[N-1][N-2] = 0; // Salida
}

void asegurarCamino(int laberinto[N][N]) {
    int x = 0, y = 1;
    while (x < N-1 || y < N-2) {
        if (x < N-1 && (rand() % 2 == 0 || y == N-2)) {
            x++;
        } else if (y < N-2) {
            y++;
        }
        laberinto[x][y] = 0;
    }
}

void imprimirLaberinto(int laberinto[N][N]) {
    // Imprimir techo
    printf("+");
    for (int i = 0; i < N; i++) {
        printf("-");
    }
    printf("+\n");

    for (int i = 0; i < N; i++) {
        printf("|"); // Pared izquierda
        for (int j = 0; j < N; j++) {
            if (laberinto[i][j] == 1) {
                printf("%c", 178);
            } else if (laberinto[i][j] == 2) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("|\n"); // Pared derecha
    }

    // Imprimir suelo
    printf("+");
    for (int i = 0; i < N; i++) {
        printf("-");
    }
    printf("+\n");
}

void esperarSimulado() 
{
    for (long i = 0; i < 500000000; i++); // Bucle vacío para simular espera más larga
} 


void imprimirPaso(int laberinto[N][N], int x, int y) {
    system("cls"); // Limpiar pantalla (para Windows)
    // system("clear"); // Limpiar pantalla (para Unix/Linux)
    laberinto[x][y] = 2; // Marca el camino actual
    imprimirLaberinto(laberinto);
    esperarSimulado(); // Pausa simulada para mostrar el proceso
}

int encontrarSalida(int laberinto[N][N], int x, int y, int* movimientos) {
    if (x < 0 || x >= N || y < 0 || y >= N || laberinto[x][y] != 0) {
        return 0; // No es una ruta válida
    }

    if (x == N-1 && y == N-2) {
        laberinto[x][y] = 2; // Encontró la salida
        (*movimientos)++;
        return 1; // Éxito
    }

    laberinto[x][y] = 2; // Marca el camino
    (*movimientos)++;
    imprimirPaso(laberinto, x, y);

    // Movimiento hacia abajo
    if (encontrarSalida(laberinto, x + 1, y, movimientos)) return 1;

    // Movimiento hacia la derecha
    if (encontrarSalida(laberinto, x, y + 1, movimientos)) return 1;

    // Movimiento hacia arriba
    if (encontrarSalida(laberinto, x - 1, y, movimientos)) return 1;

    // Movimiento hacia la izquierda
    if (encontrarSalida(laberinto, x, y - 1, movimientos)) return 1;

    laberinto[x][y] = 0; // Desmarca el camino si no hay salida
    (*movimientos)--;
    imprimirPaso(laberinto, x, y);
    return 0;
}

int main() {
    int laberinto[N][N];
    int movimientos = 0;

    generarLaberinto(laberinto);
    asegurarCamino(laberinto);
    imprimirLaberinto(laberinto);

    imprimirLaberinto(laberinto);

    if (encontrarSalida(laberinto, 0, 1, &movimientos)) {
        printf("El objeto encontró la salida en %d movimientos.\n", movimientos);
    } else {
        printf("El objeto no pudo encontrar la salida.\n");
    }

    return 0;
}
