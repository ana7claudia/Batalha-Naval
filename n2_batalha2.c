#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração do tabuleiro: inicializado todo com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios
    int linhaH = 1, colunaH = 2;  // Navio horizontal
    int linhaV = 5, colunaV = 7;  // Navio vertical
    int linhaD1 = 0, colunaD1 = 0; // Navio diagonal principal (de cima à direita)
    int linhaD2 = 7, colunaD2 = 2; // Navio diagonal secundária (de baixo à direita)

    int sobreposicao = 0; // Variável para marcar se houve sobreposição

    // Posicionando Navio Horizontal
    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] == 0) {
                tabuleiro[linhaH][colunaH + i] = 3;
            } else {
                sobreposicao = 1;
                printf("Erro: Sobreposição detectada no navio horizontal!\n");
                break;
            }
        }
    } else {
        printf("Erro: Navio horizontal não cabe no tabuleiro!\n");
    }

    // Posicionando Navio Vertical
    if (linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] == 0) {
                tabuleiro[linhaV + i][colunaV] = 3;
            } else {
                sobreposicao = 1;
                printf("Erro: Sobreposição detectada no navio vertical!\n");
                break;
            }
        }
    } else {
        printf("Erro: Navio vertical não cabe no tabuleiro!\n");
    }

    // Posicionando Navio Diagonal Principal (↘)
    if (linhaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] == 0) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
            } else {
                sobreposicao = 1;
                printf("Erro: Sobreposição detectada no navio diagonal principal!\n");
                break;
            }
        }
    } else {
        printf("Erro: Navio diagonal principal não cabe no tabuleiro!\n");
    }

    // Posicionando Navio Diagonal Secundária (↗)
    if (linhaD2 - (TAMANHO_NAVIO - 1) >= 0 && colunaD2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaD2 - i][colunaD2 + i] == 0) {
                tabuleiro[linhaD2 - i][colunaD2 + i] = 3;
            } else {
                sobreposicao = 1;
                printf("Erro: Sobreposição detectada no navio diagonal secundária!\n");
                break;
            }
        }
    } else {
        printf("Erro: Navio diagonal secundária não cabe no tabuleiro!\n");
    }

    // Exibindo o tabuleiro final
    printf("\n=== TABULEIRO ===\n\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}