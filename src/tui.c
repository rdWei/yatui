#include "../include/tui.h"
#include "../include/color.h"

void tui_init() {}
void tui_end() {
  setCursor(VISIBLE);
  setEcho(VISIBLE);
  setColor(RESET);
  clearTerminal();
}
