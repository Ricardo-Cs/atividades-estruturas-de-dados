void clear() {
	printf("\n\n\n");
	system("Pause");
	system("cls");
}

int menu() {
	printf("\n\n\n\tSistema de Biblioteca (Pilha)");
	printf("\n\n\t\tMenu");
	printf("\n\n\n1 - Criar Pilha");
	printf("\n\n2 - Empilhar");
	printf("\n\n3 - Desempilhar");
	printf("\n\n4 - Exibir Pilha");
	printf("\n\n5 - Verificar - Pilha Cheia");
	printf("\n\n6 - Verificar - Pilha Vazia");
	printf("\n\n7 - Exibir Topo");
	printf("\n\n0 - Sair");
	printf("\n\n\nInforme a op��o desejada: ");
	
	int op;
	scanf("%d", &op);
	return op;
}
