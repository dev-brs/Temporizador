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

void textColor(COLORS selectedColor) {
    const char* colorCodes[] = {
        "\033[0m",   // RESET
        "\033[30m",  // BLACK
        "\033[31m",  // RED
        "\033[32m",  // GREEN
        "\033[33m",  // YELLOW
        "\033[34m",  // BLUE
        "\033[35m",  // MAGENTA
        "\033[36m",  // CYAN
        "\033[37m"   // WHITE
    };

    if (selectedColor < 0 || selectedColor > WHITE) {
        printf("\033[0m"); // Reset if color is out of range
    } else {
        printf("%s", colorCodes[selectedColor]);
    }
}

void backgroundColor(COLORS selectedColor) {
    const char* backgroundColorCodes[] = {
        "\033[0m",   // RESET
        "\033[40m",  // BLACK
        "\033[41m",  // RED
        "\033[42m",  // GREEN
        "\033[43m",  // YELLOW
        "\033[44m",  // BLUE
        "\033[45m",  // MAGENTA
        "\033[46m",  // CYAN
        "\033[47m"   // WHITE
    };

    if (selectedColor < 0 || selectedColor > WHITE) {
        printf("\033[0m"); // Reset if color is out of range
    } else {
        printf("%s", backgroundColorCodes[selectedColor]);
    }
}

void limparConsole() {
    // Sequência de escape ANSI para limpar o console
    std::cout << "\033[2J\033[1;1H";
}
