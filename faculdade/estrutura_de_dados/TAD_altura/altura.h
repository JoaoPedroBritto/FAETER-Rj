// Feito no codeblock's !

#ifndef ALTURA_H_INCLUDED
#define ALTURA_H_INCLUDED

typedef struct altura tAltura;
tAltura* alt_cria(int m, int cm);
void alt_libera(tAltura* p);
char* alt_paraString(tAltura* p);
int alt_paraCentimetros(tAltura* p);
int alt_compara(tAltura* p1, tAltura* p2);

#endif // ALTURA_H_INCLUDED