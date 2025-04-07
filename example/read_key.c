#include "../include/tui.h"
#include "../include/terminal.h"
#include "../include/box.h"
#include "../include/key.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  // Init
  setEcho(INVISIBLE);
  setCursor(INVISIBLE);
  clearTerminal();

  Box box = newBox(newPoint(10, 5), 20, 10);
  drawFancyBox(box);

  printfAtXY(30, 30, "%s: %d", "Dio", 10);

  char key = ' ';
  while (key != 'q') {
    if (isKeyPressed(&key)) {
      char* string = malloc(sizeof(char) * 32);
      sprintf(string, "Pressed Key: %c", key);
      printAtXYRelativeTo(box, 4, 2, string);
    }
  }

  tui_end();
}
