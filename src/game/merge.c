#include "game.h"
#include <math.h>
#include "../utils/utils.h"

int merge(int gameTable[rows][columns], int* iLastFall, int* jLastFall){

  int fallVal = gameTable[*iLastFall][*jLastFall];
  if( 
    fallVal == 0 ||
    (*iLastFall!=9 && gameTable[*iLastFall+1][*jLastFall] ==0) 
   ){
    return 0;
  }
  int n = 0; 
  if( *iLastFall>0 && gameTable[*iLastFall][*jLastFall-1] == fallVal ){ // Valor da esquerda 
    n++;
    if(gameTable[*iLastFall][*jLastFall-1] < 0){
      gameTable[*iLastFall][*jLastFall-1] = 0;
    } else {
      gameTable[*iLastFall][*jLastFall-1] *= -1;
    }
  }

  if(*iLastFall != 4 && gameTable[*iLastFall][*jLastFall+1] == fallVal ){ // Valor da direita 
    n++;
    if(gameTable[*iLastFall][*jLastFall+1] < 0){
      gameTable[*iLastFall][*jLastFall+1] = 0;
    } else {
      gameTable[*iLastFall][*jLastFall+1] *= -1;
    }
  }

  if( *iLastFall != 9 && gameTable[*iLastFall+1][*jLastFall] == fallVal ){ // Valor de baixo 
    n++;
    if(gameTable[*iLastFall+1][*jLastFall] < 0){
      gameTable[*iLastFall+1][*jLastFall] = 0;
    } else {
      gameTable[*iLastFall+1][*jLastFall] *= -1;
    }
  }

  if(n!=0){
    if(gameTable[*iLastFall][*jLastFall] < 0 ){
      gameTable[*iLastFall][*jLastFall] = fallVal*pow(2, n)*-1;
      mySleep(250);
    } else {
      gameTable[*iLastFall][*jLastFall] *= -1;
    }
    return 1;
  } 

  return 0;

}