#include "game.h"
#include "../keyboard/keyboard.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rows = 7,columns = 5;
int currentPointer = 0;
int gameTable[7][5];
int nextValue1 = 4;
int nextValue2 = 16;

FILE* gameSequence;

void gameStart(){
  gameStatus = 2;
  // memset(gameTable, 0, sizeof(gameTable));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
        printf("%d ", gameTable[i][j]);
    }
    printf("\n");
  }
  gameSequence = fopen("src/data/gameSequence.txt", "r");
  if (gameSequence == NULL) {
    printf("Erro ao abrir o arquivo gameSequence.txt\n");
    exit(1);
  }

  fscanf(gameSequence, "%d", &nextValue1);
  fscanf(gameSequence, "%d", &nextValue2);
}

void handleGame(){
  printf("\033[0m==================================================\033[0m\n");
  printf("                          Proximas: |  \033[32m%d  \033[0m|  \033[35m%d  \033[0m| \n", nextValue1, nextValue2);
  printf("\033[0m--------------------------------------------------\n\n");

  for(int i = 0; i<columns; i++){
    if(currentPointer == i){
      printf("     |    ");
    } else {
      printf("          ");
    }
  }
  printf("\n");
  for(int i = 0; i<columns; i++){
    if(currentPointer == i){
      printf("     *    ");
    } else {
      printf("          ");
    }
  }
  printf("\n\033[0m--------------------------------------------------\033[0m\n");
  for(int i = 0; i<rows; i++){
    for(int j = 0; j<columns; j++){
      printf("|    %d   |", gameTable[i][j]);
    }
    printf("\n\033[0m--------------------------------------------------\033[0m\n");
  }

  char key = readKey();

  if(key == 65 || key == 97){
    if(currentPointer == 0){ currentPointer = columns-1; } 
    else {currentPointer--;};
  } else   if(key == 68 || key == 100){
    if(currentPointer == columns-1){ currentPointer = 0; } 
    else {currentPointer++;}
  } if (key == 10){ // Selecionou a linha
    nextValue1 = nextValue2;
    fscanf(gameSequence, " %d", &nextValue2);
  }
}