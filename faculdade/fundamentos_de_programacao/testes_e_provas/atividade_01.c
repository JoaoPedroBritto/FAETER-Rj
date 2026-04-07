/*Desenvolver uma função que, dada uma string
str, substitua uma substring s1 de str (definida
pelas posições inicial e final) por outra string,
s2.*/

#include<stdio.h>
#include<string.h>

void substituir_string(int inicio, int final, int tamanho_total, char string_principal[], char string_substitutiva[]){
    int len_principal = strlen(string_principal);
    int len_substitutiva = strlen(string_substitutiva);
    int novas_casas = len_substitutiva - ((final - inicio) + 1);
    int s = 0;

    for (int i = 0; i < tamanho_total; i++)
    {
        if (i == inicio)
        {   
            for (int j = 0; j < len_principal-final; j++)
            {
                // Vai pegar o último char ocupado da string principal e colocar no novo lugar ex:. 14 recebe 12, 13 recebe 11, 12 recebe 10...
                string_principal[(len_principal+novas_casas)-j] =
                string_principal[len_principal-j];
            }
            
        }   
        while ((i >= inicio)&&(i <= final+novas_casas))
        {
            string_principal[i] = string_substitutiva[s];
            s++;
            i++;
        }
        if (s == len_substitutiva)
        {
            break;
        }    
    }
}

int main()
{
    char string_principal[30] = {"e ai, vc vem?"};
    char string_substitutiva[30] = {"vossa merce"};

    printf("%s\n", string_principal);
    substituir_string(6,7,30,string_principal,string_substitutiva);
    printf("%s\n", string_principal);

    return 0;
}
