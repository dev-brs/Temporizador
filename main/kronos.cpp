#include <stdio.h>
#include "bugiganga.cpp"
#include "matrizes.c"

void printMatriz(struct estruturaDefault estrutura, DOS_COLORS corFundo, DOS_COLORS corLetra);
// system("cls");

int main()
{
    printMatriz(algarismoZero, BLACK, RED);
    Sleep(1000);
    system("cls");
    printMatriz(algarismoUm, BLACK, RED);
    Sleep(1000);
    system("cls");
    printMatriz(algarismoDois, BLACK, RED);
    Sleep(1000);
    system("cls");
    printMatriz(algarismoTres, BLACK, RED);
    Sleep(1000);
    system("cls");
    printMatriz(algarismoQuatro, BLACK, RED);
    Sleep(1000);
    system("cls");
    printMatriz(algarismoCinco, BLACK, RED);
    Sleep(1000);
    system("cls");
    printMatriz(algarismoSeis, BLACK, RED);
    Sleep(1000);
    system("cls");
    printMatriz(algarismoSete, BLACK, RED);
    Sleep(1000);
    system("cls");
    printMatriz(algarismoOito, BLACK, RED);
    Sleep(1000);
    system("cls");
    printMatriz(algarismoNove, BLACK, RED);
    Sleep(1000);
    system("cls");
    printMatriz(algarismoZero, BLACK, RED);
    return 0;
}

void printMatriz(struct estruturaDefault estrutura, DOS_COLORS corFundo, DOS_COLORS corLetra)
{
    for (int i = 0; i < estrutura.linhas; i++){
        for (int j = 0; j < estrutura.colunas; j++)
        {
            if (estrutura.matriz[i * estrutura.colunas + j])
            {
               textcolor(corLetra);
            }
            else
            {
                textcolor(corFundo);
            }
            printf("%c", 219);
        }
        printf("\n");
    }
    textcolor(WHITE);
}
