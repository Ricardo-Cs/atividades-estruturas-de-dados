#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Procedimento clear()
void clear(void) {
    printf("\n\n\n");
    system("Pause");
    system("cls");
} // Fim clear()

// Função menuPrincipal()
int menuPrincipal(void) {
    int op;
    system("cls");
    printf("\n\n\tMenu");
    printf("\n\n1 - Inserir Elemento na Árvore Binária");
    printf("\n\n2 - Excluir Elemento da Árvore Binária");
    printf("\n\n3 - Percorrer/Exibir Árvore Binária");
    printf("\n\n4 - Buscar Nó na Árvore Binária");
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
} // Fim da função menuPrincipal()

// Função menuTravessia()
int menuTravessia(void) {
    int op;
    system("cls");
    printf("\n\n\tMenu - Percorrer/Exibir Árvore Binária");
    printf("\n\n1 - Percorrer/Exibir Árvore Binária por Ordem Simétrica");
    printf("\n\n2 - Percorrer/Exibir Árvore Binária Pós-Ordem");
    printf("\n\n3 - Percorrer/Exibir Árvore Binária Pré-Ordem");
    printf("\n\n0 - Voltar ao Menu Principal");
    printf("\n\n\nInforme a opção desejada: ");
    scanf("%d", &op);
    
    if (op == 1 || op == 2 || op == 3 || op == 0)
        return op;
    else {
        printf("\n\n\nInforme uma opção válida!");
        clear();
        return menuTravessia();
    }
} // Fim da função menuTravessia()

