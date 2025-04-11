#include <stdarg.h>
#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>

#include "../include/terminal.h"

void clearTerminal(void) {
  printf("\033[H\033[J"); fflush(stdout);
}

void setMode(uint8_t mode) {
  switch (mode) {
    case NON_BLOCK:
      fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL) | O_NONBLOCK);
      return;
    case BLOCK:
      fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL) & ~O_NONBLOCK);
      return;
    case CANONICAL:
      struct termios newt;
      tcgetattr(STDIN_FILENO, &newt);
      newt.c_lflag |= ICANON;
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      return;
    case NON_CANONICAL:
      struct termios newterm;
      tcgetattr(STDIN_FILENO, &newterm);
      newterm.c_lflag &= ~ICANON;
      tcsetattr(STDIN_FILENO, TCSANOW, &newterm);
      return;
    default:
      return;
  }
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

void printAtXY(uint8_t x, uint8_t y, char* string) {
  printf("\033[%d;%dH%s", y, x, string); fflush(stdout);
}

void printfAtXY(uint8_t x, uint8_t y, char* fmt, ...) {
  va_list args;
  va_start(args, fmt);

  printf("\033[%d;%dH", y, x); fflush(stdout);
  
  vprintf(fmt, args);

  va_end(args);
}

void mvCursorAtXY(uint8_t x, uint8_t y) {
  printf("\033[%d;%dH", y, x); fflush(stdout);
}
