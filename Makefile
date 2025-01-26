CC =gcc

all: ./run 
	@echo "\nCompilado"
run: 
	$(CC) ./src/main.c ./src/keyboard/keyboard.c ./src/keyboard/keyboard.h ./src/menu/menu.c ./src/menu/menu.h -o ./run