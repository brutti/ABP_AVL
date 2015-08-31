#include<stdio.h>
#include"arv.h"

int main(void){
    arv* arvore_a;
    int n, f;
    criar_arvore(arvore_a);
    insereArv(&arvore_a, 30);
    insereArv(&arvore_a, 20);
    insereArv(&arvore_a, 50);
    insereArv(&arvore_a, 10);
    insereArv(&arvore_a, 25);
    insereArv(&arvore_a, 32);
    insereArv(&arvore_a, 54);
    printf("%s\n", avl(&arvore_a) ? "E avl" : "Nao e avl");
    printf("%s\n", balan(&arvore_a) ? "Esta balanceada" : "Nao esta balanceada");
    n = fator(&arvore_a, 50, &f);
    if(f) printf("Fator = %d\n", n);
    else printf("Nao encontrado.\n");
    printf("Arvore:\n");
    print(&arvore_a);
    destruirArv(&arvore_a);
    return 0;
}
