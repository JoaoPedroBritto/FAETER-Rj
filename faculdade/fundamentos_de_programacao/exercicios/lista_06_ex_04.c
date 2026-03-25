/*
QUESTÃO 04:
Fazer uma função que, dada uma matriz Mn×n,
determine se ela é simétrica.
*/

#include <stdio.h>
int matrizSimetrica(int linha,int coluna, int mat[linha][coluna]){
    for(int i = 0; i < linha; i++){
        for(int j = i+1; j < coluna; j++){
            if(i == j){
                continue;
            }
            if(mat[i][j] != mat[j][i]){
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int mat[3][3] = {{1,2,3},{2,5,8},{3,8,4}};
    int resp;
    
    resp = matrizSimetrica(3,3,mat);
    
    printf("Resp = %d", resp);
    return 0;
}
