#include <stdio.h>
#include "bugiganga.cpp"
#include "matrizes.c"

void printMatriz(struct estruturaDefault estrutura, DOS_COLORS corFundo, DOS_COLORS corLetra);
void printContador(int tempoAtual ,int quantidadeDeDigitos, DOS_COLORS corFundo, DOS_COLORS corLetra);

int main()
{
    printMatriz(algarismoZero, BLACK, RED);

    printContador(20, 3, BLACK, RED);
    
    return 0;
}

void printContador(int tempoAtual ,int quantidadeDeDigitos, DOS_COLORS corFundo, DOS_COLORS corLetra){

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
