#include<stdio.h>
#include"arv.h"

int main(void){
    int n;
    arv* arvore_a = criar_arvore(arvore_a);
    insereArv(&arvore_a, 23);
    insereArv(&arvore_a, 13);
    insereArv(&arvore_a, 40);
    insereArv(&arvore_a, 12);
    insereArv(&arvore_a, 60);
    insereArv(&arvore_a, 42);
    printf("%s\n", avl(&arvore_a) ? "Eh avl" : "Nao eh avl");
    printf("%s\n", balan(&arvore_a) ? "Esta balanceada" : "Nao esta balanceada");
    n=fator(&arvore_a, 23);
    printf("Fator = %d\n",n);
    print(&arvore_a);
    destruirArv(&arvore_a);
    return 0;
}
