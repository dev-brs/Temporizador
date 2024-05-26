#include <stdio.h>
#include <math.h>
#include <conio.h>
#include "bugiganga.cpp"
int mtrxcentena[7][8] = {0};
int mtrxdezena[7][8] = {0};
int mtrxunidade[7][8] = {0};
int matrixnome[9][25] =
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1};
int animacao1[21][31] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 0, 0, 0, 0, 0,
    0, 0, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 0,
    3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 2, 2, 2,
    3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 2, 2, 2,
    3, 3, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 2, 2, 2,
    3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 2, 2, 0,
    3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 0, 0, 0, 0, 0,
    0, 0, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 0, 0, 0, 0, 0,
    0, 0, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 3, 3, 3, 3, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0,
    0, 0, 2, 2, 2, 2, 2, 2, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0,
    0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0};
int animacao2[21][31] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 0, 0, 0, 0, 0,
    0, 0, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 0,
    3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 2, 2, 2,
    3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 2, 2, 2,
    3, 3, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 2, 2, 2,
    3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 2, 2, 0,
    3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 0, 0, 0, 0, 0,
    0, 0, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 0, 0, 0, 0, 0,
    0, 0, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 3, 3, 3, 3, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0,
    0, 0, 2, 2, 2, 2, 2, 2, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0,
    0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0};
void mostranimacao1(void)
{
   for (int i = 0; i < 21; i++)
      for (int j = 0; j < 31; j++)
      {
         gotoxy(j + 5, i + 5);
         if (animacao1[i][j] == 0)
         {
            textcolor(AZUL);
         }
         if (animacao1[i][j] == 1)
         {
            textcolor(YELLOW);
         }
         if (animacao1[i][j] == 2)
         {
            textcolor(YELLOW);
         }
         if (animacao1[i][j] == 3)
         {
            textcolor(PRETO);
         }
         if (animacao1[i][j] == 4)
         {
            textcolor(DARK_GRAY);
         }
         printf("%c", 219);
      }
}
void mostranimacao2(void)
{
   for (int i = 0; i < 21; i++)
      for (int j = 0; j < 31; j++)
      {
         gotoxy(j + 5, i + 5);
         if (animacao2[i][j] == 0)
         {
            textcolor(AZUL);
         }
         if (animacao2[i][j] == 1)
         {
            textcolor(YELLOW);
         }
         if (animacao2[i][j] == 2)
         {
            textcolor(YELLOW);
         }
         if (animacao2[i][j] == 3)
         {
            textcolor(PRETO);
         }
         if (animacao2[i][j] == 4)
         {
            textcolor(VERMELHO);
         }
         printf("%c", 219);
      }
}
void mostranome(void)
{
   for (int i = 0; i < 9; i++)
      for (int j = 0; j < 25; j++)
      {
         gotoxy(j + 5, i + 5);
         if (matrixnome[i][j] == 0)
         {
            textcolor(PRETO);
         }
         if (matrixnome[i][j] == 1)
         {
            textcolor(VERMELHO);
         }
         printf("%c", 219);
      }
}
void mostramatrixcentena(void)
{
   for (int i = 0; i < 7; i++)
      for (int j = 0; j < 8; j++)
      {
         gotoxy(j + 5, i + 5);
         if (mtrxcentena[i][j] == 0)
         {
            textcolor(PRETO);
         }
         if (mtrxcentena[i][j] == 1)
         {
            textcolor(VERMELHO);
         }
         printf("%c", 219);
      }
}
void mostramatrixdezena(void)
{
   for (int i = 0; i < 7; i++)
      for (int j = 0; j < 8; j++)
      {
         gotoxy(j + 15, i + 5);
         if (mtrxdezena[i][j] == 0)
         {
            textcolor(PRETO);
         }
         if (mtrxdezena[i][j] == 1)
         {
            textcolor(VERMELHO);
         }
         printf("%c", 219);
      }
}
void mostramatrixunidade(void)

{
   for (int i = 0; i < 7; i++)
      for (int j = 0; j < 8; j++)
      {
         gotoxy(j + 25, i + 5);
         if (mtrxunidade[i][j] == 0)
         {
            textcolor(PRETO);
         }
         if (mtrxunidade[i][j] == 1)
         {
            textcolor(VERMELHO);
         }
         printf("%c", 219);
      }
}
void DesenhaDigitocentena(int centena)
{
   switch (centena)
   {
   case 0:
      for (int j = 0; j < 8; j++)
      {
         mtrxcentena[0][j] = 1;
         mtrxcentena[6][j] = 1;
      }
      for (int i = 0; i < 7; i++)
      {
         mtrxcentena[i][1] = 1;
         mtrxcentena[i][0] = 1;
         mtrxcentena[i][6] = 1;
         mtrxcentena[i][7] = 1;
      }
      break;
   case 1:
      for (int i = 0; i < 7; i++)
      {
         mtrxcentena[i][6] = 1;
         mtrxcentena[i][7] = 1;
      }
      break;
   case 2:
      for (int j = 0; j < 8; j++)
      {
         mtrxcentena[0][j] = 1;
         mtrxcentena[6][j] = 1;
         mtrxcentena[3][j] = 1;
      }
      mtrxcentena[1][6] = 1;
      mtrxcentena[1][7] = 1;
      mtrxcentena[2][6] = 1;
      mtrxcentena[2][7] = 1;
      mtrxcentena[5][0] = 1;
      mtrxcentena[5][1] = 1;
      mtrxcentena[4][0] = 1;
      mtrxcentena[4][1] = 1;
      break;
   case 3:
      for (int i = 0; i < 7; i++)
      {
         mtrxcentena[i][6] = 1;
         mtrxcentena[i][7] = 1;
      }
      for (int j = 0; j < 8; j++)
      {
         mtrxcentena[0][j] = 1;
         mtrxcentena[6][j] = 1;
         mtrxcentena[3][j] = 1;
      }
      break;
   case 4:
      for (int i = 0; i < 7; i++)
      {
         mtrxcentena[i][6] = 1;
         mtrxcentena[i][7] = 1;
      }
      for (int j = 0; j < 8; j++)
      {
         mtrxcentena[3][j] = 1;
      }
      mtrxcentena[0][0] = 1;
      mtrxcentena[0][1] = 1;
      mtrxcentena[1][0] = 1;
      mtrxcentena[1][1] = 1;
      mtrxcentena[2][0] = 1;
      mtrxcentena[2][1] = 1;
      break;
   case 5:
      for (int j = 0; j < 8; j++)
      {
         mtrxcentena[0][j] = 1;
         mtrxcentena[6][j] = 1;
         mtrxcentena[3][j] = 1;
      }
      mtrxcentena[1][0] = 1;
      mtrxcentena[1][1] = 1;
      mtrxcentena[2][0] = 1;
      mtrxcentena[2][1] = 1;
      mtrxcentena[5][6] = 1;
      mtrxcentena[5][7] = 1;
      mtrxcentena[4][6] = 1;
      mtrxcentena[4][7] = 1;
      break;
   case 6:
      for (int j = 0; j < 8; j++)
      {
         mtrxcentena[0][j] = 1;
         mtrxcentena[6][j] = 1;
         mtrxcentena[3][j] = 1;
      }
      for (int i = 0; i < 7; i++)
      {
         mtrxcentena[i][0] = 1;
         mtrxcentena[i][1] = 1;
      }
      mtrxcentena[5][6] = 1;
      mtrxcentena[5][7] = 1;
      mtrxcentena[4][6] = 1;
      mtrxcentena[4][7] = 1;
      break;
   case 7:
      for (int i = 0; i < 7; i++)
      {
         mtrxcentena[i][6] = 1;
         mtrxcentena[i][7] = 1;
      }
      for (int j = 0; j < 8; j++)
         mtrxcentena[0][j] = 1;
      break;
   case 8:
      for (int j = 0; j < 8; j++)
      {
         mtrxcentena[0][j] = 1;
         mtrxcentena[6][j] = 1;
         mtrxcentena[3][j] = 1;
      }
      for (int i = 0; i < 7; i++)
      {
         mtrxcentena[i][1] = 1;
         mtrxcentena[i][0] = 1;
         mtrxcentena[i][6] = 1;
         mtrxcentena[i][7] = 1;
      }
      break;
   case 9:
      for (int i = 0; i < 7; i++)
      {
         mtrxcentena[i][6] = 1;
         mtrxcentena[i][7] = 1;
      }
      for (int j = 0; j < 8; j++)
      {
         mtrxcentena[0][j] = 1;
         mtrxcentena[6][j] = 1;
         mtrxcentena[3][j] = 1;
      }
      mtrxcentena[1][0] = 1;
      mtrxcentena[2][1] = 1;
      mtrxcentena[1][1] = 1;
      mtrxcentena[2][0] = 1;
      break;
   }
}
void DesenhaDigitodezena(int dezena)
{
   switch (dezena)
   {
   case 0:
      for (int j = 0; j < 8; j++)
      {
         mtrxdezena[0][j] = 1;
         mtrxdezena[6][j] = 1;
      }
      for (int i = 0; i < 7; i++)
      {
         mtrxdezena[i][1] = 1;
         mtrxdezena[i][0] = 1;
         mtrxdezena[i][6] = 1;
         mtrxdezena[i][7] = 1;
      }
      break;
   case 1:
      for (int i = 0; i < 7; i++)
      {
         mtrxdezena[i][6] = 1;
         mtrxdezena[i][7] = 1;
      }
      break;
   case 2:
      for (int j = 0; j < 8; j++)
      {
         mtrxdezena[0][j] = 1;
         mtrxdezena[6][j] = 1;
         mtrxdezena[3][j] = 1;
      }
      mtrxdezena[1][6] = 1;
      mtrxdezena[1][7] = 1;
      mtrxdezena[2][6] = 1;
      mtrxdezena[2][7] = 1;
      mtrxdezena[5][0] = 1;
      mtrxdezena[5][1] = 1;
      mtrxdezena[4][0] = 1;
      mtrxdezena[4][1] = 1;
      break;
   case 3:
      for (int i = 0; i < 7; i++)
      {
         mtrxdezena[i][6] = 1;
         mtrxdezena[i][7] = 1;
      }
      for (int j = 0; j < 8; j++)
      {
         mtrxdezena[0][j] = 1;
         mtrxdezena[6][j] = 1;
         mtrxdezena[3][j] = 1;
      }
      break;
   case 4:
      for (int i = 0; i < 7; i++)
      {
         mtrxdezena[i][6] = 1;
         mtrxdezena[i][7] = 1;
      }
      for (int j = 0; j < 8; j++)
      {
         mtrxdezena[3][j] = 1;
      }
      mtrxdezena[0][0] = 1;
      mtrxdezena[0][1] = 1;
      mtrxdezena[1][0] = 1;
      mtrxdezena[1][1] = 1;
      mtrxdezena[2][0] = 1;
      mtrxdezena[2][1] = 1;
      break;
   case 5:
      for (int j = 0; j < 8; j++)
      {
         mtrxdezena[0][j] = 1;
         mtrxdezena[6][j] = 1;
         mtrxdezena[3][j] = 1;
      }
      mtrxdezena[1][0] = 1;
      mtrxdezena[1][1] = 1;
      mtrxdezena[2][0] = 1;
      mtrxdezena[2][1] = 1;
      mtrxdezena[5][6] = 1;
      mtrxdezena[5][7] = 1;
      mtrxdezena[4][6] = 1;
      mtrxdezena[4][7] = 1;
      break;
   case 6:
      for (int j = 0; j < 8; j++)
      {
         mtrxdezena[0][j] = 1;
         mtrxdezena[6][j] = 1;
         mtrxdezena[3][j] = 1;
      }
      for (int i = 0; i < 7; i++)
      {
         mtrxdezena[i][0] = 1;
         mtrxdezena[i][1] = 1;
      }
      mtrxdezena[5][6] = 1;
      mtrxdezena[5][7] = 1;
      mtrxdezena[4][6] = 1;
      mtrxdezena[4][7] = 1;
      break;
   case 7:
      for (int i = 0; i < 7; i++)
      {
         mtrxdezena[i][6] = 1;
         mtrxdezena[i][7] = 1;
      }
      for (int j = 0; j < 8; j++)
         mtrxdezena[0][j] = 1;
      break;
   case 8:
      for (int j = 0; j < 8; j++)
      {
         mtrxdezena[0][j] = 1;
         mtrxdezena[6][j] = 1;
         mtrxdezena[3][j] = 1;
      }
      for (int i = 0; i < 7; i++)
      {
         mtrxdezena[i][1] = 1;
         mtrxdezena[i][0] = 1;
         mtrxdezena[i][6] = 1;
         mtrxdezena[i][7] = 1;
      }
      break;
   case 9:
      for (int i = 0; i < 7; i++)
      {
         mtrxdezena[i][6] = 1;
         mtrxdezena[i][7] = 1;
      }
      for (int j = 0; j < 8; j++)
      {
         mtrxdezena[0][j] = 1;
         mtrxdezena[6][j] = 1;
         mtrxdezena[3][j] = 1;
      }
      mtrxdezena[1][0] = 1;
      mtrxdezena[2][1] = 1;
      mtrxdezena[1][1] = 1;
      mtrxdezena[2][0] = 1;
      break;
   }
}
void DesenhaDigitounidade(int unidade)
{
   switch (unidade)
   {
   case 0:
      for (int j = 0; j < 8; j++)
      {
         mtrxunidade[0][j] = 1;
         mtrxunidade[6][j] = 1;
      }
      for (int i = 0; i < 7; i++)
      {
         mtrxunidade[i][1] = 1;
         mtrxunidade[i][0] = 1;
         mtrxunidade[i][6] = 1;
         mtrxunidade[i][7] = 1;
      }
      break;
   case 1:
      for (int i = 0; i < 7; i++)
      {
         mtrxunidade[i][6] = 1;
         mtrxunidade[i][7] = 1;
      }
      break;
   case 2:
      for (int j = 0; j < 8; j++)
      {
         mtrxunidade[0][j] = 1;
         mtrxunidade[6][j] = 1;
         mtrxunidade[3][j] = 1;
      }
      mtrxunidade[1][6] = 1;
      mtrxunidade[1][7] = 1;
      mtrxunidade[2][6] = 1;
      mtrxunidade[2][7] = 1;
      mtrxunidade[5][0] = 1;
      mtrxunidade[5][1] = 1;
      mtrxunidade[4][0] = 1;
      mtrxunidade[4][1] = 1;
      break;
   case 3:
      for (int i = 0; i < 7; i++)
      {
         mtrxunidade[i][6] = 1;
         mtrxunidade[i][7] = 1;
      }
      for (int j = 0; j < 8; j++)
      {
         mtrxunidade[0][j] = 1;
         mtrxunidade[6][j] = 1;
         mtrxunidade[3][j] = 1;
      }
      break;
   case 4:
      for (int i = 0; i < 7; i++)
      {
         mtrxunidade[i][6] = 1;
         mtrxunidade[i][7] = 1;
      }
      for (int j = 0; j < 8; j++)
      {
         mtrxunidade[3][j] = 1;
      }
      mtrxunidade[0][0] = 1;
      mtrxunidade[0][1] = 1;
      mtrxunidade[1][0] = 1;
      mtrxunidade[1][1] = 1;
      mtrxunidade[2][0] = 1;
      mtrxunidade[2][1] = 1;
      break;
   case 5:
      for (int j = 0; j < 8; j++)
      {
         mtrxunidade[0][j] = 1;
         mtrxunidade[6][j] = 1;
         mtrxunidade[3][j] = 1;
      }
      mtrxunidade[1][0] = 1;
      mtrxunidade[1][1] = 1;
      mtrxunidade[2][0] = 1;
      mtrxunidade[2][1] = 1;
      mtrxunidade[5][6] = 1;
      mtrxunidade[5][7] = 1;
      mtrxunidade[4][6] = 1;
      mtrxunidade[4][7] = 1;
      break;
   case 6:
      for (int j = 0; j < 8; j++)
      {
         mtrxunidade[0][j] = 1;
         mtrxunidade[6][j] = 1;
         mtrxunidade[3][j] = 1;
      }
      for (int i = 0; i < 7; i++)
      {
         mtrxunidade[i][0] = 1;
         mtrxunidade[i][1] = 1;
      }
      mtrxunidade[5][6] = 1;
      mtrxunidade[5][7] = 1;
      mtrxunidade[4][6] = 1;
      mtrxunidade[4][7] = 1;
      break;
   case 7:
      for (int i = 0; i < 7; i++)
      {
         mtrxunidade[i][6] = 1;
         mtrxunidade[i][7] = 1;
      }
      for (int j = 0; j < 8; j++)
         mtrxunidade[0][j] = 1;
      break;
   case 8:
      for (int j = 0; j < 8; j++)
      {
         mtrxunidade[0][j] = 1;
         mtrxunidade[6][j] = 1;
         mtrxunidade[3][j] = 1;
      }
      for (int i = 0; i < 7; i++)
      {
         mtrxunidade[i][1] = 1;
         mtrxunidade[i][0] = 1;
         mtrxunidade[i][6] = 1;
         mtrxunidade[i][7] = 1;
      }
      break;
   case 9:
      for (int i = 0; i < 7; i++)
      {
         mtrxunidade[i][6] = 1;
         mtrxunidade[i][7] = 1;
      }
      for (int j = 0; j < 8; j++)
      {
         mtrxunidade[0][j] = 1;
         mtrxunidade[6][j] = 1;
         mtrxunidade[3][j] = 1;
      }
      mtrxunidade[1][0] = 1;
      mtrxunidade[2][1] = 1;
      mtrxunidade[1][1] = 1;
      mtrxunidade[2][0] = 1;
      break;
   }
}
void zeramatrizcentena(void)
{
   for (int i = 0; i < 7; i++)
      for (int j = 0; j < 8; j++)
         mtrxcentena[i][j] = 0;
}
void zeramatrizdezena(void)
{
   for (int i = 0; i < 7; i++)
      for (int j = 0; j < 8; j++)
         mtrxdezena[i][j] = 0;
}
void zeramatrizunidade(void)
{
   for (int i = 0; i < 7; i++)
      for (int j = 0; j < 8; j++)
         mtrxunidade[i][j] = 0;
}

int main()
{

   float freq = 1000;
   int num;
   int dezena;
   int centena;
   int unidade;
   int fundo;

   FILE *tempo;
   FILE *cores;

   tempo = fopen("tempos.txt", "r");
   fscanf(tempo, "%i", &num);
   mostranome();
   printf("\n\tTurma 4312//Dia XX/05");
   Sleep(1000);
   system("cls");
   if (num == 0)
   {
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEscolha o valor:\n");
      scanf("%d", &num);
   }

   fclose(tempo);
novo:
   system("cls");
   printf("Pressione 'TAB' duas vezes para inserir um novo digito// \nPressione 'p' para as funcoes de PAUSE e RESUME// \nPressione C duas vezes para encerrar o programa//\nPressione ENTER para comecar");
   centena = num / 100;
   dezena = (num - centena * 100) / 10;
   unidade = (num - centena * 100 - dezena * 10);
   int lixo = 1;

   while (num > 0)
   {

      if (kbhit()) // pause
      {
         int a = getch();
         if (a == 'p')
         {
            int b = getch();
         }
      }
      tempo = fopen("tempos.txt", "w");
      fprintf(tempo, "%d", num);
      unidade--;
      num--;
      fclose(tempo);
      if (kbhit()) // novo numero
      {
         int a = getch();
         if (a == 9)
         {
            printf("\n\n\tDigite um novo valor:\n\t");
            scanf("%d", &num);
            goto novo;
         }
         if (a == 'c')
         {
            tempo = fopen("tempos.txt", "w");
            fprintf(tempo, "101");
            fclose(tempo);
            return 0;
         }
         if (a == 'f')
         {
            int f;
            printf("\n\n\t\tEscolha a cor de Fundo\n 1 - Ciano\n 2 - Vermelho 3 - Preto");
            scanf("%c", f);
            if (f == 1)
            {
               fundo = CIANO;
            }
            if (f == 2)
            {
               fundo = VERMELHO;
            }
            if (f == 3)
            {
               fundo = PRETO;
            }
         }
      }

      zeramatrizcentena();
      zeramatrizdezena();
      zeramatrizunidade();
      DesenhaDigitocentena(centena);
      DesenhaDigitodezena(dezena);
      DesenhaDigitounidade(unidade);
      mostramatrixcentena();
      mostramatrixdezena();
      mostramatrixunidade();
      zeramatrizcentena();
      zeramatrizdezena();
      zeramatrizunidade();
      Sleep(freq);
      if (unidade == 0)
      {
         unidade = 10;
         dezena--;
      }
      if (dezena == -1)
      {
         centena--;
         dezena = 9;
      }
      if (centena == 0)
      {
         centena = 0;
      }
      if (num == 0)
      {
         tempo = fopen("tempos.txt", "w");
         fprintf(tempo, "0");
         fclose(tempo);
         system("cls");
         system("color 1F");
         mostranimacao1();
         Sleep(2000);
         system("cls");
         mostranimacao2();
         Sleep(2000);
         system("cls");
         system("color 4F");
      }
      if (lixo == 1)
      {
         getchar();
         lixo--;
      }
   }

   getch();
}
