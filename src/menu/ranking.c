#include <string.h>

#include "./menu.h"
#include "../keyboard/keyboard.h"

int page = 0;

void showRanking(){
  Player players[15];
  for(int i =0; i<15; i++){
    players[i].points = -1;
  }
  int nOfPlayers = readPlayersInRanking(page, 15, players );
  printf("\033[0m==================================================\033[0m\n");
  printf(" Esses são os lendários jogadores do DropMerge!\n");
  printf(" Diz a lenda que ninguém foi capaz de superar \n");
  printf("              as pontuações deles!\n");
  printf("\033[0m--------------------------------------------------\n");
  for(int i = 0; i<15; i++){
    if(players[i].points > 0){
      printf(" %dº %s-%d\n", page*15+i+1, players[i].name, players[i].points);
    } else {
      printf(" %dº\n", (page*15)+i+1);
    }
  }
  printf("\n");
  printf("          Use A e D para passar as páginas");
  printf("\n\033[1;0m==================================================\033[0m\n");
  printf("\033[1;0mPressione ESC para voltar                 Pag: %d\033[0m\n", page+1);
  printf("\033[1;0m==================================================\033[0m");
  
  // while(1){
  //   char key = readKey();
  //   printf("%d", key);
  // }
  char key = readKey();
  if(key == 27){
    page = 0;
    gameStatus = 2;
  } else if (key == 97  || key == 65) { // A
    if(page != 0){page--;};
  } else if(key == 100 || key == 68){ // D
    if(nOfPlayers != 0){
      page++;
    }
  }
}