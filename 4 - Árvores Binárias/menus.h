#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Procedimento clear()
void clear(void) {
    printf("\n\n\n");
    system("Pause");
    system("cls");
} // Fim clear()

// Fun��o menuPrincipal()
int menuPrincipal(void) {
    int op;
    system("cls");
    printf("\n\n\tMenu");
    printf("\n\n1 - Inserir Elemento na �rvore Bin�ria");
    printf("\n\n2 - Excluir Elemento da �rvore Bin�ria");
    printf("\n\n3 - Percorrer/Exibir �rvore Bin�ria");
    printf("\n\n4 - Buscar N� na �rvore Bin�ria");
    printf("\n\n0 - Sair");
    printf("\n\n\nInforme a op��o desejada: ");
    scanf("%d", &op);
    
    if (op == 1 || op == 2 || op == 3 || op == 4 || op == 0)
        return op;
    else {
        printf("\n\n\nInforme uma op��o v�lida!");
        clear();
        return menuPrincipal();
    }
} // Fim da fun��o menuPrincipal()

// Fun��o menuTravessia()
int menuTravessia(void) {
    int op;
    system("cls");
    printf("\n\n\tMenu - Percorrer/Exibir �rvore Bin�ria");
    printf("\n\n1 - Percorrer/Exibir �rvore Bin�ria por Ordem Sim�trica");
    printf("\n\n2 - Percorrer/Exibir �rvore Bin�ria P�s-Ordem");
    printf("\n\n3 - Percorrer/Exibir �rvore Bin�ria Pr�-Ordem");
    printf("\n\n0 - Voltar ao Menu Principal");
    printf("\n\n\nInforme a op��o desejada: ");
    scanf("%d", &op);
    
    if (op == 1 || op == 2 || op == 3 || op == 0)
        return op;
    else {
        printf("\n\n\nInforme uma op��o v�lida!");
        clear();
        return menuTravessia();
    }
} // Fim da fun��o menuTravessia()

