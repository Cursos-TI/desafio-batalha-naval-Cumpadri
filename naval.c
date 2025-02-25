#include <stdio.h>

// Tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10

// Tamanho dos navios
#define TAMANHO_NAVIO 3

// Valor para representar água
#define AGUA 0

// Valor para representar uma parte do navio
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para posicionar um navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe no tabuleiro
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0; // Navio não cabe
    }

    // Verifica se há sobreposição com outro navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] == NAVIO) {
            return 0; // Há sobreposição
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }

    return 1; // Navio posicionado com sucesso
}

// Função para posicionar um navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe no tabuleiro
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0; // Navio não cabe
    }

    // Verifica se há sobreposição com outro navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] == NAVIO) {
            return 0; // Há sobreposição
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }

    return 1; // Navio posicionado com sucesso
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Posiciona o primeiro navio horizontalmente
    int linha1 = 2, coluna1 = 2;
    if (!posicionarNavioHorizontal(tabuleiro, linha1, coluna1)) {
        printf("Erro ao posicionar o navio horizontal.\n");
        return 1;
    }

    // Posiciona o segundo navio verticalmente
    int linha2 = 5, coluna2 = 5;
    if (!posicionarNavioVertical(tabuleiro, linha2, coluna2)) {
        printf("Erro ao posicionar o navio vertical.\n");
        return 1;
    }

    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}