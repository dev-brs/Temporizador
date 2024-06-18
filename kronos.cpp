#include <iostream>
#include <vector>
#include <locale.h>
#include <chrono>
#include <thread>
#include <functional>
#include <atomic>
#include <conio.h>

#include "src/colors.h"
#include "src/structs.h"
#include "src/mat.h"
#include "src/timer.h"
#include "src/matrizes.cpp"

#define UM_SEGUNDO 1000
#define LIMIAR_DE_TEMPO 410
#define TEMPO_INICIAL 420

typedef enum ESTADOS {
    PARADO, 
    CONTANDO
};

int CONTAGEM = TEMPO_INICIAL;
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
void atualizaEstado(ESTADOS *estadoAtual, Timer *timer);
void callbackTimer();
void printUserMenu();

int main() {
    setlocale(LC_ALL, "");

    Timer timer;
    char teclaPressionada;
    ESTADOS estadoAtual = PARADO;

    timer.start(std::chrono::milliseconds(UM_SEGUNDO), callbackTimer);
    
    while(true){
        atualizaEstado(&estadoAtual, &timer);
        if(CONTAGEM < LIMIAR_DE_TEMPO){
            timer.stop();
            return 1;
        }
        if ( kbhit() ) {
            teclaPressionada = getch();

            switch(teclaPressionada) {
                case 'P':
                case 'p':
                    (estadoAtual) ? estadoAtual = PARADO : estadoAtual = CONTANDO;
                    break;
            }
        }
    };

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

void printUserMenu()
{
    std::cout << "Segue abaixo menu de funcionalidades" << std::endl << std::endl;
    std::cout << "P - Pause/Play" << std::endl;
}

void callbackTimer() {
    if (CONTAGEM <= 0) return;

    limparConsole();

    dividirNumero(CONTAGEM, &centena, &dezena, &unidade);
    std::vector<estruturaDefault> matrizes = {NUMEROS[centena], NUMEROS[dezena], NUMEROS[unidade]};
    estruturaDefault resultado = concatenarMatrizes(matrizes);
    printMatriz(resultado, BLACK, GREEN);
    printUserMenu();
    
    CONTAGEM--;
}

void atualizaEstado(ESTADOS *estadoAtual, Timer *timer) {
    static bool timerStarted = false;

    switch(*estadoAtual) {
        case PARADO:
            if (timerStarted) {
                timer->stop();
                timerStarted = false;
            }
            break;
        case CONTANDO:
            if (!timerStarted) {
                timer->start(std::chrono::milliseconds(UM_SEGUNDO), callbackTimer);
                timerStarted = true;
            }
            break;
    }
}