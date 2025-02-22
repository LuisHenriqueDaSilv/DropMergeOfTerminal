#include <string.h>

#include "./menu.h"
#include "../keyboard/keyboard.h"
#include "../game/game.h"

int settingsPointer = 0;

void showSettings(){

  printf("\033[0m==================================================\033[0m\n");
  printf("              Configuracoes!\n");
  printf("\033[0m--------------------------------------------------\n");
  printf("\n   \033[0mZerar ranking");
  if(settingsPointer == 0){printf(" \033[36m<-");};
  printf("\n   \033[0mModo da borracha: %d", eraserMode+1);
  if(settingsPointer == 1){printf(" \033[36m<-");};
  printf("\n\n   \033[0mBorracha modo 1: Apaga apenas 1. \n   Borracha modo 2: apaga todos ao redor");
  printf("\n\033[1;0m==================================================\033[0m\n");
  printf("\033[1;0mPressione ESC para voltar                 \033[0m\n");
  printf("\033[1;0m==================================================\033[0m");

  // while(1){
  //   char key = readKey(); 
  //   printf("%d", key);
  // }

  char key = readKey(); 
  if(key == 83 || key == 115){
    if(settingsPointer == 1){settingsPointer = 0;}
    else {settingsPointer++;}
  } else if(key == 119 || key == 87){
    if(settingsPointer == 0){settingsPointer = 1;}
    else {settingsPointer--;}
  } else if(key == 10 || key == 13){ // Enter 
 
    if(settingsPointer == 0){
      clearRanking();
    } else if(settingsPointer == 1){
      if(eraserMode == 1){
        eraserMode = 0;
      } else {
        eraserMode = 1;
      }
    }
  } else if(key == 27){
    gameStatus = 2;
  }
}