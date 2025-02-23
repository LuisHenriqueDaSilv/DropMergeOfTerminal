CC =gcc

all: ./run 
	@echo "\nCompilado"
run: 
	$(CC) gcc ./src/main.c ./src/keyboard/keyboard.c ./src/keyboard/keyboard.h ./src/menu/menu.c ./src/menu/menu.h ./src/game/game.h ./src/game/game.c ./src/utils/utils.h ./src/utils/printCenter.c ./src/game/fall.c ./src/utils/mySleep.c ./src/game/merge.c ./src/menu/getNickname.c ./src/utils/clearTerminal.c ./src/game/rankingController.c ./src/menu/ranking.c ./src/game/gameover.c ./src/menu/help.c ./src/menu/settings.c  -o ./run -lm