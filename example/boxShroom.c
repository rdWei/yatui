#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "../include/terminal.h"
#include "../include/tui.h"
#include "../include/box.h"
#include "../include/keyboard.h"
#include "../include/color.h"

int randN() {
  return rand() % 128;
}

int main() {
  setEcho(INVISIBLE);
  setCursor(INVISIBLE);
  setMode(NON_CANONICAL);
  setMode(NON_BLOCK);

  clearTerminal();

  srand(time(NULL));

  char key = ' ';
  
  while ( (key = getchar()) != KEY_q ) {

    if (key == EOF)  { ; } // Do nothing

    Box boxArr[] = {newBox(newPoint(randN(), randN()), randN(), randN()), newBox(newPoint(randN(), randN()), randN(), randN()), newBox(newPoint(randN(), randN()), randN(), randN())};

    for (int x = 0; x < 3; x++) {
      setRandomColor();
      drawFancyBox(boxArr[x]);
      setColor(BG_WHITE);
      setColor(BLACK);
      setColor(BOLD);
      printfAtXY(1, 1, "Press <Q> to exit.");
      setColor(RESET);
      usleep(10000);
    }

  }
  tui_end();
}
