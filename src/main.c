#include <stdio.h>
#include "keyboard/keyboard.h"

int main(){
  while(1){
    char key = readKey();
    printf("\nTecla pressionada: %c\n", key);
  }
}