/*
Questão 01:
Uma loja de automóveis mantém os carros à
venda sob a forma de um vetor de structs
contendo as seguintes informações, para cada
veículo: placa, modelo, marca, cor,
quilometragem, ano modelo/fabricação (deve
ser um struct), valor e tipo (usado ou 0 km,
conforme o valor do campo quilometragem).
Pede-se a declaração de uma variável que
represente o estoque de veículos da loja,
incluindo todas as declarações de tipos que
possam ser necessárias.
Além disso, implementar as seguintes funções:

i . Exibir todos os carros do modelo m, ano de
fabricação entre a1 e a2 (inclusive), com
valor não superior a x reais;

ii . Reajustar os valores de todos os carros 0
km, considerando um aumento de p %;

iii . Retirar do estoque um determinado veículo,
dada a sua placa.
*/

#include<stdio.h>
#include<string.h>
#include <ctype.h>

typedef struct 
{
    char placa[7];
    char modelo[20];
    char marca[20];
    char cor[20];
    float quilometragem;
    int ano;
    float valor;
} carro;

void adicionar_carro(carro *l) { 
    printf("Placa: ");
    scanf(" %[^\n]s", l->placa);
    
    printf("Modelo: ");
    scanf(" %[^\n]s", l->modelo);

    printf("Marca: ");
    scanf(" %[^\n]s", l->marca);

    printf("Cor: ");
    scanf(" %[^\n]s", l->cor);

    printf("Quilometragem: ");
    scanf("%f", &l->quilometragem);

    printf("Ano: ");
    scanf("%d", &l->ano);

    printf("Valor: ");
    scanf("%f", &l->valor);
}

void modelos_carro_valor_menor_que(char *modelo, float valor, int indice, carro veiculos[]) {
    printf("\n=== RESULTADO DA BUSCA ===\n");
    for (int i = 0; i < indice; i++) {
        if ((strcmp(veiculos[i].modelo, modelo) == 0) && (veiculos[i].valor < valor)) {
            printf("Modelo: %s \nAno: %d \nValor: R$ %.2f\n", veiculos[i].modelo, veiculos[i].ano, veiculos[i].valor);
            printf("--------------------------\n");
        }
    }
}

void aumento_percentual_carros_zero(float porcentagem, int indice, carro veiculos[]){
    for (int i = 0; i < indice; i++)
    {
        if (veiculos[i].quilometragem == 0)
        {
            veiculos[i].valor += (porcentagem/100.0)* veiculos[i].valor ;  
        }
    }
    
}

void retirar_carro(char *placa,int indice, carro veiculos[]){
    // O último e o penúltimo carro ficaram repetidos.
    
    for (int i = 0; i < indice; i++)
    {
        if ((strcmp(veiculos[i].placa, placa) == 0))
        {
            for (int j = i+1; j < indice; j++)
            {
                for (int j = i; j < indice - 1; j++) {
                veiculos[j] = veiculos[j + 1]; 
            }
            }
            break;
        }
    }
}

int main()
{   
    carro veiculos[3];

    for (int i = 0; i < 3; i++)
    {
        printf("\n===== VEICULO %02d =====\n", i + 1);
        adicionar_carro(&veiculos[i]);
    }

    modelos_carro_valor_menor_que("Gol", 60000.00, 3, veiculos);

    return 0;
}
