#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

//Estrutura Aluno
typedef struct {
	int id;
	char nome[MAX];
	int matricula;
	int codCurso;
	char tipoCurso[MAX];
	int idade;
	float coefMediaGeral; //Média geral de todas as notas
} Aluno; //Fim da estrutura Aluno

//Estrutura No da Fila
typedef struct No {
	Aluno aluno;
	struct No* prox; //Próximo No da fila
} No; //Fim da estrutura No

//Estrutura da Fila
typedef struct {
	No* frente; //primeiro
	No* tras; //último
} Fila;//Fim da estrutura Fila

// Variável global para controlar o autoIncrement do ID do aluno
int alunoId = 1;

//Procedimento inicializarFila()
void inicializarFila(Fila* fila) {
	fila->frente = NULL; //primeiro
	fila->tras = NULL; //último
}//Fim do procedimento inicializarFila()

//Função filaVazia()
int filaVazia (Fila* fila) {
	return fila->frente == NULL;
}//Fim da função filaVazia()

//Procedimento enfileirar()
void enfileirar (Fila* fila, Aluno aluno) {
	No* novoNo = (No*) malloc(sizeof(No));
	if (novoNo == NULL) {
		printf ("\n\nErro de alocação de memória!\n\n");
		exit(1);
	}
	novoNo->aluno = aluno;
	novoNo->prox = NULL;
	
	// Insere id autoIncrement no aluno 	
	novoNo->aluno.id = alunoId;
	alunoId++;
	
	if (filaVazia(fila)) {
		fila->frente = novoNo; //primeiro
	} else {
		fila->tras->prox = novoNo;
	}
	
	fila->tras = novoNo; //último
	printf ("\n\nNovo aluno enfileirado com sucesso!\n\n");
}//Fim do procedimento enfileirar()

//Função desenfileirar()
Aluno desenfileirar (Fila* fila) {
	if (filaVazia(fila)) {
		printf ("\n\nA fila está vazia!\n\n");
		exit(1);
	}
	
	No* temp = fila->frente; //Endereço do primeiro na fila
	Aluno alunoRemovido = temp->aluno; //Dados do primeiro - struct
	fila->frente = temp->prox;
	
	if (fila->frente == NULL) {
		fila->tras = NULL;
	}
	
	free(temp);
	return alunoRemovido;		
}//Fim da função desenfileirar()

//Procedimento exibirFila()
void exibirFila(Fila* fila) {
	if (filaVazia(fila)) {
		printf ("\n\nA fila está vazia!\n\n");
		return;
	}
	
	No* atual = fila->frente;
	printf ("\n\n\nRelatório da Fila");
	while (atual != NULL) {
		Aluno alunoAtual = atual->aluno;
		printf ("\n\n\n\nID do Aluno: %d.", alunoAtual.id);
		printf ("\n\nNome do aluno: %s.", alunoAtual.nome);
		printf ("\n\nNúmero da matrícula: %d.", alunoAtual.matricula);
		printf ("\n\nCódigo do curso: %d.", alunoAtual.codCurso);
		printf ("\n\nTipo do curso: %s.", alunoAtual.tipoCurso);
		printf ("\n\nIdade: %d.", alunoAtual.idade);
		printf ("\n\nMédia geral de notas: %.2f.", alunoAtual.coefMediaGeral);
		atual = atual->prox;
	}
}//Fim do procedimento exibirFila()
