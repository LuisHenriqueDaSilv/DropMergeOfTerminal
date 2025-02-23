#include <stdio.h>
#include "utils.h"

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h> // Para Windows
#else
    #include <unistd.h>  // Para Unix/Linux
#endif

void mySleep(int ms) {
  #if defined(_WIN32) || defined(_WIN64)
    Sleep(ms);
  #else
    usleep(ms * 1000);
  #endif
  }