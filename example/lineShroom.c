#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/line.h"
#include "../include/terminal.h"
#include "../include/tui.h"
#include "../include/color.h"

int randN() {
  return rand() % 64;
}

int main() {
  setEcho(INVISIBLE);
  setCursor(INVISIBLE);
  setMode(NON_CANONICAL);
  setMode(NON_BLOCK);

  clearTerminal();

  
  srand(time(NULL));

  Line line = newLine(newPoint(1, 1), newPoint(10, 5));

  drawLine(line, '#');

  char key;
  
  do {
    if (key != EOF) {
      // Key handling
    }

    Line lineArr[] = {
    newLine(newPoint(randN(), randN()), newPoint(randN(), randN())),
    newLine(newPoint(randN(), randN()), newPoint(randN(), randN())),
    newLine(newPoint(randN(), randN()), newPoint(randN(), randN()))
    };

    for (int x = 0; x < sizeof(lineArr)/sizeof(Line); x++) {
      setRandomColor();
      drawLine(lineArr[x], '#');
      setColor(BG_WHITE);
      setColor(BLACK);
      setColor(BOLD);
      printfAtXY(1, 1, "Press <Q> to exit.");
      setColor(RESET);
      usleep(10000);
      clearTerminal();
    }
  } while ( (key = getchar()) != 'q' );

  tui_end();
}
