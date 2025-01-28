#include "ListaEncadeadaPessoa.h"
#include "menus.h"

int main(int argc, char* argv[]) { //InÃ­cio da main()
system ("cls");
setlocale (LC_ALL, "Portuguese");
Pessoa* lista = criarLista(); // Inicia a lista vazia automaticamente sem passar por menu
int opcao, id, idade;
char nome[80];
float peso;
    
printf ("\n\n\n\tEste programa controla o cadastro de pessoas atravÃ©s de uma lista encadeada!");
clear();

	//InÃ­cio do laÃ§o de controle do menu principal
    do {
        menuPrincipal();
        printf("\n\n\nEscolha uma opÃ§Ã£o: ");
        scanf("%d", &opcao);
        clear();

        switch (opcao) {
            case 1: // Inserir novo registro (pessoa) na lista
            	printf ("\n\n\nOpÃ§Ã£o desejada - Inserir Registro em Lista Encadeada");
                printf("\n\nInforme o ID: ");
                scanf("%d", &id);
                printf("\n\nInforme o nome: ");
                scanf(" %[^\n]s", nome);
                printf("\n\nInforme o peso (kg): ");
                scanf("%f", &peso);
                printf("\n\nInforme a idade: ");
                scanf("%d", &idade);
                lista = inserirLista(lista, id, nome, peso, idade);
                printf("\n\n\nNovo registro inserido com sucesso na lista encadeada!\n\n\n");
                clear();
                break;

            case 2: // Imprimir lista encadeada
            	printf ("\n\n\nOpÃ§Ã£o desejada - Listar Todos os Registros de Lista Encadeada");
                if (listaVazia(lista)) {
                    printf("\n\nImpossÃ­vel imprimir! A lista estÃ¡ vazia!\n");
                } else {
                    printf("\n\n\tRegistros cadastrados na lista encadeada:\n\n");
                    imprimirLista(lista);
                }
                clear();
                break;

            case 3: {// Buscar elemento na lista encadeada
            	printf ("\n\n\nOpÃ§Ã£o desejada - Buscar Elemento em Lista Encadeada");
                printf("\n\nInforme o ID para buscar na lista encadeada: ");
                scanf("%d", &id);
                Pessoa* encontrada = buscaElemento(lista, id);
                if (encontrada) {
                    printf("\n\n\tRegistro/Pessoa encontrado!");
                    printf("\n\nId: %d", encontrada->id);
                    printf("\n\nNome: %s", encontrada->nome);
                    printf("\n\nPeso: %.2f kg", encontrada->peso);
                    printf("\n\nIdade: %d anos completos", encontrada->idade);
                } else {
                    printf("\n\nPessoa com Id %d nÃ£o encontrada na lista encadeada!", id);
                }
                clear();
                break;
			}
			
            case 4: // Remover elemento da lista encadeada
               	printf ("\n\n\nOpÃ§Ã£o desejada - Remover Registro de Lista Encadeada");
                printf("\n\n\nInforme o ID para remoÃ§Ã£o da lista encadeada: ");
                scanf("%d", &id);
                lista = removerElemento(lista, id);
                printf("\n\n\nCaso estivesse na lista, o registro foi removido com sucesso!");
                //E se quisermos verificar se existe na lista ou nÃ£o?
                clear();
                break;

            case 5: // Liberar lista encadeada
            	printf ("\n\n\nOpÃ§Ã£o desejada - Liberar Lista Encadeada");
                lista = liberarLista(lista);
                printf("\n\nLista liberada com sucesso!\n");
                clear();
                break;
		
	    case 6: // Ordenar lista encadeada
		printf("\n\n\nOpÃ§Ã£o desejada - Ordenar Lista Encadeada");
	    	lista = ordenarLista(lista);
		printf("\n\nLista encadeada ordenada com sucesso!\n");
    		clear();
		break;
					
	    case 7: // Editar registro na lista encadeada
	    	printf("\n\n\nOpÃ§Ã£o desejada - Editar Registro na Lista Encadeada");
	    	printf("\n\nInforme o ID do registro a ser editado: ");
		scanf("%d", &id);
		printf("\n\nInforme o novo nome: ");
	    	scanf(" %[^\n]s", nome);
	    	printf("\n\nInforme o novo peso: ");
	    	scanf("%f", &peso);
	    	printf("\n\nInforme a nova idade: ");
	    	scanf("%d", &idade);
	    	editarRegistro(lista, id, nome, peso, idade);
	    	clear();
	    	break;
	    		
	    case 8:
		int campo;
	    	printf("\n\n\nOpção desejada - Comparar Registros");
	    	campo = menuCompararRegistros();
	    	clear();
	    		

            case 0: // Sair do programa
                printf("\n\n\tVocÃª optou em sair do programa!");
                clear();
                break;

            default:
                printf("\n\n\nOpÃ§Ã£o invÃ¡lida! Informe uma opÃ§Ã£o vÃ¡lida!");
                clear();
        }
    } while (opcao != 0); //Fim do laÃ§o de controle do menu principal

    // Garantir que a lista seja liberada ao final antes do encerramento do programa
    lista = liberarLista(lista);
    printf ("\n\n\nObrigado por utilizar nosso programa!\n\n\n");
    system ("Pause");
    return 0;
}//Fim da main()
