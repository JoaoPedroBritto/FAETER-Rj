#include<stdio.h>
#include<stdlib.h>

void colunas_simetricas(int m, int n, int matriz[m][n]){
    int i,j;
    int simetrico = 1;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n/2; j++)
        {
            if (matriz[i][j] != matriz[i][n-1-j])
            {
                simetrico = 0;
                break;
            }
        }
        if (simetrico == 0)
        {
            break;
        }
    }
    if (simetrico == 0)
    {
        printf("Nao E simetrico por coluna.\n");
    }
    else{
        printf("E simetrico por coluna.\n");
    }
}

int main()
{
    int matriz_A[4][4]={{1,2,2,1},
                        {2,2,2,2},
                        {3,2,2,3},
                        {4,2,2,4}};
    
    int matriz_B[4][4]={{1,2,3,4},
                        {1,2,3,4},
                        {1,2,3,4},
                        {1,2,3,4}};

    int matriz_C[4][5]={{1,2,3,2,1},
                        {1,2,3,2,1},
                        {7,2,3,2,7},
                        {1,2,3,2,1}};

    int matriz_D[4][5]={{1,2,3,7,1},
                        {1,2,3,7,1},
                        {1,2,3,7,1},
                        {1,2,3,7,1}};

    colunas_simetricas(4,4,matriz_A);
    colunas_simetricas(4,4,matriz_B);
    colunas_simetricas(4,5,matriz_C);
    colunas_simetricas(4,5,matriz_D);
    return 0;
}
