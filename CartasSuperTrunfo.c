#include <stdio.h>

typedef struct {
    char estado;
    int codigo;
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
    float super_poder;
} Carta;

void cadastrar_carta(Carta *carta) {
    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);
    printf("Código da cidade (ex: 1): ");
    scanf("%d", &carta->codigo);
    printf("População: ");
    scanf("%lu", &carta->populacao);
    printf("Área: ");
    scanf("%f", &carta->area);
    printf("PIB: ");
    scanf("%f", &carta->pib);
    printf("Pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);

    // Cálculos adicionais
    carta->densidade = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
    carta->super_poder = carta->populacao + carta->area + carta->pib +
                         carta->pontos_turisticos + carta->pib_per_capita +
                         (1 / carta->densidade);
}

void exibir_carta(Carta carta) {
    printf("\nCarta %c%02d:\n", carta.estado, carta.codigo);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade populacional: %.2f\n", carta.densidade);
    printf("PIB per capita: %.2f\n", carta.pib_per_capita);
    printf("Super Poder: %.2f\n", carta.super_poder);
}

void comparar_cartas(Carta c1, Carta c2) {
    printf("\nComparação entre as cartas:\n");

    printf("População: Carta %d vence\n", (c1.populacao > c2.populacao) ? 1 : 2);
    printf("Área: Carta %d vence\n", (c1.area > c2.area) ? 1 : 2);
    printf("PIB: Carta %d vence\n", (c1.pib > c2.pib) ? 1 : 2);
    printf("Pontos turísticos: Carta %d vence\n", (c1.pontos_turisticos > c2.pontos_turisticos) ? 1 : 2);
    printf("Densidade populacional: Carta %d vence\n", (c1.densidade < c2.densidade) ? 1 : 2);
    printf("PIB per capita: Carta %d vence\n", (c1.pib_per_capita > c2.pib_per_capita) ? 1 : 2);
    printf("Super Poder: Carta %d vence\n", (c1.super_poder > c2.super_poder) ? 1 : 2);
}

int main() {
    Carta carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    cadastrar_carta(&carta1);

    printf("\nCadastro da Carta 2:\n");
    cadastrar_carta(&carta2);

    printf("\nExibindo Cartas:\n");
    exibir_carta(carta1);
    exibir_carta(carta2);

    comparar_cartas(carta1, carta2);

    return 0;
}
