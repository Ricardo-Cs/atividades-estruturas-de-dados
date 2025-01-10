#include <stdio.h>
#include <stdlib.h>
//Arquivo sÃ³ com menus e strings

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
	printf ("\n\n0 - Sair");
}//Fim do procedimento menuPrincipal()

int menuCompararRegistros (void) {
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

//Procedimento clear()
void clear (void) {
	printf ("\n\n\n");
	system ("Pause");
	system ("cls");
}//Fim do procedimento clear()
