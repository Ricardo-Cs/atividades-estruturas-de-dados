#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Procedimento clear()
void clear(void) {
    printf("\n\n\n");
    system("Pause");
    system("cls");
} // Fim clear()

int menuPrincipal(void) {
    int op;
    system("cls");
    printf("\n\n\tMenu");
    printf("\n\n1 - Inserir Elemento na Árvore Genérica");
    printf("\n\n2 - Excluir Elemento na Árvore Genérica");
    printf("\n\n3 - Buscar Nó na Árvore Genérica");
    printf("\n\n4 - Percorrer/Exibir Árvore Genérica");
    printf("\n\n0 - Sair");
    printf("\n\n\nInforme a opção desejada: ");
    scanf("%d", &op);
    
    if (op == 1 || op == 2 || op == 3 || op == 4 || op == 0)
        return op;
    else {
        printf("\n\n\nInforme uma opção válida!");
        clear();
        return menuPrincipal();
    }
}

int menuTravessia(void) {
    int op;
    system("cls");
    printf("\n\n\tMenu - Percorrer/Exibir Árvore Genérica");
    printf("\n\n1 -  Percorrer/Exibir Árvore Genérica Pós-Ordem");
    printf("\n\n2 -  Percorrer/Exibir Árvore Genérica por Pré-Ordem");
    printf("\n\n0 - Voltar ao Menu Principal");
    printf("\n\n\nInforme a opção desejada: ");
    scanf("%d", &op);
    
    if (op == 1 || op == 2 || op == 0)
        return op;
    else {
        printf("\n\n\nInforme uma opção válida!");
        clear();
        return menuTravessia();
    }
}

