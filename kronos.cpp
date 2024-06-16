#include <iostream>
#include <vector>
#include <locale.h>
#include <chrono>
#include <thread>
#include <functional>
#include <atomic>
#include "src/colors.h"
#include "src/structs.h"
#include "src/mat.h"
#include "src/timer.h"
#include "src/matrizes.cpp"

#define UM_SEGUNDO 1000

int CONTAGEM;
int centena, dezena, unidade;
estruturaDefault NUMEROS[10] = {
        algarismoZero,
        algarismoUm,
        algarismoDois,
        algarismoTres,
        algarismoQuatro,
        algarismoCinco,
        algarismoSeis,
        algarismoSete,
        algarismoOito,
        algarismoNove        
    };

void printMatriz(struct estruturaDefault estrutura, COLORS corFundo, COLORS corLetra);
void dividirNumero(int numero, int *centena, int *dezena, int *unidade);
void callbackTimer();

int main() {
    setlocale(LC_ALL, "");

    CONTAGEM = 420;
    Timer timer;

    timer.start(std::chrono::milliseconds(UM_SEGUNDO), callbackTimer);

    while(true){};//soh pra passar o tempo

    timer.stop();

    return 0;
}

void dividirNumero(int numero, int *centena, int *dezena, int *unidade) {
    *centena = numero / 100;
    int resto = numero % 100;
    *dezena = resto / 10;
    *unidade = resto % 10;
}

void printMatriz(struct estruturaDefault estrutura, COLORS corFundo, COLORS corLetra) {
    for (int i = 0; i < estrutura.linhas; i++){
        for (int j = 0; j < estrutura.colunas; j++) {
            if (estrutura.matriz[i * estrutura.colunas + j]) {
                textColor(corLetra);
            } else {
                textColor(corFundo);
            }
            std::cout << "█";
        }
        std::cout << std::endl;
    }
    textColor(WHITE);
}

void callbackTimer() {
    if (CONTAGEM <= 0) return;

    limparConsole();

    dividirNumero(CONTAGEM, &centena, &dezena, &unidade);
    std::vector<estruturaDefault> matrizes = {NUMEROS[centena], NUMEROS[dezena], NUMEROS[unidade]};
    estruturaDefault resultado = concatenarMatrizes(matrizes);
    printMatriz(resultado, BLACK, WHITE);

    CONTAGEM--;
}
