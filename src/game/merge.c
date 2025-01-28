#include "game.h"
#include <math.h>
#include "../utils/utils.h"

void resetSpot(int gameTable[rows][columns], int i, int j){
    if(gameTable[i][j] < 0){ gameTable[i][j] = 0; } 
    else { gameTable[i][j] *= -1; }
}

int merge(int gameTable[rows][columns], int* iLastFall, int* jLastFall){

  int fallVal = gameTable[*iLastFall][*jLastFall];
  if( fallVal == 0 || (*iLastFall!=9 && gameTable[*iLastFall+1][*jLastFall] ==0) ){
    return 0;
  }

  int n = 0; 
  if( *jLastFall>0 && gameTable[*iLastFall][*jLastFall-1] == fallVal ){ // Valor da esquerda 
    n++;
    resetSpot(gameTable, *iLastFall, *jLastFall-1);
  }

  if(*jLastFall != 4 && gameTable[*iLastFall][*jLastFall+1] == fallVal ){ // Valor da direita 
    n++;
    resetSpot(gameTable, *iLastFall, *jLastFall+1);
  }

  if( *iLastFall != 9 && gameTable[*iLastFall+1][*jLastFall] == fallVal ){ // Valor de baixo 
    n++;
    resetSpot(gameTable, *iLastFall+1, *jLastFall);    
  }

  if(n!=0){
    
    if(gameTable[*iLastFall][*jLastFall] < 0 ){
      gameTable[*iLastFall][*jLastFall] = fallVal*pow(2, n)*-1;
      mySleep(400);
    } else {
      gameTable[*iLastFall][*jLastFall] *= -1;
    }
    return 1;
  } 

  return 0;

}