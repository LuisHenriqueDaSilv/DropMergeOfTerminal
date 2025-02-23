#include "game.h"
#include "../keyboard/keyboard.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../utils/utils.h"

int currentPointer = 0;
int gameTable[10][5];
int nextValue1 = 4;
int nextValue2 = 16;
int iLastFall = 0;
int jLastFall = 0;
int merge_ = 0;
int eraserX = 0,eraserY=0;

FILE* gameSequence; 

void gameStart(){
  gameStatus = 3;
  player.points = 0;
  memset(gameTable, 0, sizeof(gameTable));
  gameSequence = fopen("numeros.txt", "r");
  if (gameSequence == NULL) {
    clearTerminal();
    printf("Erro ao abrir o arquivo numeros.txt (Você provavelmente apagou ele)\n");
    exit(1);
  }

  fscanf(gameSequence, "%d", &nextValue1);
  fscanf(gameSequence, "%d", &nextValue2);
}

void handleGame(){
  // readPlayerInRanking();
  printf("\033[0m==================================================\033[0m\n");
  printf("PTS: ");
  printCenter(player.points, 10);
  printf("||          Proximas: |");
  printCenter(nextValue1, 5);
  printf("\033[0m|");
  printCenter(nextValue2, 5);
  printf("\033[0m| \n");
  printf("\033[0m--------------------------------------------------\n");
  if(erasing == 1){
    printf("SEU TABULEIRO ESTÁ CHEIO, UMA BORRACHA FOI USADA!\n");
  } else {
    printf("borrachas: %d\n", eraser);
    for(int i = 0; i<columns; i++){
      if(currentPointer == i){
        printf("     *    ");
      } else {
        printf("          ");
      }
    }
  }
  printf("\n\033[0m--------------------------------------------------\033[0m\n");
  for(int i = 0; i<rows; i++){
    for(int j = 0; j<columns; j++){
      if(gameTable[i][j] == 0){
        printf("|        |");
      } else {
        printf("|");
        if(erasing && i == eraserY && j == eraserX){
          printf("\033[0;31m");
          printCenter(gameTable[i][j], 8);
        } else {
          if(gameTable[i][j] < 0){
            int positiveValue =  gameTable[i][j]*-1;
            printf("\033[0;31m");
            printCenter(positiveValue, 8);
          } else {
            printCenter(gameTable[i][j], 8);
          }
        }
        printf("\033[0m|");
      }
    }
    printf("\n\033[0m--------------------------------------------------\033[0m\n");
  }

  if(erasing == 1){
    printf("   use WASD para selecionar onde usar a borracha");
  }

  merge_ = merge(gameTable, &iLastFall, & jLastFall);
  if(merge_ != 0){ return;}

  int fall_ = fall(gameTable, &iLastFall, &jLastFall);
  if(fall_==1){ return;} 
  
  int gameover_ = gameover(gameTable, nextValue1);
  if(gameover_ == 1 && erasing==0){
    if(eraser == 0) {
      printf("Fim de jogo, %s! Não tem mais onde você jogar\n", player.name);
      writePlayerInRanking(player);
      gameStatus = 2;
      mySleep(3000);
      clearTerminal();
      return;
    } else {
      erasing = 1;
      return;
    }
  }


  if(player.points >= nextEraser){
    eraser++;
    nextEraser = nextEraser*pow(2, 3);
  }

  // while(1){
  //   char key = readKey();
  //   printf("%d", key);
  // }

  char key = readKey();
  if(key == 65 || key == 97){ //A

    if(erasing){
      if(eraserX == 0){eraserX = columns-1;}
      else {eraserX--;}
    } else {
      if(currentPointer == 0){ currentPointer = columns-1; }
      else {currentPointer--;};
    }
    
  } else   if(key == 68 || key == 100){ // D
    if(erasing){
      if(eraserX == columns-1){eraserX = 0;}
      else {eraserX++;}
    } else {
      if(currentPointer == columns-1){ currentPointer = 0; } 
      else {currentPointer++;}
    }
  } else if(key == 115){ // S
    if(erasing){
      if(eraserY == rows-1){
        eraserY = 0;
      }else(eraserY++);
    }
  } else if(key == 119){ // W
      if(eraserY == 0){
        eraserY = rows-1;
      }else(eraserY--);
  } else if (key == 10 || key == 13){ // ENTER
    if(erasing){ // Usa a borracha
      gameTable[eraserY][eraserX] = 0;
      if(eraserMode == 1){
        if(eraserY < rows-1){
          gameTable[eraserY+1][eraserX] = 0;
        }
        if(eraserY >0 ){
          gameTable[eraserY-1][eraserX] = 0;
        }
        if(eraserX < columns -1){
          gameTable[eraserY][eraserX+1] = 0;
        }
        if(eraserX > 0){
          gameTable[eraserY][eraserX-1] = 0;
        }
      }
      erasing = 0;
      eraser--;
    } else if(gameTable[0][currentPointer] == 0){
      gameTable[0][currentPointer] = nextValue1;
      nextValue1 = nextValue2;
      iLastFall = 0;
      jLastFall = currentPointer;
      if(fscanf(gameSequence, " %d", &nextValue2) == EOF){
        printf("Parabens %s, você ganhou!!!!!\n", player.name);
        writePlayerInRanking(player);
        gameStatus = 2;
        mySleep(3000);
        clearTerminal();
      }
    }
  }
}