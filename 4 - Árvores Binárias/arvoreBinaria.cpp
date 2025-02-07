#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "menus.h"

// Estrutura nó
typedef struct no {
    int chave;
    struct no *esquerda;
    struct no *direita;
} no; // Fim da estrutura nó

// Procedimento inserirNo()
void inserirNo(no **raiz, int elemento) {
    if (*raiz == NULL) { // 1º Caso - Inserindo nó raiz
        no *aux = (no *)malloc(sizeof(no));
        aux->chave = elemento;
        aux->direita = aux->esquerda = NULL;
        *raiz = aux;
        system("cls");
        printf("\n\n\nElemento inserido com sucesso na árvore binária!");
        return; 
    }
    
    if (elemento < (*raiz)->chave) { // 2º Caso - Inserindo à esquerda
        inserirNo(&(*raiz)->esquerda, elemento); 
        system("cls");
        printf("\n\n\nElemento inserido com sucesso na árvore binária!");
        return;
    }
    
    if (elemento > (*raiz)->chave) { // 3º Caso - Inserindo à direita
        inserirNo(&(*raiz)->direita, elemento);
        system("cls");
        printf("\n\n\nElemento inserido com sucesso na árvore binária!");
        return;
    }
    
    printf("\n\n\nO código de elemento %d é uma repetição! Elemento não inserido na árvore binária", elemento);
} // Fim do procedimento inserirNo()

// Função doisFilhos()
no *doisFilhos(no *root) {
    if (root == NULL)
        return NULL;
    else if (root->esquerda == NULL) 
        return root;
    else
        return doisFilhos(root->esquerda);    
} // Fim da função doisFilhos()

// Procedimento removerNo()
void removerNo(no **raiz, int elemento) {
    if (elemento < (*raiz)->chave) {
        removerNo(&(*raiz)->esquerda, elemento);
    } else if (elemento > (*raiz)->chave) {
        removerNo(&(*raiz)->direita, elemento);
    } else if ((*raiz)->esquerda != NULL && (*raiz)->direita != NULL) {
        no *aux = doisFilhos((*raiz)->direita);
        (*raiz)->chave = aux->chave;
        removerNo(&(*raiz)->direita, (*raiz)->chave);
    } else {
        no *aux = (*raiz);
        if ((*raiz)->esquerda == NULL) {
            (*raiz) = (*raiz)->direita;
        } else {
            (*raiz) = (*raiz)->esquerda;
        }
        free(aux);
        system("cls");
        printf("\n\n\nElemento de chave %d removido com sucesso da árvore binária!\n\n", elemento);
        system("Pause");
    }
} // Fim do procedimento removerNo()

// Procedimento perOrdemSimétrica() - E-R-D - Exibir a árvore binária
void perOrdemSimetrica(no *raiz) {
    if (raiz == NULL)
        return;
    perOrdemSimetrica(raiz->esquerda);
    printf("\n%d", raiz->chave);
    perOrdemSimetrica(raiz->direita);
} // Fim do procedimento perOrdemSimétrica()

// Procedimento perPosOrdem() - E-D-R
void perPosOrdem(no *raiz) {
    if (raiz == NULL)
        return;
    perPosOrdem(raiz->esquerda);
    perPosOrdem(raiz->direita);
    printf("\n%d", raiz->chave);
} // Fim do procedimento perPosOrdem()

// Procedimento perPreOrdem() - R-E-D
void perPreOrdem(no *raiz) {
    if (raiz == NULL) 
        return;
    printf("\n%d", raiz->chave);
    perPreOrdem(raiz->esquerda);
    perPreOrdem(raiz->direita);
} // Fim do procedimento perPreOrdem()

// Início main()
int main(void) {
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    int controle = 1, quantChaves = 0, chave, i, op1;
    no *raiz = NULL;
    printf("\n\nSistema de Gerenciamento de Árvores Binárias");
    clear();

    while (controle) { // Início while()
        int opcao = menuPrincipal();
        clear();
        switch (opcao) { // Início switch()
            case 1:
                printf("\n\nOpção Inserir Nó na Árvore Binária");
                printf("\n\n\nObservação: a primeira chave digitada será o nó raiz!");
                printf("\n\nInforme a quantidade de chaves que serão inseridas na árvore: ");
                scanf("%d", &quantChaves);
                i = 1;
                while (i <= quantChaves) {
                    clear();
                    printf("\n\nInforme o valor da %dª chave: ", i);
                    scanf("%d", &chave);
                    inserirNo(&raiz, chave);
                    printf("\n\nNova chave inserida com sucesso!");
                    i++;
                }
                break;
            
            case 2:
                printf("\n\nOpção Excluir Elemento da Árvore Binária");
                printf("\n\n\nInforme a chave do elemento que será excluído da árvore binária: ");
                scanf("%d", &chave);
                removerNo(&raiz, chave);
                printf("\n\nElemento removido com sucesso!");
                break;
            
            case 3:
                op1 = menuTravessia();
                clear();
                switch(op1) { // Início do switch()
                    case 1: // Ordem Simétrica
                        printf("\n\n\nResultado da Pesquisa/Listagem em Ordem Simétrica");
                        perOrdemSimetrica(raiz);
                        clear();
                        break;
                    
                    case 2: // Pós-Ordem
                        printf("\n\n\nResultado da Pesquisa/Listagem em Pós-Ordem");
                        perPosOrdem(raiz);
                        clear();
                        break;
                    
                    case 3: // Pré-Ordem
                        printf("\n\n\nResultado da Pesquisa/Listagem em Pré-Ordem");
                        perPreOrdem(raiz);
                        clear();
                        break;
                    
                    default:
                        printf("\n\nInforme uma opção válida!");
                } // Fim do switch()
                break;
            
            case 0:
                printf("\n\nVocê optou por encerrar o programa!");
                controle = 0;
                break;
            
            default:
                printf("\n\nInforme uma opção válida!");
        } // Fim switch()    
    } // Fim while()

    printf("\n\n\nObrigado por utilizar nosso programa!\n\n");
    system("Pause");
    return 0;
} // Fim da main()