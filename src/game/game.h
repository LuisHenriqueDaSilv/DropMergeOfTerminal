#ifndef GAME_HEADER
  #define GAME_HEADER
    #include <stdio.h>
    extern int gameStatus;
    extern int rows;
    extern int columns;
    int fall();
    int merge();
    void gameStart();
    void handleGame();
#endif