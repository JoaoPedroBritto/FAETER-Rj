/*
Questão 02:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de vezes que um
determinado caracter aparece no arquivo.
*/

#include<stdio.h>
#include<string.h>

int ocorrencia_caracter(char nome_arquivo[], char caracter){
    FILE *arq;
    char ch;
    int contador;

    arq = fopen(nome_arquivo,"r");

    if (!arq)
    {
        fclose(nome_arquivo);
        return -1;
    }
    else
    {
        while (fscanf(arq,"%c", &ch) != EOF)
        {
            if (ch == caracter)
            {
                contador++;
            }
            
        }
        fclose(arq);
        return contador;
    }
    
}

int main()
{
    char nome_arquivo[20];
    int quantidade;
    int caracter;

    printf("Informe o nome do arquivo: ");
    gets(nome_arquivo);
    printf("Informe o caracter a ser buscado: ");
    scanf("%c", &caracter);

    quantidade = ocorrencia_caracter(nome_arquivo, caracter);
    printf("Quantidade de ocorrencias: %d\n", quantidade);

    return 0;
}
