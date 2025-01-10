#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
// Struct - lista encadeada pessoa
struct pessoa {
    int id;
    char nome[80];
    float peso;
    int idade;
    struct pessoa* prox;
}; // Fim da struct pessoa

typedef struct pessoa Pessoa;

// Função criarLista()
Pessoa* criarLista() {
    return NULL;
} // Fim da funçãoo criarLista()

// Função inserirLista() - inserir um novo elemento na lista
Pessoa* inserirLista(Pessoa* p, int novoId, char *novoNome, float novoPeso, int novaIdade) {
    Pessoa* novo = (Pessoa*)malloc(sizeof(Pessoa));
    if (novo == NULL) {
        printf("Erro ao alocar mem�ria! N�o ser� poss�vel inserir novo elemento na lista!\n");
        exit(1);
    }
    novo->id = novoId;
    strcpy(novo->nome, novoNome);
    novo->peso = novoPeso;
    novo->idade = novaIdade;
    novo->prox = p;
    return novo;
} // Fim da função inserirLista()

// Procedimento imprimirLista()
void imprimirLista(Pessoa* p) {
    Pessoa* pe;
    for (pe = p; pe != NULL; pe = pe->prox) {
        printf("\n\n\n\tCadastro de Pessoa");
        printf("\n\nId da pessoa: %d", pe->id);
        printf("\nNome da pessoa: %s", pe->nome);
        printf("\nPeso da pessoa (kg): %.2f", pe->peso);
        printf("\nIdade da pessoa (anos completos): %d", pe->idade);
    }
} // Fim da função imprimirLista()

// Função buscaElemento()
Pessoa* buscaElemento(Pessoa* p, int codBusca) {
    Pessoa* pe;
    for (pe = p; pe != NULL; pe = pe->prox) {
        if (pe->id == codBusca) {
            return pe;
        }
    }
    return NULL;
} // Fim da função buscaElemento()

// Função listaVazia()
int listaVazia(Pessoa* p) {
    return p == NULL; //Verdadeiro ou falso direto
} // Fim da listaVazia()

// Função removerElemento()
Pessoa* removerElemento(Pessoa* p, int codBusca) {
    Pessoa* pe = p;
    Pessoa* ant = NULL;

    while (pe != NULL && pe->id != codBusca) {
        ant = pe;
        pe = pe->prox;
    }

    // Lista est� vazia ou o elemento com codBusca n�o foi localizado
    if (pe == NULL)
        return p;

    // Elemento localizado na lista
    if (ant == NULL) // Elemento removido � o "primeiro"
        p = pe->prox;
    else
        ant->prox = pe->prox;

    free(pe);
    return p;
} // Fim da função removerElemento()

// Função liberarLista()
Pessoa* liberarLista(Pessoa* p) {
    Pessoa* pe = p;
    while (pe != NULL) {
        Pessoa* p1 = pe->prox;
        free(pe);
        pe = p1;
    }
    return NULL;
} // Fim da função liberarLista()

// Função compararListas() - Compara��o com base no id
int compararListas(Pessoa* p1, Pessoa* p2) {
    Pessoa* pe1 = p1;
    Pessoa* pe2 = p2;
    while (pe1 != NULL && pe2 != NULL) {
        if (pe1->id != pe2->id)
            return 0;
        pe1 = pe1->prox;
        pe2 = pe2->prox;
    }
    return pe1 == pe2; // NULL == NULL
} // Fim da função compararListas()

int compararPessoa(Pessoa* p1, Pessoa* p2, int campo) {
    switch(campo) {
        case 1: // ID
            return p1->id == p2->id;
            break;
        case 2: // Nome
            int igual;
            igual = strcmp(p1->nome, p2->nome);
            if(igual == 0)
                return 1;
            else
                return 0;
            break;
        case 3: // Peso
        	return p1->peso == p2->peso;
    		break;
    	case 4: // Idade
    		return p1->idade == p2->idade;
    		break;
    	default:
    		return 0;
    		break;
	}
}

//função ordenarLista() - Ordem crescente.
Pessoa* ordenarLista(Pessoa* lista) {
    if (lista == NULL || lista->prox == NULL) {
        return lista;
    }
    Pessoa* novaLista = NULL;

    while (lista != NULL) {
        Pessoa* menor = lista;
        Pessoa* anterior = NULL;
        Pessoa* atual = lista;
        while (atual->prox != NULL) {
            if (atual->prox->id < menor->id) {
                menor = atual->prox;
                anterior = atual;
            }
            atual = atual->prox;
        }
        if (anterior != NULL) {
            anterior->prox = menor->prox;
        } else {
            lista = lista->prox;
        }
        menor->prox = novaLista;
        novaLista = menor;
    }

    return novaLista;
}//Fim da função ordenarLista()

//Função editarRegistro()
void editarRegistro(Pessoa* lista, int id, char* novoNome, float novoPeso, int novaIdade) {
    Pessoa* p = buscaElemento(lista, id);
    if (p == NULL) {
        printf("\n\n\nRegistro com ID %d não encontrado.", id);
        return;
    }
    if (novoNome != NULL && strlen(novoNome) > 0) {
        strcpy(p->nome, novoNome);
    }
    if (novoPeso >= 0) {
        p->peso = novoPeso;
    }
    if (novaIdade >= 0) {
        p->idade = novaIdade;
    }

    printf("\n\n\nRegistro com ID %d atualizado com sucesso.", id);
}//Fim da função editarResgistro()
