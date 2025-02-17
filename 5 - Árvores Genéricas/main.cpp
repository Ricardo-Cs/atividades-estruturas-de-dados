#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "menus.h"
#include "arvoreGenerica.cpp"

// Início da main()
int main(int argc, char* argv[]) {
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    int controle = 1, chave, op1, valorRaiz;
    No* raiz = NULL;
    printf("\n\nSistema de Gerenciamento de Árvores Genéricas");
    clear();
    printf("\n\nPara iniciar, informe o valor do Elemento que será inserido na Raiz da Árvore: ");
    scanf("%d", &valorRaiz);
    raiz = criarNo(valorRaiz);
    
    while (controle) {
        int opcao = menuPrincipal();
        clear();
        
        switch (opcao) {
            case 1:
                printf("\n\nOpção Inserir Elemento na Árvore Genérica");
                printf("\n\nInforme o valor da chave: ");
                scanf("%d", &chave);
                inserirFilho(raiz, chave);
                printf("\n\nNovo Elemento Inserido com Sucesso!");
                clear();
                break;
            case 2:
                printf("\n\nOpção Excluir Elemento na Árvore Genérica");
                printf("\n\nInforme o valor da chave a ser removida: ");
                scanf("%d", &chave);
                removerNo(raiz, chave);
                printf("\n\nElemento removido, se existia na árvore!");
                clear();
                break;
            case 3:
                printf("\n\nOpção Buscar Nó na Árvore Genérica");
                printf("\n\nInforme o valor da chave a ser buscada: ");
                scanf("%d", &chave);
                if (buscarNo(raiz, chave))
                    printf("\n\nO elemento %d foi encontrado na árvore!", chave);
                else
                    printf("\n\nO elemento %d não está na árvore.", chave);
                clear();
                break;
            case 4:
                printf("\n\nOpção Percorrer/Exibir Árvore Genérica");
                op1 = menuTravessia();
                clear();
                switch (op1) {
                    case 1:
                        printf("\n\nResultado da Pesquisa/Listagem Pós-Ordem: ");
                        perPosOrdem(raiz);
                        break;
                    case 2:
                        printf("\n\nResultado da Pesquisa/Listagem Pré-Ordem: ");
                        perPreOrdem(raiz);
                        break;
                    default:
                        printf("\n\nInforme uma opção válida!");
                }
                clear();
                break;
            case 0:
                controle = 0;
                break;
            default:
                printf("\n\nInforme uma opção válida!");
        }
    }

    printf("\n\nObrigado por utilizar nosso programa!\n\n");
    system("Pause");
    return 0;
} // Fim da main()

