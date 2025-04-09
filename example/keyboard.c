#include "../include/keyboard.h"
#include "../include/terminal.h"
#include "../include/tui.h"
#include "../include/color.h"
#include "../include/box.h"
#include <stdio.h>

int main() {
  // Setup terminal settings
  setEcho(INVISIBLE); // Dont print pressed key
  setCursor(INVISIBLE); // Make cursor invisible
  setMode(NON_CANONICAL); // Dont wait for \n to read the input
  setMode(NON_BLOCK); // Dont wait for input

  clearTerminal();

  drawFancyBorder();
  printAtXY(3, 0, "[ Press a key to start ]");

  // Change color
  setColor(BG_WHITE);
  setColor(BLACK);

  char key;
  while ((key = getchar()) != KEY_q) {
    // Check if the key is actually pressed
    if (!(key == EOF)) {
      // Print the pressed key
      printfAtXY(10, 10, "Printed key: %c", key);
    }
  }

  tui_end();
}
