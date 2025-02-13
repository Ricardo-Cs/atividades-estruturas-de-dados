// Estrutura nó
typedef struct no {
    int chave;
    struct no *esquerda;
    struct no *direita;
} no; // Fim da estrutura nó

// Vari�vel para controlar os valores percorridos na fun��o buscarNo()
int primeiroValor = 1;

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

// Fun��o para buscar n� na �rvore (recursiva).
int noEncontrado(no* raiz, int valor) {
    if (raiz == NULL) {
        return 0;
    }
    
    if (raiz->chave == valor) {
        return 1;
    } 
    
    // Operador Tern�rio
    return (valor < raiz->chave) ? noEncontrado(raiz->esquerda, valor) : noEncontrado(raiz->direita, valor);
}

void percorrerArvore(no *raiz, int valor) {
    if (raiz == NULL) {
        return;
    }
    
    if (raiz->chave == valor) {
        return;
    }
    
    printf("\n%d", raiz->chave);
    
    if (valor < raiz->chave) {
        percorrerArvore(raiz->esquerda, valor);
    } else {
        percorrerArvore(raiz->direita, valor);
    }
}
