#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "menus.h"
#include "arvoreGenerica.cpp"

// In�cio da main()
int main(int argc, char* argv[]) {
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    int controle = 1, chave, op1, valorRaiz;
    No* raiz = NULL;
    printf("\n\nSistema de Gerenciamento de �rvores Gen�ricas");
    clear();
    printf("\n\nPara iniciar, informe o valor do Elemento que ser� inserido na Raiz da �rvore: ");
    scanf("%d", &valorRaiz);
    raiz = criarNo(valorRaiz);
    
    while (controle) {
        int opcao = menuPrincipal();
        clear();
        
        switch (opcao) {
            case 1:
                printf("\n\nOp��o Inserir Elemento na �rvore Gen�rica");
                printf("\n\nInforme o valor da chave: ");
                scanf("%d", &chave);
                inserirFilho(raiz, chave);
                printf("\n\nNovo Elemento Inserido com Sucesso!");
                clear();
                break;
            case 2:
                printf("\n\nOp��o Excluir Elemento na �rvore Gen�rica");
                printf("\n\nInforme o valor da chave a ser removida: ");
                scanf("%d", &chave);
                removerNo(raiz, chave);
                printf("\n\nElemento removido, se existia na �rvore!");
                clear();
                break;
            case 3:
                printf("\n\nOp��o Buscar N� na �rvore Gen�rica");
                printf("\n\nInforme o valor da chave a ser buscada: ");
                scanf("%d", &chave);
                if (buscarNo(raiz, chave))
                    printf("\n\nO elemento %d foi encontrado na �rvore!", chave);
                else
                    printf("\n\nO elemento %d n�o est� na �rvore.", chave);
                clear();
                break;
            case 4:
                printf("\n\nOp��o Percorrer/Exibir �rvore Gen�rica");
                op1 = menuTravessia();
                clear();
                switch (op1) {
                    case 1:
                        printf("\n\nResultado da Pesquisa/Listagem P�s-Ordem: ");
                        perPosOrdem(raiz);
                        break;
                    case 2:
                        printf("\n\nResultado da Pesquisa/Listagem Pr�-Ordem: ");
                        perPreOrdem(raiz);
                        break;
                    default:
                        printf("\n\nInforme uma op��o v�lida!");
                }
                clear();
                break;
            case 0:
                controle = 0;
                break;
            default:
                printf("\n\nInforme uma op��o v�lida!");
        }
    }

    printf("\n\nObrigado por utilizar nosso programa!\n\n");
    system("Pause");
    return 0;
} // Fim da main()

