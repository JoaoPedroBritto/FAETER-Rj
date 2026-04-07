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

void inverter_colunas(int m, int n, int matriz[m][n], int n_troca, int troca_n){
    for (int i = 0; i < m; i++)
    {
    int aux = matriz[i][n_troca];
    matriz[i][n_troca] = matriz[i][troca_n];
    matriz[i][troca_n] = aux;
    }
}

void reposicionar_ao_final(int m, int n, int matriz[m][n], int coluna_de_troca){
    int colunas_deslocadas = n- coluna_de_troca;

    for (int j = coluna_de_troca; j < (n-coluna_de_troca); j++)
    {
        inverter_colunas(m,n,matriz,coluna_de_troca,(colunas_deslocadas));
        colunas_deslocadas--;
    }
    
}

void mostrar_matriz(int m, int n, int matriz[m][n]){
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

    mostrar_matriz(5,6,matriz);
    reposicionar_ao_final(5,6,matriz,1);
    printf("\n");
    mostrar_matriz(5,6,matriz);


    return 0;
}
