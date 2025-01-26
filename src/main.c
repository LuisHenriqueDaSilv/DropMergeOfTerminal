#include <stdio.h>
#include <stdlib.h>

#include "menu/menu.h"
#include "game/game.h"

void clearTerminal() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

// Status:
  // 0: Exit
  // 1: Menu
  // 2: Jogo
int gameStatus = 1;
int rows = 7,columns = 5;


int main(){
  clearTerminal();
  while(gameStatus != 0){ // Game loop
    switch (gameStatus){
      case 0:
        break;
      case 1:
        handleMenu();
        break;
      case 2: 
        handleGame();
        break;
      default:
        break;
    }
    clearTerminal();
  }
}