#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEncadeadaPessoa.h"
#include "menus.h"

int main(int argc, char* argv[]) { // Início da main()
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    Pessoa* lista = criarLista(); // Inicia a lista vazia automaticamente sem passar por menu
    int opcao, id, idade;
    char nome[80];
    float peso;

    printf("\n\n\n\tEste programa controla o cadastro de pessoas através de uma lista encadeada!");
    clear();

    // Início do laço de controle do menu principal
    do {
        menuPrincipal();
        printf("\n\n\nEscolha uma opção: ");
        scanf("%d", &opcao);
        clear();

        switch (opcao) {
            case 1: // Inserir novo registro (pessoa) na lista
                printf("\n\n\nOpção desejada - Inserir Registro em Lista Encadeada");
                
                //- Tem id autoIncrement
                // printf("\n\nInforme o ID: ");
                // scanf("%d", &id);
                
                // CASO SEJA NECESSÁRIO VERIFICAR MANUALMENTE O ID
                // do {
                //     printf("\n\nInforme o ID: ");
                //     scanf("%d", &id);
                //     if (idExiste(lista, id)) {
                //         printf("\n\nID %d já existe! Por favor, insira um ID único.\n", id);
                //     }
                // } while (idExiste(lista, id)); // Continua pedindo até que um ID único seja fornecido

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
                printf("\n\n\nOpção desejada - Listar Todos os Registros de Lista Encadeada");
                if (listaVazia(lista)) {
                    printf("\n\nImpossível imprimir! A lista está vazia!\n");
                } else {
                    printf("\n\n\tRegistros cadastrados na lista encadeada:\n\n");
                    imprimirLista(lista);
                }
                clear();
                break;

            case 3: { // Buscar elemento na lista encadeada
                printf("\n\n\nOpção desejada - Buscar Elemento em Lista Encadeada");
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
                    printf("\n\nPessoa com Id %d não encontrada na lista encadeada!", id);
                }
                clear();
                break;
            }

            case 4: // Remover elemento da lista encadeada
                printf("\n\n\nOpção desejada - Remover Registro de Lista Encadeada");
                printf("\n\n\nInforme o ID para remoção da lista encadeada: ");
                scanf("%d", &id);
                lista = removerElemento(lista, id);
                printf("\n\n\nCaso estivesse na lista, o registro foi removido com sucesso!");
                // E se quisermos verificar se existe na lista ou não?
                clear();
                break;

            case 5: // Liberar lista encadeada
                printf("\n\n\nOpção desejada - Liberar Lista Encadeada");
                lista = liberarLista(lista);
                printf("\n\nLista liberada com sucesso!\n");
                clear();
                break;

            case 6: // Ordenar lista encadeada
                printf("\n\n\nOpção desejada - Ordenar Lista Encadeada");
                lista = ordenarLista(lista);
                printf("\n\nLista encadeada ordenada com sucesso!\n");
                clear();
                break;

            case 7: // Editar registro na lista encadeada
                printf("\n\n\nOpção desejada - Editar Registro na Lista Encadeada");
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

            case 9: // Verificar repetições de ID
                printf("\n\n\nOpção desejada - Verificar Repetições de ID");

                if (idExiste(lista, id)) {
                    printf("\n\nExistem IDs repetidos na lista.\n");
                } else {
                    printf("\n\nNão existem IDs repetidos na lista.\n");
                }

                clear();
                break;
            case 0: // Sair do programa
                printf("\n\n\tVocê optou em sair do programa!");
                clear();
                break;

            default:
                printf("\n\n\nOpção inválida! Informe uma opção válida!");
                clear();
        }
    } while (opcao != 0); // Fim do laço de controle do menu principal

    // Garantir que a lista seja liberada ao final antes do encerramento do programa
    lista = liberarLista(lista);
    printf("\n\n\nObrigado por utilizar nosso programa!\n\n\n");
    system("Pause");
    return 0;
} // Fim da main()
