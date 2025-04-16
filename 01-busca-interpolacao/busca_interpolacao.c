#include <stdio.h>
#include "busca_interpolacao.h"

// Função de busca por interpolação
int buscaInterpolacao(int vetor[], int tamanho, int chave) {
    int inicio = 0;               // Índice inicial da busca
    int fim = tamanho - 1;        // Índice final da busca

    while (inicio <= fim && chave >= vetor[inicio] && chave <= vetor[fim]) {
        // Evita divisão por zero
        if (vetor[inicio] == vetor[fim]) {
            if (vetor[inicio] == chave)
                return inicio;    // Valor encontrado
            else
                return -1;        // Valor não encontrado
        }

        // Estimativa da posição com base na interpolação
        int pos = inicio + ((chave - vetor[inicio]) * (fim - inicio)) / (vetor[fim] - vetor[inicio]);

        // Verifica se encontrou o valor
        if (vetor[pos] == chave)
            return pos;

        // Ajusta os limites da busca
        if (vetor[pos] < chave)
            inicio = pos + 1;
        else
            fim = pos - 1;
    }

    // Valor não encontrado
    return -1;
}

// Função principal do módulo, chamada pelo menu do main
void executarBuscaInterpolacao() {
    // Vetor ordenado para testes
    int vetor[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int chave;

    // Mostra o vetor na tela
    printf("\nVetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    // Lê o valor que será buscado
    printf("\nDigite o valor a ser buscado: ");
    scanf("%d", &chave);

    // Executa a busca
    int resultado = buscaInterpolacao(vetor, tamanho, chave);

    // Exibe o resultado
    if (resultado != -1)
        printf("Valor %d encontrado na posicao %d.\n", chave, resultado);
    else
        printf("Valor %d nao encontrado no vetor.\n", chave);
}
