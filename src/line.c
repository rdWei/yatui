#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/line.h"

Line newLine(Point start, Point end) {
  Line line = {
    start,
    end
  };

  return line;
}

// Da studiare TODO
void drawLine(Line line, char character) {
    int x0 = line.start.x;
    int y0 = line.start.y;
    int x1 = line.end.x;
    int y1 = line.end.y;

    int dx = abs(x1 - x0);
    int dy = -abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx + dy;

    while (1) {
        printf("\033[%d;%dH%c", y0, x0, character);

        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 >= dy) {
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx) {
            err += dx;
            y0 += sy;
        }
    }
}

