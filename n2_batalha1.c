#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração do tabuleiro: inicializado todo com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Declaração dos navios: vetores de tamanho 3
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais dos navios
    int linhaHorizontal = 2, colunaHorizontal = 4; // Navio na linha 2, coluna 4 (horizontal)
    int linhaVertical = 5, colunaVertical = 7;      // Navio na linha 5, coluna 7 (vertical)

    // Validando se o navio horizontal cabe no tabuleiro
    if (colunaHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro: Navio horizontal não cabe no tabuleiro!\n");
    }

    // Validando se o navio vertical cabe no tabuleiro
    if (linhaVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se já tem navio na posição (evita sobreposição)
            if (tabuleiro[linhaVertical + i][colunaVertical] == 0) {
                tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
            } else {
                printf("Erro: Sobreposição de navios detectada na posição (%d, %d)\n", linhaVertical + i, colunaVertical);
            }
        }
    } else {
        printf("Erro: Navio vertical não cabe no tabuleiro!\n");
    }

    // Exibindo o tabuleiro
    printf("\n=== TABULEIRO ===\n\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n"); // Nova linha a cada linha do tabuleiro
    }

    return 0;
}
