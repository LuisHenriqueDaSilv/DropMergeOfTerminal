#include <stdio.h>

#ifdef _WIN32
  #include <conio.h>
#else
  #include <termios.h>
  #include <unistd.h>
#endif

#ifndef _WIN32
void enableRawMode() {
  struct termios term;
  tcgetattr(STDIN_FILENO, &term);
  term.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void disableRawMode() {
  struct termios term;
  tcgetattr(STDIN_FILENO, &term);
  term.c_lflag |= (ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
#endif

char readKey(){
  printf("\n");
  char c = '\0';
  #ifdef _WIN32
    while (c == '\0') {
      if (_kbhit()) {
        c = _getch();
      }
    }
  #else
    enableRawMode();
    while (c == '\0') {
      read(STDIN_FILENO, &c, 1);
    }

    disableRawMode();
  #endif

  return c;
}