CC =gcc

all: ./run 
	@echo "\nCompilado"
run: 
	$(CC) ./src/main.c ./src/keyboard/keyboard.c -o ./run