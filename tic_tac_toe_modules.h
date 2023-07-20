#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
#pragma ide diagnostic ignored "cert-err34-c"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef TIC_TAC_TOE_MODULES_H
#define TIC_TAC_TOE_MODULES_H

#endif

#define N 3
#define EMPTY_CELL ' '

/**
 * Obtiene un número entero a partir del input ingresado por el usuario. El número debe estar dentro del rango
 * establecido por los parámetros <i>lowerBound</i> y <i>upperBound</i>.
 * @param message El mensaje que describe el input que se le solicita ingresar al usuario.
 * @param lowerBound La cota inferior del rango de valores aceptables.
 * @param upperBound La cota superior del rango de valores aceptables.
 * @return El número entero.
 */
int readInt(char *message, int lowerBound, int upperBound);

/**
 * Inicializa el tablero al asignar a cada posición del tablero el espacio blanco ' '.
 * @param board El tablero.
 */
void initialize(char board[][N]);

/**
 * Muestra por consola un separador entre cada fila del tablero.
 */
void drawLine();

/**
 * Muestra por consola el contenido del tablero.
 * @param board El tablero.
 */
void show(char board[][N]);

/**
 * Asigna al asar los marcadores 'O' y 'X' al jugador humano y al jugador ordenador. Aquel jugador al que se le asigne
 * el marcador 'O' será el primero en partir.
 * @param usr El marcador del jugador usuario.
 * @param cpu El marcador del jugador computador.
 */
void randomlyAssignMarkers(char *usr, char *cpu);

/**
 * Determina si la posición del tablero en las coordenadas (row, col) corresponde a un espacio en blanco.
 * @param board El tablero.
 * @param row La coordenada de la fila.
 * @param col La coordenada de la columna.
 * @return '<i>true</i>' si el espacio está vacío; de lo contrario, '<i>false</i>'.
 */
bool spaceIsUnmarked(char board[][N], int row, int col);

/**
 * Marca la posición del tablero en las coordenadas (row, col) con el marcador del jugador actual.
 * @param board El tablero.
 * @param row La coordenada de la fila.
 * @param col La coordenada de la columna.
 * @param marker El marcador del jugador actual.
 */
void markSpace(char board[][N], int row, int col, char marker);

/**
 * <p>Gestiona el turno del jugador humano. El jugador humano debe seleccionar las coordenadas correspondientes a las
 * posiciones de fila y columna, y estas deben corresponder a un espacio en blanco en el tablero.</p>
 *
 * <p>Una vez el jugador humano seleccione un espacio en blanco en el tablero, lo marcará con su marcador.</p>
 * @param board El tablero.
 * @param marker El marcador del jugador humano.
 */
void usrTurn(char board[][N], char marker);

/**
 * Gestiona el turno del jugador ordenador. El jugador ordenador selecciona un espacio en blanco en el tablero al
 * asar, y lo marca con su marcador.
 * @param board El tablero.
 * @param marker El marcador del jugador ordenador.
 */
void cpuTurn(char board[][N], char marker);

/**
 * Determina si el jugador actual ha marcado por completo todas las columnas correspondientes a la fila especificada.
 * @param board El tablero.
 * @param row La coordenada de la fila.
 * @param marker El marcador del jugador actual.
 * @return '<i>true</i>' si el jugador actual ha marcado por completo la fila especificada; de lo contrario, '<i>false</i>'.
 */
bool rowIsMarked(char board[][N], int row, char marker);

/**
 * Determina si el jugador actual ha marcado por completo todas las filas correspondientes a la columna especificada.
 * @param board El tablero.
 * @param col La coordenada de la columna.
 * @param marker El marcador del jugador actual.
 * @return '<i>true</i>' si el jugador actual ha marcado por completo la columna especificada; de lo contrario, '<i>false</i>'.
 */
bool colIsMarked(char board[][N], int col, char marker);

/**
 * Determina si el jugador actual ha marcado por completo la diagonal. La diagonal comprende desde la coordenada (0, 0)
 * hasta la coordenada (N - 1, N - 1).
 * @param board El tablero.
 * @param marker El marcador del jugador actual.
 * @return '<i>true</i>' si el jugador actual ha marcado por completo la diagonal; de lo contrario, '<i>false</i>'.
 */
bool diagIsMarked(char board[][N], char marker);

/**
 * Determina si el jugador actual ha marcado por completo la diagonal reversa. La diagonal reversa comprende desde la
 * coordenada (0, N - 1) hasta la coordenada (N - 1, 0).
 * @param board El tablero.
 * @param marker El marcador del jugador actual.
 * @return '<i>true</i>' si el jugador actual ha marcado por completo la diagonal reversa; de lo contrario, '<i>false</i>'.
 */
bool reverseDiagIsMarked(char board[][N], char marker);

/**
 * Determina si el jugador actual ha marcado a lo menos una de las filas por completo.
 * @param board El tablero.
 * @param marker El marcador del jugador actual.
 * @return '<i>true</i>' si el jugador actual ha ganado por columna; de lo contrario, '<i>false</i>'.
 */
bool anyRowIsMarked(char board[][N], char marker);

/**
 * Determina si el jugador actual ha marcado a lo menos una de las columnas por completo.
 * @param board El tablero.
 * @param marker El marcador del jugador actual.
 * @return '<i>true</i>' si el jugador actual ha ganado por columna; de lo contrario, '<i>false</i>'.
 */
bool anyColIsMarked(char board[][N], char marker);

/**
 * Determina si el jugador actual ha marcado a lo menos una de las diagonales por completo.</p>
 * @param board El tablero.
 * @param marker El marcador del jugador actual.
 * @return '<i>true</i>' si el jugador actual ha ganado por diagonal; de lo contrario, '<i>false</i>'.
 */
bool anyDiagIsMarked(char board[][N], char marker);

/**
 * Determina si el jugador actual ha ganado. Para ganar, basta con que el jugador actual haya marcado tan solo una
 * fila, columna o diagonal por completo en el tablero.
 * @param board El tablero.
 * @param marker El marcador del jugador actual.
 * @return '<i>true</i>' si el jugador actual ha ganado; de lo contrario, '<i>false</i>'.
 */
bool playerHasWon(char board[][N], char marker);

int readInt(char *message, int lowerBound, int upperBound) {
    while (true) {
        fflush(stdin);
        int value;
        printf("%s [%d, %d]: ", message, lowerBound, upperBound);
        scanf("%d", &value);
        if (value >= lowerBound && value <= upperBound) {
            return value;
        } else {
            printf("El entero ingresado no está en el rango especificado. Intente nuevamente.\n");
        }
    }
}

char readConfirmation(char *message) {
    while (true) {
        fflush(stdin);
        char value;
        printf("%s <'s': si, 'n': no>: ", message);
        scanf("%c", &value);
        if (tolower(value) == 's' || tolower(value) == 'n') {
            return value;
        } else {
            printf("El caracter ingresado no es un caracter de confirmacion valido. Intente nuevamente.\n");
        }
    }
}

void initialize(char board[][N]) {
    int i = 0;
    while (i < N) {
        int j = 0;
        while (j < N) {
            board[i][j] = EMPTY_CELL;
            j++;
        }
        i++;
    }
}

void pause() {
    fflush(stdin);
    fflush(stdout);
    printf("Presione enter para continuar...");
    getchar();
    printf("\n");
}

void drawLine() {
    int i;
    for (i = 0; i < N; i++) {
        printf("+---");
    }
    printf("+\n");
}

void show(char board[][N]) {
    fflush(stdout);
    printf("\n");
    drawLine();
    int i = 0;
    while (i < N) {
        int j = 0;
        while (j < N) {
            printf("|%2c ", board[i][j]);
            j++;
        }
        printf("|\n");
        drawLine();
        i++;
    }
    printf("\n");
}

bool spaceIsUnmarked(char board[][N], int row, int col) {
    if (board[row][col] == EMPTY_CELL) {
        return true;
    }
    return false;
}

void markSpace(char board[][N], int row, int col, char marker) {
    board[row][col] = marker;
}

void usrTurn(char board[][N], char marker) {
    while (true) {
        fflush(stdout);
        int row = readInt("Ingrese un valor para la fila", 0, N - 1);
        int col = readInt("Ingrese un valor para la columna", 0, N - 1);
        if (spaceIsUnmarked(board, row, col)) {
            markSpace(board, row, col, marker);
            printf("El usuario ha marcado un espacio en las coordenadas (%d, %d).\n", row, col);
            show(board);
            return;
        } else {
            printf("El espacio en las coordenadas (%d, %d) está ocupado. Intente nuevamente.\n", row, col);
        }
    }
}

void cpuTurn(char board[][N], char marker) {
    fflush(stdout);
    int row = rand() % N;
    int col = rand() % N;
    while (!spaceIsUnmarked(board, row, col)) {
        row = rand() % N;
        col = rand() % N;
    }
    markSpace(board, row, col, marker);
    printf("El ordenador ha marcado un espacio en las coordenadas (%d, %d).\n", row, col);
    show(board);
}

bool rowIsMarked(char board[][N], int row, char marker) {
    int col = 0;
    while (col < N) {
        if (board[row][col] != marker) {
            return false;
        }
        col++;
    }
    return true;
}

bool colIsMarked(char board[][N], int col, char marker) {
    int row = 0;
    while (row < N) {
        if (board[row][col] != marker) {
            return false;
        }
        row++;
    }
    return true;
}

bool diagIsMarked(char board[][N], char marker) {
    int row = 0, col = 0;
    while (row < N && col < N) {
        if (board[row][col] != marker) {
            return false;
        }
        row++;
        col++;
    }
    return true;
}

bool reverseDiagIsMarked(char board[][N], char marker) {
    int row = 0, col = N - 1;
    while (row < N && col >= 0) {
        if (board[row][col] != marker) {
            return false;
        }
        row++;
        col--;
    }
    return true;
}

bool anyRowIsMarked(char board[][N], char marker) {
    int row = 0;
    while (row < N) {
        if (rowIsMarked(board, row, marker)) {
            return true;
        }
        row++;
    }
    return false;
}

bool anyColIsMarked(char board[][N], char marker) {
    int col = 0;
    while (col < N) {
        if (colIsMarked(board, col, marker)) {
            return true;
        }
        col++;
    }
    return false;
}

bool anyDiagIsMarked(char board[][N], char marker) {
    return diagIsMarked(board, marker) || reverseDiagIsMarked(board, marker);
}

bool playerHasWon(char board[][N], char marker) {
    return anyRowIsMarked(board, marker) || anyColIsMarked(board, marker) || anyDiagIsMarked(board, marker);
}

#pragma clang diagnostic pop