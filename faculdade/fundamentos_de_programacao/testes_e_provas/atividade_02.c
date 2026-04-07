/*
Dadas uma matriz Mmxn e uma coluna col,
desenvolver uma função que desloque todos os
elementos da coluna col para a última coluna
da matriz.
Consequentemente, as colunas col+1 à última
deverão serão deslocadas uma posição para a
esquerda, conforme ilustrado no exemplo
abaixo:
*/

#include <stdio.h>

void reposicionar_ao_final(int m, int n, int matriz[m][n], int coluna_de_troca){
    int coluna_aux[m][1];

    // copia a coluna de troca e manda todo mundo pra esquerda
    for (int j = coluna_de_troca; j < n; j++)
    {  
        for (int i = 0; i < m; i++)
        {
            if (j == coluna_de_troca)
            {
                coluna_aux[i][0] = matriz[i][j];
            }
            else
            {
                matriz[i][j-1] = matriz[i][j];
            }   
        }
    }
    // adiciona a coluna auxiliar na última posição
    for (int i = 0; i < m; i++)
    {
        matriz[i][n-1] = coluna_aux[i][0];
    }
}

void mostrarMatriz(int m, int n, int matriz[m][n]){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" (%2d) ",matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int matriz[5][6] = {
        {1, 5, 7, 1, 4, 6},
        {6, 2, 1, 4, 7, 7},
        {3, 6, 9, 7, 0, 1},
        {2, 4, 5, 7, 2, 4},
        {2, 4, 8, 9, 1, 2}
    };

    mostrarMatriz(5,6,matriz);
    reposicionar_ao_final(5,6,matriz,1);
    printf("\n");
    mostrarMatriz(5,6,matriz);


    return 0;
}
