// terminal.h

#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdint.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <asm-generic/ioctls.h>
#include <unistd.h>
#include <termios.h>

#include "point.h"

#define VISIBLE 1
#define INVISIBLE 0

void clearTerminal(void);
Point getTerminalSize();
void setCursor(uint8_t state);
void setEcho(uint8_t state);
int terminalResized();
void printAtXY(uint8_t x, uint8_t y, char* string);

#endif
