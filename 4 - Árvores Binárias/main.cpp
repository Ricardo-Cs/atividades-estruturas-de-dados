#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "menus.h"
#include "arvoreBinaria.h"

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
            
            case 4: 
            	int chaveBusca;
				printf("\n\nInforme o valor que deseja buscar: ");
            	scanf("%d", &chaveBusca);
            	
            	if (raiz == NULL) {
            		printf("\n\nA �rvore est� vazia!\n\n");
            		system("pause");
            		break;
				}
            	
				if (raiz->chave == chaveBusca) {
					printf("\n\nN� encontrado! O valor informado � a raiz da �rvore!");
				} else if (noEncontrado(raiz, chaveBusca)) {
					printf("\n\nN� encontrado na �rvore!\n\nValores Percorridos: ");
					percorrerArvore(raiz, chaveBusca);
				} else
					printf("\n\nN� n�o encontrado na �rvore!");

				printf("\n\n");	
            	system("pause");
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
