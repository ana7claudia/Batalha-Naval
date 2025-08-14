#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5 // Usaremos 5x5 para as habilidades

// Função para inicializar uma matriz de habilidade como 0
void inicializarMatriz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            matriz[i][j] = 0;
        }
    }
}

// Função para criar a matriz de habilidade Cone
void criarCone(int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    inicializarMatriz(cone);
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= (TAMANHO_HABILIDADE/2) - i && j <= (TAMANHO_HABILIDADE/2) + i) {
                cone[i][j] = 1;
            }
        }
    }
}

// Função para criar a matriz de habilidade Cruz
void criarCruz(int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    inicializarMatriz(cruz);
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            }
        }
    }
}

// Função para criar a matriz de habilidade Octaedro
void criarOctaedro(int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    inicializarMatriz(octaedro);
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs (centro - i) + abs(centro - j) <= centro) {
                octaedro[i][j] = 1;
            }
        }
    }
}

// Função para aplicar uma habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origemLinha, int origemColuna) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTabuleiro = origemLinha + (i - centro);
            int colunaTabuleiro = origemColuna + (j - centro);

            // Verifica se está dentro dos limites do tabuleiro
            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== TABULEIRO ===\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(". "); // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("N "); // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("* "); // Área de habilidade
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posicionar navios (igual feito antes)
    tabuleiro[1][2] = tabuleiro[1][3] = tabuleiro[1][4] = 3; // Horizontal
    tabuleiro[5][7] = tabuleiro[6][7] = tabuleiro[7][7] = 3; // Vertical
    tabuleiro[0][0] = tabuleiro[1][1] = tabuleiro[2][2] = 3; // Diagonal principal
    tabuleiro[7][2] = tabuleiro[6][3] = tabuleiro[5][4] = 3; // Diagonal secundária

    // Matrizes das habilidades
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Criar as habilidades
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplicar habilidades no tabuleiro (pontos de origem escolhidos manualmente)
    aplicarHabilidade(tabuleiro, cone, 3, 3);
    aplicarHabilidade(tabuleiro, cruz, 6, 6);
    aplicarHabilidade(tabuleiro, octaedro, 8, 2);

    // Imprimir o tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}