#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Capacidade maxima da Pilha
#define MAX 100

typedef struct {
	int codLivro;
	char nome[100];
	char issn[10];
	char autor[10];
	int quantPaginas;
	float preco;
} Livro;

typedef struct {
	Livro livros[MAX];
	int topo;
} Pilha;


void inicializarPilha(Pilha *p) {
	p->topo = -1;
}

int pilhaVazia(Pilha *p) {
	return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
	return p->topo == MAX - 1;
}

void empilhar(Pilha *p, Livro livro) {
	if(pilhaCheia(p)) {
		printf("\n\nNao e possivel empilhar! A pilha esta cheia!");
		return;
	}
	
	p->livros[++(p->topo)] = livro;
}

Livro desempilhar(Pilha *p) {
	if(pilhaVazia(p)) {
		printf("\n\nA pilha esta vazia!");
		Livro livroHip = {0, "", "", "", 0, 0.0};
		return livroHip;
	}
	
	return p->livros[(p->topo)--];
}

Livro topoPilha(Pilha *p) {
	if(pilhaVazia(p)) {
		printf("\n\nA pilha esta vazia!");
		Livro livroHip = {0, "", "", "", 0, 0.0};
		return livroHip;
	}
	
	return p->livros[p->topo];
}

int tamanhoPilha(Pilha *p) {
	if(pilhaVazia(p)) {
		printf("\n\nA pilha esta vazia!");
		return 0;
	}
	
	return p->topo + 1;
}

void exibirPilha(Pilha *p) {
	if(pilhaVazia(p)) {
		printf("\n\nA pilha esta vazia!");
		return;
	}
	
	printf("\n\n\n\tLivros na Pilha");
	for(int i = p->topo; i >= 0; i--) {
		printf("\n\n\nCodigo do Livro: %d", p->livros[i].codLivro);
		printf("\n\nNome do Livro: %s", p->livros[i].nome);
		printf("\n\nNome do Autor: %s", p->livros[i].autor);
		printf("\n\nNumero do ISSN: %s", p->livros[i].issn);
		printf("\n\nQuantidade de Paginas: %d", p->livros[i].quantPaginas);
		printf("\n\nPreco do Livro: R$ %.2f", p->livros[i].preco);
	}
}

Livro carregarLivro(void) {
	Livro l;
	printf ("\n\n\tCadastro de Livro - Empilhamento");
	printf ("\n\n\nInforme o codigo do livro: ");
	scanf ("%d", &l.codLivro);
	fflush(stdin);
	printf ("\n\nInforme o nome do livro: ");
	fgets(l.nome, MAX, stdin);
	fflush(stdin);
	printf ("\n\nInforme o ISSN do livro: ");
	fgets(l.issn, 10, stdin);
	fflush(stdin);
	printf ("\n\nInforme o autor do livro: ");
	fgets(l.autor, 30, stdin);
	fflush(stdin);
	printf ("\n\nInforme a quantidade de paginas do livro: ");
	scanf ("%d", &l.quantPaginas);
	printf ("\n\nInforme o preco atual (R$) do livro: ");
	scanf ("%f", &l.preco);
	return l;
}

//Funcao para buscarPilha()
Livro* buscarPilha(Pilha *p, int codLivro) {
	if (pilhaVazia(p)) {
		printf ("\n\nA pilha esta vazia! Nao ha dados para buscar.\n");
		return NULL;
	}
	for (int i = p->topo; i >= 0; i--) {
		if (p->livros[i].codLivro == codLivro) {
			return &p->livros[i];
		}
	}
	printf ("\n\nLivro com codigo %d nao encontrado na pilha.\n", codLivro);
	return NULL;
}//Fim da funcao buscarPilha()


// Função para compararElementos()
int compararElementos(Pilha *p, int codLivro) {
    for (int i = 0; i <= p->topo; i++) {
        if (p->livros[i].codLivro == codLivro) {
            return 1; 
        } 
    }
    return 0; 
} //Fim da função compararElementos()

//função verificarRepeticao()
void verificarRepeticao(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("\n\nA pilha está vazia!");
        return;
    }

    int contRepetidos[MAX] = {0};

    printf("\n\nVerificando livros repetidos na pilha:\n");

    int encontrou = 0;

    for (int i = p->topo; i >= 0; i--) {
        if (contRepetidos[i] == 0) {
            int contador = 1;

            for (int j = i - 1; j >= 0; j--) {
                if (p->livros[i].codLivro == p->livros[j].codLivro) {
                    contador++;
                    contRepetidos[j] = 1;
                }
            }

            if (contador > 1) {
                encontrou = 1;
                printf("\nLivro repetido encontrado:");
                printf("\nCódigo: %d", p->livros[i].codLivro);
                printf("\nNome: %s", p->livros[i].nome);
                printf("\nAutor: %s", p->livros[i].autor);
                printf("\nQuantidade de repetições: %d", contador);
                printf("\n-----------------------------");
            }
        }
    }

    if (!encontrou) {
        printf("\nNenhum livro repetido encontrado.");
    }
}//fim função verificarRepeticao()
