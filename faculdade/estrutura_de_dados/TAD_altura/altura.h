// Feito no codeblock's !

#ifndef ALTURA_H_INCLUDED
#define ALTURA_H_INCLUDED

typedef struct alt tAlt;
tAlt* alt_cria(int m, int cm);
void alt_libera(tAlt* p);
char* alt_paraString(tAlt* p);
int alt_paraCentimetros(tAlt* p);
int alt_compara(tAlt* p1, tAlt* p2);

#endif // ALTURA_H_INCLUDED