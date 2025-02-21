#ifndef GAME_HEADER
  #define GAME_HEADER
    #include <stdio.h>
    typedef struct {
      char name[50];
      int points;
    } Player;
    extern int gameStatus;
    extern int points;
    extern int rows;
    extern int columns;
    extern Player player;
    
    int readPlayersInRanking(int page, int n, Player players[]);
    void writePlayerInRanking(Player player);
    int fall(int gameTable[rows][columns], int* iLastFall, int* jLastFall);
    int merge(int gameTable[rows][columns], int* iLastFall, int* jLastFall);
    int gameover(int gameTable[rows][columns], int nextVal);
    void gameStart();
    void handleGame();

#endif