//Procedimento clear()
void clear (void) {
	printf ("\n\n\n");
	system ("Pause");
	system ("cls");
}//Fim do procedimento clear()

//Funcao menu()
int menu(void) {
	int op;
	printf ("\n\n\n\tMenu");
	printf ("\n\n1 - Enfileirar Cadastro de Aluno");
	printf ("\n\n2 - Desenfileirar Cadastro de Aluno");
	printf ("\n\n3 - Exibir Fila de Cadastros de Alunos");
	printf ("\n\n4 - Alterar Cadastros de Alunos");
	printf ("\n\n5 - Vericar Repeticoes de Matriculas de Alunos");	
	printf ("\n\n6 - Buscar Cadastro de Aluno pelo ID");	
	printf ("\n\n0 - Sair");
	
	printf ("\n\n\nInforme a opcao desejada: ");
	scanf ("%d", &op);
	return op;
}//Fim da função menu()
