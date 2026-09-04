#include<stdio.h>
#include<stdlib.h>
#include "../TAD_altura/altura.h"
#include "../TAD_massa/massa.h"
#include"bagagem.h"

struct bag{
    tAlt* altura;
    tAlt* comprimento;
    tAlt* largura;
    tMas* massa;
};
tBag* bag_cria(tAlt* altura, tAlt* comprimento, tAlt* largura, tMas* massa){
    if ((altura == NULL) || (comprimento == NULL) || (largura == NULL) || (massa == NULL)){
        return NULL;
    }

    tBag* p = (tBag*) malloc(sizeof(tBag));

    if (p == NULL){
        return NULL;
    }

    p->altura = altura;
    p->comprimento = comprimento;
    p->largura = largura;
    p->massa = massa;

    return p;
}
char* bag_paraString(tBag* p){
    if (p == NULL){
        return NULL;
    }

    char* str = (char*) malloc(128 * sizeof(char));

    if (str == NULL){
        return NULL;
    }

    sprintf(str, "Altura: %d cm | Comprimento: %d cm | Largura: %d cm | Massa: %d g",
     alt_paraCentimetros(p->altura), alt_paraCentimetros(p->comprimento), alt_paraCentimetros(p->largura), mas_paraGramas(p->massa));

    return str;
}
double bag_calculaVolumeM3(tBag* p){
    if (p == NULL){
        return 0.0;
    }

    return (((alt_paraCentimetros(p->altura))*(alt_paraCentimetros(p->comprimento))*(alt_paraCentimetros(p->largura))) / 1000000.0);
}
void bag_libera(tBag* p){
    if (p != NULL){

        alt_libera(p->altura);
        alt_libera(p->comprimento);
        alt_libera(p->largura);
        mas_libera(p->massa);

        free(p);
    }
}