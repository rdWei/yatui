#include <stdio.h>

#include "box.h"
#include "point.h"
#include "terminal.h"

Box newBox(Point startPoint, uint8_t width, uint8_t height) {
  Box b = {
    startPoint,
    width,
    height
  };

  return b;
}

void drawBox(Box box, char character) {
 
  Point startPoint = box.startPoint; 

  uint8_t startx = startPoint.x;
  uint8_t starty = startPoint.y;

  uint8_t endx = startx + box.width;
  uint8_t endy = starty + box.height;


  while (startx != endx) {
    printf("\033[%d;%dH%c", starty, startx++, character);
  }

  while (starty != endy) {
    printf("\033[%d;%dH%c", starty++, startx, character);
  }

  while (startx != startPoint.x) {
    printf("\033[%d;%dH%c", starty, startx--, character);
  }

  while (starty != startPoint.y) {
    printf("\033[%d;%dH%c", starty--, startx, character);
  }

  fflush(stdout);
}

void drawBoxRelativeTo(Box mainBox, Box box, char character) {

  box.startPoint.x += mainBox.startPoint.x;
  box.startPoint.y += mainBox.startPoint.y;

  Point startPoint = box.startPoint; 

  uint8_t startx = startPoint.x;
  uint8_t starty = startPoint.y;

  uint8_t endx = startx + box.width;
  uint8_t endy = starty + box.height;


  while (startx != endx) {
    printf("\033[%d;%dH%c", starty, startx++, character);
  }

  while (starty != endy) {
    printf("\033[%d;%dH%c", starty++, startx, character);
  }

  while (startx != startPoint.x) {
    printf("\033[%d;%dH%c", starty, startx--, character);
  }

  while (starty != startPoint.y) {
    printf("\033[%d;%dH%c", starty--, startx, character);
  }

  fflush(stdout);
}

void drawFancyBox(Box box) {
  Point startPoint = box.startPoint;
  Point endPoint = newPoint(box.startPoint.x + box.width, box.startPoint.y + box.height);

  uint8_t startx = startPoint.x;
  uint8_t starty = startPoint.y;

  uint8_t endx= endPoint.x;
  uint8_t endy = endPoint.y;


  while (startx != endx) {
    printf("\033[%d;%dH─", starty, startx++);
  }

  while (starty != endy) {
  printf("\033[%d;%dH│", starty++, startx);
  }

  while (startx != startPoint.x) {
    printf("\033[%d;%dH─", starty, startx--);
  }

  while (starty != startPoint.y) {
    printf("\033[%d;%dH│", starty--, startx);
  }

  // Print Corner
  printf("\033[%d;%dH┌", startPoint.y, startPoint.x);
  printf("\033[%d;%dH└", endPoint.y, startPoint.x);
  printf("\033[%d;%dH┐", startPoint.y, endPoint.x);
  printf("\033[%d;%dH┘", endPoint.y, endPoint.x);
  fflush(stdout);
}

void drawFancyBoxRelativeTo(Box mainBox, Box box) {
  box.startPoint.x += mainBox.startPoint.x;
  box.startPoint.y += mainBox.startPoint.y;

  Point startPoint = box.startPoint;
  Point endPoint = newPoint(box.startPoint.x + box.width, box.startPoint.y + box.height);

  uint8_t startx = startPoint.x;
  uint8_t starty = startPoint.y;

  uint8_t endx= endPoint.x;
  uint8_t endy = endPoint.y;


  while (startx != endx) {
    printf("\033[%d;%dH─", starty, startx++);
  }

  while (starty != endy) {
  printf("\033[%d;%dH│", starty++, startx);
  }

  while (startx != startPoint.x) {
    printf("\033[%d;%dH─", starty, startx--);
  }

  while (starty != startPoint.y) {
    printf("\033[%d;%dH│", starty--, startx);
  }

  // Print Corner
  printf("\033[%d;%dH┌", startPoint.y, startPoint.x);
  printf("\033[%d;%dH└", endPoint.y, startPoint.x);
  printf("\033[%d;%dH┐", startPoint.y, endPoint.x);
  printf("\033[%d;%dH┘", endPoint.y, endPoint.x);
  fflush(stdout);
}




void drawBorder(char character) {
  Box box = {
    newPoint(1, 1),
    getTerminalSize().x - 1,
    getTerminalSize().y - 1
  };

  drawBox(box, character);
}

void drawFancyBorder() {
  Box box = {
    newPoint(1, 1),
    getTerminalSize().x - 1,
    getTerminalSize().y - 1
  };
  drawFancyBox(box);
}

void printAtXYRelativeTo(Box mainBox, uint8_t x, uint8_t y, char* string) {
  printAtXY(x + mainBox.startPoint.x, y + mainBox.startPoint.y, string);
}
