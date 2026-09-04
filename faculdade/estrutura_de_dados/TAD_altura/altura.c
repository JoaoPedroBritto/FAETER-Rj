// Feito no codeblock's !

#include<stdio.h>
#include<stdlib.h>
#include"altura.h"

struct alt{
    int m;
    int cm;
};

tAlt* alt_cria(int m, int cm) {
    tAlt* p = (tAlt*) malloc(sizeof(tAlt));

    if (p == NULL) {
        return NULL;
    }
    if (cm >= 100) {
        m += cm / 100;
        cm = cm % 100;
    }
    // *p.cm == p->cm && *p.m == p->m
    p->m = m;
    p->cm = cm;

    return p;
}
void alt_libera(tAlt* p){
    if(p != NULL){
        free(p);
    }
}
char* alt_paraString(tAlt* p){
    if (p == NULL) {
        return NULL;
    }

    char* str = (char*) malloc(7 * sizeof(char));
    if(str){
        sprintf(str, "%d,%02d m", p->m,p->cm);
    }

    return str;
}
int alt_paraCentimetros(tAlt* p){
    if (p == NULL) {
        return 0;
    }

    return (p->m * 100) + p->cm;
}
int alt_compara(tAlt* p1, tAlt* p2){
    if (p1 == NULL || p2 == NULL){
        return 0;
    }

    int cm1 = alt_paraCentimetros(p1);
    int cm2 = alt_paraCentimetros(p2);

    return cm1 - cm2;
}
