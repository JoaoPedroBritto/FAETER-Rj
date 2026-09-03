// Feito no codeblock's

#include<stdio.h>
#include"massa.h"
#include<stdlib.h>

struct mas {
    int kg;
    int g;
};
tMas* mas_cria(int kg, int g){
    tMas* p = (tMas*) malloc(sizeof(tMas));

    if(p == NULL){
        return NULL;
    }
    if (g >= 1000){
        kg += g / 1000;
        g = g % 1000;
    }

    p->kg = kg;
    p->g = g;
    return p;
}
void mas_libera(tMas* p){
    if (p != NULL) {
        free(p);
    }
}
char* mas_paraString (tMas* p) {
    if(p == NULL){
        return NULL;
    }

    char* str = (char*) malloc(15 * sizeof(char));

    if(str == NULL){
        return NULL;
    }

    sprintf(str, "%d,%03d kg", p->kg, p->g);

    return str;
}
int mas_paraGramas (tMas* p){
    if(p == NULL){
        return NULL;
    }

    return (p->kg * 1000) + p->g;
}
tMas* mas_soma(tMas* p1, tMas* p2){
    if(p1 == NULL || p2 == NULL){
        return NULL;
    }

    int p1_g = mas_paraGramas(p1);
    int p2_g = mas_paraGramas(p2);
    int soma_g = p1_g + p2_g;

    tMas* p3 = mas_cria(0,soma_g);

    return p3;
}