#ifndef BOX_H
#define BOX_H

#include "point.h"
#include <stdint.h>

typedef struct {
  Point startPoint;
  int8_t width;
  int8_t height;
} Box;

Box newBox(Point startPoint, uint8_t width, uint8_t height);
void drawBox(Box box, char character);
void drawBoxRelativeTo(Box mainBox, Box subBox, char character);
void drawFancyBox(Box box);
void drawFancyBoxRelativeTo(Box mainBox, Box box);
void drawBorder(char character);
void drawFancyBorder();
void printAtXYRelativeTo(Box mainBox, uint8_t x, uint8_t y, char* string);
void printfAtXYRelativeTo(Box mainBox, uint8_t x, uint8_t y, char* fmt, ...);
#endif

