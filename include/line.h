#ifndef LINE_H
#define LINE_H

#include "point.h"

typedef struct {
  Point start;
  Point end;
} Line;

Line newLine(Point start, Point end);
void drawLine(Line line, char character);

#endif
