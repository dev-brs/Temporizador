#include <iostream>
#include "mat.h"
estruturaDefault concatenarMatrizes(const std::vector<estruturaDefault>& matrizes) {
    estruturaDefault resultado;

    // Verificar se há pelo menos uma matriz para concatenar
    if (matrizes.empty()) {
        std::cerr << "Erro: Nenhuma matriz fornecida para concatenar." << std::endl;
        return resultado;  // Retornar matriz vazia em caso de erro
    }

    // Verificar se todas as matrizes têm o mesmo número de linhas
    int linhas = matrizes[0].linhas;
    for (const auto& matriz : matrizes) {
        if (matriz.linhas != linhas) {
            std::cerr << "Erro: As matrizes precisam ter o mesmo número de linhas para concatenação." << std::endl;
            return resultado;  // Retornar matriz vazia em caso de erro
        }
    }

    // Definir as dimensões da matriz resultado
    resultado.linhas = linhas;
    resultado.colunas = 0;

    // Calcular o número total de colunas na matriz resultado
    for (const auto& matriz : matrizes) {
        resultado.colunas += matriz.colunas;
    }

    // Concatenar as matrizes
    for (int i = 0; i < resultado.linhas; ++i) {
        for (const auto& matriz : matrizes) {
            for (int j = 0; j < matriz.colunas; ++j) {
                resultado.matriz.push_back(matriz.matriz[i * matriz.colunas + j]);
            }
        }
    }

    return resultado;
}
