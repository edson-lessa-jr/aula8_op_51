#include <stdio.h>
#include <stdlib.h>
#include "hash_aberta.h"

#define TAM_TABELA 10  // Tamanho fixo da tabela hash
#define LIVRE -1       // Valor que indica posição vazia

int tabela[TAM_TABELA]; // Vetor que representa a tabela hash

// Função hash simples: módulo
int funcaoHash(int chave) {
    return chave % TAM_TABELA;
}

// Inicializa a tabela com valores vazios
void inicializarTabela() {
    for (int i = 0; i < TAM_TABELA; i++) {
        tabela[i] = LIVRE; // Marca todas as posições como livres
    }
}

// Insere um valor com sondagem linear
void inserir(int chave) {
    int indice = funcaoHash(chave); // Aplica a função hash
    int tentativa = 0;

    // Laço para encontrar uma posição livre usando sondagem linear
    while (tabela[indice] != LIVRE && tentativa < TAM_TABELA) {
        indice = (indice + 1) % TAM_TABELA; // Move para a próxima posição (circular)
        tentativa++;
    }

    if (tentativa == TAM_TABELA) {
        printf("Erro: Tabela cheia, nao foi possivel inserir o valor %d.\n", chave);
        return;
    }

    tabela[indice] = chave; // Insere o valor na posição encontrada
}

// Busca um valor com sondagem linear
int buscar(int chave) {
    int indice = funcaoHash(chave); // Índice inicial pela função hash
    int tentativa = 0;

    // Percorre até encontrar o valor ou encerrar a busca
    while (tabela[indice] != LIVRE && tentativa < TAM_TABELA) {
        if (tabela[indice] == chave)
            return 1; // Encontrado

        indice = (indice + 1) % TAM_TABELA; // Vai para a próxima posição
        tentativa++;
    }

    return 0; // Valor não encontrado
}

// Exibe o conteúdo da tabela
void imprimirTabela() {
    printf("\n--- Tabela Hash (enderecamento aberto - linear) ---\n");
    for (int i = 0; i < TAM_TABELA; i++) {
        if (tabela[i] != LIVRE)
            printf("[%d]: %d\n", i, tabela[i]);
        else
            printf("[%d]: LIVRE\n", i);
    }
}

// Função principal chamada pelo menu
void executarHashAberta() {
    int opcao, valor;

    inicializarTabela(); // Prepara a tabela antes de usar

    do {
        printf("\n========== TABELA HASH - ENDERECAMENTO ABERTO ==========\n");
        printf("1. Inserir valor\n");
        printf("2. Buscar valor\n");
        printf("3. Exibir tabela\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Inserindo valores automaticamente...\n");
            // Vetor de valores predefinidos
                int valores[] = {15, 25, 35, 7, 17, 27, 10, 20, 30};
                int tam = sizeof(valores) / sizeof(valores[0]);

                for (int i = 0; i < tam; i++) {
                    inserir(valores[i]);
                    printf("Inserido: %d\n", valores[i]);
                }
                break;
            case 2:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                if (buscar(valor))
                    printf("Valor %d encontrado na tabela.\n", valor);
                else
                    printf("Valor %d NAO encontrado na tabela.\n", valor);
                break;
            case 3:
                imprimirTabela();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}
