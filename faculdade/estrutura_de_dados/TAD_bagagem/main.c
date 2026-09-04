#include <stdio.h>
#include <stdlib.h>
#include "bagagem.h"

int main() {
    /* DADOS TESTES FORNECIDOS */

    tBag* cargas[4];

    cargas[0] = bag_cria(alt_cria(0,50), alt_cria(0,40), alt_cria(0,60), mas_cria(15, 0));
    cargas[1] = bag_cria(alt_cria(1,00), alt_cria(0,80), alt_cria(1,20), mas_cria(45, 500));
    cargas[2] = bag_cria(alt_cria(0,30), alt_cria(0,30), alt_cria(0,40), mas_cria(8, 200));
    cargas[3] = bag_cria(alt_cria(0,80), alt_cria(0,60), alt_cria(0,90), mas_cria(30, 0));

    double limite_peso_kg = 80.0;
    double peso_acumulado_kg = 0.0;

    printf("=== PROCESSAMENTO DE EMBARQUE DE CARGA ===\n");

    for (int i = 0; i < 4; i++) {
        char *info = bag_paraString(cargas[i]);
        double vol = bag_calculaVolumeM3(cargas[i]);

        printf("Item %d: %s | Vol: %.3fm3\n", i + 1, info, vol);

        free(info);
        // Desalocação
        bag_libera(cargas[i]);
    }

    return 0;
}