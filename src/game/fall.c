#include "game.h"
#include "../utils/utils.h"

int fall(int gameTable[rows][columns], int* iLastFall, int* jLastFall){
  int fall_ = 0;
  for (int i = 0; i < rows-1; i++) { // Cada linha
    for (int j = 0; j < columns; j++) { // cada coluna
      if(gameTable[i+1][j] == 0 && gameTable[i][j] != 0 ){
        gameTable[i+1][j] = gameTable[i][j];
        gameTable[i][j] = 0;
        *iLastFall = i+1;
        *jLastFall = j;
        fall_ =1;
        mySleep(50);
        break;
      }
    }
    if(fall_ == 1){
      break;
    }
  }

  return fall_;

}