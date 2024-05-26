#include <stdio.h>
#include <math.h>
#include <conio.h>
#include "bugiganga.cpp"
#include "matriz_nome.c"

void mostranome();

int main()
{
    mostranome();
    return 0;
}

void mostranome(void)
{
    for (int i = 0; i < LINHAS_NOME; i++)
        for (int j = 0; j < COLUNAS_NOME; j++)
        {
            gotoxy(j, i);
            if (MATRIZ_NOME[i][j] == 0)
            {
                textcolor(BLACK);
            }
            if (MATRIZ_NOME[i][j] == 1)
            {
                textcolor(RED);
            }
            printf("%c", 219);
        }
}