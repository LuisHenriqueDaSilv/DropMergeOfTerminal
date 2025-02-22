#include <stdio.h>
#include <stdlib.h>

#include "menu/menu.h"
#include "game/game.h"
#include "utils/utils.h"


// Status:
  // 0: Exit
  // 1: Bem vindo
  // 2: Menu
  // 3: Jogo
  // 4: Ranking
  // 5: Help
  // 6: Settings
int gameStatus = 1;
int rows = 10,columns = 5;
Player player;
int eraser = 0;
int nextEraser = 1024;
int erasing = 0;
int eraserMode = 0; // 0: Remove apenas 1 valor, 1: remove todos ao redor

int main(){
  clearTerminal();
  while(gameStatus != 0){ // Game loop
    switch (gameStatus){
      case 0:
        break;
      case 1:
        getNickname();
        break;
      case 2:
        handleMenu();
        break;
      case 3: 
        handleGame();
        break;
      case 4: 
        showRanking();
        break;
      case 5: 
        showHelp();
        break;
      case 6:
        showSettings();
        break;
      default:
        break;
    }
    clearTerminal();
  }
}