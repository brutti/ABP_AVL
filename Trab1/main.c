#include<stdio.h>
#include"arv.h"

int main(void){
    int n;
    arv* arvore_a = criar_arvore(arvore_a);
    insereArv(&arvore_a, 10);
    insereArv(&arvore_a, 5);
    insereArv(&arvore_a, 4);
    insereArv(&arvore_a, 6);
    insereArv(&arvore_a, 20);
    insereArv(&arvore_a, 15);
    insereArv(&arvore_a, 100);
    insereArv(&arvore_a, 150);
    
    printf("%s\n", avl(&arvore_a) ? "Eh avl" : "Nao eh avl");
    printf("%s\n", balan(&arvore_a) ? "Esta balanceada" : "Nao esta balanceada");
    n=fator(&arvore_a, 150);
    printf("%d\n",n);
    print(&arvore_a);
     return 0;

}
