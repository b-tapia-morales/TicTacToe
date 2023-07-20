#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
#pragma ide diagnostic ignored "cert-msc51-cpp"

#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "tic_tac_toe_modules.h"

void assignMarkers(bool isUsrTurn, char *usr, char *cpu) {
    if (isUsrTurn) {
        *usr = 'O';
        *cpu = 'X';
    } else {
        *usr = 'X';
        *cpu = 'O';
    }
}

void assignMarkersRandomly(char *usr, char *cpu) {
    int usrGetsCircle = (bool) (rand() % 2);
    assignMarkers(usrGetsCircle, usr, cpu);
}

void welcomeMessage() {
    fflush(stdout);
    printf("Bienvenido al juego del gato. Se asignaran los marcadores 'O' y 'X' entre usted y el ordenador.\n");
    printf("Aquel jugador al que se le asigne el marcador 'O' partira primero.\n");
}

void initializeItems(bool isFirstGame, bool isUsrTurn, char board[N][N], char *usrMarker, char *cpuMarker) {
    initialize(board);
    welcomeMessage();
    if (isFirstGame) {
        assignMarkersRandomly(usrMarker, cpuMarker);
        printf("Se ha asignado al azar el marcador 'O' al %s.\n", isUsrTurn ? "usuario" : "ordenador");
    } else {
        assignMarkers(isUsrTurn, usrMarker, cpuMarker);
        printf("Se ha asignado el marcador 'O' al %s, ya que gano la ultima partida\n",
               isUsrTurn ? "usuario" : "ordenador");
    }
    pause();
    show(board);
}

bool gameLoop(bool isFirstGame, bool isUsrTurn, char board[N][N], char *usrMarker, char *cpuMarker) {
    initializeItems(isFirstGame, isUsrTurn, board, usrMarker, cpuMarker);
    int counter = 1;
    while (counter <= N * N) {
        if (isUsrTurn) {
            usrTurn(board, *usrMarker);
            if (counter >= 5 && playerHasWon(board, *usrMarker)) {
                printf("FELICIDADES. Has vencido al ordenador en %d movimientos.\n", counter);
                return true;
            }
            isUsrTurn = false;
        } else {
            cpuTurn(board, *cpuMarker);
            if (counter >= 5 && playerHasWon(board, *cpuMarker)) {
                printf("Has sido vencido por el ordenador en %d movimientos.\n", counter);
                return false;
            }
            isUsrTurn = true;
        }
        counter++;
    }
    printf("Ha concluido el juego en empate.\n");
    return isUsrTurn;
}

int main() {
    srand(time(NULL));
    char board[N][N] = {' '};
    char usrMarker = '\0', cpuMarker = '\0';
    bool isFirstGame = true;
    bool isUsrTurn = (bool) (rand() % 2);
    while (true) {
        isUsrTurn = gameLoop(isFirstGame, isUsrTurn, board, &usrMarker, &cpuMarker);
        char confirmation = readConfirmation("Desea seguir jugando?");
        if (confirmation == 'n') {
            break;
        }
        isFirstGame = false;
    }
    printf("Ha concluido el juego en empate.\n");
    return 0;
}

#pragma clang diagnostic pop