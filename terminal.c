#include "terminal.h"

void clearTerminal(void) {
  printf("\033[H\033[J"); fflush(stdout);
}

Point getTerminalSize() {
  struct winsize w;
  ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
  return newPoint(w.ws_col, w.ws_row);
}

void setCursor(uint8_t state) {
  if (state) {
    printf("\033[?25h"); fflush(stdout);
    return;
  }
  printf("\033[?25l"); fflush(stdout);
}

void setEcho(uint8_t state) {
  struct termios term;
  if (state) {
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ECHO; 
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    return;
  }
  tcgetattr(STDIN_FILENO, &term);
  term.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int terminalResized() {
    static struct winsize last_size = {0, 0, 0, 0};
    struct winsize current_size;
    
    ioctl(STDIN_FILENO, TIOCGWINSZ, &current_size);
    
    if (current_size.ws_col != last_size.ws_col || current_size.ws_row != last_size.ws_row) {
        last_size = current_size;
        return 1;
    }
    
    return 0;
}
