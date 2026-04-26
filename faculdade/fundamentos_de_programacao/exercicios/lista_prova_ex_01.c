/*
Desenvolver uma função que, dado um e-mail no formato usuario@xxxxxxx.yyy.zz, valide-o.
Para o e-mail ser válido, as seguintes regras devem ser atendidas:
1. A parte usuario pode conter letras e algarismos. Pode também possuir símbolos (. ou _ ou -), desde que
não estejam na primeira ou na última posição desta parte;
2. A seção xxxxxxx possui apenas letras (de 5 a 15 letras), e é proibido ter a mesma letra em posições
consecutivas;
3. yyy pode assumir apenas os valores com, edu ou org;
4. A parte zz não é obrigatória. Caso exista, deve ser br.
*/

#include <stdio.h>
#include <string.h>
int validar_email(char vetor[]){ 
    // VALIDANDO USUARIO
    int i;

    if ((vetor[0] == '_') || (vetor[0] == '.') || (vetor[0] == '-')){
        return 0;
    }
    for (i = 0; vetor[i] != '@' ; i++){
        if (!((vetor[i] >= 'A' && vetor[i] <= 'Z') || 
              (vetor[i] >= 'a' && vetor[i] <= 'z') || 
              (vetor[i] >= '0' && vetor[i] <= '9') ||
              (vetor[i] == '_') || (vetor[i] == '.') || (vetor[i] == '-'))) {
                return 0; 
            }
    }
    if ((vetor[i-1] == '_') || (vetor[i-1] == '.') || (vetor[i-1] == '-')){
        return 0;
    }

    // VALIDANDO SECAO XXXXXXX
    i ++;
    int aux = 0;

    for ( ; vetor[i] != '.'; aux++, i++){
        if (aux >= 15){
            return 0;
        }
        else{
            if (!((vetor[i] >= 'A' && vetor[i] <= 'Z') || 
              (vetor[i] >= 'a' && vetor[i] <= 'z'))){
                return 0;
            }
            if(vetor[i] == vetor[i+1]){
                return 0;
            }
        }
    }
    if (aux < 5){
        return 0;
    }
    
    // VALIDANDO YYY
    i ++;
    aux = 0;
    char vetor_aux[4]; 

    for ( ; (vetor[i] != '.') && (vetor[i] != '\0'); aux++, i++){
        if (aux > 3){
            return 0;
        }
        vetor_aux[aux] = vetor[i];
    }
    vetor_aux[aux] = '\0';
    if ((strcmp(vetor_aux,"edu") != 0) && (strcmp(vetor_aux,"com") != 0) && (strcmp(vetor_aux,"org") != 0)){
        return 0; 
    }

    // VALIDANDO ZZ
    i ++;
    aux = 0;
    
    for ( ; vetor[i] != '\0' ; aux++, i++){
        if (aux > 2){
            return 0;
        }
        vetor_aux[aux] = vetor[i];
    }
    if (strncmp(vetor_aux,"br",2) != 0){
        return 0;
    }

    return 1;
}

int main()
{
    char email_valido[] = "joao_p.12@gmail.com.br";
    char email_invalido[] = ".ana_@goolgle.net.us";
    char email_teste_01[] = "usuario@xxxxxxx.org.br";
    char email_teste_02[] = "usuario@abcde.org.br";
    int resposta_01 = -1;
    int resposta_02 = -1;
    int resposta_03 = -1;
    int resposta_04 = -1;

    resposta_01 = validar_email(email_valido);
    resposta_02 = validar_email(email_invalido);
    resposta_03 = validar_email(email_teste_01);
    resposta_04 = validar_email(email_teste_02);

    printf("--> resposta 01: %d \n--> resposta 02: %d \n--> resposta 03: %d \n--> resposta 04: %d \n", 
        resposta_01, resposta_02, resposta_03, resposta_04);

    return 0;
}