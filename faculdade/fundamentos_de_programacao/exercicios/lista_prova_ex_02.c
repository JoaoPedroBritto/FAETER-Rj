/*
Desenvolver uma função que, dada uma matriz Mmxn, crie uma submatriz contendo l linhas e c colunas, a partir do
elemento que se encontra na linha i e coluna j de M.
Observação: se existirem as l linhas e as c colunas a partir do elemento mij, a operação será realizada e o valor 1
retornado; caso contrário, a função deverá retornar 0.
*/
#include<stdio.h>

int gerar_sub_matriz(int m, int n, int matriz[m][n], int qtd_linhas,int quantidade_colunas, 
    int sub_matriz[qtd_linhas][quantidade_colunas], int inicio_linha,int inicio_coluna){

        if (((qtd_linhas+inicio_linha)>m)||((quantidade_colunas+inicio_coluna)>n)){
            return 0;
        }
        else{
            int i,j;
            int aux_i = 0, aux_j;

            for (i = inicio_linha; aux_i < qtd_linhas; aux_i++, i++)
            {
                aux_j = 0;
                for (j = inicio_coluna; aux_j < quantidade_colunas; aux_j++, j++)
                {
                    sub_matriz[aux_i][aux_j] = matriz[i][j];
                }
            }
            return 1;
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
    int matriz[6][8] = {
        {5, 7, 0, 4, 1, 0, 8, 9},
        {5, 7, 5, 3, 2, 6, 8, 5},
        {4, 3, 2, 9, 0, 8, 0, 9},
        {6, 5, 1, 8, 7, 3, 8, 5},
        {4, 8, 0, 7, 4, 2, 0, 9},
        {8, 4, 7, 9, 4, 8, 7, 1}
    };
    int sub_matriz[3][5];
    int resposta;

    resposta = gerar_sub_matriz(6,8,matriz,3,5,sub_matriz,2,1);
    printf("--> resposta = %d\n",resposta);
    mostrar_matriz(3,5,sub_matriz);

    return 0;
}
