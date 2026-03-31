/*
Questão 02:
Implementar uma função que, dadas uma matriz M de inteiros (com lin linhas e col colunas) e duas colunas c1 e c2, inverta
a ordem (por linha) dos elementos compreendidos entre estas colunas.
*/

#include<stdio.h>
#include<stdlib.h>

void inverter_colunas(int i, int j, int matriz[i][j], int j_troca, int troca_j){
    j_troca--;
    troca_j--;
    for (int m = 0; m < i; m++)
    {
    int aux = matriz[m][j_troca];
    matriz[m][j_troca] = matriz[m][troca_j];
    matriz[m][troca_j] = aux;
    }
}
void mostrarMatriz(int i, int j, int matriz[i][j]){
    for (int m = 0; m < i; m++)
    {
        for (int n = 0; n < j; n++)
        {
            printf(" (%2d) ",matriz[m][n]);
        }
        printf("\n");
    }
}
void preencherElementosRand(int i, int j, int matriz[i][j]){
    srand(time(NULL));
    for (int m = 0; m < i; m++)
    {
        for (int n = 0; n < j; n++)
        {
            matriz[m][n] = rand()%11;        
        }
    }
}
int main()
{
    int i = 2;
    int j = 5; 
    int matriz[i][j];

    preencherElementosRand(i,j,matriz);
    mostrarMatriz(i,j,matriz);
    printf("=============================\n");
    inverter_colunas(i,j,matriz,1,5);
    mostrarMatriz(i,j,matriz);

    return 0;
}
