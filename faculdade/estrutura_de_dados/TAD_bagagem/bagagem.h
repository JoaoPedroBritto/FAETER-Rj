#ifndef BAGAGEM_H_INCLUDED
#define BAGAGEM_H_INCLUDED

#include "../TAD_altura/altura.h"
#include "../TAD_massa/massa.h"

typedef struct bag tBag;
tBag* bag_cria(tAlt* altura, tAlt* comprimento, tAlt* largura, tMas* massa);
char* bag_paraString(tBag* p);
double bag_calculaVolumeM3(tBag* p);
void bag_libera(tBag* p);

#endif // BAGAGEM_H_INCLUDED