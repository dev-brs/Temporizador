#ifndef COLORS_H
#define COLORS_H

#include <stdio.h>

typedef enum {
    RESET,
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
} COLORS;

void textColor(COLORS selectedColor);
void backgroundColor(COLORS selectedColor);
void limparConsole();

#endif
