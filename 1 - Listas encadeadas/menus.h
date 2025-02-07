//Arquivos com menus e strings

//Procedimento menuPrincipal()
void menuPrincipal (void) {
	system ("cls");
	printf ("\n\n\n\tMenu Principal");
	printf ("\n\n\n1 - Inserir Registro em Lista Encadeada");
	printf ("\n\n2 - Listar Todos os Registros de Lista Encadeada");
	printf ("\n\n3 - Buscar Elemento em Lista Encadeada");
	printf ("\n\n4 - Remover Registro de Lista Encadeada");
	printf ("\n\n5 - Liberar Lista Encadeada");
	printf ("\n\n6 - Ordenar Lista Encadeada");
	printf ("\n\n7 - Editar Registro na Lista Encadeada");
	printf ("\n\n8 - Comparar Registros");
	printf ("\n\n9 - Verificar RepitiÃ§Ãµes de ID na Lista Encadeada");
	printf ("\n\n0 - Sair");
}//Fim do procedimento menuPrincipal()

int menuCampo (void) {
	int op;
	system ("cls");
	printf ("\n\n\n\tMenu de Seleção de Campo");
	printf ("\n\n\n1 - ID");
	printf ("\n\n2 - Nome");
	printf ("\n\n3 - Peso");
	printf ("\n\n4 - Idade");
	printf("\n\nInforme o campo que deseja comparar: ");
	scanf("%d", &op);
	return op;
}

int menuListas(ListaPessoas* listaPessoas[], int qtd_listas) {    
    int n;

    printf("\n\n\tListas disponíveis\n\n");
    for (int i = 0; i < qtd_listas; i++) {
        if (listaPessoas[i] != NULL) {  // Verifica se a lista foi inicializada
            printf("\n%d - %s", i + 1, listaPessoas[i]->nome);
        } else {
            printf("\n%d - [Lista não inicializada]", i + 1);
        }
    }

    do {
        printf("\n\nEscolha a lista (1-%d): ", qtd_listas);
        scanf("%d", &n);

        if (n < 1 || n > qtd_listas || listaPessoas[n - 1] == NULL) {
            printf("Opção inválida! Escolha um número entre 1 e %d.\n", qtd_listas);
        }
    } while (n < 1 || n > qtd_listas || listaPessoas[n - 1] == NULL);
	system("cls");
    return n - 1;
}


//Procedimento clear()
void clear (void) {
	printf ("\n\n\n");
	system ("Pause");
	system ("cls");
}//Fim do procedimento clear()
