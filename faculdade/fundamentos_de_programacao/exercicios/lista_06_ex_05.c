/*
QUESTÃO 05:
Implementar uma função que, dada uma matriz
Mm×n, gere um vetor V de tamanho n, onde
cada elemento do vetor consiste na soma dos
elementos de uma coluna de M. Ou seja, o
elemento V[0] consiste na soma dos elementos
da primeira coluna de M, o elemento V[1]
consiste na soma dos elementos da segunda
coluna de M, e assim por diante.
*/

#include <stdio.h>
void somaColunas(int linha, int coluna, int matriz[linha][coluna], int vetor[coluna]){
    for(int j = 0; j < coluna; j++){
        for(int i = 0; i < linha; i++ ){
            vetor[j] += matriz[i][j]; 
        }
    }
}
int main()
{
    int matriz[3][3] = {{1,2,3},
                        {4,0,1},
                        {1,0,0}};
    int vetor[3] = {0,0,0};
    
    somaColunas(3,3,matriz,vetor);
    
    for(int i=0; i<3;i++){
        printf(" %d \n ", vetor[i]);
    }

    return 0;
}
