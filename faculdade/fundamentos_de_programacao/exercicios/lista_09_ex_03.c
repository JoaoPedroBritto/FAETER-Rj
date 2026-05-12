/*
Questão 03:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de letras existentes
no mesmo (entendendo que no arquivo podem
existir letras, algarismos e símbolos).
*/

#include<stdio.h>
#include<string.h>

int quantidade_letras(char nome_arquivo[]){
    FILE *arq;
    char ch;
    int quantidade = 0;

    arq = fopen(nome_arquivo, "r");

    if (!arq)
    {
        fclose(arq);
        return -1;
    }
    else
    {
        while (fscanf(arq, "%c", &ch) != EOF)
        {
            ch = toupper(ch);
            if (ch >= 'A' && ch <= 'Z')
            {
                quantidade++;
            }
            
        }
        fclose(arq);
        return quantidade;
    }

}

int main()
{
    char nome_arquivo[20];
    int quantidade;

    printf("Informe o nome do arquivo: ");
    gets(nome_arquivo);

    quantidade = quantidade_letras(nome_arquivo);

    printf("A quantidade de letras é %d \n", quantidade);

    return 0;
}
