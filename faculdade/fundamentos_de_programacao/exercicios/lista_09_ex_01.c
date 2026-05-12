/*
Questão 01:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de caracteres no
mesmo.
*/

#include<stdio.h>

int quantidade_caracteres(char nome_arquivo[]){
    FILE *arq;
    int contador = 0;
    char caracter;

    arq = fopen(nome_arquivo, "r");  // read
    
    //if (arq == NULL)
    if (!arq)
    {
        fclose(arq);
        return -1;
    }
    else
    {
        while (fscanf(arq, "%c", &caracter) != EOF) 
        {
            contador ++;
        }
        fclose(arq);
        return contador;
    }

}

int main()
{
	char nome_arquivo[20];
	int quantidade;
	
	printf("Nome do arquivo: ");
	gets(nome_arquivo);
	
	quantidade = quantidade_caracteres(nome_arquivo);
    printf ("\n\nForam encontrados %d caracteres no arquivo %s.\n", quantidade, nome_arquivo);

    return 0;
}
