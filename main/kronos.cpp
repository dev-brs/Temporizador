#include <stdio.h>
#include "structs.h"
#include "bugiganga.cpp"
#include "structs.c"

void printMatriz(struct estruturaDefault estrutura);
// system("cls");

int main()
{
    printMatriz(nomeStruct);
    printf("\nhello world!");
    
    return 0;
}

void printMatriz(struct estruturaDefault estrutura)
{
    for (int i = 0; i < estrutura.linhas; i++){
        for (int j = 0; j < estrutura.colunas; j++)
        {
            if (estrutura.matriz[i * estrutura.colunas + j] == 0)
            {
                textcolor(BLACK);
            }
            if (estrutura.matriz[i * estrutura.colunas + j] == 1)
            {
               textcolor(RED);
            }
            printf("%c", 219);
        }
        printf("\n");
    }
    textcolor(WHITE);
}
