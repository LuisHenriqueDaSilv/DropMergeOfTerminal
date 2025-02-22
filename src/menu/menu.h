
#ifndef MENU_HEADER
#define MENU_HEADER
  #include "../game/game.h"
  #include <stdio.h>
  extern int gameStatus;
  extern Player player;
  void handleMenu();
  void getNickname();
  void showRanking();
  void showHelp();
  void showSettings();
#endif