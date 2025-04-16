#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_encadeada.h"

#define TAM_TABELA 10  // Define o tamanho fixo da tabela hash

// Estrutura de um nó da lista encadeada
typedef struct No {
    int chave;             // Valor armazenado
    struct No* proximo;    // Ponteiro para o próximo elemento
} No;

// A tabela hash é um vetor de ponteiros para No
No* tabela[TAM_TABELA];  // Inicialmente, todos os ponteiros estarão nulos

// Função hash simples (resto da divisão)
int funcaoHash(int chave) {
    return chave % TAM_TABELA;
}

// Insere um valor na tabela hash
void inserir(int chave) {
    int indice = funcaoHash(chave);  // Aplica função hash para obter o índice

    // Cria novo nó
    No* novo = (No*) malloc(sizeof(No));
    novo->chave = chave;
    novo->proximo = tabela[indice]; // Novo nó aponta para o primeiro da lista (inserção no início)

    tabela[indice] = novo;  // Atualiza a cabeça da lista
}

// Busca um valor na tabela hash
int buscar(int chave) {
    int indice = funcaoHash(chave);  // Obtém índice pela função hash
    No* atual = tabela[indice];      // Começa pelo primeiro nó da lista

    while (atual != NULL) {
        if (atual->chave == chave)
            return 1;  // Encontrado
        atual = atual->proximo;  // Vai para o próximo da lista
    }

    return 0;  // Não encontrado
}

// Exibe o conteúdo da tabela
void imprimirTabela() {
    printf("\n--- Tabela Hash (com encadeamento) ---\n");
    for (int i = 0; i < TAM_TABELA; i++) {
        printf("[%d]: ", i);
        No* atual = tabela[i];
        while (atual != NULL) {
            printf("%d -> ", atual->chave);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}

// Libera a memória da tabela hash
void liberarTabela() {
    for (int i = 0; i < TAM_TABELA; i++) {
        No* atual = tabela[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
        tabela[i] = NULL;  // Zera o ponteiro
    }
}

// Função principal chamada pelo main
void executarHashEncadeada() {
    int opcao, valor;

    // Inicializa a tabela com NULLs
    for (int i = 0; i < TAM_TABELA; i++) {
        tabela[i] = NULL;
    }

    do {
        printf("\n========== TABELA HASH - ENCADEAMENTO ==========\n");
        printf("1. Inserir valor\n");
        printf("2. Buscar valor\n");
        printf("3. Exibir tabela\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserir(valor);
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
                liberarTabela(); // Limpa a memória antes de sair
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);
}
