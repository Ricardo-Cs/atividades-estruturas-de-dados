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
				printf("\n\n\n\tOp��o Criar Pilha");
				inicializarPilha(&pilha);
				printf("\n\n\nPilha inicializada com sucesso!");
				clear();
				break;
			case 2:
				printf("\n\n\n\tOp��o Empilhar");
				Livro livro;
				livro = carregarLivro();
				empilhar(&pilha, livro);
				break;
			
			case 3:
				printf("\n\n\n\tOp��o Desempilhar");
				desempilhar(&pilha);
				printf("\n\nLivro desempilhado com sucesso!\n\n");
				clear();
				break;
				
			case 4:
				printf("\n\n\n\tOp��o Exibir Pilha");
				exibirPilha(&pilha);
				clear();
				break;
				
			case 5:
				printf("\n\n\n\tOp��o Verificar - Pilha Cheia");
				if(pilhaCheia(&pilha))
					printf("\n\n\nA pilha est� cheia!\n\n");
				else 
					printf("\n\n\nA pilha n�o est� cheia!\n\n");
				system("pause");
				break;
			
			case 6:
				printf("\n\n\n\tOp��o Verificar - Pilha Vazia");
				if(pilhaVazia(&pilha))
					printf("\n\n\nA pilha est� vazia!\n\n");
				else 
					printf("\n\n\nA pilha n�o est� vazia!\n\n");
				system("pause");
				break;
				
			case 7:
				printf("\n\n\n\tOp��o Exibir Topo");
				Livro livroTopo;
				livroTopo = topoPilha(&pilha);
				printf("\n\n\tTopo da Pilha: ");
				printf("\n\n\nC�digo do Livro: %d", livroTopo.codLivro);
				printf("\n\nNome do Livro: %s", livroTopo.nome);
				printf("\n\nNome do Autor: %s", livroTopo.autor);
				printf("\n\nN�mero do ISSN: %s", livroTopo.issn);
				printf("\n\nQuantidade de P�ginas: %d", livroTopo.quantPaginas);
				printf("\n\nPre�o do Livro: R$ %.2f", livroTopo.preco);
				clear();
				break;
			
			case 0:
				printf("\n\n\nVoc� optou em sair!");
				controle = 0;
        		clear();
				break;
			
			default:
				printf("\n\nInforme uma op��o v�lida!");
				break;	
		}
		
	} while (controle != 0);
	
	printf("\n\nObrigado por utilizar o nosso programa!\n\n");
	system("Pause");
	return 0;
}
