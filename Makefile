CC =gcc

all: ./run 
	@echo "\nCompilado"
run: 
	$(CC) ./src/main.c ./src/keyboard/keyboard.c ./src/keyboard/keyboard.h ./src/menu/menu.c ./src/menu/menu.h ./src/game/game.h ./src/game/game.c ./src/utils/utils.h ./src/utils/printCenter.c ./src/game/fall.c ./src/utils/mySleep.c ./src/game/merge.c -o ./run -lm