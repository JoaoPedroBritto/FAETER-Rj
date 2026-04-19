/*
Desenvolver uma função que, dada uma string
s, retorne um vetor de structs que armazene,
em cada uma de suas posições, um caracter
distinto de s e a quantidade de ocorrências
deste caracter na string.
Observações:
1. Ao incluir um novo caracter no vetor de
structs, deve-se buscar a posição apropriada,
de forma que o vetor fique ordenado
crescentemente em função dos caracteres;
2. Pelo que foi descrito no enunciado,
repetições de caracteres não são permitidas
no vetor.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALFABETO 128 

typedef struct {
    char character;
    int frequencia;
} Tcontador;

void frequencia_character(char* s, Tcontador ocorrencia[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        int indice = tolower(s[i]);
        
        if (ocorrencia[indice].character == '\0') {
            ocorrencia[indice].character = indice; 
        }
        
        ocorrencia[indice].frequencia += 1;
    }
}   

void mostrar_frequencia_character(Tcontador ocorrencia[]) {
    for (int i = 0; i < ALFABETO; i++) {
        if (ocorrencia[i].character != '\0') {
            printf("Caracter: '%c' | Frequencia: %d\n", ocorrencia[i].character, ocorrencia[i].frequencia);
        }
    }
}

int main() {
    Tcontador ocorrencia[ALFABETO] = {0};
    char string[] = "Testando um dois, um dois, som, som, zZzZzz"; 

    frequencia_character(string, ocorrencia);
    mostrar_frequencia_character(ocorrencia);
    
    return 0;
}