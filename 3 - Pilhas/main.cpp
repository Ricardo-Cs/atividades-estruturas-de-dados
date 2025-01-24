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
				printf("\n\n\n\tOpção Criar Pilha");
				inicializarPilha(&pilha);
				printf("\n\n\nPilha inicializada com sucesso!");
				clear();
				break;
			case 2:
				printf("\n\n\n\tOpção Empilhar");
				Livro livro;
				livro = carregarLivro();
				empilhar(&pilha, livro);
				break;
			
			case 3:
				printf("\n\n\n\tOpção Desempilhar");
				desempilhar(&pilha);
				printf("\n\nLivro desempilhado com sucesso!\n\n");
				clear();
				break;
				
			case 4:
				printf("\n\n\n\tOpção Exibir Pilha");
				exibirPilha(&pilha);
				clear();
				break;
				
			case 5:
				printf("\n\n\n\tOpção Verificar - Pilha Cheia");
				if(pilhaCheia(&pilha))
					printf("\n\n\nA pilha está cheia!\n\n");
				else 
					printf("\n\n\nA pilha não está cheia!\n\n");
				system("pause");
				break;
			
			case 6:
				printf("\n\n\n\tOpção Verificar - Pilha Vazia");
				if(pilhaVazia(&pilha))
					printf("\n\n\nA pilha está vazia!\n\n");
				else 
					printf("\n\n\nA pilha não está vazia!\n\n");
				system("pause");
				break;
				
			case 7:
				printf("\n\n\n\tOpção Exibir Topo");
				Livro livroTopo;
				livroTopo = topoPilha(&pilha);
				printf("\n\n\tTopo da Pilha: ");
				printf("\n\n\nCódigo do Livro: %d", livroTopo.codLivro);
				printf("\n\nNome do Livro: %s", livroTopo.nome);
				printf("\n\nNome do Autor: %s", livroTopo.autor);
				printf("\n\nNúmero do ISSN: %s", livroTopo.issn);
				printf("\n\nQuantidade de Páginas: %d", livroTopo.quantPaginas);
				printf("\n\nPreço do Livro: R$ %.2f", livroTopo.preco);
				clear();
				break;
			
			case 0:
				printf("\n\n\nVocê optou em sair!");
				controle = 0;
        		clear();
				break;
			
			default:
				printf("\n\nInforme uma opção válida!");
				break;	
		}
		
	} while (controle != 0);
	
	printf("\n\nObrigado por utilizar o nosso programa!\n\n");
	system("Pause");
	return 0;
}
