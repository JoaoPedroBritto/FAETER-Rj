#include<stdio.h>
#include<string.h>

int arquivo_inteiro_ordenado(char nome_arquivo[]){
    FILE *arq;
    int anterior; // maior_anterior
    int numero;

    arq = fopen(nome_arquivo, "r");

    if (!arq)
    {
        fclose(arq);
        return -1;
    }
    else
    {
        //lendo o primeiro número do arquivo, caso não esteja não vazio
        //só de ler a condição já ira fazer a atribuição, por isso não dá ruim depois
        if (fscanf(arq, "%d", & anterior) == EOF)
        {
            fclose(arq);

            return 1;
        }

        while (fscanf(arq, "%d", & numero) != EOF)
        {
            if (numero < anterior)
            {
                fclose(arq);
                return 0;
            }
            else
            {
                anterior = numero; 
            }
        }
        fclose(arq);
        return 1;
    }
    
}

int main()
{
    char nome_arquivo[20];
    int resultado;

    printf("Informe o nome do arquivo: ");
    gets(nome_arquivo);

    resultado = arquivo_inteiro_ordenado(nome_arquivo);

    printf("Resultado: %d \n", resultado);

    return 0;
}
