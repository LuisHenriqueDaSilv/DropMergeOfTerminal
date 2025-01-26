#include "utils.h"
#include <stdio.h>
#include <string.h>

void printCenter(int number, int length){
  char numStr[20];
  sprintf(numStr, "%d", number);
  int numLen = strlen(numStr);
  int padding = (length - numLen) / 2;
  int leftPadding = padding;
  int rightPadding = length - numLen - leftPadding;
  printf("%*s%s%*s", leftPadding, "", numStr, rightPadding, "");
}