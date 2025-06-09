#include <stdio.h>

// Constantes para facilitar manutenção e evitar repetição
#define BISPO_CASAS 5
#define TORRE_CASAS 5
#define RAINHA_CASAS 8

// Função recursiva para movimentação do Bispo com loops aninhados
void movimentar_bispo_recursivo(int casa_atual, int max_casas) {
    if(casa_atual > max_casas) {
        return;
    }
    
    // Loop aninhado para demonstrar movimento diagonal
    for(int direcao = 1; direcao <= 2; direcao++) {
        for(int passo = 1; passo <= 1; passo++) {
            if(direcao == 1) {
                printf("Casa %d: Cima", casa_atual);
            } else {
                printf("Direita\n");
            }
        }
    }
    
    movimentar_bispo_recursivo(casa_atual + 1, max_casas);
}

void movimentar_bispo() {
    printf("1. BISPO - Movimentacao diagonal superior direita (%d casas):\n", BISPO_CASAS);
    printf("Iniciando movimentacao...\n");
    
    movimentar_bispo_recursivo(1, BISPO_CASAS);
    printf("Bispo finalizou movimentacao!\n\n");
}

// Função recursiva para movimentação da Torre
void movimentar_torre_recursivo(int casa_atual, int max_casas) {
    if(casa_atual > max_casas) {
        return;
    }
    
    printf("Casa %d: Direita\n", casa_atual);
    movimentar_torre_recursivo(casa_atual + 1, max_casas);
}

void movimentar_torre() {
    printf("2. TORRE - Movimentacao para direita (%d casas):\n", TORRE_CASAS);
    printf("Iniciando movimentacao...\n");
    
    movimentar_torre_recursivo(1, TORRE_CASAS);
    printf("Torre finalizou movimentacao!\n\n");
}

// Função recursiva para movimentação da Rainha
void movimentar_rainha_recursivo(int casa_atual, int max_casas) {
    if(casa_atual > max_casas) {
        return;
    }
    
    printf("Casa %d: Esquerda\n", casa_atual);
    movimentar_rainha_recursivo(casa_atual + 1, max_casas);
}

void movimentar_rainha() {
    printf("3. RAINHA - Movimentacao para esquerda (%d casas):\n", RAINHA_CASAS);
    printf("Iniciando movimentacao...\n");
    
    movimentar_rainha_recursivo(1, RAINHA_CASAS);
    printf("Rainha finalizou movimentacao!\n\n");
}

// Função para movimentação do Cavalo com loops aninhados e condições múltiplas
void movimentar_cavalo() {
    printf("4. CAVALO - Movimentacao em L: cima e direita (1 movimento):\n");
    printf("Iniciando movimentacao...\n");
    
    // Variáveis múltiplas para controle
    int fase = 0, passo = 0, max_fases = 2;
    int passos_por_fase[] = {2, 1}; // 2 passos para cima, 1 passo para direita
    const char* direcoes[] = {"Cima", "Direita"};
    
    // Loop externo para as fases do movimento em L
    for(fase = 0; fase < max_fases; fase++) {
        printf("Fase %d do movimento em L:\n", fase + 1);
        
        // Loop interno com múltiplas condições
        for(passo = 1; passo <= 3; passo++) {
            // Condição múltipla: verificar fase atual E número de passos
            if(fase == 0 && passo > passos_por_fase[0]) {
                printf("  Pulando passo extra na fase 1\n");
                continue; // Pula iterações desnecessárias
            }
            
            if(fase == 1 && passo > passos_por_fase[1]) {
                printf("  Finalizando fase 2\n");
                break; // Sai do loop quando completar os passos da fase 2
            }
            
            // Executa o movimento válido
            printf("  Passo %d: %s\n", passo, direcoes[fase]);
        }
    }
    printf("Cavalo completou movimento em L!\n\n");
}

// Função para demonstração adicional
void demonstrar_direcoes() {
    printf("5. DEMONSTRACAO - Todas as direcoes basicas disponveis:\n");
    const char* direcoes[] = {"Cima", "Baixo", "Esquerda", "Direita"};
    int num_direcoes = 4;
    
    for(int i = 0; i < num_direcoes; i++) {
        printf("Direcao %d: %s\n", i + 1, direcoes[i]);
    }
}

int main() {
    printf("=== SIMULADOR DE MOVIMENTACAO DE PECAS - MateCheck ===\n\n");
    
    // Chamada das funções de movimentação
    movimentar_bispo();
    movimentar_torre();
    movimentar_rainha();
    movimentar_cavalo();
    demonstrar_direcoes();
    
    printf("\n=== TESTE DE PERFORMANCE CONCLUIDO ===\n");
    printf("Todas as estruturas de repeticao foram testadas com sucesso!\n");
    
    return 0;
}