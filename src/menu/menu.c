#include "../keyboard/keyboard.h"
#include <stdio.h>
#include "../game/game.h"
#include "../utils/utils.h"

#include "menu.h"

int pointer = 0;

void handleMenu(){
  printf("\033[0m==================================================\033[0m\n");
  printf("   Seja bem vindo ao \033[32mDropmerge de Terminal!\n");
  printf("\033[0m--------------------------------------------------\n");
  printf("\033[0m Para jogar, e facil: use as teclas \033[35mW, A, S e D\n \033[0mpara mover a seta no menu, e pressione \033[35mEnter\n \033[0mpara selecionar a opcao desejada. Se precisar \n de mais informações, escolha o modo \033[35mAjuda.\n");


  printf("\n   \033[0mJogar");
  if(pointer == 0){printf(" \033[36m<-");};
  printf("\n   \033[0mRanking");
  if(pointer == 1){printf(" \033[36m<-");};
  printf("\n   \033[0mConfiguracoes");
  if(pointer == 2){printf(" \033[36m<-");};
  printf("\n   \033[0mAjuda/Sobre");
  if(pointer == 3){printf(" \033[36m<-");};
  printf("\n   \033[31mSair");
  if(pointer == 4){printf(" \033[36m<-");};
  printf("\n\n\n\033[1;0m==================================================\033[0m\n");
  printf("\033[1;0m       Desenvolvido por: \033[1;32mLuis H. Silva\033[0m\n");
  printf("\033[1;0m==================================================\033[0m");

  char key = readKey(); 
  printf("%d", key);
  
  if(key == 83 || key == 115){
    if(pointer == 4){pointer = 0;}
    else {pointer++;}
  } else if(key == 119 || key == 87){
    if(pointer == 0){pointer = 4;}
    else {pointer--;}
  } else if(key == 10 || key == 13){ 
    if(pointer == 4){
      gameStatus = 0;
    } if (pointer == 0){
      gameStart();
    }
  }


}