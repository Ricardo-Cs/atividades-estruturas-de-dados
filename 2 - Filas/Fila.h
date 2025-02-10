#define MAX 100

//Estrutura Aluno
typedef struct {
	int id;
	char nome[MAX];
	int matricula;
	int codCurso;
	char tipoCurso[MAX];
	int idade;
	float coefMediaGeral; //Media geral de todas as notas
} Aluno; //Fim da estrutura Aluno

//Estrutura No da Fila
typedef struct No {
	Aluno aluno;
	struct No* prox; //Proximo No da fila
} No; //Fim da estrutura No

//Estrutura da Fila
typedef struct {
	No* frente; //primeiro
	No* tras; //ultimo
} Fila;//Fim da estrutura Fila

// Variavel global para controlar o autoIncrement do ID do aluno
int alunoId = 1;

//Procedimento inicializarFila()
void inicializarFila(Fila* fila) {
	fila->frente = NULL; //primeiro
	fila->tras = NULL; //ultimo
}//Fim do procedimento inicializarFila()

//Funcao filaVazia()
int filaVazia (Fila* fila) {
	return fila->frente == NULL;
}//Fim da Funcao filaVazia()

//Procedimento enfileirar()
void enfileirar (Fila* fila, Aluno aluno) {
	No* novoNo = (No*) malloc(sizeof(No));
	if (novoNo == NULL) {
		printf ("\n\nErro de alocacao de memoria!\n\n");
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
	
	fila->tras = novoNo; //ultimo
	printf ("\n\nNovo aluno enfileirado com sucesso!\n\n");
}//Fim do procedimento enfileirar()

//Funcao desenfileirar()
Aluno desenfileirar (Fila* fila) {
	if (filaVazia(fila)) {
		printf ("\n\nA fila esta vazia!\n\n");
		exit(1);
	}
	
	No* temp = fila->frente; //Endereco do primeiro na fila
	Aluno alunoRemovido = temp->aluno; //Dados do primeiro - struct
	fila->frente = temp->prox;
	
	if (fila->frente == NULL) {
		fila->tras = NULL;
	}
	
	free(temp);
	return alunoRemovido;		
}//Fim da Funcao desenfileirar()

//Procedimento exibirFila()
void exibirFila(Fila* fila) {
	if (filaVazia(fila)) {
		printf ("\n\nA fila esta vazia!\n\n");
		return;
	}
	
	No* atual = fila->frente;
	printf ("\n\n\nRelatorio da Fila");
	while (atual != NULL) {
		Aluno alunoAtual = atual->aluno;
		printf ("\n\n\n\nID do Aluno: %d.", alunoAtual.id);
		printf ("\n\nNome do aluno: %s.", alunoAtual.nome);
		printf ("\n\nNumero da matricula: %d.", alunoAtual.matricula);
		printf ("\n\nCodigo do curso: %d.", alunoAtual.codCurso);
		printf ("\n\nTipo do curso: %s.", alunoAtual.tipoCurso);
		printf ("\n\nIdade: %d.", alunoAtual.idade);
		printf ("\n\nMedia geral de notas: %.2f.", alunoAtual.coefMediaGeral);
		atual = atual->prox;
	}
}//Fim do procedimento exibirFila()

//Funcao alterarDadosAluno()
void alterarDadosAluno(Fila* fila, int id, char* novoNome, int novaMatricula, int novoCodCurso, char* novoTipoCurso, int novaIdade, float novoCoefMediaGeral) {
    if (filaVazia(fila)) {
        printf("\n\nA fila esta vazia! Nao ha dados para alterar.\n");
        return;
    }

    No* atual = fila->frente;
    while (atual != NULL) {
        if (atual->aluno.id == id) {
        	
            if (novoNome != NULL && strlen(novoNome) > 0) {
                strcpy(atual->aluno.nome, novoNome);
            }
            if (novaMatricula > 0) {
                atual->aluno.matricula = novaMatricula;
            }
            if (novoCodCurso > 0) {
                atual->aluno.codCurso = novoCodCurso;
            }
            if (novoTipoCurso != NULL && strlen(novoTipoCurso) > 0) {
                strcpy(atual->aluno.tipoCurso, novoTipoCurso);
            }
            if (novaIdade > 0) {
                atual->aluno.idade = novaIdade;
            }
            if (novoCoefMediaGeral >= 0) {
                atual->aluno.coefMediaGeral = novoCoefMediaGeral;
            }

            printf("\n\nDados do aluno atualizados com sucesso!\n");
            return;
        }
        atual = atual->prox;
    }
}//Fim Funcao alterarDadosAluno()

//Funcao para Verificar Repeticoes de Matricula na Fila
void verificarRepeticoesMatricula(Fila* fila) {
   
    if (fila->frente == NULL) {
        printf("A fila esta vazia. Nao ha matriculas para verificar.\n");
        return;
    }

    No* atual = fila->frente;
    int encontrado = 0; 

    while (atual != NULL) {
        No* comparador = atual->prox; 
        while (comparador != NULL) {
            if (atual->aluno.matricula == comparador->aluno.matricula) {
                encontrado = 1; 
                break; 
            }
            comparador = comparador->prox; 
        }
        if (encontrado) {
            break; 
        }
        atual = atual->prox; 
    }

    if (encontrado) {
        printf("\nRepeticao de matricula encontrada na fila.\n");
    } else {
        printf("\nNao ha repeticoes de matricula na fila.\n");
    }
} //Fim da Funcao verificarRepeticoesMatricula()

//Funcao buscarAlunoFila()   - 
Aluno* buscarAlunoFila(Fila* fila, int id) {
	if (filaVazia(fila)) {
		printf ("\n\nA fila esta vazia! Nao ha dados para buscar.\n");
		exit(1);//return NULL; 
	}
	No* atual = fila->frente;
	while (atual != NULL) {
		if (atual->aluno.id == id) {
			return &atual->aluno;
		}
		atual = atual->prox;
	}
	printf ("\n\nAluno com ID %d nao encontrado na fila.\n", id);
	exit(1);//return NULL;
} //Fim da Funcao buscarAlunoFila()
