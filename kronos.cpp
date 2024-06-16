#include <iostream>
#include <vector>
#include <locale.h>
#include "src/colors.h"
#include "src/structs.h"
#include "src/mat.h"
#include "src/matrizes.cpp"
#include "src/timer.cpp"

void printMatriz(struct estruturaDefault estrutura, COLORS corFundo, COLORS corLetra);

int main() {
    setlocale(LC_ALL, "");
    // Vetor de matrizes para concatenar
    std::vector<estruturaDefault> matrizes = {algarismoOito, algarismoNove, algarismoDois};

    // Concatenar matrizes A, B e C
    estruturaDefault resultado = concatenarMatrizes(matrizes);

    // Imprimir a matriz concatenada (apenas para verificar o resultado)
    printMatriz(resultado, BLACK, WHITE);
    
    timerDelay(4000);
    matrizes = {algarismoOito, algarismoNove, algarismoTres};

    // Concatenar matrizes A, B e C
    resultado = concatenarMatrizes(matrizes);

    // Imprimir a matriz concatenada (apenas para verificar o resultado)
    printMatriz(resultado, BLACK, WHITE);
    
    return 0;
}
void printMatriz(struct estruturaDefault estrutura, COLORS corFundo, COLORS corLetra)
{
    limparConsole();
    for (int i = 0; i < estrutura.linhas; i++){
        for (int j = 0; j < estrutura.colunas; j++)
        {
            if (estrutura.matriz[i * estrutura.colunas + j])
            {
               textColor(corLetra);
            }
            else
            {
                textColor(corFundo);
            }
            std::cout << "█";
        }
        std::cout << std::endl;
    }
    textColor(WHITE);
}