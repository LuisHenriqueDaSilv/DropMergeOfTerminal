#include <stdlib.h>
#include "../utils/utils.h"

#include "game.h"

int compare(const void *a, const void *b){
  Player playerA = *(Player *)a;
  Player playerB = *(Player *)b;

  return playerB.points-playerA.points; 
  
}

void writePlayerInRanking(Player player){
  if(player.points ==  0){ return;}

  FILE *file = fopen("ranking.bin", "rb");
  if(file){
    int counter = 0;
    Player aux; 
    while(fread(&aux, sizeof(Player), 1, file)  == 1){
      counter++;
    }
    fclose(file);

    Player players[counter+1];
    file = fopen("ranking.bin", "rb");
    for(int i = 0; i<counter; i++){
      fread(&players[i], sizeof(Player), 1, file);
    }
    fclose(file);

    players[counter] = player;
    qsort(players, counter+1, sizeof(Player), compare);

    file = fopen("ranking.bin", "wb+");
    for(int i = 0; i<counter+1; i++){
      fwrite(&players[i], sizeof(Player), 1, file);
    }
    fclose(file);
  } else {
    clearTerminal();
    printf("Não foi possivel abrir o arquivo ranking.bin (Você provavelmente apagou ele)");
    exit(0);
  }

}

int readPlayersInRanking(int page, int n, Player players[]){
  FILE *file = fopen("ranking.bin", "rb");
  if(file){
    int playersCount = 0; 
    for(int i = 0; playersCount < n; i++){
      Player aux; 
      if(fread(&aux, sizeof(Player), 1, file) != 1){
        break;
      }
      
      if(i>=page*n){
        players[playersCount] = aux;
        playersCount++;
      }
    }
    fclose(file);
    return playersCount;

  } else {
    clearTerminal();
    printf("Não foi possivel abrir o arquivo ranking.bin (Você provavelmente apagou ele)");
    exit(0);
  }
  return 0;
}

void clearRanking(){
  FILE *arquivo = fopen("ranking.bin", "wb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  fclose(arquivo);
  printf("Arquivo limpo com sucesso.\n");
  return;
}