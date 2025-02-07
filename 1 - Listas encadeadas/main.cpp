#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEncadeadaPessoa.h"
#include "menus.h"

int main(int argc, char* argv[]) {
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    int opcao, id, idade, qtd_listas, num_lista;
    char nome[80];
    float peso;

    printf("\n\n\nEste programa controla o cadastro de pessoas atrav�s de n listas encadeadas!");
    printf("\n\n\nInforme a quantidade de Listas Encadeadas: ");
    scanf("%d", &qtd_listas);
    clear();

    // Aloca��o din�mica para evitar estouro de mem�ria
    ListaPessoas** listaPessoas = (ListaPessoas**) malloc(qtd_listas * sizeof(ListaPessoas*));
    if (listaPessoas == NULL) {
        printf("Erro ao alocar mem�ria para as listas!\n");
        return 1;
    }

    iniciarListaPessoas(listaPessoas, qtd_listas);
    clear();

    // La�o do menu principal
    do {
        menuPrincipal();
        printf("\n\n\nEscolha uma op��o: ");
        scanf("%d", &opcao);
        clear();

        switch (opcao) {
            case 1: // Inserir novo registro
                printf("\n\n\nOp��o desejada - Inserir Registro em Lista Encadeada");
                num_lista = menuListas(listaPessoas, qtd_listas);
                printf("\n\nInforme o nome: ");
                scanf(" %[^\n]s", nome);
                printf("\n\nInforme o peso (kg): ");
                scanf("%f", &peso);
                printf("\n\nInforme a idade: ");
                scanf("%d", &idade);
                listaPessoas[num_lista]->pessoa = inserirLista(listaPessoas[num_lista]->pessoa, &listaPessoas[num_lista]->idCount, nome, peso, idade);
                printf("\n\n\nNovo registro inserido com sucesso na lista encadeada!\n\n\n");
                clear();
                break;

            case 2: // Imprimir lista encadeada
                printf("\n\n\nOp��o desejada - Listar Todos os Registros de Lista Encadeada");
                num_lista = menuListas(listaPessoas, qtd_listas);
                if (listaVazia(listaPessoas[num_lista]->pessoa)) {
                    printf("\n\nImposs�vel imprimir! A lista est� vazia!\n");
                } else {
                    printf("\n\n\tRegistros cadastrados na lista encadeada:\n\n");
                    imprimirLista(listaPessoas[num_lista]->pessoa);
                }
                clear();
                break;

            case 3: // Buscar elemento na lista encadeada
                printf("\n\n\nOp��o desejada - Buscar Elemento em Lista Encadeada");
                num_lista = menuListas(listaPessoas, qtd_listas);
                printf("\n\nInforme o ID para buscar na lista encadeada: ");
                scanf("%d", &id);
                Pessoa* encontrada;
                encontrada = buscaElemento(listaPessoas[num_lista]->pessoa, id);
                if (encontrada) {
                    printf("\n\n\tRegistro/Pessoa encontrado!");
                    printf("\n\nId: %d", encontrada->id);
                    printf("\n\nNome: %s", encontrada->nome);
                    printf("\n\nPeso: %.2f kg", encontrada->peso);
                    printf("\n\nIdade: %d anos completos", encontrada->idade);
                } else {
                    printf("\n\nPessoa com Id %d n�o encontrada na lista encadeada!", id);
                }
                clear();
                break;

            case 4: // Remover elemento da lista encadeada
                printf("\n\n\nOp��o desejada - Remover Registro de Lista Encadeada");
                num_lista = menuListas(listaPessoas, qtd_listas);
                printf("\n\nInforme o ID para remo��o da lista encadeada: ");
                scanf("%d", &id);
                listaPessoas[num_lista]->pessoa = removerElemento(listaPessoas[num_lista]->pessoa, id);
                printf("\n\n\nCaso estivesse na lista, o registro foi removido com sucesso!");
                clear();
                break;

            case 5: // Liberar lista encadeada
                printf("\n\n\nOp��o desejada - Liberar Lista Encadeada");
                num_lista = menuListas(listaPessoas, qtd_listas);
                listaPessoas[num_lista]->pessoa = liberarLista(listaPessoas[num_lista]->pessoa);
                listaPessoas[num_lista]->idCount = 1; // Reseta o id
                printf("\n\nLista liberada com sucesso!\n");
                clear();
                break;

            case 6: // Ordenar lista encadeada
                printf("\n\n\nOp��o desejada - Ordenar Lista Encadeada");
                num_lista = menuListas(listaPessoas, qtd_listas);
                listaPessoas[num_lista]->pessoa = ordenarLista(listaPessoas[num_lista]->pessoa);
                printf("\n\nLista encadeada ordenada com sucesso!\n");
                clear();
                break;

            case 7: // Editar registro na lista encadeada
                printf("\n\n\nOp��o desejada - Editar Registro na Lista Encadeada");
                num_lista = menuListas(listaPessoas, qtd_listas);
                printf("\n\nInforme o ID do registro a ser editado: ");
                scanf("%d", &id);
                printf("\n\nInforme o novo nome: ");
                scanf(" %[^\n]s", nome);
                printf("\n\nInforme o novo peso: ");
                scanf("%f", &peso);
                printf("\n\nInforme a nova idade: ");
                scanf("%d", &idade);
                editarRegistro(listaPessoas[num_lista]->pessoa, id, nome, peso, idade);
                clear();
                break;

	    	case 8:
	    		int campo, registros;
	    		printf("\n\n\nOp��o desejada - Comparar Registros");
	    		num_lista = menuListas(listaPessoas, qtd_listas);
	    		campo = menuCampo();
	    		clear();
                registros = compararPessoa(listaPessoas[num_lista]->pessoa, campo);

                if(registros >= 0)
                    printf("\n\n\nQuantidade de registros encontrados: %d", registros);
                else   
                    printf("\n\nValor inv�lido! Tente Novamente.");
				
				clear();
				break;

            case 9: // Verificar repeti��es de ID
                printf("\n\n\nOp��o desejada - Verificar Repeti��es de ID");
                num_lista = menuListas(listaPessoas, qtd_listas);
                if (idExiste(listaPessoas[num_lista]->pessoa, id)) {
                    printf("\n\nExistem IDs repetidos na lista.\n");
                } else {
                    printf("\n\nN�o existem IDs repetidos na lista.\n");
                }
                clear();
                break;

            case 0: // Sair do programa
                printf("\n\n\tVoc� optou em sair do programa!");
                clear();
                break;

            default:
                printf("\n\n\nOp��o inv�lida! Informe uma op��o v�lida!");
                clear();
        }
    } while (opcao != 0);

    // Libera��o de mem�ria antes de sair. Verifica se lista � NULL antes de liberar
	for (int i = 0; i < qtd_listas; i++) {
	    if (listaPessoas[i] != NULL) {
	        listaPessoas[i]->pessoa = liberarLista(listaPessoas[i]->pessoa);
	        free(listaPessoas[i]);
	    }
	}
	free(listaPessoas);

    printf("\n\n\nObrigado por utilizar nosso programa!\n\n\n");
    system("Pause");
    return 0;
}

