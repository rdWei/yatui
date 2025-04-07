#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include  "../include/color.h"

void setColor(char* code) {
  printf("%s", code);
}

void setRandomColor() {
  static int init = 0;
  if (!init) {
    srand(time(NULL));
    init = 1;
  }

  char* colorArr[] = {BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
  // char* bgArr[] = {BG_RED, BG_GREEN, BG_YELLOW, BG_BLUE, BG_MAGENTA, BG_CYAN, BG_WHITE, BG_BLACK};
  uint8_t color = rand() % 8;
  // uint8_t bg = rand() % 8;
  printf("%s", colorArr[color]);
  // printf("%s", bgArr[color]);
}
