#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *esquerda, *direita;
} No;
typedef struct arv
{
    No *raiz;
} Arv;
No *criaNo(int valor);
void inserirEsquerda(No *no, int valor);
void inserirDireita(No *no, int valor);
void inserir(Arv *arv, int valor);
void imprimir(No *raiz);
int buscar(No *raiz, int chave);

int main()
{
    Arv arvore;
    arvore.raiz = NULL;

    inserir(&arvore, 50);
    inserir(&arvore, 30);
    inserir(&arvore, 70);
    inserir(&arvore, 20);
    inserir(&arvore, 40);
    inserir(&arvore, 60);
    inserir(&arvore, 80);

    printf("Valores da arvore em ordem crescente: ");
    imprimir(arvore.raiz);
    printf("\n");

    int valorBuscado = 40;
    int resultado = buscar(arvore.raiz, valorBuscado);

    if (resultado != -1)
    {
        printf("Valor %d encontrado na arvore!\n", resultado);
    }
    else
    {
        printf("Valor %d nao existe na arvore.\n", valorBuscado);
    }

    return 0;
}

No *criaNo(int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

void inserirEsquerda(No *no, int valor)
{
    if (no->esquerda == NULL)
    {
        no->esquerda = criaNo(valor);
    }
    else
    {
        if (valor < no->esquerda->valor)
        {
            inserirEsquerda(no->esquerda, valor);
        }
        else
        {
            inserirDireita(no->esquerda, valor);
        }
    }
}

void inserirDireita(No *no, int valor)
{
    if (no->direita == NULL)
    {
        no->direita = criaNo(valor);
    }
    else
    {
        if (valor > no->direita->valor)
        {
            inserirDireita(no->direita, valor);
        }
        else
        {
            inserirEsquerda(no->direita, valor);
        }
    }
}

void inserir(Arv *arv, int valor)
{
    if (arv->raiz == NULL)
    {
        arv->raiz = criaNo(valor);
    }
    else
    {
        if (valor < arv->raiz->valor)
        {
            inserirEsquerda(arv->raiz, valor);
        }
        else
        {
            inserirDireita(arv->raiz, valor);
        }
    }
}

void imprimir(No *raiz)
{
    if (raiz != NULL)
    {
        imprimir(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir(raiz->direita);
    }
}

int buscar(No *raiz, int chave)
{
    if (raiz == NULL)
    {
        return -1;
    }
    else
    {
        if (raiz->valor == chave)
        {
            return raiz->valor;
        }
        else
        {
            if (raiz->valor < chave)
            {
                return buscar(raiz->direita, chave);
            }
            else
            {
                return buscar(raiz->esquerda, chave);
            }
        }
    }
}
