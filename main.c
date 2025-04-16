#include <stdio.h>
#include <stdlib.h>
#include "01-busca-interpolacao/busca_interpolacao.h"
#include "02-tabela-hash-encadeada/hash_encadeada.h"
#include "03-tabela-hash-aberta/hash_aberta.h"

int main() {
    int opcao;

    do {
        printf("\n========== AULA 8 – TECNICAS AVANCADAS DE BUSCA ==========\n");
        printf("1. Busca por Interpolacao\n");
        printf("2. Tabela Hash com Encadeamento\n");
        printf("3. Tabela Hash com Enderecamento Aberto\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                executarBuscaInterpolacao();
            break;
            case 2:
                executarHashEncadeada();
            break;
            case 3:
                executarHashAberta();
            break;
            case 0:
                printf("Saindo...\n");
            break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while(opcao != 0);

    return 0;
}
