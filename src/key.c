#include "../include/key.h"

bool isKeyPressed(char *key) {
  struct termios oldt, newt;
  int oldf;
  int ch;

  // Salva stato corrente del terminale
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~ICANON; // Disabilita modalità canonica ed echo
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  // Imposta lettura non bloccante
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  // Ripristina stato terminale
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if (ch != EOF) {
      *key = (char)ch;
      return true;
  }

  return false;
}

