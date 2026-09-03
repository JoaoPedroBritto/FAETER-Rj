// Feito no codeblock's

#ifndef MASSA_H_INCLUDED
#define MASSA_H_INCLUDED

typedef struct mas tMas;
tMas* mas_cria(int kg, int g);
void mas_libera(tMas* p);
char* mas_paraString (tMas* p);
int mas_paraGramas (tMas* p);
tMas* mas_soma(tMas* p1, tMas* p2);

#endif // MASSA_H_INCLUDED