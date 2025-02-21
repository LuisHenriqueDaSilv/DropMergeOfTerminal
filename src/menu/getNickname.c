#include "menu.h"
#include "../utils/utils.h"
#include <string.h>

void getNickname(){
  printf("Seja bem vindo(a) ao \033[32mDropmerge de Terminal!\033[0m\n\n");
  printf("Informe seu nickname: ");
  fgets(player.name, 50, stdin);
  player.name[strcspn(player.name, "\n")] = '\0';
  gameStatus = 2;
}