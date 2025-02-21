#include "game.h"

int gameover(int gameTable[rows][columns], int nextVal){
  int gameOver = 1;
  for(int i = 0; i<columns; i++){
    if(gameTable[0][i] == 0){
      gameOver = 0;
      break;
    }
  }
  return gameOver;
}