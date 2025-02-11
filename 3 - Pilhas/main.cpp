#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include "pilha.h"

int main(int argc, char* argv[]) {
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	int controle = 1, op;
	Pilha pilha;
	do {
		op = menu();
		system("cls");
		switch(op) {
			
			case 1:
				printf("\n\n\n\tOpcao Criar Pilha");
				inicializarPilha(&pilha);
				printf("\n\n\nPilha inicializada com sucesso!");
				clear();
				break;
			case 2:
				printf("\n\n\n\tOpcao Empilhar");
				Livro livro;
				livro = carregarLivro();
				empilhar(&pilha, livro);
				break;
			
			case 3:
				printf("\n\n\n\tOpcao Desempilhar");
				desempilhar(&pilha);
				printf("\n\nLivro desempilhado com sucesso!\n\n");
				clear();
				break;
				
			case 4:
				printf("\n\n\n\tOpcao Exibir Pilha");
				exibirPilha(&pilha);
				clear();
				break;
				
			case 5:
				printf("\n\n\n\tOpcao Verificar - Pilha Cheia");
				if(pilhaCheia(&pilha))
					printf("\n\n\nA pilha esta cheia!\n\n");
				else 
					printf("\n\n\nA pilha nao esta cheia!\n\n");
				system("pause");
				break;
			
			case 6:
				printf("\n\n\n\tOcao Verificar - Pilha Vazia");
				if(pilhaVazia(&pilha))
					printf("\n\n\nA pilha esta vazia!\n\n");
				else 
					printf("\n\n\nA pilha nao esta vazia!\n\n");
				system("pause");
				break;
				
			case 7:
				printf("\n\n\n\tOpcao Exibir Topo");
				Livro livroTopo;
				livroTopo = topoPilha(&pilha);
				printf("\n\n\tTopo da Pilha: ");
				printf("\n\n\nCodigo do Livro: %d", livroTopo.codLivro);
				printf("\n\nNome do Livro: %s", livroTopo.nome);
				printf("\n\nNome do Autor: %s", livroTopo.autor);
				printf("\n\nNumero do ISSN: %s", livroTopo.issn);
				printf("\n\nQuantidade de Paginas: %d", livroTopo.quantPaginas);
				printf("\n\nPreco do Livro: R$ %.2f", livroTopo.preco);
				clear();
				break;
			
			case 8: {
				printf("\n\n\n\tOpcao Buscar Livro pelo Codigo");
				int codLivro;
				printf("\n\nInforme o codigo do livro a ser buscado: ");
				scanf("%d", &codLivro);
				Livro* livroBuscado = buscarPilha(&pilha, codLivro);
				if (livroBuscado != NULL) {
					printf ("\n\nDados do livro encontrado: ");
					printf("\n\n\nCodigo do Livro: %d", livroBuscado->codLivro);
					printf("\n\nNome do Livro: %s", livroBuscado->nome);
					printf("\n\nNome do Autor: %s", livroBuscado->autor);
					printf("\n\nNumero do ISSN: %s", livroBuscado->issn);
					printf("\n\nQuantidade de Paginas: %d", livroBuscado->quantPaginas);
					printf("\n\nPreco do Livro: R$ %.2f", livroBuscado->preco);
				} 
				clear();
				break;
				}
				
			case 9: // Nova opção para verificar/comparar se um livro está na pilha
			    printf("\n\n\nOpcao Verificar Livro na Pilha");
			    int codLivro;
			    printf("\nDigite o codigo do livro a ser verificado: ");
			    scanf("%d", &codLivro);
			    if (compararElementos(&pilha, codLivro)) {
			        printf("\n\nO livro com codigo %d esta na pilha.\n\n", codLivro);
			    } else {
			        printf("\n\nO livro com codigo %d nao esta na pilha.\n\n", codLivro);
			    }
			    system("pause");
			    break;
				
			case 0:
				printf("\n\n\nVoce optou em sair!");
				controle = 0;
        		clear();
				break;
			
			default:
				printf("\n\nInforme uma opcao valida!");
				break;	
		}
		
	} while (controle != 0);
	
	printf("\n\nObrigado por utilizar o nosso programa!\n\n");
	system("Pause");
	return 0;
}
